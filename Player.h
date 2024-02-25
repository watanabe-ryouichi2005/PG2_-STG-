#pragma once
#include "Tranceform.h"
#include "Bullet.h"
class Player
{private:
	Tranceform tranceform;
	int radius_;
	int speed_;
public:
	Bullet *bullet;
	Player();
	~Player();
	void Update(char *keys,char *preKeys);
	void Draw();
	Tranceform Getpos() { return tranceform; };
	void Setpos(Tranceform trance) { this->tranceform = trance; };
	int Getradius() { return radius_; };
	int tmpisshot;
};

