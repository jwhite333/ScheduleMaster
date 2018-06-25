#include "StdAfx.h"
#include "BehindTheScenes.h"

BehindTheScenes::BehindTheScenes(void)
{
}
void BehindTheScenes::AddCourse(string className, string department, string credits, string semester, string teacher, string classSize, vector<string> &CourseList, vector<vector<string>> &ClassList, vector<vector<string>> &Elist, int &TotalCourses, int &TotalClasses, int &TotalElectives)
{
	// Fix any issues with Capitalization
	transform(className.begin(), className.end(), className.begin(), tolower);
	className[0]= toupper(className[0]);
	int nameSize = className.size();
	for (int spaceLocator = 0; spaceLocator < className.size(); spaceLocator++)
	{
		if ((className[spaceLocator] == 'A' && className[spaceLocator+ 1] == 'p' && className[spaceLocator+ 2] == ' ')
			|| (className[spaceLocator] == 'U' && className[spaceLocator+ 1] == 's' && className[spaceLocator+ 2] == ' '))
			{
				className[spaceLocator+ 1]= toupper(className[spaceLocator+ 1]);
			}
		if (className[spaceLocator] == ' ')
		{
			if ((className[spaceLocator+ 1] == 'a' && className[spaceLocator+ 2] == 'b')
				|| (className[spaceLocator+ 1] == 'b' && className[spaceLocator+ 2] == 'c')
				|| (className[spaceLocator+ 1] == 'i' && className[spaceLocator+ 2] == 'i')
				|| (className[spaceLocator+ 1] == 'i' && className[spaceLocator+ 2] == 'v')
				|| (className[spaceLocator+ 1] == 'v' && className[spaceLocator+ 2] == 'i'))
			{
				if (className[spaceLocator+ 3] == 'i')
				{
					className[spaceLocator+ 3]= toupper(className[spaceLocator+ 3]);
				}
				className[spaceLocator+ 2]= toupper(className[spaceLocator+ 2]);
			}
			className[spaceLocator+ 1]= toupper(className[spaceLocator+ 1]);
		}
		if (className[spaceLocator] == '/')
		{
			className.replace(spaceLocator, 1, "+");
		}
		if (className[spaceLocator] == ' ' && spaceLocator == (nameSize -1))
		{
			className.replace(spaceLocator, 1, "");
		}

	}
	// Add to CourseList
	ConvertStuff CV;
	CourseList.push_back(department+ "- "+ className+ "- "+ teacher+ " "+ credits+ " Creds");
	TotalCourses= CourseList.size();
	// Create new Elective Course in Elist
	if(CV.StdStringToStdInt(credits) == 3)
	{
		// Get size of Elist for IDnum
		IDnum= Elist[0].size();
		// Create new Elective with NAME, dept, ID, # of Student, and Semester Preference
		Elist[0].push_back(className);
		Elist[1].push_back(department);
		Elist[2].push_back(CV.StdIntToStdString(IDnum));
		Elist[3].push_back("0");
		Elist[4].push_back(teacher);
		Elist[5].push_back(classSize);
		TotalElectives= Elist[0].size();
	}
	// Create new Full Block Course in ClassList
	else
	{
		// Get size of ClassList for IDnum
		IDnum= ClassList[0].size();
		// Create new Course with NAME, dept, ID, and Semester Preference
		ClassList[0].push_back(className);
		ClassList[1].push_back(department);
		ClassList[2].push_back(CV.StdIntToStdString(IDnum));
		ClassList[3].push_back("0");
		ClassList[5].push_back(teacher);
		ClassList[6].push_back(classSize);
		if(CV.StdStringToStdInt(credits) == 12)
		{
			// Set Semester Preference for AP course to 1
			ClassList[4].push_back("1");
			// Create other half of AP Course with opposite Semester Preference
			ClassList[0].push_back(className);
			ClassList[1].push_back(department);
			ClassList[2].push_back(CV.StdIntToStdString(IDnum));
			ClassList[3].push_back("0");
			ClassList[4].push_back("2");
			ClassList[5].push_back(teacher);
			ClassList[6].push_back(classSize);
			TotalClasses= ClassList[0].size();
		}
		else
		{
			ClassList[4].push_back(semester);
			TotalClasses= ClassList[0].size();
		}
	}
}
void BehindTheScenes::RemoveCourse(int deletedCourse, vector<string> &CourseList, vector<vector<string>> &ClassList, vector<vector<string>> &Elist, int &TotalCourses, int &TotalClasses, int &TotalElectives)
{
	ConvertStuff CV;
	// Search for # of credits to decide which vector to search
	string NAME= CourseList[deletedCourse];
	int numCreds;
	for (int spaceLocator = 0; spaceLocator < NAME.size(); spaceLocator++)
	{
		if (NAME[spaceLocator] == 'C' && NAME[spaceLocator+ 1] == 'r' && NAME[spaceLocator+ 2] == 'e'
			&& NAME[spaceLocator+ 3] == 'd' && NAME[spaceLocator+ 4] == 's')
		{
			numCreds= NAME[spaceLocator -2]- '0';
		}
	}
	if(numCreds == 3)
	{
		string courseName;
		// Finding Where The Class Is
		int deletedClass= 0;
		int savedDash= 0;
		int numTimes= 0;

		for(int nameLocator = 0; nameLocator < NAME.size(); nameLocator++)
		{
			numTimes++;
			if(NAME[nameLocator] == '-' && NAME[nameLocator +1] == ' ')
			{
				courseName.assign(NAME, savedDash, numTimes -2);
				for(int name2Locator = 0; name2Locator < Elist[0].size(); name2Locator++)
				{
					if(Elist[0][name2Locator] == courseName)
					{
						deletedClass= name2Locator;
						break;
					}
				}
				savedDash= nameLocator +2;
				numTimes= 0;
			}
		}

		// Move all Course Information after this point over
		for(int counter = deletedClass;counter < TotalElectives -1;counter++)
		{
			Elist[0][counter]= Elist[0][counter+ 1];
			Elist[1][counter]= Elist[1][counter+ 1];
			Elist[2][counter]= Elist[2][counter+ 1];
			Elist[3][counter]= Elist[3][counter+ 1];
			Elist[4][counter]= Elist[4][counter+ 1];
			Elist[5][counter]= Elist[5][counter+ 1];
		}
		// Resize vector to remove extra point
		TotalElectives--;
		for(int countRemove= 0; countRemove < Elist.size(); countRemove++)
			Elist[countRemove].resize(TotalElectives);
	}
	else
	{
		string courseName;
		// Finding Where The Class Is
		int deletedClass= 0;
		int savedDash= 0;
		int numTimes= 0;

		for(int nameLocator = 0; nameLocator < NAME.size(); nameLocator++)
		{
			numTimes++;
			if(NAME[nameLocator] == '-' && NAME[nameLocator +1] == ' ')
			{
				courseName.assign(NAME, savedDash, numTimes -2);
				for(int name2Locator = 0; name2Locator < ClassList[0].size(); name2Locator++)
				{
					if(ClassList[0][name2Locator] == courseName)
					{
						deletedClass= name2Locator;
						break;
					}
				}
				savedDash= nameLocator +2;
				numTimes= 0;
			}
		}

		// Move all Course Information after this point over
		for(int counter = deletedClass;counter < TotalClasses -1;counter++)
		{
			ClassList[0][counter]= ClassList[0][counter+ 1];
			ClassList[1][counter]= ClassList[1][counter+ 1];
			ClassList[2][counter]= ClassList[2][counter+ 1];
			ClassList[3][counter]= ClassList[3][counter+ 1];
			ClassList[4][counter]= ClassList[4][counter+ 1];
			ClassList[5][counter]= ClassList[5][counter+ 1];
			ClassList[6][counter]= ClassList[6][counter+ 1];
		}
		// Resize vector to remove extra point
		TotalClasses--;
		for(int countR= 0; countR < ClassList.size(); countR++)
			ClassList[countR].resize(TotalClasses);
		// Move the Course Information over again if it's AP
		if(numCreds == 2)
		{
			for(int counter = deletedClass;counter < TotalClasses -1;counter++)
			{
				ClassList[0][counter]= ClassList[0][counter+ 1];
				ClassList[1][counter]= ClassList[1][counter+ 1];
				ClassList[2][counter]= ClassList[2][counter+ 1];
				ClassList[3][counter]= ClassList[3][counter+ 1];
				ClassList[4][counter]= ClassList[4][counter+ 1];
				ClassList[5][counter]= ClassList[5][counter+ 1];
				ClassList[6][counter]= ClassList[6][counter+ 1];
			}
			TotalClasses--;
			for(int countRe= 0; countRe < ClassList.size(); countRe++)
				ClassList[countRe].resize(TotalClasses);
		}
	}

	// Remove the Course from CourseList
	for(int counter = deletedCourse;counter < TotalCourses -1;counter++)
	{
		CourseList[counter]= CourseList[counter+ 1];
	}
	TotalCourses--;
	CourseList.resize(TotalCourses);
}
void BehindTheScenes::AddStudent(string FirstName, string LastName, int GradeLevel, vector<vector<string>> &ClassList, vector<vector<string>> &Elist, vector<vector<string>> &StudentClassList, vector<vector<string>> &StudentElist, vector<vector<string>> &StudentGradeList, vector<int> &GradeSizes, vector<string> &CourseChoiceList, int &TotalStudents)
{
	ConvertStuff CV;
	TotalStudents++;

	// Add Student to Student Grade List
	StudentGradeList[GradeLevel].push_back(FirstName + " " + LastName);
	GradeSizes[GradeLevel]= GradeSizes[GradeLevel] +1;

	bool swapping = true;
	string LastName1;
	string LastName2;
	int savedDash;
	int numTimes;
	if (GradeSizes[GradeLevel] > 1)
	{
		while(swapping == true) // Alphabatize Them
		{
			swapping = false;
			for(int x = 0; x < (StudentGradeList[GradeLevel].size() -1); x++)
			{
				for(int repeat2= 0; repeat2 < 2; repeat2++)
				{
					string NAME= StudentGradeList[GradeLevel][x+ repeat2];
					for (int spaceLocator = 0; spaceLocator < NAME.size(); spaceLocator++)
					{
						if (NAME[spaceLocator] == ' ')
						{
							if(repeat2 == 0)
								LastName1.assign(NAME, savedDash, numTimes -2);
							if(repeat2 == 1)
								LastName2.assign(NAME, savedDash, numTimes -2);
						}
						savedDash= spaceLocator +2;
						numTimes= 0;
					}
				}

				int NameSize;
				if(LastName1.size() <= LastName2.size())
					NameSize= LastName1.size();
				else
					NameSize= LastName2.size();
				int COMPARE= LastName1.compare(0, NameSize, LastName2);
				if(COMPARE == 1)
				{
					string swapNames = StudentGradeList[GradeLevel][x];
					StudentGradeList[GradeLevel][x] = StudentGradeList[GradeLevel][x+1];
					StudentGradeList[GradeLevel][x+1] = swapNames;
					swapping = true;
				}
			
			}
		}
	}

	// Add Student to StudentEList
	StudentElist[0].push_back(FirstName);
	StudentElist[1].push_back(LastName);

	// Add Student to StudentClassList
	StudentClassList[0].push_back(FirstName);
	StudentClassList[1].push_back(LastName);

	// Convert CourseChoices to Different Lists
	string courseName;
	savedDash= 0;
	numTimes= 0;
	bool Added;
	
	// Set values at 9999
	int currentSize1 = StudentClassList[0].size();
	currentSize1 = currentSize1 - 1;
	for(int setNine1=2;setNine1<10;setNine1++)
	{
		StudentClassList[setNine1].push_back("9999");
	}	
	int currentSize2 = StudentElist[0].size();
	currentSize2 = currentSize2 - 1;
	for(int setNine2=2;setNine2<18;setNine2++)
	{
		StudentElist[setNine2].push_back("9999");
	}


	int classCount = 2;
	int eCount = 2;

	// Find Credits
	for(int counter= 0; counter < CourseChoiceList.size(); counter++)
	{
		int CSize = CourseChoiceList.size();
		Added= false;

		// Finding Number of Credits the Course Is
		string NAME= CourseChoiceList[counter];
		int numCreds;
		for (int spaceLocator = 0; spaceLocator < NAME.size(); spaceLocator++)
		{
			if (NAME[spaceLocator] == 'C' && NAME[spaceLocator+ 1] == 'r' && NAME[spaceLocator+ 2] == 'e'
				&& NAME[spaceLocator+ 3] == 'd' && NAME[spaceLocator+ 4] == 's')
			{
				numCreds= NAME[spaceLocator -2]- '0';
			}
		}
		// Elective
		if(numCreds == 3)
		{
			// Finding Name of the Course to Get ID Num
			savedDash= 0;
			numTimes= 0;
			for (int nameLocator = 0; nameLocator < NAME.size(); nameLocator++)
			{
				numTimes++;
				if(NAME[nameLocator] == '-' && NAME[nameLocator +1] == ' ')
				{
					courseName.assign(NAME, savedDash, numTimes -2);
					savedDash= nameLocator +2;
					numTimes= 0;
				}
			}

			// Adding the Course to StudentEList
			StudentElist[eCount][currentSize2] = (CV.NameToID(courseName, ClassList, Elist));
			eCount = eCount +1;
		}
		// Regular Class
		if(numCreds == 6)
		{
			// Finding Name of the Course to Get ID Num
			savedDash= 0;
			numTimes= 0;
			for (int nameLocator = 0; nameLocator < NAME.size(); nameLocator++)
			{
				numTimes++;
				if(NAME[nameLocator] == '-' && NAME[nameLocator +1] == ' ')
				{
					courseName.assign(NAME, savedDash, numTimes -2);
					savedDash= nameLocator +2;
					numTimes= 0;
				}
			}

			// Adding the Course to StudentClassList
			StudentClassList[classCount][currentSize1] = (CV.NameToID(courseName, ClassList, Elist));
			classCount = classCount +1;
		}
		if(numCreds == 2)
		{
			// Finding Name of the Course to Get ID Num
			savedDash= 0;
			numTimes= 0;
			for (int nameLocator = 0; nameLocator < NAME.size(); nameLocator++)
			{
				numTimes++;
				if(NAME[nameLocator] == '-' && NAME[nameLocator +1] == ' ')
				{
					courseName.assign(NAME, savedDash, numTimes -2);
					savedDash= nameLocator +2;
					numTimes= 0;
				}
			}

			// Adding the Course to StudentClassList
			StudentClassList[classCount][currentSize1] = (CV.NameToID(courseName, ClassList, Elist));
			StudentClassList[classCount+1][currentSize1] = (CV.NameToID(courseName, ClassList, Elist));
			classCount = classCount +2;
		}
	}
}
void BehindTheScenes::LoadStudent(string studentName, vector<vector<string>> &ClassList, vector<vector<string>> &Elist, vector<string> &CourseList, vector<vector<string>> &StudentClassList, vector<vector<string>> &StudentElist, vector<string> &CourseChoiceList, int TotalStudents)
{
	ConvertStuff CV;
	string FirstName;
	string LastName;
	// Finding StudentName
	int foundStudent= 0;
	int savedDash= 0;
	int numTimes= 0;
	int lastChar = studentName.size() - 1;
	bool nameAssigned = false;

	for(int nameLocator = 0; nameLocator < studentName.size(); nameLocator++)
	{
		if(nameAssigned == true)
			break;
		numTimes++;
		if(studentName[nameLocator] == ' ')
		{
			FirstName.assign(studentName, savedDash, nameLocator);
			LastName.assign(studentName, nameLocator+1, lastChar);

				for(int name2Locator = 0; name2Locator < StudentClassList[0].size(); name2Locator++)
				{
					if(StudentClassList[0][name2Locator] == FirstName && StudentClassList[1][name2Locator] == LastName)
					{
						foundStudent= name2Locator;
						break;
					}
				}
			nameAssigned = true;
		 }
	}

	vector<string> StudentChoices;
	// Finding Selected Courses
	for(int counter= 2; counter < 10; counter++)
	{
		if(StudentClassList[counter][foundStudent] != "9999")
			StudentChoices.push_back(CV.IDToName(StudentClassList[counter][foundStudent], ClassList, Elist));
	}
	for(int counter= 2; counter < 18; counter++)
	{
		if(StudentElist[counter][foundStudent] != "9999")
			StudentChoices.push_back(CV.EIDToName(StudentElist[counter][foundStudent], Elist));
	}
	for(int counter= 0; counter < CourseList.size(); counter++)
	{
		string NAME= CourseList[counter];
		string courseName= "";
		savedDash= 0;
		numTimes= 0;
		for (int nameLocator = 0; nameLocator < NAME.size(); nameLocator++)
		{
			numTimes++;
			if(NAME[nameLocator] == '-' && NAME[nameLocator +1] == ' ')
			{
				courseName.assign(NAME, savedDash, numTimes -2);
				savedDash= nameLocator +2;
				numTimes= 0;
			}
		}

		// Search for the class in StudentChoices
		for(int counter2= 0; counter2 < StudentChoices.size(); counter2++)
		{
			if(courseName == StudentChoices[counter2])
			{
				CourseChoiceList.push_back(CourseList[counter]);
			}
		}
	}
}
void BehindTheScenes::DeleteStudent(string FirstName, string LastName, int GradeLevel, vector<vector<string>> &StudentClassList, vector<vector<string>> &StudentElist, vector<vector<string>> &StudentGradeList, vector<int> &GradeSizes, int &TotalStudents)
{
	TotalStudents--;

	// Deleting from StudentGrade List
	string CombinedName= FirstName+ " "+ LastName;
	for(int counter= 0; counter < StudentGradeList[GradeLevel].size(); counter++)
	{
		if(StudentGradeList[GradeLevel][counter] == CombinedName)
		{
			GradeSizes[GradeLevel]= GradeSizes[GradeLevel] -1;
			for(int num= counter; num < StudentGradeList[GradeLevel].size() -1; num++)
			{
				StudentGradeList[GradeLevel][num]= StudentGradeList[GradeLevel][num+ 1];
			}
			StudentGradeList.resize(GradeSizes[GradeLevel]);
		}
	}

	// Deleting from StudentClassList and StudentElist
	for(int counter= 0; counter < StudentClassList[0].size(); counter++)
	{
		if(StudentClassList[0][counter] == FirstName && StudentClassList[1][counter] == LastName)
		{
			for(int num= counter; num < StudentClassList[0].size() -1; num++)
			{
				for(int count= 0; count < 10; count++)
				{
					StudentClassList[count][num]= StudentClassList[count][num+ 1];
				}
				for(int count= 0; count < 18; count++)
				{
					StudentElist[count][num]= StudentElist[count][num+ 1];
				}
			}
			for(int num= 0; num  < StudentClassList.size(); num++)
			{
				StudentClassList[num].resize(TotalStudents);
			}
			for(int num= 0; num < StudentElist.size(); num++)
			{
				StudentElist[num].resize(TotalStudents);
			}
		}
	}
}
void BehindTheScenes::AddTeacher(string teacherName, vector<string> &TeacherList, int &TotalTeachers)
{
	ConvertStuff CV;
	TotalTeachers++;

	// Add Teacher to TeacherList
	TeacherList.push_back(teacherName);

	bool swapping = true;
	string LastName1;
	string LastName2;
	int savedDash;
	int numTimes;
	if (TeacherList.size() > 1)
	{
		while(swapping == true) // Alphabatize Them
		{
			swapping = false;
			for(int x = 0; x < (TeacherList.size() -1); x++)
			{
				for(int repeat2= 0; repeat2 < 2; repeat2++)
				{
					string NAME= TeacherList[x+ repeat2];
					for (int spaceLocator = 0; spaceLocator < NAME.size(); spaceLocator++)
					{
						if (NAME[spaceLocator] == ' ')
						{
							if(repeat2 == 0)
								LastName1.assign(NAME, savedDash, numTimes -2);
							if(repeat2 == 1)
								LastName2.assign(NAME, savedDash, numTimes -2);
						}
						savedDash= spaceLocator +2;
						numTimes= 0;
					}
				}

				int NameSize;
				if(LastName1.size() <= LastName2.size())
					NameSize= LastName1.size();
				else
					NameSize= LastName2.size();
				int COMPARE= LastName1.compare(0, NameSize, LastName2);
				if(COMPARE == 1)
				{
					string swapNames = TeacherList[x];
					TeacherList[x] = TeacherList[x+1];
					TeacherList[x+1] = swapNames;
					swapping = true;
				}
			
			}
		}
	}
}
void BehindTheScenes::DeleteTeacher(int placement, vector<string> &TeacherList, int &TotalTeachers)
{
	TotalTeachers--;

	for(int counter= placement; counter < TeacherList.size() -1; counter++)
	{
		TeacherList[counter]= TeacherList[counter +1];
	}

	TeacherList.resize(TotalTeachers);
}