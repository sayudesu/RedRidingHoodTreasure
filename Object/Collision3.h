#pragma once
#include "Vec2.h"
#include "Collision.h"

class PlayerNew;
class DrawMapStage1;
class EnemyStage3;

class Collision3 :public Collision
{
public:
	Collision3();
	~Collision3();

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
	int HitBarre();//�n�ʂƂ̔���
	int HitBarre2();//�n�ʂƂ̔���
	int HItEnemyLadder();//��q�ƃG�l�~�[�̓����蔻��

	int HitEnemyFireBall();//�����ƒn�ʂ̓����蔻��
	bool HitEnemy();//�v���C���[�ƓG�̓����蔻��

	int HitScore();//�X�R�A����

	int HitFallenRange();//������G�͈̔�
	bool HitFallen();//�������ƃv���C���[�̔���

	bool HitCharge();//�ǐՂ���G�ƃv���C���[�̔���

	int HitTrap();//�g���b�v�ɓ����Ă��邩�ǂ���
	//�n��
public:
	bool m_isStageClear;
	float GetPos() { return m_posY; }
	void GetGoal(bool stageClear) { m_isStageClear = stageClear; }
	void GetDead(bool dead) { m_isGameOver = dead; }
	bool SetDead() { return m_isGameOver; }

	bool m_isDeadSceneChange;//���񂾗p�V�[���؂�ւ�
	void GetDeadChangeScene(bool deadSceneChange) { m_isDeadSceneChange = deadSceneChange; }//���񂾂�V�[����؂�ւ�

	float m_posY;//�v���C���[��Y���W

private:

	bool m_isGameOver;
	float m_enemyPosY[3];//�v���C���[��Y���W
	int m_enemyFireBallPosY;//�v���C���[��Y���W

	float m_landingPos;//���n�ʒu

	bool m_isPlayerPos;


	PlayerNew* m_pPlayer;
	DrawMapStage1* m_pMap;
	EnemyStage3* m_pEnemy;
};

