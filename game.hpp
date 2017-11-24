#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game {
public:
	Game();
	void run();
	
private:
	bool is_moving_up;
	bool is_moving_down;
	bool is_moving_left;
	bool is_moving_right;
	
	static const float PlayerSpeed;
	static const sf::Time TimePerFrame;

	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	
	void handlePlayerInput(sf::Keyboard::Key key, bool is_pressed);
	
	sf::CircleShape m_circle;
	sf::RenderWindow m_mainWindow;
};

#endif // GAME_HPP
