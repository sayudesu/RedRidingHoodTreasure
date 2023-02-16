#pragma once
#include "SceneBase.h"
#include "Vec2.h"

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
	void DrawPadCursor();
	void DrawSelection();
private:
	//画像ハンドル
	int m_hImagePlayer;
	int m_hImageMap;
	int m_charaImagePos;
	//カウント
	int m_frameCount;
	int m_sceneChangeCount;

	Vec2 m_padPos;
	Vec2 m_imagePos;
};
