#ifndef BIGSTONE_H
#define BIGSTONE_H

#include "StageObj.h"

//�X�e�[�W�M�~�b�N�i�΁j
class BigStone : public StageObj{

public:
	/*--------------------
	�R���X�g���N�^
	---------------------*/
	BigStone();
	BigStone(const BigStone&);
	~BigStone();

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

	BigStone* clone() override;

private:
	/*----------------------------------------
	�ʒu�Œ�������ϐ�
	-----------------------------------------*/
	Vec2 clampPos;
};
#endif