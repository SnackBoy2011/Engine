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
				
				/*switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					m_leftPressed = true;
					break;
				case SDLK_RIGHT:
					m_rightPressed = true;
					break;
				case SDLK_UP:
					m_upPressed = true;
					break;
				case SDLK_DOWN:
					m_downPressed = true;
					break;
				}*/
				break;
			case SDL_KEYUP:
				keys[e.key.keysym.sym] = false;
				/*
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					m_leftPressed = false;
					break;
				case SDLK_RIGHT:
					m_rightPressed = false;
					break;
				case SDLK_UP:
					m_upPressed = false;
					break;
				case SDLK_DOWN:
					m_downPressed = false;
					break;
				}*/
				break;

		/*	case SDL_MOUSEMOTION:
				std::cout << "Mouse is moving" << std::endl;
				break;*/
			case SDL_QUIT:
				quitResquested = true;
				break;
			}
		}
	}
	bool InputSystem::isKeyDown(unsigned int key)
	{
		auto it = keys.find(key);
		if(it != keys.end())
			return keys[key];

		return false;
	}
}
