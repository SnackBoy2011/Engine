#pragma once
#include <Scene.h>
#include "Player.h"
#include "Enemy.h"

namespace core
{
	class InputSystem;
};

class MainScene : public scene::Scene
{
	Player player;
	Enemy enemy;

	core::InputSystem* inputSystem;

public:
	MainScene ();
	~MainScene ();

	bool init () override;
	void update () override;
	void draw () const override;
	bool shutdown () override;
};

