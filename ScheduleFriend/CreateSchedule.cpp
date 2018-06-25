#include "StdAfx.h"
#include "CreateSchedule.h"
using namespace std;

CreateSchedule::CreateSchedule(void)
{
}

//
void CreateSchedule::DoItAll(vector<vector<string> > SElist, vector<vector<string>> StudentList, vector<vector<string>> StudentEList, vector<vector<string>> SelectedClassList, int TotalClasses, int TotalElectives, int TotalStudents)
{
	std::vector< vector<string> > Elist;
	//std::vector< vector<string> > SElist;
	std::vector<int> IDs;
	std::vector<int> IDs2;
	std::vector<string> IDss;
	std::vector<string> IDss2;
	std::vector<string> ComboID;
	std::vector<vector<int>> SortedElist;
	std::vector<vector<int>> SortedRlist;
	std::vector<vector<int>> SortedSlist;
	//vector<vector<string>> StudentList;
	//vector<vector<string>> StudentEList;
	vector<vector<string>> StudentCombinedList;
	vector<vector<string>> ClassList;
	//vector<vector<string>> SelectedClassList;
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
	//int TotalClasses;
	//int TotalElectives;
	//int TotalStudents;
	std::vector<vector<int>> ComboVector;
	std::vector<vector<int>> ComboVector2;
	std::vector<vector<int>> ComboVector3;
	std::vector<vector<int>> ComboVectorInt; 
	std::vector<vector<int>> RemovedElectiveCombo;
	std::vector<vector<string>> ComboVectorString;


//  Sort Elevtives 
vector<string>::iterator iter;
ConvertStuff CV;
SavingStuff SF;
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
		int E = CV.StdStringToStdInt(StudentEList[counter2][counter1]);
		if (E == 9999)
			break;
		iter=find(SElist[2].begin(),SElist[2].end(), CV.StdIntToStdString(E));
		int newE = iter - SElist[2].begin();
		int newSize = CV.StdStringToStdInt(SElist[3][newE]) + 1;
		SElist[3][newE] = CV.StdIntToStdString(newSize);
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
			convertedInt1E = CV.StdStringToStdInt(SElist[3][x]);
			convertedInt2E = CV.StdStringToStdInt(SElist[3][x+1]);
			
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
//  PairEveryOtherDayClasses

int SEsize;
SEsize = SElist[0].size();
int width = SEsize;
int height = SEsize;
int IDsUsed = 0;
ComboVector.resize(height);
//Size Combo vector appropriately 
for(int c=0;c<height;c++)
{
	ComboVector[c].resize(width);
}
//Get Combinations for Electives use StudentList
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
				
				int I = CV.StdStringToStdInt(StudentEList[c2][c]); 
				int I2 = CV.StdStringToStdInt(StudentEList[c3][c]);
				it=find(SElist[2].begin(),SElist[2].end(), CV.StdIntToStdString(I));
				int newI = it - SElist[2].begin();
				it=find(SElist[2].begin(),SElist[2].end(), CV.StdIntToStdString(I2));
				int newI2 = it - SElist[2].begin();

				if(StudentEList[c3][c] == "9999")
					break;
				if(SElist[4][newI] == SElist[4][newI2])
				{
					int size = CV.StdStringToStdInt(SElist[3][newI]);
					if(CV.StdStringToStdInt(SElist[3][newI2]) > CV.StdStringToStdInt(SElist[3][newI]))
						size = CV.StdStringToStdInt(SElist[3][newI2]);
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


//change StudentEList ids to be the new values

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
//change SElist ids to be the new value																					<--	id#s change for the electives here 

	int stop = SElist[0].size();
	for(int schange=0;schange<stop;schange++)
	{
		SElist[2][schange] = "000" + SElist[2][schange];
	}
//create StudentCombinedList
	//set it to equal StudentList
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
	//add in the values from StudentEList
	for(int set3=0;set3<TotalStudents;set3++)
	{
		for(int set4=2;set4<18;set4++)  //searches StudentEList for classes
		{
			if(StudentEList[set4][set3] != "0009999") //if it finds one 
			{
				for(int find9s=2;find9s<18;find9s++) //it searches for the next 9999 (open spot) in StudentCombinedList
				{
					if(StudentCombinedList[find9s][set3] == "9999")
					{
						StudentCombinedList[find9s][set3] = StudentEList[set4][set3]; //and adds the Elective id# there
						break;
					}
				}
			}
			else
				break;
		}
	}

//Reverse Sort the Electives to Pair them        

SortedElist[0].resize(0);
SortedElist[1].resize(0);
IDs.resize(0);
for(int row=1;row<height;row++)
{
	if(std::find(IDs.begin(), IDs.end(), row) == IDs.end())     /* if IDs doesn't contain row, the Elective ID# */
	{
		if(CV.VectorSpaceAvailable(IDs, row) == true)
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
			SortedElist[0].push_back(CV.StdStringToStdInt(SElist[2][id1]));//ID   
			SortedElist[1].push_back(CV.StdStringToStdInt(SElist[2][id2]));//ID  
			IDs.push_back(id1);
			IDs.push_back(id2);
		}
		else if(CV.VectorSpaceAvailable(IDs, row) == false && row == height-1)
		{
			SortedElist[0].push_back(CV.StdStringToStdInt(SElist[2][row]));//ID
			SortedElist[1].push_back(9999);//Null ID
			IDs.push_back(row);
		}

	}	
}
//  ReverseSortAllClassesIntoSemesters

vector<string>::iterator iterAP;   //Find Regular Class Sizes
SSsize = SelectedClassList[0].size();
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
		//AP or multiple class
		//int ending = SelectedClassList[0].size();
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

//Add classes from SElist to SelectedClassList

int startNewIDs = CV.StdStringToStdInt(SelectedClassList[2][0]);
int Ssize2 = SElist[0].size();
for(int c=0;c<Ssize2;c++)
{
	if(CV.StdStringToStdInt(SelectedClassList[2][c]) > startNewIDs)
		startNewIDs = CV.StdStringToStdInt(SelectedClassList[2][c]);
}		//sets the new paired elective classes to have an id of one higher than the highest class id. not in use currently
startNewIDs = startNewIDs + 1;
int counter = SortedElist[0].size();
for(int c=0;c<counter;c++)
{
	string I = "000" + CV.StdIntToStdString(SortedElist[0][c]);		//newI and newI2 are the positions of classes in SelecetedElectiveList based on the ids in SortedElist					
	string I2 = "000" + CV.StdIntToStdString(SortedElist[1][c]);	//now that the ids have 00 in them we need to use strings and not int like before 
	it=find(SElist[2].begin(),SElist[2].end(), I);
	int newI = it - SElist[2].begin();
	it=find(SElist[2].begin(),SElist[2].end(), I2);
	int newI2 = it - SElist[2].begin();
	if (I2 == "0009999")
	{
		SelectedClassList[0].push_back(SElist[0][newI]);
		SelectedClassList[1].push_back(SElist[1][newI]);
		SelectedClassList[2].push_back(SElist[2][newI]); //CV.StdIntToStdString(startNewIDs) what it was
		SelectedClassList[3].push_back(SElist[3][newI]);
		SelectedClassList[4].push_back("0");
		SelectedClassList[5].push_back(SElist[4][newI]);
		break;
	}
	SelectedClassList[0].push_back(SElist[0][newI] + "/" + SElist[0][newI2]); //name1/name2							
	SelectedClassList[1].push_back(SElist[1][newI] + "/" + SElist[1][newI2]); //dept1/dept2
	SelectedClassList[2].push_back(SElist[2][newI] + "," + SElist[2][newI2]); //new ID	
	int IntersectStudents = ComboVector[newI][newI2];
	int Student1 = CV.StdStringToStdInt(SElist[3][newI]);
	int Student2 = CV.StdStringToStdInt(SElist[3][newI2]);  //students
	int BothStudents = Student1 + Student2;
	SelectedClassList[3].push_back(CV.StdIntToStdString(BothStudents-IntersectStudents));// students continued
	SelectedClassList[4].push_back("0");
	SelectedClassList[5].push_back(SElist[4][newI] + "/" + SElist[4][newI2]);
	startNewIDs = startNewIDs +1;
}
//Sort regular classes by size
int bigness = SelectedClassList[0].size();
int convertedInt1;
int convertedInt2;
string swap;
string swap2;
string swap3;
string swap4;
string swap5;
string swap6;
swapping = true;

if(bigness > 1)
{
	while(swapping == true)
	{
		swapping = false;
		for(x = 0; x<bigness-1; x++)
		{
			convertedInt1 = CV.StdStringToStdInt(SelectedClassList[3][x]);
			convertedInt2 = CV.StdStringToStdInt(SelectedClassList[3][x+1]);
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
//Begin Reverse-Sorting
int SCsize;
SCsize = SelectedClassList[0].size();
width = SCsize;
height = SCsize;
IDsUsed = 0;
ComboVector.resize(0);
ComboVector.resize(height);
//Size Combo vector appropriately 
for(int c=0;c<height;c++)
{
	ComboVector[c].resize(width);
}
//Get Combinations for Classes use StudentCombinedList     
	SF.loadStudentList(TotalStudents, StudentList);
	int StudentSize = StudentList[0].size();
	vector<string>::iterator APit1;
	vector<string>::iterator APit2;
	size = SelectedClassList[0].size();
	string idString1 = "";
	string idString2 = "";
	int newI =0;
	int newI2 = 0;

for(int c=0;c<StudentSize;c++)   //here is where the first pairings happens								<--here is the first ComboVector for full classes
{
	for(int c2=2;c2<17;c2++)
	{
		
		if(StudentCombinedList[c2][c] == "9999" || StudentCombinedList[c2][c] == "0009999")
			break;
		for(int c3=c2+1;c3<18;c3++)
		{
			if(StudentCombinedList[c3][c] == "9999" || StudentCombinedList[c3][c] == "0009999")
				break;
			//changes: use comibined student list
			string I = StudentCombinedList[c2][c];
			string I2 = StudentCombinedList[c3][c];
			int iSize = I.size();
			if(iSize > 3)  //finds the position of the class id (newI)
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
			if(iSize2 > 3)  //finds the position of the second class id (newI2)
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
					
			//testing for AP classes #1
			it=find(APit1+1, SelectedClassList[2].end(), I);
			int newI5 = it - SelectedClassList[2].begin();
			int SCListEnd = SelectedClassList[0].size();
			if(newI5 != SCListEnd)  //if there is a second newI aka first class is an AP
			{
				int newI3 = it - SelectedClassList[2].begin();
				if(SelectedClassList[5][newI3] == SelectedClassList[5][newI2])
				{
					int size = CV.StdStringToStdInt(SelectedClassList[3][newI3]);
					if(CV.StdStringToStdInt(SelectedClassList[3][newI2]) < CV.StdStringToStdInt(SelectedClassList[3][newI3]))
						size = CV.StdStringToStdInt(SelectedClassList[3][newI2]);
					ComboVector[newI3][newI2] = size;
					ComboVector[newI2][newI3] = size;
					//CV.TroubleShoot(newI3, newI2, c2, c3, c, StudentCombinedList);//t
				}
				else
				{
					ComboVector[newI3][newI2] = (ComboVector[newI][newI2]+1);
					ComboVector[newI2][newI3] = (ComboVector[newI2][newI]+1);
					//CV.TroubleShoot(newI3, newI2, c2, c3, c, StudentCombinedList);//t
				}
			}
			//testing for AP classes #2
			it=find(APit2+1, SelectedClassList[2].end(), I2);
			int newI6 = it - SelectedClassList[2].begin();
			if(newI6 != SCListEnd) //if there is a second newI2 aka second class is an AP
			{
				int newI4 = it - SelectedClassList[2].begin();
				if(SelectedClassList[5][newI4] == SelectedClassList[5][newI4])
				{
					int size = CV.StdStringToStdInt(SelectedClassList[3][newI]);
					if(CV.StdStringToStdInt(SelectedClassList[3][newI4]) < CV.StdStringToStdInt(SelectedClassList[3][newI]))
						size = CV.StdStringToStdInt(SelectedClassList[3][newI4]);
					ComboVector[newI][newI4] = size;
					ComboVector[newI4][newI] = size;
					//CV.TroubleShoot(newI4, newI, c2, c3, c, StudentCombinedList);//t
				}
				else
				{
					ComboVector[newI][newI4] = (ComboVector[newI][newI2]+1);
					ComboVector[newI4][newI] = (ComboVector[newI2][newI]+1);
					//CV.TroubleShoot(newI4, newI, c2, c3, c, StudentCombinedList);//t
				}
			}


			//add in the values to ComboVector
			if(SelectedClassList[5][newI] == SelectedClassList[5][newI2])  
			{
				int size2 = CV.StdStringToStdInt(SelectedClassList[3][newI]);
				if(CV.StdStringToStdInt(SelectedClassList[3][newI2]) > CV.StdStringToStdInt(SelectedClassList[3][newI]))
					size2 = CV.StdStringToStdInt(SelectedClassList[3][newI2]);
				ComboVector[newI][newI2] = size2;//9999
				ComboVector[newI2][newI] = size2;
				//CV.TroubleShoot(newI2, newI, c2, c3, c, StudentCombinedList);//t
			}
			else 
			{
				//if(newI == 9 && newI2 == 49)
					//bool fixthisdamnthing = true;   //find out what the hell is wrong
			ComboVector[newI][newI2] = (ComboVector[newI][newI2]+1);
			ComboVector[newI2][newI] = (ComboVector[newI2][newI]+1);
			//CV.TroubleShoot(newI2, newI, c2, c3, c, StudentCombinedList);//t
			}
		}
	}	  
}

//set the middle values to be 9999 so they don't get picked
size = ComboVector[0].size();
for(int nineSet=0;nineSet<size;nineSet++)
{
	ComboVector[nineSet][nineSet] = 9999;
}

//Reverse Sort Classes to Pair them

SortedRlist[0].resize(0);
SortedRlist[1].resize(0);
IDs.resize(0);
for(int row=1;row<height;row++)
{
	if(std::find(IDs.begin(), IDs.end(), row) == IDs.end())      //if IDs doesn't contain row, the Elective ID# 
	{
		if(CV.VectorSpaceAvailable(IDs, row) == true)
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
			SortedRlist[0].push_back(id1);//ID   
			SortedRlist[1].push_back(id2);//ID  
			IDs.push_back(id1);
			IDs.push_back(id2);
		}
		else if(CV.VectorSpaceAvailable(IDs, row) == false && row == height-1)
		{
			SortedRlist[0].push_back(row);//ID
			SortedRlist[1].push_back(9999);//Null ID
			IDs.push_back(row);
		}

	}	
	//if(row == height-1 && std::find(IDs.begin(), IDs.end(), row) != IDs.end())//If its the last class all by itself
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

//Add classes from SortedRegularlist to Semester1list and Semester2list

int row = 0;
int column = 0;
counter = SortedRlist[0].size();
for(int c=0;c<counter;c++)
{
	row = SortedRlist[0][c]; // row and column are the positons in SElist of paired classes (obtained from ComboVector)
	column = SortedRlist[1][c];
	if (column == 9999)
		break;
	int semester1 = CV.StdStringToStdInt(SelectedClassList[4][row]);
	int semester2 = CV.StdStringToStdInt(SelectedClassList[4][column]);
	string nullcheck1 = SelectedClassList[2][row]; //check if this is the right list
	string nullcheck2 = SelectedClassList[2][column];
	if(nullcheck1 != "9999")
	{
		//first class
		if(semester1 == 1 || semester1 == 0)
		{
			S1List[0].push_back(SelectedClassList[0][row]); //name1
			S1List[1].push_back(SelectedClassList[1][row]); //dept1
			S1List[2].push_back(SelectedClassList[2][row]); //new ID
			S1List[3].push_back(SelectedClassList[3][row]);// students
		}
		if(semester1 == 2)
		{
			S2List[0].push_back(SelectedClassList[0][row]); //name1
			S2List[1].push_back(SelectedClassList[1][row]); //dept1
			S2List[2].push_back(SelectedClassList[2][row]); //new ID
			S2List[3].push_back(SelectedClassList[3][row]);// students
		}
	}
	if(nullcheck2 != "9999")
	{
		//second class
		if(semester2 == 1)
		{
			S1List[0].push_back(SelectedClassList[0][column]); //name1
			S1List[1].push_back(SelectedClassList[1][column]); //dept1
			S1List[2].push_back(SelectedClassList[2][column]); //new ID
			S1List[3].push_back(SelectedClassList[3][column]);// students
		}
		if(semester2 == 2)
		{
			S2List[0].push_back(SelectedClassList[0][column]); //name1
			S2List[1].push_back(SelectedClassList[1][column]); //dept1
			S2List[2].push_back(SelectedClassList[2][column]); //new ID
			S2List[3].push_back(SelectedClassList[3][column]);// students
		}
		if(semester2 == 0 && (semester1 == 1 || semester1 == 0))
		{
			S2List[0].push_back(SelectedClassList[0][column]); //name1
			S2List[1].push_back(SelectedClassList[1][column]); //dept1
			S2List[2].push_back(SelectedClassList[2][column]); //new ID
			S2List[3].push_back(SelectedClassList[3][column]);// students
		}
		if(semester2 == 0 && semester1 == 2)
		{
			S1List[0].push_back(SelectedClassList[0][column]); //name1
			S1List[1].push_back(SelectedClassList[1][column]); //dept1
			S1List[2].push_back(SelectedClassList[2][column]); //new ID
			S1List[3].push_back(SelectedClassList[3][column]);// students
		}
	}
}			
bool pausing = true;

//Yay this is so exciting!!!!
//  SortS1IntoBlocks

	bool vector2 = false;   //logorithm cheating to find number of sorts
	counter = 0;
	stop = S1List[0].size();
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
	//copy combovector1 to combovector3
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

		//Sort S1List classes by size
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
				convertedInt1 = CV.StdStringToStdInt(S1List[3][x]);
				convertedInt2 = CV.StdStringToStdInt(S1List[3][x+1]);
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
	if (vector2 == false)// if vector2 is in existance
	{
		//Find Sizes for combo vector2
		int S1size;
		S1size = S1List[0].size();
		int width = S1size;
		int height = S1size;
		int IDsUsed = 0;
		ComboVector2.resize(height);
		ComboVectorInt.resize(height);

		//Size Combo vector appropriately 
		for(int c=0;c<height;c++)
		{
			ComboVector2[c].resize(width);
			ComboVectorInt[c].resize(width);
		}
		//Get Combinations for Classes using ComboVector3/2
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
						int size2 = CV.StdStringToStdInt(SelectedClassList[3][xx]);
						if(CV.StdStringToStdInt(SelectedClassList[3][y]) > CV.StdStringToStdInt(SelectedClassList[3][xx]))
							size2 = CV.StdStringToStdInt(SelectedClassList[3][y]);
						if(xx != y)
						{
							ComboVector2[c1][c2] = size2;
							ComboVector2[c2][c1] = size2;
						}
					}
				}	
			}
			ComboVector2[0][0] = 9999;
			ComboVector2[width-1][width-1] = 9999;
			vector2 = true;
	}
	else //regenerate combovector2
	{
		int S1size2;
		S1size2 = S1List[0].size();
		ComboVector2.resize(0);
		ComboVector2.resize(S1size2);
		for(int copy6=0;copy6<S1size2;copy6++)
		{
			ComboVector2[copy6].resize(S1size2);
		}
		//Go through S1List to find combinations for the new ComboVector2
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
				}  //Create ComboVector2. We want to add 1 to ComboVector 2 if any of the ids from IDs and any of the ids from IDs2 are present in the combined student list vector
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
										if(CV.IDToTeacher(StudentCombinedList[c2][c], SelectedClassList, SElist) == CV.IDToTeacher(StudentCombinedList[c3][c], SelectedClassList, SElist))
										{
											if(std::find(ClassCombos.begin(), ClassCombos.end(), StudentCombinedList[c2][c]) == ClassCombos.end() && std::find(ClassCombos.begin(), ClassCombos.end(), StudentCombinedList[c3][c]) == ClassCombos.end())
											{
												int size1 = CV.StdStringToStdInt(CV.IDToSize(StudentCombinedList[c2][c], SelectedClassList, SElist));
												int size2 = CV.StdStringToStdInt(CV.IDToSize(StudentCombinedList[c3][c], SelectedClassList, SElist));
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
											ComboVector2[position][position2] = ComboVector2[position][position2] +1;   //somehow make it so that it makes classes larger if they have the same teachers
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
		//Sort S1 Classes to Pair them  

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
		if(std::find(IDs.begin(), IDs.end(), row) == IDs.end())      //if IDs doesn't contain row, the Class ID# 
		{
			if(CV.VectorSpaceAvailable(IDs, row) == true)
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
				SortedSlist[0].push_back(id1);//ID   
				SortedSlist[1].push_back(id2);//ID  
				IDs.push_back(id1);
				IDs.push_back(id2);
			}
			else //if(CV.VectorSpaceAvailable(IDs, row) == false && row == height-1)
			{
				SortedSlist[0].push_back(row);//ID
				SortedSlist[1].push_back(9999);//Null ID
				IDs.push_back(row);
			}

		}
	}
	if (divisBy4 == false)
	{
		for(int Cnum=0;Cnum<end+1;Cnum++) //checks through the nubbers in ComboVector to see if they have been paired, if not then they are a class paired with a null class
		{
			if (std::find(IDs.begin(), IDs.end(), Cnum) == IDs.end())
			{
				SortedSlist[0].push_back(Cnum);//ID   
				SortedSlist[1].push_back(9999);// Null ID 
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
		int I = SortedSlist[0][copy];   // find class names
		int I2 = SortedSlist[1][copy];

		if (I2 == 9999)
		{
			S1List[0][copy] = S1ListCopy[0][I]; //name
			S1List[1][copy] = S1ListCopy[1][I]; //dept
			S1List[2][copy] = S1ListCopy[2][I]; //id#
			S1List[3][copy] = S1ListCopy[3][I]; //size
		}
		else
		{
			string name = S1ListCopy[0][I] + " | " + S1ListCopy[0][I2];  //adding values from the larger S1ListCopy to the smaller S1List
			S1List[0][copy] = name;
			string dept = S1ListCopy[1][I] + " | " + S1ListCopy[1][I2];
			S1List[1][copy] = dept;
			S1List[2][copy] = (S1ListCopy[2][I] + "," + S1ListCopy[2][I2]);

			//find sizes
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
			S1List[3][copy] = CV.StdIntToStdString(classSize);
		}
	}
			divisBy4 = true; 
}	
//  SortS2IntoBlocks

	vector2 = false;    //logorithm cheating to find number of sorts
	counter = 0;
	stop = S2List[0].size();
	HowManySorts = 0;
	individualSorts; 
	for(int c=4;c<stop;c=c*2)
		HowManySorts = HowManySorts + 1;

	initialSize = S2List[0].size();
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
	//copy combovector1 to combovector3
	size1 = ComboVector.size();
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

		//Sort S2List classes by size
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
				convertedInt1 = CV.StdStringToStdInt(S2List[3][x]);
				convertedInt2 = CV.StdStringToStdInt(S2List[3][x+1]);
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
	if (vector2 == false)// if vector2 is in existance
	{
		//Find Sizes for combo vector2
		int S2size;
		S2size = S2List[0].size();
		int width = S2size;
		int height = S2size;
		int IDsUsed = 0;
		ComboVector2.resize(height);
		ComboVectorInt.resize(height);

		//Size Combo vector appropriately 
		for(int c=0;c<height;c++)
		{
			ComboVector2[c].resize(width);
			ComboVectorInt[c].resize(width);
		}
		//Get Combinations for Classes using ComboVector3/2
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
						int size2 = CV.StdStringToStdInt(SelectedClassList[3][xx]);
						if(CV.StdStringToStdInt(SelectedClassList[3][y]) > CV.StdStringToStdInt(SelectedClassList[3][xx]))
							size2 = CV.StdStringToStdInt(SelectedClassList[3][y]);
						if(xx != y)
						{
							ComboVector2[c1][c2] = size2;
							ComboVector2[c2][c1] = size2;
						}
					}
				}	
			}
			ComboVector2[0][0] = 9999;
			ComboVector2[width-1][width-1] = 9999;
			vector2 = true;
	}
	else //regenerate combovector2
	{
		int S2size2;
		S2size2 = S2List[0].size();
		ComboVector2.resize(0);
		ComboVector2.resize(S2size2);
		for(int copy6=0;copy6<S2size2;copy6++)
		{
			ComboVector2[copy6].resize(S2size2);
		}
		//Go through S2List to find combinations for the new ComboVector2
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
				}  //Create ComboVector2. We want to add 1 to ComboVector 2 if any of the ids from IDs and any of the ids from IDs2 are present in the combined student list vector
				ClassCombos.resize(0);
				for(int c=0;c<TotalStudents;c++)  
				{
nextStudent2:
					for(int c2=2;c2<17;c2++)
						{
							for(int c3=c2+1;c3<18;c3++)
								{
									if((std::find(IDss.begin(), IDss.end(), StudentCombinedList[c2][c]) != IDss.end() && std::find(IDss2.begin(), IDss2.end(), StudentCombinedList[c3][c]) != IDss2.end()) || (std::find(IDss.begin(), IDss.end(), StudentCombinedList[c3][c]) != IDss.end() && std::find(IDss2.begin(), IDss2.end(), StudentCombinedList[c2][c]) != IDss2.end()))
									{
										if(CV.IDToTeacher(StudentCombinedList[c2][c], SelectedClassList, SElist) == CV.IDToTeacher(StudentCombinedList[c3][c], SelectedClassList, SElist))
										{
											if(std::find(ClassCombos.begin(), ClassCombos.end(), StudentCombinedList[c2][c]) == ClassCombos.end() && std::find(ClassCombos.begin(), ClassCombos.end(), StudentCombinedList[c3][c]) == ClassCombos.end())
											{
												int size1 = CV.StdStringToStdInt(CV.IDToSize(StudentCombinedList[c2][c], SelectedClassList, SElist));
												int size2 = CV.StdStringToStdInt(CV.IDToSize(StudentCombinedList[c3][c], SelectedClassList, SElist));
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
											ComboVector2[position][position2] = ComboVector2[position][position2] +1;   //somehow make it so that it makes classes larger if they have the same teachers
											ComboVector2[position2][position] = ComboVector2[position][position2] +1;
										}
										if(c<TotalStudents-1)
										{
											c = c+1;
											goto nextStudent2;
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
		//Sort S2 Classes to Pair them  

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
		if(std::find(IDs.begin(), IDs.end(), row) == IDs.end())      //if IDs doesn't contain row, the Class ID# 
		{
			if(CV.VectorSpaceAvailable(IDs, row) == true)
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
				SortedSlist[0].push_back(id1);//ID   
				SortedSlist[1].push_back(id2);//ID  
				IDs.push_back(id1);
				IDs.push_back(id2);
			}
			else //if(CV.VectorSpaceAvailable(IDs, row) == false && row == height-1)
			{
				SortedSlist[0].push_back(row);//ID
				SortedSlist[1].push_back(9999);//Null ID
				IDs.push_back(row);
			}

		}
	}
	if (divisBy4 == false)
	{
		for(int Cnum=0;Cnum<end+1;Cnum++) //checks through the nubbers in ComboVector to see if they have been paired, if not then they are a class paired with a null class
		{
			if (std::find(IDs.begin(), IDs.end(), Cnum) == IDs.end())
			{
				SortedSlist[0].push_back(Cnum);//ID   
				SortedSlist[1].push_back(9999);// Null ID 
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
		int I = SortedSlist[0][copy];   // find class names
		int I2 = SortedSlist[1][copy];

		if (I2 == 9999)
		{
			S2List[0][copy] = S2ListCopy[0][I]; //name
			S2List[1][copy] = S2ListCopy[1][I]; //dept
			S2List[2][copy] = S2ListCopy[2][I]; //id#
			S2List[3][copy] = S2ListCopy[3][I]; //size
		}
		else
		{
			string name = S2ListCopy[0][I] + " | " + S2ListCopy[0][I2];  //adding values from the larger S2ListCopy to the smaller S2List
			S2List[0][copy] = name;
			string dept = S2ListCopy[1][I] + " | " + S2ListCopy[1][I2];
			S2List[1][copy] = dept;
			S2List[2][copy] = (S2ListCopy[2][I] + "," + S2ListCopy[2][I2]);

			//find sizes
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
			S2List[3][copy] = CV.StdIntToStdString(classSize);
		}
	}
			divisBy4 = true; 
}

//  GetResults()

for(int blockNum= 0; blockNum < 4; blockNum++)  //S1List
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
			
			//the first one doesn't have the last character
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

//S2List
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
			
			//the first one doesn't have the last character
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

//Removing Electives from Block 4 for S1
vector< vector<int> > ElectivePutterBacker(4, vector<int>(4));
vector<string> blockStrings(4);
string temp = "";

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
int stopping = StudentCombinedList.size();//?

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

//generate comboVector for electives (electiveputterbakcer)
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
		//get Idss from S1ListResult
		for(int move=0;move<S1ListResult[position].size();move++)
		{
			IDss.push_back(S1ListResult[position][move]);
		}

		//Convert IDss and IDss2 from names to id#s
		for(int convert=0; convert<IDss.size();convert++)
		{
			IDss[convert] = CV.NameToID(IDss[convert], SelectedClassList, SElist);
		}
		for(int convert=0; convert<IDss2.size();convert++)
		{
			IDss2[convert] = CV.NameToID(IDss2[convert], SelectedClassList, SElist);
		}
		for(int convert=0; convert<IDss2.size();convert++)
		{
			IDss.push_back(IDss2[convert]);
		}


		//Get Combinations
		for(int c=0;c<TotalStudents;c++)  
		{
next:
			for(int c2=2;c2<17;c2++)
				{
					for(int c3=c2+1;c3<18;c3++)
						{
							//string class1 = StudentCombinedList[c2][c];
							//string class2 = StudentCombinedList[c3][c];
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
//Pick Which Elective Group to Move
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
	string className = S1ListElectiveResult[elective][eStore];
	S1ListElectiveResult[class1].push_back(className);     //it dies here : yes
}
S1ListElectiveResult[elective].resize(0);
for(int eStore=0; eStore<4; eStore++)
{
	for(int eStore2=0; eStore2<S1ListElectiveResult[eStore].size(); eStore2++)
	{
		S1ListResult[eStore].push_back(S1ListElectiveResult[eStore][eStore2]);
	}
}

//Removing Electives from Block 4 for S2																										S2
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

//generate comboVector for electives (electiveputterbakcer)
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
		//get Idss from S2ListResult
		for(int move=0;move<S2ListResult[position].size();move++)
		{
			IDss.push_back(S2ListResult[position][move]);
		}

		//Convert IDss and IDss2 from names to id#s
		for(int convert=0; convert<IDss.size();convert++)
		{
			IDss[convert] = CV.NameToID(IDss[convert], SelectedClassList, SElist);
		}
		for(int convert=0; convert<IDss2.size();convert++)
		{
			IDss2[convert] = CV.NameToID(IDss2[convert], SelectedClassList, SElist);
		}
		for(int convert=0; convert<IDss2.size();convert++)
		{
			IDss.push_back(IDss2[convert]);
		}


		//Get Combinations
		for(int c=0;c<TotalStudents;c++)  
		{
next2:
			for(int c2=2;c2<17;c2++)
				{
					for(int c3=c2+1;c3<18;c3++)
						{
							//string class1 = StudentCombinedList[c2][c];
							//string class2 = StudentCombinedList[c3][c];
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
//Pick Which Elective Group to Move
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
	string className = S2ListElectiveResult[elective][eStore];
	S2ListElectiveResult[class1].push_back(className);
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
int theEnd=0;

//  GetBetterResultsS1

	int comboSize= S1ListResultCopy[0].size() + S1ListResultCopy[1].size() + S1ListResultCopy[2].size() + S1ListResultCopy[3].size();

	ComboVectorString.resize(0);
	ComboVectorString.resize(comboSize);
	for(int cSize=0; cSize<comboSize; cSize++)
	{
		ComboVectorString[cSize].resize(6);
	}


goAgain:
	int tally = 0;
	int combination = 0;
	for(int setZero=0;setZero<comboSize;setZero++)
	{
		for(int setZero2=2;setZero2<6;setZero2++)
		{
			ComboVectorString[setZero][setZero2] = "0";
		}
	}

	for(int oneTo4=0;oneTo4<4;oneTo4++)
	{
		int ending = S1ListResultCopy[oneTo4].size();
		for(int blockSize=0;blockSize<ending;blockSize++)
		{
			it= std::find(SelectedClassList[0].begin(), SelectedClassList[0].end(), S1ListResultCopy[oneTo4][blockSize]);
			int place = it - SelectedClassList[0].begin();
			ComboVectorString[tally][0] = S1ListResultCopy[oneTo4][blockSize];
			ComboVectorString[tally][1] = CV.StdIntToStdString(oneTo4);
//step 1 + 2
			for(int oneTo42=0;oneTo42<4;oneTo42++)
			{
				int ending2 = S1ListResultCopy[oneTo42].size();
				for(int blockSize2=0;blockSize2<ending2;blockSize2++)
				{
					it= std::find(SelectedClassList[0].begin(), SelectedClassList[0].end(), S1ListResultCopy[oneTo42][blockSize2]);
					int place2 = it - SelectedClassList[0].begin();
						if(SelectedClassList[5][place] == SelectedClassList[5][place2] && SelectedClassList[0][place] != SelectedClassList[0][place2])
						{
							int scSize1 = CV.StdStringToStdInt(SelectedClassList[2][place]);
							int scSize2 = CV.StdStringToStdInt(SelectedClassList[2][place2]);
							if(scSize1 > scSize2)
								combination = scSize1;
							else
								combination = scSize2;
						}
						else
						{
							combination = ComboVector[place][place2]; //change to ComboVector3 for the real thing
						}
					if(combination != 9999)
					{
						int cValue = CV.StdStringToStdInt(ComboVectorString[tally][oneTo42+2]);
						ComboVectorString[tally][oneTo42+2] = CV.StdIntToStdString(combination + cValue);
					}
				}
			}
			tally = tally + 1;
		}
	}
	//step 3	
	int lastSubValue=0;
	int current=0;
	int newBlock = 9999;
	int switchClass = 9999;
	int lastValue=9999;
	bool changed = false;

	for(int listClass=0;listClass<comboSize;listClass++)
	{
		for(int block=2;block<6;block++)
		{
			//if(block - 1 != CV.StdStringToStdInt(ComboVectorString[listClass][block]))
			//{
				int currentBlockValue = CV.StdStringToStdInt(ComboVectorString[listClass][(CV.StdStringToStdInt(ComboVectorString[listClass][1]) + 2)]);
				int value = CV.StdStringToStdInt(ComboVectorString[listClass][block]);
				int subtractValue = currentBlockValue - value;
				if(subtractValue >= lastSubValue && subtractValue > 0)
				{
	//step 4		
					lastSubValue = value - CV.StdStringToStdInt(ComboVectorString[listClass][2]);
					switchClass = listClass;
					changed = true;
					newBlock = block -2;
				}
			//}
		}
	}

	//step 5

	if(changed == true)
	{
		int oldBlock = CV.StdStringToStdInt(ComboVectorString[switchClass][1]);
		string name = ComboVectorString[switchClass][0];

			//if(std::find(S1ListResultCopy[blockFind].begin(), S1ListResultCopy[blockFind].end(), name) != S1ListResultCopy[blockFind].end())

		it = std::find(S1ListResultCopy[oldBlock].begin(), S1ListResultCopy[oldBlock].end(), name);
		int spot = it - S1ListResultCopy[oldBlock].begin();
		S1ListResultCopy[newBlock].push_back(S1ListResultCopy[oldBlock][spot]);
		S1ListResult[newBlock].push_back(S1ListResultCopy[oldBlock][spot]);

		S1ListResultCopy[oldBlock][spot] = "9999";
		S1ListResult[oldBlock][spot] = "9999";
		int vectorSize = S1ListResultCopy[oldBlock].size();
		for(int replace=spot;replace<vectorSize;replace++)
		{
			if(replace != vectorSize - 1)
				S1ListResultCopy[oldBlock][replace] = S1ListResultCopy[oldBlock][replace+1];
		}
		int vectorSize2 = S1ListResult[oldBlock].size();
		//for(int replace=spot;replace<vectorSize2;replace++)
		//{
			//if(replace != vectorSize2 - 1)
				//S1ListResult[oldBlock][replace] = S1ListResult[oldBlock][replace+1];
		//}
		
		S1ListResultCopy[oldBlock].resize(vectorSize-1);
		//string classRemoved = S1ListResult[oldBlock][vectorSize2-1];
		//S1ListResult[oldBlock].resize(vectorSize2-1);
		goto goAgain;
	}

	for(int eStore=0; eStore<4; eStore++)
	{
		for(int eStore2=0; eStore2<S1ListElectiveResult[eStore].size(); eStore2++)
		{
			S1ListResultCopy[eStore].push_back(S1ListElectiveResult[eStore][eStore2]);
		}
	}
//  GetBetterResultsS2

	comboSize= S2ListResultCopy[0].size() + S2ListResultCopy[1].size() + S2ListResultCopy[2].size() + S2ListResultCopy[3].size();

	ComboVectorString.resize(0);
	ComboVectorString.resize(comboSize);
	for(int cSize=0; cSize<comboSize; cSize++)
	{
		ComboVectorString[cSize].resize(6);
	}


goAgain2:
	tally = 0;
	combination = 0;
	for(int setZero=0;setZero<comboSize;setZero++)
	{
		for(int setZero2=2;setZero2<6;setZero2++)
		{
			ComboVectorString[setZero][setZero2] = "0";
		}
	}

	for(int oneTo4=0;oneTo4<4;oneTo4++)
	{
		int ending = S2ListResultCopy[oneTo4].size();
		for(int blockSize=0;blockSize<ending;blockSize++)
		{
			it= std::find(SelectedClassList[0].begin(), SelectedClassList[0].end(), S2ListResultCopy[oneTo4][blockSize]);
			int place = it - SelectedClassList[0].begin();
			ComboVectorString[tally][0] = S2ListResultCopy[oneTo4][blockSize];
			ComboVectorString[tally][1] = CV.StdIntToStdString(oneTo4);
//step 1 + 2
			for(int oneTo42=0;oneTo42<4;oneTo42++)
			{
				int ending2 = S2ListResultCopy[oneTo42].size();
				for(int blockSize2=0;blockSize2<ending2;blockSize2++)
				{
					it= std::find(SelectedClassList[0].begin(), SelectedClassList[0].end(), S2ListResultCopy[oneTo42][blockSize2]);
					int place2 = it - SelectedClassList[0].begin();
					if(SelectedClassList[5][place] == SelectedClassList[5][place2] && SelectedClassList[0][place] != SelectedClassList[0][place2])
					{
						int scSize1 = CV.StdStringToStdInt(SelectedClassList[2][place]);
						int scSize2 = CV.StdStringToStdInt(SelectedClassList[2][place2]);
						if(scSize1 > scSize2)
							combination = scSize1;
						else
							combination = scSize2;
					}
					else
					{
						combination = ComboVector[place][place2]; //change to ComboVector3 for the real thing
					}
					if(combination != 9999)
					{
						int cValue = CV.StdStringToStdInt(ComboVectorString[tally][oneTo42+2]);
						ComboVectorString[tally][oneTo42+2] = CV.StdIntToStdString(combination + cValue);
					}
				}
			}
			tally = tally + 1;
		}
	}
	//step 3	
	lastSubValue=0;
	current=0;
	newBlock = 9999;
	switchClass = 9999;
	lastValue=9999;
	changed = false;

	for(int listClass=0;listClass<comboSize;listClass++)
	{
		for(int block=2;block<6;block++)
		{
			//if(block - 1 != CV.StdStringToStdInt(ComboVectorString[listClass][block]))
			//{
				int currentBlockValue = CV.StdStringToStdInt(ComboVectorString[listClass][(CV.StdStringToStdInt(ComboVectorString[listClass][1]) + 2)]);
				int value = CV.StdStringToStdInt(ComboVectorString[listClass][block]);
				int subtractValue = currentBlockValue - value;
				if(subtractValue >= lastSubValue && subtractValue > 0)
				{
	//step 4		
					lastSubValue = value - CV.StdStringToStdInt(ComboVectorString[listClass][2]);
					switchClass = listClass;
					changed = true;
					newBlock = block -2;
				}
			//}
		}
	}

	//step 5

	if(changed == true)
	{
		int oldBlock = CV.StdStringToStdInt(ComboVectorString[switchClass][1]);
		string name = ComboVectorString[switchClass][0];

			//if(std::find(S2ListResultCopy[blockFind].begin(), S2ListResultCopy[blockFind].end(), name) != S2ListResultCopy[blockFind].end())

		it = std::find(S2ListResultCopy[oldBlock].begin(), S2ListResultCopy[oldBlock].end(), name);
		int spot = it - S2ListResultCopy[oldBlock].begin();
		S2ListResultCopy[newBlock].push_back(S2ListResultCopy[oldBlock][spot]);
		S2ListResult[newBlock].push_back(S2ListResultCopy[oldBlock][spot]);

		S2ListResultCopy[oldBlock][spot] = "9999";
		S2ListResult[oldBlock][spot] = "9999";
		int vectorSize = S2ListResultCopy[oldBlock].size();
		for(int replace=spot;replace<vectorSize;replace++)
		{
			if(replace != vectorSize - 1)
				S2ListResultCopy[oldBlock][replace] = S2ListResultCopy[oldBlock][replace+1];
		}
		int vectorSize2 = S2ListResult[oldBlock].size();
		//for(int replace=spot;replace<vectorSize2;replace++)
		//{
			//if(replace != vectorSize2 - 1)
				//S2ListResult[oldBlock][replace] = S2ListResult[oldBlock][replace+1];
		//}
		
		S2ListResultCopy[oldBlock].resize(vectorSize-1);
		//S2ListResult[oldBlock].resize(vectorSize2-1);
		goto goAgain2;
	}

	for(int eStore=0; eStore<4; eStore++)
	{
		for(int eStore2=0; eStore2<S2ListElectiveResult[eStore].size(); eStore2++)
		{
			S2ListResultCopy[eStore].push_back(S2ListElectiveResult[eStore][eStore2]);
		}
	}
//  Scoring


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

//S1 Classes
for(int S1=0;S1<4;S1++)
{
	for(int block1=0;block1<S1ListResultCopy[S1].size();block1++)
	{
		for(int c=0;c<TotalStudents;c++)  
			{
				if(std::find(BlockFilled[S1].begin(), BlockFilled[S1].end(), c) == BlockFilled[S1].end())
				{
					for(int c2=2;c2<18;c2++)
						{
							if(StudentCombinedList[c2][c] == CV.NameToID(S1ListResultCopy[S1][block1], SelectedClassList, SElist))
							{
								scheduleSuccess = scheduleSuccess+1;
								BlockFilled[S1].push_back(c);
							}
						}
				}
			}
	}
}

//S1 Electives
for(int S1=0;S1<4;S1++)
{
	for(int block1=0;block1<S1ListElectiveResultCopy[S1].size();block1++)
	{
		for(int c=0;c<TotalStudents;c++)  
			{
				if(std::find(BlockFilled[S1].begin(), BlockFilled[S1].end(), c) == BlockFilled[S1].end())
				{
					for(int c2=2;c2<18;c2++)
						{
							if(StudentCombinedList[c2][c] == CV.NameToID(S1ListResultCopy[S1][block1], SelectedClassList, SElist))
							{
								scheduleSuccess = scheduleSuccess+1;
								//BlockFilled.push_back(c);
							}
						}
				}
			}
	}
}


//S2 Classes
for(int S2=0;S2<4;S2++)
{
	BlockFilled[S2].resize(0);
	for(int block1=0;block1<S2ListResultCopy[S2].size();block1++)
	{
		for(int c=0;c<TotalStudents;c++)  
			{
				if(std::find(BlockFilled[S2].begin(), BlockFilled[S2].end(), c) == BlockFilled[S2].end())
				{
					for(int c2=2;c2<18;c2++)
						{
							if(StudentCombinedList[c2][c] == CV.NameToID(S2ListResultCopy[S2][block1], SelectedClassList, SElist))
							{
								scheduleSuccess = scheduleSuccess+1;
								BlockFilled[S2].push_back(c);
							}
						}
				}
			}
	}
}

//S2 Electives
for(int S2=0;S2<4;S2++)
{
	for(int block1=0;block1<S2ListElectiveResultCopy[S2].size();block1++)
	{
		for(int c=0;c<TotalStudents;c++)  
			{
				if(std::find(BlockFilled[S2].begin(), BlockFilled[S2].end(), c) == BlockFilled[S2].end())
				{
					for(int c2=2;c2<18;c2++)
						{
							if(StudentCombinedList[c2][c] == CV.NameToID(S2ListResultCopy[S2][block1], SelectedClassList, SElist))
							{
								scheduleSuccess = scheduleSuccess+1;
								//BlockFilled.push_back(c);
							}
						} 
				}
			}
	}
}


//Determine Efficiency:
float SS = scheduleSuccess;
float TR = totalRequests;
float percentage = 0.0; 
percentage = (SS/TR);
//find block 4
int S1block4=9999;
int S2block4=9999;
for(int finder=0;finder<4;finder++)
{
	if(S1ListElectiveResult[finder].size() == 0)
	{
		S1block4 = finder;
		goto block2;
	}
}
block2:
for(int finder=0;finder<4;finder++)
{
	if(S2ListElectiveResult[finder].size() == 0)
	{
		S2block4 = finder;
		goto print;
	}
}

print:
//print out results
ofstream outFile;
outFile.open("Results!!!!!.dat");
outFile<< "Semester 1: " << endl << endl;
for(int blocknum=0;blocknum<4;blocknum++)
{
	int rSize = S1ListResultCopy[blocknum].size();
	if(blocknum == S1block4)
		outFile << endl << "Block: " << 4 << endl << endl;
	else
		outFile << endl << "Block: " << "N/A" << endl << endl;
	for(int r =0;r<rSize;r++)
	{
		//string id = CV.NameToID(S1ListResult[blocknum][r], SelectedClassList, SElist);
		//string teacher = CV.IDToTeacher(id, SelectedClassList, SElist);
		outFile << S1ListResultCopy[blocknum][r] << endl; //add in teachers so i don't have to do it by hand
	}
}
outFile<< endl << "Semester 2: " << endl << endl;
for(int blocknum=0;blocknum<4;blocknum++)
{
	int rSize = S2ListResultCopy[blocknum].size();
	if(blocknum == S2block4)
		outFile << endl << "Block: " << 4 << endl << endl;
	else
		outFile << endl << "Block: " << "N/A" << endl << endl;
	for(int r =0;r<rSize;r++)
	{
		//string id = CV.NameToID(S2ListResult[blocknum][r], SelectedClassList, SElist);
		//string teacher = CV.IDToTeacher(id, SelectedClassList, SElist);
		outFile << S2ListResultCopy[blocknum][r] << endl;
	}
}


outFile<< endl << "Total Requests: " << totalRequests << endl << "Total Successes: " << scheduleSuccess << endl << "Percentage: " << percentage << endl;
outFile.close();


}

