using namespace std;
#include "Converter2Header.h"
//#include "Save File Header.h"

namespace ScheduleFriend
{
public class Module
{
public:
	Module();
	void SortElectives();
	void PairEveryOtherDayClasses();
	void ReverseSortAllClassesIntoSemesters();
	void SortS1IntoBlocks();
	void SortS2IntoBlocks();
	void GetResults();
	void Scoring();
private:
	std::vector< vector<string> > Elist;
	std::vector< vector<string> > SElist;
	std::vector<int> IDs;
	std::vector<int> IDs2;
	std::vector<string> IDss;
	std::vector<string> IDss2;
	std::vector<string> ComboID;
	std::vector<vector<int> > SortedElist;
	std::vector<vector<int> > SortedRlist;
	std::vector<vector<int> > SortedSlist;
	vector<vector<string>> StudentList;
	vector<vector<string>> StudentEList;
	vector<vector<string>> StudentCombinedList;
	vector<vector<string>> ClassList;
	vector<vector<string>> SelectedClassList;
	vector<vector<string>> S1List;
	vector<vector<string>> S1ListCopy;
	vector<vector<string>> S1ListInt;
	vector<vector<string>> S2List;
	vector<vector<string>> S2ListCopy;
	vector<vector<string>> S2ListInt;
	vector<vector<string>> S1ListResult;
	vector<vector<string>> S2ListResult;
	vector<vector<string>> S1ListElectiveResult;
	vector<vector<string>> S2ListElectiveResult;
	vector<vector<string>> S1ListResultCopy;
	vector<vector<string>> S2ListResultCopy;
	vector<vector<string>> S1ListElectiveResultCopy;
	vector<vector<string>> S2ListElectiveResultCopy;
	std::vector<string> ClassCombos;
	int TotalClasses;
	int TotalElectives;
	int TotalStudents;

	std::vector<vector<int>> ComboVector;
	std::vector<vector<int>> ComboVector2;
	std::vector<vector<int>> ComboVector3;
	std::vector<vector<int>> ComboVectorInt; 
	std::vector<vector<int>> RemovedElectiveCombo;

};

Module::Module()
{
}
void Module::SortElectives()
{
	vector<string>::iterator iter;
	ConvertorTwo DV;
	int SSsize = SElist[0].size();
	cout<< "Calculating" << endl;
	for(int S=0;S<SSsize;S++)
	{
		SElist[3][S] = "0";
	}

	for(int counter1=0;counter1<TotalStudents;counter1++)  
	{
		for(int counter2=2;counter2<18;counter2++)
		{
			int E = DV.StdStringToStdInt(StudentEList[counter2][counter1]);
			if (E == 9999)
				break;
			iter=find(SElist[2].begin(),SElist[2].end(), DV.StdIntToStdString(E));
			int newE = iter - SElist[2].begin();
			int newSize = DV.StdStringToStdInt(SElist[3][newE]) + 1;
			SElist[3][newE] = DV.StdIntToStdString(newSize);
		}
	}

	int Ebigness = SElist[0].size();
	int c = 0;
	int x = 0;
	int convertedInt1E;
	int convertedInt2E;
	string swapE;
	string swap2E;
	string swap3E;
	string swap4E;
	string swap5E;
	bool swapping = true;



	if(Ebigness > 1)
	{
		while(swapping == true)
		{
			swapping = false;
			for(x = 0; x<(Ebigness-1); x++)
			{
				ConvertorTwo DV;
				convertedInt1E = DV.StdStringToStdInt(SElist[3][x]);
				convertedInt2E = DV.StdStringToStdInt(SElist[3][x+1]);
				
				if(convertedInt1E < convertedInt2E)
				{
					swapE = SElist[0][x];
					swap2E = SElist[1][x];
					swap3E = SElist[2][x];
					swap4E = SElist[3][x];
					swap5E = SElist[4][x];
					SElist[0][x] = SElist[0][x+1];
					SElist[1][x] = SElist[1][x+1];
					SElist[2][x] = SElist[2][x+1];
					SElist[3][x] = SElist[3][x+1];
					SElist[4][x] = SElist[4][x+1];
					SElist[0][x+1] = swapE;
					SElist[1][x+1] = swap2E;
					SElist[2][x+1] = swap3E;
					SElist[3][x+1] = swap4E;
					SElist[4][x+1] = swap5E;
					swapping = true;
				}
			}
		}  
	} 
}
void Module::PairEveryOtherDayClasses()
{
	ConvertorTwo DV;
	int SEsize;
	SEsize = SElist[0].size();
	int width = SEsize;
	int height = SEsize;
	int IDsUsed = 0;
	ComboVector.resize(height);
	for(int c=0;c<height;c++)
	{
		ComboVector[c].resize(width);
	}
	int StudentEsize = StudentEList[0].size();
	vector<string>::iterator it;
	for(int c=0;c<StudentEsize;c++)
	{
		for(int c2=2;c2<17;c2++)
		{
			
			if(StudentEList[c2][c] == "9999")
				break;
			for(int c3=c2+1;c3<18;c3++)
			{
				
				ConvertorTwo DV;
				int I = DV.StdStringToStdInt(StudentEList[c2][c]); 
				int I2 = DV.StdStringToStdInt(StudentEList[c3][c]);
				it=find(SElist[2].begin(),SElist[2].end(), DV.StdIntToStdString(I));
				int newI = it - SElist[2].begin();
				it=find(SElist[2].begin(),SElist[2].end(), DV.StdIntToStdString(I2));
				int newI2 = it - SElist[2].begin();

				if(StudentEList[c3][c] == "9999")
					break;
				if(SElist[4][newI] == SElist[4][newI2])
				{
					int size = DV.StdStringToStdInt(SElist[3][newI]);
					if(DV.StdStringToStdInt(SElist[3][newI2]) > DV.StdStringToStdInt(SElist[3][newI]))
						size = DV.StdStringToStdInt(SElist[3][newI2]);
					ComboVector[newI][newI2] = size; //9999
					ComboVector[newI2][newI] = size;
				}
				else 
				{
					ComboVector[newI][newI2] = (ComboVector[newI][newI2]+1);
					ComboVector[newI2][newI] = (ComboVector[newI2][newI]+1);
				}		
			}
		}	
	}
	int size = ComboVector[0].size();
	for(int nineSet=0;nineSet<size;nineSet++)
	{
		ComboVector[nineSet][nineSet] = 9999;
	}

	for(int student1=0;student1<TotalStudents;student1++)
	{
		for(int student2=2;student2<18;student2++)
		{
			if(StudentEList[student2][student1] != "9999")
				StudentEList[student2][student1] = "000" + StudentEList[student2][student1];
			else
				break;
		}
	}
	int stop = SElist[0].size();
	for(int schange=0;schange<stop;schange++)
	{
		SElist[2][schange] = "000" + SElist[2][schange];
	}
	for(int set=0;set<TotalStudents;set++)
	{
		for(int set2=0;set2<18;set2++)
		{
			if(set2 < 10)
				StudentCombinedList[set2][set] = StudentList[set2][set];
			else
				StudentCombinedList[set2][set] = "9999";
		}
	}
	vector<string>::iterator iter;
	for(int set3=0;set3<TotalStudents;set3++)
	{
		for(int set4=2;set4<18;set4++)
		{
			if(StudentEList[set4][set3] != "0009999")
			{
				for(int find9s=2;find9s<18;find9s++)
				{
					if(StudentCombinedList[find9s][set3] == "9999")
					{
						StudentCombinedList[find9s][set3] = StudentEList[set4][set3];
						break;
					}
				}
			}
			else
				break;
		}
	}
	SortedElist[0].resize(0);
	SortedElist[1].resize(0);
	IDs.resize(0);
	for(int row=1;row<height;row++)
	{
		if(std::find(IDs.begin(), IDs.end(), row) == IDs.end())
		{
			ConvertorTwo DV;
			if(DV.VectorSpaceAvailable(IDs, row) == true)
			{
				int search = 0;
				int Initialvalue = -1;
				int CurrentValue = Initialvalue;
				int id1 = row;
				int id2 = search;
				for(search;search<row;search++)
				{
					if(ComboVector[row][search] > CurrentValue && std::find(IDs.begin(), IDs.end(), search) == IDs.end())
					{
						CurrentValue = ComboVector[row][search];
						id1 = row;
						id2 = search;
					}
				}
				SortedElist[0].push_back(DV.StdStringToStdInt(SElist[2][id1]));
				SortedElist[1].push_back(DV.StdStringToStdInt(SElist[2][id2]));
				IDs.push_back(id1);
				IDs.push_back(id2);
			}
			else if(DV.VectorSpaceAvailable(IDs, row) == false && row == height-1)
			{
				SortedElist[0].push_back(DV.StdStringToStdInt(SElist[2][row]));
				SortedElist[1].push_back(9999);
				IDs.push_back(row);
			}
		}	
	}
}
void Module::ReverseSortAllClassesIntoSemesters()
{
	SaveFile SF;
	vector<string>::iterator iter;
	vector<string>::iterator iterAP;
	ConvertorTwo DV;
	int SSsize = SElist[0].size();
	for(int S=0;S<SSsize;S++)
	{
		SelectedClassList[3][S] = "0";
	}
	for(int counter1=0;counter1<TotalStudents;counter1++) 
	{
		for(int counter2=2;counter2<10;counter2++)
		{
			int C = DV.StdStringToStdInt(StudentList[counter2][counter1]);
			if (C == 9999)
				break;
			iter=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), DV.StdIntToStdString(C));  
			int newC = iter - SelectedClassList[2].begin();
			int newSize = DV.StdStringToStdInt(SelectedClassList[3][newC]) + 1;
			SelectedClassList[3][newC] = DV.StdIntToStdString(newSize);     
			int placement = newC;
			int end = SelectedClassList[0].size();
			for(int findAP=newC+1;findAP<end;findAP++)
			{
				placement = placement + 1;
				if ( SelectedClassList[2][findAP] == DV.StdIntToStdString(C))
				{
					int newC2 = placement;
					int newSize2 = DV.StdStringToStdInt(SelectedClassList[3][newC2]) + 1;
					SelectedClassList[3][newC2] = DV.StdIntToStdString(newSize2);
				}
			}
		}
	}
	int startNewIDs = DV.StdStringToStdInt(SelectedClassList[2][0]);
	int Ssize2 = SElist[0].size();
	for(int c=0;c<Ssize2;c++)
	{
		if(DV.StdStringToStdInt(SelectedClassList[2][c]) > startNewIDs)
			startNewIDs = DV.StdStringToStdInt(SelectedClassList[2][c]);
	}
	startNewIDs = startNewIDs + 1;
	int counter = SortedElist[0].size();
	vector<string>::iterator it;
	for(int c=0;c<counter;c++)
	{
		string I = "000" + DV.StdIntToStdString(SortedElist[0][c]);					
		string I2 = "000" + DV.StdIntToStdString(SortedElist[1][c]);
		it=find(SElist[2].begin(),SElist[2].end(), I);
		int newI = it - SElist[2].begin();
		it=find(SElist[2].begin(),SElist[2].end(), I2);
		int newI2 = it - SElist[2].begin();
		if (I2 == "0009999")
		{
			SelectedClassList[0].push_back(SElist[0][newI]);
			SelectedClassList[1].push_back(SElist[1][newI]);
			SelectedClassList[2].push_back(SElist[2][newI]);
			SelectedClassList[3].push_back(SElist[3][newI]);
			SelectedClassList[4].push_back("0");
			SelectedClassList[5].push_back(SElist[4][newI]);
			break;
		}
		SelectedClassList[0].push_back(SElist[0][newI] + "/" + SElist[0][newI2]);					
		SelectedClassList[1].push_back(SElist[1][newI] + "/" + SElist[1][newI2]);
		SelectedClassList[2].push_back(SElist[2][newI] + "," + SElist[2][newI2]);	
		int IntersectStudents = ComboVector[newI][newI2];
		int Student1 = DV.StdStringToStdInt(SElist[3][newI]);
		int Student2 = DV.StdStringToStdInt(SElist[3][newI2]);
		int BothStudents = Student1 + Student2;
		SelectedClassList[3].push_back(DV.StdIntToStdString(BothStudents-IntersectStudents));
		SelectedClassList[4].push_back("0");
		SelectedClassList[5].push_back(SElist[4][newI] + "/" + SElist[4][newI2]);
		startNewIDs = startNewIDs +1;
	}
	int bigness = SelectedClassList[0].size();
	int c = 0;
	int x = 0;
	int convertedInt1;
	int convertedInt2;
	string swap;
	string swap2;
	string swap3;
	string swap4;
	string swap5;
	string swap6;
	bool swapping = true;

	if(bigness > 1)
	{
		while(swapping == true)
		{
			swapping = false;
			for(x = 0; x<bigness-1; x++)
			{
				convertedInt1 = DV.StdStringToStdInt(SelectedClassList[3][x]);
				convertedInt2 = DV.StdStringToStdInt(SelectedClassList[3][x+1]);
				if(convertedInt1 < convertedInt2)
				{
					swap = SelectedClassList[0][x];
					swap2 = SelectedClassList[1][x];
					swap3 = SelectedClassList[2][x];
					swap4 = SelectedClassList[3][x];
					swap5 = SelectedClassList[4][x];
					swap6 = SelectedClassList[5][x];
					SelectedClassList[0][x] = SelectedClassList[0][x+1];
					SelectedClassList[1][x] = SelectedClassList[1][x+1];
					SelectedClassList[2][x] = SelectedClassList[2][x+1];
					SelectedClassList[3][x] = SelectedClassList[3][x+1];
					SelectedClassList[4][x] = SelectedClassList[4][x+1];
					SelectedClassList[5][x] = SelectedClassList[5][x+1];
					SelectedClassList[0][x+1] = swap;
					SelectedClassList[1][x+1] = swap2;
					SelectedClassList[2][x+1] = swap3;
					SelectedClassList[3][x+1] = swap4;
					SelectedClassList[4][x+1] = swap5;
					SelectedClassList[5][x+1] = swap6;
					swapping = true;
				}
			}
		}
	}
	int SCsize;
	SCsize = SelectedClassList[0].size();
	int width = SCsize;
	int height = SCsize;
	int IDsUsed = 0;
	ComboVector.resize(0);
	ComboVector.resize(height);
	for(int c=0;c<height;c++)
	{
		ComboVector[c].resize(width);
	}    
		SF.loadStudentList(TotalStudents, StudentList);
		int StudentSize = StudentList[0].size();
		vector<string>::iterator APit1;
		vector<string>::iterator APit2;
		int size = SelectedClassList[0].size();
		string idString1 = "";
		string idString2 = "";
		int newI =0;
		int newI2 = 0;

	for(int c=0;c<StudentSize;c++)
	{
		for(int c2=2;c2<17;c2++)
		{
			
			if(StudentCombinedList[c2][c] == "9999" || StudentCombinedList[c2][c] == "0009999")
				break;
			for(int c3=c2+1;c3<18;c3++)
			{
				if(StudentCombinedList[c3][c] == "9999" || StudentCombinedList[c3][c] == "0009999")
					break;
				ConvertorTwo DV;
				string I = StudentCombinedList[c2][c];
				string I2 = StudentCombinedList[c3][c];
				int iSize = I.size();
				if(iSize > 3)
				{
					for(int finder=0;finder<size;finder++)
					{
						if(SelectedClassList[2][finder].find(I, 0) != -1)
						{
							idString1 = SelectedClassList[2][finder];
							break;
						}
					}
					it=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), idString1); APit1 = it;
					newI = it - SelectedClassList[2].begin();
				}
				else
				{
					it=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), I); APit1 = it;
					newI = it - SelectedClassList[2].begin();
				}
				int iSize2 = I2.size();
				if(iSize2 > 3)
				{
					for(int finder2=0;finder2<size;finder2++)
					{
						if(SelectedClassList[2][finder2].find(I2, 0) != -1)
						{
							idString2 = SelectedClassList[2][finder2];
							break;
						}
					}
					it=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), idString2); APit2 = it;
					newI2 = it - SelectedClassList[2].begin();
				}
				else
				{
					it=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), I2); APit2 = it;
					newI2 = it - SelectedClassList[2].begin();
				}
				it=find(APit1+1, SelectedClassList[2].end(), I);
				int newI5 = it - SelectedClassList[2].begin();
				int SCListEnd = SelectedClassList[0].size();
				if(newI5 != SCListEnd)
				{
					int newI3 = it - SelectedClassList[2].begin();
					if(SelectedClassList[5][newI3] == SelectedClassList[5][newI2])
					{
						int size = DV.StdStringToStdInt(SelectedClassList[3][newI3]);
						if(DV.StdStringToStdInt(SelectedClassList[3][newI2]) < DV.StdStringToStdInt(SelectedClassList[3][newI3]))
							size = DV.StdStringToStdInt(SelectedClassList[3][newI2]);
						ComboVector[newI3][newI2] = size;
						ComboVector[newI2][newI3] = size;
					}
					else
					{
						ComboVector[newI3][newI2] = (ComboVector[newI][newI2]+1);
						ComboVector[newI2][newI3] = (ComboVector[newI2][newI]+1);
					}
				}
				it=find(APit2+1, SelectedClassList[2].end(), I2);
				int newI6 = it - SelectedClassList[2].begin();
				if(newI6 != SCListEnd)
				{
					int newI4 = it - SelectedClassList[2].begin();
					if(SelectedClassList[5][newI4] == SelectedClassList[5][newI4])
					{
						int size = DV.StdStringToStdInt(SelectedClassList[3][newI]);
						if(DV.StdStringToStdInt(SelectedClassList[3][newI4]) < DV.StdStringToStdInt(SelectedClassList[3][newI]))
							size = DV.StdStringToStdInt(SelectedClassList[3][newI4]);
						ComboVector[newI][newI4] = size;
						ComboVector[newI4][newI] = size;
					}
					else
					{
						ComboVector[newI][newI4] = (ComboVector[newI][newI2]+1);
						ComboVector[newI4][newI] = (ComboVector[newI2][newI]+1);
					}
				}
				if(SelectedClassList[5][newI] == SelectedClassList[5][newI2])  
				{
					int size2 = DV.StdStringToStdInt(SelectedClassList[3][newI]);
					if(DV.StdStringToStdInt(SelectedClassList[3][newI2]) > DV.StdStringToStdInt(SelectedClassList[3][newI]))
						size2 = DV.StdStringToStdInt(SelectedClassList[3][newI2]);
					ComboVector[newI][newI2] = size2;
					ComboVector[newI2][newI] = size2;
				}
				else 
				{
				ComboVector[newI][newI2] = (ComboVector[newI][newI2]+1);
				ComboVector[newI2][newI] = (ComboVector[newI2][newI]+1);
				}
			}
		}	  
	}
	size = ComboVector[0].size();
	for(int nineSet=0;nineSet<size;nineSet++)
	{
		ComboVector[nineSet][nineSet] = 9999;
	}
	SortedRlist[0].resize(0);
	SortedRlist[1].resize(0);
	IDs.resize(0);
	for(int row=1;row<height;row++)
	{
		if(std::find(IDs.begin(), IDs.end(), row) == IDs.end())
		{
			ConvertorTwo DV;
			if(DV.VectorSpaceAvailable(IDs, row) == true)
			{
				int search = 0;
				int Initialvalue = -1;
				int CurrentValue = Initialvalue;
				int id1 = row;
				int id2 = search;
				for(search;search<row;search++)
				{
					if(ComboVector[row][search] > CurrentValue && std::find(IDs.begin(), IDs.end(), search) == IDs.end())
					{
						CurrentValue = ComboVector[row][search];
						id1 = row;
						id2 = search;
					}
				}
				SortedRlist[0].push_back(id1);
				SortedRlist[1].push_back(id2);
				IDs.push_back(id1);
				IDs.push_back(id2);
			}
			else if(DV.VectorSpaceAvailable(IDs, row) == false && row == height-1)
			{
				SortedRlist[0].push_back(row);
				SortedRlist[1].push_back(9999);
				IDs.push_back(row);
			}
		}	
	}
	int Ssize = SortedRlist[0].size();
	S1List[0].resize(0);
	S1List[1].resize(0);
	S1List[2].resize(0);
	S1List[3].resize(0);
	S2List[0].resize(0);
	S2List[1].resize(0);
	S2List[2].resize(0);
	S2List[3].resize(0);
	int row = 0;
	int column = 0;
	counter = SortedRlist[0].size();
	for(int c=0;c<counter;c++)
	{
		row = SortedRlist[0][c];
		column = SortedRlist[1][c];
		if (column == 9999)
			break;
		int semester1 = DV.StdStringToStdInt(SelectedClassList[4][row]);
		int semester2 = DV.StdStringToStdInt(SelectedClassList[4][column]);
		string nullcheck1 = SelectedClassList[2][row];
		string nullcheck2 = SelectedClassList[2][column];
		if(nullcheck1 != "9999")
		{
			if(semester1 == 1 || semester1 == 0)
			{
				S1List[0].push_back(SelectedClassList[0][row]);
				S1List[1].push_back(SelectedClassList[1][row]);
				S1List[2].push_back(SelectedClassList[2][row]);
				S1List[3].push_back(SelectedClassList[3][row]);
			}
			if(semester1 == 2)
			{
				S2List[0].push_back(SelectedClassList[0][row]);
				S2List[1].push_back(SelectedClassList[1][row]);
				S2List[2].push_back(SelectedClassList[2][row]);
				S2List[3].push_back(SelectedClassList[3][row]);
			}
		}
		if(nullcheck2 != "9999")
		{
			if(semester2 == 1)
			{
				S1List[0].push_back(SelectedClassList[0][column]);
				S1List[1].push_back(SelectedClassList[1][column]);
				S1List[2].push_back(SelectedClassList[2][column]);
				S1List[3].push_back(SelectedClassList[3][column]);
			}
			if(semester2 == 2)
			{
				S2List[0].push_back(SelectedClassList[0][column]);
				S2List[1].push_back(SelectedClassList[1][column]);
				S2List[2].push_back(SelectedClassList[2][column]);
				S2List[3].push_back(SelectedClassList[3][column]);
			}
			if(semester2 == 0 && (semester1 == 1 || semester1 == 0))
			{
				S2List[0].push_back(SelectedClassList[0][column]);
				S2List[1].push_back(SelectedClassList[1][column]);
				S2List[2].push_back(SelectedClassList[2][column]);
				S2List[3].push_back(SelectedClassList[3][column]);
			}
			if(semester2 == 0 && semester1 == 2)
			{
				S1List[0].push_back(SelectedClassList[0][column]);
				S1List[1].push_back(SelectedClassList[1][column]);
				S1List[2].push_back(SelectedClassList[2][column]);
				S1List[3].push_back(SelectedClassList[3][column]);
			}
		}
	}
}
void Module::SortS1IntoBlocks()
{
	ConvertorTwo DV;
	bool vector2 = false;
	int counter = 0;
	int stop = S1List[0].size();
	int HowManySorts = 0;
	int individualSorts; 
	for(int c=4;c<stop;c=c*2)
		HowManySorts = HowManySorts + 1;
	int initialSize = S1List[0].size();
	bool divisBy4;
	if (initialSize != 4*(pow(2.0, HowManySorts-1)))
		divisBy4 = false;
	else
		divisBy4 = true;
	S1ListCopy.resize(S1List.size());
	S1ListCopy[0].resize(S1List[0].size());
	S1ListCopy[1].resize(S1List[0].size());
	S1ListCopy[2].resize(S1List[0].size());
	S1ListCopy[3].resize(S1List[0].size());
	S1ListInt.resize(S1List.size());
	S1ListInt[0].resize(S1List[0].size());
	S1ListInt[1].resize(S1List[0].size());
	S1ListInt[2].resize(S1List[0].size());
	S1ListInt[3].resize(S1List[0].size());
	int size1 = ComboVector.size();
	ComboVector3.resize(size1);
	for(int Schange=0; Schange<size1;Schange++)
	{
		ComboVector3[Schange].resize(size1);
	}
	for(int copy=0;copy<size1;copy++)
	{
		for(int copy2=0;copy2<size1;copy2++)
		{
			ComboVector3[copy][copy2] = ComboVector[copy][copy2];
		}
	}
	for(int sorting=0;sorting<HowManySorts;sorting++)
	{
		int bigness = S1List[0].size();
		int x = 0;
		int convertedInt1;
		int convertedInt2;
		string swap;
		string swap2;
		string swap3;
		string swap4;
		string swap5;
		bool swapping = true;
		if(bigness > 1)
		{
			while(swapping == true)
			{
				swapping = false;
				for(x = 0; x<bigness-1; x++)
				{
					convertedInt1 = DV.StdStringToStdInt(S1List[3][x]);
					convertedInt2 = DV.StdStringToStdInt(S1List[3][x+1]);
					if(convertedInt1 < convertedInt2)
					{
						swap = S1List[0][x];
						swap2 = S1List[1][x];
						swap3 = S1List[2][x];
						swap4 = S1List[3][x];
						S1List[0][x] = S1List[0][x+1];
						S1List[1][x] = S1List[1][x+1];
						S1List[2][x] = S1List[2][x+1];
						S1List[3][x] = S1List[3][x+1];
						S1List[0][x+1] = swap;
						S1List[1][x+1] = swap2;
						S1List[2][x+1] = swap3;
						S1List[3][x+1] = swap4;
						swapping = true;
					}
				}
			}
		}
		if (vector2 == false)
		{
			int S1size;
			S1size = S1List[0].size();
			int width = S1size;
			int height = S1size;
			int IDsUsed = 0;
			ComboVector2.resize(height);
			ComboVectorInt.resize(height);
			for(int c=0;c<height;c++)
			{
				ComboVector2[c].resize(width);
				ComboVectorInt[c].resize(width);
			}
				int Semester1size = S1List[0].size();
				vector<string>::iterator iter;
				for(int c1=0;c1<Semester1size-1;c1++)
				{
					for(int c2=1;c2<Semester1size;c2++)
					{
						iter=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), S1List[2][c1]);  
						int xx = iter - SelectedClassList[2].begin();
						iter=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), S1List[2][c2]);  
						int y = iter - SelectedClassList[2].begin();
						if(SelectedClassList[5][xx] != SelectedClassList[5][y])
						{
							ComboVector2[c1][c2] = ComboVector3[xx][y];
							ComboVector2[c2][c1] = ComboVector3[y][xx];
							ComboVectorInt[c1][c2] = ComboVector3[xx][y];
							ComboVectorInt[c2][c1] = ComboVector3[y][xx];
						}
						else
						{
							int size2 = DV.StdStringToStdInt(SelectedClassList[3][xx]);
							if(DV.StdStringToStdInt(SelectedClassList[3][y]) > DV.StdStringToStdInt(SelectedClassList[3][xx]))
								size2 = DV.StdStringToStdInt(SelectedClassList[3][y]);
							ComboVector[xx][y] = size2;
							ComboVector[y][xx] = size2;
						}
					}	
				}
				ComboVector2[0][0] = 9999;
				ComboVector2[width-1][width-1] = 9999;
				vector2 = true;
		}
		else
		{
			int S1size2;
			S1size2 = S1List[0].size();
			ComboVector2.resize(0);
			ComboVector2.resize(S1size2);
			for(int copy6=0;copy6<S1size2;copy6++)
			{
				ComboVector2[copy6].resize(S1size2);
			}
			for(int position=0;position<S1size2-1;position++)
			{
				for(int position2=1;position2<S1size2;position2++)
				{
					IDss.resize(0);
					IDss2.resize(0);
					string id1 = S1List[2][position];
					string id2 = S1List[2][position2];
					int I1size = id1.size();
					int I2size = id2.size();
					int savedSlash= 0;
					int numTimes= 0;
					string savedID= "";
					for(int slashLocator= 0; slashLocator< I1size; slashLocator++)   
					{
						numTimes++;
						if(id1[slashLocator] == ',')
						{
								savedID.assign(id1, savedSlash, numTimes-1);
								IDss.push_back(savedID);
								savedSlash= slashLocator+1;
								numTimes= 0;
						}
						if(slashLocator == I1size-1)
						{
							savedID.assign(id1, savedSlash, I1size - savedSlash);
							IDss.push_back(savedID);
						}
					}
					savedSlash= 0;
					numTimes= 0;
					savedID= "";
					for(int slashLocator= 0; slashLocator< I2size; slashLocator++)
					{
						numTimes++;
						if(id2[slashLocator] == ',')
						{
								savedID.assign(id2, savedSlash, numTimes-1);
								IDss2.push_back(savedID);
								savedSlash= slashLocator+1;
								numTimes= 0;
						}
						if(slashLocator == I2size-1)
						{
							savedID.assign(id2, savedSlash, I2size - savedSlash);
							IDss2.push_back(savedID);
						}
					}
					ClassCombos.resize(0);
					for(int c=0;c<TotalStudents;c++)  
					{
	nextStudent:
						for(int c2=2;c2<17;c2++)
						{
							for(int c3=c2+1;c3<18;c3++)
							{
								if((std::find(IDss.begin(), IDss.end(), StudentCombinedList[c2][c]) != IDss.end() && std::find(IDss2.begin(), IDss2.end(), StudentCombinedList[c3][c]) != IDss2.end()) || (std::find(IDss.begin(), IDss.end(), StudentCombinedList[c3][c]) != IDss.end() && std::find(IDss2.begin(), IDss2.end(), StudentCombinedList[c2][c]) != IDss2.end()))
								{
									if(DV.IDToTeacher(StudentCombinedList[c2][c], SelectedClassList, SElist) == DV.IDToTeacher(StudentCombinedList[c3][c], SelectedClassList, SElist))
									{
										if(std::find(ClassCombos.begin(), ClassCombos.end(), StudentCombinedList[c2][c]) == ClassCombos.end() && std::find(ClassCombos.begin(), ClassCombos.end(), StudentCombinedList[c3][c]) == ClassCombos.end())
										{
											int size1 = DV.StdStringToStdInt(DV.IDToSize(StudentCombinedList[c2][c], SelectedClassList, SElist));
											int size2 = DV.StdStringToStdInt(DV.IDToSize(StudentCombinedList[c3][c], SelectedClassList, SElist));
											if(size1 > size2)
											{
												ComboVector2[position][position2] = ComboVector2[position][position2] + size1;
												ComboVector2[position2][position] = ComboVector2[position][position2] + size1;
											}
											else
											{
												ComboVector2[position][position2] = ComboVector2[position][position2] + size2;
												ComboVector2[position2][position] = ComboVector2[position][position2] + size2;
											}
										}
									}
									else
									{
										ComboVector2[position][position2] = ComboVector2[position][position2] +1;
										ComboVector2[position2][position] = ComboVector2[position][position2] +1;
									}
									if(c<TotalStudents-1)
									{
										c = c+1;
										goto nextStudent;
									}
								}
							}
						}
					}
				}
			}
			int size9 = ComboVector2.size();
			for(int set9=0;set9<size9;set9++)
			{
				ComboVector2[set9][set9] = 9999;
			}
		}
		SortedSlist[0].resize(0);
		SortedSlist[1].resize(0);
		IDs.resize(0);
		int rowEnd = 0;
		if (divisBy4 == false)
		{
			individualSorts = initialSize - (4 *pow(2.0,(HowManySorts-1)));
			rowEnd = initialSize - (individualSorts+1);
		}	
		int end = ComboVector2[0].size()-1;
		for(int row=end;row>rowEnd;row--)
		{
			if(std::find(IDs.begin(), IDs.end(), row) == IDs.end()) 
			{
				ConvertorTwo DV;
				if(DV.VectorSpaceAvailable(IDs, row) == true)
				{
					int search = 0;
					int Initialvalue = 1000000;
					int CurrentValue = Initialvalue;
					int id1 = row;
					int id2 = search;
					for(search;search<row;search++)
					{
						if(ComboVector2[row][search] < CurrentValue && std::find(IDs.begin(), IDs.end(), search) == IDs.end())
						{
							CurrentValue = ComboVector2[row][search];
							id1 = row;
							id2 = search;
						}
					}
					SortedSlist[0].push_back(id1);   
					SortedSlist[1].push_back(id2);  
					IDs.push_back(id1);
					IDs.push_back(id2);
				}
				else
				{
					SortedSlist[0].push_back(row);
					SortedSlist[1].push_back(9999);
					IDs.push_back(row);
				}
			}
		}
		if (divisBy4 == false)
		{
			for(int Cnum=0;Cnum<end+1;Cnum++)
			{
				if (std::find(IDs.begin(), IDs.end(), Cnum) == IDs.end())
				{
					SortedSlist[0].push_back(Cnum); 
					SortedSlist[1].push_back(9999);
				}
			}
		}
		int copy =0;
		int copyEnd = S1List[0].size();  
		for(copy=0;copy<4;copy++)
		{
			for(int copy2=0;copy2<copyEnd;copy2++)
			{
				S1ListCopy[copy][copy2] = S1List[copy][copy2];
				S1ListInt[copy][copy2] = S1List[copy][copy2];
			}
		}
		S1List.resize(0);
		S1List.resize(4);
		S1List[0].resize(SortedSlist[0].size());
		S1List[1].resize(SortedSlist[0].size());
		S1List[2].resize(SortedSlist[0].size());
		S1List[3].resize(SortedSlist[0].size());
		copyEnd = SortedSlist[0].size();
		for(copy=0;copy<copyEnd;copy++)
		{
			int I = SortedSlist[0][copy];
			int I2 = SortedSlist[1][copy];

			if (I2 == 9999)
			{
				S1List[0][copy] = S1ListCopy[0][I];
				S1List[1][copy] = S1ListCopy[1][I];
				S1List[2][copy] = S1ListCopy[2][I];
				S1List[3][copy] = S1ListCopy[3][I];
			}
			else
			{
				string name = S1ListCopy[0][I] + " | " + S1ListCopy[0][I2];
				S1List[0][copy] = name;
				string dept = S1ListCopy[1][I] + " | " + S1ListCopy[1][I2];
				S1List[1][copy] = dept;
				S1List[2][copy] = (S1ListCopy[2][I] + "," + S1ListCopy[2][I2]);
				string name1 = S1List[2][copy];
				int classSize = 0;
				int Bsize = name1.size();
				int savedSlash= 0;
				int numTimes= 0;
				string savedClass= "";
				IDss.resize(0); 
				for(int slashLocator= 0; slashLocator< Bsize; slashLocator++)
				{
					numTimes++;
					if(name1[slashLocator] == ',')
					{
							savedClass.assign(name1, savedSlash, numTimes-1);
							IDss.push_back(savedClass);
							savedSlash= slashLocator+1;
							numTimes= 0;
					}
					if(slashLocator == Bsize-1)
					{
						savedClass.assign(name1, savedSlash, Bsize - savedSlash);
						IDss.push_back(savedClass);
					}
				}
				for(int fillIn=0;fillIn<TotalStudents;fillIn++)
				{
					for(int under18=2; under18<18; under18++)
					{
						if(std::find(IDss.begin(), IDss.end(), StudentCombinedList[under18][fillIn]) != IDss.end())
						{
							classSize = classSize + 1;
							break;
						}
					}
				}
				S1List[3][copy] = DV.StdIntToStdString(classSize);
			}
		}
		divisBy4 = true; 
	}
}
void Module::SortS2IntoBlocks()
{
	ConvertorTwo DV;
	bool vector2 = false;
	int counter = 0;
	int stop = S2List[0].size();
	int HowManySorts = 0;
	int individualSorts; 
	for(int c=4;c<stop;c=c*2)
		HowManySorts = HowManySorts + 1;
	int initialSize = S2List[0].size();
	bool divisBy4;
	if (initialSize != 4*(pow(2.0, HowManySorts-1)))
		divisBy4 = false;
	else
		divisBy4 = true;
	S2ListCopy.resize(S2List.size());
	S2ListCopy[0].resize(S2List[0].size());
	S2ListCopy[1].resize(S2List[0].size());
	S2ListCopy[2].resize(S2List[0].size());
	S2ListCopy[3].resize(S2List[0].size());
	S2ListInt.resize(S2List.size());
	S2ListInt[0].resize(S2List[0].size());
	S2ListInt[1].resize(S2List[0].size());
	S2ListInt[2].resize(S2List[0].size());
	S2ListInt[3].resize(S2List[0].size());
	int size1 = ComboVector.size();
	ComboVector3.resize(size1);
	for(int Schange=0; Schange<size1;Schange++)
	{
		ComboVector3[Schange].resize(size1);
	}
	for(int copy=0;copy<size1;copy++)
	{
		for(int copy2=0;copy2<size1;copy2++)
		{
			ComboVector3[copy][copy2] = ComboVector[copy][copy2];
		}
	}
	for(int sorting=0;sorting<HowManySorts;sorting++)
	{
		int bigness = S2List[0].size();
		int x = 0;
		int convertedInt1;
		int convertedInt2;
		string swap;
		string swap2;
		string swap3;
		string swap4;
		string swap5;
		bool swapping = true;
		if(bigness > 1)
		{
			while(swapping == true)
			{
				swapping = false;
				for(x = 0; x<bigness-1; x++)
				{
					convertedInt1 = DV.StdStringToStdInt(S2List[3][x]);
					convertedInt2 = DV.StdStringToStdInt(S2List[3][x+1]);
					if(convertedInt1 < convertedInt2)
					{
						swap = S2List[0][x];
						swap2 = S2List[1][x];
						swap3 = S2List[2][x];
						swap4 = S2List[3][x];
						S2List[0][x] = S2List[0][x+1];
						S2List[1][x] = S2List[1][x+1];
						S2List[2][x] = S2List[2][x+1];
						S2List[3][x] = S2List[3][x+1];
						S2List[0][x+1] = swap;
						S2List[1][x+1] = swap2;
						S2List[2][x+1] = swap3;
						S2List[3][x+1] = swap4;
						swapping = true;
					}
				}
			}
		}
		if (vector2 == false)
		{
			int S2size;
			S2size = S2List[0].size();
			int width = S2size;
			int height = S2size;
			int IDsUsed = 0;
			ComboVector2.resize(height);
			ComboVectorInt.resize(height);
			for(int c=0;c<height;c++)
			{
				ComboVector2[c].resize(width);
				ComboVectorInt[c].resize(width);
			}
				int Semester1size = S2List[0].size();
				vector<string>::iterator iter;
				for(int c1=0;c1<Semester1size-1;c1++)
				{
					for(int c2=1;c2<Semester1size;c2++)
					{
						iter=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), S2List[2][c1]);  
						int xx = iter - SelectedClassList[2].begin();
						iter=find(SelectedClassList[2].begin(),SelectedClassList[2].end(), S2List[2][c2]);  
						int y = iter - SelectedClassList[2].begin();
						if(SelectedClassList[5][xx] != SelectedClassList[5][y])
						{
							ComboVector2[c1][c2] = ComboVector3[xx][y];
							ComboVector2[c2][c1] = ComboVector3[y][xx];
							ComboVectorInt[c1][c2] = ComboVector3[xx][y];
							ComboVectorInt[c2][c1] = ComboVector3[y][xx];
						}
						else
						{
							int size2 = DV.StdStringToStdInt(SelectedClassList[3][xx]);
							if(DV.StdStringToStdInt(SelectedClassList[3][y]) > DV.StdStringToStdInt(SelectedClassList[3][xx]))
								size2 = DV.StdStringToStdInt(SelectedClassList[3][y]);
							ComboVector[xx][y] = size2;
							ComboVector[y][xx] = size2;
						}
					}	
				}
				ComboVector2[0][0] = 9999;
				ComboVector2[width-1][width-1] = 9999;
				vector2 = true;
		}
		else
		{
			int S2size2;
			S2size2 = S2List[0].size();
			ComboVector2.resize(0);
			ComboVector2.resize(S2size2);
			for(int copy6=0;copy6<S2size2;copy6++)
			{
				ComboVector2[copy6].resize(S2size2);
			}
			for(int position=0;position<S2size2-1;position++)
			{
				for(int position2=1;position2<S2size2;position2++)
				{
					IDss.resize(0);
					IDss2.resize(0);
					string id1 = S2List[2][position];
					string id2 = S2List[2][position2];
					int I1size = id1.size();
					int I2size = id2.size();
					int savedSlash= 0;
					int numTimes= 0;
					string savedID= "";
					for(int slashLocator= 0; slashLocator< I1size; slashLocator++)   
					{
						numTimes++;
						if(id1[slashLocator] == ',')
						{
								savedID.assign(id1, savedSlash, numTimes-1);
								IDss.push_back(savedID);
								savedSlash= slashLocator+1;
								numTimes= 0;
						}
						if(slashLocator == I1size-1)
						{
							savedID.assign(id1, savedSlash, I1size - savedSlash);
							IDss.push_back(savedID);
						}
					}
					savedSlash= 0;
					numTimes= 0;
					savedID= "";
					for(int slashLocator= 0; slashLocator< I2size; slashLocator++)
					{
						numTimes++;
						if(id2[slashLocator] == ',')
						{
								savedID.assign(id2, savedSlash, numTimes-1);
								IDss2.push_back(savedID);
								savedSlash= slashLocator+1;
								numTimes= 0;
						}
						if(slashLocator == I2size-1)
						{
							savedID.assign(id2, savedSlash, I2size - savedSlash);
							IDss2.push_back(savedID);
						}
					}
					ClassCombos.resize(0);
					for(int c=0;c<TotalStudents;c++)  
					{
	nextStudent:
						for(int c2=2;c2<17;c2++)
						{
							for(int c3=c2+1;c3<18;c3++)
							{
								if((std::find(IDss.begin(), IDss.end(), StudentCombinedList[c2][c]) != IDss.end() && std::find(IDss2.begin(), IDss2.end(), StudentCombinedList[c3][c]) != IDss2.end()) || (std::find(IDss.begin(), IDss.end(), StudentCombinedList[c3][c]) != IDss.end() && std::find(IDss2.begin(), IDss2.end(), StudentCombinedList[c2][c]) != IDss2.end()))
								{
									if(DV.IDToTeacher(StudentCombinedList[c2][c], SelectedClassList, SElist) == DV.IDToTeacher(StudentCombinedList[c3][c], SelectedClassList, SElist))
									{
										if(std::find(ClassCombos.begin(), ClassCombos.end(), StudentCombinedList[c2][c]) == ClassCombos.end() && std::find(ClassCombos.begin(), ClassCombos.end(), StudentCombinedList[c3][c]) == ClassCombos.end())
										{
											int size1 = DV.StdStringToStdInt(DV.IDToSize(StudentCombinedList[c2][c], SelectedClassList, SElist));
											int size2 = DV.StdStringToStdInt(DV.IDToSize(StudentCombinedList[c3][c], SelectedClassList, SElist));
											if(size1 > size2)
											{
												ComboVector2[position][position2] = ComboVector2[position][position2] + size1;
												ComboVector2[position2][position] = ComboVector2[position][position2] + size1;
											}
											else
											{
												ComboVector2[position][position2] = ComboVector2[position][position2] + size2;
												ComboVector2[position2][position] = ComboVector2[position][position2] + size2;
											}
										}
									}
									else
									{
										ComboVector2[position][position2] = ComboVector2[position][position2] +1;
										ComboVector2[position2][position] = ComboVector2[position][position2] +1;
									}
									if(c<TotalStudents-1)
									{
										c = c+1;
										goto nextStudent;
									}
								}
							}
						}
					}
				}
			}
			int size9 = ComboVector2.size();
			for(int set9=0;set9<size9;set9++)
			{
				ComboVector2[set9][set9] = 9999;
			}
		}
		SortedSlist[0].resize(0);
		SortedSlist[1].resize(0);
		IDs.resize(0);
		int rowEnd = 0;
		if (divisBy4 == false)
		{
			individualSorts = initialSize - (4 *pow(2.0,(HowManySorts-1)));
			rowEnd = initialSize - (individualSorts+1);
		}	
		int end = ComboVector2[0].size()-1;
		for(int row=end;row>rowEnd;row--)
		{
			if(std::find(IDs.begin(), IDs.end(), row) == IDs.end()) 
			{
				ConvertorTwo DV;
				if(DV.VectorSpaceAvailable(IDs, row) == true)
				{
					int search = 0;
					int Initialvalue = 1000000;
					int CurrentValue = Initialvalue;
					int id1 = row;
					int id2 = search;
					for(search;search<row;search++)
					{
						if(ComboVector2[row][search] < CurrentValue && std::find(IDs.begin(), IDs.end(), search) == IDs.end())
						{
							CurrentValue = ComboVector2[row][search];
							id1 = row;
							id2 = search;
						}
					}
					SortedSlist[0].push_back(id1);   
					SortedSlist[1].push_back(id2);  
					IDs.push_back(id1);
					IDs.push_back(id2);
				}
				else
				{
					SortedSlist[0].push_back(row);
					SortedSlist[1].push_back(9999);
					IDs.push_back(row);
				}
			}
		}
		if (divisBy4 == false)
		{
			for(int Cnum=0;Cnum<end+1;Cnum++)
			{
				if (std::find(IDs.begin(), IDs.end(), Cnum) == IDs.end())
				{
					SortedSlist[0].push_back(Cnum); 
					SortedSlist[1].push_back(9999);
				}
			}
		}
		int copy =0;
		int copyEnd = S2List[0].size();  
		for(copy=0;copy<4;copy++)
		{
			for(int copy2=0;copy2<copyEnd;copy2++)
			{
				S2ListCopy[copy][copy2] = S2List[copy][copy2];
				S2ListInt[copy][copy2] = S2List[copy][copy2];
			}
		}
		S2List.resize(0);
		S2List.resize(4);
		S2List[0].resize(SortedSlist[0].size());
		S2List[1].resize(SortedSlist[0].size());
		S2List[2].resize(SortedSlist[0].size());
		S2List[3].resize(SortedSlist[0].size());
		copyEnd = SortedSlist[0].size();
		for(copy=0;copy<copyEnd;copy++)
		{
			int I = SortedSlist[0][copy];
			int I2 = SortedSlist[1][copy];

			if (I2 == 9999)
			{
				S2List[0][copy] = S2ListCopy[0][I];
				S2List[1][copy] = S2ListCopy[1][I];
				S2List[2][copy] = S2ListCopy[2][I];
				S2List[3][copy] = S2ListCopy[3][I];
			}
			else
			{
				string name = S2ListCopy[0][I] + " | " + S2ListCopy[0][I2];
				S2List[0][copy] = name;
				string dept = S2ListCopy[1][I] + " | " + S2ListCopy[1][I2];
				S2List[1][copy] = dept;
				S2List[2][copy] = (S2ListCopy[2][I] + "," + S2ListCopy[2][I2]);
				string name1 = S2List[2][copy];
				int classSize = 0;
				int Bsize = name1.size();
				int savedSlash= 0;
				int numTimes= 0;
				string savedClass= "";
				IDss.resize(0); 
				for(int slashLocator= 0; slashLocator< Bsize; slashLocator++)
				{
					numTimes++;
					if(name1[slashLocator] == ',')
					{
							savedClass.assign(name1, savedSlash, numTimes-1);
							IDss.push_back(savedClass);
							savedSlash= slashLocator+1;
							numTimes= 0;
					}
					if(slashLocator == Bsize-1)
					{
						savedClass.assign(name1, savedSlash, Bsize - savedSlash);
						IDss.push_back(savedClass);
					}
				}
				for(int fillIn=0;fillIn<TotalStudents;fillIn++)
				{
					for(int under18=2; under18<18; under18++)
					{
						if(std::find(IDss.begin(), IDss.end(), StudentCombinedList[under18][fillIn]) != IDss.end())
						{
							classSize = classSize + 1;
							break;
						}
					}
				}
				S2List[3][copy] = DV.StdIntToStdString(classSize);
			}
		}
		divisBy4 = true; 
	}
}
void Module::GetResults()
{
	for(int blockNum= 0; blockNum < 4; blockNum++)
	{
		string blockedClasses= S1List[0][blockNum];
		int Bsize = blockedClasses.size();
		int savedSlash= 0;
		int numTimes= 0;
		string savedClass= "";
		bool first = true;
		for(int slashLocator= 0; slashLocator< Bsize; slashLocator++)
		{
			numTimes++;
			if(blockedClasses[slashLocator] == '|')
			{
				if(first == true)
				{
					savedClass.assign(blockedClasses, savedSlash, numTimes-2);
					first = false;
				}
				else
				{
					savedClass.assign(blockedClasses, savedSlash, numTimes-3);		
				}
				for(int lineLocator= 0; lineLocator < savedClass.size(); lineLocator++)
				{
					if(savedClass[lineLocator] == '/')
					{
						S1ListElectiveResult[blockNum].push_back(savedClass);
						S1ListElectiveResultCopy[blockNum].push_back(savedClass);
						break;
					}
					if(lineLocator == savedClass.size()-1)
					{
						S1ListResult[blockNum].push_back(savedClass);
						S1ListResultCopy[blockNum].push_back(savedClass);
					}
				}	
				savedSlash= slashLocator+2;
				numTimes= 0;
			}
			if(slashLocator == Bsize-1)
			{
				savedClass.assign(blockedClasses, savedSlash, Bsize - savedSlash);
				for(int lineLocator= 0; lineLocator < savedClass.size(); lineLocator++)
				{
					if(savedClass[lineLocator] == '/')
					{
						S1ListElectiveResult[blockNum].push_back(savedClass);
						S1ListElectiveResultCopy[blockNum].push_back(savedClass);
						break;
					}
					if(lineLocator == savedClass.size()-1)
					{
						S1ListResult[blockNum].push_back(savedClass);
						S1ListResultCopy[blockNum].push_back(savedClass);
					}
				}
			}
		}
	}
	for(int blockNum= 0; blockNum < 4; blockNum++)
	{
		string blockedClasses= S2List[0][blockNum];
		int Bsize = blockedClasses.size();
		int savedSlash= 0;
		int numTimes= 0;
		string savedClass= "";
		bool first = true;
		for(int slashLocator= 0; slashLocator< Bsize; slashLocator++)
		{
			numTimes++;
			if(blockedClasses[slashLocator] == '|')
			{
				if(first == true)
				{
					savedClass.assign(blockedClasses, savedSlash, numTimes-2);
					first = false;
				}
				else
				{
					savedClass.assign(blockedClasses, savedSlash, numTimes-3);		
				}
				for(int lineLocator= 0; lineLocator < savedClass.size(); lineLocator++)
				{
					if(savedClass[lineLocator] == '/')
					{
						S2ListElectiveResult[blockNum].push_back(savedClass);
						S2ListElectiveResultCopy[blockNum].push_back(savedClass);
						break;
					}
					if(lineLocator == savedClass.size()-1)
					{
						S2ListResult[blockNum].push_back(savedClass);
						S2ListResultCopy[blockNum].push_back(savedClass);
					}
				}	
				savedSlash= slashLocator+2;
				numTimes= 0;
			}
			if(slashLocator == Bsize-1)
			{
				savedClass.assign(blockedClasses, savedSlash, Bsize - savedSlash);
				for(int lineLocator= 0; lineLocator < savedClass.size(); lineLocator++)
				{
					if(savedClass[lineLocator] == '/')
					{
						S2ListElectiveResult[blockNum].push_back(savedClass);
						S2ListElectiveResultCopy[blockNum].push_back(savedClass);
						break;
					}
					if(lineLocator == savedClass.size()-1)
					{
						S2ListResult[blockNum].push_back(savedClass);
						S2ListResultCopy[blockNum].push_back(savedClass);
					}
				}
			}
		}
	}
	vector< vector<int> > ElectivePutterBacker(4, vector<int>(4));
	vector<string> blockStrings(4);
	string temp = "";
	ConvertorTwo DV;
	for(int checkFor0=0; checkFor0 < 4; checkFor0++)
	{
		if(S1ListElectiveResult[checkFor0].size() == 0)
		{
			for(int giveBack=0;giveBack<4;giveBack++)
			{
				for(int giveBack2 =0; giveBack2<S1ListElectiveResult[giveBack].size(); giveBack2++)
				{
					S1ListResult[giveBack].push_back(S1ListElectiveResult[giveBack][giveBack2]);
				}
			}
			goto S2;
		}
	}
	int stopping = StudentCombinedList.size();
	for(int stringCreate=0; stringCreate<4;stringCreate++)
	{
		for(int stringCreate2=0;stringCreate2<S1ListElectiveResult[stringCreate].size();stringCreate2++)
		{
			temp = temp + S1ListElectiveResult[stringCreate][stringCreate2];
			if(stringCreate2 < S1ListElectiveResult[stringCreate].size()-1)
				temp= temp + "/";
		}
		blockStrings[stringCreate] = temp;
		temp = "";
	}
	for(int position=0;position<4;position++)
	{
		for(int position2=0;position2<4;position2++)
		{
			IDss.resize(0);
			IDss2.resize(0);
			string id2 = blockStrings[position2];
			int I2size = id2.size();
			int savedSlash= 0;
			int numTimes= 0;
			string savedID= "";
			for(int slashLocator= 0; slashLocator< I2size; slashLocator++)
			{
				numTimes++;
				if(id2[slashLocator] == '/')
				{
						savedID.assign(id2, savedSlash, numTimes-1);
						IDss2.push_back(savedID);
						savedSlash= slashLocator+1;
						numTimes= 0;
				}
				if(slashLocator == I2size-1)
				{
					savedID.assign(id2, savedSlash, I2size - savedSlash);
					IDss2.push_back(savedID);
				}
			}
			for(int move=0;move<S1ListResult[position].size();move++)
			{
				IDss.push_back(S1ListResult[position][move]);
			}
			for(int convert=0; convert<IDss.size();convert++)
			{
				IDss[convert] = DV.NameToID(IDss[convert], SelectedClassList, SElist);
			}
			for(int convert=0; convert<IDss2.size();convert++)
			{
				IDss2[convert] = DV.NameToID(IDss2[convert], SelectedClassList, SElist);
			}
			for(int convert=0; convert<IDss2.size();convert++)
			{
				IDss.push_back(IDss2[convert]);
			}
			for(int c=0;c<TotalStudents;c++)  
			{
	next:
				for(int c2=2;c2<17;c2++)
					{
						for(int c3=c2+1;c3<18;c3++)
							{
								if((std::find(IDss.begin(), IDss.end(), StudentCombinedList[c2][c]) != IDss.end() && std::find(IDss2.begin(), IDss2.end(), StudentCombinedList[c3][c]) != IDss2.end())  || (std::find(IDss.begin(), IDss.end(), StudentCombinedList[c3][c]) != IDss.end() && std::find(IDss2.begin(), IDss2.end(), StudentCombinedList[c2][c]) != IDss2.end()))
								{
									ElectivePutterBacker[position][position2] = ElectivePutterBacker[position][position2] +1; 
									if(c<TotalStudents-1)
									{
										c = c+1;
										goto next;
									}
								}

							}
					}
			}
		}
	}
	for(int set9=0;set9<4;set9++)
	{
		ElectivePutterBacker[set9][set9] = 9999;
	}
	int elective;
	int class1;
	int selection = 9999;
	for(int choosing=0;choosing<4;choosing++)
	{
		for(int choosing2=0;choosing2<4;choosing2++)
		{
			if(ElectivePutterBacker[choosing2][choosing] < selection)
			{
				selection = ElectivePutterBacker[choosing2][choosing];
				elective = choosing;
				class1 = choosing2;
			}
		}
	}
	for(int eStore=0; eStore<S1ListElectiveResult[elective].size(); eStore++)
	{
		S1ListResult[class1].push_back(S1ListElectiveResult[elective][eStore]);
	}
	S1ListElectiveResult[elective].resize(0);
	for(int eStore=0; eStore<4; eStore++)
	{
		for(int eStore2=0; eStore2<S1ListElectiveResult[eStore].size(); eStore2++)
		{
			S1ListResult[eStore].push_back(S1ListElectiveResult[eStore][eStore2]);
		}
	}
	S2:
	ElectivePutterBacker.resize(0);
	ElectivePutterBacker.resize(4);
	ElectivePutterBacker[0].resize(4);
	ElectivePutterBacker[1].resize(4);
	ElectivePutterBacker[2].resize(4);
	ElectivePutterBacker[3].resize(4);
	blockStrings.resize(0);
	blockStrings.resize(4);
	temp = "";
	for(int checkFor0=0; checkFor0 < 4; checkFor0++)
	{
		if(S2ListElectiveResult[checkFor0].size() == 0)
		{
			for(int giveBack=0;giveBack<4;giveBack++)
			{
				for(int giveBack2 =0; giveBack2<S2ListElectiveResult[giveBack].size(); giveBack2++)
				{
					S2ListResult[giveBack].push_back(S2ListElectiveResult[giveBack][giveBack2]);
				}
			}
			goto Results;
		}
	}
	for(int stringCreate=0; stringCreate<4;stringCreate++)
	{
		for(int stringCreate2=0;stringCreate2<S2ListElectiveResult[stringCreate].size();stringCreate2++)
		{
			temp = temp + S2ListElectiveResult[stringCreate][stringCreate2];
			if(stringCreate2 < S2ListElectiveResult[stringCreate].size()-1)
				temp= temp + "/";
		}
		blockStrings[stringCreate] = temp;
		temp = "";
	}
	for(int position=0;position<4;position++)
	{
		for(int position2=0;position2<4;position2++)
		{
			IDss.resize(0);
			IDss2.resize(0);
			string id2 = blockStrings[position2];
			int I2size = id2.size();
			int savedSlash= 0;
			int numTimes= 0;
			string savedID= "";
			for(int slashLocator= 0; slashLocator< I2size; slashLocator++)
			{
				numTimes++;
				if(id2[slashLocator] == '/')
				{
						savedID.assign(id2, savedSlash, numTimes-1);
						IDss2.push_back(savedID);
						savedSlash= slashLocator+1;
						numTimes= 0;
				}
				if(slashLocator == I2size-1)
				{
					savedID.assign(id2, savedSlash, I2size - savedSlash);
					IDss2.push_back(savedID);
				}
			}
			for(int move=0;move<S2ListResult[position].size();move++)
			{
				IDss.push_back(S2ListResult[position][move]);
			}
			for(int convert=0; convert<IDss.size();convert++)
			{
				IDss[convert] = DV.NameToID(IDss[convert], SelectedClassList, SElist);
			}
			for(int convert=0; convert<IDss2.size();convert++)
			{
				IDss2[convert] = DV.NameToID(IDss2[convert], SelectedClassList, SElist);
			}
			for(int convert=0; convert<IDss2.size();convert++)
			{
				IDss.push_back(IDss2[convert]);
			}

			for(int c=0;c<TotalStudents;c++)  
			{
	next2:
				for(int c2=2;c2<17;c2++)
				{
					for(int c3=c2+1;c3<18;c3++)
					{
						if((std::find(IDss.begin(), IDss.end(), StudentCombinedList[c2][c]) != IDss.end() && std::find(IDss2.begin(), IDss2.end(), StudentCombinedList[c3][c]) != IDss2.end())  || (std::find(IDss.begin(), IDss.end(), StudentCombinedList[c3][c]) != IDss.end() && std::find(IDss2.begin(), IDss2.end(), StudentCombinedList[c2][c]) != IDss2.end()))
						{
							ElectivePutterBacker[position][position2] = ElectivePutterBacker[position][position2] +1; 
							if(c<TotalStudents-1)
							{
								c = c+1;
								goto next2;
							}
						}

					}
				}
			}
		}
	}
	for(int set9=0;set9<4;set9++)
	{
		ElectivePutterBacker[set9][set9] = 9999;
	}
	selection = 9999;
	for(int choosing=0;choosing<4;choosing++)
	{
		for(int choosing2=0;choosing2<4;choosing2++)
		{
			if(ElectivePutterBacker[choosing2][choosing] < selection)
			{
				selection = ElectivePutterBacker[choosing2][choosing];
				elective = choosing;
				class1 = choosing2;
			}
		}
	}
	for(int eStore=0; eStore<S2ListElectiveResult[elective].size(); eStore++)
	{
		S2ListResult[class1].push_back(S2ListElectiveResult[elective][eStore]);
	}
	S2ListElectiveResult[elective].resize(0);
	for(int eStore=0; eStore<4; eStore++)
	{
		for(int eStore2=0; eStore2<S2ListElectiveResult[eStore].size(); eStore2++)
		{
			S2ListResult[eStore].push_back(S2ListElectiveResult[eStore][eStore2]);
		}
	}
	Results:
	ofstream outFile;
	outFile.open("Results!!!!!");
	outFile<< "Semester 1: " << endl << endl;
	for(int blocknum=0;blocknum<4;blocknum++)
	{
		int rSize = S1ListResult[blocknum].size();
		outFile << endl << "Block: " << blocknum+1 << endl << endl;
		for(int r =0;r<rSize;r++)
		{
			outFile << S1ListResult[blocknum][r] << endl;
		}
	}
	outFile<< endl << "Semester 2: " << endl << endl;
	for(int blocknum=0;blocknum<4;blocknum++)
	{
		int rSize = S2ListResult[blocknum].size();
		outFile << endl << "Block: " << blocknum+1 << endl << endl;
		for(int r =0;r<rSize;r++)
		{
			outFile << S2ListResult[blocknum][r] << endl;
		}
	}
}
void Module::Scoring()
{
	ConvertorTwo DV;
	int scheduleSuccess=0;
	int totalRequests=0;
	std::vector<vector<int>> BlockFilled(4, vector<int>(0));
	for(int c=0;c<TotalStudents;c++)  
	{
		for(int c2=2;c2<17;c2++)
		{
			if(StudentCombinedList[c2][c] != "9999")
				totalRequests = totalRequests + 1;
		}
	}
	for(int S1=0;S1<4;S1++)
	{
		for(int block1=0;block1<S1ListResult[S1].size();block1++)
		{
			for(int c=0;c<TotalStudents;c++)  
			{
				if(std::find(BlockFilled[S1].begin(), BlockFilled[S1].end(), c) == BlockFilled[S1].end())
				{
					for(int c2=2;c2<18;c2++)
					{
						if(StudentCombinedList[c2][c] == DV.NameToID(S1ListResult[S1][block1], SelectedClassList, SElist))
						{
							scheduleSuccess = scheduleSuccess+1;
							BlockFilled[S1].push_back(c);
						}
					}
				}
			}
		}
	}
	for(int S1=0;S1<4;S1++)
	{
		for(int block1=0;block1<S1ListElectiveResult[S1].size();block1++)
		{
			for(int c=0;c<TotalStudents;c++)  
			{
				if(std::find(BlockFilled[S1].begin(), BlockFilled[S1].end(), c) == BlockFilled[S1].end())
				{
					for(int c2=2;c2<18;c2++)
					{
						if(StudentCombinedList[c2][c] == DV.NameToID(S1ListResult[S1][block1], SelectedClassList, SElist))
						{
							scheduleSuccess = scheduleSuccess+1;
							//BlockFilled.push_back(c);
						}
					}
				}
			}
		}
	}
	for(int S2=0;S2<4;S2++)
	{
		BlockFilled[S2].resize(0);
		for(int block1=0;block1<S2ListResult[S2].size();block1++)
		{
			for(int c=0;c<TotalStudents;c++)  
			{
				if(std::find(BlockFilled[S2].begin(), BlockFilled[S2].end(), c) == BlockFilled[S2].end())
				{
					for(int c2=2;c2<18;c2++)
					{
						if(StudentCombinedList[c2][c] == DV.NameToID(S2ListResult[S2][block1], SelectedClassList, SElist))
						{
							scheduleSuccess = scheduleSuccess+1;
							BlockFilled[S2].push_back(c);
						}
					}
				}
			}
		}
	}
	for(int S2=0;S2<4;S2++)
	{
		for(int block1=0;block1<S2ListElectiveResult[S2].size();block1++)
		{
			for(int c=0;c<TotalStudents;c++)  
			{
				if(std::find(BlockFilled[S2].begin(), BlockFilled[S2].end(), c) == BlockFilled[S2].end())
				{
					for(int c2=2;c2<18;c2++)
					{
						if(StudentCombinedList[c2][c] == DV.NameToID(S2ListResult[S2][block1], SelectedClassList, SElist))
						{
							scheduleSuccess = scheduleSuccess+1;
						}
					}
				}
			}
		}
	}
	float SS = scheduleSuccess;
	float TR = totalRequests;
	float percentage = 0.0; 
	percentage = (SS/TR);
	ofstream outFile;
	outFile.open("Results!!!!!", ios::app);
	outFile<< endl << "Total Requests: " << totalRequests << endl << "Total Successes: " << scheduleSuccess << endl << "Percentage: " << percentage << endl;
	outFile.close();
}
}