#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <nlohmann/json.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

int main()
{
	auto console = spdlog::stdout_color_mt("console");    
    auto err_logger = spdlog::stderr_color_mt("stderr");    
    spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");


    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Verbeal");
    window.setFramerateLimit(144);

	if (!ImGui::SFML::Init(window))
	{
        spdlog::get("console")->error("Could not init ImGUI");
        return -1;
	}

    sf::Clock clock;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
        	ImGui::SFML::ProcessEvent(window, *event);

        	if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        ImGui::SFML::Update(window, clock.restart());

        ImGui::Begin("Hello, world!");
        if (ImGui::Button("Look at this pretty button"))
        {
			spdlog::get("console")->warn("Button pressed");
        }
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

	ImGui::SFML::Shutdown();
}
