#include "Enemy.h"
#include<Novice.h>
Enemy::~Enemy()
{
}
void Enemy::initalize()
{
	trance. x= 640;
	trance.y = 150;
	speed_.x = 5;
	speed_.y = 5;
	radius_ = 20;
	isAlive_ = 1;
	timer_ = 0;
	hp_ = 3;
}

void Enemy::Update()
{
	
	if (isAlive_ == 1) {
		trance.x += speed_.x;
		trance.y += speed_.y;
		if (trance.x >= 1260 || trance.x <= 20) {
			speed_.x*= -1;
			
		}if (trance.y >= 700||trance.y <=20) {
			speed_.y*=-1;
		}
	}
}

void Enemy::OnCollision()
{
	if (isAlive_ == 0) {
		timer_++;
		if (timer_ >= 120) {
			isAlive_ = 1;
			hp_ -= 1;
			timer_ = 0;
		}
		
	}
}

void Enemy::Draw()
{
	if (isAlive_ == 1) {
		
		Novice::DrawEllipse(trance.x, trance.y, radius_, radius_, 0.0f, 0xff0000ff, kFillModeSolid);
		
	
	}
			//Novice::DrawEllipse(trance.x, trance.y, radius_, radius_, 0.0f, 0xff0000ff, kFillModeSolid);
		
}
