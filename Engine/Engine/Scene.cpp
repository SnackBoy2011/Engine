#include "Scene.h"
#include"GameObject.h"

namespace scene
{
	Scene::Scene ()
	{
	}


	Scene::~Scene ()
	{
	}

	bool Scene::init ()
	{
		for (GameObject* go : gameObjects)
		{
			if (!go->init())
				return false;
				
		}
		return true;
	}
	void Scene::update ()
	{
		for (GameObject* go : gameObjects)
		{
			go->update();
				

		}
	}
	void Scene::draw () const
	{
		for (GameObject* go : gameObjects)
		{
			go->draw();


		}
	}
	bool Scene::shutdown ()
	{
		for (GameObject* go : gameObjects)
		{
			if (!go->shutdown())
				return false;

		}
		return true;
	}
}