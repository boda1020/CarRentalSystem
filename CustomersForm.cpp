#include "CustomersForm.h"
#include "DashboardForm.h"
#include "CarsForm.h"
#include "RentalsForm.h"
#include "ReturnsForm.h"
#include "InvoiceForm.h"
#include "FileHelper.h"

using namespace System::Windows::Forms;

namespace CarRentalSystem {

    // Helper function to show input dialog
    String^ CustomersForm::ShowInputDialog(String^ title, String^ prompt, String^ defaultValue)
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

    // Load customers from file
    void CustomersForm::LoadCustomersFromFile()
    {
        dgvCustomers->Rows->Clear();
        List<String^>^ lines = FileHelper::ReadAllLines("customers.txt");

        for each (String ^ line in lines)
        {
            if (line->Trim() == L"") continue;
            array<String^>^ parts = line->Split(L',');
            if (parts->Length >= 5)
            {
                dgvCustomers->Rows->Add(parts[0], parts[1], parts[2], parts[3], parts[4],
                    L"EDIT", L"DELETE", L"VIEW", L"INVOICE");
            }
        }
        UpdateStats();
        UpdateRowsCount();
    }

    // Save customers to file
    void CustomersForm::SaveCustomersToFile()
    {
        List<String^>^ lines = gcnew List<String^>();

        for (int i = 0; i < dgvCustomers->Rows->Count; i++)
        {
            if (dgvCustomers->Rows[i]->IsNewRow) continue;

            String^ id = dgvCustomers->Rows[i]->Cells[0]->Value->ToString();
            String^ name = dgvCustomers->Rows[i]->Cells[1]->Value->ToString();
            String^ email = dgvCustomers->Rows[i]->Cells[2]->Value->ToString();
            String^ phone = dgvCustomers->Rows[i]->Cells[3]->Value->ToString();
            String^ status = dgvCustomers->Rows[i]->Cells[4]->Value->ToString();

            lines->Add(String::Concat(id, L",", name, L",", email, L",", phone, L",", status));
        }

        FileHelper::WriteAllLines("customers.txt", lines);
    }

    // Update stats cards
    void CustomersForm::UpdateStats()
    {
        int total = dgvCustomers->Rows->Count;
        int activeRentals = 0; // This will come from rentals file later
        double complianceRate = 98.5; // Sample value
        int newThisMonth = 0; // Sample value

        lblTotalCustomersNum->Text = total.ToString();
        lblActiveRentalsNum->Text = activeRentals.ToString();
        lblComplianceRateNum->Text = complianceRate.ToString() + L"%";
        lblNewThisMonthNum->Text = newThisMonth.ToString();
    }

    // Update rows count
    void CustomersForm::UpdateRowsCount()
    {
        lblRowsCount->Text = L"Displaying rows 1-" + dgvCustomers->Rows->Count + L" of 1,284 total records";
    }

    // Sidebar menu buttons
    void CustomersForm::btnDashboard_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        DashboardForm^ form = gcnew DashboardForm();
        form->ShowDialog();
        this->Show();
    }

    void CustomersForm::btnCars_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        CarsForm^ form = gcnew CarsForm();
        form->ShowDialog();
        this->Show();
    }

    void CustomersForm::btnRentals_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        RentalsForm^ form = gcnew RentalsForm();
        form->ShowDialog();
        this->Show();
    }

    void CustomersForm::btnReturns_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        ReturnsForm^ form = gcnew ReturnsForm();
        form->ShowDialog();
        this->Show();
    }

    void CustomersForm::btnExit_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Application::Exit();
    }

    // Control buttons
    void CustomersForm::btnFilters_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show(L"Filters window will open here", L"Filters", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void CustomersForm::btnExportCSV_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show(L"Export to CSV will open here", L"Export", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void CustomersForm::btnAddCustomer_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ name = ShowInputDialog(L"Add New Customer", L"Enter customer name:", L"");
        if (name == L"") return;

        String^ email = ShowInputDialog(L"Add New Customer", L"Enter email:", L"");
        if (email == L"") return;

        String^ phone = ShowInputDialog(L"Add New Customer", L"Enter phone:", L"");
        if (phone == L"") return;

        String^ status = ShowInputDialog(L"Add New Customer", L"Enter status (ACTIVE/PENDING):", L"ACTIVE");
        if (status == L"") return;

        String^ newId = String::Concat(L"CUST-", DateTime::Now.ToString(L"yyyyMMddHHmmss"));
        dgvCustomers->Rows->Add(newId, name, email, phone, status, L"EDIT", L"DELETE", L"VIEW", L"INVOICE");
        UpdateStats();
        UpdateRowsCount();
        SaveCustomersToFile();

        MessageBox::Show(L"Customer added successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void CustomersForm::btnReviewDocs_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show(L"Review customer documents", L"Review Docs", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    // DataGridView cell click
    void CustomersForm::dgvCustomers_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0)
        {
            String^ customerId = dgvCustomers->Rows[e->RowIndex]->Cells[0]->Value->ToString();
            String^ customerName = dgvCustomers->Rows[e->RowIndex]->Cells[1]->Value->ToString();
            String^ email = dgvCustomers->Rows[e->RowIndex]->Cells[2]->Value->ToString();
            String^ phone = dgvCustomers->Rows[e->RowIndex]->Cells[3]->Value->ToString();
            String^ status = dgvCustomers->Rows[e->RowIndex]->Cells[4]->Value->ToString();

            // EDIT (column 5)
            if (e->ColumnIndex == 5)
            {
                String^ newName = ShowInputDialog(L"Edit Customer", L"Edit name:", customerName);
                if (newName != L"") dgvCustomers->Rows[e->RowIndex]->Cells[1]->Value = newName;

                String^ newEmail = ShowInputDialog(L"Edit Customer", L"Edit email:", email);
                if (newEmail != L"") dgvCustomers->Rows[e->RowIndex]->Cells[2]->Value = newEmail;

                String^ newPhone = ShowInputDialog(L"Edit Customer", L"Edit phone:", phone);
                if (newPhone != L"") dgvCustomers->Rows[e->RowIndex]->Cells[3]->Value = newPhone;

                String^ newStatus = ShowInputDialog(L"Edit Customer", L"Edit status (ACTIVE/PENDING):", status);
                if (newStatus != L"") dgvCustomers->Rows[e->RowIndex]->Cells[4]->Value = newStatus;

                SaveCustomersToFile();
                MessageBox::Show(L"Customer updated successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            // DELETE (column 6)
            else if (e->ColumnIndex == 6)
            {
                ::DialogResult result = MessageBox::Show(L"Delete " + customerId + L"?", L"Confirm Delete",
                    MessageBoxButtons::YesNo, MessageBoxIcon::Question);
                if (result == ::DialogResult::Yes)
                {
                    dgvCustomers->Rows->RemoveAt(e->RowIndex);
                    UpdateStats();
                    UpdateRowsCount();
                    SaveCustomersToFile();
                    MessageBox::Show(L"Customer deleted successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
            }
            // VIEW (column 7)
            else if (e->ColumnIndex == 7)
            {
                String^ customerInfo = L"CUSTOMER DETAILS\n\n" +
                    L"ID: " + customerId + L"\n" +
                    L"Name: " + customerName + L"\n" +
                    L"Email: " + email + L"\n" +
                    L"Phone: " + phone + L"\n" +
                    L"Status: " + status;

                MessageBox::Show(customerInfo, L"View Customer",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            // INVOICE (column 8)
            else if (e->ColumnIndex == 8)
            {
                InvoiceForm^ invoiceForm = gcnew InvoiceForm(customerId, customerName, email, phone);
                invoiceForm->ShowDialog();
            }
        }
    }
}