#ifndef SMALLSTONE_H
#define SMALLSTONE_H

#include "StageObj.h"

//�X�e�[�W�M�~�b�N�i�΁j
class SmallStone : public StageObj{

public:
	/*--------------------
	�R���X�g���N�^
	---------------------*/
	SmallStone();
	SmallStone(const SmallStone&);
	~SmallStone();

	/**---------------
	�X�V
	float deltatime �t���[��
	------------------*/
	void update(float deltatime) override;

	/**---------------
	�Փˏ���
	Node* node �Փˑ���
	------------------*/
	void onContact(Node* node) override;

	/**
	�ʒu�ݒ�
	float x �`��ʒu x
	float y �`��ʒu y
	*/
	void setPosition(const float x, const float y) override;

	/*-----------------------------------
	�`��O�Ɉ��Ă΂�邾��
	------------------------------------*/
	void onEnter() override;

	bool isDead() override;

	SmallStone* clone() override;

private:
	/*----------------------------------------
	�ʒu�Œ�������ϐ�
	-----------------------------------------*/
	Vec2 clampPos;
};
#endif