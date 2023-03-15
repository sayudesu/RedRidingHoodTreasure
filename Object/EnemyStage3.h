#pragma once
#include "Vec2.h"
#include "EnemyStage1.h"

class EnemyStage3 : public EnemyStage1
{
public:
	EnemyStage3();
	virtual~EnemyStage3();

	virtual void Init();
	virtual void End();
	virtual void Update();
	virtual void Draw();

private:

	void BarrelMove();//�M�̓���

	void fireBallMove();//�M�̓���

	void falleMove();//�ǂ����񓮂�

	void ChargeMove();//�`���[�W����G����

	void UpDownMove();//�㉺�^�������

	void npcPos();//�G�̃L�������W�擾

public:
	//�摜
	//�t�@�C�A�{�[���̉摜
	void SetHandleFireBall(int handle) { m_hFireBall = handle; }

	//�t�@�C�A�[�{�[��
	int  GetLeft  () { return m_posLeft; }
	int  GetTop   () { return m_posTop; }
	int  GetRight () { return m_posRight; }
	int  GetBottom() { return m_posBottom; }
	//�M
	int  GetBarrelLeft  () { return m_barrelLeft[0]; }
	int  GetBarrelTop   () { return m_barrelTop[0]; }
	int  GetBarrelRight () { return m_barrelRight[0]; }
	int  GetBarrelBottom() { return m_barrelBottom[0]; }
	int  GetBarrel2Left() { return m_barrelLeft[1]; }
	int  GetBarrel2Top() { return m_barrelTop[1]; }
	int  GetBarrel2Right() { return m_barrelRight[1]; }
	int  GetBarrel2Bottom() { return m_barrelBottom[1]; }
	int  GetBarrel3Left() { return m_barrelLeft[2]; }
	int  GetBarrel3Top() { return m_barrelTop[2]; }
	int  GetBarrel3Right() { return m_barrelRight[2]; }
	int  GetBarrel3Bottom() { return m_barrelBottom[2]; }
	//�M�X�s�[�h
	void  GetBarrelSpeed(int speed) { m_barrelSpeed = speed; }
	//�ǂ�����
	int  GetFallenLeft  () { return m_fallenLeft; }
	int  GetFallenTop   () { return m_fallenTop; }
	int  GetFallenRight () { return m_fallenRight; }
	int  GetFallenBottom() { return m_fallenBottom; }
	//�ǂ�����͈�
	int  GetFallenRangeLeft  () { return m_fallenRangeLeft; }
	int  GetFallenRangeTop   () { return m_fallenRangeTop; }
	int  GetFallenRangeRight () { return m_fallenRangeRight; }
	int  GetFallenRangeBottom() { return m_fallenRangeBottom; }
	//�ǂ�����2
	int  GetFallen2Left  () { return m_fallen2Left; }
	int  GetFallen2Top   () { return m_fallen2Top; }
	int  GetFallen2Right () { return m_fallen2Right; }
	int  GetFallen2Bottom() { return m_fallen2Bottom; }
	//�ǂ�����2�͈�
	int  GetFallenRange2Left  () { return m_fallenRange2Left; }
	int  GetFallenRange2Top   () { return m_fallenRange2Top; }
	int  GetFallenRange2Right () { return m_fallenRange2Right; }
	int  GetFallenRange2Bottom() { return m_fallenRange2Bottom; }
	//�ǂ�����3
	int  GetFallen3Left() { return m_fallen3Left; }
	int  GetFallen3Top() { return m_fallen3Top; }
	int  GetFallen3Right() { return m_fallen3Right; }
	int  GetFallen3Bottom() { return m_fallen3Bottom; }
	//�ǂ�����3�͈�
	int  GetFallenRange3Left() { return m_fallenRange3Left; }
	int  GetFallenRange3Top() { return m_fallenRange3Top; }
	int  GetFallenRange3Right() { return m_fallenRange3Right; }
	int  GetFallenRange3Bottom() { return m_fallenRange3Bottom; }
	//�ǂ�����4
	int  GetFallen4Left() { return m_fallen4Left; }
	int  GetFallen4Top() { return m_fallen4Top; }
	int  GetFallen4Right() { return m_fallen4Right; }
	int  GetFallen4Bottom() { return m_fallen4Bottom; }
	//�ǂ�����4�͈�
	int  GetFallenRange4Left() { return m_fallenRange4Left; }
	int  GetFallenRange4Top() { return m_fallenRange4Top; }
	int  GetFallenRange4Right() { return m_fallenRange4Right; }
	int  GetFallenRange4Bottom() { return m_fallenRange4Bottom; }

	//�`���[�W�G�l�~�[
	int  GetChargeLeft  () { return m_chargeLeft; }
	int  GetChargeTop   () { return m_chargeTop; }
	int  GetChargeRight () { return m_chargeRight; }
	int  GetChargeBottom() { return m_chargeBottom; }

	//�㉺�^��
	int  GetUpDownLeft  () { return m_upDownLeft; }
	int  GetUpDownTop   () { return m_upDownTop; }
	int  GetUpDownRight () { return m_upDownRight; }
	int  GetUpDownBottom() { return m_upDownBottom; }

	int  GetUpDown2Left() { return m_upDown2Left; }
	int  GetUpDown2Top() { return m_upDown2Top; }
	int  GetUpDown2Right() { return m_upDown2Right; }
	int  GetUpDown2Bottom() { return m_upDown2Bottom; }

	int  GetUpDown3Left() { return m_upDown3Left; }
	int  GetUpDown3Top() { return m_upDown3Top; }
	int  GetUpDown3Right() { return m_upDown3Right; }
	int  GetUpDown3Bottom() { return m_upDown3Bottom; }

	bool GetRushBlink() { return m_isRushBlink; }//�`���[�W�G�l�~�[�ɓ�����Ǝ��ʂ��ǂ���

public:

	void GetHitFall    (int fall)   { m_fall[0] = fall; }
	void GetHitFall2(int fall) { m_fall[1] = fall; }
	void GetHitFall3(int fall) { m_fall[2] = fall; }
	void GetPos        (float posY) { m_getPos[0] = posY; }
	void GetPos2	   (float posY) { m_getPos[1] = posY; }
	void GetPos3	   (float posY) { m_getPos[2] = posY; }
	void GetEnemyLadder(int num)    { m_ladderNum = num; }

	void GetHitFireBallFall(int fall)   { m_fallFireBall = fall; }
	void GetFireBallPos    (float posY) { m_getFireBallPos = posY; }

	void GetFallenRange(int range)  { m_fallenRange = range; }
	void GetFallenRange2(int range) { m_fallenRange2 = range; }

	void GetPlayerPos(Vec2 pos)  { m_playerPos = pos; }//�v���C���[�̍��W
	void GetRush     (bool rush) { m_isRush = rush; }

private:
	//�G�l�~�[�摜
	int m_hFireBall;
	int m_hBarre[3];
	int m_hEnemyImage;
	int m_hNeedle;//�n�ʗp
	int m_hTiles;//�摜�`�b�v
	int m_hCave;//���A�摜
	int m_hUpDown;//�㉺�^����㩉摜
	//���̋ʂ̃T�C�Y
	int m_posLeft;
	int m_posTop;
	int m_posRight;
	int m_posBottom;
	//�M�̃T�C�Y
	int m_barrelLeft[3];
	int m_barrelTop[3];
	int m_barrelRight[3];
	int m_barrelBottom[3];
	//�M�T�C�Y�v���X
	int m_barrelSizePulsX;
	//�h�b�X���̃T�C�Y
	int m_fallenLeft;
	int m_fallenTop;
	int m_fallenRight;
	int m_fallenBottom;
	//�h�b�X���Q�̃T�C�Y
	int m_fallen2Left;
	int m_fallen2Top;
	int m_fallen2Right;
	int m_fallen2Bottom;
	//�h�b�X��3�̃T�C�Y
	int m_fallen3Left;
	int m_fallen3Top;
	int m_fallen3Right;
	int m_fallen3Bottom;
	//�h�b�X��4�̃T�C�Y
	int m_fallen4Left;
	int m_fallen4Top;
	int m_fallen4Right;
	int m_fallen4Bottom;
	//�h�b�X���̓����蔻��̃T�C�Y
	int m_fallenRangeLeft;
	int m_fallenRangeTop;
	int m_fallenRangeRight;
	int m_fallenRangeBottom;
	//�h�b�X���Q�̓����蔻��̃T�C�Y
	int m_fallenRange2Left;
	int m_fallenRange2Top;
	int m_fallenRange2Right;
	int m_fallenRange2Bottom;
	//�h�b�X��3�̓����蔻��̃T�C�Y
	int m_fallenRange3Left;
	int m_fallenRange3Top;
	int m_fallenRange3Right;
	int m_fallenRange3Bottom;
	//�h�b�X��4�̓����蔻��̃T�C�Y
	int m_fallenRange4Left;
	int m_fallenRange4Top;
	int m_fallenRange4Right;
	int m_fallenRange4Bottom;
	//���s����G�̃T�C�Y
	int m_chargeLeft;
	int m_chargeTop;
	int m_chargeRight;
	int m_chargeBottom;
	//�㉺�^�������
	int m_upDownLeft;
	int m_upDownTop;
	int m_upDownRight;
	int m_upDownBottom;
	int m_upDown2Left;
	int m_upDown2Top;
	int m_upDown2Right;
	int m_upDown2Bottom;
	int m_upDown3Left;
	int m_upDown3Top;
	int m_upDown3Right;
	int m_upDown3Bottom;

	//�t�@�C�A�{�[���̉摜�ʒu
	int m_fireBallImagePosX;
	int m_fireBallImagePosY;
	bool m_fireImageDirection;//�摜�̕���
	//�M�i�C�m�V�V�j�̉摜�ʒu
	int m_barreImagePosX[3];
	bool m_barreImageDirection[3];//�摜�̕���

	//㩂̉摜�ʒu
	int m_upDownLeftImageX;
	int m_upDownLeftImageY;
	int m_upDownLeft2ImageX;
	int m_upDownLeft2ImageY;
	int m_upDownLeft3ImageX;
	int m_upDownLeft3ImageY;
	int m_upDownRad;//�p�x

	int m_barrelSpeed;//�M�̑��x

	int m_fall[3];//�n�ʂƂ̔���
	int m_fallFireBall;//�n�ʂƂ̔���

	int m_fallenRange;//�������̓G�͈͔̔���
	int m_fallenRange2;//�������̓G�͈͔̔���
	int m_fallenRange3;//�������̓G�͈͔̔���
	int m_fallenRange4;//�������̓G�͈͔̔���

	//�t���[���J�E���g��
	int m_fallenCount;
	int m_fallenCount2;
	int m_fallenCount3;
	int m_fallenCount4;
	int m_frameCountFireImage;
	int m_frameCountBarreImage[3];

	int m_ladderNum;
	int m_getFireBallPos;//y���Œ���W

	int m_fireRad;//�p�x���W�A��

	float m_fallenUpSpeed;//
	float m_fallenUpSpeed2;//
	float m_fallenUpSpeed3;//
	float m_fallenUpSpeed4;//

	float m_getPos[3];//y���Œ���W
	float m_chargeSpeed;
	float m_length;
	int   m_rushCount;

	bool m_isFirstMove;//��������

	bool m_isCourse[3];//��������
	bool m_isFireBallCourse;//��������

	bool m_isFallenDrop;
	bool m_isCanFallen;
	bool m_isFallenDrop2;
	bool m_isCanFallen2;
	bool m_isFallenDrop3;
	bool m_isCanFallen3;
	bool m_isFallenDrop4;
	bool m_isCanFallen4;

	bool m_isFallenUp;
	bool m_isFallenUp2;
	bool m_isFallenUp3;
	bool m_isFallenUp4;

	bool m_isBarreMove;//2�̂̓G���������ǂ���

	bool m_isUpDown;//�㉺�ǂ���ɂ��邩
	bool m_isUpDown2;//�㉺�ǂ���ɂ��邩
	bool m_isUpDown3;//�㉺�ǂ���ɂ��邩

	bool m_isRush;//�ːi����G�������邩�ǂ���
	bool m_isRushBlink;//�ːi����G�������Ă��邩


	Vec2 m_pos;//�t�@�C�A�[�{�[��
	Vec2 m_barrelPos[3];//�M
	Vec2 m_fallenPos;//�h�b�X���I�Ȃ��
	Vec2 m_fallen2Pos;//�h�b�X���I�Ȃ��
	Vec2 m_fallen3Pos;//�h�b�X���I�Ȃ��
	Vec2 m_fallen4Pos;//�h�b�X���I�Ȃ��
	Vec2 m_chargePos;//�`���[�W����G
	Vec2 m_upDownPos;//�㉺�^�������
	Vec2 m_upDown2Pos;//�㉺�^�������
	Vec2 m_upDown3Pos;//�㉺�^�������
	Vec2 m_vec[3];

	Vec2 m_playerPos;
	Vec2 m_playerSavePos;


};



