#include "Player.h"
#include<Novice.h>
Player::Player()
{
	
	tranceform.x = 500;
	tranceform.y = 700;
	speed_ = 5;
	radius_ = 50;
	bullet = new Bullet();

}

Player::~Player()
{
	delete bullet;
}

void Player::Update(char *keys,char *preKeys)
{

	Tranceform tempPlayerpos = Getpos();

	if (keys[DIK_W]) {
		tranceform.y -= speed_;
	}if (keys[DIK_S]) {
		tranceform.y += speed_;
	}if (keys[DIK_D]) {
		tranceform.x += speed_;
	}if (keys[DIK_A]) {
		tranceform.x -= speed_;
	}
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]&&bullet->isBullet==0) {
		bullet->isBullet = 1;
		bullet->Setpos(tempPlayerpos);
	}

	bullet->Update();
}

void Player::Draw()
{
	bullet->Draw();
	
	Novice::DrawBox(tranceform.x, tranceform.y, radius_, radius_,0.0f, 0xffff00ff, kFillModeSolid);
}
