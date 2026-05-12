#pragma once
#include "FileHelper.h"

namespace CarRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CarsForm
	/// </summary>
	public ref class CarsForm : public System::Windows::Forms::Form
	{
	public:
		CarsForm(void)
		{
			InitializeComponent();
			LoadCarsFromFile();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CarsForm()
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
	private: System::Windows::Forms::Panel^ panelTotalCars;
	private: System::Windows::Forms::Label^ lblTotalCarsIncrease;
	private: System::Windows::Forms::Label^ lblTotalCarsText;
	private: System::Windows::Forms::Label^ FixedSingle;
	private: System::Windows::Forms::Panel^ panelTotalFleet;


	private: System::Windows::Forms::Label^ lblTotalFleetText;

	private: System::Windows::Forms::Label^ lblTotalFleetNum;
	private: System::Windows::Forms::Panel^ panelAvailable;



	private: System::Windows::Forms::Label^ lblAvailableText;

	private: System::Windows::Forms::Label^ lblAvailableNum;
	private: System::Windows::Forms::Panel^ panelOnRental;



	private: System::Windows::Forms::Label^ lblOnRentalText;

	private: System::Windows::Forms::Label^ lblOnRentalNum;
	private: System::Windows::Forms::Panel^ panelMaintenance;



	private: System::Windows::Forms::Label^ lblMaintenanceText;

	private: System::Windows::Forms::Label^ lblMaintenanceNum;
	private: System::Windows::Forms::Panel^ panelFilterButtons;
	private: System::Windows::Forms::Button^ btnAll;
	private: System::Windows::Forms::Button^ btnSedan;
	private: System::Windows::Forms::Button^ btnSUV;
	private: System::Windows::Forms::DataGridView^ dgvCars;






	private: System::Windows::Forms::Label^ lblRowsCount;
	private: System::Windows::Forms::Button^ btnAddCar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCarID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colModel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDailyRate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colStatus;
	private: System::Windows::Forms::DataGridViewButtonColumn^ colActions;




	protected:


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
			this->panelTotalCars = (gcnew System::Windows::Forms::Panel());
			this->panelTotalFleet = (gcnew System::Windows::Forms::Panel());
			this->lblTotalFleetText = (gcnew System::Windows::Forms::Label());
			this->lblTotalFleetNum = (gcnew System::Windows::Forms::Label());
			this->lblTotalCarsIncrease = (gcnew System::Windows::Forms::Label());
			this->lblTotalCarsText = (gcnew System::Windows::Forms::Label());
			this->FixedSingle = (gcnew System::Windows::Forms::Label());
			this->panelAvailable = (gcnew System::Windows::Forms::Panel());
			this->lblAvailableText = (gcnew System::Windows::Forms::Label());
			this->lblAvailableNum = (gcnew System::Windows::Forms::Label());
			this->panelOnRental = (gcnew System::Windows::Forms::Panel());
			this->lblOnRentalText = (gcnew System::Windows::Forms::Label());
			this->lblOnRentalNum = (gcnew System::Windows::Forms::Label());
			this->panelMaintenance = (gcnew System::Windows::Forms::Panel());
			this->lblMaintenanceText = (gcnew System::Windows::Forms::Label());
			this->lblMaintenanceNum = (gcnew System::Windows::Forms::Label());
			this->panelFilterButtons = (gcnew System::Windows::Forms::Panel());
			this->btnSUV = (gcnew System::Windows::Forms::Button());
			this->btnSedan = (gcnew System::Windows::Forms::Button());
			this->btnAll = (gcnew System::Windows::Forms::Button());
			this->dgvCars = (gcnew System::Windows::Forms::DataGridView());
			this->lblRowsCount = (gcnew System::Windows::Forms::Label());
			this->btnAddCar = (gcnew System::Windows::Forms::Button());
			this->colCarID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colModel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDailyRate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colStatus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colActions = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panelTotalCars->SuspendLayout();
			this->panelTotalFleet->SuspendLayout();
			this->panelAvailable->SuspendLayout();
			this->panelOnRental->SuspendLayout();
			this->panelMaintenance->SuspendLayout();
			this->panelFilterButtons->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCars))->BeginInit();
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
			this->panel1->TabIndex = 1;
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
			this->panel2->TabIndex = 2;
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
			this->btnExit->Click += gcnew System::EventHandler(this, &CarsForm::btnExit_Click);
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
			this->btnReturns->Click += gcnew System::EventHandler(this, &CarsForm::btnReturns_Click);
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
			this->btnRentals->Click += gcnew System::EventHandler(this, &CarsForm::btnRentals_Click);
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
			this->btnCustomers->Click += gcnew System::EventHandler(this, &CarsForm::btnCustomers_Click);
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
			this->btnDashboard->Click += gcnew System::EventHandler(this, &CarsForm::btnDashboard_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::DarkBlue;
			this->label3->Location = System::Drawing::Point(256, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(438, 65);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Cars Management";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->label4->ForeColor = System::Drawing::Color::Gray;
			this->label4->Location = System::Drawing::Point(262, 167);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(469, 30);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Inventory overview and fleet status monitoring.";
			this->label4->Click += gcnew System::EventHandler(this, &CarsForm::label4_Click);
			// 
			// panelTotalCars
			// 
			this->panelTotalCars->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panelTotalCars->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTotalCars->Controls->Add(this->panelTotalFleet);
			this->panelTotalCars->Controls->Add(this->lblTotalCarsIncrease);
			this->panelTotalCars->Controls->Add(this->lblTotalCarsText);
			this->panelTotalCars->Controls->Add(this->FixedSingle);
			this->panelTotalCars->Location = System::Drawing::Point(280, 210);
			this->panelTotalCars->Name = L"panelTotalCars";
			this->panelTotalCars->Size = System::Drawing::Size(370, 150);
			this->panelTotalCars->TabIndex = 5;
			// 
			// panelTotalFleet
			// 
			this->panelTotalFleet->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panelTotalFleet->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTotalFleet->Controls->Add(this->lblTotalFleetText);
			this->panelTotalFleet->Controls->Add(this->lblTotalFleetNum);
			this->panelTotalFleet->Location = System::Drawing::Point(-1, -1);
			this->panelTotalFleet->Name = L"panelTotalFleet";
			this->panelTotalFleet->Size = System::Drawing::Size(370, 150);
			this->panelTotalFleet->TabIndex = 6;
			// 
			// lblTotalFleetText
			// 
			this->lblTotalFleetText->AutoSize = true;
			this->lblTotalFleetText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalFleetText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblTotalFleetText->Location = System::Drawing::Point(20, 19);
			this->lblTotalFleetText->Name = L"lblTotalFleetText";
			this->lblTotalFleetText->Size = System::Drawing::Size(143, 30);
			this->lblTotalFleetText->TabIndex = 1;
			this->lblTotalFleetText->Text = L"TOTAL FLEET";
			// 
			// lblTotalFleetNum
			// 
			this->lblTotalFleetNum->AutoSize = true;
			this->lblTotalFleetNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalFleetNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblTotalFleetNum->Location = System::Drawing::Point(25, 49);
			this->lblTotalFleetNum->Name = L"lblTotalFleetNum";
			this->lblTotalFleetNum->Size = System::Drawing::Size(81, 96);
			this->lblTotalFleetNum->TabIndex = 0;
			this->lblTotalFleetNum->Text = L"0";
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
			this->lblTotalCarsText->Size = System::Drawing::Size(143, 30);
			this->lblTotalCarsText->TabIndex = 1;
			this->lblTotalCarsText->Text = L"TOTAL FLEET";
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
			// 
			// panelAvailable
			// 
			this->panelAvailable->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->panelAvailable->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelAvailable->Controls->Add(this->lblAvailableText);
			this->panelAvailable->Controls->Add(this->lblAvailableNum);
			this->panelAvailable->Location = System::Drawing::Point(682, 210);
			this->panelAvailable->Name = L"panelAvailable";
			this->panelAvailable->Size = System::Drawing::Size(370, 150);
			this->panelAvailable->TabIndex = 6;
			this->panelAvailable->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CarsForm::panel4_Paint);
			// 
			// lblAvailableText
			// 
			this->lblAvailableText->AutoSize = true;
			this->lblAvailableText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAvailableText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblAvailableText->Location = System::Drawing::Point(20, 19);
			this->lblAvailableText->Name = L"lblAvailableText";
			this->lblAvailableText->Size = System::Drawing::Size(126, 30);
			this->lblAvailableText->TabIndex = 1;
			this->lblAvailableText->Text = L"AVAILABLE";
			// 
			// lblAvailableNum
			// 
			this->lblAvailableNum->AutoSize = true;
			this->lblAvailableNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAvailableNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblAvailableNum->Location = System::Drawing::Point(25, 49);
			this->lblAvailableNum->Name = L"lblAvailableNum";
			this->lblAvailableNum->Size = System::Drawing::Size(81, 96);
			this->lblAvailableNum->TabIndex = 0;
			this->lblAvailableNum->Text = L"0";
			// 
			// panelOnRental
			// 
			this->panelOnRental->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->panelOnRental->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelOnRental->Controls->Add(this->lblOnRentalText);
			this->panelOnRental->Controls->Add(this->lblOnRentalNum);
			this->panelOnRental->Location = System::Drawing::Point(1087, 210);
			this->panelOnRental->Name = L"panelOnRental";
			this->panelOnRental->Size = System::Drawing::Size(370, 150);
			this->panelOnRental->TabIndex = 7;
			// 
			// lblOnRentalText
			// 
			this->lblOnRentalText->AutoSize = true;
			this->lblOnRentalText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblOnRentalText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblOnRentalText->Location = System::Drawing::Point(20, 19);
			this->lblOnRentalText->Name = L"lblOnRentalText";
			this->lblOnRentalText->Size = System::Drawing::Size(133, 30);
			this->lblOnRentalText->TabIndex = 1;
			this->lblOnRentalText->Text = L"ON RENTAL";
			// 
			// lblOnRentalNum
			// 
			this->lblOnRentalNum->AutoSize = true;
			this->lblOnRentalNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblOnRentalNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblOnRentalNum->Location = System::Drawing::Point(25, 49);
			this->lblOnRentalNum->Name = L"lblOnRentalNum";
			this->lblOnRentalNum->Size = System::Drawing::Size(81, 96);
			this->lblOnRentalNum->TabIndex = 0;
			this->lblOnRentalNum->Text = L"0";
			// 
			// panelMaintenance
			// 
			this->panelMaintenance->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->panelMaintenance->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelMaintenance->Controls->Add(this->lblMaintenanceText);
			this->panelMaintenance->Controls->Add(this->lblMaintenanceNum);
			this->panelMaintenance->Location = System::Drawing::Point(1493, 210);
			this->panelMaintenance->Name = L"panelMaintenance";
			this->panelMaintenance->Size = System::Drawing::Size(370, 150);
			this->panelMaintenance->TabIndex = 8;
			// 
			// lblMaintenanceText
			// 
			this->lblMaintenanceText->AutoSize = true;
			this->lblMaintenanceText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMaintenanceText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblMaintenanceText->Location = System::Drawing::Point(20, 19);
			this->lblMaintenanceText->Name = L"lblMaintenanceText";
			this->lblMaintenanceText->Size = System::Drawing::Size(173, 30);
			this->lblMaintenanceText->TabIndex = 1;
			this->lblMaintenanceText->Text = L"MAINTENANCE";
			// 
			// lblMaintenanceNum
			// 
			this->lblMaintenanceNum->AutoSize = true;
			this->lblMaintenanceNum->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMaintenanceNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblMaintenanceNum->Location = System::Drawing::Point(25, 49);
			this->lblMaintenanceNum->Name = L"lblMaintenanceNum";
			this->lblMaintenanceNum->Size = System::Drawing::Size(81, 96);
			this->lblMaintenanceNum->TabIndex = 0;
			this->lblMaintenanceNum->Text = L"0";
			// 
			// panelFilterButtons
			// 
			this->panelFilterButtons->BackColor = System::Drawing::Color::Transparent;
			this->panelFilterButtons->Controls->Add(this->btnSUV);
			this->panelFilterButtons->Controls->Add(this->btnSedan);
			this->panelFilterButtons->Controls->Add(this->btnAll);
			this->panelFilterButtons->Location = System::Drawing::Point(280, 370);
			this->panelFilterButtons->Name = L"panelFilterButtons";
			this->panelFilterButtons->Size = System::Drawing::Size(261, 40);
			this->panelFilterButtons->TabIndex = 9;
			// 
			// btnSUV
			// 
			this->btnSUV->BackColor = System::Drawing::Color::LightGray;
			this->btnSUV->FlatAppearance->BorderSize = 0;
			this->btnSUV->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSUV->ForeColor = System::Drawing::Color::Black;
			this->btnSUV->Location = System::Drawing::Point(175, 3);
			this->btnSUV->Name = L"btnSUV";
			this->btnSUV->Size = System::Drawing::Size(80, 35);
			this->btnSUV->TabIndex = 10;
			this->btnSUV->Text = L"SUV";
			this->btnSUV->UseVisualStyleBackColor = false;
			this->btnSUV->Click += gcnew System::EventHandler(this, &CarsForm::btnSUV_Click);
			// 
			// btnSedan
			// 
			this->btnSedan->BackColor = System::Drawing::Color::LightGray;
			this->btnSedan->FlatAppearance->BorderSize = 0;
			this->btnSedan->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSedan->ForeColor = System::Drawing::Color::Black;
			this->btnSedan->Location = System::Drawing::Point(89, 3);
			this->btnSedan->Name = L"btnSedan";
			this->btnSedan->Size = System::Drawing::Size(80, 35);
			this->btnSedan->TabIndex = 10;
			this->btnSedan->Text = L"SEDAN";
			this->btnSedan->UseVisualStyleBackColor = false;
			this->btnSedan->Click += gcnew System::EventHandler(this, &CarsForm::btnSedan_Click);
			// 
			// btnAll
			// 
			this->btnAll->BackColor = System::Drawing::Color::DarkBlue;
			this->btnAll->FlatAppearance->BorderSize = 0;
			this->btnAll->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAll->ForeColor = System::Drawing::Color::White;
			this->btnAll->Location = System::Drawing::Point(3, 3);
			this->btnAll->Name = L"btnAll";
			this->btnAll->Size = System::Drawing::Size(80, 35);
			this->btnAll->TabIndex = 10;
			this->btnAll->Text = L"ALL";
			this->btnAll->UseVisualStyleBackColor = false;
			this->btnAll->Click += gcnew System::EventHandler(this, &CarsForm::btnAll_Click);
			// 
			// dgvCars
			// 
			this->dgvCars->AllowUserToOrderColumns = true;
			this->dgvCars->BackgroundColor = System::Drawing::Color::White;
			this->dgvCars->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCars->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colCarID, this->colModel,
					this->colType, this->colDailyRate, this->colStatus, this->colActions
			});
			this->dgvCars->Location = System::Drawing::Point(280, 414);
			this->dgvCars->Name = L"dgvCars";
			this->dgvCars->RowHeadersVisible = false;
			this->dgvCars->RowHeadersWidth = 62;
			this->dgvCars->RowTemplate->Height = 28;
			this->dgvCars->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvCars->Size = System::Drawing::Size(1583, 426);
			this->dgvCars->TabIndex = 10;
			this->dgvCars->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CarsForm::dgvCars_CellClick);
			// 
			// lblRowsCount
			// 
			this->lblRowsCount->AutoSize = true;
			this->lblRowsCount->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRowsCount->ForeColor = System::Drawing::Color::Gray;
			this->lblRowsCount->Location = System::Drawing::Point(280, 860);
			this->lblRowsCount->Name = L"lblRowsCount";
			this->lblRowsCount->Size = System::Drawing::Size(94, 28);
			this->lblRowsCount->TabIndex = 11;
			this->lblRowsCount->Text = L"ROWS: 5";
			// 
			// btnAddCar
			// 
			this->btnAddCar->BackColor = System::Drawing::Color::DarkBlue;
			this->btnAddCar->FlatAppearance->BorderSize = 0;
			this->btnAddCar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddCar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddCar->ForeColor = System::Drawing::Color::White;
			this->btnAddCar->Location = System::Drawing::Point(1704, 117);
			this->btnAddCar->Name = L"btnAddCar";
			this->btnAddCar->Size = System::Drawing::Size(159, 50);
			this->btnAddCar->TabIndex = 12;
			this->btnAddCar->Text = L"+ ADD CAR";
			this->btnAddCar->UseVisualStyleBackColor = false;
			this->btnAddCar->Click += gcnew System::EventHandler(this, &CarsForm::btnAddCar_Click);
			// 
			// colCarID
			// 
			this->colCarID->HeaderText = L"Car ID";
			this->colCarID->MinimumWidth = 8;
			this->colCarID->Name = L"colCarID";
			this->colCarID->ReadOnly = true;
			this->colCarID->Width = 120;
			// 
			// colModel
			// 
			this->colModel->HeaderText = L"Model";
			this->colModel->MinimumWidth = 8;
			this->colModel->Name = L"colModel";
			this->colModel->ReadOnly = true;
			this->colModel->Width = 350;
			// 
			// colType
			// 
			this->colType->HeaderText = L"Type";
			this->colType->MinimumWidth = 8;
			this->colType->Name = L"colType";
			this->colType->ReadOnly = true;
			this->colType->Width = 150;
			// 
			// colDailyRate
			// 
			this->colDailyRate->HeaderText = L"Daily Rate";
			this->colDailyRate->MinimumWidth = 8;
			this->colDailyRate->Name = L"colDailyRate";
			this->colDailyRate->ReadOnly = true;
			this->colDailyRate->Width = 130;
			// 
			// colStatus
			// 
			this->colStatus->HeaderText = L"Status";
			this->colStatus->MinimumWidth = 8;
			this->colStatus->Name = L"colStatus";
			this->colStatus->ReadOnly = true;
			this->colStatus->Width = 140;
			// 
			// colActions
			// 
			this->colActions->HeaderText = L"Actions";
			this->colActions->MinimumWidth = 8;
			this->colActions->Name = L"colActions";
			this->colActions->ReadOnly = true;
			this->colActions->Text = L"DELETE";
			this->colActions->UseColumnTextForButtonValue = true;
			this->colActions->Width = 160;
			// 
			// CarsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1898, 1024);
			this->Controls->Add(this->btnAddCar);
			this->Controls->Add(this->lblRowsCount);
			this->Controls->Add(this->dgvCars);
			this->Controls->Add(this->panelFilterButtons);
			this->Controls->Add(this->panelMaintenance);
			this->Controls->Add(this->panelOnRental);
			this->Controls->Add(this->panelAvailable);
			this->Controls->Add(this->panelTotalCars);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"CarsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cars Management";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panelTotalCars->ResumeLayout(false);
			this->panelTotalCars->PerformLayout();
			this->panelTotalFleet->ResumeLayout(false);
			this->panelTotalFleet->PerformLayout();
			this->panelAvailable->ResumeLayout(false);
			this->panelAvailable->PerformLayout();
			this->panelOnRental->ResumeLayout(false);
			this->panelOnRental->PerformLayout();
			this->panelMaintenance->ResumeLayout(false);
			this->panelMaintenance->PerformLayout();
			this->panelFilterButtons->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCars))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {}

private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}

private: System::Void btnAddCar_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnCustomers_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnRentals_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnReturns_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnAll_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnSedan_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnSUV_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void dgvCars_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);\

private:
	String^ ShowInputDialog(String^ title, String^ prompt, String^ defaultValue);
	void UpdateRowsCount();

private:
	void LoadCarsFromFile();
	void SaveCarsToFile();
	String^ ExtractValue(String^ line);
	void UpdateStats();
};
}
