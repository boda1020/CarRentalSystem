#include "CarsForm.h"
#include "DashboardForm.h"
#include "CustomersForm.h"
#include "RentalsForm.h"
#include "ReturnsForm.h"
#include "FileHelper.h"

using namespace System::Windows::Forms;

namespace CarRentalSystem {

    void CarsForm::LoadCarsFromFile()
    {
        dgvCars->Rows->Clear();
        List<String^>^ lines = FileHelper::ReadAllLines("cars.txt");

        for each (String ^ line in lines)
        {
            if (line->Trim() == L"") continue;
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5)
            {
                dgvCars->Rows->Add(parts[0], parts[1], parts[2],
                    L"$" + parts[3], parts[4], L"EDIT");
            }
        }
        UpdateStats();
        UpdateRowsCount();
    }

    void CarsForm::SaveCarsToFile()
    {
        List<String^>^ lines = gcnew List<String^>();

        for (int i = 0; i < dgvCars->Rows->Count; i++)
        {
            if (dgvCars->Rows[i]->IsNewRow) continue;

            String^ carId = dgvCars->Rows[i]->Cells[0]->Value->ToString();
            String^ model = dgvCars->Rows[i]->Cells[1]->Value->ToString();
            String^ type = dgvCars->Rows[i]->Cells[2]->Value->ToString();
            String^ rate = dgvCars->Rows[i]->Cells[3]->Value->ToString()->Replace(L"$", L"");
            String^ status = dgvCars->Rows[i]->Cells[4]->Value->ToString();

            lines->Add(carId + L"," + model + L"," + type + L"," + rate + L"," + status);
        }

        FileHelper::WriteAllLines("cars.txt", lines);
    }

    void CarsForm::UpdateRowsCount()
    {
        lblRowsCount->Text = L"ROWS: " + dgvCars->Rows->Count;
    }

    void CarsForm::UpdateStats()
    {
        int available = 0, onRental = 0, maintenance = 0;
        for (int i = 0; i < dgvCars->Rows->Count; i++)
        {
            if (dgvCars->Rows[i]->Cells[4]->Value == nullptr) continue;
            String^ status = dgvCars->Rows[i]->Cells[4]->Value->ToString();
            if (status == L"Available") available++;
            else if (status == L"On Rental") onRental++;
            else if (status == L"Maintenance") maintenance++;
        }
        lblTotalFleetNum->Text = dgvCars->Rows->Count.ToString();
        lblAvailableNum->Text = available.ToString();
        lblOnRentalNum->Text = onRental.ToString();
        lblMaintenanceNum->Text = maintenance.ToString();
    }

    String^ CarsForm::ShowInputDialog(String^ title, String^ prompt, String^ defaultValue)
    {
        Form^ inputForm = gcnew Form();
        Label^ label = gcnew Label();
        TextBox^ textBox = gcnew TextBox();
        Button^ okButton = gcnew Button();
        Button^ cancelButton = gcnew Button();

        inputForm->Text = title;
        inputForm->Size = Drawing::Size(400, 180);
        inputForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
        inputForm->StartPosition = FormStartPosition::CenterScreen;
        inputForm->MaximizeBox = false;

        label->Text = prompt;
        label->Location = Drawing::Point(20, 20);
        label->Size = Drawing::Size(340, 25);

        textBox->Text = defaultValue;
        textBox->Location = Drawing::Point(20, 50);
        textBox->Size = Drawing::Size(340, 25);

        okButton->Text = L"OK";
        okButton->Location = Drawing::Point(180, 90);
        okButton->Size = Drawing::Size(80, 30);
        okButton->DialogResult = ::DialogResult::OK;

        cancelButton->Text = L"CANCEL";
        cancelButton->Location = Drawing::Point(270, 90);
        cancelButton->Size = Drawing::Size(80, 30);
        cancelButton->DialogResult = ::DialogResult::Cancel;

        inputForm->Controls->Add(label);
        inputForm->Controls->Add(textBox);
        inputForm->Controls->Add(okButton);
        inputForm->Controls->Add(cancelButton);

        if (inputForm->ShowDialog() == ::DialogResult::OK)
            return textBox->Text;
        return L"";
    }

    void CarsForm::btnDashboard_Click(Object^ sender, EventArgs^ e)
    {
        this->Hide();
        DashboardForm^ form = gcnew DashboardForm();
        form->ShowDialog();
        this->Show();
    }

    void CarsForm::btnCustomers_Click(Object^ sender, EventArgs^ e)
    {
        this->Hide();
        CustomersForm^ form = gcnew CustomersForm();
        form->ShowDialog();
        this->Show();
    }

    void CarsForm::btnRentals_Click(Object^ sender, EventArgs^ e)
    {
        this->Hide();
        RentalsForm^ form = gcnew RentalsForm();
        form->ShowDialog();
        this->Show();
    }

    void CarsForm::btnReturns_Click(Object^ sender, EventArgs^ e)
    {
        this->Hide();
        ReturnsForm^ form = gcnew ReturnsForm();
        form->ShowDialog();
        this->Show();
    }

    void CarsForm::btnExit_Click(Object^ sender, EventArgs^ e)
    {
        Application::Exit();
    }

    void CarsForm::btnAll_Click(Object^ sender, EventArgs^ e)
    {
        LoadCarsFromFile();
    }

    void CarsForm::btnSedan_Click(Object^ sender, EventArgs^ e)
    {
        dgvCars->Rows->Clear();
        List<String^>^ lines = FileHelper::ReadAllLines("cars.txt");
        for each (String ^ line in lines)
        {
            if (line->Trim() == L"") continue;
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5 && parts[2] == L"Sedan")
            {
                dgvCars->Rows->Add(parts[0], parts[1], parts[2], L"$" + parts[3], parts[4], L"EDIT");
            }
        }
        UpdateRowsCount();
    }

    void CarsForm::btnSUV_Click(Object^ sender, EventArgs^ e)
    {
        dgvCars->Rows->Clear();
        List<String^>^ lines = FileHelper::ReadAllLines("cars.txt");
        for each (String ^ line in lines)
        {
            if (line->Trim() == L"") continue;
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5 && parts[2] == L"SUV")
            {
                dgvCars->Rows->Add(parts[0], parts[1], parts[2], L"$" + parts[3], parts[4], L"EDIT");
            }
        }
        UpdateRowsCount();
    }

    void CarsForm::btnAddCar_Click(Object^ sender, EventArgs^ e)
    {
        String^ model = ShowInputDialog(L"Add New Car", L"Enter car model:", L"");
        if (model == L"") return;

        String^ type = ShowInputDialog(L"Add New Car", L"Enter type (Sedan/SUV/EV Sedan):", L"Sedan");
        if (type == L"") return;

        String^ rate = ShowInputDialog(L"Add New Car", L"Enter daily rate:", L"100");
        if (rate == L"") return;

        String^ status = ShowInputDialog(L"Add New Car", L"Enter status (Available/On Rental/Maintenance):", L"Available");
        if (status == L"") return;

        String^ newId = L"CR-" + DateTime::Now.ToString(L"yyyyMMddHHmmss");
        dgvCars->Rows->Add(newId, model, type, L"$" + rate, status, L"EDIT");
        UpdateRowsCount();
        UpdateStats();
        SaveCarsToFile();

        MessageBox::Show(L"Car added successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void CarsForm::dgvCars_CellClick(Object^ sender, DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0 && e->ColumnIndex == 5)
        {
            System::Windows::Forms::DialogResult result = MessageBox::Show(L"Delete this car?", L"Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
            if (result == ::DialogResult::Yes)
            {
                dgvCars->Rows->RemoveAt(e->RowIndex);
                UpdateRowsCount();
                UpdateStats();
                SaveCarsToFile();
            }
        }
    }

    String^ CarsForm::ExtractValue(String^ line)
    {
        int colonPos = line->IndexOf(L":");
        if (colonPos == -1) return L"";
        String^ value = line->Substring(colonPos + 2);
        value = value->Replace(L"\",", L"");
        value = value->Replace(L"\"", L"");
        return value->Trim();
    }
}