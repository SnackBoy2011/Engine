#include "Enemy.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

Enemy::Enemy(std::string path) :
	GameObject(path)
{
	transform.y = 0;
	transform.x = 0;
	transform.w = 300;
	transform.h = 150;
	speedX = 2.0f;
	startTime = std::clock();
}


void Enemy::update()
{
	duration = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	std::cout << "X: " << transform.x << '\n';

	//move enemy by 2 every .005 seconds
	if (duration >= 0.005) {
		moveEnemy();
	}
}

void Enemy::moveEnemy() {
	startTime = std::clock();

	//check if out of bounds, reverse direction, increase speed
	if (transform.x + transform.w >= 1000 || transform.x <= 0) {
		speedX *= -1.1f;
		transform.y += 25;
	}
	transform.x += speedX;
}

Enemy::~Enemy()
{
}


