#include "DrawMapStage2.h"
#include "game.h"
#include "Image.h"
#include <Dxlib.h>

DrawMapStage2::DrawMapStage2():
	m_hMap1(-1), m_hMap2(-1),//マップ用ハンドル
	m_hMap3(-1), m_hMap4(-1),
	m_hMap5(-1),
	m_hTiles(-1),
	m_hBlock(-1),
	m_hMapChip1(-1),//マップチップデータ
	m_hBox(-1)//箱画像

{

}

DrawMapStage2::~DrawMapStage2()
{
}

void DrawMapStage2::Init()
{

	for (int i = 0; i < 9; i++)
	{
		m_hForest[i] = 0;
		m_hForestCut[i] = 0;
	}

	//マップ画像読み込み
	m_hMap1 = LoadGraph(Image::kMapFirst);
	m_hMap2 = LoadGraph(Image::kMapSecond);
	m_hMap3 = LoadGraph(Image::kMapThird);
	m_hMap4 = LoadGraph(Image::kMapFourth);
	m_hMap5 = LoadGraph(Image::kMapFifth);
	m_hTiles = LoadGraph(Image::kMapTiles);//地面画像を読み込み

	m_hForest[0] = LoadGraph(Image::kMapForest0);//地面画像を読み込み
	m_hForest[1] = LoadGraph(Image::kMapForest2);//地面画像を読み込み
	m_hForest[2] = LoadGraph(Image::kMapForest3);//地面画像を読み込み
	m_hForest[3] = LoadGraph(Image::kMapForest4);//地面画像を読み込み
	m_hForest[4] = LoadGraph(Image::kMapForest5);//地面画像を読み込み
	m_hForest[5] = LoadGraph(Image::kMapForest6);//地面画像を読み込み
	m_hForest[6] = LoadGraph(Image::kMapForest7);//地面画像を読み込み
	m_hForest[7] = LoadGraph(Image::kMapForest8);//地面画像を読み込み
	m_hForest[8] = LoadGraph(Image::kMapForest9);//地面画像を読み込み



	m_hBlock = DerivationGraph(178 + 1, 236, 32 + 16 - 10 , 16, m_hTiles);//地面画像から一部を抽出

	int sizeX, sizeY;
	GetGraphSize(m_hForest[0],& sizeX, &sizeY);
	m_hForestCut[0] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[0]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[1], &sizeX, &sizeY);
	m_hForestCut[1] = DerivationGraph(0,250, sizeX, sizeY, m_hForest[1]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[2], &sizeX, &sizeY);
	m_hForestCut[2] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[2]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[3], &sizeX, &sizeY);
	m_hForestCut[3] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[3]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[4], &sizeX, &sizeY);
	m_hForestCut[4] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[4]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[5], &sizeX, &sizeY);
	m_hForestCut[5] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[5]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[6], &sizeX, &sizeY);
	m_hForestCut[6] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[6]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[7], &sizeX, &sizeY);
	m_hForestCut[7] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[7]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[8], &sizeX, &sizeY);
	m_hForestCut[8] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[8]);//地面画像から一部を抽出

	//m_hTiles = LoadGraph(Image::kMapTiles);

	m_hMapChip1 = LoadGraph(Image::kMapTiles);
	m_hBox = DerivationGraph(288, 272, 32, 32, m_hMapChip1);//地面画像から一部を抽出
}

void DrawMapStage2::End()
{
	DeleteGraph(m_hMap1);
	DeleteGraph(m_hMap2);
	DeleteGraph(m_hMap3);
	DeleteGraph(m_hMap4);
	DeleteGraph(m_hMap5);
	DeleteGraph(m_hTiles);
	DeleteGraph(m_hBlock);

	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(m_hForest[i]);
		DeleteGraph(m_hForestCut[i]);
	}

	DeleteGraph(m_hMapChip1);
	DeleteGraph(m_hBox);
}

void DrawMapStage2::Update()
{
}

void DrawMapStage2::Draw()
{


	DrawGraph(100, 100, m_hBox, true);

	DrawBackground();//マップの背景を表示
	DrawMap();//マップ表示

	//第一梯子
	DrawBox(Stage2::kLadder1X, Stage2::kLadder1Y, Stage2::kLadderBottom1X, Stage2::kLadderBottom1Y, 0xff0000, true);
	//第二梯子
	DrawBox(Stage2::kLadder2X, Stage2::kLadder2Y, Stage2::kLadderBottom2X, Stage2::kLadderBottom2Y, 0xff0000, true);
	//第三梯子
	DrawBox(Stage2::kLadder3X, Stage2::kLadder3Y, Stage2::kLadderBottom3X, Stage2::kLadderBottom3Y, 0xff0000, true);
	//第四梯子
	DrawBox(Stage2::kLadder4X, Stage2::kLadder4Y, Stage2::kLadderBottom4X, Stage2::kLadderBottom4Y, 0xff0000, true);

	//ゴール
	DrawExtendGraph(Stage2::kGoalX, Stage2::kGoalY, Stage2::kGoalBottomX, Stage2::kGoalBottomY, m_hBox, true);
	DrawBox(Stage2::kGoalX, Stage2::kGoalY, Stage2::kGoalBottomX, Stage2::kGoalBottomY, 0xff00ff, false);

}

void DrawMapStage2::DrawBackground()
{
	/*DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMap1, true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMap2, true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMap3, true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMap4, true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMap5, true);*/

	for (int i = 0; i < 9; i++)//背景を描画
	{
		DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[i], true);
	}
	/*
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[0], true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[1], true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[2], true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[3], true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[4], true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[5], true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[6], true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[7], true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[8], true);
	*/
}

void DrawMapStage2::DrawMap()
{
	//1階地面
	DrawExtendGraph(Stage2::kBox1X, Stage2::kBox1Y - 2, Stage2::kBoxBottom1X, Stage2::kBoxBottom1Y, m_hBlock, true);
	//DrawBox(Stage2::kBox1X, Stage2::kBox1Y, Stage2::kBoxBottom1X, Stage2::kBoxBottom1Y, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox2X, Stage2::kBox2Y - 2, Stage2::kBoxBottom2X, Stage2::kBoxBottom2Y, m_hBlock, true);
	//DrawBox(Stage2::kBox2X, Stage2::kBox2Y, Stage2::kBoxBottom2X, Stage2::kBoxBottom2Y, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox3X, Stage2::kBox3Y - 2, Stage2::kBoxBottom3X, Stage2::kBoxBottom3Y, m_hBlock, true);
	//DrawBox(Stage2::kBox3X, Stage2::kBox3Y, Stage2::kBoxBottom3X, Stage2::kBoxBottom3Y, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox4X, Stage2::kBox4Y - 2, Stage2::kBoxBottom4X, Stage2::kBoxBottom4Y, m_hBlock, true);
	//DrawBox(Stage2::kBox4X, Stage2::kBox4Y, Stage2::kBoxBottom4X, Stage2::kBoxBottom4Y, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox5X, Stage2::kBox5Y - 2, Stage2::kBoxBottom5X, Stage2::kBoxBottom5Y, m_hBlock, true);
	//DrawBox(Stage2::kBox5X, Stage2::kBox5Y, Stage2::kBoxBottom5X, Stage2::kBoxBottom5Y, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox6X, Stage2::kBox6Y - 2, Stage2::kBoxBottom6X, Stage2::kBoxBottom6Y, m_hBlock, true);
	//DrawBox(Stage2::kBox6X, Stage2::kBox6Y, Stage2::kBoxBottom6X, Stage2::kBoxBottom6Y, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox7X, Stage2::kBox7Y - 2, Stage2::kBoxBottom7X, Stage2::kBoxBottom7Y, m_hBlock, true);
	//DrawBox(Stage2::kBox7X, Stage2::kBox7Y, Stage2::kBoxBottom7X, Stage2::kBoxBottom7Y, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox8X, Stage2::kBox8Y - 2, Stage2::kBoxBottom8X, Stage2::kBoxBottom8Y, m_hBlock, true);
	//DrawBox(Stage2::kBox8X, Stage2::kBox8Y, Stage2::kBoxBottom8X, Stage2::kBoxBottom8Y, 0xffffff, false);

	//2階地面
	DrawExtendGraph(Stage2::kBox1Xs, Stage2::kBox1Ys - 2, Stage2::kBoxBottom1Xs, Stage2::koxBottom1Ys, m_hBlock, true);
	//DrawBox(Stage2::kBox1Xs, Stage2::kBox1Ys, Stage2::kBoxBottom1Xs, Stage2::koxBottom1Ys, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox2Xs, Stage2::kBox2Ys - 2, Stage2::kBoxBottom2Xs, Stage2::kBoxBottom2Ys, m_hBlock, true);
	//DrawBox(Stage2::kBox2Xs, Stage2::kBox2Ys, Stage2::kBoxBottom2Xs, Stage2::kBoxBottom2Ys, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox3Xs, Stage2::kBox3Ys - 2, Stage2::kBoxBottom3Xs, Stage2::kBoxBottom3Ys, m_hBlock, true);
	//DrawBox(Stage2::kBox3Xs, Stage2::kBox3Ys, Stage2::kBoxBottom3Xs, Stage2::kBoxBottom3Ys, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox4Xs, Stage2::kBox4Ys - 2, Stage2::kBoxBottom4Xs, Stage2::kBoxBottom4Ys, m_hBlock, true);
	//DrawBox(Stage2::kBox4Xs, Stage2::kBox4Ys, Stage2::kBoxBottom4Xs, Stage2::kBoxBottom4Ys, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox5Xs, Stage2::kBox5Ys - 2, Stage2::kBoxBottom5Xs, Stage2::kBoxBottom5Ys, m_hBlock, true);
	//DrawBox(Stage2::kBox5Xs, Stage2::kBox5Ys, Stage2::kBoxBottom5Xs, Stage2::kBoxBottom5Ys, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox6Xs, Stage2::kBox6Ys - 2, Stage2::kBoxBottom6Xs, Stage2::kBoxBottom6Ys, m_hBlock, true);
	//DrawBox(Stage2::kBox6Xs, Stage2::kBox6Ys, Stage2::kBoxBottom6Xs, Stage2::kBoxBottom6Ys, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox7Xs, Stage2::kBox7Ys - 2, Stage2::kBoxBottom7Xs, Stage2::kBoxBottom7Ys, m_hBlock, true);
	//DrawBox(Stage2::kBox7Xs, Stage2::kBox7Ys, Stage2::kBoxBottom7Xs, Stage2::kBoxBottom7Ys, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox8Xs, Stage2::kBox8Ys - 2, Stage2::kBoxBottom8Xs, Stage2::kBoxBottom8Ys, m_hBlock, true);
	//DrawBox(Stage2::kBox8Xs, Stage2::kBox8Ys, Stage2::kBoxBottom8Xs, Stage2::kBoxBottom8Ys, 0xffffff, false);

	//3階地面
	DrawExtendGraph(Stage2::kBox1Xt, Stage2::kBox1Yt - 2, Stage2::kBoxBottom1Xt, Stage2::kBoxBottom1Yt, m_hBlock, true);
	//DrawBox(Stage2::kBox1Xt, Stage2::kBox1Yt, Stage2::kBoxBottom1Xt, Stage2::kBoxBottom1Yt, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox2Xt, Stage2::kBox2Yt - 2, Stage2::kBoxBottom2Xt, Stage2::kBoxBottom2Yt, m_hBlock, true);
	//DrawBox(Stage2::kBox2Xt, Stage2::kBox2Yt, Stage2::kBoxBottom2Xt, Stage2::kBoxBottom2Yt, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox3Xt, Stage2::kBox3Yt - 2, Stage2::kBoxBottom3Xt, Stage2::kBoxBottom3Yt, m_hBlock, true);
	//DrawBox(Stage2::kBox3Xt, Stage2::kBox3Yt, Stage2::kBoxBottom3Xt, Stage2::kBoxBottom3Yt, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox4Xt, Stage2::kBox4Yt - 2, Stage2::kBoxBottom4Xt, Stage2::kBoxBottom4Yt, m_hBlock, true);
	//DrawBox(Stage2::kBox4Xt, Stage2::kBox4Yt, Stage2::kBoxBottom4Xt, Stage2::kBoxBottom4Yt, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox5Xt, Stage2::kBox5Yt - 2, Stage2::kBoxBottom5Xt, Stage2::kBoxBottom5Yt, m_hBlock, true);
	//DrawBox(Stage2::kBox5Xt, Stage2::kBox5Yt, Stage2::kBoxBottom5Xt, Stage2::kBoxBottom5Yt, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox6Xt, Stage2::kBox6Yt - 2, Stage2::kBoxBottom6Xt, Stage2::kBoxBottom6Yt, m_hBlock, true);
	//DrawBox(Stage2::kBox6Xt, Stage2::kBox6Yt, Stage2::kBoxBottom6Xt, Stage2::kBoxBottom6Yt, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox7Xt, Stage2::kBox7Yt - 2, Stage2::kBoxBottom7Xt, Stage2::kBoxBottom7Yt, m_hBlock, true);
	//DrawBox(Stage2::kBox7Xt, Stage2::kBox7Yt, Stage2::kBoxBottom7Xt, Stage2::kBoxBottom7Yt, 0xffffff, false);
	//DrawBox(Stage2::kBox8Xt, Stage2::kBox8Yt, Stage2::kBoxBottom8Xt, Stage2::kBoxBottom8Yt, 0xffffff, true);

	//4階地面
	DrawExtendGraph(Stage2::kBox1Xf, Stage2::kBox1Yf - 2, Stage2::kBoxBottom1Xf, Stage2::kBoxBottom1Yf, m_hBlock, true);
	//DrawBox(Stage2::kBox1Xf, Stage2::kBox1Yf, Stage2::kBoxBottom1Xf, Stage2::kBoxBottom1Yf, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox2Xf, Stage2::kBox2Yf - 2, Stage2::kBoxBottom2Xf, Stage2::kBoxBottom2Yf, m_hBlock, true);
	//DrawBox(Stage2::kBox2Xf, Stage2::kBox2Yf, Stage2::kBoxBottom2Xf, Stage2::kBoxBottom2Yf, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox3Xf, Stage2::kBox3Yf - 2, Stage2::kBoxBottom3Xf, Stage2::kBoxBottom3Yf, m_hBlock, true);
	//DrawBox(Stage2::kBox3Xf, Stage2::kBox3Yf, Stage2::kBoxBottom3Xf, Stage2::kBoxBottom3Yf, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox4Xf, Stage2::kBox4Yf - 2, Stage2::kBoxBottom4Xf, Stage2::kBoxBottom4Yf, m_hBlock, true);
	//DrawBox(Stage2::kBox4Xf, Stage2::kBox4Yf, Stage2::kBoxBottom4Xf, Stage2::kBoxBottom4Yf, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox5Xf, Stage2::kBox5Yf - 2, Stage2::kBoxBottom5Xf, Stage2::kBoxBottom5Yf, m_hBlock, true);
	//DrawBox(Stage2::kBox5Xf, Stage2::kBox5Yf, Stage2::kBoxBottom5Xf, Stage2::kBoxBottom5Yf, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox6Xf, Stage2::kBox6Yf - 2, Stage2::kBoxBottom6Xf, Stage2::kBoxBottom6Yf, m_hBlock, true);
	//DrawBox(Stage2::kBox6Xf, Stage2::kBox6Yf, Stage2::kBoxBottom6Xf, Stage2::kBoxBottom6Yf, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox7Xf, Stage2::kBox7Yf - 2, Stage2::kBoxBottom7Xf, Stage2::kBoxBottom7Yf, m_hBlock, true);
	//DrawBox(Stage2::kBox7Xf, Stage2::kBox7Yf, Stage2::kBoxBottom7Xf, Stage2::kBoxBottom7Yf, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox8Xf, Stage2::kBox8Yf - 2, Stage2::kBoxBottom8Xf, Stage2::kBoxBottom8Yf, m_hBlock, true);
	//DrawBox(Stage2::kBox8Xf, Stage2::kBox8Yf, Stage2::kBoxBottom8Xf, Stage2::kBoxBottom8Yf, 0xffffff, false);

	//5階地面

	DrawExtendGraph(Stage2::kBox1XFi, Stage2::kBox1YFi - 2, Stage2::kBoxBottom1XFi, Stage2::kBoxBottom1YFi, m_hBlock, true);
	//DrawBox(Stage2::kBox1XFi, Stage2::kBox1YFi, Stage2::kBoxBottom1XFi, Stage2::kBoxBottom1YFi, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox2XFi, Stage2::kBox2YFi - 2 , Stage2::kBoxBottom2XFi, Stage2::kBoxBottom2YFi, m_hBlock, true);
	//DrawBox(Stage2::kBox2XFi, Stage2::kBox2YFi, Stage2::kBoxBottom2XFi, Stage2::kBoxBottom2YFi, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox3XFi, Stage2::kBox3YFi - 2, Stage2::kBoxBottom3XFi, Stage2::kBoxBottom3YFi, m_hBlock, true);
	//DrawBox(Stage2::kBox3XFi, Stage2::kBox3YFi, Stage2::kBoxBottom3XFi, Stage2::kBoxBottom3YFi, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox4XFi, Stage2::kBox4YFi - 2, Stage2::kBoxBottom4XFi, Stage2::kBoxBottom4YFi, m_hBlock, true);
	//DrawBox(Stage2::kBox4XFi, Stage2::kBox4YFi, Stage2::kBoxBottom4XFi, Stage2::kBoxBottom4YFi, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox5XFi, Stage2::kBox5YFi - 2, Stage2::kBoxBottom5XFi, Stage2::kBoxBottom5YFi, m_hBlock, true);
	//DrawBox(Stage2::kBox5XFi, Stage2::kBox5YFi, Stage2::kBoxBottom5XFi, Stage2::kBoxBottom5YFi, 0xffffff, false);
	DrawExtendGraph(Stage2::kBox6XFi, Stage2::kBox6YFi - 2, Stage2::kBoxBottom6XFi, Stage2::kBoxBottom6YFi,m_hBlock, true);
	//DrawBox(Stage2::kBox6XFi, Stage2::kBox6YFi, Stage2::kBoxBottom6XFi, Stage2::kBoxBottom6YFi, 0xffffff, false);

	//DrawBox(Stage2::kBox7XFi, Stage2::kBox7YFi, Stage2::kBoxBottom7XFi, Stage2::kBoxBottom7YFi, 0xffffff, true);
	//DrawBox(Stage2::kBox8XFi, Stage2::kBox8YFi, Stage2::kBoxBottom8XFi, Stage2::kBoxBottom8YFi, 0xffffff, true);
}
