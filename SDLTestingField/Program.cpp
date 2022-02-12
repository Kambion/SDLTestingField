#include "Program.hpp"

void Program::run() {
	init();
	mainLoop();
}
void Program::init() {
	Button1* button1 = new Button1{ 100, 100, 100, 30, ElementDrawType::BUTTON };
	button1->setText("text");
	Button2* button2 = new Button2{ 300, 100, 100, 30, ElementDrawType::BUTTON };
	elementsList.push_front(button1);
	elementsList.push_front(button2);
	Droplist1* droplist = new Droplist1{ 500, 100, 150, 50, ElementDrawType::DROPLISTMAIN };
	droplist->setText("droplist");
	droplist->initElements(&elementsList);
	elementsList.push_front(droplist);
}
void Program::mainLoop() {
	while (!exit) {
		event();
		draw();
	}
}
void Program::draw() {
	std::list<Element*>::iterator it = elementsList.begin();
	while (it != elementsList.end()) {
		if ((*it)->checkDraw()) {
			window.drawElement((*it)->shape(), (*it)->type(), (*it)->getText(), (*it)->getDroplistNumber());
		}
		it++;
	}
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
			mouseHandle(event.button.x, event.button.y);
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
void Program::mouseHandle(int x, int y) {
	std::list<Element*>::iterator it = elementsList.begin();
	while (it != elementsList.end()) {
		if ((*it)->checkActive() && (*it)->checkClick(x, y)) {
			(*it)->onClick(x, y);
			break;
		}
		it++;
	}
}