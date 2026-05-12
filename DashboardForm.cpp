#include "DashboardForm.h"
#include "CarsForm.h"
#include "CustomersForm.h"
#include "RentalsForm.h"
#include "ReturnsForm.h"
#include "InvoiceForm.h"
#include "FileHelper.h"

namespace CarRentalSystem {

    // Refresh stats from text files
    void DashboardForm::RefreshStats()
    {
        // Total Cars
        List<String^>^ cars = FileHelper::ReadAllLines("cars.txt");
        int totalCars = cars->Count;

        // Available Cars
        int availableCars = 0;
        for each (String ^ line in cars)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5 && parts[4] == L"Available")
                availableCars++;
        }

        // Total Customers
        List<String^>^ customers = FileHelper::ReadAllLines("customers.txt");
        int totalCustomers = customers->Count;

        // Active Rentals
        List<String^>^ rentals = FileHelper::ReadAllLines("rentals.txt");
        int activeRentals = 0;
        for each (String ^ line in rentals)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 8 && parts[7] == L"Active")
                activeRentals++;
        }

        // Update labels
        FixedSingle->Text = totalCars.ToString();
        lblAvailableCarsNum->Text = availableCars.ToString();
        lblCustomersNum->Text = totalCustomers.ToString();
        lblActiveRentalsNum->Text = activeRentals.ToString();

        // Increase indicators (calculated from data)
        lblTotalCarsIncrease->Text = L"+0 NEW";
        lblAvailableCarsIncrease->Text = L"+0 THIS MONTH";
        lblCustomersIncrease->Text = L"+0 CUSTOMERS";
        lblActiveRentalsIncrease->Text = L"+0 RENTAL";
    }

    // Sidebar menu buttons
    void DashboardForm::btnCars_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        CarsForm^ form = gcnew CarsForm();
        form->ShowDialog();
        this->Show();
    }

    void DashboardForm::btnCustomers_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        CustomersForm^ form = gcnew CustomersForm();
        form->ShowDialog();
        this->Show();
    }

    void DashboardForm::btnRentals_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        RentalsForm^ form = gcnew RentalsForm();
        form->ShowDialog();
        this->Show();
    }

    void DashboardForm::btnReturns_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        ReturnsForm^ form = gcnew ReturnsForm();
        form->ShowDialog();
        this->Show();
    }

    void DashboardForm::btnExit_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Application::Exit();
    }

    // DataGridView cell click event for the ACTION button
    void DashboardForm::dataGridView1_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0)
        {
            // VIEW button (colAction)
            if (e->ColumnIndex == colAction->Index)
            {
                String^ date = dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString();
                String^ customerName = dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString();
                String^ rentalNo = safe_cast<String^>(dataGridView1->Rows[e->RowIndex]->Tag);
                String^ carId = safe_cast<String^>(dataGridView1->Rows[e->RowIndex]->Cells[2]->Tag);
                String^ status = dataGridView1->Rows[e->RowIndex]->Cells[3]->Value->ToString();

                String^ carModel = GetCarModelById(carId);
                int days = GetRentalDays(rentalNo);
                double total = GetRentalTotal(rentalNo);
                double dailyRate = total / days;

                String^ rentalInfo = L"RENTAL DETAILS\n\n" +
                    L"Date: " + date + L"\n" +
                    L"Customer: " + customerName + L"\n" +
                    L"Vehicle: " + carModel + L"\n" +
                    L"Status: " + status + L"\n\n" +
                    L"Daily Rate: $" + dailyRate.ToString(L"0.00") + L"\n" +
                    L"Total Days: " + days + L"\n" +
                    L"Total Amount: $" + total.ToString(L"0.00");

                MessageBox::Show(rentalInfo, L"Rental Details",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }

            // DELETE button (colDelete)
// DELETE button (colDelete)
            else if (e->ColumnIndex == colDelete->Index)
            {
                String^ rentalNo = safe_cast<String^>(dataGridView1->Rows[e->RowIndex]->Tag);

                System::Windows::Forms::DialogResult result = MessageBox::Show(L"Delete rental " + rentalNo + L"?", L"Confirm Delete",
                    MessageBoxButtons::YesNo, MessageBoxIcon::Question);

                if (result == ::DialogResult::Yes)
                {
                    List<String^>^ rentals = FileHelper::ReadAllLines("rentals.txt");
                    List<String^>^ newRentals = gcnew List<String^>();

                    for each (String ^ line in rentals)
                    {
                        if (!line->Contains(rentalNo))
                            newRentals->Add(line);
                    }

                    FileHelper::WriteAllLines("rentals.txt", newRentals);

                    LoadRecentRentals();
                    RefreshStats();

                    MessageBox::Show(L"Rental deleted successfully!", L"Success",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
            }
        }
    }

    double DashboardForm::GetDailyRate(String^ carId)
    {
        List<String^>^ cars = FileHelper::ReadAllLines("cars.txt");
        for each (String ^ line in cars)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5 && parts[0] == carId)
                return Double::Parse(parts[3]);   // daily rate
        }
        return 145.0;
    }

    int DashboardForm::GetRentalDays(String^ rentalNo)
    {
        List<String^>^ rentals = FileHelper::ReadAllLines("rentals.txt");
        for each (String ^ line in rentals)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 8 && parts[0] == rentalNo)
                return Int32::Parse(parts[5]);
        }
        return 7;
    }

    double DashboardForm::GetRentalTotal(String^ rentalNo)
    {
        List<String^>^ rentals = FileHelper::ReadAllLines("rentals.txt");
        for each (String ^ line in rentals)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 8 && parts[0] == rentalNo)
                return Double::Parse(parts[6]);
        }
        return 1015.0;
    }

    String^ DashboardForm::GetCustomerName(String^ customerId)
    {
        List<String^>^ customers = FileHelper::ReadAllLines("customers.txt");
        for each (String ^ line in customers)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5 && parts[0] == customerId)
                return parts[1];
        }
        return L"Unknown";
    }

    String^ DashboardForm::GetCarModelById(String^ carId)
    {
        List<String^>^ cars = FileHelper::ReadAllLines("cars.txt");
        for each (String ^ line in cars)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5 && parts[0] == carId)
                return parts[1];
        }
        return L"Unknown";
    }

    void DashboardForm::LoadRecentRentals()
    {
        dataGridView1->Rows->Clear();
        List<String^>^ rentals = FileHelper::ReadAllLines("rentals.txt");

        for each (String ^ line in rentals)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 8)
            {
                String^ startDate = parts[3];
                String^ customerId = parts[1];
                String^ carId = parts[2];
                String^ status = parts[7];
                String^ rentalNo = parts[0];

                String^ customerName = GetCustomerName(customerId);
                String^ carModel = GetCarModel(carId);  // دي تجيب الموديل

                int rowIndex = dataGridView1->Rows->Add(startDate, customerName, carModel, status, L"VIEW");
                dataGridView1->Rows[rowIndex]->Tag = rentalNo;
                dataGridView1->Rows[rowIndex]->Cells[2]->Tag = carId;
            }
        }
    }

    String^ DashboardForm::GetCarModel(String^ carId)
    {
        List<String^>^ cars = FileHelper::ReadAllLines("cars.txt");
        for each (String ^ line in cars)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5 && parts[0] == carId)
                return parts[1];
        }
        return L"Unknown";
    }
}