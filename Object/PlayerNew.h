#pragma once
#include "Vec2.h"

class SelectMenu;

class PlayerNew
{
public:
	PlayerNew();
	virtual ~PlayerNew();

	virtual void Init();
	virtual void End();

	virtual void Update();
	virtual void Draw();

public:
	
	//�摜
	void SetHandle         (int handle) { m_hPlayer = handle;         }
	void SetHandleIdle     (int handle) { m_hPlayerIdle = handle;     }
	void SetHandleLighting (int handle) { m_hPlayerLighting = handle; }
	void SetHandleHealthBer(int handle) { m_hHealthBer = handle;      }


	//�v���C���[�̍��W
	float GetPlayerLeft  () { return static_cast<float>(m_playerLeft);   }
	float GetPlayerTop   () { return static_cast<float>(m_playerTop);    }
	float GetPlayerRight () { return static_cast<float>(m_playerRight);  }
	float GetPlayerBottom() { return static_cast<float>(m_playerBottom); }
	//�v���C���[�̃X�R�A������W
	float GetScoreLeft  () { return static_cast<float>(m_scoreLeft);   }
	float GetScoreTop   () { return static_cast<float>(m_scoreTop);    }
	float GetScoreRight () { return static_cast<float>(m_scoreRight);  }
	float GetScoreBottom() { return static_cast<float>(m_scoreBottom); }

	//�v���C���[�̍��W
	float GetAttackPlayerLeft  () { return static_cast<float>(m_attackPlayerLeft  ); }
	float GeAttacktPlayerTop   () { return static_cast<float>(m_attackPlayerTop   ); }
	float GetAttackPlayerRight () { return static_cast<float>(m_attackPlayerRight ); }
	float GetAttackPlayerBottom() { return static_cast<float>(m_attackPlayerBottom); }

	bool GetGameClear() { return m_isStageClearChangeScene; }//�Q�[���N���A�t���O
	bool GetGameOver () { return m_isDead;                  }//�Q�[���I�[�o�[�t���O
	//���񂾏ꍇ
	bool SetDead() { return m_isStageDeadChangeScene; }

	//Vec2�ł̃v���C���[���W
	Vec2 GetkPlayerPos() { return m_pos; }

	//�v���C���[�̏��
	void GetPos			   (float pos     ) { m_getPos         = pos;       }//�n�ʂɂ���ꍇ�̍��W.y
	void GetLadder		   (bool ladderHit) { m_isLadder       = ladderHit; }//��q�ɓ������Ă��邩�ǂ���
	void GetScaffold	   (bool fall     ) { m_isFall         = fall;      }//�n�ʂɂ��邩�ǂ���
	void GetGoal		   (bool goal     ) { m_isStageClear   = goal;      }//�X�e�[�W�N���A
	void GetEnemyHit	   (bool hit      ) { m_isDamage       = hit;       }//�G�ɓ�����
	void GetEnemyFallenHit (bool hit      ) { m_isDamageFallen = hit;       }//�G�ɓ�����
	void GetPlayerHit	   (bool attack   ) { m_isAttackHit    = attack;    }//�G�ɍU����^����
	void GetEnemyChageHit  (bool attack   ) { m_isDamageCharge = attack;    }//�`���[�W�G�l�~�[����U�����󂯂�
	void GetEnemyChageBlink(bool blink    ) { m_isRushBlink    = blink;     }//�`���[�W�G�l�~�[����U�����󂯂�
	void GetTrapHit        (bool hit      ) { m_trapHit        = hit;       }//�g���b�v�ɓ�����

	void GetScore(int score) { m_score = score; }//�X�R�A����
private:
	void Animation();//�A�j���[�V�����Đ�
private:
	//�v���C���[�ʒu�␳
	void PlayerPosSet();
	//����
	void Operation        ();//����S��
	void OperationStandard();//��{����
	void OperationJump    ();//�W�����v
	void OperationLadder  ();//��q�ł̑���

	void Score();//�X�R�A�v�Z
private:

	//�X�V���
	void UpdateMove();

	//���S����
	void UpdateDead();

private:

	//�O���t�B�b�N�n���h��
	int m_hPlayer;
	int m_hPlayerIdle;//�������Ă��Ȃ����
	int m_hPlayerLighting;
	int m_hHealthBer;
	//�}�b�v�p�O���t�B�b�N�n���h��
	int m_hMapFirst;
	int m_hMapSecond;
	int m_hMapThird;
	int m_hMapFourth;
	int m_hMapFifth;
	int m_hMapChip;
	int m_hMapChipSecond;
	//�T�E���h�n���h��
	int m_hFxJump;
	int m_hRun;
	int m_hLadder;
	int m_hAttack;
	int m_hDead;
	//�J�E���g
	int m_CountLadderSound;//��q����鉹���Đ�����t���[���J�E���g
	int m_CountRunSound;//�������Đ�����t���[���J�E���g
	//����p
	int m_padInput;
	//�v���C���[����p
	int m_playerLeft;
	int m_playerTop;
	int m_playerRight;
	int m_playerBottom;
	//�v���C���[�X�R�A����
	int m_scoreLeft;
	int m_scoreTop;
	int m_scoreRight;
	int m_scoreBottom;
	int m_score;//�X�R�A�v�Z
	//�v���C���[�U���͈͔���p
	int m_attackPlayerLeft;
	int m_attackPlayerTop;
	int m_attackPlayerRight;
	int m_attackPlayerBottom;
	//�L�����N�^�[�摜�ʒu
	int m_charaImagePos;
	int m_charaImageIdlePos;
	int m_charaImageAttackPos;
	int m_charaImageDamagePos;
	int m_charaImageJumpPos;
	int m_charaImageCrouching;
	//�v���C���[�����񂾏ꍇ�̃A�j���V����
	int m_charaImageDeadPosX;
	int m_charaImageDeadPosY;
	
	//�v���C���[�摜�ł̈ʒu
	int m_charaImageLeft;
	int m_charaImageTop;
	int m_charaImageRigth;
	int m_charaImageBottom;
	//�͂���
	int m_count;
	//�A�C�e���{�b�N�X�T�C�Y�ʒu
	int m_boxPosX;
	int m_boxPosY;
	int m_boxPosBottomX;
	int m_boxPosBottomY;
	//�A�C�e���{�b�N�X�̉��o
	int m_stagingBoxX;
	int m_stagingBoxY;
	int m_stagingBoxBottomX;
	int m_stagingBoxBottomY;
	//�v���C���[�̗�
	int m_playerHealthBer;
	int m_playerHealthBerCount;
	int m_playerHealthSizeX;
	int m_playerHealthSizeY;
	//�A�C�e���{�b�N�X�h���b�v
	int m_boxDropCount;
	//�t���[���J�E���g
	int m_frameCount1;
	int m_frameCount2;
	int m_frameCount3;
	int m_frameCountDead;
	bool m_isDeadSound;//���񂾍ۂɃT�E���h���Đ�����
	//���񂾂炻�̂��ƃJ�E���g
	int m_deadCount;
	//���݉��K�ɂ��邩
	int m_hierarchy;
	//�����p
	int m_tip;
	//��ʉ��H
	int m_tempScreenH;//��ʃT�C�Y���擾
	//�d��
	float m_gravity;
	//�v���C���[�w�i�J���[
	float m_playerColorSize;
	//�A�j���[�V����
	bool m_isRunMove;
	bool m_isStopMove;
	bool m_isIdleMove;
	bool m_isAttackMove;
	bool m_isDamageMove;
	bool m_isJumpMove;
	bool m_isCrouchingMove;
	//�A�j���[�V�����Đ��摜�ʒu
	bool m_isRunImagePos;//�����Ă���
	bool m_isJumpImagePos;//�W�����v���Ă���
	//�v���C���[�̉摜�p�x
	int m_playerRad;
	//HP
	bool m_isHealthBer;
	bool m_isDead;
	//���񂾏ꍇ
	bool m_isReset;
	bool m_isTitle;
	//�A�C�e������
	bool m_isGetSword;
	bool m_isItemDrop;
	//�U������
	bool m_isAttack;
	bool m_isEnemyDead;
	//�K�i����
	bool m_isFloorOne;
	//��q����
	bool m_isLadder;
	bool m_isLadderNow;//����q�ɐG���Ă��邩
	//���Ɉړ��ł��Ȃ�
	bool m_isInvaliDown;
	//�L�����N�^�[�̌���
	bool m_isCharaDirection;
	bool m_isCharaIdleDirection;
	//�X�e�[�W�N���A����
	bool m_isStageClear;
	
	//�Q�[���N���A�V�[���؂�ւ����� true = �N���A/false = ���N���A
	bool m_isStageClearChangeScene;
	bool m_isStageDeadChangeScene;//���S
	
	bool m_isMenu;
	//�Q�[���q���g
	bool m_isItemTip;
	bool m_isItemDropTip;
	bool m_isUpTip;

	bool m_isGravity;
	bool m_isFall;
	//���j���[��ʗp
	bool m_isMenuDraw;//���j���[��ʂ�\�����Ă��邩�ǂ���
	//�v���C���[�O���t�B�b�N�T�C�Y
	Vec2 m_playerSize;
	//�L�����N�^�[�̈ʒu
	Vec2 m_pos;
	//�摜�p�L�����N�^�[�ʒu����
	Vec2 m_imagePos;
	Vec2 m_imageBalancePos;
	Vec2 m_underPos;
	//�v���C���[�U���͈�
	Vec2 m_attackPos;
	Vec2 m_attackBottomPos;
	//����
	Vec2 m_vec;

	float m_getPos;

	bool m_isDamage;
	bool m_isDamageFallen;
	bool m_isAttackHit;
	bool m_isDamageCharge;
	bool m_isRushBlink;
	int m_trapHit;//�g���b�v�ɓ������Ď���

	void (PlayerNew::* m_func)();

};
