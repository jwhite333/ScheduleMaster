#pragma once
using namespace std;

ref class BehindTheScenes
{
public:
	BehindTheScenes(void);
	void AddCourse(string, string, string, string, string, string, vector<string> &, vector<vector<string>> &, vector<vector<string>> &, int &, int &, int &);
	void RemoveCourse(int, vector<string> &, vector<vector<string>> &, vector<vector<string>> &, int &, int &, int &);
	void AddStudent(string, string, int, vector<vector<string>> &, vector<vector<string>> &, vector<vector<string>> &, vector<vector<string>> &, vector<vector<string>> &, vector<int> &, vector<string> &, int &);
	void LoadStudent(string, vector<vector<string>> &, vector<vector<string>> &, vector<string> &, vector<vector<string>> &, vector<vector<string>> &, vector<string> &, int);
	void DeleteStudent(string, string, int, vector<vector<string>> &, vector<vector<string>> &, vector<vector<string>> &, vector<int> &, int &);
	void AddTeacher(string, vector<string> &, int &);
	void DeleteTeacher(int, vector<string> &, int &);

private:
	int numCreds;
	int IDnum;
};
