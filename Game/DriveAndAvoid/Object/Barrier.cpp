#include "Barrier.h"
#include "DxLib.h"

Barrier::Barrier(): image(NULL), life_span(1000)
{
	//‰æ‘œ‚Ì“Ç‚İ‚İ
	image = LoadGraph("Resource/images/barrier.png");

	if (image == -1)
	{
		throw("Resource/images/barrier.png‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}
}

Barrier::~Barrier()
{
	//“Ç‚İ‚ñ‚¾‰æ‘œ‚ğíœ
	DeleteGraph(image);
}

//•`‰æˆ—
void Barrier::Draw(const Vector2D& location)
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);
}
//õ–½‚ªs‚«‚½‚©H
bool Barrier::IsFinished(float speed)
{
	life_span -= speed;
	return (life_span <= 0);
}