#pragma once

namespace CarRentalSystem {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;
    using namespace System::Text;

    public ref class InvoiceForm : public System::Windows::Forms::Form
    {
    public:
        InvoiceForm(String^ id, String^ name, String^ email, String^ phone)
        {
            InitializeComponent();

            m_customerId = id;
            m_customerName = name;
            m_customerEmail = email;
            m_customerPhone = phone;

           

            // Bind events
            this->btnDashboard->Click += gcnew EventHandler(this, &InvoiceForm::btnDashboard_Click);
            this->btnCars->Click += gcnew EventHandler(this, &InvoiceForm::btnCars_Click);
            this->btnCustomers->Click += gcnew EventHandler(this, &InvoiceForm::btnCustomers_Click);
            this->btnRentals->Click += gcnew EventHandler(this, &InvoiceForm::btnRentals_Click);
            this->btnReturns->Click += gcnew EventHandler(this, &InvoiceForm::btnReturns_Click);
            this->btnExit->Click += gcnew EventHandler(this, &InvoiceForm::btnExit_Click);
            this->btnPrint->Click += gcnew EventHandler(this, &InvoiceForm::btnPrint_Click);
            this->btnClose->Click += gcnew EventHandler(this, &InvoiceForm::btnClose_Click);
        }

    protected:
        ~InvoiceForm()
        {
            if (components) delete components;
        }

    private:
        String^ m_customerId;
        String^ m_customerName;
        String^ m_customerEmail;
        String^ m_customerPhone;

        

        void LoadRentalData()
        {
            List<String^>^ rentals = FileHelper::ReadAllLines("rentals.txt");

            for each (String ^ line in rentals)
            {
                array<String^>^ parts = line->Split(L',');
                if (parts->Length >= 8 && parts[1] == m_customerId)
                {
                    // Get car details from cars.txt
                    List<String^>^ cars = FileHelper::ReadAllLines("cars.txt");
                    String^ carModel = L"Unknown";

                    for each (String ^ carLine in cars)
                    {
                        array<String^>^ carParts = carLine->Split(L',');
                        if (carParts->Length >= 5 && carParts[0] == parts[2])
                        {
                            carModel = carParts[1];
                            break;
                        }
                    }

                    // Update invoice with real data
                    lblVehicleValue->Text = carModel;
                    lblPeriodValue->Text = parts[3] + L" to " + parts[4] + L" (" + parts[5] + L" days)";
                    lblInvoiceNoValue->Text = L"INV-" + parts[0];
                    lblDateValue->Text = DateTime::Now.ToString(L"MM/dd/yyyy");

                    // Update totals
                    double total = Double::Parse(parts[6]);
                    double tax = total * 0.085;

                    lblSubtotalValue->Text = L"$" + total.ToString(L"0.00");
                    lblTaxValue->Text = L"$" + tax.ToString(L"0.00");
                    lblTotalValue->Text = L"$" + (total + tax).ToString(L"0.00");

                    // Update grid items (sample items with percentages)
                    double dailyRate = total / Double::Parse(parts[5]);

                    dgvInvoiceItems->Rows->Clear();
                    dgvInvoiceItems->Rows->Add(L"Vehicle Rental (" + parts[5] + L" days)", parts[5], L"$" + dailyRate.ToString(L"0.00"), L"$" + total.ToString(L"0.00"));
                    dgvInvoiceItems->Rows->Add(L"Insurance (Premium Coverage)", parts[5], L"$25.00", L"$" + (25 * Double::Parse(parts[5])).ToString(L"0.00"));
                    dgvInvoiceItems->Rows->Add(L"Airport Fee", L"1", L"$45.00", L"$45.00");

                    break;
                }
            }
        }

        void btnDashboard_Click(Object^ sender, EventArgs^ e)
        {
            this->Hide();
            DashboardForm^ form = gcnew DashboardForm();
            form->ShowDialog();
            this->Show();
        }

        void btnCars_Click(Object^ sender, EventArgs^ e)
        {
            this->Hide();
            CarsForm^ form = gcnew CarsForm();
            form->ShowDialog();
            this->Show();
        }

        void btnCustomers_Click(Object^ sender, EventArgs^ e)
        {
            this->Hide();
            CustomersForm^ form = gcnew CustomersForm();
            form->ShowDialog();
            this->Show();
        }

        void btnRentals_Click(Object^ sender, EventArgs^ e)
        {
            this->Hide();
            RentalsForm^ form = gcnew RentalsForm();
            form->ShowDialog();
            this->Show();
        }

        void btnReturns_Click(Object^ sender, EventArgs^ e)
        {
            this->Hide();
            ReturnsForm^ form = gcnew ReturnsForm();
            form->ShowDialog();
            this->Show();
        }

        void btnExit_Click(Object^ sender, EventArgs^ e)
        {
            Application::Exit();
        }

        void btnPrint_Click(Object^ sender, EventArgs^ e)
        {
            SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
            saveDialog->Filter = L"Text Files (*.txt)|*.txt";
            saveDialog->Title = L"Save Invoice As";
            saveDialog->FileName = lblInvoiceNoValue->Text + L".txt";

            if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                SaveToTextFile(saveDialog->FileName);
                MessageBox::Show(L"Invoice saved successfully!\n" + saveDialog->FileName, L"Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }

        void SaveToTextFile(String^ filePath)
        {
            StringBuilder^ sb = gcnew StringBuilder();

            sb->AppendLine(L"==============================");
            sb->AppendLine(L"        INVOICE");
            sb->AppendLine(L"==============================");
            sb->AppendLine();
            sb->AppendLine(L"AutoLease Manager");
            sb->AppendLine(L"123 Enterprise Way, Chicago, IL 60601");
            sb->AppendLine(L"Tel: (555) 012-3456");
            sb->AppendLine();
            sb->AppendLine(L"BILL TO:");
            sb->AppendLine(L"  " + lblCompanyName->Text);
            sb->AppendLine(L"  " + lblAttn->Text);
            sb->AppendLine(L"  " + lblBillAddress1->Text);
            sb->AppendLine(L"  " + lblBillAddress2->Text);
            sb->AppendLine();
            sb->AppendLine(L"RENTAL DETAILS:");
            sb->AppendLine(L"  Invoice #: " + lblInvoiceNoValue->Text);
            sb->AppendLine(L"  Date: " + lblDateValue->Text);
            sb->AppendLine(L"  Vehicle: " + lblVehicleValue->Text);
            sb->AppendLine(L"  Period: " + lblPeriodValue->Text);
            sb->AppendLine();
            sb->AppendLine(L"DESCRIPTION                     DAYS  UNIT PRICE    TOTAL");
            sb->AppendLine(L"--------------------------------------------------------");

            for each (DataGridViewRow ^ row in dgvInvoiceItems->Rows)
            {
                if (row->IsNewRow) continue;
                sb->AppendLine(String::Format(L"{0,-30} {1,4}  {2,10}  {3,10}",
                    row->Cells[0]->Value, row->Cells[1]->Value,
                    row->Cells[2]->Value, row->Cells[3]->Value));
            }

            sb->AppendLine(L"--------------------------------------------------------");
            sb->AppendLine(String::Format(L"{0,50} {1,10}", L"Subtotal:", lblSubtotalValue->Text));
            sb->AppendLine(String::Format(L"{0,50} {1,10}", L"Tax (8.5%):", lblTaxValue->Text));
            sb->AppendLine(L"--------------------------------------------------------");
            sb->AppendLine(String::Format(L"{0,50} {1,10}", L"TOTAL AMOUNT:", lblTotalValue->Text));
            sb->AppendLine();
            sb->AppendLine(L"Thank you for choosing Car Rental System");

            File::WriteAllText(filePath, sb->ToString());
        }

        void btnClose_Click(Object^ sender, EventArgs^ e)
        {
            this->Close();
        }

        // GUI Controls
        System::Windows::Forms::Panel^ panel1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Panel^ panel2;
        System::Windows::Forms::Button^ btnExit;
        System::Windows::Forms::Button^ btnReturns;
        System::Windows::Forms::Button^ btnRentals;
        System::Windows::Forms::Button^ btnCustomers;
        System::Windows::Forms::Button^ btnCars;
        System::Windows::Forms::Button^ btnDashboard;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Panel^ panelCompanyInfo;
        System::Windows::Forms::Label^ lblCorporateTag;
        System::Windows::Forms::Label^ lblCompanyTitle;
        System::Windows::Forms::Label^ lblEmail;
        System::Windows::Forms::Label^ lblPhone;
        System::Windows::Forms::Label^ lblAddress2;
        System::Windows::Forms::Label^ lblAddress1;
        System::Windows::Forms::Panel^ panelBillTo;
        System::Windows::Forms::Label^ label10;
        System::Windows::Forms::Label^ lblBillToTitle;
        System::Windows::Forms::Label^ lblAttn;
        System::Windows::Forms::Label^ lblCompanyName;
        System::Windows::Forms::Label^ lblBillAddress1;
        System::Windows::Forms::Label^ lblCustomerID;
        System::Windows::Forms::Label^ lblBillAddress2;
        System::Windows::Forms::Panel^ panelRentalDetails;
        System::Windows::Forms::Label^ lblVehicleValue;
        System::Windows::Forms::Label^ lblVehicleLabel;
        System::Windows::Forms::Label^ lblRentalDetailsTitle;
        System::Windows::Forms::Label^ lblDateValue;
        System::Windows::Forms::Label^ lblDateLabel;
        System::Windows::Forms::Label^ lblInvoiceNoValue;
        System::Windows::Forms::Label^ lblInvoiceNoLabel;
        System::Windows::Forms::Label^ lblPeriodValue;
        System::Windows::Forms::Label^ lblPeriodLabel;
        System::Windows::Forms::DataGridView^ dgvInvoiceItems;
        System::Windows::Forms::DataGridViewTextBoxColumn^ colDescription;
        System::Windows::Forms::DataGridViewTextBoxColumn^ colDays;
        System::Windows::Forms::DataGridViewTextBoxColumn^ colUnitPrice;
        System::Windows::Forms::DataGridViewTextBoxColumn^ colTotal;
        System::Windows::Forms::Label^ lblSubtotalLabel;
        System::Windows::Forms::Label^ lblSubtotalValue;
        System::Windows::Forms::Panel^ panel3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Label^ lblTaxValue;
        System::Windows::Forms::Label^ lblTaxLabel;
        System::Windows::Forms::Button^ btnClose;
        System::Windows::Forms::Button^ btnPrint;
        System::Windows::Forms::Label^ lblTotalValue;
        System::Windows::Forms::Label^ lblTotalLabel;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->btnExit = (gcnew System::Windows::Forms::Button());
            this->btnReturns = (gcnew System::Windows::Forms::Button());
            this->btnRentals = (gcnew System::Windows::Forms::Button());
            this->btnCustomers = (gcnew System::Windows::Forms::Button());
            this->btnCars = (gcnew System::Windows::Forms::Button());
            this->btnDashboard = (gcnew System::Windows::Forms::Button());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->panelCompanyInfo = (gcnew System::Windows::Forms::Panel());
            this->btnClose = (gcnew System::Windows::Forms::Button());
            this->btnPrint = (gcnew System::Windows::Forms::Button());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->lblTotalValue = (gcnew System::Windows::Forms::Label());
            this->lblTotalLabel = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->lblSubtotalLabel = (gcnew System::Windows::Forms::Label());
            this->lblTaxValue = (gcnew System::Windows::Forms::Label());
            this->lblSubtotalValue = (gcnew System::Windows::Forms::Label());
            this->lblTaxLabel = (gcnew System::Windows::Forms::Label());
            this->dgvInvoiceItems = (gcnew System::Windows::Forms::DataGridView());
            this->colDescription = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colDays = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colUnitPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colTotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->panelRentalDetails = (gcnew System::Windows::Forms::Panel());
            this->lblDateValue = (gcnew System::Windows::Forms::Label());
            this->lblDateLabel = (gcnew System::Windows::Forms::Label());
            this->lblInvoiceNoValue = (gcnew System::Windows::Forms::Label());
            this->lblInvoiceNoLabel = (gcnew System::Windows::Forms::Label());
            this->lblPeriodValue = (gcnew System::Windows::Forms::Label());
            this->lblPeriodLabel = (gcnew System::Windows::Forms::Label());
            this->lblVehicleValue = (gcnew System::Windows::Forms::Label());
            this->lblVehicleLabel = (gcnew System::Windows::Forms::Label());
            this->lblRentalDetailsTitle = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->panelBillTo = (gcnew System::Windows::Forms::Panel());
            this->lblCustomerID = (gcnew System::Windows::Forms::Label());
            this->lblBillAddress2 = (gcnew System::Windows::Forms::Label());
            this->lblBillAddress1 = (gcnew System::Windows::Forms::Label());
            this->lblAttn = (gcnew System::Windows::Forms::Label());
            this->lblCompanyName = (gcnew System::Windows::Forms::Label());
            this->lblBillToTitle = (gcnew System::Windows::Forms::Label());
            this->lblEmail = (gcnew System::Windows::Forms::Label());
            this->lblPhone = (gcnew System::Windows::Forms::Label());
            this->lblAddress2 = (gcnew System::Windows::Forms::Label());
            this->lblAddress1 = (gcnew System::Windows::Forms::Label());
            this->lblCorporateTag = (gcnew System::Windows::Forms::Label());
            this->lblCompanyTitle = (gcnew System::Windows::Forms::Label());
            this->panel1->SuspendLayout();
            this->panel2->SuspendLayout();
            this->panelCompanyInfo->SuspendLayout();
            this->panel3->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInvoiceItems))->BeginInit();
            this->panelRentalDetails->SuspendLayout();
            this->panelBillTo->SuspendLayout();
            this->SuspendLayout();
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::White;
            this->panel1->Controls->Add(this->label2);
            this->panel1->Controls->Add(this->label1);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(1898, 100);
            this->panel1->TabIndex = 4;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::White;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
            this->label2->ForeColor = System::Drawing::SystemColors::AppWorkspace;
            this->label2->Location = System::Drawing::Point(12, 60);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(148, 32);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Admin Panel";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::White;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
            this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
                static_cast<System::Int32>(static_cast<System::Byte>(110)));
            this->label1->Location = System::Drawing::Point(3, 6);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(364, 54);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Car Rental System";
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
                static_cast<System::Int32>(static_cast<System::Byte>(65)));
            this->panel2->Controls->Add(this->btnExit);
            this->panel2->Controls->Add(this->btnReturns);
            this->panel2->Controls->Add(this->btnRentals);
            this->panel2->Controls->Add(this->btnCustomers);
            this->panel2->Controls->Add(this->btnCars);
            this->panel2->Controls->Add(this->btnDashboard);
            this->panel2->Location = System::Drawing::Point(0, 100);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(250, 927);
            this->panel2->TabIndex = 5;
            // 
            // btnExit
            // 
            this->btnExit->BackColor = System::Drawing::Color::Red;
            this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnExit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->btnExit->ForeColor = System::Drawing::Color::White;
            this->btnExit->Location = System::Drawing::Point(0, 881);
            this->btnExit->Name = L"btnExit";
            this->btnExit->Size = System::Drawing::Size(250, 50);
            this->btnExit->TabIndex = 5;
            this->btnExit->Text = L"EXIT";
            this->btnExit->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
            this->btnExit->UseVisualStyleBackColor = false;
            // 
            // btnReturns
            // 
            this->btnReturns->BackColor = System::Drawing::Color::Transparent;
            this->btnReturns->FlatAppearance->BorderSize = 0;
            this->btnReturns->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnReturns->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->btnReturns->ForeColor = System::Drawing::Color::White;
            this->btnReturns->Location = System::Drawing::Point(0, 260);
            this->btnReturns->Name = L"btnReturns";
            this->btnReturns->Size = System::Drawing::Size(250, 50);
            this->btnReturns->TabIndex = 4;
            this->btnReturns->Text = L"RETURNS";
            this->btnReturns->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnReturns->UseVisualStyleBackColor = false;
            // 
            // btnRentals
            // 
            this->btnRentals->BackColor = System::Drawing::Color::Transparent;
            this->btnRentals->FlatAppearance->BorderSize = 0;
            this->btnRentals->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnRentals->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->btnRentals->ForeColor = System::Drawing::Color::White;
            this->btnRentals->Location = System::Drawing::Point(0, 200);
            this->btnRentals->Name = L"btnRentals";
            this->btnRentals->Size = System::Drawing::Size(250, 50);
            this->btnRentals->TabIndex = 3;
            this->btnRentals->Text = L"RENTALS";
            this->btnRentals->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnRentals->UseVisualStyleBackColor = false;
            // 
            // btnCustomers
            // 
            this->btnCustomers->BackColor = System::Drawing::Color::Transparent;
            this->btnCustomers->FlatAppearance->BorderSize = 0;
            this->btnCustomers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCustomers->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->btnCustomers->ForeColor = System::Drawing::Color::White;
            this->btnCustomers->Location = System::Drawing::Point(0, 140);
            this->btnCustomers->Name = L"btnCustomers";
            this->btnCustomers->Size = System::Drawing::Size(250, 50);
            this->btnCustomers->TabIndex = 2;
            this->btnCustomers->Text = L"CUSTOMERS";
            this->btnCustomers->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnCustomers->UseVisualStyleBackColor = false;
            // 
            // btnCars
            // 
            this->btnCars->BackColor = System::Drawing::Color::Transparent;
            this->btnCars->FlatAppearance->BorderSize = 0;
            this->btnCars->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCars->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->btnCars->ForeColor = System::Drawing::Color::White;
            this->btnCars->Location = System::Drawing::Point(0, 80);
            this->btnCars->Name = L"btnCars";
            this->btnCars->Size = System::Drawing::Size(250, 50);
            this->btnCars->TabIndex = 1;
            this->btnCars->Text = L"CARS";
            this->btnCars->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnCars->UseVisualStyleBackColor = false;
            // 
            // btnDashboard
            // 
            this->btnDashboard->BackColor = System::Drawing::Color::Transparent;
            this->btnDashboard->FlatAppearance->BorderSize = 0;
            this->btnDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnDashboard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->btnDashboard->ForeColor = System::Drawing::Color::White;
            this->btnDashboard->Location = System::Drawing::Point(0, 20);
            this->btnDashboard->Name = L"btnDashboard";
            this->btnDashboard->Size = System::Drawing::Size(250, 50);
            this->btnDashboard->TabIndex = 0;
            this->btnDashboard->Text = L"DASHBOARD";
            this->btnDashboard->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnDashboard->UseVisualStyleBackColor = false;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold));
            this->label3->ForeColor = System::Drawing::Color::DarkBlue;
            this->label3->Location = System::Drawing::Point(256, 102);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(211, 65);
            this->label3->TabIndex = 6;
            this->label3->Text = L"Invoices";
            // 
            // panelCompanyInfo
            // 
            this->panelCompanyInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
                static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->panelCompanyInfo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelCompanyInfo->Controls->Add(this->btnClose);
            this->panelCompanyInfo->Controls->Add(this->btnPrint);
            this->panelCompanyInfo->Controls->Add(this->panel3);
            this->panelCompanyInfo->Controls->Add(this->dgvInvoiceItems);
            this->panelCompanyInfo->Controls->Add(this->panelRentalDetails);
            this->panelCompanyInfo->Controls->Add(this->label10);
            this->panelCompanyInfo->Controls->Add(this->panelBillTo);
            this->panelCompanyInfo->Controls->Add(this->lblEmail);
            this->panelCompanyInfo->Controls->Add(this->lblPhone);
            this->panelCompanyInfo->Controls->Add(this->lblAddress2);
            this->panelCompanyInfo->Controls->Add(this->lblAddress1);
            this->panelCompanyInfo->Controls->Add(this->lblCorporateTag);
            this->panelCompanyInfo->Controls->Add(this->lblCompanyTitle);
            this->panelCompanyInfo->Location = System::Drawing::Point(280, 170);
            this->panelCompanyInfo->Name = L"panelCompanyInfo";
            this->panelCompanyInfo->Size = System::Drawing::Size(1593, 857);
            this->panelCompanyInfo->TabIndex = 7;
            // 
            // btnClose
            // 
            this->btnClose->BackColor = System::Drawing::Color::Gray;
            this->btnClose->FlatAppearance->BorderSize = 0;
            this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClose->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnClose->ForeColor = System::Drawing::Color::White;
            this->btnClose->Location = System::Drawing::Point(874, 787);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(120, 40);
            this->btnClose->TabIndex = 22;
            this->btnClose->Text = L"CLOSE";
            this->btnClose->UseVisualStyleBackColor = false;
            // 
            // btnPrint
            // 
            this->btnPrint->BackColor = System::Drawing::Color::DarkBlue;
            this->btnPrint->FlatAppearance->BorderSize = 0;
            this->btnPrint->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnPrint->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnPrint->ForeColor = System::Drawing::Color::White;
            this->btnPrint->Location = System::Drawing::Point(641, 787);
            this->btnPrint->Name = L"btnPrint";
            this->btnPrint->Size = System::Drawing::Size(187, 40);
            this->btnPrint->TabIndex = 21;
            this->btnPrint->Text = L"PRINT INVOICE";
            this->btnPrint->UseVisualStyleBackColor = false;
            // 
            // panel3
            // 
            this->panel3->BackColor = System::Drawing::Color::White;
            this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel3->Controls->Add(this->lblTotalValue);
            this->panel3->Controls->Add(this->lblTotalLabel);
            this->panel3->Controls->Add(this->label4);
            this->panel3->Controls->Add(this->lblSubtotalLabel);
            this->panel3->Controls->Add(this->lblTaxValue);
            this->panel3->Controls->Add(this->lblSubtotalValue);
            this->panel3->Controls->Add(this->lblTaxLabel);
            this->panel3->Location = System::Drawing::Point(1165, 530);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(413, 200);
            this->panel3->TabIndex = 20;
            // 
            // lblTotalValue
            // 
            this->lblTotalValue->AutoSize = true;
            this->lblTotalValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->lblTotalValue->ForeColor = System::Drawing::Color::Green;
            this->lblTotalValue->Location = System::Drawing::Point(246, 151);
            this->lblTotalValue->Name = L"lblTotalValue";
            this->lblTotalValue->Size = System::Drawing::Size(145, 38);
            this->lblTotalValue->TabIndex = 23;
            this->lblTotalValue->Text = L"$1,372.53";
            // 
            // lblTotalLabel
            // 
            this->lblTotalLabel->AutoSize = true;
            this->lblTotalLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->lblTotalLabel->ForeColor = System::Drawing::Color::DarkBlue;
            this->lblTotalLabel->Location = System::Drawing::Point(3, 100);
            this->lblTotalLabel->Name = L"lblTotalLabel";
            this->lblTotalLabel->Size = System::Drawing::Size(242, 38);
            this->lblTotalLabel->TabIndex = 22;
            this->lblTotalLabel->Text = L"TOTAL AMOUNT:";
            // 
            // label4
            // 
            this->label4->BackColor = System::Drawing::Color::LightGray;
            this->label4->Location = System::Drawing::Point(1, 88);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(407, 2);
            this->label4->TabIndex = 24;
            // 
            // lblSubtotalLabel
            // 
            this->lblSubtotalLabel->AutoSize = true;
            this->lblSubtotalLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->lblSubtotalLabel->ForeColor = System::Drawing::Color::Gray;
            this->lblSubtotalLabel->Location = System::Drawing::Point(3, 9);
            this->lblSubtotalLabel->Name = L"lblSubtotalLabel";
            this->lblSubtotalLabel->Size = System::Drawing::Size(98, 30);
            this->lblSubtotalLabel->TabIndex = 16;
            this->lblSubtotalLabel->Text = L"Subtotal:";
            this->lblSubtotalLabel->Click += gcnew System::EventHandler(this, &InvoiceForm::lblSubtotalLabel_Click);
            // 
            // lblTaxValue
            // 
            this->lblTaxValue->AutoSize = true;
            this->lblTaxValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->lblTaxValue->ForeColor = System::Drawing::Color::Black;
            this->lblTaxValue->Location = System::Drawing::Point(284, 49);
            this->lblTaxValue->Name = L"lblTaxValue";
            this->lblTaxValue->Size = System::Drawing::Size(90, 30);
            this->lblTaxValue->TabIndex = 19;
            this->lblTaxValue->Text = L"$107.53";
            // 
            // lblSubtotalValue
            // 
            this->lblSubtotalValue->AutoSize = true;
            this->lblSubtotalValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->lblSubtotalValue->ForeColor = System::Drawing::Color::Black;
            this->lblSubtotalValue->Location = System::Drawing::Point(284, 9);
            this->lblSubtotalValue->Name = L"lblSubtotalValue";
            this->lblSubtotalValue->Size = System::Drawing::Size(107, 30);
            this->lblSubtotalValue->TabIndex = 17;
            this->lblSubtotalValue->Text = L"$1,265.00";
            // 
            // lblTaxLabel
            // 
            this->lblTaxLabel->AutoSize = true;
            this->lblTaxLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->lblTaxLabel->ForeColor = System::Drawing::Color::Gray;
            this->lblTaxLabel->Location = System::Drawing::Point(3, 49);
            this->lblTaxLabel->Name = L"lblTaxLabel";
            this->lblTaxLabel->Size = System::Drawing::Size(116, 30);
            this->lblTaxLabel->TabIndex = 18;
            this->lblTaxLabel->Text = L"Tax (8.5%):";
            // 
            // dgvInvoiceItems
            // 
            this->dgvInvoiceItems->BackgroundColor = System::Drawing::Color::White;
            this->dgvInvoiceItems->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvInvoiceItems->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
                this->colDescription,
                    this->colDays, this->colUnitPrice, this->colTotal
            });
            this->dgvInvoiceItems->Location = System::Drawing::Point(11, 530);
            this->dgvInvoiceItems->Name = L"dgvInvoiceItems";
            this->dgvInvoiceItems->RowHeadersVisible = false;
            this->dgvInvoiceItems->RowHeadersWidth = 62;
            this->dgvInvoiceItems->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvInvoiceItems->Size = System::Drawing::Size(1133, 200);
            this->dgvInvoiceItems->TabIndex = 15;
            // 
            // colDescription
            // 
            this->colDescription->HeaderText = L"DESCRIPTION";
            this->colDescription->MinimumWidth = 8;
            this->colDescription->Name = L"colDescription";
            this->colDescription->ReadOnly = true;
            this->colDescription->Width = 380;
            // 
            // colDays
            // 
            this->colDays->HeaderText = L"DAYS";
            this->colDays->MinimumWidth = 8;
            this->colDays->Name = L"colDays";
            this->colDays->ReadOnly = true;
            this->colDays->Width = 80;
            // 
            // colUnitPrice
            // 
            this->colUnitPrice->HeaderText = L"UNIT PRICE";
            this->colUnitPrice->MinimumWidth = 8;
            this->colUnitPrice->Name = L"colUnitPrice";
            this->colUnitPrice->ReadOnly = true;
            this->colUnitPrice->Width = 150;
            // 
            // colTotal
            // 
            this->colTotal->HeaderText = L"TOTAL";
            this->colTotal->MinimumWidth = 8;
            this->colTotal->Name = L"colTotal";
            this->colTotal->ReadOnly = true;
            this->colTotal->Width = 130;
            // 
            // panelRentalDetails
            // 
            this->panelRentalDetails->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
                static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->panelRentalDetails->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelRentalDetails->Controls->Add(this->lblDateValue);
            this->panelRentalDetails->Controls->Add(this->lblDateLabel);
            this->panelRentalDetails->Controls->Add(this->lblInvoiceNoValue);
            this->panelRentalDetails->Controls->Add(this->lblInvoiceNoLabel);
            this->panelRentalDetails->Controls->Add(this->lblPeriodValue);
            this->panelRentalDetails->Controls->Add(this->lblPeriodLabel);
            this->panelRentalDetails->Controls->Add(this->lblVehicleValue);
            this->panelRentalDetails->Controls->Add(this->lblVehicleLabel);
            this->panelRentalDetails->Controls->Add(this->lblRentalDetailsTitle);
            this->panelRentalDetails->Location = System::Drawing::Point(798, 264);
            this->panelRentalDetails->Name = L"panelRentalDetails";
            this->panelRentalDetails->Size = System::Drawing::Size(780, 250);
            this->panelRentalDetails->TabIndex = 14;
            // 
            // lblDateValue
            // 
            this->lblDateValue->AutoSize = true;
            this->lblDateValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblDateValue->Location = System::Drawing::Point(516, 167);
            this->lblDateValue->Name = L"lblDateValue";
            this->lblDateValue->Size = System::Drawing::Size(116, 28);
            this->lblDateValue->TabIndex = 8;
            this->lblDateValue->Text = L"10/24/2025";
            // 
            // lblDateLabel
            // 
            this->lblDateLabel->AutoSize = true;
            this->lblDateLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->lblDateLabel->ForeColor = System::Drawing::Color::Gray;
            this->lblDateLabel->Location = System::Drawing::Point(14, 167);
            this->lblDateLabel->Name = L"lblDateLabel";
            this->lblDateLabel->Size = System::Drawing::Size(62, 28);
            this->lblDateLabel->TabIndex = 7;
            this->lblDateLabel->Text = L"Date:";
            // 
            // lblInvoiceNoValue
            // 
            this->lblInvoiceNoValue->AutoSize = true;
            this->lblInvoiceNoValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblInvoiceNoValue->Location = System::Drawing::Point(497, 130);
            this->lblInvoiceNoValue->Name = L"lblInvoiceNoValue";
            this->lblInvoiceNoValue->Size = System::Drawing::Size(148, 28);
            this->lblInvoiceNoValue->TabIndex = 6;
            this->lblInvoiceNoValue->Text = L"INV-2024-0082";
            // 
            // lblInvoiceNoLabel
            // 
            this->lblInvoiceNoLabel->AutoSize = true;
            this->lblInvoiceNoLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->lblInvoiceNoLabel->ForeColor = System::Drawing::Color::Gray;
            this->lblInvoiceNoLabel->Location = System::Drawing::Point(14, 130);
            this->lblInvoiceNoLabel->Name = L"lblInvoiceNoLabel";
            this->lblInvoiceNoLabel->Size = System::Drawing::Size(103, 28);
            this->lblInvoiceNoLabel->TabIndex = 5;
            this->lblInvoiceNoLabel->Text = L"Invoice #:";
            // 
            // lblPeriodValue
            // 
            this->lblPeriodValue->AutoSize = true;
            this->lblPeriodValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblPeriodValue->Location = System::Drawing::Point(488, 93);
            this->lblPeriodValue->Name = L"lblPeriodValue";
            this->lblPeriodValue->Size = System::Drawing::Size(219, 28);
            this->lblPeriodValue->TabIndex = 4;
            this->lblPeriodValue->Text = L"Oct 17 - Oct 24 (7 days)";
            // 
            // lblPeriodLabel
            // 
            this->lblPeriodLabel->AutoSize = true;
            this->lblPeriodLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->lblPeriodLabel->ForeColor = System::Drawing::Color::Gray;
            this->lblPeriodLabel->Location = System::Drawing::Point(14, 93);
            this->lblPeriodLabel->Name = L"lblPeriodLabel";
            this->lblPeriodLabel->Size = System::Drawing::Size(77, 28);
            this->lblPeriodLabel->TabIndex = 3;
            this->lblPeriodLabel->Text = L"Period:";
            // 
            // lblVehicleValue
            // 
            this->lblVehicleValue->AutoSize = true;
            this->lblVehicleValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblVehicleValue->Location = System::Drawing::Point(488, 54);
            this->lblVehicleValue->Name = L"lblVehicleValue";
            this->lblVehicleValue->Size = System::Drawing::Size(180, 28);
            this->lblVehicleValue->TabIndex = 2;
            this->lblVehicleValue->Text = L"2023 Tesla Model 3";
            this->lblVehicleValue->Click += gcnew System::EventHandler(this, &InvoiceForm::lblVehicleValue_Click);
            // 
            // lblVehicleLabel
            // 
            this->lblVehicleLabel->AutoSize = true;
            this->lblVehicleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->lblVehicleLabel->ForeColor = System::Drawing::Color::Gray;
            this->lblVehicleLabel->Location = System::Drawing::Point(14, 54);
            this->lblVehicleLabel->Name = L"lblVehicleLabel";
            this->lblVehicleLabel->Size = System::Drawing::Size(85, 28);
            this->lblVehicleLabel->TabIndex = 1;
            this->lblVehicleLabel->Text = L"Vehicle:";
            // 
            // lblRentalDetailsTitle
            // 
            this->lblRentalDetailsTitle->AutoSize = true;
            this->lblRentalDetailsTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->lblRentalDetailsTitle->ForeColor = System::Drawing::Color::DarkBlue;
            this->lblRentalDetailsTitle->Location = System::Drawing::Point(3, 12);
            this->lblRentalDetailsTitle->Name = L"lblRentalDetailsTitle";
            this->lblRentalDetailsTitle->Size = System::Drawing::Size(183, 30);
            this->lblRentalDetailsTitle->TabIndex = 0;
            this->lblRentalDetailsTitle->Text = L"RENTAL DETAILS";
            // 
            // label10
            // 
            this->label10->BackColor = System::Drawing::Color::LightGray;
            this->label10->Location = System::Drawing::Point(7, 237);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(1575, 2);
            this->label10->TabIndex = 23;
            // 
            // panelBillTo
            // 
            this->panelBillTo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelBillTo->Controls->Add(this->lblCustomerID);
            this->panelBillTo->Controls->Add(this->lblBillAddress2);
            this->panelBillTo->Controls->Add(this->lblBillAddress1);
            this->panelBillTo->Controls->Add(this->lblAttn);
            this->panelBillTo->Controls->Add(this->lblCompanyName);
            this->panelBillTo->Controls->Add(this->lblBillToTitle);
            this->panelBillTo->Location = System::Drawing::Point(11, 264);
            this->panelBillTo->Name = L"panelBillTo";
            this->panelBillTo->Size = System::Drawing::Size(688, 250);
            this->panelBillTo->TabIndex = 12;
            // 
            // lblCustomerID
            // 
            this->lblCustomerID->AutoSize = true;
            this->lblCustomerID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Italic));
            this->lblCustomerID->ForeColor = System::Drawing::Color::DarkGray;
            this->lblCustomerID->Location = System::Drawing::Point(11, 205);
            this->lblCustomerID->Name = L"lblCustomerID";
            this->lblCustomerID->Size = System::Drawing::Size(207, 25);
            this->lblCustomerID->TabIndex = 5;
            this->lblCustomerID->Text = L"Customer ID: #CTS-9921";
            // 
            // lblBillAddress2
            // 
            this->lblBillAddress2->AutoSize = true;
            this->lblBillAddress2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblBillAddress2->ForeColor = System::Drawing::Color::Gray;
            this->lblBillAddress2->Location = System::Drawing::Point(11, 167);
            this->lblBillAddress2->Name = L"lblBillAddress2";
            this->lblBillAddress2->Size = System::Drawing::Size(224, 28);
            this->lblBillAddress2->TabIndex = 4;
            this->lblBillAddress2->Text = L"San Francisco, CA 94105";
            // 
            // lblBillAddress1
            // 
            this->lblBillAddress1->AutoSize = true;
            this->lblBillAddress1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblBillAddress1->ForeColor = System::Drawing::Color::Gray;
            this->lblBillAddress1->Location = System::Drawing::Point(11, 130);
            this->lblBillAddress1->Name = L"lblBillAddress1";
            this->lblBillAddress1->Size = System::Drawing::Size(216, 28);
            this->lblBillAddress1->TabIndex = 3;
            this->lblBillAddress1->Text = L"455 Market St, Floor 12";
            // 
            // lblAttn
            // 
            this->lblAttn->AutoSize = true;
            this->lblAttn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblAttn->ForeColor = System::Drawing::Color::Gray;
            this->lblAttn->Location = System::Drawing::Point(11, 93);
            this->lblAttn->Name = L"lblAttn";
            this->lblAttn->Size = System::Drawing::Size(175, 28);
            this->lblAttn->TabIndex = 2;
            this->lblAttn->Text = L"Attn: Sarah Jenkins";
            // 
            // lblCompanyName
            // 
            this->lblCompanyName->AutoSize = true;
            this->lblCompanyName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->lblCompanyName->Location = System::Drawing::Point(11, 52);
            this->lblCompanyName->Name = L"lblCompanyName";
            this->lblCompanyName->Size = System::Drawing::Size(277, 30);
            this->lblCompanyName->TabIndex = 1;
            this->lblCompanyName->Text = L"Global Tech Solutions Inc.";
            // 
            // lblBillToTitle
            // 
            this->lblBillToTitle->AutoSize = true;
            this->lblBillToTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->lblBillToTitle->ForeColor = System::Drawing::Color::DarkBlue;
            this->lblBillToTitle->Location = System::Drawing::Point(3, 12);
            this->lblBillToTitle->Name = L"lblBillToTitle";
            this->lblBillToTitle->Size = System::Drawing::Size(97, 30);
            this->lblBillToTitle->TabIndex = 0;
            this->lblBillToTitle->Text = L"BILL TO:";
            // 
            // lblEmail
            // 
            this->lblEmail->AutoSize = true;
            this->lblEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblEmail->ForeColor = System::Drawing::Color::Gray;
            this->lblEmail->Location = System::Drawing::Point(23, 179);
            this->lblEmail->Name = L"lblEmail";
            this->lblEmail->Size = System::Drawing::Size(242, 25);
            this->lblEmail->TabIndex = 11;
            this->lblEmail->Text = L"Email: billing@autolease.com";
            // 
            // lblPhone
            // 
            this->lblPhone->AutoSize = true;
            this->lblPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblPhone->ForeColor = System::Drawing::Color::Gray;
            this->lblPhone->Location = System::Drawing::Point(23, 154);
            this->lblPhone->Name = L"lblPhone";
            this->lblPhone->Size = System::Drawing::Size(193, 25);
            this->lblPhone->TabIndex = 10;
            this->lblPhone->Text = L"Phone: (555) 012-3456";
            // 
            // lblAddress2
            // 
            this->lblAddress2->AutoSize = true;
            this->lblAddress2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblAddress2->ForeColor = System::Drawing::Color::Gray;
            this->lblAddress2->Location = System::Drawing::Point(23, 129);
            this->lblAddress2->Name = L"lblAddress2";
            this->lblAddress2->Size = System::Drawing::Size(153, 25);
            this->lblAddress2->TabIndex = 9;
            this->lblAddress2->Text = L"Chicago, IL 60601";
            // 
            // lblAddress1
            // 
            this->lblAddress1->AutoSize = true;
            this->lblAddress1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblAddress1->ForeColor = System::Drawing::Color::Gray;
            this->lblAddress1->Location = System::Drawing::Point(23, 104);
            this->lblAddress1->Name = L"lblAddress1";
            this->lblAddress1->Size = System::Drawing::Size(247, 25);
            this->lblAddress1->TabIndex = 8;
            this->lblAddress1->Text = L"123 Enterprise Way, Suite 500";
            // 
            // lblCorporateTag
            // 
            this->lblCorporateTag->AutoSize = true;
            this->lblCorporateTag->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->lblCorporateTag->ForeColor = System::Drawing::Color::Gray;
            this->lblCorporateTag->Location = System::Drawing::Point(23, 60);
            this->lblCorporateTag->Name = L"lblCorporateTag";
            this->lblCorporateTag->Size = System::Drawing::Size(298, 25);
            this->lblCorporateTag->TabIndex = 1;
            this->lblCorporateTag->Text = L"CORPORATE RENTAL SOLUTIONS";
            // 
            // lblCompanyTitle
            // 
            this->lblCompanyTitle->AutoSize = true;
            this->lblCompanyTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->lblCompanyTitle->ForeColor = System::Drawing::Color::DarkBlue;
            this->lblCompanyTitle->Location = System::Drawing::Point(3, 7);
            this->lblCompanyTitle->Name = L"lblCompanyTitle";
            this->lblCompanyTitle->Size = System::Drawing::Size(288, 45);
            this->lblCompanyTitle->TabIndex = 0;
            this->lblCompanyTitle->Text = L"Car Rental System";
            // 
            // InvoiceForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(1898, 1024);
            this->Controls->Add(this->panelCompanyInfo);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->panel1);
            this->Name = L"InvoiceForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Invoices";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->panel2->ResumeLayout(false);
            this->panelCompanyInfo->ResumeLayout(false);
            this->panelCompanyInfo->PerformLayout();
            this->panel3->ResumeLayout(false);
            this->panel3->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInvoiceItems))->EndInit();
            this->panelRentalDetails->ResumeLayout(false);
            this->panelRentalDetails->PerformLayout();
            this->panelBillTo->ResumeLayout(false);
            this->panelBillTo->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private: System::Void lblVehicleValue_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void lblSubtotalLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}