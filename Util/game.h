#pragma once
#include "game.h"
//#define _DEBUG 

//�O���[�o���ϐ��̏�ʌ݊��̗l�ȕ�
_declspec(selectany) int stageNum = 0;

namespace Game
{
//#ifdef _DEBUG	
	// �E�C���h�E���[�h�ݒ�
	constexpr bool kWindowMode = true;

	// �}�E�X�J�[�\���\��
	constexpr bool kMouseMode = true;
	// �E�C���h�E��
	const char* const kTitleText = "�Ԃ�����̍���";
	//�t�H���g��
	const char* const kFontName = "Eras Demi ITC"; 
	//const char* const kFontNameJp = "Data/Font/GAGAGAGA FREE.otf";
	const char* const kFontNameJp = "Ark Pixel 10px monospaced ja";
	//const char* const kFontName = "Data/Font/GAGAGAGA FREE";
	constexpr int kFontSize = 64;
	// �E�C���h�E�T�C�Y
	/*constexpr int kScreenWidth = 1280;
	constexpr int kScreenHeight = 720;*/
	constexpr int kScreenWidth = 1920;
	constexpr int kScreenHeight = 1080;
	// �J���[���[�h
	constexpr int kColorDepth = 32;		// 32 or 16
};

namespace Stage1
{
	//���̉���
	constexpr int kBoxWidth = 150;
	//���̍���
	constexpr int kBoxHeight = 20;
	//�i��
	constexpr int kBoxStep = 5;
	constexpr int kBoxStep2 = 5;//12;

	//��K////////////////////////////////////////////////////////////////////////////////
	constexpr int kBox1X = 0;                                   //��
	constexpr int kBox1Y = Game::kScreenHeight - 60;            //��
	constexpr int kBoxBottom1X = kBox1X + Game::kScreenWidth / 2;//�E
	constexpr int kBoxBottom1Y = kBox1Y + kBoxHeight;             //��

	//��K��i��
	constexpr int kBox2X = kBoxBottom1X;
	constexpr int kBox2Y = kBox1Y - kBoxStep;
	constexpr int kBoxBottom2X = kBox2X + kBoxWidth;
	constexpr int kBoxBottom2Y = kBox2Y + kBoxHeight;

	//��K��i��
	constexpr int kBox3X = kBoxBottom2X;
	constexpr int kBox3Y = kBox2Y - kBoxStep;
	constexpr int kBoxBottom3X = kBox3X + kBoxWidth;
	constexpr int kBoxBottom3Y = kBox3Y + kBoxHeight;

	//��K�O�i��
	constexpr int kBox4X = kBoxBottom3X;
	constexpr int kBox4Y = kBox3Y - kBoxStep;
	constexpr int kBoxBottom4X = kBox4X + kBoxWidth;
	constexpr int kBoxBottom4Y = kBox4Y + kBoxHeight;

	//��K�l�i��
	constexpr int kBox5X = kBoxBottom4X;
	constexpr int kBox5Y = kBox4Y - kBoxStep;
	constexpr int kBoxBottom5X = kBox5X + kBoxWidth;
	constexpr int kBoxBottom5Y = kBox5Y + kBoxHeight;

	//��K�ܒi��
	constexpr int kBox6X = kBoxBottom5X;
	constexpr int kBox6Y = kBox5Y - kBoxStep;
	constexpr int kBoxBottom6X = kBox6X + kBoxWidth;
	constexpr int kBoxBottom6Y = kBox6Y + kBoxHeight;

	//��K�Z�i��
	constexpr int kBox7X = kBoxBottom6X;
	constexpr int kBox7Y = kBox6Y - kBoxStep;
	constexpr int kBoxBottom7X = kBox7X + kBoxWidth;
	constexpr int kBoxBottom7Y = kBox7Y + kBoxHeight;

	//��K���i��
	constexpr int kBox8X = kBoxBottom7X;
	constexpr int kBox8Y = kBox7Y - kBoxStep;
	constexpr int kBoxBottom8X = kBox8X + kBoxWidth;
	constexpr int kBoxBottom8Y = kBox8Y + kBoxHeight;

	//��K///////////////////////////////////////////////////////////////////////////

	constexpr int kBox1Xs = 100;
	constexpr int kBox1Ys = Game::kScreenHeight - 250 - 20;
	constexpr int kBoxBottom1Xs = kBox1Xs + kBoxWidth;
	constexpr int koxBottom1Ys = kBox1Ys + kBoxHeight;

	constexpr int kBox2Xs = kBoxBottom1Xs;
	constexpr int kBox2Ys = kBox1Ys + kBoxStep;
	constexpr int kBoxBottom2Xs = kBox2Xs + kBoxWidth;
	constexpr int kBoxBottom2Ys = kBox2Ys + kBoxHeight;

	constexpr int kBox3Xs = kBoxBottom2Xs;
	constexpr int kBox3Ys = kBox2Ys + kBoxStep;
	constexpr int kBoxBottom3Xs = kBox3Xs + kBoxWidth;
	constexpr int kBoxBottom3Ys = kBox3Ys + kBoxHeight;


	constexpr int kBox4Xs = kBoxBottom3Xs;
	constexpr int kBox4Ys = kBox3Ys + kBoxStep;
	constexpr int kBoxBottom4Xs = kBox4Xs + kBoxWidth;
	constexpr int kBoxBottom4Ys = kBox4Ys + kBoxHeight;


	constexpr int kBox5Xs = kBoxBottom4Xs;
	constexpr int kBox5Ys = kBox4Ys + kBoxStep;
	constexpr int kBoxBottom5Xs = kBox5Xs + kBoxWidth;
	constexpr int kBoxBottom5Ys = kBox5Ys + kBoxHeight;


	constexpr int kBox6Xs = kBoxBottom5Xs;
	constexpr int kBox6Ys = kBox5Ys + kBoxStep;
	constexpr int kBoxBottom6Xs = kBox6Xs + kBoxWidth;
	constexpr int kBoxBottom6Ys = kBox6Ys + kBoxHeight;


	constexpr int kBox7Xs = kBoxBottom6Xs;
	constexpr int kBox7Ys = kBox6Ys + kBoxStep;
	constexpr int kBoxBottom7Xs = kBox7Xs + kBoxWidth;
	constexpr int kBoxBottom7Ys = kBox7Ys + kBoxHeight;


	constexpr int kBox8Xs = kBoxBottom7Xs;
	constexpr int kBox8Ys = kBox7Ys + kBoxStep;
	constexpr int kBoxBottom8Xs = Game::kScreenWidth - 100;
	constexpr int kBoxBottom8Ys = kBox8Ys + kBoxHeight;

	//�O�K//////////////////////////////////////////////////////////////////////////////////////////////
	constexpr int kBox1Xt = 200;                                   //��
	constexpr int kBox1Yt = Game::kScreenHeight - 400 - 20;             //��
	constexpr int kBoxBottom1Xt = kBox1Xt + Game::kScreenWidth / 2;//�E
	constexpr int kBoxBottom1Yt = kBox1Yt + kBoxHeight;            //��

	//��K��i��
	constexpr int kBox2Xt = kBoxBottom1Xt;
	constexpr int kBox2Yt = kBox1Yt - kBoxStep;
	constexpr int kBoxBottom2Xt = kBox2Xt + kBoxWidth;
	constexpr int kBoxBottom2Yt = kBox2Yt + kBoxHeight;

	//��K��i��
	constexpr int kBox3Xt = kBoxBottom2Xt;
	constexpr int kBox3Yt = kBox2Yt - kBoxStep;
	constexpr int kBoxBottom3Xt = kBox3Xt + kBoxWidth;
	constexpr int kBoxBottom3Yt = kBox3Yt + kBoxHeight;

	//��K�O�i��
	constexpr int kBox4Xt = kBoxBottom3Xt;
	constexpr int kBox4Yt = kBox3Yt - kBoxStep;
	constexpr int kBoxBottom4Xt = kBox4Xt + kBoxWidth;
	constexpr int kBoxBottom4Yt = kBox4Yt + kBoxHeight;

	//��K�l�i��
	constexpr int kBox5Xt = kBoxBottom4Xt;
	constexpr int kBox5Yt = kBox4Yt - kBoxStep;
	constexpr int kBoxBottom5Xt = kBox5Xt + kBoxWidth;
	constexpr int kBoxBottom5Yt = kBox5Yt + kBoxHeight;

	//��K�ܒi��
	constexpr int kBox6Xt = kBoxBottom5Xt;
	constexpr int kBox6Yt = kBox5Yt - kBoxStep;
	constexpr int kBoxBottom6Xt = kBox6Xt + kBoxWidth;
	constexpr int kBoxBottom6Yt = kBox6Yt + kBoxHeight;

	//��K�Z�i��
	constexpr int kBox7Xt = kBoxBottom6Xt;
	constexpr int kBox7Yt = kBox6Yt - kBoxStep;
	constexpr int kBoxBottom7Xt = kBox7Xt + kBoxWidth;
	constexpr int kBoxBottom7Yt = kBox7Yt + kBoxHeight;

	//��K���i��
	constexpr int kBox8Xt = kBoxBottom7Xt;
	constexpr int kBox8Yt = kBox7Yt - kBoxStep;
	constexpr int kBoxBottom8Xt = kBox8Xt + kBoxWidth;
	constexpr int kBoxBottom8Yt = kBox8Yt + kBoxHeight;

	//��q///////////////////////////////////////////////////////////////////////////////
	//����q
	constexpr int kLadder1X = Game::kScreenWidth - 150;
	constexpr int kLadder1Y = Game::kScreenHeight - 240;
	constexpr int kLadderBottom1X = kLadder1X + 10;
	constexpr int kLadderBottom1Y = kLadder1Y + 115;
	//����q
	constexpr int kLadder2X = 300;
	constexpr int kLadder2Y = Game::kScreenHeight - 425;
	constexpr int kLadderBottom2X = kLadder2X + 10;
	constexpr int kLadderBottom2Y = kLadder2Y + 125;

	//�Q�[���N���A�����ʒu//////////////////////////////////////////////////////////////////////////
	constexpr int kGoalX = Game::kScreenWidth - 880;
	constexpr int kGoalY = kBox1Yt - 50;
	constexpr int kGoalBottomX = kGoalX + 50;
	constexpr int kGoalBottomY = kGoalY + 50;
}


namespace Stage2
{
	//���̉���
	constexpr int kBoxWidth = 150;
	//���̍���
	constexpr int kBoxHeight = 20;
	//�i��
	constexpr int kBoxStep = 5;
	constexpr int kBoxStep2 = 5;//12;

	//��K////////////////////////////////////////////////////////////////////////////////
	constexpr int kBox1X = 0;                                   //��
	constexpr int kBox1Y = Game::kScreenHeight - 60;            //��
	constexpr int kBoxBottom1X = kBox1X + Game::kScreenWidth / 2;//�E
	constexpr int kBoxBottom1Y = kBox1Y + kBoxHeight;             //��

	//��K��i��
	constexpr int kBox2X = kBoxBottom1X;
	constexpr int kBox2Y = kBox1Y - kBoxStep;
	constexpr int kBoxBottom2X = kBox2X + kBoxWidth;
	constexpr int kBoxBottom2Y = kBox2Y + kBoxHeight;

	//��K��i��
	constexpr int kBox3X = kBoxBottom2X;
	constexpr int kBox3Y = kBox2Y - kBoxStep;
	constexpr int kBoxBottom3X = kBox3X + kBoxWidth;
	constexpr int kBoxBottom3Y = kBox3Y + kBoxHeight;

	//��K�O�i��
	constexpr int kBox4X = kBoxBottom3X;
	constexpr int kBox4Y = kBox3Y - kBoxStep;
	constexpr int kBoxBottom4X = kBox4X + kBoxWidth;
	constexpr int kBoxBottom4Y = kBox4Y + kBoxHeight;

	//��K�l�i��
	constexpr int kBox5X = kBoxBottom4X;
	constexpr int kBox5Y = kBox4Y - kBoxStep;
	constexpr int kBoxBottom5X = kBox5X + kBoxWidth;
	constexpr int kBoxBottom5Y = kBox5Y + kBoxHeight;

	//��K�ܒi��
	constexpr int kBox6X = kBoxBottom5X;
	constexpr int kBox6Y = kBox5Y - kBoxStep;
	constexpr int kBoxBottom6X = kBox6X + kBoxWidth;
	constexpr int kBoxBottom6Y = kBox6Y + kBoxHeight;

	//��K�Z�i��
	constexpr int kBox7X = kBoxBottom6X;
	constexpr int kBox7Y = kBox6Y - kBoxStep;
	constexpr int kBoxBottom7X = kBox7X + kBoxWidth;
	constexpr int kBoxBottom7Y = kBox7Y + kBoxHeight;

	//��K���i��
	constexpr int kBox8X = kBoxBottom7X;
	constexpr int kBox8Y = kBox7Y - kBoxStep;
	constexpr int kBoxBottom8X = kBox8X + kBoxWidth;
	constexpr int kBoxBottom8Y = kBox8Y + kBoxHeight;

	//��K///////////////////////////////////////////////////////////////////////////

	constexpr int kBox1Xs = 100;
	constexpr int kBox1Ys = Game::kScreenHeight - 250 - 20;
	constexpr int kBoxBottom1Xs = kBox1Xs + kBoxWidth;
	constexpr int koxBottom1Ys = kBox1Ys + kBoxHeight;

	constexpr int kBox2Xs = kBoxBottom1Xs;
	constexpr int kBox2Ys = kBox1Ys + kBoxStep;
	constexpr int kBoxBottom2Xs = kBox2Xs + kBoxWidth;
	constexpr int kBoxBottom2Ys = kBox2Ys + kBoxHeight;

	constexpr int kBox3Xs = kBoxBottom2Xs;
	constexpr int kBox3Ys = kBox2Ys + kBoxStep;
	constexpr int kBoxBottom3Xs = kBox3Xs + kBoxWidth;
	constexpr int kBoxBottom3Ys = kBox3Ys + kBoxHeight;


	constexpr int kBox4Xs = kBoxBottom3Xs;
	constexpr int kBox4Ys = kBox3Ys + kBoxStep;
	constexpr int kBoxBottom4Xs = kBox4Xs + kBoxWidth;
	constexpr int kBoxBottom4Ys = kBox4Ys + kBoxHeight;


	constexpr int kBox5Xs = kBoxBottom4Xs;
	constexpr int kBox5Ys = kBox4Ys + kBoxStep;
	constexpr int kBoxBottom5Xs = kBox5Xs + kBoxWidth;
	constexpr int kBoxBottom5Ys = kBox5Ys + kBoxHeight;


	constexpr int kBox6Xs = kBoxBottom5Xs;
	constexpr int kBox6Ys = kBox5Ys + kBoxStep;
	constexpr int kBoxBottom6Xs = kBox6Xs + kBoxWidth;
	constexpr int kBoxBottom6Ys = kBox6Ys + kBoxHeight;


	constexpr int kBox7Xs = kBoxBottom6Xs;
	constexpr int kBox7Ys = kBox6Ys + kBoxStep;
	constexpr int kBoxBottom7Xs = kBox7Xs + kBoxWidth;
	constexpr int kBoxBottom7Ys = kBox7Ys + kBoxHeight;


	constexpr int kBox8Xs = kBoxBottom7Xs;
	constexpr int kBox8Ys = kBox7Ys + kBoxStep;
	constexpr int kBoxBottom8Xs = Game::kScreenWidth - 100;
	constexpr int kBoxBottom8Ys = kBox8Ys + kBoxHeight;

	//�O�K//////////////////////////////////////////////////////////////////////////////////////////////
	constexpr int kBox1Xt = 200;                                   //��
	constexpr int kBox1Yt = Game::kScreenHeight - 400 - 20;             //��
	constexpr int kBoxBottom1Xt = kBox1Xt + Game::kScreenWidth / 2;//�E
	constexpr int kBoxBottom1Yt = kBox1Yt + kBoxHeight;            //��

	//��K��i��
	constexpr int kBox2Xt = kBoxBottom1Xt;
	constexpr int kBox2Yt = kBox1Yt - kBoxStep;
	constexpr int kBoxBottom2Xt = kBox2Xt + kBoxWidth;
	constexpr int kBoxBottom2Yt = kBox2Yt + kBoxHeight;

	//��K��i��
	constexpr int kBox3Xt = kBoxBottom2Xt;
	constexpr int kBox3Yt = kBox2Yt - kBoxStep;
	constexpr int kBoxBottom3Xt = kBox3Xt + kBoxWidth;
	constexpr int kBoxBottom3Yt = kBox3Yt + kBoxHeight;

	//��K�O�i��
	constexpr int kBox4Xt = kBoxBottom3Xt;
	constexpr int kBox4Yt = kBox3Yt - kBoxStep;
	constexpr int kBoxBottom4Xt = kBox4Xt + kBoxWidth;
	constexpr int kBoxBottom4Yt = kBox4Yt + kBoxHeight;

	//��K�l�i��
	constexpr int kBox5Xt = kBoxBottom4Xt;
	constexpr int kBox5Yt = kBox4Yt - kBoxStep;
	constexpr int kBoxBottom5Xt = kBox5Xt + kBoxWidth;
	constexpr int kBoxBottom5Yt = kBox5Yt + kBoxHeight;

	//��K�ܒi��
	constexpr int kBox6Xt = kBoxBottom5Xt;
	constexpr int kBox6Yt = kBox5Yt - kBoxStep;
	constexpr int kBoxBottom6Xt = kBox6Xt + kBoxWidth;
	constexpr int kBoxBottom6Yt = kBox6Yt + kBoxHeight;

	//��K�Z�i��
	constexpr int kBox7Xt = kBoxBottom6Xt;
	constexpr int kBox7Yt = kBox6Yt - kBoxStep;
	constexpr int kBoxBottom7Xt = kBox7Xt + kBoxWidth;
	constexpr int kBoxBottom7Yt = kBox7Yt + kBoxHeight;

	//��K���i��
	constexpr int kBox8Xt = kBoxBottom7Xt;
	constexpr int kBox8Yt = kBox7Yt - kBoxStep;
	constexpr int kBoxBottom8Xt = kBox8Xt + kBoxWidth;
	constexpr int kBoxBottom8Yt = kBox8Yt + kBoxHeight;

	//�l�K///////////////////////////////////////////////////////////////////////////

	constexpr int kBox1Xf = 100;
	constexpr int kBox1Yf = Game::kScreenHeight - 600 - 20;
	constexpr int kBoxBottom1Xf = kBox1Xf + kBoxWidth;
	constexpr int kBoxBottom1Yf = kBox1Yf + kBoxHeight;

	constexpr int kBox2Xf = kBoxBottom1Xf;
	constexpr int kBox2Yf = kBox1Yf + kBoxStep;
	constexpr int kBoxBottom2Xf = kBox2Xf + kBoxWidth;
	constexpr int kBoxBottom2Yf = kBox2Yf + kBoxHeight;

	constexpr int kBox3Xf = kBoxBottom2Xf;
	constexpr int kBox3Yf = kBox2Yf + kBoxStep;
	constexpr int kBoxBottom3Xf = kBox3Xf + kBoxWidth;
	constexpr int kBoxBottom3Yf = kBox3Yf + kBoxHeight;

	constexpr int kBox4Xf = kBoxBottom3Xf;
	constexpr int kBox4Yf = kBox3Yf + kBoxStep;
	constexpr int kBoxBottom4Xf = kBox4Xf + kBoxWidth;
	constexpr int kBoxBottom4Yf = kBox4Yf + kBoxHeight;

	constexpr int kBox5Xf = kBoxBottom4Xf;
	constexpr int kBox5Yf = kBox4Yf + kBoxStep;
	constexpr int kBoxBottom5Xf = kBox5Xf + kBoxWidth;
	constexpr int kBoxBottom5Yf = kBox5Yf + kBoxHeight;

	constexpr int kBox6Xf = kBoxBottom5Xf;
	constexpr int kBox6Yf = kBox5Yf + kBoxStep;
	constexpr int kBoxBottom6Xf = kBox6Xf + kBoxWidth;
	constexpr int kBoxBottom6Yf = kBox6Yf + kBoxHeight;

	constexpr int kBox7Xf = kBoxBottom6Xf;
	constexpr int kBox7Yf = kBox6Yf + kBoxStep;
	constexpr int kBoxBottom7Xf = kBox7Xf + kBoxWidth;
	constexpr int kBoxBottom7Yf = kBox7Yf + kBoxHeight;

	constexpr int kBox8Xf = kBoxBottom7Xf;
	constexpr int kBox8Yf = kBox7Yf + kBoxStep;
	constexpr int kBoxBottom8Xf = Game::kScreenWidth - 100;
	constexpr int kBoxBottom8Yf = kBox8Yf + kBoxHeight;

	//�܊K//////////////////////////////////////////////////////////////////////////////////////////////
	constexpr int kBox1XFi = 200;                                   //��
	constexpr int kBox1YFi = Game::kScreenHeight - 750 - 20;             //��
	constexpr int kBoxBottom1XFi = kBox1XFi + Game::kScreenWidth / 2;//�E
	constexpr int kBoxBottom1YFi = kBox1YFi + kBoxHeight;            //��

	//��K��i��
	constexpr int kBox2XFi = kBoxBottom1XFi;
	constexpr int kBox2YFi = kBox1YFi - kBoxStep;
	constexpr int kBoxBottom2XFi = kBox2XFi + kBoxWidth;
	constexpr int kBoxBottom2YFi = kBox2YFi + kBoxHeight;

	//��K��i��
	constexpr int kBox3XFi = kBoxBottom2XFi;
	constexpr int kBox3YFi = kBox2YFi - kBoxStep;
	constexpr int kBoxBottom3XFi = kBox3XFi + kBoxWidth;
	constexpr int kBoxBottom3YFi = kBox3YFi + kBoxHeight;

	//��K�O�i��
	constexpr int kBox4XFi = kBoxBottom3XFi;
	constexpr int kBox4YFi = kBox3YFi - kBoxStep;
	constexpr int kBoxBottom4XFi = kBox4XFi + kBoxWidth;
	constexpr int kBoxBottom4YFi = kBox4YFi + kBoxHeight;

	//��K�l�i��
	constexpr int kBox5XFi = kBoxBottom4XFi;
	constexpr int kBox5YFi = kBox4YFi - kBoxStep;
	constexpr int kBoxBottom5XFi = kBox5XFi + kBoxWidth;
	constexpr int kBoxBottom5YFi = kBox5YFi + kBoxHeight;

	//��K�ܒi��
	constexpr int kBox6XFi = kBoxBottom5XFi;
	constexpr int kBox6YFi = kBox5YFi - kBoxStep;
	constexpr int kBoxBottom6XFi = kBox6XFi + kBoxWidth;
	constexpr int kBoxBottom6YFi = kBox6YFi + kBoxHeight;

	//��K�Z�i��
	constexpr int kBox7XFi = kBoxBottom6XFi;
	constexpr int kBox7YFi = kBox6YFi - kBoxStep;
	constexpr int kBoxBottom7XFi = kBox7XFi + kBoxWidth;
	constexpr int kBoxBottom7YFi = kBox7YFi + kBoxHeight;

	//��K���i��
	constexpr int kBox8XFi = kBoxBottom7XFi;
	constexpr int kBox8YFi = kBox7YFi - kBoxStep;
	constexpr int kBoxBottom8XFi = kBox8XFi + kBoxWidth;
	constexpr int kBoxBottom8YFi = kBox8YFi + kBoxHeight;

	//��q///////////////////////////////////////////////////////////////////////////////
	//����q
	constexpr int kLadder1X = Game::kScreenWidth - 150;
	constexpr int kLadder1Y = Game::kScreenHeight - 240;
	constexpr int kLadderBottom1X = kLadder1X + 10;
	constexpr int kLadderBottom1Y = kLadder1Y + 115;
	//����q
	constexpr int kLadder2X = 300;
	constexpr int kLadder2Y = Game::kScreenHeight - 425;
	constexpr int kLadderBottom2X = kLadder2X + 10;
	constexpr int kLadderBottom2Y = kLadder2Y + 125;
	//��O��q
	constexpr int kLadder3X = Game::kScreenWidth - 200;
	constexpr int kLadder3Y = Game::kScreenHeight - 590;
	constexpr int kLadderBottom3X = kLadder3X + 10;
	constexpr int kLadderBottom3Y = kLadder3Y + 115;
	//��l��q
	constexpr int kLadder4X = 300;
	constexpr int kLadder4Y = Game::kScreenHeight - 780;
	constexpr int kLadderBottom4X = kLadder4X + 10;
	constexpr int kLadderBottom4Y = kLadder4Y + 135;

	//�Q�[���N���A�����ʒu//////////////////////////////////////////////////////////////////////////
	constexpr int kGoalX = Game::kScreenWidth - 880;
	constexpr int kGoalY = 280 - 20;
	constexpr int kGoalBottomX = kGoalX + 50;
	constexpr int kGoalBottomY = kGoalY + 50;
}

namespace TitleMenu
{
	constexpr int kAnimationFrame = 3;
	constexpr int kCharaImageRightPos = 112; //�E�ړ�
	//�`���[�g���A��
	constexpr int kSelection1X = Game::kScreenWidth / 2 - 150;
	constexpr int kSelection1Y = Game::kScreenHeight / 2 + 100;
	constexpr int kSelectionBottom1X = kSelection1X + 300;
	constexpr int kSelectionBottom1Y = kSelection1Y + 30;
	//�X�e�[�W�P
	constexpr int kSelection2X = Game::kScreenWidth / 2 - 150;
	constexpr int kSelection2Y = kSelection1Y;
	constexpr int kSelectionBottom2X = kSelection2X + 300;
	constexpr int kSelectionBottom2Y = kSelection2Y + 30;
	//�Q�[���I��
	constexpr int kSelection3X = Game::kScreenWidth / 2 - 150;
	constexpr int kSelection3Y = kSelection2Y + 200;
	constexpr int kSelectionBottom3X = kSelection3X + 300;
	constexpr int kSelectionBottom3Y = kSelection3Y + 50;

	//DrawBox(kSelection1X, kSelection1Y, kSelectionBottom1X, kSelectionBottom1Y, 0xffffff, true);

}
namespace Enemy1
{
	//�{�X�̈ʒu
	constexpr int kBossPosLeft   = Game::kScreenWidth - 200;
	constexpr int kBossPosTop    = 460 - 20;
	constexpr int kBossPosRight  = kBossPosLeft + 200;
	constexpr int kBossPosBottom = kBossPosTop + 200;

	constexpr float kBarrelSpeed = 5.0f;
}
namespace Enemy2
{
	//�{�X�̈ʒu
	constexpr int kBossPosLeft   = Game::kScreenWidth - 200;
	constexpr int kBossPosTop    = 110 - 20;
	constexpr int kBossPosRight  = kBossPosLeft + 200;
	constexpr int kBossPosBottom = kBossPosTop + 200;

	constexpr float kBarrelSpeed = 10.0f;
}
namespace SceneSelect
{
	constexpr int kSelectLeft   = Game::kScreenWidth / 2 - 130;
	constexpr int kSelectTop    = Game::kScreenHeight / 2 - 120;
	constexpr int kSelectRight  = kSelectLeft + 260;
	constexpr int kSelectBottom = kSelectTop + 30;

	constexpr int kSelectLeft2   = kSelectLeft;
	constexpr int kSelectTop2    = kSelectTop + 80 + 20;
	constexpr int kSelectRight2  = kSelectLeft2 + 260;
	constexpr int kSelectBottom2 = kSelectTop2 + 30;

	constexpr int kSelectLeft3   = kSelectLeft2;
	constexpr int kSelectTop3    = kSelectTop2 + 120;
	constexpr int kSelectRight3  = kSelectLeft3 + 260;
	constexpr int kSelectBottom3 = kSelectTop3 + 30;

	constexpr int kSlideSpeed  = 20 * 2;
	constexpr int kSlideSpeed2 = 15;
}

namespace Color
{
	constexpr int kWhite    = 0xffffff;//��
	constexpr int kRed      = 0xff0000;//��
	constexpr int kGreen    = 0x00ff00;//��
	constexpr int kBlue     = 0x0000ff;//��
	constexpr int kYellow   = 0xffff00;//���F
	constexpr int kThinRed  = 0xaa0000;//������
	constexpr int kThinBlue = 0x0000aa;//��
}

namespace Scene
{
	constexpr float kFadeSpeed = 3.5f;//�t�F�C�h�n
}

namespace Staging//���o�p
{
	constexpr int kFireworksNum = 5;//�ԉ΂̐�

	constexpr int kFireworksAnimatioFramenCount = 1;//�A�j���[�V�����t���[���J�E���g

	constexpr int kFireworksRocketSpeed = 25;//�ԉΑł��グ���x
}
