#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ScheduleFriend {

	// Vectors
	static vector<string> Course_List;
	static vector<vector<string>> Class_List;
	static vector<vector<string>> E_List;
	static vector<string> Teacher_List;
	static vector<vector<string>> StudentE_List;
	static vector<vector<string>> StudentC_List;
	static vector<int> Grade_Sizes;
	static vector<vector<string>> StudentGrade_List;
	static vector<string> CourseChoice_List;
	static vector<string> SelectedClasses;
	// Vector Variable Sizes
	static int total_Courses= 0;
	static int total_Classes= 0;
	static int total_Electives= 0;
	static int total_Students= 0;
	static int total_Teachers= 0;
	// Variables for Adding a Student
	static string studentFirst= "";
	static string studentLast= "";
	static string gradeString= "";
	static int gradeLevel= 0;
	static int SelectedCredits =0;
	// Variables for Loading a Student
	static string studentName= "";
	static bool button1 = false;
	static bool button2 = false;
	static bool button3 = false;
	static bool button4 = false;
	static bool Loading = false;
	static int CCheckNum= 0;

	/// <summary>
	/// Summary for StudentClassPage
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class StudentClassPage : public System::Windows::Forms::Form
	{
	public:
		StudentClassPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Button^  butContinue;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	public: 
	private: System::Windows::Forms::Form ^ home;
	public:
		StudentClassPage(System::Windows::Forms::Form ^ form)
		{
			home = form;
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentClassPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txtFirstName;
	private: System::Windows::Forms::TextBox^  txtLastName;
	private: System::Windows::Forms::ComboBox^  cmbNewGradeLevel;

	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ComboBox^  cmbLoadGradeLevel;
	private: System::Windows::Forms::ComboBox^  cmbLoadStudentName;


	private: System::Windows::Forms::Button^  butLoadStudent;
	private: System::Windows::Forms::CheckedListBox^  chkCourses;

	private: System::Windows::Forms::ListBox^  listCourses;
	private: System::Windows::Forms::Button^  butSaveFile;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
			this->txtLastName = (gcnew System::Windows::Forms::TextBox());
			this->cmbNewGradeLevel = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cmbLoadGradeLevel = (gcnew System::Windows::Forms::ComboBox());
			this->cmbLoadStudentName = (gcnew System::Windows::Forms::ComboBox());
			this->butLoadStudent = (gcnew System::Windows::Forms::Button());
			this->chkCourses = (gcnew System::Windows::Forms::CheckedListBox());
			this->listCourses = (gcnew System::Windows::Forms::ListBox());
			this->butSaveFile = (gcnew System::Windows::Forms::Button());
			this->butContinue = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(214, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Create New Student File";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(339, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(215, 24);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Load Saved Student File";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 33);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(57, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"First Name";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(140, 33);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Last Name";
			// 
			// txtFirstName
			// 
			this->txtFirstName->Location = System::Drawing::Point(16, 50);
			this->txtFirstName->Name = L"txtFirstName";
			this->txtFirstName->Size = System::Drawing::Size(121, 20);
			this->txtFirstName->TabIndex = 9;
			this->txtFirstName->TextChanged += gcnew System::EventHandler(this, &StudentClassPage::txtFirstName_TextChanged);
			// 
			// txtLastName
			// 
			this->txtLastName->Location = System::Drawing::Point(143, 50);
			this->txtLastName->Name = L"txtLastName";
			this->txtLastName->Size = System::Drawing::Size(121, 20);
			this->txtLastName->TabIndex = 10;
			this->txtLastName->TextChanged += gcnew System::EventHandler(this, &StudentClassPage::txtLastName_TextChanged);
			// 
			// cmbNewGradeLevel
			// 
			this->cmbNewGradeLevel->FormattingEnabled = true;
			this->cmbNewGradeLevel->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Freshman", L"Sophomore", L"Junior", L"Senior"});
			this->cmbNewGradeLevel->Location = System::Drawing::Point(16, 88);
			this->cmbNewGradeLevel->Name = L"cmbNewGradeLevel";
			this->cmbNewGradeLevel->Size = System::Drawing::Size(80, 21);
			this->cmbNewGradeLevel->TabIndex = 11;
			this->cmbNewGradeLevel->SelectedIndexChanged += gcnew System::EventHandler(this, &StudentClassPage::cmbNewGradeLevel_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Grade Level";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(340, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Grade Level";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(466, 49);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(75, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Student Name";
			// 
			// cmbLoadGradeLevel
			// 
			this->cmbLoadGradeLevel->FormattingEnabled = true;
			this->cmbLoadGradeLevel->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Freshman", L"Sophomore", L"Junior", L"Senior"});
			this->cmbLoadGradeLevel->Location = System::Drawing::Point(343, 65);
			this->cmbLoadGradeLevel->Name = L"cmbLoadGradeLevel";
			this->cmbLoadGradeLevel->Size = System::Drawing::Size(103, 21);
			this->cmbLoadGradeLevel->TabIndex = 19;
			this->cmbLoadGradeLevel->SelectedIndexChanged += gcnew System::EventHandler(this, &StudentClassPage::cmbLoadGradeLevel_SelectedIndexChanged);
			// 
			// cmbLoadStudentName
			// 
			this->cmbLoadStudentName->FormattingEnabled = true;
			this->cmbLoadStudentName->Location = System::Drawing::Point(469, 65);
			this->cmbLoadStudentName->Name = L"cmbLoadStudentName";
			this->cmbLoadStudentName->Size = System::Drawing::Size(121, 21);
			this->cmbLoadStudentName->TabIndex = 20;
			// 
			// butLoadStudent
			// 
			this->butLoadStudent->Location = System::Drawing::Point(606, 63);
			this->butLoadStudent->Name = L"butLoadStudent";
			this->butLoadStudent->Size = System::Drawing::Size(75, 23);
			this->butLoadStudent->TabIndex = 21;
			this->butLoadStudent->Text = L"Load File";
			this->butLoadStudent->UseVisualStyleBackColor = true;
			this->butLoadStudent->Click += gcnew System::EventHandler(this, &StudentClassPage::butLoadStudent_Click);
			// 
			// chkCourses
			// 
			this->chkCourses->CheckOnClick = true;
			this->chkCourses->FormattingEnabled = true;
			this->chkCourses->Location = System::Drawing::Point(16, 116);
			this->chkCourses->Name = L"chkCourses";
			this->chkCourses->Size = System::Drawing::Size(361, 394);
			this->chkCourses->TabIndex = 22;
			this->chkCourses->SelectedIndexChanged += gcnew System::EventHandler(this, &StudentClassPage::chkCourses_SelectedIndexChanged);
			// 
			// listCourses
			// 
			this->listCourses->FormattingEnabled = true;
			this->listCourses->Location = System::Drawing::Point(383, 116);
			this->listCourses->Name = L"listCourses";
			this->listCourses->Size = System::Drawing::Size(415, 186);
			this->listCourses->TabIndex = 23;
			// 
			// butSaveFile
			// 
			this->butSaveFile->Enabled = false;
			this->butSaveFile->Location = System::Drawing::Point(667, 366);
			this->butSaveFile->Name = L"butSaveFile";
			this->butSaveFile->Size = System::Drawing::Size(130, 23);
			this->butSaveFile->TabIndex = 24;
			this->butSaveFile->Text = L"Save Student Data";
			this->butSaveFile->UseVisualStyleBackColor = true;
			this->butSaveFile->Click += gcnew System::EventHandler(this, &StudentClassPage::butSaveFile_Click);
			// 
			// butContinue
			// 
			this->butContinue->Location = System::Drawing::Point(690, 487);
			this->butContinue->Name = L"butContinue";
			this->butContinue->Size = System::Drawing::Size(107, 23);
			this->butContinue->TabIndex = 25;
			this->butContinue->Text = L"Continue";
			this->butContinue->UseVisualStyleBackColor = true;
			this->butContinue->Click += gcnew System::EventHandler(this, &StudentClassPage::butContinue_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(531, 314);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 17);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Caution:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(531, 331);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(266, 26);
			this->label9->TabIndex = 27;
			this->label9->Text = L"Saving student data with more that 48 credits selected \r\nwill cause the program t" 
				L"o crash unexpectedly";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(383, 314);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(56, 17);
			this->label10->TabIndex = 28;
			this->label10->Text = L"Credits:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(445, 316);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(13, 13);
			this->label11->TabIndex = 29;
			this->label11->Text = L"0";
			// 
			// StudentClassPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(810, 523);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->butContinue);
			this->Controls->Add(this->butSaveFile);
			this->Controls->Add(this->listCourses);
			this->Controls->Add(this->chkCourses);
			this->Controls->Add(this->butLoadStudent);
			this->Controls->Add(this->cmbLoadStudentName);
			this->Controls->Add(this->cmbLoadGradeLevel);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cmbNewGradeLevel);
			this->Controls->Add(this->txtLastName);
			this->Controls->Add(this->txtFirstName);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Name = L"StudentClassPage";
			this->Text = L"StudentClassPage";
			this->Load += gcnew System::EventHandler(this, &StudentClassPage::StudentClassPage_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void StudentClassPage_Load(System::Object^  sender, System::EventArgs^  e)
		 {
			 SavingStuff SS;
			 SS.loadSizes(total_Classes, total_Electives, total_Students, total_Courses, total_Teachers);
			 SS.loadCourseList(total_Courses, Course_List);
			 SS.loadClassList(total_Classes, Class_List);
			 SS.loadElist(total_Electives, E_List);
			 SS.loadStudentList(total_Students, StudentC_List);
			 SS.loadStudentEList(total_Students, StudentE_List);
			 SS.loadGradeSizes(Grade_Sizes);
			 SS.loadStudentGradeList(Grade_Sizes, StudentGrade_List);
			 SS.loadCheckPoint(CCheckNum);

			 // Add Courses to chkCourses on Load
			 for(int counter= 0; counter < total_Courses; counter++)
			 {
				 String ^ UpdateList = gcnew String(Course_List[counter].c_str());
				 chkCourses->Items->Add(UpdateList);
			 }
		 }
private: System::Void chkCourses_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 listCourses->Items->Clear();
			 for(int counter= 0; counter < chkCourses->CheckedItems->Count; counter++)
			 {
				 listCourses->Items->Add(chkCourses->CheckedItems[counter]);
			 }
			 msclr::interop::marshal_context context;
			 SelectedClasses.resize(0);
			 for(int counter= 0; counter < listCourses->Items->Count; counter++)
			 {
				 String ^ CourseChosen= listCourses->Items[counter]->ToString();
				 SelectedClasses.push_back(context.marshal_as<std::string>(CourseChosen));
			 }
			 // Finding Number of Credits the Course Is
			 int totalCreds = 0;
			 for(int findCreds=0;findCreds<SelectedClasses.size();findCreds++)
			 {
				string NAME= SelectedClasses[findCreds];
				int numCreds;
				for (int spaceLocator = 0; spaceLocator < NAME.size(); spaceLocator++)
				{
				if (NAME[spaceLocator] == 'C' && NAME[spaceLocator+ 1] == 'r' && NAME[spaceLocator+ 2] == 'e'
					&& NAME[spaceLocator+ 3] == 'd' && NAME[spaceLocator+ 4] == 's')
					{
						numCreds= NAME[spaceLocator -2]- '0';
						if(numCreds == 2)
							numCreds = 12;
						totalCreds = totalCreds + numCreds;
					}
				}
			 }
			 ConvertStuff CV;
			 string tCreds = CV.StdIntToStdString(totalCreds);
			 String ^ tCred = gcnew String(tCreds.c_str());
			 label11->Text = tCred;
			 button4 = true;
			 if (button1 == true && button2 == true && button3 == true && button4 == true)
				 butSaveFile->Enabled=true;
		
		 }
private: System::Void butSaveFile_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 if(Loading == false)
			 {
				 button1 = false;
				 button2 = false;
				 button4 = false;
				 ConvertStuff CV;
		
				 msclr::interop::marshal_context context;
				 // Getting Variables from Windows Form
				 String ^ FirstName= txtFirstName->Text;
				 String ^ LastName= txtLastName->Text;
				 Int32 GRADE= System::Convert::ToInt32(cmbNewGradeLevel->SelectedIndex);
				 String ^ GRADE2= System::Convert::ToString(GRADE);
				 // Converting Variables to std Variables
				 studentFirst= context.marshal_as<std::string>(FirstName);
				 studentLast= context.marshal_as<std::string>(LastName);
				 gradeString= context.marshal_as<std::string>(GRADE2);
				 gradeLevel= CV.StdStringToStdInt(gradeString);
				 // Get choices of students
				 String ^ CourseChoosing;
				 CourseChoice_List.resize(0);
				 for(int counter= 0; counter < listCourses->Items->Count; counter++)
				 {
					 CourseChoosing= listCourses->Items[counter]->ToString();
					 CourseChoice_List.push_back(context.marshal_as<std::string>(CourseChoosing));
				 }
				 // Sending Variables to BehindTheScenes.cpp
				 BehindTheScenes BS;
				 BS.AddStudent(studentFirst, studentLast, gradeLevel, Class_List, E_List, StudentC_List, StudentE_List, StudentGrade_List, Grade_Sizes, CourseChoice_List, total_Students);
			 }
			 else
			 {
				 ConvertStuff CV;
				 msclr::interop::marshal_context context;
				 // Getting Variables from Windows Form
				 String ^ StudentName= cmbLoadStudentName->Text;
				 Int32 GRADE= System::Convert::ToInt32(cmbLoadGradeLevel->SelectedIndex);
				 String ^ GRADE2= System::Convert::ToString(GRADE);
				 // Converting Variables to std Variables
				 studentName= context.marshal_as<std::string>(StudentName);
				 gradeString= context.marshal_as<std::string>(GRADE2);
				 gradeLevel= CV.StdStringToStdInt(gradeString);

				 int savedDash= 0;
				 int numTimes= 0;
				 bool firstTime= true;
				 for(int nameLocator = 0; nameLocator < studentName.size(); nameLocator++)
				 {
					 numTimes++;
					 if(studentName[nameLocator] == ' ')
					 {
						studentFirst.assign(studentName, savedDash, numTimes - 1);
						savedDash = nameLocator +1;
						numTimes = studentName.size() - (numTimes - 1);
						studentLast.assign(studentName, savedDash, numTimes - 1);
					 }
				 }
				 // Get choices of students
				 String ^ CourseChoosing;
				 CourseChoice_List.resize(0);
				 for(int counter= 0; counter < listCourses->Items->Count; counter++)
				 {
					 CourseChoosing= listCourses->Items[counter]->ToString();
					 CourseChoice_List.push_back(context.marshal_as<std::string>(CourseChoosing));
				 }
				 // Sending Variables to BehindTheScenes.cpp
				 BehindTheScenes BS;
				 BS.DeleteStudent(studentFirst, studentLast, gradeLevel, StudentC_List, StudentE_List, StudentGrade_List, Grade_Sizes, total_Students);
				 BS.AddStudent(studentFirst, studentLast, gradeLevel, Class_List, E_List, StudentC_List, StudentE_List, StudentGrade_List, Grade_Sizes, CourseChoice_List, total_Students);

				 cmbLoadStudentName->SelectedIndex= -1;
				 listCourses->Items->Clear();

				 txtFirstName->Enabled= true;
				 txtLastName->Enabled= true;
				 cmbNewGradeLevel->Enabled= true;
				 cmbLoadGradeLevel->Enabled = true;
				 cmbLoadStudentName->Enabled = true;
				 Loading = false;
			 }

			 CourseChoice_List.resize(0);
			 // Save Data
			 SavingStuff SS;
			 SS.saveSizes(total_Classes, total_Electives, total_Students, total_Courses, total_Teachers);
			 SS.saveStudentList(total_Students, StudentC_List);
			 SS.saveStudentEList(total_Students, StudentE_List);
			 SS.saveGradeSizes(Grade_Sizes);
			 SS.saveStudentGradeList(Grade_Sizes, StudentGrade_List);
			 txtFirstName->Text = "";
			 txtLastName->Text = "";
			 for (int i = 0; i < chkCourses->Items->Count; ++i)
			 {
				 chkCourses->SetItemChecked(i, false);
			 }
			 listCourses->Items->Clear();
			 butSaveFile->Enabled=false;
			 label11->Text = "0";
		 }
private: System::Void butContinue_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 CCheckNum= 3;
			 SavingStuff SS;
			 SS.saveCheckPoint(CCheckNum);

			 home->Show();
			 this->Hide();
			 this->Close();
		 }
private: System::Void cmbLoadGradeLevel_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 gradeLevel= cmbLoadGradeLevel->SelectedIndex;

			 cmbLoadStudentName->Items->Clear();
			 for(int counter=0; counter < Grade_Sizes[gradeLevel]; counter++)
			 {
		 		 String ^ UpdateList = gcnew String(StudentGrade_List[gradeLevel][counter].c_str());
				 cmbLoadStudentName->Items->Add(UpdateList);
			 }
		 }
private: System::Void txtFirstName_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 button1 = true;
			 if (button1 == true && button2 == true && button3 == true && button4 == true)
				 butSaveFile->Enabled=true;
		 }
private: System::Void txtLastName_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 button2 = true;
			 if (button1 == true && button2 == true && button3 == true && button4 == true)
				 butSaveFile->Enabled=true;
		 }
private: System::Void butLoadStudent_Click(System::Object^  sender, System::EventArgs^  e)
	 {
		 ConvertStuff CV;
		 msclr::interop::marshal_context context;
		 // Getting Variables from Windows Form
		 String ^ StudentName= cmbLoadStudentName->Text;
		 // Converting Variables to std Variables
		 studentName= context.marshal_as<std::string>(StudentName);

		 BehindTheScenes BS;
		 BS.LoadStudent(studentName, Class_List, E_List, Course_List, StudentC_List, StudentE_List, CourseChoice_List, total_Students);

		 for(int counter2= 0; counter2 < CourseChoice_List.size(); counter2++)
		 {
			 for(int counter = 0; counter < chkCourses->Items->Count; counter++ )
			 {
				 String ^ CheckCourses = chkCourses->Items[counter]->ToString();
				 string CHECK= context.marshal_as<std::string>(CheckCourses);
				 if(CHECK == CourseChoice_List[counter2])
				 {
					 chkCourses->SetItemChecked(counter, true);
				 }
			 }
		 }

		 listCourses->Items->Clear();
		 for(int counter= 0; counter < chkCourses->CheckedItems->Count; counter++)
		 {
			 listCourses->Items->Add(chkCourses->CheckedItems[counter]);
		 }

		 // Finding Number of Credits the Course Is
		 SelectedClasses.resize(0);
		 for(int counter= 0; counter < listCourses->Items->Count; counter++)
		 {
			 String ^ CourseChosen= listCourses->Items[counter]->ToString();
			 SelectedClasses.push_back(context.marshal_as<std::string>(CourseChosen));
		 }

		 int totalCreds = 0;
		 for(int findCreds=0;findCreds<SelectedClasses.size();findCreds++)
		 {
			string NAME= SelectedClasses[findCreds];
			int numCreds;
			for (int spaceLocator = 0; spaceLocator < NAME.size(); spaceLocator++)
			{
			if (NAME[spaceLocator] == 'C' && NAME[spaceLocator+ 1] == 'r' && NAME[spaceLocator+ 2] == 'e'
				&& NAME[spaceLocator+ 3] == 'd' && NAME[spaceLocator+ 4] == 's')
				{
					numCreds= NAME[spaceLocator -2]- '0';
					if(numCreds == 2)
						numCreds = 12;
					totalCreds = totalCreds + numCreds;
				}
			}
		 }
		 string tCreds = CV.StdIntToStdString(totalCreds);
		 String ^ tCred = gcnew String(tCreds.c_str());
		 label11->Text = tCred;

		 txtFirstName->Enabled= false;
		 txtLastName->Enabled= false;
		 cmbNewGradeLevel->Enabled= false;
		 cmbLoadGradeLevel->Enabled = false;
		 cmbLoadStudentName->Enabled = false;
		 butSaveFile->Enabled= true;
		 Loading= true;
	 }
private: System::Void cmbNewGradeLevel_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 button3 = true;
			 if (button1 == true && button2 == true && button3 == true && button4 == true)
				 butSaveFile->Enabled=true;
		 }
};
}
