#pragma once
#include "Vec2.h"

class EnemyStage1
{
public:
	EnemyStage1();
	~EnemyStage1();

	void Init();
	void End();
	void Update();
	void Draw();

private:
	
	void BarrelMove();//�M�̓���

	void fireBallMove();//�M�̓���

	void falleMove();//�ǂ����񓮂�

	void ChargeMove();//�`���[�W����G����

	void npcPos();//�G�̃L�������W�擾

public:

	//�t�@�C�A�[�{�[��
	int  GetLeft()   { return m_posLeft;   }
	int  GetTop()    { return m_posTop;    }
	int  GetRight()  { return m_posRight;  }
	int  GetBottom() { return m_posBottom; }
	//�M
	int  GetBarrelLeft  () { return m_barrelLeft;   }
	int  GetBarrelTop   () { return m_barrelTop;    }
	int  GetBarrelRight () { return m_barrelRight;  }
	int  GetBarrelBottom() { return m_barrelBottom; }
	//�ǂ�����
	int  GetFallenLeft  () { return m_fallenLeft;   }
	int  GetFallenTop   () { return m_fallenTop;    }
	int  GetFallenRight () { return m_fallenRight;  }
	int  GetFallenBottom() { return m_fallenBottom; }
	//�ǂ�����͈�
	int  GetFallenRangeLeft  () { return m_fallenRangeLeft;   }
	int  GetFallenRangeTop   () { return m_fallenRangeTop;    }
	int  GetFallenRangeRight () { return m_fallenRangeRight;  }
	int  GetFallenRangeBottom() { return m_fallenRangeBottom; }
	//�ǂ�����2
	int  GetFallen2Left() { return m_fallen2Left; }
	int  GetFallen2Top() { return m_fallen2Top; }
	int  GetFallen2Right() { return m_fallen2Right; }
	int  GetFallen2Bottom() { return m_fallen2Bottom; }
	//�ǂ�����2�͈�
	int  GetFallenRange2Left() { return m_fallenRange2Left; }
	int  GetFallenRange2Top() { return m_fallenRange2Top; }
	int  GetFallenRange2Right() { return m_fallenRange2Right; }
	int  GetFallenRange2Bottom() { return m_fallenRange2Bottom; }
	//�`���[�W�G�l�~�[
	int  GetChargeLeft() { return m_chargeLeft; }
	int  GetChargeTop() { return m_chargeTop; }
	int  GetChargeRight() { return m_chargeRight; }
	int  GetChargeBottom() { return m_chargeBottom; }
	
public:

	void GetHitFall(int fall  ) { m_fall = fall; }
	void GetPos    (float posY) { m_getPos = posY; }
	void GetEnemyLadder(int num) { m_ladderNum = num; }

	void GetHitFireBallFall(int fall  ) { m_fallFireBall = fall; }
	void GetFireBallPos    (float posY) { m_getFireBallPos = posY; }

	void GetFallenRange(int range) { m_fallenRange = range; }
	void GetFallenRange2(int range) { m_fallenRange2 = range; }

	void GetPlayerPos(Vec2 pos) { m_playerPos = pos; }//�v���C���[�̍��W
	void GetRush(bool rush) { m_isRush = rush; }

private:

	int m_posLeft;
	int m_posTop;
	int m_posRight;
	int m_posBottom;

	int m_barrelLeft;
	int m_barrelTop;
	int m_barrelRight;
	int m_barrelBottom;

	int m_fallenLeft;
	int m_fallenTop;
	int m_fallenRight;
	int m_fallenBottom;

	int m_fallen2Left;
	int m_fallen2Top;
	int m_fallen2Right;
	int m_fallen2Bottom;

	int m_fallenRangeLeft;
	int m_fallenRangeTop;
	int m_fallenRangeRight;
	int m_fallenRangeBottom;

	int m_fallenRange2Left;
	int m_fallenRange2Top;
	int m_fallenRange2Right;
	int m_fallenRange2Bottom;

	int m_chargeLeft;
	int m_chargeTop;
	int m_chargeRight;
	int m_chargeBottom;

	int m_fall;//�n�ʂƂ̔���
	int m_fallFireBall;//�n�ʂƂ̔���

	int m_fallenRange;//�������̓G�͈͔̔���
	int m_fallenRange2;//�������̓G�͈͔̔���

	int m_fallenCount;
	int m_fallenCount2;
	
	int m_ladderNum;
	int m_getFireBallPos;//y���Œ���W

	int m_rushCount;

	float m_getPos;//y���Œ���W
	float m_rad;//�p�x���W�A��

	bool m_isFirstMove;//��������

	bool m_isCourse;//��������
	bool m_isFireBallCourse;//��������

	bool m_isFallenDrop;
	bool m_isCanFallen;

	bool m_isFallenDrop2;
	bool m_isCanFallen2;

	bool m_isRush;
	bool m_isRushBlink;

	Vec2 m_pos;//�t�@�C�A�[�{�[��
	Vec2 m_barrelPos;//�M
	Vec2 m_fallenPos;//�h�b�X���I�Ȃ��
	Vec2 m_fallen2Pos;//�h�b�X���I�Ȃ��
	Vec2 m_chargePos;//�`���[�W����G
	Vec2 m_vec;

	Vec2 m_playerPos;
	Vec2 m_playerSavePos;


};
