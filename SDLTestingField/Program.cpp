#include "Program.hpp"

void Program::run() {
	mainLoop();
}
void Program::mainLoop() {
	while (!exit) {
		event();
		draw();
	}
}
void Program::draw() {

	window.update();
}
void Program::event() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				exit = true;
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		case SDL_KEYUP:
			break;
		case SDL_QUIT:
			break;
		};
	};
}