#include "RankingInputScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

RankingInputScene::RankingInputScene() : background_image(NULL),
ranking(nullptr), score(0), name_num(0), cursor_x(0), cursor_y(0)

{
	memset(name, NULL, (sizeof(char) * 15));
}

RankingInputScene::~RankingInputScene()
{

}

//初期化処理
void RankingInputScene::Initialize()
{
	//画像の読み込み
	background_image = LoadGraph("Resource/images/Ranking.bmp");

	//エラーチェック
	if (background_image == -1)
	{
		throw("Resource/images/Ranking.bmpがありません\n");
	}

	//メモリの動的確保
	ranking = new RankingData;
	ranking->Initialize();

	//リザルトデータを取得する
	FILE* fp = nullptr;
	//ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv","r");
	//エラーチェック
	if (result != 0)
	{
		throw("Resource/datt/result_data.csvが読み込めません\n");
	}
	//結果を読み込む
	fscanf_s(fp, "%6d,\n", &score);
	//ファイルクローズ
	fclose(fp);

}

//更新処理
eScenetype RankingInputScene::Update()
{
	bool is_shange = false;

	//名前入力処理
	is_change = InputName();

	//シーン変更は可能か？
	if (is_change)
	{
		//ランキング表示に移行
		return eScenetype::E_RANKING_DISP;
	}
	else
	{
		return GetNowScene();
	}
}
//描画処理
void RankingInputScene::Draw() const
{
	//背景画像の描画
	DrawGraph(0, 0, background_image, TRUE);
	//名前入力指示文字列の描画
	DrawString(150, 100, "ランキングに登録します", 0xFFFFFF);
	DrawFormatString(100, 220, GetColor(255, 255, 255), ">%s", name);

	//選択文字を描画
	const int font_size = 25;
	for (int i = 0; i < 26; i++)
	{
		int x = (i % 13) * font_size + 15;
		int y = (i / 13) * font_size + 300;
		DrawFormatString(x, y, GetColor(255, 255, 255), "%-3c", 'a' + i);
		y = ((i / 13) + 2) * font_size + 300;
		DrawFormatString(x, y, GetColor(255, 255, 255), "%-3c", 'A' + i);
	}
	DrawString(40, 405, "決定", GetColor(255, 255, 255));
	DrawString(40 + font_size * 2, 405, "消す", GetColor(255, 255, 255));

}