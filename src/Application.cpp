#include "Application.h"
#include <spdlog/spdlog.h>

#include "imgui-SFML.h"
#include "imgui.h"
#include "spdlog/sinks/stdout_color_sinks-inl.h"
#include <BuildConfig.h>

void Verbeal::Application::Init()
{
	auto console = spdlog::stdout_color_mt("console");    
    auto err_logger = spdlog::stderr_color_mt("stderr");

	m_renderWindow.create(sf::VideoMode({640u, 480u}), "Verbeal");
	m_renderWindow.setFramerateLimit(144);

	if (!ImGui::SFML::Init(m_renderWindow))
	{
        spdlog::error("Could not init ImGUI");
	}
}

void Verbeal::Application::Run()
{
	sf::Clock clock;
    while (m_renderWindow.isOpen())
    {
        while (const std::optional event = m_renderWindow.pollEvent())
        {
        	ImGui::SFML::ProcessEvent(m_renderWindow, *event);

        	if (event->is<sf::Event::Closed>())
            {
                m_renderWindow.close();
            }
        }

        ImGui::SFML::Update(m_renderWindow, clock.restart());

        

        ImGui::Begin(VERBEAL_VERSION_STR);
        if (ImGui::Button("Look at this pretty button"))
        {
			spdlog::get("console")->warn("Button pressed");
        }
        ImGui::End();

        m_renderWindow.clear();
        ImGui::SFML::Render(m_renderWindow);
        m_renderWindow.display();
    }
}

void Verbeal::Application::Cleanup()
{
	ImGui::SFML::Shutdown();
}
