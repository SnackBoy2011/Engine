#include "InputSystem.h"

#include <SDL.h>
#include <iostream>
namespace core
{
	InputSystem::InputSystem () :
		System (SystemType::INPUT),
		quitResquested(false)
	{
	}


	InputSystem::~InputSystem ()
	{
	}

	void InputSystem::update ()
	{
		//Event handler
		SDL_Event e;

		//Handle events on queue
		while (SDL_PollEvent (&e) != 0)
		{
			switch (e.type)
			{
			case SDL_KEYDOWN:
				keys[e.key.keysym.sym] = true;
				break;
			case SDL_KEYUP:
				keys[e.key.keysym.sym] = false;
				break;
			case SDL_QUIT:
				quitResquested = true;
				break;
			}
		}
	}


	bool InputSystem::IsKeyDown(unsigned int key) 
	{
		auto it = keys.find(key);

		if (it != keys.end())
			return keys[key];

		return false;
	}
}
