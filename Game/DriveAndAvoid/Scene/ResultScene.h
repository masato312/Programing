#pragma once

#include "SceneBase.h"

class ResultScene : public SceneBase
{
private:
	int back_ground;			//”wŒi‰æ‘œ
	int score;					//ƒXƒRƒA
	int enemy_count[3];			//“G‚ÌƒJƒEƒ“ƒg
	int enemy_image[3];			//“G‰æ‘œ

public:
	virtual void Initialize() override;
	
	virtual void Initialize() override;
	virtual eScenetype Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eScenetype GetNowScene()const override;

private:
	void ReadResultData();
};