#include "App.h"
#include "StateIncludes.h"

int main() {
	App game;

	game.push_state(new StartUpState(&game));

	game.GameLoop();

	return 0;
}