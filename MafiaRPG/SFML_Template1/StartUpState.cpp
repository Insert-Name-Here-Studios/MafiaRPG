#include "StartUpState.h"
#include "OverworldState.h"
#include "State.h"
#include "TextureManager.h"

#include <iostream>

#include "SFML\Graphics.hpp"

StartUpState::StartUpState(App* game) 
{
	menuScreen.AddResource("MenuBackground");
	MenuBackground.setTexture(*(menuScreen.GetResource("MenuBackground")));
	
	game->gameWindow.setSize(sf::Vector2u(MenuBackground.getGlobalBounds().width, MenuBackground.getGlobalBounds().height));

	game->gameWindow.setView(view);

	this->game = game;
}

void StartUpState::render(const float delta) 
{
	
	


	game->gameWindow.draw(MenuBackground);
}

void StartUpState::update(const float delta)
{
}

void StartUpState::handleInput()
{
	sf::Event e;

	while (game->gameWindow.pollEvent(e)) {
		switch (e.type) {
		case sf::Event::Closed:
			game->gameWindow.close();
			break;
		case sf::Event::KeyPressed:
			if (e.key.code == sf::Keyboard::Return)
				startGame();
			break;

		}
	}
}

void StartUpState::startGame()
{
	game->push_state(new OverworldState(game));
}



