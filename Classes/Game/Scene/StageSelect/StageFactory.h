#ifndef STAGEFACTORY_H
#define STAGEFACTORY_H

#include <string>
#include <map>
#include <map>

class StageObj;

class StageFactory{
public:
	StageFactory();
	~StageFactory();
    StageObj* order(const std::string &name);
		
private:
	
	void init();

	StageObj* create(std::string name);
	
	std::map<std::string, StageObj*> objContainer;

};
#endif