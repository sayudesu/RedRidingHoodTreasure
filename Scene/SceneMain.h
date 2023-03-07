#pragma once
#include "SceneBase.h"
#include "Vec2.h"
#include <vector>


class PlayerMapMove;
//class Player;
class Enemy;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();


	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();
private:
	void FadeIn();
	void FadeOut();
public:
	bool Check(int firstLeft,int firstTop,int firstRight,int firstBottom,
		int SecondLeft, int SecondTop, int SecondRight, int SecondBottom);
private:
	//MakeScreenテスト
	int m_test;

	int m_hPlayer;
	int m_hPlayerIdle;
	int m_hPlayerLighting;
	int m_hPlayerHealthBer;
	int m_hEnemy;

	int m_hMapFirst;
	int m_hMapSecond;
	int m_hMapThird;
	int m_hMapFourth;
	int m_hMapFifth;
	int m_hMapChip;
	int m_hMapChipSecond;

	float m_fadeValue;//明るさ調整用

	bool m_isFadeIn;//フェイドインしたかどうか
	bool m_isFadeOut;//フェイドアウトしたかどうか

	bool m_isSceneStage;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneEnd;//画面が暗くなった後にシーンの切り替え

	PlayerMapMove* m_pPlayer;
	Enemy* m_pEnemy;

};
