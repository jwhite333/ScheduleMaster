#pragma once

ref class ConvertStuff
{
public:
	ConvertStuff(void);
	std::string StdIntToStdString(int);
	int StdStringToStdInt(std::string);
	bool VectorSpaceAvailable(std::vector<int>, int);
	std::string NameToID(std::string, std::vector<std::vector<std::string>>, std::vector<std::vector<std::string>>);
	std::string IDToName(std::string, std::vector<std::vector<std::string>>, std::vector<std::vector<std::string>>);
	std::string IDToTeacher(std::string, std::vector<std::vector<std::string>>, std::vector<std::vector<std::string>>);
	std::string IDToSize(std::string, std::vector<std::vector<std::string>>, std::vector<std::vector<std::string>>);
	std::string EIDToName(std::string id, std::vector<vector<string>>);
private:
	int integer;
	int counter;
	int limit;
};
