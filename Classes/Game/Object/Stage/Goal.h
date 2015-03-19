#ifndef GOAL_H
#define GOAL_H

#include "StageObj.h"

class Goal : public StageObj{

public:
	Goal();
	Goal(const Goal&);
	~Goal();

	void update(float deltatime) override;

	void onContact(Node* node) override;

	void setPosition(const float x, const float y) override;

	void onEnter() override;

	bool isDead() override;

	Goal* clone() override;

private:
	Vec2* clampPos;
};
#endif