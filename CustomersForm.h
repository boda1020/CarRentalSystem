#pragma once

namespace CarRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CustomersForm
	/// </summary>
	public ref class CustomersForm : public System::Windows::Forms::Form
	{
	public:
		CustomersForm(void)
		{
			InitializeComponent();
			LoadCustomersFromFile();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CustomersForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Button^ btnReturns;
	private: System::Windows::Forms::Button^ btnRentals;
	private: System::Windows::Forms::Button^ btnCustomers;
	private: System::Windows::Forms::Button^ btnCars;
	private: System::Windows::Forms::Button^ btnDashboard;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panelTotalCustomers;
	private: System::Windows::Forms::Label^ lblTotalCustomersText;


	private: System::Windows::Forms::Label^ lblTotalCustomersNum;
	private: System::Windows::Forms::Label^ lblActiveRentalsText;



	private: System::Windows::Forms::Label^ lblActiveRentalsNum;
	private: System::Windows::Forms::Panel^ panelComplianceRate;
	private: System::Windows::Forms::Label^ lblComplianceRateText;



	private: System::Windows::Forms::Label^ lblComplianceRateNum;
	private: System::Windows::Forms::Panel^ panelNewThisMonth;
	private: System::Windows::Forms::Label^ lblNewThisMonthText;



	private: System::Windows::Forms::Label^ lblNewThisMonthNum;

	private: System::Windows::Forms::Panel^ panelActiveRentals;
	private: System::Windows::Forms::Panel^ panelControls;
	private: System::Windows::Forms::Label^ lblShowing;
	private: System::Windows::Forms::Button^ btnFilters;
	private: System::Windows::Forms::Button^ btnExportCSV;
	private: System::Windows::Forms::DataGridView^ dgvCustomers;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCustomerID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEmail;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colPhone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colStatus;
	private: System::Windows::Forms::DataGridViewButtonColumn^ colEdit;
	private: System::Windows::Forms::DataGridViewButtonColumn^ colDelete;
	private: System::Windows::Forms::DataGridViewButtonColumn^ colView;
	private: System::Windows::Forms::DataGridViewButtonColumn^ colInvoice;
	private: System::Windows::Forms::Panel^ panelRecentActivity;
	private: System::Windows::Forms::Label^ lblActivity2;
	private: System::Windows::Forms::Label^ lblActivity1;
	private: System::Windows::Forms::Label^ lblRecentActivityTitle;
	private: System::Windows::Forms::Label^ lblActivity3;
	private: System::Windows::Forms::Panel^ panelSystemAlert;
	private: System::Windows::Forms::Label^ lblSystemAlertTitle;
	private: System::Windows::Forms::Button^ btnReviewDocs;
	private: System::Windows::Forms::Label^ lblAlertText2;
	private: System::Windows::Forms::Label^ lblAlertText1;
	private: System::Windows::Forms::Label^ lblRowsCount;
	private: System::Windows::Forms::Button^ btnAddCustomer;












	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panelTotalCustomers = (gcnew System::Windows::Forms::Panel());
			this->lblTotalCustomersText = (gcnew System::Windows::Forms::Label());
			this->lblTotalCustomersNum = (gcnew System::Windows::Forms::Label());
			this->panelActiveRentals = (gcnew System::Windows::Forms::Panel());
			this->lblActiveRentalsText = (gcnew System::Windows::Forms::Label());
			this->lblActiveRentalsNum = (gcnew System::Windows::Forms::Label());
			this->panelComplianceRate = (gcnew System::Windows::Forms::Panel());
			this->lblComplianceRateText = (gcnew System::Windows::Forms::Label());
			this->lblComplianceRateNum = (gcnew System::Windows::Forms::Label());
			this->panelNewThisMonth = (gcnew System::Windows::Forms::Panel());
			this->lblNewThisMonthText = (gcnew System::Windows::Forms::Label());
			this->lblNewThisMonthNum = (gcnew System::Windows::Forms::Label());
			this->panelControls = (gcnew System::Windows::Forms::Panel());
			this->btnExportCSV = (gcnew System::Windows::Forms::Button());
			this->btnFilters = (gcnew System::Windows::Forms::Button());
			this->lblShowing = (gcnew System::Windows::Forms::Label());
			this->dgvCustomers = (gcnew System::Windows::Forms::DataGridView());
			this->colCustomerID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEmail = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPhone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colStatus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEdit = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->colDelete = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->colView = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->colInvoice = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->panelRecentActivity = (gcnew System::Windows::Forms::Panel());
			this->lblActivity3 = (gcnew System::Windows::Forms::Label());
			this->lblActivity2 = (gcnew System::Windows::Forms::Label());
			this->lblActivity1 = (gcnew System::Windows::Forms::Label());
			this->lblRecentActivityTitle = (gcnew System::Windows::Forms::Label());
			this->panelSystemAlert = (gcnew System::Windows::Forms::Panel());
			this->btnReviewDocs = (gcnew System::Windows::Forms::Button());
			this->lblAlertText2 = (gcnew System::Windows::Forms::Label());
			this->lblAlertText1 = (gcnew System::Windows::Forms::Label());
			this->lblSystemAlertTitle = (gcnew System::Windows::Forms::Label());
			this->lblRowsCount = (gcnew System::Windows::Forms::Label());
			this->btnAddCustomer = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panelTotalCustomers->SuspendLayout();
			this->panelActiveRentals->SuspendLayout();
			this->panelComplianceRate->SuspendLayout();
			this->panelNewThisMonth->SuspendLayout();
			this->panelControls->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCustomers))->BeginInit();
			this->panelRecentActivity->SuspendLayout();
			this->panelSystemAlert->SuspendLayout();
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
			this->panel1->TabIndex = 2;
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
			this->panel2->TabIndex = 3;
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
			this->btnExit->Click += gcnew System::EventHandler(this, &CustomersForm::btnExit_Click);
			// 
			// btnReturns
			// 
			this->btnReturns->BackColor = System::Drawing::Color::Transparent;
			this->btnReturns->FlatAppearance->BorderSize = 0;
			this->btnReturns->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReturns->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->btnReturns->ForeColor = System::Drawing::Color::White;
			this->btnReturns->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnReturns->Location = System::Drawing::Point(0, 260);
			this->btnReturns->Name = L"btnReturns";
			this->btnReturns->Size = System::Drawing::Size(250, 50);
			this->btnReturns->TabIndex = 4;
			this->btnReturns->Text = L"RETURNS";
			this->btnReturns->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnReturns->UseVisualStyleBackColor = false;
			this->btnReturns->Click += gcnew System::EventHandler(this, &CustomersForm::btnReturns_Click);
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
			this->btnRentals->Click += gcnew System::EventHandler(this, &CustomersForm::btnRentals_Click);
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
			this->btnCars->Click += gcnew System::EventHandler(this, &CustomersForm::btnCars_Click);
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
			this->btnDashboard->Click += gcnew System::EventHandler(this, &CustomersForm::btnDashboard_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::DarkBlue;
			this->label3->Location = System::Drawing::Point(256, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(470, 65);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Customer Directory";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->label4->ForeColor = System::Drawing::Color::Gray;
			this->label4->Location = System::Drawing::Point(275, 165);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(656, 30);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Manage corporate and individual accounts for terminal operations.";
			// 
			// panelTotalCustomers
			// 
			this->panelTotalCustomers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panelTotalCustomers->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTotalCustomers->Controls->Add(this->lblTotalCustomersText);
			this->panelTotalCustomers->Controls->Add(this->lblTotalCustomersNum);
			this->panelTotalCustomers->Location = System::Drawing::Point(289, 218);
			this->panelTotalCustomers->Name = L"panelTotalCustomers";
			this->panelTotalCustomers->Size = System::Drawing::Size(370, 150);
			this->panelTotalCustomers->TabIndex = 7;
			// 
			// lblTotalCustomersText
			// 
			this->lblTotalCustomersText->AutoSize = true;
			this->lblTotalCustomersText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalCustomersText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblTotalCustomersText->Location = System::Drawing::Point(20, 19);
			this->lblTotalCustomersText->Name = L"lblTotalCustomersText";
			this->lblTotalCustomersText->Size = System::Drawing::Size(214, 30);
			this->lblTotalCustomersText->TabIndex = 1;
			this->lblTotalCustomersText->Text = L"TOTAL CUSTOMERS";
			// 
			// lblTotalCustomersNum
			// 
			this->lblTotalCustomersNum->AutoSize = true;
			this->lblTotalCustomersNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalCustomersNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblTotalCustomersNum->Location = System::Drawing::Point(25, 49);
			this->lblTotalCustomersNum->Name = L"lblTotalCustomersNum";
			this->lblTotalCustomersNum->Size = System::Drawing::Size(81, 96);
			this->lblTotalCustomersNum->TabIndex = 0;
			this->lblTotalCustomersNum->Text = L"0";
			// 
			// panelActiveRentals
			// 
			this->panelActiveRentals->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->panelActiveRentals->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelActiveRentals->Controls->Add(this->lblActiveRentalsText);
			this->panelActiveRentals->Controls->Add(this->lblActiveRentalsNum);
			this->panelActiveRentals->Location = System::Drawing::Point(691, 218);
			this->panelActiveRentals->Name = L"panelActiveRentals";
			this->panelActiveRentals->Size = System::Drawing::Size(370, 150);
			this->panelActiveRentals->TabIndex = 8;
			// 
			// lblActiveRentalsText
			// 
			this->lblActiveRentalsText->AutoSize = true;
			this->lblActiveRentalsText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblActiveRentalsText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblActiveRentalsText->Location = System::Drawing::Point(20, 19);
			this->lblActiveRentalsText->Name = L"lblActiveRentalsText";
			this->lblActiveRentalsText->Size = System::Drawing::Size(187, 30);
			this->lblActiveRentalsText->TabIndex = 1;
			this->lblActiveRentalsText->Text = L"ACTIVE RENTALS";
			// 
			// lblActiveRentalsNum
			// 
			this->lblActiveRentalsNum->AutoSize = true;
			this->lblActiveRentalsNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblActiveRentalsNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblActiveRentalsNum->Location = System::Drawing::Point(25, 49);
			this->lblActiveRentalsNum->Name = L"lblActiveRentalsNum";
			this->lblActiveRentalsNum->Size = System::Drawing::Size(81, 96);
			this->lblActiveRentalsNum->TabIndex = 0;
			this->lblActiveRentalsNum->Text = L"0";
			// 
			// panelComplianceRate
			// 
			this->panelComplianceRate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->panelComplianceRate->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelComplianceRate->Controls->Add(this->lblComplianceRateText);
			this->panelComplianceRate->Controls->Add(this->lblComplianceRateNum);
			this->panelComplianceRate->Location = System::Drawing::Point(1097, 218);
			this->panelComplianceRate->Name = L"panelComplianceRate";
			this->panelComplianceRate->Size = System::Drawing::Size(370, 150);
			this->panelComplianceRate->TabIndex = 9;
			// 
			// lblComplianceRateText
			// 
			this->lblComplianceRateText->AutoSize = true;
			this->lblComplianceRateText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblComplianceRateText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblComplianceRateText->Location = System::Drawing::Point(20, 19);
			this->lblComplianceRateText->Name = L"lblComplianceRateText";
			this->lblComplianceRateText->Size = System::Drawing::Size(213, 30);
			this->lblComplianceRateText->TabIndex = 1;
			this->lblComplianceRateText->Text = L"COMPLIANCE RATE";
			// 
			// lblComplianceRateNum
			// 
			this->lblComplianceRateNum->AutoSize = true;
			this->lblComplianceRateNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblComplianceRateNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblComplianceRateNum->Location = System::Drawing::Point(25, 49);
			this->lblComplianceRateNum->Name = L"lblComplianceRateNum";
			this->lblComplianceRateNum->Size = System::Drawing::Size(81, 96);
			this->lblComplianceRateNum->TabIndex = 0;
			this->lblComplianceRateNum->Text = L"0";
			// 
			// panelNewThisMonth
			// 
			this->panelNewThisMonth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->panelNewThisMonth->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelNewThisMonth->Controls->Add(this->lblNewThisMonthText);
			this->panelNewThisMonth->Controls->Add(this->lblNewThisMonthNum);
			this->panelNewThisMonth->Location = System::Drawing::Point(1503, 218);
			this->panelNewThisMonth->Name = L"panelNewThisMonth";
			this->panelNewThisMonth->Size = System::Drawing::Size(370, 150);
			this->panelNewThisMonth->TabIndex = 10;
			// 
			// lblNewThisMonthText
			// 
			this->lblNewThisMonthText->AutoSize = true;
			this->lblNewThisMonthText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNewThisMonthText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblNewThisMonthText->Location = System::Drawing::Point(20, 19);
			this->lblNewThisMonthText->Name = L"lblNewThisMonthText";
			this->lblNewThisMonthText->Size = System::Drawing::Size(210, 30);
			this->lblNewThisMonthText->TabIndex = 1;
			this->lblNewThisMonthText->Text = L"NEW THIS MONTH";
			// 
			// lblNewThisMonthNum
			// 
			this->lblNewThisMonthNum->AutoSize = true;
			this->lblNewThisMonthNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNewThisMonthNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblNewThisMonthNum->Location = System::Drawing::Point(25, 49);
			this->lblNewThisMonthNum->Name = L"lblNewThisMonthNum";
			this->lblNewThisMonthNum->Size = System::Drawing::Size(81, 96);
			this->lblNewThisMonthNum->TabIndex = 0;
			this->lblNewThisMonthNum->Text = L"0";
			// 
			// panelControls
			// 
			this->panelControls->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->panelControls->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelControls->Controls->Add(this->btnExportCSV);
			this->panelControls->Controls->Add(this->btnFilters);
			this->panelControls->Controls->Add(this->lblShowing);
			this->panelControls->Location = System::Drawing::Point(280, 374);
			this->panelControls->Name = L"panelControls";
			this->panelControls->Size = System::Drawing::Size(566, 40);
			this->panelControls->TabIndex = 11;
			// 
			// btnExportCSV
			// 
			this->btnExportCSV->BackColor = System::Drawing::Color::DarkBlue;
			this->btnExportCSV->FlatAppearance->BorderSize = 0;
			this->btnExportCSV->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExportCSV->ForeColor = System::Drawing::Color::White;
			this->btnExportCSV->Location = System::Drawing::Point(410, 5);
			this->btnExportCSV->Name = L"btnExportCSV";
			this->btnExportCSV->Size = System::Drawing::Size(147, 30);
			this->btnExportCSV->TabIndex = 12;
			this->btnExportCSV->Text = L"EXPORT CSV";
			this->btnExportCSV->UseVisualStyleBackColor = false;
			this->btnExportCSV->Click += gcnew System::EventHandler(this, &CustomersForm::btnExportCSV_Click);
			// 
			// btnFilters
			// 
			this->btnFilters->BackColor = System::Drawing::Color::DarkBlue;
			this->btnFilters->FlatAppearance->BorderSize = 0;
			this->btnFilters->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFilters->ForeColor = System::Drawing::Color::White;
			this->btnFilters->Location = System::Drawing::Point(273, 5);
			this->btnFilters->Name = L"btnFilters";
			this->btnFilters->Size = System::Drawing::Size(105, 30);
			this->btnFilters->TabIndex = 12;
			this->btnFilters->Text = L"FILTERS";
			this->btnFilters->UseVisualStyleBackColor = false;
			this->btnFilters->Click += gcnew System::EventHandler(this, &CustomersForm::btnFilters_Click);
			// 
			// lblShowing
			// 
			this->lblShowing->AutoSize = true;
			this->lblShowing->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblShowing->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblShowing->Location = System::Drawing::Point(3, 3);
			this->lblShowing->Name = L"lblShowing";
			this->lblShowing->Size = System::Drawing::Size(250, 28);
			this->lblShowing->TabIndex = 12;
			this->lblShowing->Text = L"SHOWING: ALL RECORDS";
			this->lblShowing->Click += gcnew System::EventHandler(this, &CustomersForm::label5_Click);
			// 
			// dgvCustomers
			// 
			this->dgvCustomers->AllowUserToOrderColumns = true;
			this->dgvCustomers->BackgroundColor = System::Drawing::Color::White;
			this->dgvCustomers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCustomers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->colCustomerID,
					this->colName, this->colEmail, this->colPhone, this->colStatus, this->colEdit, this->colDelete, this->colView, this->colInvoice
			});
			this->dgvCustomers->Location = System::Drawing::Point(280, 420);
			this->dgvCustomers->Name = L"dgvCustomers";
			this->dgvCustomers->RowHeadersVisible = false;
			this->dgvCustomers->RowHeadersWidth = 62;
			this->dgvCustomers->RowTemplate->Height = 28;
			this->dgvCustomers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvCustomers->Size = System::Drawing::Size(1593, 400);
			this->dgvCustomers->TabIndex = 12;
			this->dgvCustomers->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CustomersForm::dgvCustomers_CellClick);
			// 
			// colCustomerID
			// 
			this->colCustomerID->HeaderText = L"CUSTOMER ID";
			this->colCustomerID->MinimumWidth = 8;
			this->colCustomerID->Name = L"colCustomerID";
			this->colCustomerID->ReadOnly = true;
			this->colCustomerID->Width = 140;
			// 
			// colName
			// 
			this->colName->HeaderText = L"NAME";
			this->colName->MinimumWidth = 8;
			this->colName->Name = L"colName";
			this->colName->ReadOnly = true;
			this->colName->Width = 220;
			// 
			// colEmail
			// 
			this->colEmail->HeaderText = L"EMAIL";
			this->colEmail->MinimumWidth = 8;
			this->colEmail->Name = L"colEmail";
			this->colEmail->ReadOnly = true;
			this->colEmail->Width = 300;
			// 
			// colPhone
			// 
			this->colPhone->HeaderText = L"PHONE";
			this->colPhone->MinimumWidth = 8;
			this->colPhone->Name = L"colPhone";
			this->colPhone->ReadOnly = true;
			this->colPhone->Width = 150;
			// 
			// colStatus
			// 
			this->colStatus->HeaderText = L"STATUS";
			this->colStatus->MinimumWidth = 8;
			this->colStatus->Name = L"colStatus";
			this->colStatus->ReadOnly = true;
			this->colStatus->Width = 120;
			// 
			// colEdit
			// 
			this->colEdit->HeaderText = L"EDIT";
			this->colEdit->MinimumWidth = 8;
			this->colEdit->Name = L"colEdit";
			this->colEdit->ReadOnly = true;
			this->colEdit->Text = L"EDIT";
			this->colEdit->UseColumnTextForButtonValue = true;
			this->colEdit->Width = 70;
			// 
			// colDelete
			// 
			this->colDelete->HeaderText = L"DELETE";
			this->colDelete->MinimumWidth = 8;
			this->colDelete->Name = L"colDelete";
			this->colDelete->ReadOnly = true;
			this->colDelete->Text = L"DELETE";
			this->colDelete->UseColumnTextForButtonValue = true;
			this->colDelete->Width = 80;
			// 
			// colView
			// 
			this->colView->HeaderText = L"VIEW";
			this->colView->MinimumWidth = 8;
			this->colView->Name = L"colView";
			this->colView->ReadOnly = true;
			this->colView->Text = L"VIEW";
			this->colView->UseColumnTextForButtonValue = true;
			this->colView->Width = 70;
			// 
			// colInvoice
			// 
			this->colInvoice->HeaderText = L"INVOICE";
			this->colInvoice->MinimumWidth = 8;
			this->colInvoice->Name = L"colInvoice";
			this->colInvoice->ReadOnly = true;
			this->colInvoice->Text = L"INVOICE";
			this->colInvoice->UseColumnTextForButtonValue = true;
			this->colInvoice->Width = 90;
			// 
			// panelRecentActivity
			// 
			this->panelRecentActivity->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->panelRecentActivity->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelRecentActivity->Controls->Add(this->lblActivity3);
			this->panelRecentActivity->Controls->Add(this->lblActivity2);
			this->panelRecentActivity->Controls->Add(this->lblActivity1);
			this->panelRecentActivity->Controls->Add(this->lblRecentActivityTitle);
			this->panelRecentActivity->Location = System::Drawing::Point(365, 866);
			this->panelRecentActivity->Name = L"panelRecentActivity";
			this->panelRecentActivity->Size = System::Drawing::Size(626, 161);
			this->panelRecentActivity->TabIndex = 13;
			// 
			// lblActivity3
			// 
			this->lblActivity3->AutoSize = true;
			this->lblActivity3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblActivity3->ForeColor = System::Drawing::Color::Gray;
			this->lblActivity3->Location = System::Drawing::Point(17, 116);
			this->lblActivity3->Name = L"lblActivity3";
			this->lblActivity3->Size = System::Drawing::Size(527, 28);
			this->lblActivity3->TabIndex = 3;
			this->lblActivity3->Text = L"ALERT: Suspicious login attempt flagged for Marcus Thorne";
			this->lblActivity3->Click += gcnew System::EventHandler(this, &CustomersForm::lblActivity3_Click);
			// 
			// lblActivity2
			// 
			this->lblActivity2->AutoSize = true;
			this->lblActivity2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblActivity2->ForeColor = System::Drawing::Color::Gray;
			this->lblActivity2->Location = System::Drawing::Point(15, 78);
			this->lblActivity2->Name = L"lblActivity2";
			this->lblActivity2->Size = System::Drawing::Size(404, 28);
			this->lblActivity2->TabIndex = 2;
			this->lblActivity2->Text = L"UPDATE: Address update for Elena Rodriguez";
			// 
			// lblActivity1
			// 
			this->lblActivity1->AutoSize = true;
			this->lblActivity1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblActivity1->ForeColor = System::Drawing::Color::Gray;
			this->lblActivity1->Location = System::Drawing::Point(15, 40);
			this->lblActivity1->Name = L"lblActivity1";
			this->lblActivity1->Size = System::Drawing::Size(569, 28);
			this->lblActivity1->TabIndex = 1;
			this->lblActivity1->Text = L"INFO: New identity verification completed for Julian Northwood";
			// 
			// lblRecentActivityTitle
			// 
			this->lblRecentActivityTitle->AutoSize = true;
			this->lblRecentActivityTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRecentActivityTitle->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblRecentActivityTitle->Location = System::Drawing::Point(15, 10);
			this->lblRecentActivityTitle->Name = L"lblRecentActivityTitle";
			this->lblRecentActivityTitle->Size = System::Drawing::Size(185, 32);
			this->lblRecentActivityTitle->TabIndex = 0;
			this->lblRecentActivityTitle->Text = L"Recent Activity";
			// 
			// panelSystemAlert
			// 
			this->panelSystemAlert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->panelSystemAlert->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelSystemAlert->Controls->Add(this->btnReviewDocs);
			this->panelSystemAlert->Controls->Add(this->lblAlertText2);
			this->panelSystemAlert->Controls->Add(this->lblAlertText1);
			this->panelSystemAlert->Controls->Add(this->lblSystemAlertTitle);
			this->panelSystemAlert->Location = System::Drawing::Point(1097, 866);
			this->panelSystemAlert->Name = L"panelSystemAlert";
			this->panelSystemAlert->Size = System::Drawing::Size(670, 161);
			this->panelSystemAlert->TabIndex = 14;
			// 
			// btnReviewDocs
			// 
			this->btnReviewDocs->BackColor = System::Drawing::Color::DarkRed;
			this->btnReviewDocs->FlatAppearance->BorderSize = 0;
			this->btnReviewDocs->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReviewDocs->ForeColor = System::Drawing::Color::White;
			this->btnReviewDocs->Location = System::Drawing::Point(510, 126);
			this->btnReviewDocs->Name = L"btnReviewDocs";
			this->btnReviewDocs->Size = System::Drawing::Size(155, 30);
			this->btnReviewDocs->TabIndex = 3;
			this->btnReviewDocs->Text = L"REVIEW DOCS";
			this->btnReviewDocs->UseVisualStyleBackColor = false;
			this->btnReviewDocs->Click += gcnew System::EventHandler(this, &CustomersForm::btnReviewDocs_Click);
			// 
			// lblAlertText2
			// 
			this->lblAlertText2->AutoSize = true;
			this->lblAlertText2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblAlertText2->ForeColor = System::Drawing::Color::Gray;
			this->lblAlertText2->Location = System::Drawing::Point(16, 78);
			this->lblAlertText2->Name = L"lblAlertText2";
			this->lblAlertText2->Size = System::Drawing::Size(394, 28);
			this->lblAlertText2->TabIndex = 2;
			this->lblAlertText2->Text = L"Automated reminders have been scheduled.";
			// 
			// lblAlertText1
			// 
			this->lblAlertText1->AutoSize = true;
			this->lblAlertText1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblAlertText1->ForeColor = System::Drawing::Color::Gray;
			this->lblAlertText1->Location = System::Drawing::Point(15, 40);
			this->lblAlertText1->Name = L"lblAlertText1";
			this->lblAlertText1->Size = System::Drawing::Size(494, 28);
			this->lblAlertText1->TabIndex = 1;
			this->lblAlertText1->Text = L"There are 12 customers with expired license documents.";
			// 
			// lblSystemAlertTitle
			// 
			this->lblSystemAlertTitle->AutoSize = true;
			this->lblSystemAlertTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSystemAlertTitle->ForeColor = System::Drawing::Color::DarkRed;
			this->lblSystemAlertTitle->Location = System::Drawing::Point(15, 10);
			this->lblSystemAlertTitle->Name = L"lblSystemAlertTitle";
			this->lblSystemAlertTitle->Size = System::Drawing::Size(184, 32);
			this->lblSystemAlertTitle->TabIndex = 0;
			this->lblSystemAlertTitle->Text = L"SYSTEM ALERT";
			// 
			// lblRowsCount
			// 
			this->lblRowsCount->AutoSize = true;
			this->lblRowsCount->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblRowsCount->ForeColor = System::Drawing::Color::Gray;
			this->lblRowsCount->Location = System::Drawing::Point(275, 823);
			this->lblRowsCount->Name = L"lblRowsCount";
			this->lblRowsCount->Size = System::Drawing::Size(377, 28);
			this->lblRowsCount->TabIndex = 15;
			this->lblRowsCount->Text = L"Displaying rows 1-4 of 1,284 total records";
			// 
			// btnAddCustomer
			// 
			this->btnAddCustomer->BackColor = System::Drawing::Color::DarkBlue;
			this->btnAddCustomer->FlatAppearance->BorderSize = 0;
			this->btnAddCustomer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddCustomer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddCustomer->ForeColor = System::Drawing::Color::White;
			this->btnAddCustomer->Location = System::Drawing::Point(1643, 129);
			this->btnAddCustomer->Name = L"btnAddCustomer";
			this->btnAddCustomer->Size = System::Drawing::Size(230, 50);
			this->btnAddCustomer->TabIndex = 16;
			this->btnAddCustomer->Text = L"+ ADD CUSTOMER";
			this->btnAddCustomer->UseVisualStyleBackColor = false;
			this->btnAddCustomer->Click += gcnew System::EventHandler(this, &CustomersForm::btnAddCustomer_Click);
			// 
			// CustomersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1898, 1024);
			this->Controls->Add(this->btnAddCustomer);
			this->Controls->Add(this->lblRowsCount);
			this->Controls->Add(this->panelSystemAlert);
			this->Controls->Add(this->panelRecentActivity);
			this->Controls->Add(this->dgvCustomers);
			this->Controls->Add(this->panelControls);
			this->Controls->Add(this->panelNewThisMonth);
			this->Controls->Add(this->panelComplianceRate);
			this->Controls->Add(this->panelActiveRentals);
			this->Controls->Add(this->panelTotalCustomers);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"CustomersForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Customers Management";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panelTotalCustomers->ResumeLayout(false);
			this->panelTotalCustomers->PerformLayout();
			this->panelActiveRentals->ResumeLayout(false);
			this->panelActiveRentals->PerformLayout();
			this->panelComplianceRate->ResumeLayout(false);
			this->panelComplianceRate->PerformLayout();
			this->panelNewThisMonth->ResumeLayout(false);
			this->panelNewThisMonth->PerformLayout();
			this->panelControls->ResumeLayout(false);
			this->panelControls->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCustomers))->EndInit();
			this->panelRecentActivity->ResumeLayout(false);
			this->panelRecentActivity->PerformLayout();
			this->panelSystemAlert->ResumeLayout(false);
			this->panelSystemAlert->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnExportCSV_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void lblActivity3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnCars_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnRentals_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnReturns_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnFilters_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnAddCustomer_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnReviewDocs_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void dgvCustomers_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

private:

	String^ ShowInputDialog(String^ title, String^ prompt, String^ defaultValue);
	void UpdateRowsCount();

private:
		void LoadCustomersFromFile();
		void SaveCustomersToFile();
		void UpdateStats();

};
}
