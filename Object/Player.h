#pragma once
#include "Vec2.h"

class Enemy;
class Player
{
public:
	Player();
	virtual ~Player();

	virtual void Init();
	virtual void End();

	virtual void Update();
	virtual void Draw();

public:

	//�摜
	void SetHandle(int handle) { m_hPlayer = handle; }
	void SetHandleIdle(int handle) { m_hPlayerIdle = handle; }
	void SetHandleLighting(int handle) { m_hPlayerLighting = handle; }
	void SetHandleHealthBer(int handle) { m_hHealthBer = handle; }

private:

	//����
	void Operation();
	//���
	void Condition();
	//�n�ʔ���
	int FieldJudgement();
	//��q����
	int CheckHit();
	//�A�C�e���{�b�N�X����
	void BoxJudgement();
	//��������
	void CheckFall();
	//�G�Ƃ̓����蔻��
	bool EnemyHit();
	//HP�Ǘ�
	void HealthControl();

private:

	void UpdateMove();

	void MenuStop();

private:

	//�O���t�B�b�N�n���h��
	int m_hPlayer;
	int m_hPlayerIdle;
	int m_hPlayerLighting;
	int m_hHealthBer;
	//�L�����N�^�[�摜�ʒu
	int m_charaImagePos;
	int m_charaImageIdlePos;
	int m_charaImageAttackPos;
	int m_charaImageDamagePos;
	//�A�C�e���{�b�N�X�T�C�Y�ʒu
	int m_boxPosX;
	int m_boxPosY;
	int m_boxPosBottomX;
	int m_boxPosBottomY;
	//�v���C���[�̗�
	int m_playerHealthBer;
	int m_playerHealthBerCount;
	int m_playerHealthSizeX;
	int m_playerHealthSizeY;
	//�A�C�e���{�b�N�X�h���b�v
	int m_boxDropCount;
	//�t���[���J�E���g
	int m_frameCount;
	//���݉��K�ɂ��邩
	int m_hierarchy;
	//�d��
	float m_gravity;
	//�A�j���[�V����
	bool m_isRunMoveLeft;
	bool m_isRunMoveRight;
	bool m_isIdleMove;
	bool m_isAttackMove;
	bool m_isDamageMove;
	//HP�\��
	bool m_isHealthBer;
	//�A�C�e������
	bool m_isGetSword;
	//�K�i����
	bool m_isFloorOne;
	//��q����
	bool m_isLadder;
	//���Ɉړ��ł��Ȃ�
	bool m_isInvaliDown;
	//�L�����N�^�[�̌���
	bool m_isCharaDirection;
	bool m_isCharaIdleDirection;
	//�v���C���[�O���t�B�b�N�T�C�Y
	Vec2 m_playerSize;
	//�L�����N�^�[�̈ʒu
	Vec2 m_pos;
	//�摜�p�L�����N�^�[�ʒu����
	Vec2 m_imagePos;
	Vec2 m_imageBalancePos;
	Vec2 m_underPos;
	//����
	Vec2 m_vec;
	
	void (Player::* m_func)();
	Enemy* m_pEnemy;
};
