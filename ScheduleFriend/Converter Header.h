#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
using namespace std;

class Convertor 
{
public:
	//Convertor();
	string StdIntToStdString(int);
	int StdStringToStdInt(string);
	bool VectorSpaceAvailable(vector<int>, int);
	void TroubleShoot(int, int, int, int, int, vector<vector<string>>);
	string NameToID(string, vector<vector<string>>, vector<vector<string>>);
	string IDToName(string, vector<vector<string>>, vector<vector<string>>);
	string IDToTeacher(string, vector<vector<string>>, vector<vector<string>>);
	string IDToSize(string, vector<vector<string>>, vector<vector<string>>);
private:
};

//Convertor::Convertor()
//{
	//int integer;
	//int counter;
	//string mystring;
//}
string Convertor::StdIntToStdString(int integer)
{
	ostringstream convert;
	convert << integer;
	string mystring = convert.str();
	return mystring;
}
int Convertor::StdStringToStdInt(std::string mystring)
{
	int integer = atoi(mystring.c_str());
	return integer;
}
bool Convertor::VectorSpaceAvailable(std::vector<int> ID, int row)
{ //If ComboVector Has and Space 
	int counter = 0;
	for(int integer=0;integer<row;integer++)
	{
		if(std::find(ID.begin(), ID.end(), integer) == ID.end())
		{
			counter = counter +1;
		}
	}
	if(counter > 0)
		return true;
	else if(ID.size() == 0)
		 return true;
	else
		return false;
}
void Convertor::TroubleShoot(int newI, int newI2, int c2, int c3, int c, vector<vector<string>> SCList)
{
		if(newI == 90 || newI2 == 90)
		{
			ofstream outFile;
			outFile.open("Troubleshooting.dat", ios::app);
			outFile << SCList[c2][c] << " , " << SCList[c3][c] <<  " , " << c << " , " << c2 << " , " << c3 << endl;  //not once does it equal 90!!! where are these values coming from!!!
			outFile.close();
		}
}



string Convertor::NameToID(std::string name, std::vector<vector<string>> SelectedClassList, std::vector<vector<string>> SElist)
{
	vector<string>::iterator it;
	int integer;
	if(std::find(SelectedClassList[0].begin(), SelectedClassList[0].end(), name) != SelectedClassList[0].end())
	{  
		it=find(SelectedClassList[0].begin(),SelectedClassList[0].end(), name);
		integer = it - SelectedClassList[0].begin();
		return SelectedClassList[2][integer];
	}
	else
	{
		it=find(SElist[0].begin(),SElist[0].end(), name);  
		integer = it - SElist[0].begin();
		return SElist[2][integer];
	}
}
string Convertor::IDToName(std::string id, std::vector<vector<string>> SelectedClassList, std::vector<vector<string>> SElist)
{
	int size = id.size();
	int integer;
	vector<string>::iterator it;
	if(size < 4)
	{
		it=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), id);  
		integer = it - SelectedClassList[2].begin();
		return SelectedClassList[0][integer];
	}
	else
	{
		it=find(SElist[2].begin(),SElist[2].end(), id);  
		integer = it - SElist[2].begin();
		return SElist[0][integer];
	}
}
string Convertor::IDToTeacher(std::string id, std::vector<vector<string>> SelectedClassList, std::vector<vector<string>> SElist)
{
	int size = id.size();
	int integer;
	vector<string>::iterator it;
	if(size < 4)
	{
		it=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), id);  
		integer = it - SelectedClassList[2].begin();
		return SelectedClassList[5][integer];
	}
	else
	{
		it=find(SElist[2].begin(),SElist[2].end(), id);  
		integer = it - SElist[2].begin();
		return SElist[4][integer];
	}
}
string Convertor::IDToSize(std::string id, std::vector<vector<string>> SelectedClassList, std::vector<vector<string>> SElist)
{
	int size = id.size();
	int integer;
	vector<string>::iterator it;
	if(size < 4)
	{
		it=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), id);  
		integer = it - SelectedClassList[2].begin();
		return SelectedClassList[3][integer];
	}
	else
	{
		it=find(SElist[2].begin(),SElist[2].end(), id);  
		integer = it - SElist[2].begin();
		return SElist[3][integer];
	}
}