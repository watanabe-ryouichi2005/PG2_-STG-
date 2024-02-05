#pragma once
#include "Tranceform.h"

class Bullet
{
private:
	Tranceform bulletpos_;
	float radius_ ;
	float speed_;
	
	
public:
	int isBullet;
	Bullet();
	~Bullet();
	void Update();
	void Draw();

	Tranceform Getpos() { return bulletpos_; };
	void Setpos(Tranceform bulletpos) { this->bulletpos_ = bulletpos; };
	int Getradius() { return radius_; };

};

