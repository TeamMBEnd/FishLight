#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

USING_NS_CC;
/**
	@�G�l�~�[�̃C���^�[�t�F�[�X��YO
*/
class Enemy : public cocos2d::Sprite {
public:
	/**
		@�R���X�g���N�^
	*/
	Enemy();

	/**
		@�f�X�g���N�^
	*/
	~Enemy() override;

	/**
		@������
	*/
	virtual bool init();

	/**
		@�G�l�~�[�̃X�v���C�g�ݒ�
	*/
	virtual Sprite* enemyCreate(cocos2d::Point position);

	/**
		@�X�V

		@param	deltaTime�@�f���^����
	*/
	virtual void update(float deltaTime, Vec2 targetPos);
	virtual void onContact(Node* node);
	void releaseObj();
	bool dead();
	void checkDistance(Sprite* sprite, Vec2 targetPos);

	CREATE_FUNC(Enemy);
protected:
	bool mIsDead;
	int mDiffDistanceX;
	int mDiffDistanceY;
	int mPlayerDistance;
	Sprite* sprite;
};

#endif