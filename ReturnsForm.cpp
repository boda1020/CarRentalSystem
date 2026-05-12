#include "ReturnsForm.h"
#include "DashboardForm.h"
#include "CarsForm.h"
#include "CustomersForm.h"
#include "RentalsForm.h"

using namespace System::Windows::Forms;

namespace CarRentalSystem {

    ReturnsForm::ReturnsForm(void)
    {
        InitializeComponent();
        this->Load += gcnew EventHandler(this, &ReturnsForm::ReturnsForm_Load);
    }

    ReturnsForm::~ReturnsForm()
    {
        if (components) delete components;
    }

    String^ ReturnsForm::GetCustomerName(String^ customerId)
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

    void ReturnsForm::LoadRentalInfo(Object^ sender, EventArgs^ e)
    {
        if (cmbReturnCustomer->SelectedIndex < 0 || cmbReturnCar->SelectedIndex < 0) return;

        String^ selectedCustomer = cmbReturnCustomer->SelectedItem->ToString();
        String^ customerId = selectedCustomer->Substring(selectedCustomer->LastIndexOf(L"(") + 1)->Replace(L")", L"");

        List<String^>^ rentals = FileHelper::ReadAllLines("rentals.txt");

        for each (String ^ line in rentals)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 8 && parts[1] == customerId && parts[7] == L"Active")
            {
                m_carId = parts[2];
                m_startDate = parts[3];
                m_endDate = parts[4];
                m_rentalDays = Int32::Parse(parts[5]);
                m_rentalTotal = Double::Parse(parts[6]);
                m_dailyRate = m_rentalTotal / m_rentalDays;

                String^ carModel = GetCarModel(m_carId);

                lblReturnDaysValue->Text = m_rentalDays.ToString();
                lblReturnPeriodValue->Text = m_startDate + L" to " + m_endDate;

                double dailyTotal = m_dailyRate * m_rentalDays;
                double insurance = dailyTotal * 0.15;
                lblDailyRateValue->Text = L"$" + dailyTotal.ToString(L"0.00");
                lblInsuranceValue->Text = L"$" + insurance.ToString(L"0.00");

                UpdateTotals(nullptr, nullptr);
                return;
            }
        }

        MessageBox::Show(L"No active rental for selected customer/car.", L"Info");
    }

    void ReturnsForm::UpdateTotals(Object^ sender, EventArgs^ e)
    {
        int cleaningFee = (chkCleaningFee->Checked) ? 150 : 0;
        double fuelSurcharge = (double)numFuelSurcharge->Value;
        double damageDeduction = (double)numDamageDeduction->Value;

        double dailyTotal = m_dailyRate * m_rentalDays;
        double insurance = dailyTotal * 0.15;
        double subtotal = dailyTotal + insurance + cleaningFee + fuelSurcharge + damageDeduction;
        double taxes = subtotal * 0.08875;
        double totalDue = subtotal + taxes;

        lblCleaningValue->Text = L"$" + cleaningFee.ToString(L"0.00");
        lblTaxesValue->Text = L"$" + taxes.ToString(L"0.00");
        lblTotalDueValue->Text = L"$" + totalDue.ToString(L"0.00");
    }

    void ReturnsForm::ReturnsForm_Load(System::Object^ sender, System::EventArgs^ e)
    {
        // Load customers
        cmbReturnCustomer->Items->Clear();
        List<String^>^ customers = FileHelper::ReadAllLines("customers.txt");
        for each (String ^ line in customers)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5)
                cmbReturnCustomer->Items->Add(parts[1] + L" (" + parts[0] + L")");
        }
        if (cmbReturnCustomer->Items->Count > 0) cmbReturnCustomer->SelectedIndex = 0;

        // Load cars
        cmbReturnCar->Items->Clear();
        List<String^>^ cars = FileHelper::ReadAllLines("cars.txt");
        for each (String ^ line in cars)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5)
                cmbReturnCar->Items->Add(parts[1] + L" - $" + parts[3] + L"/day");
        }
        if (cmbReturnCar->Items->Count > 0) cmbReturnCar->SelectedIndex = 0;

        chkCleaningFee->CheckedChanged += gcnew EventHandler(this, &ReturnsForm::UpdateTotals);
        numFuelSurcharge->ValueChanged += gcnew EventHandler(this, &ReturnsForm::UpdateTotals);
        numDamageDeduction->ValueChanged += gcnew EventHandler(this, &ReturnsForm::UpdateTotals);

        cmbReturnCustomer->SelectedIndexChanged += gcnew EventHandler(this, &ReturnsForm::LoadRentalInfo);
        cmbReturnCar->SelectedIndexChanged += gcnew EventHandler(this, &ReturnsForm::LoadRentalInfo);

        LoadRentalInfo(nullptr, nullptr);
    }

    void ReturnsForm::btnDashboard_Click(Object^ sender, EventArgs^ e)
    {
        this->Hide();
        DashboardForm^ form = gcnew DashboardForm();
        form->ShowDialog();
        this->Show();
    }

    void ReturnsForm::btnCars_Click(Object^ sender, EventArgs^ e)
    {
        this->Hide();
        CarsForm^ form = gcnew CarsForm();
        form->ShowDialog();
        this->Show();
    }

    void ReturnsForm::btnCustomers_Click(Object^ sender, EventArgs^ e)
    {
        this->Hide();
        CustomersForm^ form = gcnew CustomersForm();
        form->ShowDialog();
        this->Show();
    }

    void ReturnsForm::btnRentals_Click(Object^ sender, EventArgs^ e)
    {
        this->Hide();
        RentalsForm^ form = gcnew RentalsForm();
        form->ShowDialog();
        this->Show();
    }

    void ReturnsForm::btnExit_Click(Object^ sender, EventArgs^ e)
    {
        Application::Exit();
    }

    void ReturnsForm::btnReturnVehicle_Click(Object^ sender, EventArgs^ e)
    {
        int cleaningFee = (chkCleaningFee->Checked) ? 150 : 0;
        double fuelSurcharge = (double)numFuelSurcharge->Value;
        double damageDeduction = (double)numDamageDeduction->Value;

        double dailyTotal = m_dailyRate * m_rentalDays;
        double insurance = dailyTotal * 0.15;
        double subtotal = dailyTotal + insurance + cleaningFee + fuelSurcharge + damageDeduction;
        double taxes = subtotal * 0.08875;
        double totalDue = subtotal + taxes;

        String^ message = L"RETURN SUMMARY\n\n" +
            L"Customer: " + GetCustomerName(m_customerId) + L"\n" +
            L"Total Due: $" + totalDue.ToString(L"0.00");

        ::DialogResult result = MessageBox::Show(message, L"Confirm Return",
            MessageBoxButtons::YesNo, MessageBoxIcon::Question);

        if (result == ::DialogResult::Yes)
        {
            MessageBox::Show(L"Vehicle returned successfully!", L"Success",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }

    String^ ReturnsForm::GetCarModel(String^ carId)
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

    double ReturnsForm::GetDailyRate(String^ carId)
    {
        List<String^>^ cars = FileHelper::ReadAllLines("cars.txt");
        for each (String ^ line in cars)
        {
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5 && parts[0] == carId)
                return Double::Parse(parts[3]);
        }
        return 120.0;
    }

    void ReturnsForm::btnSaveProgress_Click(Object^ sender, EventArgs^ e)
    {
        MessageBox::Show(L"Progress saved!", L"Save Progress",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void ReturnsForm::lblRentalEntryTitle_Click(Object^ sender, EventArgs^ e) {}
}