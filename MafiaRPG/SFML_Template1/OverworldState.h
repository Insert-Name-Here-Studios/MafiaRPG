#pragma once
#ifndef OVERWORLD_STATE_H
#define OVERWORLD_STATE_H
#include <SFML\Graphics.hpp>

#include "State.h"
#include "TextureManager.h"
#include "FontManager.h"

class OverworldState : public State
{
public:

	virtual void render(const float delta);
	virtual void update(const float delta);
	virtual void handleInput();

	OverworldState(App* game);

private:
	void Pause();
	void Resume();
	bool paused = false;

	bool keys[4];

	sf::View view;
	TextureManager gameScreen;
	FontManager gameFonts;
	sf::Text gameText;
	sf::Sprite gameBackground;
	sf::Vector2f pos;
};

#endif