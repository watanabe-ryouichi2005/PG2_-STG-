#pragma once
#include"Tranceform.h"
class Enemy
{private:
	Tranceform trance;
	int speed_;
	int radius_;
	int	isAlive;


public:
	~Enemy();

	void initalize();
	void Update();
	
		void Draw();
		Tranceform Getpos() { return trance; };
		int Getradius() { return radius_; };
};

