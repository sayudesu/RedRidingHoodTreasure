#pragma once

class PlayerImage
{
public:
	PlayerImage();
	virtual ~PlayerImage() {};

	virtual void Init();
	virtual void End();

	virtual void Update() {};

	void SetHandle(int Player) { m_hPlayer = Player; }

	virtual void Draw();

protected:
	//グラフィックハンドル
	int	m_hPlayer;

};

