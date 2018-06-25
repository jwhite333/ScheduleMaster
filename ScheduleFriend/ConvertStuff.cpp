#include "StdAfx.h"
#include "ConvertStuff.h"
using namespace std;

ConvertStuff::ConvertStuff(void)
{
}
string ConvertStuff::StdIntToStdString(int integer)
{
	ostringstream convert;
	convert << integer;
	string mystring = convert.str();
	return mystring;
}
int ConvertStuff::StdStringToStdInt(string mystring)
{
	int integer = atoi(mystring.c_str());
	return integer;
}
bool ConvertStuff::VectorSpaceAvailable(vector<int> ID, int row)
{ //If ComboVector Has and Space 
	counter = 0;
	vector<string>::iterator it;
	for(int integer=0;integer<row;integer++)
	{
		if(find(ID.begin(), ID.end(), integer) == ID.end())
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

string ConvertStuff::NameToID(std::string name, std::vector<vector<string>> SelectedClassList, std::vector<vector<string>> SElist)
{
	int integer;
	vector<string>::iterator it;
	if(std::find(SelectedClassList[0].begin(), SelectedClassList[0].end(), name) != SelectedClassList[0].end())
	{  
		it=find(SelectedClassList[0].begin(),SelectedClassList[0].end(), name);
		int integer = it - SelectedClassList[0].begin();
		return SelectedClassList[2][integer];
	}
	else
	{
		it=find(SElist[0].begin(),SElist[0].end(), name);  
		integer = it - SElist[0].begin();
		return SElist[2][integer];
	}
}
string ConvertStuff::IDToName(std::string id, std::vector<vector<string>> SelectedClassList, std::vector<vector<string>> SElist)
{
	int integer;
	vector<string>::iterator it;
	int size = id.size();
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
string ConvertStuff::IDToTeacher(std::string id, std::vector<vector<string>> SelectedClassList, std::vector<vector<string>> SElist)
{
	int integer;
	vector<string>::iterator it;
	int size = id.size();
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
string ConvertStuff::IDToSize(std::string id, std::vector<vector<string>> SelectedClassList, std::vector<vector<string>> SElist)
{
	int integer;
	vector<string>::iterator it;
	int size = id.size();
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
string ConvertStuff::EIDToName(std::string id, std::vector<vector<string>> SElist)
{
	int integer;
	vector<string>::iterator it;
	int size = id.size();

	it=find(SElist[2].begin(),SElist[2].end(), id);  
	integer = it - SElist[2].begin();
	return SElist[0][integer];
}