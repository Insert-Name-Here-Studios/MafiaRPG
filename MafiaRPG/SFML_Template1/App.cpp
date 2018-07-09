#include "App.h"
#include "State.h"

const int WINDOW_HEIGHT = 480, WINDOW_WIDTH = 640;

App::App() {
	gameWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "MafiaRPG");

	gameWindow.setFramerateLimit(60);
}

App::~App()
{
	while (!states.empty())
		states.pop_back();
}

void App::push_state(State * state)
{
	states.push_back(state);
}

void App::pop_state()
{
	states.back();
	delete states.back();
	states.pop_back();
}

State * App::getCurrentState()
{
	if (states.empty())
		return nullptr;
	else
		return states.back();
}

void App::GameLoop()
{
	sf::Clock gameClock;

	while (gameWindow.isOpen()) {
		sf::Time tempDT = gameClock.restart();
		float delta = tempDT.asSeconds();

		if (getCurrentState() == nullptr)
			continue;

		getCurrentState()->handleInput();

		getCurrentState()->update(delta);

		gameWindow.clear();

		getCurrentState()->render(delta);

		gameWindow.display();
	}
}

