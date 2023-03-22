#include "DxLib.h"
#include "game.h"
#include "Scene/SceneManager.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetWindowSizeChangeEnableFlag(true);
	SetAlwaysRunFlag(true);
	// window���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	// �E�C���h�E���ݒ�
	SetMainWindowText(Game::kTitleText);
	//�}�E�X�J�[�\���\��
	SetMouseDispFlag(Game::kMouseMode);
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);
	//CreateFontToHandle(Game::kFontName,64,-1,-1);

	SetChangeScreenModeGraphicsSystemResetFlag(false);//�t���X�N���[���؂�ւ��p

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	PCSTR font_path = "Data/Font/Silver.ttf"; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) 
	{
	}
	else
	{
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}
	//�t�H���g�ύX
	ChangeFont("Silver");

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);
	//�t���X�N���[�����ǂ���
	bool isScreenSize = false;
	bool isTrigger = false;//�{�^���m�F
	// �ŏ��̃V�[���̏�����
	SceneManager scene;
	scene.Init();

	while (ProcessMessage() == 0)
	{
		LONGLONG  time = GetNowHiPerformanceCount();

		// ��ʂ̃N���A
		ClearDrawScreen();

		
		//�t���X�N���[���ݒ�
		if (CheckHitKey(KEY_INPUT_LALT))
		{
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				if (!isTrigger)
				{
					isScreenSize = !isScreenSize;
					ChangeWindowMode(isScreenSize);
					SetDrawScreen(DX_SCREEN_BACK);//�`�����Ē�`
				}
				
				isScreenSize = true;
			}
			else
			{
				isScreenSize = false;
			}
		}
		

		//�X�V����
		scene.Update();

		//�\������
		scene.Draw();

#if false		
		auto fps = GetFPS();// Frame Per Second
		auto drawcall = GetDrawCallCount();// �`�施�ߐ�
		DrawFormatString(200, 200, 0xffffff, "FPS=%2.2f", fps);
		DrawFormatString(200, 230, 0xffffff, "DC=%d", drawcall);
#endif

		//����ʂ�\��ʂ����ւ���
		ScreenFlip();

		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		// fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	//�������̉��
	scene.End();
	//DeleteFontToHandle(font);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}