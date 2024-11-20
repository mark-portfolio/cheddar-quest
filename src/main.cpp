#include <SFML/Graphics.hpp> // for graphics
#include <fstream> // for logging

int main()
{
    // Open a log file to write debugging information to.
    std::ofstream logFile("log.txt");

    // Create a window on your screen, sized to 800 pixels by 600 pixels,
    // with the title Cheddar Quest.
    auto window = sf::RenderWindow({800u, 600u}, "Cheddar Quest");

    // Don't redraw the window more than 144 times per second.
    window.setFramerateLimit(144);

    // Mouse texture
    sf::Texture mouseTexture;

    if (!mouseTexture.loadFromFile("assets/mouse.png")) {
        logFile << "Failed to load mouse texture.\n";
        return EXIT_FAILURE;
    }

    sf::Sprite mouseSprite;
    mouseSprite.setTexture(mouseTexture);

    // Position of the mouse
    int mouseX = 10, mouseY = 10;

    // Cheese texture
    sf::Texture cheeseTexture;

    if (!cheeseTexture.loadFromFile("assets/cheese.png")) {
        logFile << "Failed to load cheese texture.\n";
        return EXIT_FAILURE;
    }

    sf::Sprite cheeseSprite;
    cheeseSprite.setTexture(cheeseTexture);

    // Position of the cheese
    int cheeseX = 600, cheeseY = 400;

    while (window.isOpen())
    {
        // Loop over the events that are waiting to be processed.
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            --mouseX;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            ++mouseX;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            --mouseY;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            ++mouseY;
        }

        // Fill the window with the color black.
        window.clear(sf::Color::Black);

        mouseSprite.setPosition(mouseX, mouseY);
        window.draw(mouseSprite);

        cheeseSprite.setPosition(cheeseX, cheeseY);
        window.draw(cheeseSprite);
        
        // Display the stuff we drew.
        window.display();
    }
}
