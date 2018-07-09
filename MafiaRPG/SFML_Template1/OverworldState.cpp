#include "OverworldState.h"
#include "StartUpState.h"
#include <iostream>

#include <SFML\Graphics.hpp>

#include "State.h"

OverworldState::OverworldState(App* game)
{
	gameScreen.AddResource("GameBackground");
	gameBackground.setTexture(*(gameScreen.GetResource("GameBackground")));

	gameFonts.AddResource("gameFont");
	gameText.setFont(*(gameFonts.GetResource("gameFont")));
	gameText.setString("Test");
	gameText.setCharacterSize(36);
	gameText.setFillColor(sf::Color::White);
	gameText.setPosition(0, 0);

	pos.y = 0;
	pos.x = 0;

	this->game = game;
}

void OverworldState::Pause()
{
	paused = true;
}

void OverworldState::Resume()
{
	paused = false;
}




void OverworldState::render(const float delta)
{
	
	game->gameWindow.draw(gameText);
	game->gameWindow.draw(gameBackground);
}

void OverworldState::update(const float delta)
{
	if(!paused)
		gameBackground.setPosition(pos);
	if (keys[0])
		pos.y--;
	if (keys[1])
		pos.y++;
	if (keys[2])
		pos.x--;
	if (keys[3])
		pos.x++;
}

void OverworldState::handleInput()
{
	sf::Event e;

	while (game->gameWindow.pollEvent(e)) {
		switch (e.type) {
		case sf::Event::Closed:
			game->gameWindow.close();
			break;
		case sf::Event::KeyPressed:
			if (e.key.code == sf::Keyboard::Escape) {
				if (paused)
					Resume();
				else
					Pause();
			}
				
			if (!paused) {
				if (e.key.code == sf::Keyboard::W || e.key.code == sf::Keyboard::Up)
					keys[0] = true;
				if (e.key.code == sf::Keyboard::S || e.key.code == sf::Keyboard::Down)
					keys[1] = true;
				if (e.key.code == sf::Keyboard::A || e.key.code == sf::Keyboard::Left)
					keys[2] = true;
				if (e.key.code == sf::Keyboard::D || e.key.code == sf::Keyboard::Right)
					keys[3] = true;
			}
			break;
		case sf::Event::KeyReleased:
			if (!paused) {
				if (e.key.code == sf::Keyboard::W || e.key.code == sf::Keyboard::Up)
					keys[0] = false;
				if (e.key.code == sf::Keyboard::S || e.key.code == sf::Keyboard::Down)
					keys[1] = false;
				if (e.key.code == sf::Keyboard::A || e.key.code == sf::Keyboard::Left)
					keys[2] = false;
				if (e.key.code == sf::Keyboard::D || e.key.code == sf::Keyboard::Right)
					keys[3] = false;
			}
			break;
		}
	}
}
