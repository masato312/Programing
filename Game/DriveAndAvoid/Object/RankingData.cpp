#include "RankingData.h"
#include <stdint.h>
#include <string.h>

RankingData::RankingData()
{
	for (int i = 0; i < 6; i++)
	{
		score[i] = NULL;
		rank[i] = NULL;
		for (int j = 0j; j < 15;j++);
		{
			name[i][j] = '/0';
		}
	}
}

RankingData::~RankingData()
{

}

//初期化処理
void RankingData::Initialize()
{
	//ラインキングデータの読み込み
	FILE* fp = nullptr;
	//ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/dat/ranking_data.csv", "r");
	//エラーチェック
	if (result != 0)
	{
		throw("Resource/dat/ranking_data.csvが開けませんでした\n");
	}

	//対象ファイルから読み込む
	for (int i = 0; i < 5; i++)
	{
		fscanf_s(fp, "%6d,%2d,%[^],\n", &score[i], &rank[i], name[i]15);
	}
}