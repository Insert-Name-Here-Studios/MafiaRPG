#ifndef STATE_H

#define STATE_H

#include "App.h"

class State {
public:

	App* game;

	virtual void render(const float delta) = 0;
	virtual void update(const float delta) = 0;
	virtual void handleInput() = 0;

};

#endif