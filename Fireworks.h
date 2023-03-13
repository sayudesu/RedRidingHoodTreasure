#pragma once

class Fireworks
{
public:

	Fireworks();
	virtual ~Fireworks();
	void Init();
	void End();
	void Update();
	void Draw();

private:
	int m_hFireworksRocket[2];
	int m_hFireworks[9];//花火画像ハンドル

	int m_fireworksImagePosX[1];
	int m_fireworksImagePosY[1];

	int m_fireworksImageRocketLeft;
	int m_fireworksImageRocketTop;
	int m_fireworksImageRocketRight;
	int m_fireworksImageRocketBottom;

	int m_fireworksImageLeft;
	int m_fireworksImageTop;
	int m_fireworksImageRight;
	int m_fireworksImageBottom;

	int m_frameCount;

	bool m_isFireRocket;//花火発射画像表示状態
	bool m_isFire;//花火画像表示状態
};

