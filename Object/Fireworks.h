#pragma once
#include "game.h"

class Fireworks//花火
{
public:

	Fireworks();//コンストラクタ
	virtual ~Fireworks();//デストラクタ
	void Init();//初期化
	void End();//メモリ解放
	void Update();//更新
	void Draw();//描画

private:
	int m_pulsCount;
	int m_puls;
	int m_FirePos;
	//花火画像ハンドル
	int m_hFireworksRocket[Staging::kFireworksNum];//花火打ち上げ画像
	int m_hFireworks[9];//花火画像ハンドル
	//花火位置
	int m_fireworksImagePosX[Staging::kFireworksNum];
	int m_fireworksImagePosY[Staging::kFireworksNum];
	//花火打ち上げ画像位置
	int m_fireworksImageRocketLeft;
	int m_fireworksImageRocketTop;
	int m_fireworksImageRocketRight;
	int m_fireworksImageRocketBottom;
	//花火画像位置
	int m_fireworksImageLeft[Staging::kFireworksNum];
	int m_fireworksImageTop;
	int m_fireworksImageRight;
	int m_fireworksImageBottom;
	//カウント類
	int m_frameCount[Staging::kFireworksNum];//花火アニメーションカウント
	int m_delayCount[Staging::kFireworksNum];//花火複数の場合のディレイを入れるよう
	//画像表示非表示
	bool m_isFireRocket[Staging::kFireworksNum];//花火発射画像表示状態
	bool m_isFire[Staging::kFireworksNum];//花火画像表示状態
};

