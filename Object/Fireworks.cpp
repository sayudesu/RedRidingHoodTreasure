#include <Dxlib.h>
#include "Fireworks.h"
#include "Image.h"
#include "game.h"

Fireworks::Fireworks() :
	m_hSoundFireworksRocket(), m_hSoundFireworksBreak(), m_soundCount(), m_saundTimeCount(),
	m_puls(0), m_pulsCount(0), m_FirePos(),
	m_hFireworks(), m_hFireworksRocket(),//�ԉΗp�摜�n���h��
	m_fireworksImagePosX(), m_fireworksImagePosY(),//�ԉΕ`��ʒu
	m_fireworksImageRocketLeft(0), m_fireworksImageRocketTop(0),//�ԉΉ摜�ʒu
	m_fireworksImageRocketRight(0), m_fireworksImageRocketBottom(0),
	m_fireworksImageLeft(), m_fireworksImageTop(0),//�ԉΉ摜�ʒu
	m_fireworksImageRight(0), m_fireworksImageBottom(0),
	m_frameCount(), m_delayCount(),
	m_isFireRocket(), m_isFire()
{
	//������
	for (int i = 0; i < Staging::kFireworksNum; i++)
	{
		//�T�E���h
		m_hSoundFireworksRocket[i] = LoadSoundMem(Sound::kFireWprkRocket);
		m_hSoundFireworksBreak[i] = LoadSoundMem(Sound::kFireWprkBreak);
		m_soundCount[i] = 0;
		m_saundTimeCount[i] = 0;

		m_FirePos[i] = 0;
		m_fireworksImagePosX[i] = GetRand(Game::kScreenWidth);
		m_fireworksImagePosY[i] = Game::kScreenHeight;
		m_fireworksImageLeft[i] = 96;
		m_frameCount[i] = 0;
		m_isFireRocket[i] = true;
		m_isFire[i] = false;
	}
	//�ŏ��̉ԉ΂̐�
	m_puls = Staging::kFireworksFastNum;

	//
	m_fireworksImageRocketRight = 7;
	m_fireworksImageRocketBottom = 51;
	//
	m_fireworksImageRight = 96;
	m_fireworksImageBottom = 100;

	

	m_hFireworksRocket[0] = LoadGraph(Image::RocketBlue);
	m_hFireworksRocket[1] = LoadGraph(Image::RocketOrange);

	m_hFireworks[0] = LoadGraph(Image::LongOrange);
	m_hFireworks[1] = LoadGraph(Image::LongGreen);
	m_hFireworks[2] = LoadGraph(Image::LongBlue);
	m_hFireworks[3] = LoadGraph(Image::DefaultOrange);
	m_hFireworks[4] = LoadGraph(Image::DefaultGreen);
	m_hFireworks[5] = LoadGraph(Image::DefaultBlue);
	m_hFireworks[6] = LoadGraph(Image::CrystalsOrange);
	m_hFireworks[7] = LoadGraph(Image::CrystalsGreen);
	m_hFireworks[8] = LoadGraph(Image::CrystalsBlue);
}

Fireworks::~Fireworks()
{
	/*���������*/
	for (int i = 0; i < Staging::kFireworksNum; i++)
	{
		//�摜
		DeleteGraph(m_hFireworks[i]);
		//�T�E���h
		DeleteSoundMem(m_hSoundFireworksRocket[i]);
		DeleteSoundMem(m_hSoundFireworksBreak[i]);
	}
}

void Fireworks::Init()
{
}

void Fireworks::End()
{
}

void Fireworks::Update()
{
	m_pulsCount++;//�ԉ΂𑝂₷�܂ł̃J�E���g

	if (m_puls < Staging::kFireworksNum)//�ő�10�܂ŉԉ΂�`��
	{
		if (m_pulsCount == 60)//�P�b��1��ԉ΂𑝂₷
		{
			m_puls++;
			m_pulsCount = 0;//�J�E���g��������
		}
	}
	for (int i = 0; i < m_puls; i++)//�ԉΕ`�悷�鐔������������
	{
		m_frameCount[i]++;
		//m_delayCount[i]++;//�����ԉ΂̏ꍇ�̓f�B���C������
		if (m_frameCount[i] == Staging::kFireworksAnimatioFramenCount)//2�t���[����1��X�V
		{
			m_frameCount[i] = 0;

			if (m_fireworksImagePosY[i] > m_FirePos[i]/*GetRand(Game::kScreenHeight) - 200*/)//�j��ꏊ�ʒu
			{
				m_FirePos[i] = GetRand(Game::kScreenHeight) - 400;//���j������ʒu�������_���Ɍ���
				m_fireworksImagePosY[i] -= Staging::kFireworksRocketSpeed;//��ɍ��W���ړ�
			}
			else//�j��ʒu�ɓ��B�����ꍇ
			{
				printfDx("%d\n", m_soundCount[i]);

				m_soundCount[i]++;

				if (m_soundCount[i] == 65)
				{
					StopSoundMem(m_hSoundFireworksBreak[i]);
					m_saundTimeCount[i] = 0;
				}

				if (CheckSoundMem(m_hSoundFireworksBreak[i]) == 0)//���Ă��Ȃ�������
				{
					
					if (m_soundCount[i] == 1)
					{
						PlaySoundMem(m_hSoundFireworksBreak[i], DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
					}
					m_soundCount[i] = 0;
				}
				else
				{
					m_saundTimeCount[i]++;
				}
	

				m_isFire[i] = true;//�ԉ΂�\��
				m_isFireRocket[i] = false;//�ł��グ���\��
			}

		} 
		
		if (m_isFire[i])//�ł��グ�����j�摜
		{
			//�ԉ�
			if (m_fireworksImageLeft[i] <= 5766)m_fireworksImageLeft[i] += 93;//�A�j���[�V�������Đ�
			else//�ԉ΃A�j���[�V�������I�������
			{
				//���W�����l
				m_fireworksImagePosX[i] = GetRand(Game::kScreenWidth);//�ԉΈʒu��ύX
				m_fireworksImagePosY[i] = Game::kScreenHeight;//��ԉ��Ɉړ�
				m_isFire[i] = false;//�U�����ԉ΂͔�\��
				m_isFireRocket[i] = true;//�ł��グ��\��
				m_fireworksImageLeft[i] = 96;

			}

		}

		if (m_fireworksImageRocketLeft <= 280)m_fireworksImageRocketLeft += 7;//�ԉ΃��P�b�g
		else
		{
			m_fireworksImageRocketLeft = 7;//�摜���̈ʒu�������l�ɖ߂�
		}
	}

}

void Fireworks::Draw()
{
	for (int i = 0; i < m_puls; i++)
	{
		if (m_isFireRocket[i])
		{
			DrawRectRotaGraph(m_fireworksImagePosX[i], m_fireworksImagePosY[i],
				m_fireworksImageRocketLeft, m_fireworksImageRocketTop, m_fireworksImageRocketRight, m_fireworksImageRocketBottom,
				3, DX_PI * 2, m_hFireworksRocket[0], true, false);//�摜��`��
		}
	
		if (m_isFire[i])
		{
			DrawRectRotaGraph(m_fireworksImagePosX[i] + 30, m_fireworksImagePosY[i] - 30,
				m_fireworksImageLeft[i], m_fireworksImageTop, m_fireworksImageRight, m_fireworksImageBottom,
				5, DX_PI * 2, m_hFireworks[3], true, false);//�摜��`��
		}
	}
}
