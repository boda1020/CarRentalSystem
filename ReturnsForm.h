#pragma once
#include "FileHelper.h"

namespace CarRentalSystem {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ReturnsForm : public System::Windows::Forms::Form
	{
	public:
		ReturnsForm(void);
	protected:
		~ReturnsForm();
	private:
		// Functions
		void LoadRentalInfo(System::Object^ sender, System::EventArgs^ e);
		void UpdateTotals(System::Object^ sender, System::EventArgs^ e);
		String^ GetCustomerName(String^ customerId);
		String^ GetCarModel(String^ carId);
		double GetDailyRate(String^ carId);

		// Event handlers
		void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e);
		void btnCars_Click(System::Object^ sender, System::EventArgs^ e);
		void btnCustomers_Click(System::Object^ sender, System::EventArgs^ e);
		void btnRentals_Click(System::Object^ sender, System::EventArgs^ e);
		void btnExit_Click(System::Object^ sender, System::EventArgs^ e);
		void btnReturnVehicle_Click(System::Object^ sender, System::EventArgs^ e);
		void btnSaveProgress_Click(System::Object^ sender, System::EventArgs^ e);
		void ReturnsForm_Load(System::Object^ sender, System::EventArgs^ e);
		void lblRentalEntryTitle_Click(System::Object^ sender, System::EventArgs^ e);

		// Data members
		String^ m_rentalNo;
		String^ m_customerId;
		String^ m_carId;
		String^ m_startDate;
		String^ m_endDate;
		int m_rentalDays;
		double m_rentalTotal;
		double m_dailyRate;

		// Controls (from designer)
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
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Panel^ panelBillingSummary;
		System::Windows::Forms::Label^ lblDailyRateValue;
		System::Windows::Forms::Label^ lblDailyRateLabel;
		System::Windows::Forms::Label^ lblBillingTitle;
		System::Windows::Forms::Label^ lblInsuranceValue;
		System::Windows::Forms::Label^ lblInsuranceLabel;
		System::Windows::Forms::Label^ lblCleaningValue;
		System::Windows::Forms::Label^ lblCleaningLabel;
		System::Windows::Forms::Label^ lblOverageValue;
		System::Windows::Forms::Label^ lblOverageLabel;
		System::Windows::Forms::Label^ lblTaxesValue;
		System::Windows::Forms::Label^ lblTaxesLabel;
		System::Windows::Forms::Panel^ panelTotalDue;
		System::Windows::Forms::Label^ lblTotalDueValue;
		System::Windows::Forms::Label^ lblTotalDueTitle;
		System::Windows::Forms::Button^ btnSaveProgress;
		System::Windows::Forms::Button^ btnReturnVehicle;
		System::Windows::Forms::Label^ label8;
		System::Windows::Forms::Label^ label11;
		System::Windows::Forms::Label^ label9;
		System::Windows::Forms::Panel^ panelRentalEntry;
		System::Windows::Forms::TextBox^ txtNotes;
		System::Windows::Forms::Label^ lblNotes;

		System::Windows::Forms::Label^ lblReturnPeriodValue;

		System::Windows::Forms::Label^ lblReturnDaysValue;
		System::Windows::Forms::ComboBox^ cmbReturnCar;
		System::Windows::Forms::Label^ lblCar;
		System::Windows::Forms::ComboBox^ cmbReturnCustomer;
		System::Windows::Forms::Label^ lblCustomer;
		System::Windows::Forms::Label^ lblRentalEntryTitle;
		System::Windows::Forms::CheckBox^ chkCleaningFee;
		System::Windows::Forms::NumericUpDown^ numFuelSurcharge;
		System::Windows::Forms::NumericUpDown^ numDamageDeduction;
		System::Windows::Forms::Label^ lblFuelSurchargeLabel;
		System::Windows::Forms::Label^ lblDamageLabel;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
		   System::ComponentModel::Container^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

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
			this->panelBillingSummary = (gcnew System::Windows::Forms::Panel());
			this->btnSaveProgress = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->btnReturnVehicle = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panelTotalDue = (gcnew System::Windows::Forms::Panel());
			this->lblTotalDueValue = (gcnew System::Windows::Forms::Label());
			this->lblTotalDueTitle = (gcnew System::Windows::Forms::Label());
			this->lblTaxesValue = (gcnew System::Windows::Forms::Label());
			this->lblTaxesLabel = (gcnew System::Windows::Forms::Label());
			this->lblCleaningValue = (gcnew System::Windows::Forms::Label());
			this->lblCleaningLabel = (gcnew System::Windows::Forms::Label());
			this->lblOverageValue = (gcnew System::Windows::Forms::Label());
			this->lblOverageLabel = (gcnew System::Windows::Forms::Label());
			this->lblInsuranceValue = (gcnew System::Windows::Forms::Label());
			this->lblInsuranceLabel = (gcnew System::Windows::Forms::Label());
			this->lblDailyRateValue = (gcnew System::Windows::Forms::Label());
			this->lblDailyRateLabel = (gcnew System::Windows::Forms::Label());
			this->lblBillingTitle = (gcnew System::Windows::Forms::Label());
			this->panelRentalEntry = (gcnew System::Windows::Forms::Panel());
			this->numDamageDeduction = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblDamageLabel = (gcnew System::Windows::Forms::Label());
			this->numFuelSurcharge = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblFuelSurchargeLabel = (gcnew System::Windows::Forms::Label());
			this->chkCleaningFee = (gcnew System::Windows::Forms::CheckBox());
			this->txtNotes = (gcnew System::Windows::Forms::TextBox());
			this->lblNotes = (gcnew System::Windows::Forms::Label());
			this->lblReturnPeriodValue = (gcnew System::Windows::Forms::Label());
			this->lblReturnDaysValue = (gcnew System::Windows::Forms::Label());
			this->cmbReturnCar = (gcnew System::Windows::Forms::ComboBox());
			this->lblCar = (gcnew System::Windows::Forms::Label());
			this->cmbReturnCustomer = (gcnew System::Windows::Forms::ComboBox());
			this->lblCustomer = (gcnew System::Windows::Forms::Label());
			this->lblRentalEntryTitle = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panelBillingSummary->SuspendLayout();
			this->panelTotalDue->SuspendLayout();
			this->panelRentalEntry->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDamageDeduction))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numFuelSurcharge))->BeginInit();
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
			this->btnExit->Click += gcnew System::EventHandler(this, &ReturnsForm::btnExit_Click);
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
			this->btnRentals->Click += gcnew System::EventHandler(this, &ReturnsForm::btnRentals_Click);
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
			this->btnCustomers->Click += gcnew System::EventHandler(this, &ReturnsForm::btnCustomers_Click);
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
			this->btnCars->Click += gcnew System::EventHandler(this, &ReturnsForm::btnCars_Click);
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
			this->btnDashboard->Click += gcnew System::EventHandler(this, &ReturnsForm::btnDashboard_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::DarkBlue;
			this->label3->Location = System::Drawing::Point(256, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(535, 65);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Return Vehicle Process";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->label4->ForeColor = System::Drawing::Color::Gray;
			this->label4->Location = System::Drawing::Point(275, 165);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(807, 30);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Process vehicle return, check for damages, and finalize billing for Rental #R-882"
				L"91.";
			// 
			// panelBillingSummary
			// 
			this->panelBillingSummary->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelBillingSummary->Controls->Add(this->btnSaveProgress);
			this->panelBillingSummary->Controls->Add(this->label11);
			this->panelBillingSummary->Controls->Add(this->btnReturnVehicle);
			this->panelBillingSummary->Controls->Add(this->label9);
			this->panelBillingSummary->Controls->Add(this->label8);
			this->panelBillingSummary->Controls->Add(this->panelTotalDue);
			this->panelBillingSummary->Controls->Add(this->lblTaxesValue);
			this->panelBillingSummary->Controls->Add(this->lblTaxesLabel);
			this->panelBillingSummary->Controls->Add(this->lblCleaningValue);
			this->panelBillingSummary->Controls->Add(this->lblCleaningLabel);
			this->panelBillingSummary->Controls->Add(this->lblOverageValue);
			this->panelBillingSummary->Controls->Add(this->lblOverageLabel);
			this->panelBillingSummary->Controls->Add(this->lblInsuranceValue);
			this->panelBillingSummary->Controls->Add(this->lblInsuranceLabel);
			this->panelBillingSummary->Controls->Add(this->lblDailyRateValue);
			this->panelBillingSummary->Controls->Add(this->lblDailyRateLabel);
			this->panelBillingSummary->Controls->Add(this->lblBillingTitle);
			this->panelBillingSummary->Location = System::Drawing::Point(1123, 210);
			this->panelBillingSummary->Name = L"panelBillingSummary";
			this->panelBillingSummary->Size = System::Drawing::Size(763, 663);
			this->panelBillingSummary->TabIndex = 7;
			// 
			// btnSaveProgress
			// 
			this->btnSaveProgress->BackColor = System::Drawing::Color::DarkBlue;
			this->btnSaveProgress->FlatAppearance->BorderSize = 0;
			this->btnSaveProgress->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnSaveProgress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSaveProgress->ForeColor = System::Drawing::Color::White;
			this->btnSaveProgress->Location = System::Drawing::Point(396, 560);
			this->btnSaveProgress->Name = L"btnSaveProgress";
			this->btnSaveProgress->Size = System::Drawing::Size(200, 45);
			this->btnSaveProgress->TabIndex = 11;
			this->btnSaveProgress->Text = L"SAVE PROGRESS";
			this->btnSaveProgress->UseVisualStyleBackColor = false;
			this->btnSaveProgress->Click += gcnew System::EventHandler(this, &ReturnsForm::btnSaveProgress_Click);
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::Color::LightGray;
			this->label11->Location = System::Drawing::Point(9, 511);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(738, 2);
			this->label11->TabIndex = 15;
			this->label11->Text = L"\"\"";
			// 
			// btnReturnVehicle
			// 
			this->btnReturnVehicle->BackColor = System::Drawing::Color::DarkGreen;
			this->btnReturnVehicle->FlatAppearance->BorderSize = 0;
			this->btnReturnVehicle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReturnVehicle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReturnVehicle->ForeColor = System::Drawing::Color::White;
			this->btnReturnVehicle->Location = System::Drawing::Point(157, 560);
			this->btnReturnVehicle->Name = L"btnReturnVehicle";
			this->btnReturnVehicle->Size = System::Drawing::Size(200, 45);
			this->btnReturnVehicle->TabIndex = 10;
			this->btnReturnVehicle->Text = L"RETURN VEHICLE";
			this->btnReturnVehicle->UseVisualStyleBackColor = false;
			this->btnReturnVehicle->Click += gcnew System::EventHandler(this, &ReturnsForm::btnReturnVehicle_Click);
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::LightGray;
			this->label9->Location = System::Drawing::Point(9, 360);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(738, 2);
			this->label9->TabIndex = 14;
			this->label9->Text = L"\"\"";
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::Color::LightGray;
			this->label8->Location = System::Drawing::Point(12, 65);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(738, 2);
			this->label8->TabIndex = 13;
			this->label8->Text = L"\"\"";
			// 
			// panelTotalDue
			// 
			this->panelTotalDue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->panelTotalDue->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTotalDue->Controls->Add(this->lblTotalDueValue);
			this->panelTotalDue->Controls->Add(this->lblTotalDueTitle);
			this->panelTotalDue->Location = System::Drawing::Point(13, 379);
			this->panelTotalDue->Name = L"panelTotalDue";
			this->panelTotalDue->Size = System::Drawing::Size(734, 120);
			this->panelTotalDue->TabIndex = 9;
			// 
			// lblTotalDueValue
			// 
			this->lblTotalDueValue->AutoSize = true;
			this->lblTotalDueValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalDueValue->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTotalDueValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblTotalDueValue->Location = System::Drawing::Point(438, 34);
			this->lblTotalDueValue->Name = L"lblTotalDueValue";
			this->lblTotalDueValue->Size = System::Drawing::Size(286, 74);
			this->lblTotalDueValue->TabIndex = 1;
			this->lblTotalDueValue->Text = L"$1,268.39";
			// 
			// lblTotalDueTitle
			// 
			this->lblTotalDueTitle->AutoSize = true;
			this->lblTotalDueTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalDueTitle->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblTotalDueTitle->Location = System::Drawing::Point(3, 5);
			this->lblTotalDueTitle->Name = L"lblTotalDueTitle";
			this->lblTotalDueTitle->Size = System::Drawing::Size(298, 38);
			this->lblTotalDueTitle->TabIndex = 0;
			this->lblTotalDueTitle->Text = L"TOTAL AMOUNT DUE";
			// 
			// lblTaxesValue
			// 
			this->lblTaxesValue->AutoSize = true;
			this->lblTaxesValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblTaxesValue->ForeColor = System::Drawing::Color::Black;
			this->lblTaxesValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblTaxesValue->Location = System::Drawing::Point(656, 302);
			this->lblTaxesValue->Name = L"lblTaxesValue";
			this->lblTaxesValue->Size = System::Drawing::Size(82, 28);
			this->lblTaxesValue->TabIndex = 10;
			this->lblTaxesValue->Text = L"$103.39";
			// 
			// lblTaxesLabel
			// 
			this->lblTaxesLabel->AutoSize = true;
			this->lblTaxesLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblTaxesLabel->ForeColor = System::Drawing::Color::Gray;
			this->lblTaxesLabel->Location = System::Drawing::Point(8, 302);
			this->lblTaxesLabel->Name = L"lblTaxesLabel";
			this->lblTaxesLabel->Size = System::Drawing::Size(142, 28);
			this->lblTaxesLabel->TabIndex = 9;
			this->lblTaxesLabel->Text = L"Taxes (8.875%):";
			// 
			// lblCleaningValue
			// 
			this->lblCleaningValue->AutoSize = true;
			this->lblCleaningValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblCleaningValue->ForeColor = System::Drawing::Color::Red;
			this->lblCleaningValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblCleaningValue->Location = System::Drawing::Point(656, 252);
			this->lblCleaningValue->Name = L"lblCleaningValue";
			this->lblCleaningValue->Size = System::Drawing::Size(82, 28);
			this->lblCleaningValue->TabIndex = 8;
			this->lblCleaningValue->Text = L"$150.00";
			// 
			// lblCleaningLabel
			// 
			this->lblCleaningLabel->AutoSize = true;
			this->lblCleaningLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblCleaningLabel->ForeColor = System::Drawing::Color::Gray;
			this->lblCleaningLabel->Location = System::Drawing::Point(8, 252);
			this->lblCleaningLabel->Name = L"lblCleaningLabel";
			this->lblCleaningLabel->Size = System::Drawing::Size(304, 28);
			this->lblCleaningLabel->TabIndex = 7;
			this->lblCleaningLabel->Text = L"Cleaning Fee (Smoking detected):";
			// 
			// lblOverageValue
			// 
			this->lblOverageValue->AutoSize = true;
			this->lblOverageValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblOverageValue->ForeColor = System::Drawing::Color::Green;
			this->lblOverageValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblOverageValue->Location = System::Drawing::Point(656, 204);
			this->lblOverageValue->Name = L"lblOverageValue";
			this->lblOverageValue->Size = System::Drawing::Size(60, 28);
			this->lblOverageValue->TabIndex = 6;
			this->lblOverageValue->Text = L"$0.00";
			// 
			// lblOverageLabel
			// 
			this->lblOverageLabel->AutoSize = true;
			this->lblOverageLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblOverageLabel->ForeColor = System::Drawing::Color::Gray;
			this->lblOverageLabel->Location = System::Drawing::Point(8, 204);
			this->lblOverageLabel->Name = L"lblOverageLabel";
			this->lblOverageLabel->Size = System::Drawing::Size(165, 28);
			this->lblOverageLabel->TabIndex = 5;
			this->lblOverageLabel->Text = L"Overage Charges:";
			// 
			// lblInsuranceValue
			// 
			this->lblInsuranceValue->AutoSize = true;
			this->lblInsuranceValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblInsuranceValue->ForeColor = System::Drawing::Color::Black;
			this->lblInsuranceValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblInsuranceValue->Location = System::Drawing::Point(656, 149);
			this->lblInsuranceValue->Name = L"lblInsuranceValue";
			this->lblInsuranceValue->Size = System::Drawing::Size(82, 28);
			this->lblInsuranceValue->TabIndex = 4;
			this->lblInsuranceValue->Text = L"$175.00";
			// 
			// lblInsuranceLabel
			// 
			this->lblInsuranceLabel->AutoSize = true;
			this->lblInsuranceLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblInsuranceLabel->ForeColor = System::Drawing::Color::Gray;
			this->lblInsuranceLabel->Location = System::Drawing::Point(8, 155);
			this->lblInsuranceLabel->Name = L"lblInsuranceLabel";
			this->lblInsuranceLabel->Size = System::Drawing::Size(281, 28);
			this->lblInsuranceLabel->TabIndex = 3;
			this->lblInsuranceLabel->Text = L"Insurance (Premium Coverage):";
			// 
			// lblDailyRateValue
			// 
			this->lblDailyRateValue->AutoSize = true;
			this->lblDailyRateValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblDailyRateValue->ForeColor = System::Drawing::Color::Black;
			this->lblDailyRateValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblDailyRateValue->Location = System::Drawing::Point(656, 100);
			this->lblDailyRateValue->Name = L"lblDailyRateValue";
			this->lblDailyRateValue->Size = System::Drawing::Size(82, 28);
			this->lblDailyRateValue->TabIndex = 2;
			this->lblDailyRateValue->Text = L"$840.00";
			// 
			// lblDailyRateLabel
			// 
			this->lblDailyRateLabel->AutoSize = true;
			this->lblDailyRateLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblDailyRateLabel->ForeColor = System::Drawing::Color::Gray;
			this->lblDailyRateLabel->Location = System::Drawing::Point(11, 100);
			this->lblDailyRateLabel->Name = L"lblDailyRateLabel";
			this->lblDailyRateLabel->Size = System::Drawing::Size(221, 28);
			this->lblDailyRateLabel->TabIndex = 1;
			this->lblDailyRateLabel->Text = L"Daily Rate ($120.00 x 7):";
			// 
			// lblBillingTitle
			// 
			this->lblBillingTitle->AutoSize = true;
			this->lblBillingTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBillingTitle->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblBillingTitle->Location = System::Drawing::Point(281, 10);
			this->lblBillingTitle->Name = L"lblBillingTitle";
			this->lblBillingTitle->Size = System::Drawing::Size(236, 32);
			this->lblBillingTitle->TabIndex = 0;
			this->lblBillingTitle->Text = L"BILLING SUMMARY";
			// 
			// panelRentalEntry
			// 
			this->panelRentalEntry->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelRentalEntry->Controls->Add(this->label6);
			this->panelRentalEntry->Controls->Add(this->label5);
			this->panelRentalEntry->Controls->Add(this->numDamageDeduction);
			this->panelRentalEntry->Controls->Add(this->lblDamageLabel);
			this->panelRentalEntry->Controls->Add(this->numFuelSurcharge);
			this->panelRentalEntry->Controls->Add(this->lblFuelSurchargeLabel);
			this->panelRentalEntry->Controls->Add(this->chkCleaningFee);
			this->panelRentalEntry->Controls->Add(this->txtNotes);
			this->panelRentalEntry->Controls->Add(this->lblNotes);
			this->panelRentalEntry->Controls->Add(this->lblReturnPeriodValue);
			this->panelRentalEntry->Controls->Add(this->lblReturnDaysValue);
			this->panelRentalEntry->Controls->Add(this->cmbReturnCar);
			this->panelRentalEntry->Controls->Add(this->lblCar);
			this->panelRentalEntry->Controls->Add(this->cmbReturnCustomer);
			this->panelRentalEntry->Controls->Add(this->lblCustomer);
			this->panelRentalEntry->Controls->Add(this->lblRentalEntryTitle);
			this->panelRentalEntry->Location = System::Drawing::Point(280, 210);
			this->panelRentalEntry->Name = L"panelRentalEntry";
			this->panelRentalEntry->Size = System::Drawing::Size(777, 663);
			this->panelRentalEntry->TabIndex = 10;
			// 
			// numDamageDeduction
			// 
			this->numDamageDeduction->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->numDamageDeduction->Location = System::Drawing::Point(482, 559);
			this->numDamageDeduction->Name = L"numDamageDeduction";
			this->numDamageDeduction->Size = System::Drawing::Size(271, 30);
			this->numDamageDeduction->TabIndex = 16;
			// 
			// lblDamageLabel
			// 
			this->lblDamageLabel->AutoSize = true;
			this->lblDamageLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->lblDamageLabel->Location = System::Drawing::Point(6, 560);
			this->lblDamageLabel->Name = L"lblDamageLabel";
			this->lblDamageLabel->Size = System::Drawing::Size(225, 29);
			this->lblDamageLabel->TabIndex = 15;
			this->lblDamageLabel->Text = L"Damage Deduction:";
			// 
			// numFuelSurcharge
			// 
			this->numFuelSurcharge->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->numFuelSurcharge->Location = System::Drawing::Point(482, 498);
			this->numFuelSurcharge->Name = L"numFuelSurcharge";
			this->numFuelSurcharge->Size = System::Drawing::Size(271, 30);
			this->numFuelSurcharge->TabIndex = 13;
			// 
			// lblFuelSurchargeLabel
			// 
			this->lblFuelSurchargeLabel->AutoSize = true;
			this->lblFuelSurchargeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->lblFuelSurchargeLabel->Location = System::Drawing::Point(6, 499);
			this->lblFuelSurchargeLabel->Name = L"lblFuelSurchargeLabel";
			this->lblFuelSurchargeLabel->Size = System::Drawing::Size(184, 29);
			this->lblFuelSurchargeLabel->TabIndex = 12;
			this->lblFuelSurchargeLabel->Text = L"Fuel Surcharge:";
			// 
			// chkCleaningFee
			// 
			this->chkCleaningFee->AutoSize = true;
			this->chkCleaningFee->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->chkCleaningFee->Location = System::Drawing::Point(10, 440);
			this->chkCleaningFee->Name = L"chkCleaningFee";
			this->chkCleaningFee->Size = System::Drawing::Size(322, 33);
			this->chkCleaningFee->TabIndex = 11;
			this->chkCleaningFee->Text = L"Smoking detected (+$150)";
			this->chkCleaningFee->UseVisualStyleBackColor = true;
			// 
			// txtNotes
			// 
			this->txtNotes->Location = System::Drawing::Point(10, 362);
			this->txtNotes->Multiline = true;
			this->txtNotes->Name = L"txtNotes";
			this->txtNotes->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtNotes->Size = System::Drawing::Size(743, 60);
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
			// lblReturnPeriodValue
			// 
			this->lblReturnPeriodValue->AutoSize = true;
			this->lblReturnPeriodValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblReturnPeriodValue->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblReturnPeriodValue->Location = System::Drawing::Point(444, 252);
			this->lblReturnPeriodValue->Name = L"lblReturnPeriodValue";
			this->lblReturnPeriodValue->Size = System::Drawing::Size(135, 30);
			this->lblReturnPeriodValue->TabIndex = 7;
			this->lblReturnPeriodValue->Text = L"00-00-0000";
			// 
			// lblReturnDaysValue
			// 
			this->lblReturnDaysValue->AutoSize = true;
			this->lblReturnDaysValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblReturnDaysValue->ForeColor = System::Drawing::Color::DarkBlue;
			this->lblReturnDaysValue->Location = System::Drawing::Point(15, 252);
			this->lblReturnDaysValue->Name = L"lblReturnDaysValue";
			this->lblReturnDaysValue->Size = System::Drawing::Size(26, 30);
			this->lblReturnDaysValue->TabIndex = 5;
			this->lblReturnDaysValue->Text = L"0";
			// 
			// cmbReturnCar
			// 
			this->cmbReturnCar->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbReturnCar->FormattingEnabled = true;
			this->cmbReturnCar->Location = System::Drawing::Point(20, 171);
			this->cmbReturnCar->Name = L"cmbReturnCar";
			this->cmbReturnCar->Size = System::Drawing::Size(733, 28);
			this->cmbReturnCar->TabIndex = 4;
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
			// cmbReturnCustomer
			// 
			this->cmbReturnCustomer->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbReturnCustomer->FormattingEnabled = true;
			this->cmbReturnCustomer->Location = System::Drawing::Point(20, 89);
			this->cmbReturnCustomer->Name = L"cmbReturnCustomer";
			this->cmbReturnCustomer->Size = System::Drawing::Size(733, 28);
			this->cmbReturnCustomer->TabIndex = 2;
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
			this->lblRentalEntryTitle->Location = System::Drawing::Point(228, 5);
			this->lblRentalEntryTitle->Name = L"lblRentalEntryTitle";
			this->lblRentalEntryTitle->Size = System::Drawing::Size(304, 38);
			this->lblRentalEntryTitle->TabIndex = 0;
			this->lblRentalEntryTitle->Text = L"RENTAL IFORMATION";
			this->lblRentalEntryTitle->Click += gcnew System::EventHandler(this, &ReturnsForm::lblRentalEntryTitle_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::DarkBlue;
			this->label5->Location = System::Drawing::Point(15, 215);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(145, 30);
			this->label5->TabIndex = 17;
			this->label5->Text = L"RENT DAYS *";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::DarkBlue;
			this->label6->Location = System::Drawing::Point(444, 215);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(154, 30);
			this->label6->TabIndex = 18;
			this->label6->Text = L"START DATE *";
			// 
			// ReturnsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1898, 1024);
			this->Controls->Add(this->panelRentalEntry);
			this->Controls->Add(this->panelBillingSummary);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"ReturnsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Return Car Screen";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panelBillingSummary->ResumeLayout(false);
			this->panelBillingSummary->PerformLayout();
			this->panelTotalDue->ResumeLayout(false);
			this->panelTotalDue->PerformLayout();
			this->panelRentalEntry->ResumeLayout(false);
			this->panelRentalEntry->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDamageDeduction))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numFuelSurcharge))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

};
}
