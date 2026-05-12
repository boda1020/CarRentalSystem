#pragma once

namespace CarRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DashboardForm
	/// </summary>
	public ref class DashboardForm : public System::Windows::Forms::Form
	{
	public:
		DashboardForm(void)
		{
			InitializeComponent();
			LoadRecentRentals();
			RefreshStats();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ btnCustomers;

	private: System::Windows::Forms::Button^ btnCars;
	private: System::Windows::Forms::Button^ btnDashboard;
	private: System::Windows::Forms::Button^ btnReturns;
	private: System::Windows::Forms::Button^ btnRentals;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Panel^ panelTotalCars;
	private: System::Windows::Forms::Label^ FixedSingle;
	private: System::Windows::Forms::Label^ lblTotalCarsText;
	private: System::Windows::Forms::Label^ lblTotalCarsIncrease;
	private: System::Windows::Forms::Panel^ panelAvailableCars;
	private: System::Windows::Forms::Label^ lblAvailableCarsText;
	private: System::Windows::Forms::Label^ lblAvailableCarsNum;

	private: System::Windows::Forms::Label^ lblAvailableCarsIncrease;
	private: System::Windows::Forms::Panel^ panelCustomers;
	private: System::Windows::Forms::Label^ lblCustomersNum;
	private: System::Windows::Forms::Label^ lblCustomersIncrease;
	private: System::Windows::Forms::Label^ lblCustomersText;
	private: System::Windows::Forms::Panel^ panelActiveRentals;
	private: System::Windows::Forms::Label^ lblActiveRentalsNum;
	private: System::Windows::Forms::Label^ lblActiveRentalsIncrease;

	private: System::Windows::Forms::Label^ lblActiveRentalsText;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;





	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ lblUtil4;
	private: System::Windows::Forms::Label^ lblUtil3;
	private: System::Windows::Forms::Label^ lblUtil2;
	private: System::Windows::Forms::Label^ lblUtil1;
	private: System::Windows::Forms::Panel^ panelTopPerforming;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::ProgressBar^ progressBar3;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::ProgressBar^ progressBar4;





	private: System::Windows::Forms::Panel^ panelFleetExpansion;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCustomer;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colStatus;
	private: System::Windows::Forms::DataGridViewButtonColumn^ colAction;
	private: System::Windows::Forms::DataGridViewButtonColumn^ colDelete;





























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
			this->panelTotalCars = (gcnew System::Windows::Forms::Panel());
			this->lblTotalCarsIncrease = (gcnew System::Windows::Forms::Label());
			this->lblTotalCarsText = (gcnew System::Windows::Forms::Label());
			this->FixedSingle = (gcnew System::Windows::Forms::Label());
			this->panelAvailableCars = (gcnew System::Windows::Forms::Panel());
			this->lblAvailableCarsIncrease = (gcnew System::Windows::Forms::Label());
			this->lblAvailableCarsText = (gcnew System::Windows::Forms::Label());
			this->lblAvailableCarsNum = (gcnew System::Windows::Forms::Label());
			this->panelCustomers = (gcnew System::Windows::Forms::Panel());
			this->lblCustomersIncrease = (gcnew System::Windows::Forms::Label());
			this->lblCustomersText = (gcnew System::Windows::Forms::Label());
			this->lblCustomersNum = (gcnew System::Windows::Forms::Label());
			this->panelActiveRentals = (gcnew System::Windows::Forms::Panel());
			this->lblActiveRentalsIncrease = (gcnew System::Windows::Forms::Label());
			this->lblActiveRentalsText = (gcnew System::Windows::Forms::Label());
			this->lblActiveRentalsNum = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->lblUtil4 = (gcnew System::Windows::Forms::Label());
			this->lblUtil3 = (gcnew System::Windows::Forms::Label());
			this->lblUtil2 = (gcnew System::Windows::Forms::Label());
			this->lblUtil1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panelTopPerforming = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->progressBar4 = (gcnew System::Windows::Forms::ProgressBar());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->progressBar3 = (gcnew System::Windows::Forms::ProgressBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panelFleetExpansion = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->colDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCustomer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCar = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colStatus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colAction = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->colDelete = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panelTotalCars->SuspendLayout();
			this->panelAvailableCars->SuspendLayout();
			this->panelCustomers->SuspendLayout();
			this->panelActiveRentals->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel3->SuspendLayout();
			this->panelTopPerforming->SuspendLayout();
			this->panelFleetExpansion->SuspendLayout();
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
			this->panel1->TabIndex = 0;
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
			this->label2->Click += gcnew System::EventHandler(this, &DashboardForm::label2_Click);
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
			this->label1->Click += gcnew System::EventHandler(this, &DashboardForm::label1_Click);
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
			this->panel2->TabIndex = 1;
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
			this->btnExit->Click += gcnew System::EventHandler(this, &DashboardForm::btnExit_Click);
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
			this->btnReturns->Click += gcnew System::EventHandler(this, &DashboardForm::btnReturns_Click);
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
			this->btnRentals->Click += gcnew System::EventHandler(this, &DashboardForm::btnRentals_Click);
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
			this->btnCustomers->Click += gcnew System::EventHandler(this, &DashboardForm::btnCustomers_Click);
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
			this->btnCars->Click += gcnew System::EventHandler(this, &DashboardForm::btnCars_Click);
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
			// panelTotalCars
			// 
			this->panelTotalCars->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panelTotalCars->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTotalCars->Controls->Add(this->lblTotalCarsIncrease);
			this->panelTotalCars->Controls->Add(this->lblTotalCarsText);
			this->panelTotalCars->Controls->Add(this->FixedSingle);
			this->panelTotalCars->Location = System::Drawing::Point(280, 140);
			this->panelTotalCars->Name = L"panelTotalCars";
			this->panelTotalCars->Size = System::Drawing::Size(370, 150);
			this->panelTotalCars->TabIndex = 2;
			// 
			// lblTotalCarsIncrease
			// 
			this->lblTotalCarsIncrease->AutoSize = true;
			this->lblTotalCarsIncrease->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalCarsIncrease->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->lblTotalCarsIncrease->Location = System::Drawing::Point(275, 113);
			this->lblTotalCarsIncrease->Name = L"lblTotalCarsIncrease";
			this->lblTotalCarsIncrease->Size = System::Drawing::Size(78, 25);
			this->lblTotalCarsIncrease->TabIndex = 2;
			this->lblTotalCarsIncrease->Text = L"+0 NEW";
			// 
			// lblTotalCarsText
			// 
			this->lblTotalCarsText->AutoSize = true;
			this->lblTotalCarsText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalCarsText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblTotalCarsText->Location = System::Drawing::Point(20, 19);
			this->lblTotalCarsText->Name = L"lblTotalCarsText";
			this->lblTotalCarsText->Size = System::Drawing::Size(139, 30);
			this->lblTotalCarsText->TabIndex = 1;
			this->lblTotalCarsText->Text = L"TOTAL CARS";
			// 
			// FixedSingle
			// 
			this->FixedSingle->AutoSize = true;
			this->FixedSingle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FixedSingle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->FixedSingle->Location = System::Drawing::Point(25, 49);
			this->FixedSingle->Name = L"FixedSingle";
			this->FixedSingle->Size = System::Drawing::Size(81, 96);
			this->FixedSingle->TabIndex = 0;
			this->FixedSingle->Text = L"0";
			this->FixedSingle->Click += gcnew System::EventHandler(this, &DashboardForm::FixedSingle_Click);
			// 
			// panelAvailableCars
			// 
			this->panelAvailableCars->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->panelAvailableCars->Controls->Add(this->lblAvailableCarsIncrease);
			this->panelAvailableCars->Controls->Add(this->lblAvailableCarsText);
			this->panelAvailableCars->Controls->Add(this->lblAvailableCarsNum);
			this->panelAvailableCars->Location = System::Drawing::Point(682, 140);
			this->panelAvailableCars->Name = L"panelAvailableCars";
			this->panelAvailableCars->Size = System::Drawing::Size(370, 150);
			this->panelAvailableCars->TabIndex = 3;
			// 
			// lblAvailableCarsIncrease
			// 
			this->lblAvailableCarsIncrease->AutoSize = true;
			this->lblAvailableCarsIncrease->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblAvailableCarsIncrease->Location = System::Drawing::Point(221, 114);
			this->lblAvailableCarsIncrease->Name = L"lblAvailableCarsIncrease";
			this->lblAvailableCarsIncrease->Size = System::Drawing::Size(146, 25);
			this->lblAvailableCarsIncrease->TabIndex = 2;
			this->lblAvailableCarsIncrease->Text = L"+0 THIS MONTH";
			// 
			// lblAvailableCarsText
			// 
			this->lblAvailableCarsText->AutoSize = true;
			this->lblAvailableCarsText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblAvailableCarsText->Location = System::Drawing::Point(23, 20);
			this->lblAvailableCarsText->Name = L"lblAvailableCarsText";
			this->lblAvailableCarsText->Size = System::Drawing::Size(187, 30);
			this->lblAvailableCarsText->TabIndex = 1;
			this->lblAvailableCarsText->Text = L"AVAILABLE CARS";
			// 
			// lblAvailableCarsNum
			// 
			this->lblAvailableCarsNum->AutoSize = true;
			this->lblAvailableCarsNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAvailableCarsNum->Location = System::Drawing::Point(26, 50);
			this->lblAvailableCarsNum->Name = L"lblAvailableCarsNum";
			this->lblAvailableCarsNum->Size = System::Drawing::Size(81, 96);
			this->lblAvailableCarsNum->TabIndex = 0;
			this->lblAvailableCarsNum->Text = L"0";
			this->lblAvailableCarsNum->Click += gcnew System::EventHandler(this, &DashboardForm::lblAvailableCarsNum_Click);
			// 
			// panelCustomers
			// 
			this->panelCustomers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->panelCustomers->Controls->Add(this->lblCustomersIncrease);
			this->panelCustomers->Controls->Add(this->lblCustomersText);
			this->panelCustomers->Controls->Add(this->lblCustomersNum);
			this->panelCustomers->Location = System::Drawing::Point(1088, 140);
			this->panelCustomers->Name = L"panelCustomers";
			this->panelCustomers->Size = System::Drawing::Size(370, 150);
			this->panelCustomers->TabIndex = 5;
			// 
			// lblCustomersIncrease
			// 
			this->lblCustomersIncrease->AutoSize = true;
			this->lblCustomersIncrease->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblCustomersIncrease->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->lblCustomersIncrease->Location = System::Drawing::Point(227, 114);
			this->lblCustomersIncrease->Name = L"lblCustomersIncrease";
			this->lblCustomersIncrease->Size = System::Drawing::Size(140, 25);
			this->lblCustomersIncrease->TabIndex = 2;
			this->lblCustomersIncrease->Text = L"+0 CUSTOMERS";
			// 
			// lblCustomersText
			// 
			this->lblCustomersText->AutoSize = true;
			this->lblCustomersText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblCustomersText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblCustomersText->Location = System::Drawing::Point(25, 20);
			this->lblCustomersText->Name = L"lblCustomersText";
			this->lblCustomersText->Size = System::Drawing::Size(143, 30);
			this->lblCustomersText->TabIndex = 1;
			this->lblCustomersText->Text = L"CUSTOMERS";
			// 
			// lblCustomersNum
			// 
			this->lblCustomersNum->AutoSize = true;
			this->lblCustomersNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCustomersNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblCustomersNum->Location = System::Drawing::Point(24, 50);
			this->lblCustomersNum->Name = L"lblCustomersNum";
			this->lblCustomersNum->Size = System::Drawing::Size(81, 96);
			this->lblCustomersNum->TabIndex = 0;
			this->lblCustomersNum->Text = L"0";
			// 
			// panelActiveRentals
			// 
			this->panelActiveRentals->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panelActiveRentals->Controls->Add(this->lblActiveRentalsIncrease);
			this->panelActiveRentals->Controls->Add(this->lblActiveRentalsText);
			this->panelActiveRentals->Controls->Add(this->lblActiveRentalsNum);
			this->panelActiveRentals->Location = System::Drawing::Point(1495, 140);
			this->panelActiveRentals->Name = L"panelActiveRentals";
			this->panelActiveRentals->Size = System::Drawing::Size(370, 150);
			this->panelActiveRentals->TabIndex = 6;
			// 
			// lblActiveRentalsIncrease
			// 
			this->lblActiveRentalsIncrease->AutoSize = true;
			this->lblActiveRentalsIncrease->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblActiveRentalsIncrease->Location = System::Drawing::Point(267, 114);
			this->lblActiveRentalsIncrease->Name = L"lblActiveRentalsIncrease";
			this->lblActiveRentalsIncrease->Size = System::Drawing::Size(100, 25);
			this->lblActiveRentalsIncrease->TabIndex = 3;
			this->lblActiveRentalsIncrease->Text = L"+0 RENTAL";
			this->lblActiveRentalsIncrease->Click += gcnew System::EventHandler(this, &DashboardForm::label4_Click);
			// 
			// lblActiveRentalsText
			// 
			this->lblActiveRentalsText->AutoSize = true;
			this->lblActiveRentalsText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblActiveRentalsText->Location = System::Drawing::Point(24, 20);
			this->lblActiveRentalsText->Name = L"lblActiveRentalsText";
			this->lblActiveRentalsText->Size = System::Drawing::Size(187, 30);
			this->lblActiveRentalsText->TabIndex = 2;
			this->lblActiveRentalsText->Text = L"ACTIVE RENTALS";
			// 
			// lblActiveRentalsNum
			// 
			this->lblActiveRentalsNum->AutoSize = true;
			this->lblActiveRentalsNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblActiveRentalsNum->Location = System::Drawing::Point(30, 50);
			this->lblActiveRentalsNum->Name = L"lblActiveRentalsNum";
			this->lblActiveRentalsNum->Size = System::Drawing::Size(81, 96);
			this->lblActiveRentalsNum->TabIndex = 1;
			this->lblActiveRentalsNum->Text = L"0";
			this->lblActiveRentalsNum->Click += gcnew System::EventHandler(this, &DashboardForm::lblActiveRentalsNum_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::DarkBlue;
			this->label3->Location = System::Drawing::Point(290, 320);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(315, 48);
			this->label3->TabIndex = 7;
			this->label3->Text = L"RECENT RENTALS";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colDate,
					this->colCustomer, this->colCar, this->colStatus, this->colAction, this->colDelete
			});
			this->dataGridView1->Location = System::Drawing::Point(280, 371);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(1585, 280);
			this->dataGridView1->TabIndex = 8;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DashboardForm::dataGridView1_CellClick);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->lblUtil4);
			this->panel3->Controls->Add(this->lblUtil3);
			this->panel3->Controls->Add(this->lblUtil2);
			this->panel3->Controls->Add(this->lblUtil1);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Location = System::Drawing::Point(433, 670);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(547, 269);
			this->panel3->TabIndex = 9;
			// 
			// lblUtil4
			// 
			this->lblUtil4->AutoSize = true;
			this->lblUtil4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->lblUtil4->Location = System::Drawing::Point(20, 180);
			this->lblUtil4->Name = L"lblUtil4";
			this->lblUtil4->Size = System::Drawing::Size(229, 32);
			this->lblUtil4->TabIndex = 4;
			this->lblUtil4->Text = L"Avg Rental Days: 6.2";
			// 
			// lblUtil3
			// 
			this->lblUtil3->AutoSize = true;
			this->lblUtil3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->lblUtil3->Location = System::Drawing::Point(20, 140);
			this->lblUtil3->Name = L"lblUtil3";
			this->lblUtil3->Size = System::Drawing::Size(252, 32);
			this->lblUtil3->TabIndex = 3;
			this->lblUtil3->Text = L"Maintenance Rate: 5%";
			// 
			// lblUtil2
			// 
			this->lblUtil2->AutoSize = true;
			this->lblUtil2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->lblUtil2->Location = System::Drawing::Point(20, 100);
			this->lblUtil2->Name = L"lblUtil2";
			this->lblUtil2->Size = System::Drawing::Size(245, 32);
			this->lblUtil2->TabIndex = 2;
			this->lblUtil2->Text = L"Monthly Trend: +12%";
			// 
			// lblUtil1
			// 
			this->lblUtil1->AutoSize = true;
			this->lblUtil1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->lblUtil1->Location = System::Drawing::Point(20, 60);
			this->lblUtil1->Name = L"lblUtil1";
			this->lblUtil1->Size = System::Drawing::Size(196, 32);
			this->lblUtil1->TabIndex = 1;
			this->lblUtil1->Text = L"Fleet Usage: 78%";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::DarkBlue;
			this->label4->Location = System::Drawing::Point(20, 15);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(304, 38);
			this->label4->TabIndex = 0;
			this->label4->Text = L"UTILIZATION TRENDS";
			// 
			// panelTopPerforming
			// 
			this->panelTopPerforming->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panelTopPerforming->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTopPerforming->Controls->Add(this->label13);
			this->panelTopPerforming->Controls->Add(this->progressBar4);
			this->panelTopPerforming->Controls->Add(this->label12);
			this->panelTopPerforming->Controls->Add(this->label11);
			this->panelTopPerforming->Controls->Add(this->progressBar3);
			this->panelTopPerforming->Controls->Add(this->label10);
			this->panelTopPerforming->Controls->Add(this->label9);
			this->panelTopPerforming->Controls->Add(this->progressBar2);
			this->panelTopPerforming->Controls->Add(this->label8);
			this->panelTopPerforming->Controls->Add(this->label7);
			this->panelTopPerforming->Controls->Add(this->progressBar1);
			this->panelTopPerforming->Controls->Add(this->label6);
			this->panelTopPerforming->Controls->Add(this->label5);
			this->panelTopPerforming->Location = System::Drawing::Point(1196, 670);
			this->panelTopPerforming->Name = L"panelTopPerforming";
			this->panelTopPerforming->Size = System::Drawing::Size(527, 269);
			this->panelTopPerforming->TabIndex = 10;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label13->Location = System::Drawing::Point(460, 225);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(41, 20);
			this->label13->TabIndex = 21;
			this->label13->Text = L"45%";
			// 
			// progressBar4
			// 
			this->progressBar4->ForeColor = System::Drawing::Color::Green;
			this->progressBar4->Location = System::Drawing::Point(150, 225);
			this->progressBar4->Name = L"progressBar4";
			this->progressBar4->Size = System::Drawing::Size(200, 23);
			this->progressBar4->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar4->TabIndex = 20;
			this->progressBar4->Value = 45;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(20, 225);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(115, 20);
			this->label12->TabIndex = 19;
			this->label12->Text = L"Sports Coupes";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label11->Location = System::Drawing::Point(460, 170);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(41, 20);
			this->label11->TabIndex = 18;
			this->label11->Text = L"61%";
			// 
			// progressBar3
			// 
			this->progressBar3->ForeColor = System::Drawing::Color::Green;
			this->progressBar3->Location = System::Drawing::Point(150, 170);
			this->progressBar3->Name = L"progressBar3";
			this->progressBar3->Size = System::Drawing::Size(200, 23);
			this->progressBar3->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar3->TabIndex = 17;
			this->progressBar3->Value = 61;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(20, 170);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(122, 20);
			this->label10->TabIndex = 16;
			this->label10->Text = L"Economy Hatch";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label9->Location = System::Drawing::Point(460, 115);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(41, 20);
			this->label9->TabIndex = 15;
			this->label9->Text = L"74%";
			// 
			// progressBar2
			// 
			this->progressBar2->ForeColor = System::Drawing::Color::Green;
			this->progressBar2->Location = System::Drawing::Point(150, 115);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(200, 23);
			this->progressBar2->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar2->TabIndex = 14;
			this->progressBar2->Value = 74;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(20, 115);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(120, 20);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Electric Sedans";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label7->Location = System::Drawing::Point(460, 60);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 20);
			this->label7->TabIndex = 12;
			this->label7->Text = L"82%";
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::Color::Green;
			this->progressBar1->Location = System::Drawing::Point(150, 60);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(200, 23);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 11;
			this->progressBar1->Value = 82;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(20, 60);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(101, 20);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Luxury SUVs";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(17, 15);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(260, 38);
			this->label5->TabIndex = 0;
			this->label5->Text = L"TOP PERFORMING";
			// 
			// panelFleetExpansion
			// 
			this->panelFleetExpansion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->panelFleetExpansion->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelFleetExpansion->Controls->Add(this->button1);
			this->panelFleetExpansion->Controls->Add(this->label15);
			this->panelFleetExpansion->Controls->Add(this->label14);
			this->panelFleetExpansion->Location = System::Drawing::Point(280, 956);
			this->panelFleetExpansion->Name = L"panelFleetExpansion";
			this->panelFleetExpansion->Size = System::Drawing::Size(1592, 80);
			this->panelFleetExpansion->TabIndex = 11;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkBlue;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(1407, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(180, 35);
			this->button1->TabIndex = 2;
			this->button1->Text = L"REVIEW LOGISTICS";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// label15
			// 
			this->label15->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->label15->ForeColor = System::Drawing::Color::DimGray;
			this->label15->Location = System::Drawing::Point(20, 40);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(1212, 30);
			this->label15->TabIndex = 1;
			this->label15->Text = L"New premium inventory arriving next week. Review upcoming vehicle logistics and i"
				L"nsurance documentation for the 2026 fleet rollout.";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::DarkBlue;
			this->label14->Location = System::Drawing::Point(19, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(222, 32);
			this->label14->TabIndex = 0;
			this->label14->Text = L"FLEET EXPANSION";
			this->label14->Click += gcnew System::EventHandler(this, &DashboardForm::label14_Click);
			// 
			// colDate
			// 
			this->colDate->HeaderText = L"DATE";
			this->colDate->MinimumWidth = 8;
			this->colDate->Name = L"colDate";
			this->colDate->ReadOnly = true;
			this->colDate->Width = 160;
			// 
			// colCustomer
			// 
			this->colCustomer->HeaderText = L"CUSTOMER";
			this->colCustomer->MinimumWidth = 8;
			this->colCustomer->Name = L"colCustomer";
			this->colCustomer->ReadOnly = true;
			this->colCustomer->Width = 230;
			// 
			// colCar
			// 
			this->colCar->HeaderText = L"CAR";
			this->colCar->MinimumWidth = 8;
			this->colCar->Name = L"colCar";
			this->colCar->ReadOnly = true;
			this->colCar->Width = 350;
			// 
			// colStatus
			// 
			this->colStatus->HeaderText = L"STATUS";
			this->colStatus->MinimumWidth = 8;
			this->colStatus->Name = L"colStatus";
			this->colStatus->ReadOnly = true;
			this->colStatus->Width = 160;
			// 
			// colAction
			// 
			this->colAction->HeaderText = L"ACTION";
			this->colAction->MinimumWidth = 8;
			this->colAction->Name = L"colAction";
			this->colAction->ReadOnly = true;
			this->colAction->Width = 150;
			// 
			// colDelete
			// 
			this->colDelete->HeaderText = L"DELETE";
			this->colDelete->MinimumWidth = 8;
			this->colDelete->Name = L"colDelete";
			this->colDelete->ReadOnly = true;
			this->colDelete->Text = L"DELETE";
			this->colDelete->UseColumnTextForButtonValue = true;
			this->colDelete->Width = 150;
			// 
			// DashboardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1898, 1024);
			this->Controls->Add(this->panelFleetExpansion);
			this->Controls->Add(this->panelTopPerforming);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panelActiveRentals);
			this->Controls->Add(this->panelCustomers);
			this->Controls->Add(this->panelAvailableCars);
			this->Controls->Add(this->panelTotalCars);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"DashboardForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DashboardForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panelTotalCars->ResumeLayout(false);
			this->panelTotalCars->PerformLayout();
			this->panelAvailableCars->ResumeLayout(false);
			this->panelAvailableCars->PerformLayout();
			this->panelCustomers->ResumeLayout(false);
			this->panelCustomers->PerformLayout();
			this->panelActiveRentals->ResumeLayout(false);
			this->panelActiveRentals->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panelTopPerforming->ResumeLayout(false);
			this->panelTopPerforming->PerformLayout();
			this->panelFleetExpansion->ResumeLayout(false);
			this->panelFleetExpansion->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void FixedSingle_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblAvailableCarsNum_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblActiveRentalsNum_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void btnCustomers_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnRentals_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnReturns_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnCars_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

private: System::Void RefreshStats();

private:
	void LoadRecentRentals();
	String^ GetCustomerName(String^ customerId);
	String^ GetCarModel(String^ carId);

private:
	String^ GetCarModelById(String^ carId);
	double GetDailyRate(String^ carId);
	int GetRentalDays(String^ rentalNo);
	double GetRentalTotal(String^ rentalNo);
};
}
