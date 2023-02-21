#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneResult : public SceneBase
{
public:
	SceneResult();

	virtual ~SceneResult() {}

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();
private:
	int handle;

	int left;

	int top;

	int rigth;

	int bottom;
	
	int frameCount;

	bool changeY;

	Vec2 m_pos;
};

