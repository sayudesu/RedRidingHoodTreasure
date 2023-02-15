#pragma once
#include "game.h"
//#define _DEBUG 

namespace Game
{
//#ifdef _DEBUG	
	// ウインドウモード設定
	constexpr bool kWindowMode = true;
	/*
#else
	constexpr bool kWindowMode = false;
#endif
*/
	// マウスカーソル表示
	constexpr bool kMouseMode = true;
	// ウインドウ名
	const char* const kTitleText = "ゲーム（制作中）";
	//フォント名
	//const char* const kFontName = "HG行書体";
	//const char* const kFontName = "Data/Font/GAGAGAGA FREE";
	constexpr int kFontSize = 64;
	// ウインドウサイズ
	/*constexpr int kScreenWidth = 1280;
	constexpr int kScreenHeight = 720;*/
	constexpr int kScreenWidth = 1920;
	constexpr int kScreenHeight = 1080;
	// カラーモード
	constexpr int kColorDepth = 32;		// 32 or 16
};

namespace Stage2
{
	//箱の横幅
	constexpr int kBoxWidth = 150;
	//箱の高さ
	constexpr int kBoxHeight = 20;
	//段差
	constexpr int kBoxStep = 5;
	constexpr int kBoxStep2 = 5;//12;

	//一階////////////////////////////////////////////////////////////////////////////////
	constexpr int kBox1X = 0;                                   //左
	constexpr int kBox1Y = Game::kScreenHeight - 60;            //上
	constexpr int kBoxBottom1X = kBox1X + Game::kScreenWidth / 2;//右
	constexpr int kBoxBottom1Y = kBox1Y + kBoxHeight;             //下

	//一階一段差
	constexpr int kBox2X = kBoxBottom1X;
	constexpr int kBox2Y = kBox1Y - kBoxStep;
	constexpr int kBoxBottom2X = kBox2X + kBoxWidth;
	constexpr int kBoxBottom2Y = kBox2Y + kBoxHeight;

	//一階二段差
	constexpr int kBox3X = kBoxBottom2X;
	constexpr int kBox3Y = kBox2Y - kBoxStep;
	constexpr int kBoxBottom3X = kBox3X + kBoxWidth;
	constexpr int kBoxBottom3Y = kBox3Y + kBoxHeight;

	//一階三段差
	constexpr int kBox4X = kBoxBottom3X;
	constexpr int kBox4Y = kBox3Y - kBoxStep;
	constexpr int kBoxBottom4X = kBox4X + kBoxWidth;
	constexpr int kBoxBottom4Y = kBox4Y + kBoxHeight;

	//一階四段差
	constexpr int kBox5X = kBoxBottom4X;
	constexpr int kBox5Y = kBox4Y - kBoxStep;
	constexpr int kBoxBottom5X = kBox5X + kBoxWidth;
	constexpr int kBoxBottom5Y = kBox5Y + kBoxHeight;

	//一階五段差
	constexpr int kBox6X = kBoxBottom5X;
	constexpr int kBox6Y = kBox5Y - kBoxStep;
	constexpr int kBoxBottom6X = kBox6X + kBoxWidth;
	constexpr int kBoxBottom6Y = kBox6Y + kBoxHeight;

	//一階六段差
	constexpr int kBox7X = kBoxBottom6X;
	constexpr int kBox7Y = kBox6Y - kBoxStep;
	constexpr int kBoxBottom7X = kBox7X + kBoxWidth;
	constexpr int kBoxBottom7Y = kBox7Y + kBoxHeight;

	//一階七段差
	constexpr int kBox8X = kBoxBottom7X;
	constexpr int kBox8Y = kBox7Y - kBoxStep;
	constexpr int kBoxBottom8X = kBox8X + kBoxWidth;
	constexpr int kBoxBottom8Y = kBox8Y + kBoxHeight;

	//二階///////////////////////////////////////////////////////////////////////////

	constexpr int kBox1Xs = 100;
	constexpr int kBox1Ys = Game::kScreenHeight - 250;
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

	//三階//////////////////////////////////////////////////////////////////////////////////////////////
	constexpr int kBox1Xt = 200;                                   //左
	constexpr int kBox1Yt = Game::kScreenHeight - 370;             //上
	constexpr int kBoxBottom1Xt = kBox1Xt + Game::kScreenWidth / 2;//右
	constexpr int kBoxBottom1Yt = kBox1Yt + kBoxHeight;            //下

	//一階一段差
	constexpr int kBox2Xt = kBoxBottom1Xt;
	constexpr int kBox2Yt = kBox1Yt - kBoxStep;
	constexpr int kBoxBottom2Xt = kBox2Xt + kBoxWidth;
	constexpr int kBoxBottom2Yt = kBox2Yt + kBoxHeight;

	//一階二段差
	constexpr int kBox3Xt = kBoxBottom2Xt;
	constexpr int kBox3Yt = kBox2Yt - kBoxStep;
	constexpr int kBoxBottom3Xt = kBox3Xt + kBoxWidth;
	constexpr int kBoxBottom3Yt = kBox3Yt + kBoxHeight;

	//一階三段差
	constexpr int kBox4Xt = kBoxBottom3Xt;
	constexpr int kBox4Yt = kBox3Yt - kBoxStep;
	constexpr int kBoxBottom4Xt = kBox4Xt + kBoxWidth;
	constexpr int kBoxBottom4Yt = kBox4Yt + kBoxHeight;

	//一階四段差
	constexpr int kBox5Xt = kBoxBottom4Xt;
	constexpr int kBox5Yt = kBox4Yt - kBoxStep;
	constexpr int kBoxBottom5Xt = kBox5Xt + kBoxWidth;
	constexpr int kBoxBottom5Yt = kBox5Yt + kBoxHeight;

	//一階五段差
	constexpr int kBox6Xt = kBoxBottom5Xt;
	constexpr int kBox6Yt = kBox5Yt - kBoxStep;
	constexpr int kBoxBottom6Xt = kBox6Xt + kBoxWidth;
	constexpr int kBoxBottom6Yt = kBox6Yt + kBoxHeight;

	//一階六段差
	constexpr int kBox7Xt = kBoxBottom6Xt;
	constexpr int kBox7Yt = kBox6Yt - kBoxStep;
	constexpr int kBoxBottom7Xt = kBox7Xt + kBoxWidth;
	constexpr int kBoxBottom7Yt = kBox7Yt + kBoxHeight;

	//一階七段差
	constexpr int kBox8Xt = kBoxBottom7Xt;
	constexpr int kBox8Yt = kBox7Yt - kBoxStep;
	constexpr int kBoxBottom8Xt = kBox8Xt + kBoxWidth;
	constexpr int kBoxBottom8Yt = kBox8Yt + kBoxHeight;

	//梯子///////////////////////////////////////////////////////////////////////////////
	//第一梯子
	constexpr int kLadder1X = Game::kScreenWidth - 150;
	constexpr int kLadder1Y = Game::kScreenHeight - 250;
	constexpr int kLadderBottom1X = kLadder1X + 10;
	constexpr int kLadderBottom1Y = kLadder1Y + 150;
	//第二梯子
	constexpr int kLadder2X = 300;
	constexpr int kLadder2Y = Game::kScreenHeight - 400;
	constexpr int kLadderBottom2X = kLadder2X + 10;
	constexpr int kLadderBottom2Y = kLadder2Y + 150;
}