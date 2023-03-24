#pragma once
#include "Vec2.h"

namespace Object
{
	constexpr int kNum = 16;
}

class PlayerNew;
class DrawMapStage1;
class EnemyStage1;

class Collision
{
public:
	Collision();
	~Collision();

	void Init();
	void Update();
	void Draw();

//�����蔻��
public:
	bool HitObject();//�n�ʂƂ̓����蔻��
	bool HItLadder();//��q�Ƃ̓����蔻��
	bool HitPlayer();//�v���C���[�ƓG�̓����蔻��
	bool HitGoal();//�S�[���Ƃ̔���

    int HitEnemyObject();//�G�ƒn�ʂƂ̓����蔻��
	int HItEnemyLadder();//��q�ƃG�l�~�[�̓����蔻��

	int HitEnemyFireBall();//�����ƒn�ʂ̓����蔻��
	bool HitEnemy();//�v���C���[�ƓG�̓����蔻��

	int HitScore();//�X�R�A����

	int HitFallenRange();//������G�͈̔�
	bool HitFallen();//�������ƃv���C���[�̔���

	bool HitCharge();//�ǐՂ���G�ƃv���C���[�̔���
//�n��
public:
	bool m_isStageClear;
	float GetPos () { return m_posY; }
	void GetGoal(bool stageClear) { m_isStageClear = stageClear; }
	void GetDead(bool dead) { m_isGameOver = dead; }
	bool SetDead() { return m_isGameOver; }

	bool m_isDeadSceneChange;//���񂾗p�V�[���؂�ւ�
    void GetDeadChangeScene(bool deadSceneChange) { m_isDeadSceneChange = deadSceneChange; }//���񂾂�V�[����؂�ւ�

	float m_posY;//�v���C���[��Y���W

private:

	int m_floorLeftPos[Object::kNum];//�n�ʈʒu
	int m_floorTopPos[Object::kNum];//�n�ʈʒu
	int m_floorRightPos[Object::kNum];//�n�ʈʒu
	int m_floorBottomPos[Object::kNum];//�n�ʈʒu

	int m_playerYposMove[Object::kNum];//�v���C���[�̈ʒu�𒲐�
	int m_playerYPulsNum[Object::kNum];

	bool m_isGameOver;
	float m_enemyPosY;//�v���C���[��Y���W
	int m_enemyFireBallPosY;//�v���C���[��Y���W

	float m_landingPos;//���n�ʒu

	bool m_isPlayerPos;


	PlayerNew* m_pPlayer;
	DrawMapStage1* m_pMap;
	EnemyStage1* m_pEnemy;
};

