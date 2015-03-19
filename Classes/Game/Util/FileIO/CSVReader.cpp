#include "CSVReader.h"
#include <sstream>
#include <fstream>
#include <iostream>

#include "cocos2d.h"


//�Ƃ肠�����ǂݍ��݂��Ă݂�
std::vector<std::vector<std::string>> CSVReader::Read(const std::string& filename){

	// Toshikawa
	// cocos2d GetFullFilePath.
	auto fileUtils	= cocos2d::FileUtils::getInstance();
	auto filePath = fileUtils->fullPathForFilename(filename);
	

	std::ifstream ifs(filePath.c_str());
	std::stringstream ss;
	std::string str;
	std::vector<std::vector<std::string>> createList;

	if (!ifs) {
		std::cout << "File error, Not file" << std::endl;
		return createList;
	}

	//�ŏ��̈�s�͂���Ȃ��̂ŉ��s
	std::getline(ifs, str, '\n');
	while (std::getline(ifs, str)){
		str += "\n";
		std::cout << str << std::endl;

		csvParser(str, createList);
	}

	return createList;
}

std::vector<std::vector<std::string>> CSVReader::Read(char* filename,const char* mode){
	//�X�e�[�WURL�@https://dl.dropboxusercontent.com/s/atbitj5qv5puo9o/test.txt

	std::vector<std::vector<std::string>> createList;



	return createList;
}


void CSVReader::csvParser(std::string sorce, std::vector<std::vector<std::string>> &list ){

	char *pSorce;
	std::string str;
	std::vector<std::string> value;

	pSorce = &sorce.at(0);
	while (*pSorce != NULL)
	{
		if (*pSorce == ',' || *pSorce == '\n'){
			//���������X�g�ɒǉ�
			value.push_back(str);
			//���s�R�[�h�ł���Η�̍Ō�܂ňړ�
			if (*pSorce == '\n')break;

			str = "";
		}
		else str += *pSorce;
		pSorce++;
	}

	list.push_back(value);
}
