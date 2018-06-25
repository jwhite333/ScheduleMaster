#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ScheduleFriend {

	// Vectors
	static vector<string> TeacherVector_List;
	static vector<vector<string>> StudentElect_List;
	static vector<vector<string>> StudentClass_List;
	static vector<int> GradeSizes;
	static vector<vector<string>> StudentGradeList;
	// Vector Variable Sizes
	static int totCourses= 0;
	static int totClasses= 0;
	static int totElectives= 0;
	static int totStudents= 0;
	static int totTeachers= 0;
	// Variables for Stuff
	static string teacherAddName= "";
	static string studentMoveName= "";
	static int teacherDelete= 0;
	static int loadGradeList= 0;
	static int moveStudent= 0;
	static int ACheckNum= 0;

	/// <summary>
	/// Summary for NewYear
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class NewYear : public System::Windows::Forms::Form
	{
	public:
		NewYear(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Label^  label5;
	public: 

	private: System::Windows::Forms::Form ^ home;
	public:
		NewYear(System::Windows::Forms::Form ^ form)
		{
			home = form;
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewYear()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  butAdd;
	private: System::Windows::Forms::TextBox^  txtTeacher;
	protected: 


	private: System::Windows::Forms::ListBox^  listTeachers;

	private: System::Windows::Forms::Button^  butDelete;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RadioButton^  radFreshman;
	private: System::Windows::Forms::RadioButton^  radSophomores;
	private: System::Windows::Forms::RadioButton^  radJuniors;
	private: System::Windows::Forms::RadioButton^  radSeniors;




	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ListBox^  listStudentList;

	private: System::Windows::Forms::Button^  butStayedBack;


	private: System::Windows::Forms::Button^  butTransferred;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  butContinue;

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
			this->butAdd = (gcnew System::Windows::Forms::Button());
			this->txtTeacher = (gcnew System::Windows::Forms::TextBox());
			this->listTeachers = (gcnew System::Windows::Forms::ListBox());
			this->butDelete = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radFreshman = (gcnew System::Windows::Forms::RadioButton());
			this->radSophomores = (gcnew System::Windows::Forms::RadioButton());
			this->radJuniors = (gcnew System::Windows::Forms::RadioButton());
			this->radSeniors = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->listStudentList = (gcnew System::Windows::Forms::ListBox());
			this->butStayedBack = (gcnew System::Windows::Forms::Button());
			this->butTransferred = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->butContinue = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"New Teacher";
			// 
			// butAdd
			// 
			this->butAdd->Enabled = false;
			this->butAdd->Location = System::Drawing::Point(167, 30);
			this->butAdd->Name = L"butAdd";
			this->butAdd->Size = System::Drawing::Size(75, 23);
			this->butAdd->TabIndex = 1;
			this->butAdd->Text = L"Add";
			this->butAdd->UseVisualStyleBackColor = true;
			this->butAdd->Click += gcnew System::EventHandler(this, &NewYear::butAdd_Click);
			// 
			// txtTeacher
			// 
			this->txtTeacher->Location = System::Drawing::Point(13, 30);
			this->txtTeacher->Name = L"txtTeacher";
			this->txtTeacher->Size = System::Drawing::Size(148, 20);
			this->txtTeacher->TabIndex = 2;
			this->txtTeacher->TextChanged += gcnew System::EventHandler(this, &NewYear::txtTeacher_TextChanged);
			// 
			// listTeachers
			// 
			this->listTeachers->FormattingEnabled = true;
			this->listTeachers->Location = System::Drawing::Point(12, 73);
			this->listTeachers->Name = L"listTeachers";
			this->listTeachers->Size = System::Drawing::Size(148, 134);
			this->listTeachers->TabIndex = 3;
			this->listTeachers->SelectedIndexChanged += gcnew System::EventHandler(this, &NewYear::listTeachers_SelectedIndexChanged);
			// 
			// butDelete
			// 
			this->butDelete->Enabled = false;
			this->butDelete->Location = System::Drawing::Point(167, 73);
			this->butDelete->Name = L"butDelete";
			this->butDelete->Size = System::Drawing::Size(75, 23);
			this->butDelete->TabIndex = 4;
			this->butDelete->Text = L"Delete";
			this->butDelete->UseVisualStyleBackColor = true;
			this->butDelete->Click += gcnew System::EventHandler(this, &NewYear::butDelete_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Delete Teacher";
			// 
			// radFreshman
			// 
			this->radFreshman->AutoSize = true;
			this->radFreshman->Location = System::Drawing::Point(292, 34);
			this->radFreshman->Name = L"radFreshman";
			this->radFreshman->Size = System::Drawing::Size(126, 17);
			this->radFreshman->TabIndex = 6;
			this->radFreshman->TabStop = true;
			this->radFreshman->Text = L"Last Year\'s Freshman";
			this->radFreshman->UseVisualStyleBackColor = true;
			// 
			// radSophomores
			// 
			this->radSophomores->AutoSize = true;
			this->radSophomores->Location = System::Drawing::Point(292, 57);
			this->radSophomores->Name = L"radSophomores";
			this->radSophomores->Size = System::Drawing::Size(139, 17);
			this->radSophomores->TabIndex = 7;
			this->radSophomores->TabStop = true;
			this->radSophomores->Text = L"Last Year\'s Sophomores";
			this->radSophomores->UseVisualStyleBackColor = true;
			// 
			// radJuniors
			// 
			this->radJuniors->AutoSize = true;
			this->radJuniors->Location = System::Drawing::Point(292, 80);
			this->radJuniors->Name = L"radJuniors";
			this->radJuniors->Size = System::Drawing::Size(113, 17);
			this->radJuniors->TabIndex = 8;
			this->radJuniors->TabStop = true;
			this->radJuniors->Text = L"Last Year\'s Juniors";
			this->radJuniors->UseVisualStyleBackColor = true;
			// 
			// radSeniors
			// 
			this->radSeniors->AutoSize = true;
			this->radSeniors->Location = System::Drawing::Point(292, 103);
			this->radSeniors->Name = L"radSeniors";
			this->radSeniors->Size = System::Drawing::Size(115, 17);
			this->radSeniors->TabIndex = 9;
			this->radSeniors->TabStop = true;
			this->radSeniors->Text = L"Last Year\'s Seniors";
			this->radSeniors->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(309, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Edit Grade Levels";
			// 
			// listStudentList
			// 
			this->listStudentList->FormattingEnabled = true;
			this->listStudentList->Location = System::Drawing::Point(437, 34);
			this->listStudentList->Name = L"listStudentList";
			this->listStudentList->Size = System::Drawing::Size(181, 147);
			this->listStudentList->TabIndex = 11;
			this->listStudentList->SelectedIndexChanged += gcnew System::EventHandler(this, &NewYear::listStudentList_SelectedIndexChanged);
			// 
			// butStayedBack
			// 
			this->butStayedBack->Enabled = false;
			this->butStayedBack->Location = System::Drawing::Point(312, 127);
			this->butStayedBack->Name = L"butStayedBack";
			this->butStayedBack->Size = System::Drawing::Size(119, 23);
			this->butStayedBack->TabIndex = 12;
			this->butStayedBack->Text = L"Student Stayed Back";
			this->butStayedBack->UseVisualStyleBackColor = true;
			// 
			// butTransferred
			// 
			this->butTransferred->Enabled = false;
			this->butTransferred->Location = System::Drawing::Point(312, 156);
			this->butTransferred->Name = L"butTransferred";
			this->butTransferred->Size = System::Drawing::Size(119, 23);
			this->butTransferred->TabIndex = 13;
			this->butTransferred->Text = L"Student Transferred";
			this->butTransferred->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(233, 184);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(388, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Note: If Student skips a grade, click \"Student Transferred\" and add them in later" 
				L".";
			// 
			// butContinue
			// 
			this->butContinue->Location = System::Drawing::Point(543, 228);
			this->butContinue->Name = L"butContinue";
			this->butContinue->Size = System::Drawing::Size(75, 23);
			this->butContinue->TabIndex = 15;
			this->butContinue->Text = L"Continue";
			this->butContinue->UseVisualStyleBackColor = true;
			this->butContinue->Click += gcnew System::EventHandler(this, &NewYear::butContinue_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(233, 197);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(369, 13);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Or if you wish to delete a student for any reason, click \"Student Transferred\".";
			// 
			// NewYear
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(630, 263);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->butContinue);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->butTransferred);
			this->Controls->Add(this->butStayedBack);
			this->Controls->Add(this->listStudentList);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->radSeniors);
			this->Controls->Add(this->radJuniors);
			this->Controls->Add(this->radSophomores);
			this->Controls->Add(this->radFreshman);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->butDelete);
			this->Controls->Add(this->listTeachers);
			this->Controls->Add(this->txtTeacher);
			this->Controls->Add(this->butAdd);
			this->Controls->Add(this->label1);
			this->Name = L"NewYear";
			this->Text = L"NewYear";
			this->Load += gcnew System::EventHandler(this, &NewYear::NewYear_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void NewYear_Load(System::Object^  sender, System::EventArgs^  e)
		 {
			 msclr::interop::marshal_context context;
			 SavingStuff SS;
			 SS.loadSizes(totClasses, totElectives, totStudents, totCourses, totTeachers);
			 SS.loadStudentList(totStudents, StudentClass_List);
			 SS.loadStudentEList(totStudents, StudentElect_List);
			 SS.loadGradeSizes(GradeSizes);
			 SS.loadStudentGradeList(GradeSizes, StudentGradeList);
			 SS.loadTeacherList(totTeachers, TeacherVector_List);
			 SS.loadCheckPoint(ACheckNum);

			 // Add Teachers to listTeachers
			 for(int counter= 0; counter < totTeachers; counter++)
			 {
				 String ^ UpdateList = gcnew String(TeacherVector_List[counter].c_str());
				 listTeachers->Items->Add(UpdateList);
			 }
		 }
private: System::Void butContinue_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 ACheckNum= 1;
			 SavingStuff SS;
			 SS.saveCheckPoint(ACheckNum);

			 home->Show();
			 this->Hide();
			 this->Close();
		 }
private: System::Void txtTeacher_TextChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 butAdd->Enabled= true;
		 }
private: System::Void listTeachers_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 butDelete->Enabled= true;
		 }
private: System::Void listStudentList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 butStayedBack->Enabled= true;
			 butTransferred->Enabled= true;
		 }
private: System::Void butAdd_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			  msclr::interop::marshal_context context;
			  // Getting Variables from Windows Form
			  String ^ Teach= txtTeacher->Text;
			  // Converting Variables to std Variables
			  teacherAddName= context.marshal_as<std::string>(Teach);

			  BehindTheScenes BS;
			  BS.AddTeacher(teacherAddName, TeacherVector_List, totTeachers);

			  // Add Teachers to listTeachers
			  listTeachers->Items->Clear();
			  for(int counter= 0; counter < totTeachers; counter++)
			  {
				  String ^ UpdateList = gcnew String(TeacherVector_List[counter].c_str());
				  listTeachers->Items->Add(UpdateList);
			  }

			  SavingStuff SS;
			  SS.saveSizes(totClasses, totElectives, totStudents, totCourses, totTeachers);
			  SS.loadTeacherList(totTeachers, TeacherVector_List);
		 }
private: System::Void butDelete_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 teacherDelete= listTeachers->SelectedIndex;

			 BehindTheScenes BS;
			 BS.DeleteTeacher(teacherDelete, TeacherVector_List, totTeachers);

			 // Add Teachers to listTeachers
			 listTeachers->Items->Clear();
			 for(int counter= 0; counter < totTeachers; counter++)
			 {
				 String ^ UpdateList = gcnew String(TeacherVector_List[counter].c_str());
				 listTeachers->Items->Add(UpdateList);
			 }

			 SavingStuff SS;
			 SS.saveSizes(totClasses, totElectives, totStudents, totCourses, totTeachers);
			 SS.saveTeacherList(totTeachers, TeacherVector_List);
		 }
};
}
