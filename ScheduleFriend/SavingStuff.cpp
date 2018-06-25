#include "stdafx.h"
#include "SavingStuff.h"
using namespace std;

SavingStuff::SavingStuff(void)
{
}
void SavingStuff::saveCheckPoint(int checkPoint)
{
	ofstream outFile;
	outFile.open("CheckPoint.dat");
	outFile << checkPoint;
	outFile.close();
}
void SavingStuff::loadCheckPoint(int &checkPoint)
{
	ifstream inFile;
	inFile.open("CheckPoint.dat");
	inFile >> checkPoint;
	inFile.close();
}
// Save and Load the Course Catalog for Add Class.h
void SavingStuff::saveCourseList(int TotalCourses, vector<string> &CourseList)
{
	ofstream outFile;
	outFile.open("CourseList.dat");
	for(num= 0; num < TotalCourses; num++)
	{
		outFile << CourseList[num] << endl;
	}
	outFile.close();
}
void SavingStuff::loadCourseList(int TotalCourses, vector<string> &CourseList)
{
	ifstream inFile;
	inFile.open("CourseList.dat");
	num= 0;
	CourseList.resize(TotalCourses);
	for(num= 0; num < TotalCourses; num++)
	{
		getline(inFile, CourseList[num]);
	}
	inFile.close();
}
// Load and Save Teacher List
void SavingStuff::saveTeacherList(int TotalTeachers, vector<string> &TeacherList)
{
	ofstream outFile;
	outFile.open("TeacherList.dat");
	for(num= 0; num < TotalTeachers; num++)
	{
		outFile << TeacherList[num] << endl;
	}
	outFile.close();
}
void SavingStuff::loadTeacherList(int TotalTeachers, vector<string> &TeacherList)
{
	ifstream inFile;
	inFile.open("TeacherList.dat");
	num= 0;
	TeacherList.resize(TotalTeachers);
	for(num= 0; num < TotalTeachers; num++)
	{
		getline(inFile, TeacherList[num]);
	}
	inFile.close();
}
// GradeLevel Sizes for vector StudentGradeList
void SavingStuff::saveGradeSizes(vector<int> &GradeSizes)
{
	ofstream outFile;
	outFile.open("GradeSizes.dat");
	for(num= 0; num < 5; num++)
	{
		outFile << GradeSizes[num] << endl;
	}
	outFile.close();
}
void SavingStuff::loadGradeSizes(vector<int> &GradeSizes)
{
	ifstream inFile;
	inFile.open("GradeSizes.dat");
	GradeSizes.resize(5);
	for(num= 0; num < 5; num++)
	{
		inFile >> GradeSizes[num];
	}
	inFile.close();
}
// List of he names of people in each class
void SavingStuff::saveStudentGradeList(vector<int> GradeSizes, vector<vector<string>> &StudentGradeList)
{
	ofstream outFile;
	outFile.open("StudentGradeList.dat");
	for(num= 0; num < 5; num++)
	{
		for(counter= 0; counter < GradeSizes[num]; counter++)
		{
			outFile << StudentGradeList[num][counter] << endl;
		}
	}
	outFile.close();
}
void SavingStuff::loadStudentGradeList(vector<int> GradeSizes, vector<vector<string>> &StudentGradeList)
{
	ifstream inFile;
	inFile.open("StudentGradeList.dat");
	StudentGradeList.resize(5);
	for(counter=0;counter<4;counter++)
	{
		StudentGradeList[counter].resize(GradeSizes[counter]);
	}
	for(num= 0; num < 5; num++)
	{
		for(counter= 0; counter < GradeSizes[num]; counter++)
		{
			getline(inFile, StudentGradeList[num][counter]);
		}
	}
	inFile.close();
}
//
void SavingStuff::saveClassList(int TotalClasses, vector<vector<string>> &ClassList)
{
	ofstream outFile;
	outFile.open("ClassList.dat");
	num= 0;
	while (num < TotalClasses)
	{
		counter= 0;
		while (counter < 7)
		{
			outFile << ClassList[counter][num] << endl;
			counter= counter+1;
		}
		num= num+1;
	}
	outFile.close();
}
void SavingStuff::loadClassList(int TotalClasses, vector<vector<string>> &ClassList)
{
	ifstream inFile;
	inFile.open("ClassList.dat");
	num= 0;
	ClassList.resize(7);
	for(counter=0;counter<7;counter++)
	{
		ClassList[counter].resize(TotalClasses);
	}
	while (num < TotalClasses)
	{
		counter= 0;
		while (counter < 7)
		{
			getline(inFile, ClassList[counter][num]);
			counter= counter+1;
		}
		num= num+1;
	}
	inFile.close();
}
//
void SavingStuff::saveElist(int TotalElectives, vector<vector<string>> &Elist)
{
	ofstream outFile;
	outFile.open("Elist.dat");
	num= 0;
	while (num < TotalElectives)
	{
		counter= 0;
		while (counter < 6)
		{
			outFile << Elist[counter][num] << endl;
			counter= counter+1;
		}
		num= num+1;
	}
	outFile.close();
}
void SavingStuff::loadElist(int TotalElectives, vector<vector<string>> &Elist)
{
	ifstream inFile;
	inFile.open("Elist.dat");
	num= 0;
	Elist.resize(6);
	Elist[0].resize(TotalElectives);
	Elist[1].resize(TotalElectives);
	Elist[2].resize(TotalElectives);
	Elist[3].resize(TotalElectives);
	Elist[4].resize(TotalElectives);
	Elist[5].resize(TotalElectives);

	for(num;num<TotalElectives;num++)
	{
		counter= 0;
		for(counter;counter<6;counter++)
		{
			getline(inFile, Elist[counter][num]);
		}
	}
	inFile.close();
}
//
void SavingStuff::saveStudentEList(int TotalStudents, vector<vector<string>> &StudentEList)
{
	ofstream outFile;
	outFile.open("StudentEList.dat");
	for(counter=0;counter<TotalStudents;counter++)
	{
		for(num=0;num<18;num++)
		{
			outFile << StudentEList[num][counter] << endl;
		}
	}
	outFile.close();
}
void SavingStuff::loadStudentEList(int TotalStudents, vector<vector<string>> &StudentEList)
{
	ifstream inFile;
	inFile.open("StudentEList.dat");
	StudentEList.resize(18);
	for(int r=0;r<18;r++)
	{
		StudentEList[r].resize(TotalStudents);
	}
	for(counter=0;counter<TotalStudents;counter++)
	{
		for(num=0;num<18;num++)
		{
			getline(inFile, StudentEList[num][counter]);
		}
	}
	inFile.close();
}
//
void SavingStuff::saveSizes(int TotalClasses, int TotalElectives, int TotalStudents, int TotalCourses, int TotalTeachers)
{
	ofstream outFile;
	outFile.open("ClassSizes.dat");

	outFile << TotalClasses << endl << TotalElectives << endl << TotalStudents << endl << TotalCourses << endl << TotalTeachers;

	outFile.close();
}
void SavingStuff::loadSizes(int &TotalClasses, int &TotalElectives, int &TotalStudents, int &TotalCourses, int &TotalTeachers)
{
	ifstream inFile;
	inFile.open("ClassSizes.dat");

	inFile >> TotalClasses;
	inFile >> TotalElectives;
	inFile >> TotalStudents;
	inFile >> TotalCourses;
	inFile >> TotalTeachers;

	inFile.close();
}

//
void SavingStuff::saveSelectedClassList(int TotalClasses, vector<vector<string>> &SelectedClassList)
{
	ofstream outFile;
	outFile.open("SelectedClassList.dat");
	for(counter=0;counter<TotalClasses;counter++)
	{
		for(num=0;num<6;num++)
		{
			outFile << SelectedClassList[num][counter] << endl;
		}
	}
	outFile.close();
}
void SavingStuff::loadSelectedClassList(int TotalClasses, vector<vector<string>> &SelectedClassList)
{
	ifstream inFile;
	inFile.open("SelectedClassList.dat");
	SelectedClassList.resize(6);
	SelectedClassList[0].resize(TotalClasses);
	SelectedClassList[1].resize(TotalClasses);
	SelectedClassList[2].resize(TotalClasses);
	SelectedClassList[3].resize(TotalClasses);
	SelectedClassList[4].resize(TotalClasses);
	SelectedClassList[5].resize(TotalClasses);

	for(counter=0;counter<TotalClasses;counter++)
	{
		for(num=0;num<6;num++)
		{
			getline(inFile, SelectedClassList[num][counter]);
		}
	}
	inFile.close();
}

//
void SavingStuff::saveSelectedEList(int TotalElectives, vector<vector<string>> &SElist)
{
	ofstream outFile;
	outFile.open("SelectedEList.dat");
	for(counter=0;counter<TotalElectives;counter++)
	{
		for(num=0;num<5;num++)
		{
			outFile << SElist[num][counter] << endl;
		}
	}
	outFile.close();
}
void SavingStuff::loadSelectedEList(int TotalElectives, vector<vector<string>> &SElist)
{
	ifstream inFile;
	inFile.open("SelectedEList.dat");
	SElist.resize(5);
	SElist[0].resize(TotalElectives);
	SElist[1].resize(TotalElectives);
	SElist[2].resize(TotalElectives);
	SElist[3].resize(TotalElectives);
	SElist[4].resize(TotalElectives);

	for(counter=0;counter<TotalElectives;counter++)
	{
		for(num=0;num<5;num++)
		{
			getline(inFile, SElist[num][counter]);
		}
	}
	inFile.close();
}
//
void SavingStuff::saveStudentList(int TotalStudents, vector<vector<string>> &StudentList)
{
	ofstream outFile;
	outFile.open("StudentList.dat");
	for(counter=0;counter<TotalStudents;counter++)
	{
		for(num=0;num<10;num++)
		{
			outFile << StudentList[num][counter] << endl;
		}
	}
	outFile.close();
}
void SavingStuff::loadStudentList(int TotalStudents, vector<vector<string>> &StudentList)
{
	ifstream inFile;
	inFile.open("StudentList.dat");
	StudentList.resize(10);
	for(int r=0;r<10;r++)
	{
		StudentList[r].resize(TotalStudents);
	}
	for(counter=0;counter<TotalStudents;counter++)
	{
		for(num=0;num<10;num++)
		{
			getline(inFile, StudentList[num][counter]);
		}
	}
	inFile.close();
}
//
void SavingStuff::saveStudentCombinedList(int TotalStudents, vector<vector<string>> &StudentEList)
{
	ofstream outFile;
	outFile.open("StudentCombinedList.dat");
	for(counter=0;counter<TotalStudents;counter++)
	{
		for(num=0;num<18;num++)
		{
			outFile << StudentEList[num][counter] << endl;
		}
	}
	outFile.close();
}
void SavingStuff::loadStudentCombinedList(int TotalStudents, vector<vector<string>> &StudentEList)
{
	ifstream inFile;
	inFile.open("StudentCombinedList.dat");
	StudentEList.resize(18);
	for(int r=0;r<18;r++)
	{
		StudentEList[r].resize(TotalStudents);
	}
	for(counter=0;counter<TotalStudents;counter++)
	{
		for(num=0;num<18;num++)
		{
			getline(inFile, StudentEList[num][counter]);
		}
	}
	inFile.close();
}
//
void SavingStuff::loadResults(int block1, int block2, int block3, int block4, int block12, int block22, int block32, int block42, std::vector<vector<string>> &S1ListResult, vector<vector<string>> &S2ListResult)
{
	ifstream inFile;
	inFile.open("Result.dat");

	S1ListResult.resize(4);
	S1ListResult[0].resize(block1);
	S1ListResult[1].resize(block2);
	S1ListResult[2].resize(block3);
	S1ListResult[3].resize(block4);

	S2ListResult.resize(4);
	S2ListResult[0].resize(block12);
	S2ListResult[1].resize(block22);
	S2ListResult[2].resize(block32);
	S2ListResult[3].resize(block42);

//S1
	for(int r=0;r<block1;r++)
	{
		getline(inFile, S1ListResult[0][r]);
	}
	for(int r=0;r<block2;r++)
	{
		getline(inFile, S1ListResult[1][r]);
	}
	for(int r=0;r<block3;r++)
	{
		getline(inFile, S1ListResult[2][r]);
	}
	for(int r=0;r<block4;r++)
	{
		getline(inFile, S1ListResult[3][r]);
	}
//S2
	for(int r=0;r<block12;r++)
	{
		getline(inFile, S2ListResult[0][r]);
	}
	for(int r=0;r<block22;r++)
	{
		getline(inFile, S2ListResult[1][r]);
	}
	for(int r=0;r<block32;r++)
	{
		getline(inFile, S2ListResult[2][r]);
	}
	for(int r=0;r<block42;r++)
	{
		getline(inFile, S2ListResult[3][r]);
	}
	inFile.close();

}
void SavingStuff::saveResults(int block1, int block2, int block3, int block4, int block12, int block22, int block32, int block42, std::vector<vector<string>> &S1ListResult, vector<vector<string>> &S2ListResult)
{
	ofstream outFile;
	outFile.open("Result.dat");
//S1
	for(int r=0;r<block1;r++)
	{
		outFile << S1ListResult[0][r] << endl;
	}
	for(int r=0;r<block2;r++)
	{
		outFile << S1ListResult[1][r] << endl;
	}
	for(int r=0;r<block3;r++)
	{
		outFile << S1ListResult[2][r] << endl;
	}
	for(int r=0;r<block4;r++)
	{
		outFile << S1ListResult[3][r] << endl;
	}
//S2
	for(int r=0;r<block12;r++)
	{
		outFile << S2ListResult[0][r] << endl;
	}
	for(int r=0;r<block22;r++)
	{
		outFile << S2ListResult[1][r] << endl;
	}
	for(int r=0;r<block32;r++)
	{
		outFile << S2ListResult[2][r] << endl;
	}
	for(int r=0;r<block42;r++)
	{
		outFile << S2ListResult[3][r] << endl;
	}
	

	outFile.close();
}

//
void SavingStuff::loadResultsCopy(int block1, int block2, int block3, int block4, int block12, int block22, int block32, int block42, std::vector<vector<string>> &S1ListResultCopy, vector<vector<string>> &S2ListResultCopy)
{
	ifstream inFile;
	inFile.open("ResultCopy.dat");

	S1ListResultCopy.resize(4);
	S1ListResultCopy[0].resize(block1);
	S1ListResultCopy[1].resize(block2);
	S1ListResultCopy[2].resize(block3);
	S1ListResultCopy[3].resize(block4);

	S2ListResultCopy.resize(4);
	S2ListResultCopy[0].resize(block12);
	S2ListResultCopy[1].resize(block22);
	S2ListResultCopy[2].resize(block32);
	S2ListResultCopy[3].resize(block42);

//S1
	for(int r=0;r<block1;r++)
	{
		getline(inFile, S1ListResultCopy[0][r]);
	}
	for(int r=0;r<block2;r++)
	{
		getline(inFile, S1ListResultCopy[1][r]);
	}
	for(int r=0;r<block3;r++)
	{
		getline(inFile, S1ListResultCopy[2][r]);
	}
	for(int r=0;r<block4;r++)
	{
		getline(inFile, S1ListResultCopy[3][r]);
	}
//S2
	for(int r=0;r<block12;r++)
	{
		getline(inFile, S2ListResultCopy[0][r]);
	}
	for(int r=0;r<block22;r++)
	{
		getline(inFile, S2ListResultCopy[1][r]);
	}
	for(int r=0;r<block32;r++)
	{
		getline(inFile, S2ListResultCopy[2][r]);
	}
	for(int r=0;r<block42;r++)
	{
		getline(inFile, S2ListResultCopy[3][r]);
	}
	inFile.close();

}
void SavingStuff::saveResultsCopy(int block1, int block2, int block3, int block4, int block12, int block22, int block32, int block42, std::vector<vector<string>> &S1ListResultCopy, vector<vector<string>> &S2ListResultCopy)
{
	ofstream outFile;
	outFile.open("ResultCopy.dat");
//S1
	for(int r=0;r<block1;r++)
	{
		outFile << S1ListResultCopy[0][r] << endl;
	}
	for(int r=0;r<block2;r++)
	{
		outFile << S1ListResultCopy[1][r] << endl;
	}
	for(int r=0;r<block3;r++)
	{
		outFile << S1ListResultCopy[2][r] << endl;
	}
	for(int r=0;r<block4;r++)
	{
		outFile << S1ListResultCopy[3][r] << endl;
	}
//S2
	for(int r=0;r<block12;r++)
	{
		outFile << S2ListResultCopy[0][r] << endl;
	}
	for(int r=0;r<block22;r++)
	{
		outFile << S2ListResultCopy[1][r] << endl;
	}
	for(int r=0;r<block32;r++)
	{
		outFile << S2ListResultCopy[2][r] << endl;
	}
	for(int r=0;r<block42;r++)
	{
		outFile << S2ListResultCopy[3][r] << endl;
	}
	

	outFile.close();
}
