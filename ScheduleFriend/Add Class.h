#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace std;

namespace ScheduleFriend {

	// Vectors
	static vector<vector<string>> ClassList(7, vector<string>(0));
	static vector<vector<string>> Elist(7, vector<string>(0));
	static vector<string> CourseList(0);
	static vector<string> TeacherList(0);
	// Vector Size Variables
	static int totalClasses= 0;
	static int totalElectives= 0;
	static int totalStudents= 0;
	static int totalCourses= 0;
	static int totalTeachers= 0;
	// Variables to make sure all the data for a class is filled out
	static bool buttonWork1= false;
	static bool buttonWork2= false;
	static bool buttonWork3= false;
	static bool buttonWork4= false;
	static bool buttonWork5= true;
	static bool buttonWork6= false;
	// Variables for adding a class
	static string className= "";
	static string department= "";
	static string credits= "";
	static string semester= "";
	static string teacherName= "";
	static string classSize= "";
	// Variable for removing a class
	static int deletedCourse= 0;
	static int BCheckNum= 0;

	/// <summary>
	/// Summary for AddClass
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AddClass : public System::Windows::Forms::Form
	{
	public:
		AddClass(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Form ^ home;
	public:
		AddClass(System::Windows::Forms::Form ^ form)
		{
			home = form;
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddClass()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  butAdd;
	private: System::Windows::Forms::Button^  butContinue;
	protected: 

	protected: 

	private: System::Windows::Forms::Button^  butRemove;
	private: System::Windows::Forms::TextBox^  txtRemoveClass;


	private: System::Windows::Forms::TextBox^  txtClassName;

	private: System::Windows::Forms::ComboBox^  cmbDepartment;
	private: System::Windows::Forms::ComboBox^  cmbTeacher;


	private: System::Windows::Forms::NumericUpDown^  numCredits;
	private: System::Windows::Forms::NumericUpDown^  numSemester;
	private: System::Windows::Forms::ListBox^  listCourses;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  numClassSize;

	private: System::Windows::Forms::Label^  label9;


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
			this->butAdd = (gcnew System::Windows::Forms::Button());
			this->butContinue = (gcnew System::Windows::Forms::Button());
			this->butRemove = (gcnew System::Windows::Forms::Button());
			this->txtRemoveClass = (gcnew System::Windows::Forms::TextBox());
			this->txtClassName = (gcnew System::Windows::Forms::TextBox());
			this->cmbDepartment = (gcnew System::Windows::Forms::ComboBox());
			this->cmbTeacher = (gcnew System::Windows::Forms::ComboBox());
			this->numCredits = (gcnew System::Windows::Forms::NumericUpDown());
			this->numSemester = (gcnew System::Windows::Forms::NumericUpDown());
			this->listCourses = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->numClassSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numCredits))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numSemester))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numClassSize))->BeginInit();
			this->SuspendLayout();
			// 
			// butAdd
			// 
			this->butAdd->Enabled = false;
			this->butAdd->Location = System::Drawing::Point(346, 98);
			this->butAdd->Name = L"butAdd";
			this->butAdd->Size = System::Drawing::Size(75, 23);
			this->butAdd->TabIndex = 0;
			this->butAdd->Text = L"Add";
			this->butAdd->UseVisualStyleBackColor = true;
			this->butAdd->Click += gcnew System::EventHandler(this, &AddClass::butAdd_Click);
			// 
			// butContinue
			// 
			this->butContinue->Location = System::Drawing::Point(543, 227);
			this->butContinue->Name = L"butContinue";
			this->butContinue->Size = System::Drawing::Size(75, 23);
			this->butContinue->TabIndex = 1;
			this->butContinue->Text = L"Continue";
			this->butContinue->UseVisualStyleBackColor = true;
			this->butContinue->Click += gcnew System::EventHandler(this, &AddClass::butContinue_Click);
			// 
			// butRemove
			// 
			this->butRemove->Enabled = false;
			this->butRemove->Location = System::Drawing::Point(543, 95);
			this->butRemove->Name = L"butRemove";
			this->butRemove->Size = System::Drawing::Size(75, 23);
			this->butRemove->TabIndex = 2;
			this->butRemove->Text = L"Remove";
			this->butRemove->UseVisualStyleBackColor = true;
			this->butRemove->Click += gcnew System::EventHandler(this, &AddClass::butRemove_Click);
			// 
			// txtRemoveClass
			// 
			this->txtRemoveClass->Location = System::Drawing::Point(411, 61);
			this->txtRemoveClass->Name = L"txtRemoveClass";
			this->txtRemoveClass->ReadOnly = true;
			this->txtRemoveClass->Size = System::Drawing::Size(207, 20);
			this->txtRemoveClass->TabIndex = 3;
			// 
			// txtClassName
			// 
			this->txtClassName->Location = System::Drawing::Point(139, 61);
			this->txtClassName->Name = L"txtClassName";
			this->txtClassName->Size = System::Drawing::Size(232, 20);
			this->txtClassName->TabIndex = 4;
			this->txtClassName->TextChanged += gcnew System::EventHandler(this, &AddClass::txtClassName_TextChanged);
			// 
			// cmbDepartment
			// 
			this->cmbDepartment->FormattingEnabled = true;
			this->cmbDepartment->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"English", L"Mathematics", L"Science", L"Social Studies", 
				L"World Languages", L"Electives", L"Special Programs and Opportunities", L"Other/ No Category"});
			this->cmbDepartment->Location = System::Drawing::Point(12, 61);
			this->cmbDepartment->Name = L"cmbDepartment";
			this->cmbDepartment->Size = System::Drawing::Size(121, 21);
			this->cmbDepartment->TabIndex = 5;
			this->cmbDepartment->SelectedIndexChanged += gcnew System::EventHandler(this, &AddClass::cmbDepartment_SelectedIndexChanged);
			// 
			// cmbTeacher
			// 
			this->cmbTeacher->FormattingEnabled = true;
			this->cmbTeacher->Location = System::Drawing::Point(72, 100);
			this->cmbTeacher->Name = L"cmbTeacher";
			this->cmbTeacher->Size = System::Drawing::Size(103, 21);
			this->cmbTeacher->TabIndex = 6;
			this->cmbTeacher->SelectedIndexChanged += gcnew System::EventHandler(this, &AddClass::cmbTeacher_SelectedIndexChanged);
			// 
			// numCredits
			// 
			this->numCredits->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->numCredits->Location = System::Drawing::Point(277, 98);
			this->numCredits->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {12, 0, 0, 0});
			this->numCredits->Name = L"numCredits";
			this->numCredits->Size = System::Drawing::Size(54, 20);
			this->numCredits->TabIndex = 7;
			this->numCredits->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numCredits->ValueChanged += gcnew System::EventHandler(this, &AddClass::numCredits_ValueChanged);
			// 
			// numSemester
			// 
			this->numSemester->Location = System::Drawing::Point(12, 101);
			this->numSemester->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->numSemester->Name = L"numSemester";
			this->numSemester->Size = System::Drawing::Size(54, 20);
			this->numSemester->TabIndex = 8;
			this->numSemester->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// listCourses
			// 
			this->listCourses->FormattingEnabled = true;
			this->listCourses->Location = System::Drawing::Point(12, 127);
			this->listCourses->Name = L"listCourses";
			this->listCourses->Size = System::Drawing::Size(525, 121);
			this->listCourses->TabIndex = 9;
			this->listCourses->SelectedIndexChanged += gcnew System::EventHandler(this, &AddClass::listCourses_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 24);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Add a Class";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(389, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(229, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Are You Sure You Wish To Remove This Class";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(69, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Preferred Teacher";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 85);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Semester";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(277, 85);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Credits";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(134, 45);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Choose Class Name";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 45);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(101, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Choose Department";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(388, 21);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(146, 24);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Remove a Class";
			// 
			// numClassSize
			// 
			this->numClassSize->Location = System::Drawing::Point(181, 101);
			this->numClassSize->Name = L"numClassSize";
			this->numClassSize->Size = System::Drawing::Size(83, 20);
			this->numClassSize->TabIndex = 18;
			this->numClassSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numClassSize->ValueChanged += gcnew System::EventHandler(this, &AddClass::numClassSize_ValueChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(178, 85);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(93, 13);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Optimal Class Size";
			// 
			// AddClass
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(630, 262);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->numClassSize);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listCourses);
			this->Controls->Add(this->numSemester);
			this->Controls->Add(this->numCredits);
			this->Controls->Add(this->cmbTeacher);
			this->Controls->Add(this->cmbDepartment);
			this->Controls->Add(this->txtClassName);
			this->Controls->Add(this->txtRemoveClass);
			this->Controls->Add(this->butRemove);
			this->Controls->Add(this->butContinue);
			this->Controls->Add(this->butAdd);
			this->Name = L"AddClass";
			this->Text = L"AddClass";
			this->Load += gcnew System::EventHandler(this, &AddClass::AddClass_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numCredits))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numSemester))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numClassSize))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// Load Vectors for Functions
private: System::Void AddClass_Load(System::Object^  sender, System::EventArgs^  e)
	{
		 SavingStuff SF;
		 SF.loadSizes(totalClasses, totalElectives, totalStudents, totalCourses, totalTeachers);
		 SF.loadClassList(totalClasses, ClassList);
		 SF.loadElist(totalElectives, Elist);
		 SF.loadCourseList(totalCourses, CourseList);
		 SF.loadTeacherList(totalTeachers, TeacherList);
		 SF.loadCheckPoint(BCheckNum);

		 // Adding Courses to List on Load
		 listCourses->Items->Clear();
		 for(int counter=0; counter < totalCourses; counter++)
		 {
			 String ^ UpdateList = gcnew String(CourseList[counter].c_str());
			 listCourses->Items->Add(UpdateList);
		 }
		 // Adding Teachers to List on Load
		 cmbTeacher->Items->Clear();
		 for(int counter= 0; counter < totalTeachers; counter++)
		 {
			 String ^ UpdateList = gcnew String(TeacherList[counter].c_str());
			 cmbTeacher->Items->Add(UpdateList);
		 }
	}
// Check to make sure items are filled out before creating a course
private: System::Void cmbDepartment_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		buttonWork1= true;
		if(buttonWork1 == true && buttonWork2 == true && buttonWork3 == true && buttonWork4 == true && buttonWork5 == true)
			butAdd->Enabled= true;
	}
private: System::Void txtClassName_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		buttonWork2= true;
		if(buttonWork1 == true && buttonWork2 == true && buttonWork3 == true && buttonWork4 == true && buttonWork5 == true)
			butAdd->Enabled= true;
	}
private: System::Void numCredits_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		buttonWork3= true;
		if(buttonWork1 == true && buttonWork2 == true && buttonWork3 == true && buttonWork4 == true && buttonWork5 == true)
			butAdd->Enabled= true;
	}
private: System::Void cmbTeacher_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		buttonWork4= true;
		if(buttonWork1 == true && buttonWork2 == true && buttonWork3 == true && buttonWork4 == true && buttonWork5 == true)
			butAdd->Enabled= true;
	}
private: System::Void numClassSize_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		buttonWork5= true;
		if(buttonWork1 == true && buttonWork2 == true && buttonWork3 == true && buttonWork4 == true && buttonWork5 == true)
			butAdd->Enabled= true;
	}
// Add Class
private: System::Void butAdd_Click(System::Object^  sender, System::EventArgs^  e)
	{
		msclr::interop::marshal_context context;
		// Getting Variables from Windows Form
		String ^ CourseName= txtClassName->Text;
		String ^ Department= cmbDepartment->Text;
		String ^ Teacher= cmbTeacher->Text;
		Int32 Credits= System::Convert::ToInt32(numCredits->Text);
		Int32 Semester= System::Convert::ToInt32(numSemester->Text);
		Int32 ClassSize= System::Convert::ToInt32(numClassSize->Text);
		String ^ Creds= System::Convert::ToString(Credits);
		String ^ Sem= System::Convert::ToString(Semester);
		String ^ CSize= System::Convert::ToString(ClassSize);
		// Converting Variables to std Variables
		className= context.marshal_as<std::string>(CourseName);
		department= context.marshal_as<std::string>(Department);
		teacherName= context.marshal_as<std::string>(Teacher);
		credits= context.marshal_as<std::string>(Creds);
		semester= context.marshal_as<std::string>(Sem);
		classSize= context.marshal_as<std::string>(CSize);
		// Send Variables to BehindTheScenes.cpp
		BehindTheScenes BS;
		BS.AddCourse(className, department, credits, semester, teacherName, classSize, CourseList, ClassList, Elist, totalCourses, totalClasses, totalElectives);
		// Convert List to CourseList
		listCourses->Items->Clear();
		for(int counter=0; counter < totalCourses; counter++)
		{
			String ^ UpdateList = gcnew String(CourseList[counter].c_str());
			listCourses->Items->Add(UpdateList);
		}

		// Save Data
		SavingStuff SF;
		SF.saveSizes(totalClasses, totalElectives, totalStudents, totalCourses, totalTeachers);
		SF.saveClassList(totalClasses, ClassList);
		SF.saveElist(totalElectives, Elist);
		SF.saveCourseList(totalCourses, CourseList);
		SF.saveTeacherList(totalTeachers, TeacherList);

		// Reset Variables
		String ^ Blank = "";
		txtClassName->Text = Blank;
		butAdd->Enabled= false;
		buttonWork2= false;
	}
private: System::Void listCourses_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		txtRemoveClass->Text = listCourses->Text;
		deletedCourse= listCourses->SelectedIndex;
		butRemove->Enabled= true;
	}
private: System::Void butRemove_Click(System::Object^  sender, System::EventArgs^  e)
	{
		BehindTheScenes BS;
		BS.RemoveCourse(deletedCourse, CourseList, ClassList, Elist, totalCourses, totalClasses, totalElectives);

		// Convert List to CourseList
		listCourses->Items->Clear();
		for(int counter= 0; counter< totalCourses; counter++)
		{
			String ^ UpdateList = gcnew String(CourseList[counter].c_str());
			listCourses->Items->Add(UpdateList);
		}

		// Save Data
		SavingStuff SS;
		SS.saveSizes(totalClasses, totalElectives, totalStudents, totalCourses, totalTeachers);
		SS.saveClassList(totalClasses, ClassList);
		SS.saveElist(totalElectives, Elist);
		SS.saveCourseList(totalCourses, CourseList);
		//SS.saveTeacherList(totalTeachers, TeacherList);
	}
private: System::Void butContinue_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		BCheckNum= 2;
		SavingStuff SS;
		SS.saveCheckPoint(BCheckNum);

		home->Show();
		this->Hide();
		this->Close();
	}
};
}
