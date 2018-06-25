#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ScheduleFriend {

	static int CheckNumber= 0;

	/// <summary>
	/// Summary for HomePage
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class HomePage : public System::Windows::Forms::Form
	{
	public:
		HomePage(void)
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
		~HomePage()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  check2;








	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  check3;
	private: System::Windows::Forms::CheckBox^  check4;





	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label7;


	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::CheckBox^  check1;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->check2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->check1 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->check3 = (gcnew System::Windows::Forms::CheckBox());
			this->check4 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(5, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(317, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Step 1: Update the Course Catalog";
			// 
			// check2
			// 
			this->check2->AutoSize = true;
			this->check2->Location = System::Drawing::Point(379, 50);
			this->check2->Name = L"check2";
			this->check2->Size = System::Drawing::Size(15, 14);
			this->check2->TabIndex = 9;
			this->check2->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->check1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->check3);
			this->groupBox1->Controls->Add(this->check2);
			this->groupBox1->Controls->Add(this->check4);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 51);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(605, 196);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(455, 95);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 26;
			this->button5->Text = L"Enjoyed";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &HomePage::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(455, 20);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 25;
			this->button4->Text = L"Start";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// check1
			// 
			this->check1->AutoSize = true;
			this->check1->Location = System::Drawing::Point(379, 25);
			this->check1->Name = L"check1";
			this->check1->Size = System::Drawing::Size(15, 14);
			this->check1->TabIndex = 24;
			this->check1->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(6, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(230, 25);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Step 0: Start A New Year";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(455, 70);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 22;
			this->button3->Text = L"Update";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &HomePage::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(455, 45);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Update";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &HomePage::button2_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(5, 66);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(368, 25);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Step 2: Select Students\' Course Choices";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(5, 91);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(299, 25);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Step 3: Enjoy Life Until Next Year";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(439, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Calculate Schedules";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &HomePage::button1_Click);
			// 
			// check3
			// 
			this->check3->AutoSize = true;
			this->check3->Location = System::Drawing::Point(379, 75);
			this->check3->Name = L"check3";
			this->check3->Size = System::Drawing::Size(15, 14);
			this->check3->TabIndex = 14;
			this->check3->UseVisualStyleBackColor = true;
			// 
			// check4
			// 
			this->check4->AutoSize = true;
			this->check4->Location = System::Drawing::Point(379, 100);
			this->check4->Name = L"check4";
			this->check4->Size = System::Drawing::Size(15, 14);
			this->check4->TabIndex = 12;
			this->check4->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(244, 39);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Welcome Back";
			// 
			// HomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(630, 262);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"HomePage";
			this->Text = L"HomePage";
			this->Load += gcnew System::EventHandler(this, &HomePage::HomePage_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->Hide();
			 CalculateSchedules ^ Form = gcnew CalculateSchedules(this);
			 Form->ShowDialog();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->Hide();
			 StudentClassPage ^ Form = gcnew StudentClassPage(this);
			 Form->ShowDialog();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->Hide();
			 AddClass ^ Form = gcnew AddClass(this);
			 Form->ShowDialog();
		 }
private: System::Void HomePage_Load(System::Object^  sender, System::EventArgs^  e)
		 {
			 SavingStuff SS;
			 SS.loadCheckPoint(CheckNumber);

			 if(CheckNumber > 0)
				 check1->Checked= true;
			 if(CheckNumber > 1)
				 check2->Checked= true;
			 if(CheckNumber > 2)
				 check3->Checked= true;
			 if(CheckNumber == 3)
				 check4->Checked= true;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 if(CheckNumber == 2)
			 {
				 CheckNumber= 3;
				 SavingStuff SS;
				 SS.saveCheckPoint(CheckNumber);
			 }
		 }

};
}
