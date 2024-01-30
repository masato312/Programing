#pragma once

#include "SceneBase.h"

class HelpScene :public SceneBase
{
private:
	int background_image;		//�w�i�摜

public:
	HelpScene();
	virtual ~HelpScene();

	virtual void Initialize() override;
	virtual eScenetype Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eScenetype GetNowScene()const override;
};