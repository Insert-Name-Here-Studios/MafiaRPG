#ifndef STARTUP_STATE_H

#define STARTUP_STATE_H


#include "SFML\Graphics.hpp"

#include "State.h"
#include "TextureManager.h"
#include "FontManager.h"

class StartUpState : public State
{
public:
	StartUpState(App* game);
	
	virtual void render(const float delta);
	virtual void update(const float delta);
	virtual void handleInput();

private:
	sf::View view;
	TextureManager menuScreen;
	FontManager menuFonts;
	sf::Sprite MenuBackground;

	void startGame();
};


#endif