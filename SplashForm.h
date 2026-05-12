#pragma once

namespace CarRentalSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SplashForm
	/// </summary>
	public ref class SplashForm : public System::Windows::Forms::Form
	{
	public:
		SplashForm(void)
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
		~SplashForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ mainPanel;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Label^ lblSubtitle;
	private: System::Windows::Forms::Panel^ cardFleet;

	private: System::Windows::Forms::Panel^ cardCustomer;
	private: System::Windows::Forms::Label^ lblFleetTitle;
	private: System::Windows::Forms::Label^ lblFleetTitle2;
	private: System::Windows::Forms::Label^ lblFleetDesc;


	private: System::Windows::Forms::Label^ lblFleetDesc2;
	private: System::Windows::Forms::Panel^ cardRental;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblFleetDesc3;
	private: System::Windows::Forms::Label^ lblFleetTitle3;
	private: System::Windows::Forms::Button^ btnEnter;
	private: System::Windows::Forms::Label^ lblCopyright;
	private: System::Windows::Forms::Label^ lblSecure;





	protected:




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
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->lblCopyright = (gcnew System::Windows::Forms::Label());
			this->lblSecure = (gcnew System::Windows::Forms::Label());
			this->btnEnter = (gcnew System::Windows::Forms::Button());
			this->cardRental = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblFleetDesc3 = (gcnew System::Windows::Forms::Label());
			this->lblFleetTitle3 = (gcnew System::Windows::Forms::Label());
			this->cardCustomer = (gcnew System::Windows::Forms::Panel());
			this->lblFleetDesc2 = (gcnew System::Windows::Forms::Label());
			this->lblFleetTitle2 = (gcnew System::Windows::Forms::Label());
			this->cardFleet = (gcnew System::Windows::Forms::Panel());
			this->lblFleetDesc = (gcnew System::Windows::Forms::Label());
			this->lblFleetTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->mainPanel->SuspendLayout();
			this->cardRental->SuspendLayout();
			this->cardCustomer->SuspendLayout();
			this->cardFleet->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainPanel
			// 
			this->mainPanel->BackColor = System::Drawing::Color::White;
			this->mainPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mainPanel->Controls->Add(this->lblCopyright);
			this->mainPanel->Controls->Add(this->lblSecure);
			this->mainPanel->Controls->Add(this->btnEnter);
			this->mainPanel->Controls->Add(this->cardRental);
			this->mainPanel->Controls->Add(this->cardCustomer);
			this->mainPanel->Controls->Add(this->cardFleet);
			this->mainPanel->Controls->Add(this->lblSubtitle);
			this->mainPanel->Controls->Add(this->lblTitle);
			this->mainPanel->Location = System::Drawing::Point(387, 248);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(1173, 600);
			this->mainPanel->TabIndex = 0;
			// 
			// lblCopyright
			// 
			this->lblCopyright->AutoSize = true;
			this->lblCopyright->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCopyright->ForeColor = System::Drawing::Color::Gray;
			this->lblCopyright->Location = System::Drawing::Point(819, 570);
			this->lblCopyright->Name = L"lblCopyright";
			this->lblCopyright->Size = System::Drawing::Size(349, 25);
			this->lblCopyright->TabIndex = 7;
			this->lblCopyright->Text = L"2026 Car Rental System. All rights reserved";
			// 
			// lblSecure
			// 
			this->lblSecure->AutoSize = true;
			this->lblSecure->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSecure->ForeColor = System::Drawing::Color::Gray;
			this->lblSecure->Location = System::Drawing::Point(3, 570);
			this->lblSecure->Name = L"lblSecure";
			this->lblSecure->Size = System::Drawing::Size(195, 28);
			this->lblSecure->TabIndex = 6;
			this->lblSecure->Text = L"Secure Admin Access";
			// 
			// btnEnter
			// 
			this->btnEnter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btnEnter->FlatAppearance->BorderSize = 0;
			this->btnEnter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEnter->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEnter->ForeColor = System::Drawing::Color::White;
			this->btnEnter->Location = System::Drawing::Point(410, 407);
			this->btnEnter->Name = L"btnEnter";
			this->btnEnter->Size = System::Drawing::Size(321, 65);
			this->btnEnter->TabIndex = 5;
			this->btnEnter->Text = L"Enter Dashboard";
			this->btnEnter->UseVisualStyleBackColor = false;
			this->btnEnter->Click += gcnew System::EventHandler(this, &SplashForm::btnEnter_Click);
			// 
			// cardRental
			// 
			this->cardRental->BackColor = System::Drawing::Color::WhiteSmoke;
			this->cardRental->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cardRental->Controls->Add(this->label1);
			this->cardRental->Controls->Add(this->lblFleetDesc3);
			this->cardRental->Controls->Add(this->lblFleetTitle3);
			this->cardRental->Location = System::Drawing::Point(808, 170);
			this->cardRental->Name = L"cardRental";
			this->cardRental->Size = System::Drawing::Size(290, 130);
			this->cardRental->TabIndex = 4;
			this->cardRental->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SplashForm::cardRental_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->label1->Location = System::Drawing::Point(56, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 20);
			this->label1->TabIndex = 2;
			// 
			// lblFleetDesc3
			// 
			this->lblFleetDesc3->AutoSize = true;
			this->lblFleetDesc3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->lblFleetDesc3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFleetDesc3->ForeColor = System::Drawing::Color::Gray;
			this->lblFleetDesc3->Location = System::Drawing::Point(55, 75);
			this->lblFleetDesc3->Name = L"lblFleetDesc3";
			this->lblFleetDesc3->Size = System::Drawing::Size(194, 25);
			this->lblFleetDesc3->TabIndex = 1;
			this->lblFleetDesc3->Text = L"Process rentals & returns";
			this->lblFleetDesc3->Click += gcnew System::EventHandler(this, &SplashForm::lblFleetDesc3_Click);
			// 
			// lblFleetTitle3
			// 
			this->lblFleetTitle3->AutoSize = true;
			this->lblFleetTitle3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFleetTitle3->Location = System::Drawing::Point(41, 32);
			this->lblFleetTitle3->Name = L"lblFleetTitle3";
			this->lblFleetTitle3->Size = System::Drawing::Size(219, 32);
			this->lblFleetTitle3->TabIndex = 0;
			this->lblFleetTitle3->Text = L"Rental Operations";
			this->lblFleetTitle3->Click += gcnew System::EventHandler(this, &SplashForm::lblFleetTitle3_Click);
			// 
			// cardCustomer
			// 
			this->cardCustomer->BackColor = System::Drawing::Color::WhiteSmoke;
			this->cardCustomer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cardCustomer->Controls->Add(this->lblFleetDesc2);
			this->cardCustomer->Controls->Add(this->lblFleetTitle2);
			this->cardCustomer->Location = System::Drawing::Point(432, 170);
			this->cardCustomer->Name = L"cardCustomer";
			this->cardCustomer->Size = System::Drawing::Size(290, 130);
			this->cardCustomer->TabIndex = 3;
			// 
			// lblFleetDesc2
			// 
			this->lblFleetDesc2->AutoSize = true;
			this->lblFleetDesc2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFleetDesc2->ForeColor = System::Drawing::Color::Gray;
			this->lblFleetDesc2->Location = System::Drawing::Point(30, 75);
			this->lblFleetDesc2->Name = L"lblFleetDesc2";
			this->lblFleetDesc2->Size = System::Drawing::Size(228, 25);
			this->lblFleetDesc2->TabIndex = 1;
			this->lblFleetDesc2->Text = L"Track customer information";
			// 
			// lblFleetTitle2
			// 
			this->lblFleetTitle2->AutoSize = true;
			this->lblFleetTitle2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFleetTitle2->Location = System::Drawing::Point(1, 32);
			this->lblFleetTitle2->Name = L"lblFleetTitle2";
			this->lblFleetTitle2->Size = System::Drawing::Size(282, 32);
			this->lblFleetTitle2->TabIndex = 0;
			this->lblFleetTitle2->Text = L"Customer Management";
			// 
			// cardFleet
			// 
			this->cardFleet->BackColor = System::Drawing::Color::WhiteSmoke;
			this->cardFleet->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cardFleet->Controls->Add(this->lblFleetDesc);
			this->cardFleet->Controls->Add(this->lblFleetTitle);
			this->cardFleet->Location = System::Drawing::Point(58, 170);
			this->cardFleet->Name = L"cardFleet";
			this->cardFleet->Size = System::Drawing::Size(290, 130);
			this->cardFleet->TabIndex = 2;
			// 
			// lblFleetDesc
			// 
			this->lblFleetDesc->AutoSize = true;
			this->lblFleetDesc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFleetDesc->ForeColor = System::Drawing::Color::Gray;
			this->lblFleetDesc->Location = System::Drawing::Point(11, 75);
			this->lblFleetDesc->Name = L"lblFleetDesc";
			this->lblFleetDesc->Size = System::Drawing::Size(254, 25);
			this->lblFleetDesc->TabIndex = 1;
			this->lblFleetDesc->Text = L"Manage your vehicle inventory";
			// 
			// lblFleetTitle
			// 
			this->lblFleetTitle->AutoSize = true;
			this->lblFleetTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFleetTitle->Location = System::Drawing::Point(30, 32);
			this->lblFleetTitle->Name = L"lblFleetTitle";
			this->lblFleetTitle->Size = System::Drawing::Size(226, 32);
			this->lblFleetTitle->TabIndex = 0;
			this->lblFleetTitle->Text = L"Fleet Management";
			this->lblFleetTitle->Click += gcnew System::EventHandler(this, &SplashForm::lblFleetTitle_Click);
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->BackColor = System::Drawing::Color::White;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSubtitle->ForeColor = System::Drawing::Color::Gray;
			this->lblSubtitle->Location = System::Drawing::Point(393, 83);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(398, 38);
			this->lblSubtitle->TabIndex = 1;
			this->lblSubtitle->Text = L"Professional Admin Dashboard";
			this->lblSubtitle->Click += gcnew System::EventHandler(this, &SplashForm::label1_Click);
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->lblTitle->Location = System::Drawing::Point(345, 0);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(505, 74);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"Car Rental System";
			this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SplashForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->ClientSize = System::Drawing::Size(1898, 1024);
			this->Controls->Add(this->mainPanel);
			this->Name = L"SplashForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SplashForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->mainPanel->ResumeLayout(false);
			this->mainPanel->PerformLayout();
			this->cardRental->ResumeLayout(false);
			this->cardRental->PerformLayout();
			this->cardCustomer->ResumeLayout(false);
			this->cardCustomer->PerformLayout();
			this->cardFleet->ResumeLayout(false);
			this->cardFleet->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblFleetTitle_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cardRental_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblFleetDesc3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblFleetTitle3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnEnter_Click(System::Object^ sender, System::EventArgs^ e);

};
}
