#pragma once
#include "SceneBase.h"

class SceneResult : public SceneBase
{
public:
	SceneResult()
	{
		m_isEnd = false;
	}
	virtual ~SceneResult() {}

	virtual void init();
	virtual void end();

	virtual SceneBase* update() override;
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;

};

