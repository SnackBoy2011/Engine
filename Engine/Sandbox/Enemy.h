#pragma once
#include <GameObject.h>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>
class Enemy : public scene::GameObject

{
public:
	Enemy(std::string path);

	std::clock_t startTime;
	double duration;
	float speedX;
	//int speedY;

	void update() override;
	void moveEnemy();
	~Enemy();
};

