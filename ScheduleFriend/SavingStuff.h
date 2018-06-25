#pragma once
using namespace std;

ref class SavingStuff
{
public:
	SavingStuff(void);
	void saveCheckPoint(int);
	void loadCheckPoint(int &);
	void saveCourseList(int, vector<string> &);
	void loadCourseList(int, vector<string> &);
	void saveTeacherList(int, vector<string> &);
	void loadTeacherList(int, vector<string> &);
	void saveGradeSizes(vector<int> &);
	void loadGradeSizes(vector<int> &);
	void saveStudentGradeList(vector<int>, vector<vector<string>> &);
	void loadStudentGradeList(vector<int>, vector<vector<string>> &);
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
	void loadResults(int, int, int, int, int, int, int, int, vector<vector<string>> &, vector<vector<string>> &);
	void saveResults(int, int, int, int, int, int, int, int, vector<vector<string>> &, vector<vector<string>> &);
	void loadResultsCopy(int, int, int, int, int, int, int, int, vector<vector<string>> &, vector<vector<string>> &);
	void saveResultsCopy(int, int, int, int, int, int, int, int, vector<vector<string>> &, vector<vector<string>> &);

private:
	int num;
	int counter;
	int counter2;
	int classNum;
};
