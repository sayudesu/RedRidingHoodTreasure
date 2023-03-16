#pragma once
#include "game.h"

class Fireworks//�ԉ�
{
public:

	Fireworks();//�R���X�g���N�^
	virtual ~Fireworks();//�f�X�g���N�^
	void Init();//������
	void End();//���������
	void Update();//�X�V
	void Draw();//�`��

private:
	int m_pulsCount;
	int m_puls;
	int m_FirePos;
	//�ԉΉ摜�n���h��
	int m_hFireworksRocket[Staging::kFireworksNum];//�ԉΑł��グ�摜
	int m_hFireworks[9];//�ԉΉ摜�n���h��
	//�ԉΈʒu
	int m_fireworksImagePosX[Staging::kFireworksNum];
	int m_fireworksImagePosY[Staging::kFireworksNum];
	//�ԉΑł��グ�摜�ʒu
	int m_fireworksImageRocketLeft;
	int m_fireworksImageRocketTop;
	int m_fireworksImageRocketRight;
	int m_fireworksImageRocketBottom;
	//�ԉΉ摜�ʒu
	int m_fireworksImageLeft[Staging::kFireworksNum];
	int m_fireworksImageTop;
	int m_fireworksImageRight;
	int m_fireworksImageBottom;
	//�J�E���g��
	int m_frameCount[Staging::kFireworksNum];//�ԉ΃A�j���[�V�����J�E���g
	int m_delayCount[Staging::kFireworksNum];//�ԉΕ����̏ꍇ�̃f�B���C������悤
	//�摜�\����\��
	bool m_isFireRocket[Staging::kFireworksNum];//�ԉΔ��ˉ摜�\�����
	bool m_isFire[Staging::kFireworksNum];//�ԉΉ摜�\�����
};

