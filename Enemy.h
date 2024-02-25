#pragma once
#include"Tranceform.h"
class Enemy
{private:
	Tranceform trance_;
	Tranceform speed_;
	int radius_;
	int isAlive_;
	int timer_;
	int hp_;

public:
	~Enemy();
	
	void initalize();
	void Update();
	void OnCollision(Scene&scene);

		void Draw();
		Tranceform Getpos() { return trance_; };
		void Setpos(Tranceform trance) { this->trance_=trance; };
		int Getradius() { return radius_; };
		int GetisAlive() { return isAlive_; };
		int SetisAlive(int isAlive) { return this->isAlive_ = isAlive; };
		
		int GetHp() { return hp_; };
		int SetHp(int hp) { return this->hp_ = hp; };

};

