#pragma once
#include "game.h"
#include "Vec2.h"
class DeadDirection
{
public:
	DeadDirection();
	~DeadDirection();

	void Update();
	void DrawPlayerDead();
	void Draw();
private:
	int m_hPlayer;//�v���C���[�̉摜�`�b�v
	int m_hPlayerDead;//�v���C���[������ł���摜����
	int m_hEffectScreen;//��ʃn���h��
	int m_snowCount;//�Ⴊ������^�C�~���O
	int m_snowDrop;//�Ⴊ�����鐔

	//�摜�ʒu

	Vec2 m_snowPos[Dead::kSnowNum];//��̈ʒu
};

