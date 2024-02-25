#pragma once
#include"Tranceform.h"
class Enemy
{private:
	Tranceform trance;
	Tranceform speed_;
	int radius_;
	int isAlive_;
	int timer_;
	int hp_;

public:
	~Enemy();
	
	void initalize();
	void Update();
	void OnCollision();

		void Draw();
		Tranceform Getpos() { return trance; };
		int Getradius() { return radius_; };
		int GetisAlive() { return isAlive_; };
		int SetisAlive(int isAlive) { return this->isAlive_ = isAlive; };
		//int Gettimer() { return timer_; };
		//int Settimer(int timer) { return this->timer_ = timer; };
		int GetHp() { return hp_; };
		int SetHp(int hp) { return this->hp_ = hp; };

};

