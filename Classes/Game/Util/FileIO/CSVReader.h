#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <map>
#include <vector>

class CSVReader{
public :
	std::vector<std::vector<std::string>> Read(const std::string& filename);

	std::vector<std::vector<std::string>> Read(char* filename,const char* mode);

private:
	void csvParser(std::string sorce, std::vector<std::vector<std::string>> &list);
};
#endif