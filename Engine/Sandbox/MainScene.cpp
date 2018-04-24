#include "MainScene.h"

#include <Engine.h>
#include <SystemManager.h>
#include <InputSystem.h>
#include <iostream>
#include "Player.h"
#include <SDL.h>
#include <GameObject.h>
#include"Enemy.h"

MainScene::MainScene () :
	player("player.bmp"),enemy("alien.bmp")
{
	gameObjects.push_back(&player);
	gameObjects.push_back(&enemy);
}


MainScene::~MainScene ()
{
}

bool MainScene::init ()
{
	Scene::init();
	inputSystem = dynamic_cast<core::InputSystem*>(core::SystemManager::GetInstance ()->GetSystem (core::SystemType::INPUT));

	return true;
}

void MainScene::update ()
{
	Scene::update();
	//enemy.Update();
	if(inputSystem->isKeyDown(SDLK_LEFT))
		player.transform.x -= 1;
	if (inputSystem->isKeyDown(SDLK_RIGHT))
		player.transform.x += 1;
	if (inputSystem->isKeyDown(SDLK_UP))
		player.transform.y -= 1;
	if (inputSystem->isKeyDown(SDLK_DOWN))
		player.transform.y += 1;
	
	// draw the player
	SDL_Surface *windowSurface = engine->getSurface ();
	// notice the function to draw the player scaled down
//	SDL_BlitSurface (player.objectImage, NULL, windowSurface, &player.transform);

	for (scene::GameObject* go : gameObjects)
	{
		go->draw(windowSurface);
		//go->update();
	}
}

void MainScene::draw () const
{
	Scene::draw();
	SDL_UpdateWindowSurface (engine->getWindow());
}


bool MainScene::shutdown ()
{
	Scene::shutdown();
	return true;
}