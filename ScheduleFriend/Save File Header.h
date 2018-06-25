#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class SaveFile
{
public:
	//SaveFile();
	void saveCourseList(int, vector<string> &);
	void loadCourseList(int, vector<string> &);
	void saveClassList(int, vector<vector<string>> &);
	void loadClassList(int, vector<vector<string>> &);
	void saveElist(int, vector<vector<string>> &);
	void loadElist(int, vector<vector<string>> &);
	void loadStudentList(int, vector<vector<string>> &);
	void saveStudentList(int, vector<vector<string>> &);
	void loadStudentEList(int, vector<vector<string>> &);
	void saveStudentEList(int, vector<vector<string>> &);
	void loadSizes(int &, int &, int &, int &, int &);
	void saveSizes(int, int, int, int, int);
	void loadSelectedClassList(int, vector<vector<string>> &);
	void saveSelectedClassList(int, vector<vector<string>> &);
	void loadSelectedEList(int, vector<vector<string>> &);
	void saveSelectedEList(int, vector<vector<string>> &);
	void loadStudentCombinedList(int, vector<vector<string>> &);
	void saveStudentCombinedList(int, vector<vector<string>> &);
	void saveTeacherList(int, vector<string> &);
	void loadTeacherList(int, vector<string> &);

private:
	vector<vector<string>> ClassList;
	vector<vector<string>> Slist;
	vector<vector<string>> Elist;
	vector<vector<vector<string>>> StudentList;
	vector<vector<vector<string>>> StudentEList;
};


//SaveFile::SaveFile()
//{
//	std::vector<vector<string>> Slist;
//	std::vector<vector<string>> ClassList;
//	std::vector<vector<string>> Elist;
//}


//
void SaveFile::saveClassList(int TotalClasses, vector<vector<string>> &ClassList)
{
	ofstream outFile;
	outFile.open("ClassList.dat");
	int num= 0;
	int counter;
	while (num < TotalClasses)
	{
		counter= 0;
		while (counter < 10)
		{
			outFile << ClassList[counter][num] << endl;
			counter= counter+1;
		}
		num= num+1;
	}
	outFile.close();
}
void SaveFile::loadClassList(int TotalClasses, vector<vector<string>> &ClassList)
{
	ifstream inFile;
	inFile.open("ClassList.dat");
	int num= 0;
	int counter2;
	ClassList.resize(4);
	for(int counter=0;counter<4;counter++)
	{
		ClassList[counter].resize(TotalClasses);
	}
	while (num < TotalClasses)
	{
		counter2= 0;
		while (counter2 < 4)
		{
			getline(inFile, ClassList[counter2][num]);
			counter2= counter2+1;
		}
		num= num+1;
	}
	inFile.close();
}
//
void SaveFile::saveElist(int TotalElectives, vector<vector<string>> &Elist)
{
	ofstream outFile;
	outFile.open("Elist.dat");
	int num= 0;
	int counter;
	while (num < TotalElectives)
	{
		counter= 0;
		while (counter < 5)
		{
			outFile << Elist[counter][num] << endl;
			counter= counter+1;
		}
		num= num+1;
	}
	outFile.close();
}
void SaveFile::loadElist(int TotalElectives, vector<vector<string>> &Elist)
{
	ifstream inFile;
	inFile.open("Elist.dat");
	int num= 0;
	Elist.resize(5);
	Elist[0].resize(TotalElectives);
	Elist[1].resize(TotalElectives);
	Elist[2].resize(TotalElectives);
	Elist[3].resize(TotalElectives);
	Elist[4].resize(TotalElectives);

	int counter;
	for(num;num<TotalElectives;num++)
	{
		counter= 0;
		for(counter;counter<5;counter++)
		{
			getline(inFile, Elist[counter][num]);
		}
	}
	inFile.close();
}
//
void SaveFile::saveStudentEList(int TotalStudents, vector<vector<string>> &StudentEList)
{
	ofstream outFile;
	outFile.open("StudentEList.dat");
	for(int counter=0;counter<TotalStudents;counter++)
	{
		for(int num=0;num<18;num++)
		{
			outFile << StudentEList[num][counter] << endl;
		}
	}
	outFile.close();
}
void SaveFile::loadStudentEList(int TotalStudents, vector<vector<string>> &StudentEList)
{
	ifstream inFile;
	inFile.open("StudentEList.dat");
	StudentEList.resize(18);
	for(int r=0;r<18;r++)
	{
		StudentEList[r].resize(TotalStudents);
	}
	for(int counter=0;counter<TotalStudents;counter++)
	{
		for(int num=0;num<18;num++)
		{
			getline(inFile, StudentEList[num][counter]);
		}
	}
	inFile.close();
}
//
void SaveFile::saveSizes(int TotalClasses, int TotalElectives, int TotalStudents, int TotalCourses, int TotalTeachers)
{
	ofstream outFile;
	outFile.open("ClassSizes.dat");

	outFile << TotalClasses << endl << TotalElectives << endl << TotalStudents << endl << TotalCourses << endl << TotalTeachers;

	outFile.close();
}
void SaveFile::loadSizes(int &TotalClasses, int &TotalElectives, int &TotalStudents, int &TotalCourses, int &TotalTeachers)
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
void SaveFile::saveSelectedClassList(int TotalClasses, vector<vector<string>> &SelectedClassList)
{
	ofstream outFile;
	outFile.open("SelectedClassList.dat");
	for(int counter=0;counter<TotalClasses;counter++)
	{
		for(int num=0;num<6;num++)
		{
			outFile << SelectedClassList[num][counter] << endl;
		}
	}
	outFile.close();
}
void SaveFile::loadSelectedClassList(int TotalClasses, vector<vector<string>> &SelectedClassList)
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

	for(int counter=0;counter<TotalClasses;counter++)
	{
		for(int num=0;num<6;num++)
		{
			getline(inFile, SelectedClassList[num][counter]);
		}
	}
	inFile.close();
}

//
void SaveFile::saveSelectedEList(int TotalElectives, vector<vector<string>> &SElist)
{
	ofstream outFile;
	outFile.open("SelectedEList.dat");
	for(int counter=0;counter<TotalElectives;counter++)
	{
		for(int num=0;num<5;num++)
		{
			outFile << SElist[num][counter] << endl;
		}
	}
	outFile.close();
}
void SaveFile::loadSelectedEList(int TotalElectives, vector<vector<string>> &SElist)
{
	ifstream inFile;
	inFile.open("SelectedEList.dat");
	SElist.resize(5);
	SElist[0].resize(TotalElectives);
	SElist[1].resize(TotalElectives);
	SElist[2].resize(TotalElectives);
	SElist[3].resize(TotalElectives);
	SElist[4].resize(TotalElectives);

	for(int counter=0;counter<TotalElectives;counter++)
	{
		for(int num=0;num<5;num++)
		{
			getline(inFile, SElist[num][counter]);
		}
	}
	inFile.close();
}
//
void SaveFile::saveStudentList(int TotalStudents, vector<vector<string>> &StudentList)
{
	ofstream outFile;
	outFile.open("StudentList.dat");
	for(int counter=0;counter<TotalStudents;counter++)
	{
		for(int num=0;num<10;num++)
		{
			outFile << StudentList[num][counter] << endl;
		}
	}
	outFile.close();
}
void SaveFile::loadStudentList(int TotalStudents, vector<vector<string>> &StudentList)
{
	ifstream inFile;
	inFile.open("StudentList.dat");
	StudentList.resize(10);
	for(int r=0;r<10;r++)
	{
		StudentList[r].resize(TotalStudents);
	}
	for(int counter=0;counter<TotalStudents;counter++)
	{
		for(int num=0;num<10;num++)
		{
			getline(inFile, StudentList[num][counter]);
		}
	}
	inFile.close();
}
//
void SaveFile::saveStudentCombinedList(int TotalStudents, vector<vector<string>> &StudentEList)
{
	ofstream outFile;
	outFile.open("StudentCombinedList.dat");
	for(int counter=0;counter<TotalStudents;counter++)
	{
		for(int num=0;num<18;num++)
		{
			outFile << StudentEList[num][counter] << endl;
		}
	}
	outFile.close();
}
void SaveFile::loadStudentCombinedList(int TotalStudents, vector<vector<string>> &StudentEList)
{
	ifstream inFile;
	inFile.open("StudentCombinedList.dat");
	StudentEList.resize(18);
	for(int r=0;r<18;r++)
	{
		StudentEList[r].resize(TotalStudents);
	}
	for(int counter=0;counter<TotalStudents;counter++)
	{
		for(int num=0;num<18;num++)
		{
			getline(inFile, StudentEList[num][counter]);
		}
	}
	inFile.close();
}
//
void SaveFile::saveCourseList(int TotalCourses, vector<string> &CourseList)
{
	ofstream outFile;
	outFile.open("CourseList.dat");
	int num= 0;
	while (num < TotalCourses)
	{
		outFile << CourseList[num] << endl;
		num= num+1;
	}
	outFile.close();
}
void SaveFile::loadCourseList(int TotalCourses, vector<string> &CourseList)
{
	ifstream inFile;
	inFile.open("CourseList.dat");
	int num= 0;
	while (num < TotalCourses)
	{
		getline(inFile, CourseList[num]);
		num= num+1;
	}
	inFile.close();
}
//
void SaveFile::saveTeacherList(int TotalTeachers, vector<string> &TeacherList)
{
	ofstream outFile;
	outFile.open("TeacherList.dat");
	int num= 0;
	while (num < TotalTeachers)
	{
		outFile << TeacherList[num] << endl;
		num= num+1;
	}
	outFile.close();
}
void SaveFile::loadTeacherList(int TotalTeachers, vector<string> &TeacherList)
{
	ifstream inFile;
	inFile.open("TeacherList.dat");
	int num= 0;
	while (num < TotalTeachers)
	{
		getline(inFile, TeacherList[num]);
		num= num+1;
	}
	inFile.close();
}
//