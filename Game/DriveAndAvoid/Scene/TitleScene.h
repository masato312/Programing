#pragma once

#include "SceneBase.h"

class TitleScene :public SceneBase
{
private:
	int background_image;
	int menu_image;
	int cursor_image;
	int menu_cursor;

public:
	TitleScene();
	virtual ~TitleScene();

	virtual void Initialize() override;
	virtual eScenetype Update() override;
	virtual void Draw() const override;
	virtual eScenetype GetNowScene() const override;
};