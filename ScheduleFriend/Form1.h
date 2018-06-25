#pragma once


namespace ScheduleFriend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	bool username_entered= false;
	bool password_entered= false;
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  butLogin;
	protected: 

	private: System::Windows::Forms::LinkLabel^  lnkSignUp;
	private: System::Windows::Forms::TextBox^  txtPassword;
	protected: 


	private: System::Windows::Forms::TextBox^  txtUsername;

	private: System::Windows::Forms::CheckBox^  chkRememberUser;

	private: System::Windows::Forms::Label^  labUsername;
	private: System::Windows::Forms::Label^  labPassword;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->butLogin = (gcnew System::Windows::Forms::Button());
			this->lnkSignUp = (gcnew System::Windows::Forms::LinkLabel());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->chkRememberUser = (gcnew System::Windows::Forms::CheckBox());
			this->labUsername = (gcnew System::Windows::Forms::Label());
			this->labPassword = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// butLogin
			// 
			this->butLogin->Location = System::Drawing::Point(169, 73);
			this->butLogin->Name = L"butLogin";
			this->butLogin->Size = System::Drawing::Size(75, 23);
			this->butLogin->TabIndex = 3;
			this->butLogin->Text = L"Login";
			this->butLogin->UseVisualStyleBackColor = true;
			this->butLogin->Click += gcnew System::EventHandler(this, &Form1::butLogin_Click);
			// 
			// lnkSignUp
			// 
			this->lnkSignUp->AutoSize = true;
			this->lnkSignUp->Location = System::Drawing::Point(114, 78);
			this->lnkSignUp->Name = L"lnkSignUp";
			this->lnkSignUp->Size = System::Drawing::Size(45, 13);
			this->lnkSignUp->TabIndex = 4;
			this->lnkSignUp->TabStop = true;
			this->lnkSignUp->Text = L"Sign Up";
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(130, 50);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(114, 20);
			this->txtPassword->TabIndex = 2;
			this->txtPassword->TextChanged += gcnew System::EventHandler(this, &Form1::txtPassword_TextChanged);
			// 
			// txtUsername
			// 
			this->txtUsername->Location = System::Drawing::Point(9, 50);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(100, 20);
			this->txtUsername->TabIndex = 1;
			this->txtUsername->TextChanged += gcnew System::EventHandler(this, &Form1::txtUsername_TextChanged);
			// 
			// chkRememberUser
			// 
			this->chkRememberUser->AutoSize = true;
			this->chkRememberUser->Location = System::Drawing::Point(6, 77);
			this->chkRememberUser->Name = L"chkRememberUser";
			this->chkRememberUser->Size = System::Drawing::Size(102, 17);
			this->chkRememberUser->TabIndex = 0;
			this->chkRememberUser->TabStop = false;
			this->chkRememberUser->Text = L"Remember User";
			this->chkRememberUser->UseVisualStyleBackColor = true;
			// 
			// labUsername
			// 
			this->labUsername->AutoSize = true;
			this->labUsername->Location = System::Drawing::Point(6, 34);
			this->labUsername->Name = L"labUsername";
			this->labUsername->Size = System::Drawing::Size(55, 13);
			this->labUsername->TabIndex = 0;
			this->labUsername->Text = L"Username";
			// 
			// labPassword
			// 
			this->labPassword->AutoSize = true;
			this->labPassword->Location = System::Drawing::Point(127, 34);
			this->labPassword->Name = L"labPassword";
			this->labPassword->Size = System::Drawing::Size(53, 13);
			this->labPassword->TabIndex = 0;
			this->labPassword->Text = L"Password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"AR DESTINE", 15, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(169, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 48);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Power\r\nSchedule";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->labUsername);
			this->groupBox1->Controls->Add(this->txtUsername);
			this->groupBox1->Controls->Add(this->butLogin);
			this->groupBox1->Controls->Add(this->lnkSignUp);
			this->groupBox1->Controls->Add(this->chkRememberUser);
			this->groupBox1->Controls->Add(this->labPassword);
			this->groupBox1->Controls->Add(this->txtPassword);
			this->groupBox1->Location = System::Drawing::Point(12, 150);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(260, 100);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Login to Begin";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(13, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(150, 131);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label3);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void txtUsername_TextChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 username_entered = true;
			 if(username_entered == true && password_entered == true)
			 {
				 butLogin->Enabled = true;
			 }
		 }
private: System::Void txtPassword_TextChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 password_entered = true;
			 if(username_entered == true && password_entered == true)
			 {
				 butLogin->Enabled = true;
			 }
		 }
// Login using Username and Password check
private: System::Void butLogin_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //if("hi" == txtUsername-> Text && "pie" == txtPassword->Text)
			 //{
				 this->Hide();
				 HomePage ^ Form = gcnew HomePage();
				 Form->ShowDialog();
				 this->Close();
			 //}
			 //else
			 //{
			//	 txtUsername->Text = "";
				 txtPassword->Text = "";
			//}
		 }
};
}

