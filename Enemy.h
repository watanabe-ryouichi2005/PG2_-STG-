#pragma once
#include"Tranceform.h"
class Enemy
{private:
	Tranceform trance;
	int speed_;
	int radius_;
	int isAlive_;
	int timer_;


public:
	~Enemy();
	
	void initalize();
	void Update();
	
		void Draw();
		Tranceform Getpos() { return trance; };
		int Getradius() { return radius_; };
		int GetisAlive() { return isAlive_; };
		int SetisAlive(int isAlive) { return isAlive_ = isAlive; };
		int Gettimer() { return timer_; };
		int Settimer(int timer) { return timer_ = timer; };

};

