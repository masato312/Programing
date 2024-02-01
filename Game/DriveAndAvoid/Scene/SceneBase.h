#pragma once

//シーン情報
enum eScenetype
{
	E_TITLE,
	E_MAIN,
	E_HELP,
	E_RANKING_DISP,
	E_RANKING_INPUT,
	E_RESULT,
	E_END
};

//基底シーンクラス
class SceneBase
{
public:
	SceneBase() {}

	//初期化処理
	virtual void Initialize(){}
	//更新処理
	virtual eScenetype Update()
	{
		return GetNowScene();
	}
	//描画処理
	virtual void Draw() const {}
	//終了時処理
	virtual void Finalize() {}
	
	//現在のシーン情報を取得
	virtual eScenetype GetNowScene() const = 0;
};