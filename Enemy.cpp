#include "Enemy.h"
#include<Novice.h>
Enemy::~Enemy()
{
}
void Enemy::initalize()
{
	trance. x= 640;
	trance.y = 150;
	speed_ = 10;
	radius_ = 20;
	isAlive_ = 1;
	timer_ = 0;
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
	if (isAlive_ == 1) {
		
		Novice::DrawEllipse(trance.x, trance.y, radius_, radius_, 0.0f, 0xff0000ff, kFillModeSolid);
		
	
	}
	if (isAlive_ == 1) {
		timer_++;
	}
		if (timer_ > 100){
			isAlive_ = 0;
	
		}
	
	timer_ = 0;
	
	/*if (timer_ < 0) {
		Novice::DrawEllipse(trance.x, trance.y, radius_, radius_, 0.0f, 0xff0000ff, kFillModeSolid);
		timer_ = 100;
	}*/
}
