#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();


	virtual void init();
	virtual void end();

	virtual SceneBase* update() override;
	virtual void draw();

private:
	void UpdateMove();
private:
	//キャラクターの位置
	Vec2 m_pos;
	Vec2 m_underPos;
	//方向
	Vec2 m_vec;

	//update処理メンバ関数ポインタ
	void (SceneMain::* m_func)();
};
