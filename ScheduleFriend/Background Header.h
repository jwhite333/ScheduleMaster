using namespace std;
#include "Converter Header.h"

class Background
{
public:
	Background();
	void AddCourse(string, string, int, int, vector<string> &, vector<vector<string>> &, vector<vector<string>> &, int &, int &, int &);
	void RemoveCourse(int, vector<string> &, vector<vector<string>> &, vector<vector<string>> &, int &, int &, int &);
	//void AddStudent(int, vector<vector<string>> &);
	//void RemoveStudent(int, vector<vector<string>> &);
private:
	int numCreds;
	int IDnum;
	string name;
};

Background::Background()
{
}

void Background::AddCourse(string className, string department, int credits, int semester, vector<string> &CourseList, vector<vector<string>> &ClassList, vector<vector<string>> &Elist, int &TotalCourses, int &TotalClasses, int &TotalElectives)
{
	// Fix any issues with Capitalization
	transform(className.begin(), className.end(), className.begin(), tolower);
	className[0]= toupper(className[0]);
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
	}
	// Add to CourseList
	Convertor CV;
	CourseList.push_back(department+ "- "+ className+ "- "+ CV.StdIntToStdString(credits)+ " Creds");
	TotalCourses= CourseList.size();
	// Create new Elective Course in Elist
	if(credits == 3)
	{
		// Get size of Elist for IDnum
		IDnum= Elist[0].size();
		// Create new Elective with name, dept, ID, # of Student, and Semester Preference
		Elist[0].push_back(className);
		Elist[1].push_back(department);
		Elist[2].push_back(CV.StdIntToStdString(IDnum));
		Elist[3].push_back("0");
		Elist[4].push_back(CV.StdIntToStdString(semester));
		TotalElectives= Elist[0].size();
	}
	// Create new Full Block Course in ClassList
	else
	{
		// Get size of ClassList for IDnum
		IDnum= ClassList[0].size();
		// Create new Course with name, dept, ID, and Semester Preference
		ClassList[0].push_back(className);
		ClassList[1].push_back(department);
		ClassList[2].push_back(CV.StdIntToStdString(IDnum));
		ClassList[3].push_back("0");
		if(credits == 12)
		{
			// Set Semester Preference for AP course to 1
			ClassList[4].push_back("1");
			// Create other half of AP Course with opposite Semester Preference
			ClassList[0].push_back(className);
			ClassList[1].push_back(department);
			ClassList[2].push_back(CV.StdIntToStdString(IDnum));
			ClassList[3].push_back("0");
			ClassList[4].push_back("2");
			TotalClasses= ClassList[0].size();
		}
		else
		{
			ClassList[4].push_back(CV.StdIntToStdString(semester));
			TotalClasses= ClassList[0].size();
		}
	}
}
void Background::RemoveCourse(int deletedCourse, vector<string> &CourseList, vector<vector<string>> &ClassList, vector<vector<string>> &Elist, int &TotalCourses, int &TotalClasses, int &TotalElectives)
{
	// Search for # of credits to decide which vector to search
	string name= CourseList[deletedCourse];
	for (int spaceLocator = 0; spaceLocator < name.size(); spaceLocator++)
	{
		if (name[spaceLocator] == 'C' && name[spaceLocator+ 1] == 'r' && name[spaceLocator+ 2] == 'e'
			&& name[spaceLocator+ 3] == 'd' && name[spaceLocator+ 4] == 's')
			{
				int numCreds= name[spaceLocator -2];
			}
	}
	for(int counter = deletedCourse;counter < TotalCourses -1;counter++)
		{
			CourseList[counter]= CourseList[counter+ 1];
		}
	TotalCourses--;
	CourseList.resize(TotalCourses);
	if(numCreds == 3)
	{
		// Move all Course Information after this point over
		for(int counter = deletedCourse;counter < TotalElectives -1;counter++)
		{
			Elist[0][counter]= Elist[0][counter+ 1];
			Elist[1][counter]= Elist[1][counter+ 1];
			Elist[3][counter]= Elist[3][counter+ 1];
			Elist[4][counter]= Elist[4][counter+ 1];
		}
		// Resize vector to remove extra point
		TotalElectives--;
		Elist[0].resize(TotalElectives);
	}
	else
	{
		// Move all Course Information after this point over
		for(int counter = deletedCourse;counter < TotalClasses -1;counter++)
		{
			ClassList[0][counter]= ClassList[0][counter+ 1];
			ClassList[1][counter]= ClassList[1][counter+ 1];
			ClassList[3][counter]= ClassList[3][counter+ 1];
			ClassList[4][counter]= ClassList[4][counter+ 1];
			// Move the Course Information over again so there's not still a class
			if(numCreds == 2)
			{
				ClassList[0][counter]= ClassList[0][counter+ 1];
				ClassList[1][counter]= ClassList[1][counter+ 1];
				ClassList[3][counter]= ClassList[3][counter+ 1];
				ClassList[4][counter]= ClassList[4][counter+ 1];
			}
		}
		// Resize vector to remove extra point
		TotalClasses--;
		ClassList[0].resize(TotalClasses);
		if(numCreds == 12)
		{
			TotalClasses--;
			ClassList[0].resize(TotalClasses);
		}
	}
}