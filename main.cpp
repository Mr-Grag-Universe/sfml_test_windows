#include <iostream>

#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

int main() {
    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    std::cout << "desktop: (" << mode.size.x << "; " << mode.size.y << ")\n";
    sf::Vector2u size((int) mode.size.x, (int) mode.size.y);
    // sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WIDTH, HEIGHT)), "Walker Game");
    sf::RenderWindow window(sf::VideoMode(size), "Walker Game");

    while(window.isOpen()){
        sf::Event event{};
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }

            window.clear(sf::Color::Black);
            window.display();
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
