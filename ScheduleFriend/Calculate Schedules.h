#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ScheduleFriend {

	static vector<vector<string>> SelectedClassList;
	static vector<vector<string>> SElist;
	static vector<vector<string>> StudentEList;
	static vector<vector<string>> StudentList;

	static int TotalClasses;
	static int TotalElectives;
	static int TotalStudents;
	static int TotalCourses;
	static int TotalTeachers;

	/// <summary>
	/// Summary for CalculateSchedules
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CalculateSchedules : public System::Windows::Forms::Form
	{
	public:
		CalculateSchedules(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Label^  label6;
	public: 
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Form ^ home;
	public:
		CalculateSchedules(System::Windows::Forms::Form ^ form)
		{
			home = form;
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CalculateSchedules()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^  progCalculationNumber;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  labEndAmount;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  labStartAmount;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  butContinue;
	private: System::Windows::Forms::Button^  butCancel;

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
			this->progCalculationNumber = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labEndAmount = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labStartAmount = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->butContinue = (gcnew System::Windows::Forms::Button());
			this->butCancel = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// progCalculationNumber
			// 
			this->progCalculationNumber->Location = System::Drawing::Point(12, 227);
			this->progCalculationNumber->Name = L"progCalculationNumber";
			this->progCalculationNumber->Size = System::Drawing::Size(606, 23);
			this->progCalculationNumber->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 208);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Progress:";
			// 
			// labEndAmount
			// 
			this->labEndAmount->AutoSize = true;
			this->labEndAmount->Location = System::Drawing::Point(581, 208);
			this->labEndAmount->Name = L"labEndAmount";
			this->labEndAmount->Size = System::Drawing::Size(35, 13);
			this->labEndAmount->TabIndex = 2;
			this->labEndAmount->Text = L"label2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(541, 208);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"out of";
			// 
			// labStartAmount
			// 
			this->labStartAmount->AutoSize = true;
			this->labStartAmount->Location = System::Drawing::Point(500, 208);
			this->labStartAmount->Name = L"labStartAmount";
			this->labStartAmount->Size = System::Drawing::Size(35, 13);
			this->labStartAmount->TabIndex = 4;
			this->labStartAmount->Text = L"label3";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(13, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(467, 31);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Are You Sure You Wish To Continue\?";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(13, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(572, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Clicking continue will start the Schedule Creation Process. Once started it will " 
				L"have to continue running until it is finished.";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(135, 118);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(369, 17);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Warning: The following process must happen all at once. \r\n";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// butContinue
			// 
			this->butContinue->Location = System::Drawing::Point(148, 92);
			this->butContinue->Name = L"butContinue";
			this->butContinue->Size = System::Drawing::Size(75, 23);
			this->butContinue->TabIndex = 8;
			this->butContinue->Text = L"Continue";
			this->butContinue->UseVisualStyleBackColor = true;
			// 
			// butCancel
			// 
			this->butCancel->Location = System::Drawing::Point(405, 92);
			this->butCancel->Name = L"butCancel";
			this->butCancel->Size = System::Drawing::Size(75, 23);
			this->butCancel->TabIndex = 9;
			this->butCancel->Text = L"Cancel";
			this->butCancel->UseVisualStyleBackColor = true;
			this->butCancel->Click += gcnew System::EventHandler(this, &CalculateSchedules::butCancel_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 61);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(607, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"If you have any more students to add before the schedules are created, please hit" 
				L" Cancel and fill in the required information first.";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(40, 152);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(554, 17);
			this->label9->TabIndex = 13;
			this->label9->Text = L"If you do not have the time to wait, please postpone hitting Continue until you h" 
				L"ave the ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(265, 169);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(93, 17);
			this->label7->TabIndex = 14;
			this->label7->Text = L"time to do so.";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(53, 135);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(522, 17);
			this->label8->TabIndex = 15;
			this->label8->Text = L"This process is very time consuming and may take up to half an hour to complete.";
			// 
			// CalculateSchedules
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(630, 262);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->butCancel);
			this->Controls->Add(this->butContinue);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->labStartAmount);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->labEndAmount);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progCalculationNumber);
			this->Name = L"CalculateSchedules";
			this->Text = L"CalculateSchedules";
			this->Load += gcnew System::EventHandler(this, &CalculateSchedules::CalculateSchedules_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void CalculateSchedules_Load(System::Object^  sender, System::EventArgs^  e)
	{
		SavingStuff SS;
		SS.loadSizes(TotalClasses, TotalElectives, TotalStudents, TotalCourses, TotalTeachers);
		SS.loadClassList(TotalClasses, SelectedClassList);
		SS.loadElist(TotalElectives, SElist);
		SS.loadStudentList(TotalStudents, StudentList);
		SS.loadStudentEList(TotalStudents, StudentEList);


		ConvertStuff CV;

		vector<string>::iterator iter;
		for(int counter1=0;counter1<TotalStudents;counter1++)  
		{
			for(int counter2=2;counter2<18;counter2++)
			{
				int E = CV.StdStringToStdInt(StudentEList[counter2][counter1]);
				if (E == 9999)
					break;
				iter=find(SElist[2].begin(),SElist[2].end(), CV.StdIntToStdString(E));
				int newE = iter - SElist[2].begin();
				int newSize = CV.StdStringToStdInt(SElist[3][newE]) + 1;
				SElist[3][newE] = CV.StdIntToStdString(newSize);
			}
		}

		vector<string>::iterator iterAP;
		int SSsize = SelectedClassList[0].size();
		for(int S=0;S<SSsize;S++)
		{
			SelectedClassList[3][S] = "0";
		}
		for(int counter1=0;counter1<TotalStudents;counter1++) 
		{
			for(int counter2=2;counter2<10;counter2++)
			{
				int C = CV.StdStringToStdInt(StudentList[counter2][counter1]);
				if (C == 9999)
					break;
				iter=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), CV.StdIntToStdString(C));  
				int newC = iter - SelectedClassList[2].begin();
				int newSize = CV.StdStringToStdInt(SelectedClassList[3][newC]) + 1;
				SelectedClassList[3][newC] = CV.StdIntToStdString(newSize);
				int placement = newC;
				int end = SelectedClassList[0].size();
				for(int findAP=newC+1;findAP<end;findAP++)
				{
					placement = placement + 1;
					if ( SelectedClassList[2][findAP] == CV.StdIntToStdString(C))
					{
						int newC2 = placement;
						int newSize2 = CV.StdStringToStdInt(SelectedClassList[3][newC2]) + 1;
						SelectedClassList[3][newC2] = CV.StdIntToStdString(newSize2);
					}
				}
			}
		}

		// Adding in Extra Copies of a Class
		for(int AddAClass= 0; AddAClass < TotalClasses; AddAClass++)
		{
			float numOfClasses= CV.StdStringToStdInt(SelectedClassList[3][AddAClass]) / CV.StdStringToStdInt(SelectedClassList[6][AddAClass]);
			while(numOfClasses > 1.5)
			{
				for(int counter= 0; counter < SelectedClassList.size(); counter++)
				{
					SelectedClassList[counter].push_back(SelectedClassList[counter][AddAClass]);
				}
				numOfClasses= numOfClasses - 1.5;
			}
		}

		// Adding in Extra Electives
		for(int AddAClass= 0; AddAClass < TotalElectives; AddAClass++)
		{
			float numOfClasses= CV.StdStringToStdInt(SElist[3][AddAClass]) / CV.StdStringToStdInt(SElist[5][AddAClass]);
			while(numOfClasses > 1.5)
			{
				for(int counter= 0; counter < SElist.size(); counter++)
				{
					SElist[counter].push_back(SElist[counter][AddAClass]);
				}
				numOfClasses= numOfClasses - 1.5;
			}
		}

		SelectedClassList.resize(6);
		SElist.resize(5);

	}
private: System::Void butCancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		home->Show();
		this->Hide();
		this->Close();
	}
};
}
