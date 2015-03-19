#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <string>
#include <map>

class Enemy;

class EnemyFactory{
public:

	Enemy* order(const std::string &name);

private:

	Enemy* create(const std::string name);

};
#endif