#pragma once
#include "FileHelper.h"

namespace CarRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for RentalsForm
	/// </summary>
	public ref class RentalsForm : public System::Windows::Forms::Form
	{
	public:
		RentalsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RentalsForm()
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
	private: System::Windows::Forms::Panel^ panelInstructions;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ lblInstructionsTitle;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panelTerminalStatus;
	private: System::Windows::Forms::Label^ lblStatusText2;
	private: System::Windows::Forms::Label^ lblStatusText1;
	private: System::Windows::Forms::Label^ lblStatusValue;
	private: System::Windows::Forms::Label^ lblTerminalStatusTitle;
	private: System::Windows::Forms::Label^ lblTerminalID;
	private: System::Windows::Forms::Label^ lblStatusText3;
	private: System::Windows::Forms::Panel^ panelRentalEntry;
	private: System::Windows::Forms::Label^ lblCar;
	private: System::Windows::Forms::ComboBox^ cmbCustomer;
	private: System::Windows::Forms::Label^ lblCustomer;
	private: System::Windows::Forms::Label^ lblRentalEntryTitle;
	private: System::Windows::Forms::Label^ lblStartDate;

	private: System::Windows::Forms::NumericUpDown^ numRentDays;
	private: System::Windows::Forms::Label^ lblRentDays;
	private: System::Windows::Forms::ComboBox^ cmbCar;
	private: System::Windows::Forms::TextBox^ txtNotes;
	private: System::Windows::Forms::Label^ lblNotes;
	private: System::Windows::Forms::DateTimePicker^ dtpStartDate;
	private: System::Windows::Forms::Panel^ panelCostPreview;
	private: System::Windows::Forms::Label^ lblDailyRateValue;
	private: System::Windows::Forms::Label^ lblDailyRateLabel;
	private: System::Windows::Forms::Label^ lblCostPreviewTitle;
	private: System::Windows::Forms::Label^ lblTotalLabel;
	private: System::Windows::Forms::Label^ lblInsuranceValue;
	private: System::Windows::Forms::Label^ lblSeparator;
	private: System::Windows::Forms::Label^ lblInsuranceLabel;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ lblTotalValue;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ btnConfirmRental;

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
			this->panelInstructions = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lblInstructionsTitle = (gcnew System::Windows::Forms::Label());
			this->panelTerminalStatus = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lblTerminalID = (gcnew System::Windows::Forms::Label());
			this->lblStatusText3 = (gcnew System::Windows::Forms::Label());
			this->lblStatusText2 = (gcnew System::Windows::Forms::Label());
			this->lblStatusText1 = (gcnew System::Windows::Forms::Label());
			this->lblStatusValue = (gcnew System::Windows::Forms::Label());
			this->lblTerminalStatusTitle = (gcnew System::Windows::Forms::Label());
			this->panelRentalEntry = (gcnew System::Windows::Forms::Panel());
			this->panelCostPreview = (gcnew System::Windows::Forms::Panel());
			this->btnConfirmRental = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lblTotalValue = (gcnew System::Windows::Forms::Label());
			this->lblTotalLabel = (gcnew System::Windows::Forms::Label());
			this->lblInsuranceValue = (gcnew System::Windows::Forms::Label());
			this->lblSeparator = (gcnew System::Windows::Forms::Label());
			this->lblInsuranceLabel = (gcnew System::Windows::Forms::Label());
			this->lblDailyRateValue = (gcnew System::Windows::Forms::Label());
			this->lblDailyRateLabel = (gcnew System::Windows::Forms::Label());
			this->lblCostPreviewTitle = (gcnew System::Windows::Forms::Label());
			this->txtNotes = (gcnew System::Windows::Forms::TextBox());
			this->lblNotes = (gcnew System::Windows::Forms::Label());
			this->dtpStartDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblStartDate = (gcnew System::Windows::Forms::Label());
			this->numRentDays = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblRentDays = (gcnew System::Windows::Forms::Label());
			this->cmbCar = (gcnew System::Windows::Forms::ComboBox());
			this->lblCar = (gcnew System::Windows::Forms::Label());
			this->cmbCustomer = (gcnew System::Windows::Forms::ComboBox());
			this->lblCustomer = (gcnew System::Windows::Forms::Label());
			this->lblRentalEntryTitle = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panelInstructions->SuspendLayout();
			this->panelTerminalStatus->SuspendLayout();
			this->panelRentalEntry->SuspendLayout();
			this->panelCostPreview->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numRentDays))->BeginInit();
			this->SuspendLayout();

			// Bind events
			this->cmbCar->SelectedIndexChanged += gcnew EventHandler(this, &RentalsForm::UpdateCostPreview);
			this->numRentDays->ValueChanged += gcnew EventHandler(this, &RentalsForm::UpdateCostPreview);
			this->Load += gcnew EventHandler(this, &RentalsForm::RentalsForm_Load);
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
			this->panel1->TabIndex = 3;
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
			this->panel2->TabIndex = 4;
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
			this->btnExit->Click += gcnew System::EventHandler(this, &RentalsForm::btnExit_Click);
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
			this->btnReturns->Click += gcnew System::EventHandler(this, &RentalsForm::btnReturns_Click);
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
			this->btnCustomers->Click += gcnew System::EventHandler(this, &RentalsForm::btnCustomers_Click);
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
			this->btnCars->Click += gcnew System::EventHandler(this, &RentalsForm::btnCars_Click);
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
			this->btnDashboard->Click += gcnew System::EventHandler(this, &RentalsForm::btnDashboard_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::DarkBlue;
			this->label3->Location = System::Drawing::Point(256, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(331, 65);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Create Rental";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->label4->ForeColor = System::Drawing::Color::Gray;
			this->label4->Location = System::Drawing::Point(275, 165);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(617, 30);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Register a new vehicle lease agreement in the terminal system.";
			// 
			// panelInstructions
			// 
			this->panelInstructions->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panelInstructions->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelInstructions->Controls->Add(this->label10);
			this->panelInstructions->Controls->Add(this->label7);
			this->panelInstructions->Controls->Add(this->label6);
			this->panelInstructions->Controls->Add(this->label5);
			this->panelInstructions->Controls->Add(this->lblInstructionsTitle);
			this->panelInstructions->Location = System::Drawing::Point(280, 210);
			this->panelInstructions->Name = L"panelInstructions";
			this->panelInstructions->Size = System::Drawing::Size(466, 169);
			this->panelInstructions->TabIndex = 7;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::Color::LightGray;
			this->label10->Location = System::Drawing::Point(3, 47);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(457, 2);
			this->label10->TabIndex = 11;
			this->label10->Text = L"\"\"";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->label7->ForeColor = System::Drawing::Color::Gray;
			this->label7->Location = System::Drawing::Point(15, 120);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(439, 28);
			this->label7->TabIndex = 3;
			this->label7->Text = L" System will automatically generate an invoice ID.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->label6->ForeColor = System::Drawing::Color::Gray;
			this->label6->Location = System::Drawing::Point(16, 83);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(420, 28);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Verify customer credit limits before confirming.";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->label5->ForeColor = System::Drawing::Color::Gray;
			this->label5->Location = System::Drawing::Point(15, 51);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(449, 28);
			this->label5->TabIndex = 1;
			this->label5->Text = L"All fields marked with * are required for validation.";
			// 
			// lblInstructionsTitle
			// 
			this->lblInstructionsTitle->AutoSize = true;
			this->lblInstructionsTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInstructionsTitle->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblInstructionsTitle->Location = System::Drawing::Point(15, 9);
			this->lblInstructionsTitle->Name = L"lblInstructionsTitle";
			this->lblInstructionsTitle->Size = System::Drawing::Size(238, 32);
			this->lblInstructionsTitle->TabIndex = 0;
			this->lblInstructionsTitle->Text = L"System Instructions";
			// 
			// panelTerminalStatus
			// 
			this->panelTerminalStatus->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panelTerminalStatus->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTerminalStatus->Controls->Add(this->label9);
			this->panelTerminalStatus->Controls->Add(this->lblTerminalID);
			this->panelTerminalStatus->Controls->Add(this->lblStatusText3);
			this->panelTerminalStatus->Controls->Add(this->lblStatusText2);
			this->panelTerminalStatus->Controls->Add(this->lblStatusText1);
			this->panelTerminalStatus->Controls->Add(this->lblStatusValue);
			this->panelTerminalStatus->Controls->Add(this->lblTerminalStatusTitle);
			this->panelTerminalStatus->Location = System::Drawing::Point(280, 396);
			this->panelTerminalStatus->Name = L"panelTerminalStatus";
			this->panelTerminalStatus->Size = System::Drawing::Size(465, 251);
			this->panelTerminalStatus->TabIndex = 8;
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::LightGray;
			this->label9->Location = System::Drawing::Point(3, 49);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(457, 2);
			this->label9->TabIndex = 10;
			this->label9->Text = L"\"\"";
			// 
			// lblTerminalID
			// 
			this->lblTerminalID->AutoSize = true;
			this->lblTerminalID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTerminalID->ForeColor = System::Drawing::Color::DarkGray;
			this->lblTerminalID->Location = System::Drawing::Point(304, 215);
			this->lblTerminalID->Name = L"lblTerminalID";
			this->lblTerminalID->Size = System::Drawing::Size(156, 25);
			this->lblTerminalID->TabIndex = 5;
			this->lblTerminalID->Text = L"ID: ADM-TERM-X1";
			// 
			// lblStatusText3
			// 
			this->lblStatusText3->AutoSize = true;
			this->lblStatusText3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblStatusText3->ForeColor = System::Drawing::Color::Gray;
			this->lblStatusText3->Location = System::Drawing::Point(16, 172);
			this->lblStatusText3->Name = L"lblStatusText3";
			this->lblStatusText3->Size = System::Drawing::Size(275, 28);
			this->lblStatusText3->TabIndex = 4;
			this->lblStatusText3->Text = L"Text-only display mode active.";
			// 
			// lblStatusText2
			// 
			this->lblStatusText2->AutoSize = true;
			this->lblStatusText2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblStatusText2->ForeColor = System::Drawing::Color::Gray;
			this->lblStatusText2->Location = System::Drawing::Point(15, 130);
			this->lblStatusText2->Name = L"lblStatusText2";
			this->lblStatusText2->Size = System::Drawing::Size(289, 28);
			this->lblStatusText2->TabIndex = 3;
			this->lblStatusText2->Text = L"Hardware acceleration disabled.";
			this->lblStatusText2->Click += gcnew System::EventHandler(this, &RentalsForm::lblStatusText2_Click);
			// 
			// lblStatusText1
			// 
			this->lblStatusText1->AutoSize = true;
			this->lblStatusText1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblStatusText1->ForeColor = System::Drawing::Color::Gray;
			this->lblStatusText1->Location = System::Drawing::Point(16, 89);
			this->lblStatusText1->Name = L"lblStatusText1";
			this->lblStatusText1->Size = System::Drawing::Size(249, 28);
			this->lblStatusText1->TabIndex = 2;
			this->lblStatusText1->Text = L"All subsystems operational.";
			// 
			// lblStatusValue
			// 
			this->lblStatusValue->AutoSize = true;
			this->lblStatusValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatusValue->ForeColor = System::Drawing::Color::Green;
			this->lblStatusValue->Location = System::Drawing::Point(88, 51);
			this->lblStatusValue->Name = L"lblStatusValue";
			this->lblStatusValue->Size = System::Drawing::Size(262, 38);
			this->lblStatusValue->TabIndex = 1;
			this->lblStatusValue->Text = L"READY FOR INPUT";
			// 
			// lblTerminalStatusTitle
			// 
			this->lblTerminalStatusTitle->AutoSize = true;
			this->lblTerminalStatusTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTerminalStatusTitle->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblTerminalStatusTitle->Location = System::Drawing::Point(15, 10);
			this->lblTerminalStatusTitle->Name = L"lblTerminalStatusTitle";
			this->lblTerminalStatusTitle->Size = System::Drawing::Size(189, 32);
			this->lblTerminalStatusTitle->TabIndex = 0;
			this->lblTerminalStatusTitle->Text = L"Terminal Status";
			// 
			// panelRentalEntry
			// 
			this->panelRentalEntry->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelRentalEntry->Controls->Add(this->panelCostPreview);
			this->panelRentalEntry->Controls->Add(this->txtNotes);
			this->panelRentalEntry->Controls->Add(this->lblNotes);
			this->panelRentalEntry->Controls->Add(this->dtpStartDate);
			this->panelRentalEntry->Controls->Add(this->lblStartDate);
			this->panelRentalEntry->Controls->Add(this->numRentDays);
			this->panelRentalEntry->Controls->Add(this->lblRentDays);
			this->panelRentalEntry->Controls->Add(this->cmbCar);
			this->panelRentalEntry->Controls->Add(this->lblCar);
			this->panelRentalEntry->Controls->Add(this->cmbCustomer);
			this->panelRentalEntry->Controls->Add(this->lblCustomer);
			this->panelRentalEntry->Controls->Add(this->lblRentalEntryTitle);
			this->panelRentalEntry->Location = System::Drawing::Point(858, 210);
			this->panelRentalEntry->Name = L"panelRentalEntry";
			this->panelRentalEntry->Size = System::Drawing::Size(956, 817);
			this->panelRentalEntry->TabIndex = 9;
			// 
			// panelCostPreview
			// 
			this->panelCostPreview->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panelCostPreview->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelCostPreview->Controls->Add(this->btnConfirmRental);
			this->panelCostPreview->Controls->Add(this->label8);
			this->panelCostPreview->Controls->Add(this->lblTotalValue);
			this->panelCostPreview->Controls->Add(this->lblTotalLabel);
			this->panelCostPreview->Controls->Add(this->lblInsuranceValue);
			this->panelCostPreview->Controls->Add(this->lblSeparator);
			this->panelCostPreview->Controls->Add(this->lblInsuranceLabel);
			this->panelCostPreview->Controls->Add(this->lblDailyRateValue);
			this->panelCostPreview->Controls->Add(this->lblDailyRateLabel);
			this->panelCostPreview->Controls->Add(this->lblCostPreviewTitle);
			this->panelCostPreview->Location = System::Drawing::Point(20, 447);
			this->panelCostPreview->Name = L"panelCostPreview";
			this->panelCostPreview->Size = System::Drawing::Size(911, 354);
			this->panelCostPreview->TabIndex = 11;
			this->panelCostPreview->Click += gcnew System::EventHandler(this, &RentalsForm::UpdateCostPreview);
			// 
			// btnConfirmRental
			// 
			this->btnConfirmRental->BackColor = System::Drawing::Color::DarkGreen;
			this->btnConfirmRental->FlatAppearance->BorderSize = 0;
			this->btnConfirmRental->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConfirmRental->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->btnConfirmRental->ForeColor = System::Drawing::Color::White;
			this->btnConfirmRental->Location = System::Drawing::Point(307, 285);
			this->btnConfirmRental->Name = L"btnConfirmRental";
			this->btnConfirmRental->Size = System::Drawing::Size(350, 50);
			this->btnConfirmRental->TabIndex = 9;
			this->btnConfirmRental->Text = L"CONFIRM RENTAL";
			this->btnConfirmRental->UseVisualStyleBackColor = false;
			this->btnConfirmRental->Click += gcnew System::EventHandler(this, &RentalsForm::btnConfirmRental_Click);
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::Color::LightGray;
			this->label8->Location = System::Drawing::Point(6, 187);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(887, 2);
			this->label8->TabIndex = 8;
			this->label8->Text = L"\"\"";
			// 
			// lblTotalValue
			// 
			this->lblTotalValue->AutoSize = true;
			this->lblTotalValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalValue->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblTotalValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblTotalValue->Location = System::Drawing::Point(792, 201);
			this->lblTotalValue->Name = L"lblTotalValue";
			this->lblTotalValue->Size = System::Drawing::Size(101, 45);
			this->lblTotalValue->TabIndex = 7;
			this->lblTotalValue->Text = L"$0.00";
			// 
			// lblTotalLabel
			// 
			this->lblTotalLabel->AutoSize = true;
			this->lblTotalLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalLabel->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblTotalLabel->Location = System::Drawing::Point(17, 201);
			this->lblTotalLabel->Name = L"lblTotalLabel";
			this->lblTotalLabel->Size = System::Drawing::Size(287, 45);
			this->lblTotalLabel->TabIndex = 6;
			this->lblTotalLabel->Text = L"TOTAL ESTIMATE:";
			// 
			// lblInsuranceValue
			// 
			this->lblInsuranceValue->AutoSize = true;
			this->lblInsuranceValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInsuranceValue->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblInsuranceValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblInsuranceValue->Location = System::Drawing::Point(805, 129);
			this->lblInsuranceValue->Name = L"lblInsuranceValue";
			this->lblInsuranceValue->Size = System::Drawing::Size(77, 32);
			this->lblInsuranceValue->TabIndex = 5;
			this->lblInsuranceValue->Text = L"$0.00";
			// 
			// lblSeparator
			// 
			this->lblSeparator->BackColor = System::Drawing::Color::LightGray;
			this->lblSeparator->Location = System::Drawing::Point(6, 51);
			this->lblSeparator->Name = L"lblSeparator";
			this->lblSeparator->Size = System::Drawing::Size(887, 2);
			this->lblSeparator->TabIndex = 4;
			this->lblSeparator->Text = L"\"\"";
			// 
			// lblInsuranceLabel
			// 
			this->lblInsuranceLabel->AutoSize = true;
			this->lblInsuranceLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->lblInsuranceLabel->ForeColor = System::Drawing::Color::Gray;
			this->lblInsuranceLabel->Location = System::Drawing::Point(19, 129);
			this->lblInsuranceLabel->Name = L"lblInsuranceLabel";
			this->lblInsuranceLabel->Size = System::Drawing::Size(224, 32);
			this->lblInsuranceLabel->TabIndex = 3;
			this->lblInsuranceLabel->Text = L"Insurance Premium:";
			// 
			// lblDailyRateValue
			// 
			this->lblDailyRateValue->AutoSize = true;
			this->lblDailyRateValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDailyRateValue->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblDailyRateValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblDailyRateValue->Location = System::Drawing::Point(805, 80);
			this->lblDailyRateValue->Name = L"lblDailyRateValue";
			this->lblDailyRateValue->Size = System::Drawing::Size(77, 32);
			this->lblDailyRateValue->TabIndex = 2;
			this->lblDailyRateValue->Text = L"$0.00";
			// 
			// lblDailyRateLabel
			// 
			this->lblDailyRateLabel->AutoSize = true;
			this->lblDailyRateLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->lblDailyRateLabel->ForeColor = System::Drawing::Color::Gray;
			this->lblDailyRateLabel->Location = System::Drawing::Point(19, 80);
			this->lblDailyRateLabel->Name = L"lblDailyRateLabel";
			this->lblDailyRateLabel->Size = System::Drawing::Size(182, 32);
			this->lblDailyRateLabel->TabIndex = 1;
			this->lblDailyRateLabel->Text = L"Daily Rate Base:";
			// 
			// lblCostPreviewTitle
			// 
			this->lblCostPreviewTitle->AutoSize = true;
			this->lblCostPreviewTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCostPreviewTitle->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblCostPreviewTitle->Location = System::Drawing::Point(3, 0);
			this->lblCostPreviewTitle->Name = L"lblCostPreviewTitle";
			this->lblCostPreviewTitle->Size = System::Drawing::Size(413, 38);
			this->lblCostPreviewTitle->TabIndex = 0;
			this->lblCostPreviewTitle->Text = L"COST CALCULATION PREVIEW";
			// 
			// txtNotes
			// 
			this->txtNotes->Location = System::Drawing::Point(10, 362);
			this->txtNotes->Multiline = true;
			this->txtNotes->Name = L"txtNotes";
			this->txtNotes->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtNotes->Size = System::Drawing::Size(908, 60);
			this->txtNotes->TabIndex = 10;
			// 
			// lblNotes
			// 
			this->lblNotes->AutoSize = true;
			this->lblNotes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNotes->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblNotes->Location = System::Drawing::Point(15, 316);
			this->lblNotes->Name = L"lblNotes";
			this->lblNotes->Size = System::Drawing::Size(223, 30);
			this->lblNotes->TabIndex = 9;
			this->lblNotes->Text = L"ADDITIONAL NOTES";
			// 
			// dtpStartDate
			// 
			this->dtpStartDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpStartDate->Location = System::Drawing::Point(529, 259);
			this->dtpStartDate->Name = L"dtpStartDate";
			this->dtpStartDate->Size = System::Drawing::Size(402, 26);
			this->dtpStartDate->TabIndex = 8;
			// 
			// lblStartDate
			// 
			this->lblStartDate->AutoSize = true;
			this->lblStartDate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStartDate->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblStartDate->Location = System::Drawing::Point(524, 217);
			this->lblStartDate->Name = L"lblStartDate";
			this->lblStartDate->Size = System::Drawing::Size(154, 30);
			this->lblStartDate->TabIndex = 7;
			this->lblStartDate->Text = L"START DATE *";
			// 
			// numRentDays
			// 
			this->numRentDays->Location = System::Drawing::Point(20, 259);
			this->numRentDays->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 365, 0, 0, 0 });
			this->numRentDays->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numRentDays->Name = L"numRentDays";
			this->numRentDays->Size = System::Drawing::Size(384, 26);
			this->numRentDays->TabIndex = 6;
			this->numRentDays->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// lblRentDays
			// 
			this->lblRentDays->AutoSize = true;
			this->lblRentDays->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRentDays->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblRentDays->Location = System::Drawing::Point(15, 217);
			this->lblRentDays->Name = L"lblRentDays";
			this->lblRentDays->Size = System::Drawing::Size(145, 30);
			this->lblRentDays->TabIndex = 5;
			this->lblRentDays->Text = L"RENT DAYS *";
			// 
			// cmbCar
			// 
			this->cmbCar->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCar->FormattingEnabled = true;
			this->cmbCar->Location = System::Drawing::Point(20, 171);
			this->cmbCar->Name = L"cmbCar";
			this->cmbCar->Size = System::Drawing::Size(911, 28);
			this->cmbCar->TabIndex = 4;
			// 
			// lblCar
			// 
			this->lblCar->AutoSize = true;
			this->lblCar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCar->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblCar->Location = System::Drawing::Point(15, 138);
			this->lblCar->Name = L"lblCar";
			this->lblCar->Size = System::Drawing::Size(72, 30);
			this->lblCar->TabIndex = 3;
			this->lblCar->Text = L"CAR *";
			// 
			// cmbCustomer
			// 
			this->cmbCustomer->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCustomer->FormattingEnabled = true;
			this->cmbCustomer->Location = System::Drawing::Point(20, 89);
			this->cmbCustomer->Name = L"cmbCustomer";
			this->cmbCustomer->Size = System::Drawing::Size(911, 28);
			this->cmbCustomer->TabIndex = 2;
			// 
			// lblCustomer
			// 
			this->lblCustomer->AutoSize = true;
			this->lblCustomer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCustomer->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblCustomer->Location = System::Drawing::Point(15, 51);
			this->lblCustomer->Name = L"lblCustomer";
			this->lblCustomer->Size = System::Drawing::Size(147, 30);
			this->lblCustomer->TabIndex = 1;
			this->lblCustomer->Text = L"CUSTOMER *";
			// 
			// lblRentalEntryTitle
			// 
			this->lblRentalEntryTitle->AutoSize = true;
			this->lblRentalEntryTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRentalEntryTitle->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblRentalEntryTitle->Location = System::Drawing::Point(321, 9);
			this->lblRentalEntryTitle->Name = L"lblRentalEntryTitle";
			this->lblRentalEntryTitle->Size = System::Drawing::Size(305, 38);
			this->lblRentalEntryTitle->TabIndex = 0;
			this->lblRentalEntryTitle->Text = L"RENTAL ENTRY FORM";
			// 
			// RentalsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1898, 1024);
			this->Controls->Add(this->panelRentalEntry);
			this->Controls->Add(this->panelTerminalStatus);
			this->Controls->Add(this->panelInstructions);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"RentalsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Create Rental";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panelInstructions->ResumeLayout(false);
			this->panelInstructions->PerformLayout();
			this->panelTerminalStatus->ResumeLayout(false);
			this->panelTerminalStatus->PerformLayout();
			this->panelRentalEntry->ResumeLayout(false);
			this->panelRentalEntry->PerformLayout();
			this->panelCostPreview->ResumeLayout(false);
			this->panelCostPreview->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numRentDays))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lblStatusText2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnCars_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnCustomers_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnReturns_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnConfirmRental_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void UpdateCostPreview(System::Object^ sender, System::EventArgs^ e);

private:

	void RentalsForm_Load(System::Object^ sender, System::EventArgs^ e);
	void SaveRentalToFile();
	Dictionary<String^, double>^ carRates;
};
}
