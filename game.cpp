#include "game.hpp"
#include <iostream>
using namespace std;

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() {
	m_mainWindow.create(sf::VideoMode(640, 480, 32), "Lin98");
	m_circle.setRadius(40.f);
	m_circle.setPosition(100.f, 100.f);
	m_circle.setFillColor(sf::Color::Cyan);
}

void Game::run() {	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	
	while (m_mainWindow.isOpen()) {
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	
	while (m_mainWindow.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				m_mainWindow.close();
				break;
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool is_pressed) {
	if (key == sf::Keyboard::W)
		is_moving_up = is_pressed;
	else if (key == sf::Keyboard::S)
		is_moving_down = is_pressed;
	else if (key == sf::Keyboard::A)
		is_moving_left = is_pressed;
	else if (key == sf::Keyboard::D)
		is_moving_right = is_pressed;
}

void Game::update(sf::Time deltaTime) {
	sf::Vector2f movement(0.f, 0.f);
	
	if (is_moving_up)
		movement.y -= PlayerSpeed;
	if (is_moving_down)
		movement.y += PlayerSpeed;
	if (is_moving_left)
		movement.x -= PlayerSpeed;
	if (is_moving_right)
		movement.x += PlayerSpeed;
		
	m_circle.move(movement * deltaTime.asSeconds());
}

void Game::render() {
	m_mainWindow.clear();
	m_mainWindow.draw(m_circle);
	m_mainWindow.display();
}

