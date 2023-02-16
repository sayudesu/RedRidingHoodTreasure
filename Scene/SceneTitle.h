#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class TitleCursor;
class TitleCollision;
class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	//画像ハンドル
	int m_hImagePlayer;
	int m_hImageMap;
	int m_charaImagePos;
	//カウント
	int m_frameCount;
	int m_sceneChangeCountDemo;
	int m_sceneChangeCountStage1;
	int m_sceneChangeCountEnd;

	Vec2 m_imagePos;

	TitleCursor* m_pCursor;
	TitleCollision* m_pCollsion;
};
