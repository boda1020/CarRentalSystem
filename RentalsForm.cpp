#include "RentalsForm.h"
#include "DashboardForm.h"
#include "CarsForm.h"
#include "CustomersForm.h"
#include "ReturnsForm.h"

using namespace System::Windows::Forms;

namespace CarRentalSystem {

    // Load form - populate combo boxes
    void RentalsForm::RentalsForm_Load(System::Object^ sender, System::EventArgs^ e)
    {
        carRates = gcnew Dictionary<String^, double>();

        // Load customers from file
        cmbCustomer->Items->Clear();
        List<String^>^ customers = FileHelper::ReadAllLines("customers.txt");
        for each (String ^ line in customers)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5)
            {
                cmbCustomer->Items->Add(parts[1] + L" (" + parts[0] + L")");
            }
        }
        if (cmbCustomer->Items->Count > 0) cmbCustomer->SelectedIndex = 0;

        // Load cars from file with prices
        cmbCar->Items->Clear();
        List<String^>^ cars = FileHelper::ReadAllLines("cars.txt");
        for each (String ^ line in cars)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5)
            {
                String^ carName = parts[1];
                String^ itemText = carName + L" - $" + parts[3] + L"/day";
                cmbCar->Items->Add(itemText);
                carRates->Add(itemText, Double::Parse(parts[3]));
            }
        }
        if (cmbCar->Items->Count > 0) cmbCar->SelectedIndex = 0;

        numRentDays->Value = 1;
        dtpStartDate->Value = DateTime::Now;

        UpdateCostPreview(nullptr, nullptr);
    }

    // Update cost preview when car or days change
    void RentalsForm::UpdateCostPreview(System::Object^ sender, System::EventArgs^ e)
    {
        if (cmbCar->SelectedIndex < 0) return;

        String^ selectedCar = cmbCar->SelectedItem->ToString();
        double dailyRate = carRates[selectedCar];
        int days = (int)numRentDays->Value;

        double insurance = dailyRate * 0.10;
        double total = (dailyRate + insurance) * days;

        lblDailyRateValue->Text = L"$" + dailyRate.ToString(L"0.00");
        lblInsuranceValue->Text = L"$" + insurance.ToString(L"0.00");
        lblTotalValue->Text = L"$" + total.ToString(L"0.00");
    }



    void RentalsForm::SaveRentalToFile()
    {
        // جلب البيانات من الـ Controls
        String^ customer = cmbCustomer->SelectedItem->ToString();
        String^ customerId = customer->Substring(customer->LastIndexOf(L"(") + 1)->Replace(L")", L"");

        String^ car = cmbCar->SelectedItem->ToString();
        String^ carId = car->Substring(0, car->IndexOf(L" -"));

        // حساب السعر اليومي من النص
        String^ carText = cmbCar->SelectedItem->ToString();
        double dailyRate = 0;
        if (carText->Contains(L"$240")) dailyRate = 240;
        else if (carText->Contains(L"$185")) dailyRate = 185;
        else if (carText->Contains(L"$155")) dailyRate = 155;
        else if (carText->Contains(L"$190")) dailyRate = 190;
        else if (carText->Contains(L"$165")) dailyRate = 165;

        int days = (int)numRentDays->Value;
        double subtotal = dailyRate * days;
        double insurance = subtotal * 0.15;
        double total = subtotal + insurance;

        String^ startDate = dtpStartDate->Value.ToString(L"yyyy-MM-dd");
        String^ endDate = dtpStartDate->Value.AddDays(days).ToString(L"yyyy-MM-dd");
        String^ rentalNo = L"RENT-" + DateTime::Now.ToString(L"yyyyMMddHHmmss");

        // قراءة الملف الحالي
        List<String^>^ rentals = FileHelper::ReadAllLines("rentals.txt");

        // إضافة السطر الجديد
        String^ newLine = String::Concat(rentalNo, L",", customerId, L",", carId, L",",
            startDate, L",", endDate, L",", days.ToString(), L",", total.ToString(L"0.00"), L",", L"Active");

        rentals->Add(newLine);

        // حفظ الملف
        FileHelper::WriteAllLines("rentals.txt", rentals);

        MessageBox::Show(L"Rental saved successfully!\nRental No: " + rentalNo,
            L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    // Sidebar menu buttons
    void RentalsForm::btnDashboard_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        DashboardForm^ form = gcnew DashboardForm();
        form->ShowDialog();
        this->Show();
    }

    void RentalsForm::btnCars_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        CarsForm^ form = gcnew CarsForm();
        form->ShowDialog();
        this->Show();
    }

    void RentalsForm::btnCustomers_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        CustomersForm^ form = gcnew CustomersForm();
        form->ShowDialog();
        this->Show();
    }

    void RentalsForm::btnReturns_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        ReturnsForm^ form = gcnew ReturnsForm();
        form->ShowDialog();
        this->Show();
    }

    void RentalsForm::btnExit_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Application::Exit();
    }

    // Confirm Rental button
    void RentalsForm::btnConfirmRental_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Validate
        if (cmbCustomer->SelectedIndex == -1 || cmbCar->SelectedIndex == -1 || numRentDays->Value <= 0)
        {
            MessageBox::Show(L"Please fill all required fields", L"Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Build confirmation message
        String^ message = L"RENTAL CONFIRMATION\n\n" +
            L"Customer: " + cmbCustomer->SelectedItem->ToString() + L"\n" +
            L"Vehicle: " + cmbCar->SelectedItem->ToString() + L"\n" +
            L"Rental Days: " + numRentDays->Value + L"\n" +
            L"Start Date: " + dtpStartDate->Value.ToString(L"yyyy-MM-dd") + L"\n" +
            L"Total Amount: " + lblTotalValue->Text + L"\n\n" +
            L"Additional Notes:\n" + txtNotes->Text;

        ::DialogResult result = MessageBox::Show(message, L"Confirm Rental",
            MessageBoxButtons::YesNo, MessageBoxIcon::Question);

        if (result == ::DialogResult::Yes)
        {
            // Save to file
            SaveRentalToFile();

            MessageBox::Show(L"Rental confirmed successfully!\n\nInvoice will be generated.",
                L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

            // Reset form for next rental
            cmbCustomer->SelectedIndex = 0;
            cmbCar->SelectedIndex = 0;
            numRentDays->Value = 1;
            dtpStartDate->Value = DateTime::Now;
            txtNotes->Text = L"";
        }
    }
}