#include "Enemy.h"
#include<Novice.h>
void Enemy::initalize()
{
	trance. x= 640;
	trance.y = 150;
	speed_ = 10;
	radius_ = 20;
	isAlive = 0;
}

void Enemy::Update()
{
	trance.x += speed_;

	if (trance.x >= 1260|| trance.x <= 20) {
		speed_ *= -1;
	}
}

void Enemy::Draw()
{
	Novice::DrawEllipse((int)trance.x, (int)trance.y, radius_, radius_, 0.0f,0xff0000ff, kFillModeSolid);

}
