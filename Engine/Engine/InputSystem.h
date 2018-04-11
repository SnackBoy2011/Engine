#pragma once
#include "System.h"
#include <map>

namespace core
{
	class InputSystem : public System
	{
		bool quitResquested;

		bool m_leftPressed = false;
		bool m_rightPressed = false;
		bool m_upPressed = false;
		bool m_downPressed = false;

		std::map<unsigned int, bool> keys;

	public:
		InputSystem ();
		~InputSystem ();

		void update () override;

		inline bool IsLeftPressed () const { return m_leftPressed; }
		inline bool IsRightPressed () const { return m_rightPressed; }
		inline bool IsUpPressed () const { return m_upPressed; }
		inline bool IsDownPressed () const { return m_downPressed; }

		bool IsKeyDown(unsigned int key);

		inline bool QuitResquested () const { return quitResquested; }
	};
}

