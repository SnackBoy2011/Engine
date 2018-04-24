#include "Player.h"

Player::Player (std::string path) :
	GameObject(path)
{
	transform.y = 500;
	transform.x = 500;
	transform.w = 90;
	transform.h = 90;
}

Player::~Player ()
{

}