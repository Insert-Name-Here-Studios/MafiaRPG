#ifndef APP_H

#define APP_H


#include <vector>
#include "SFML/Graphics.hpp"

class State;

class App {
public:
	App();
	~App();

	void push_state(State* state);
	void pop_state();

	State* getCurrentState();

	void GameLoop();

	sf::RenderWindow gameWindow;

private:
	std::vector<State*> states;
};

#endif