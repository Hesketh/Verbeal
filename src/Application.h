#pragma once
#include "SFML/Graphics/RenderWindow.hpp"

namespace Verbeal
{
	class Application
	{
	private:
		sf::RenderWindow m_renderWindow;
	public:
		void Init();
		void Run();
		void Cleanup();
	};
}