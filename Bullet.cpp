#include "Bullet.h"
#include <Novice.h>
Bullet::Bullet()
{

	bulletpos_.x = 0;
	bulletpos_.y = -10;
	radius_ = 20;
	speed_ = 10;
	isBullet_ = 0;

}

Bullet::~Bullet()
{


}

void Bullet::Update()
{
	if (isBullet_ == 1) {
		bulletpos_.y -= speed_;
		if (bulletpos_.y <= -10) {
			isBullet_ = 0;
		}
	}


}

void Bullet::Draw()
{
	if (isBullet_ == 1) {
		Novice::DrawBox(bulletpos_.x, bulletpos_.y, radius_, radius_, 0.0f, 0xffff00ff, kFillModeSolid);

	}

}
