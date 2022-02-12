#pragma once
#include "SDLgraphics.hpp"
#include "Interface.hpp"
#include <list>
#include <memory>

static constexpr std::string_view TITLE = "SDL TESTING FIELD";
static constexpr int SCREEN_WIDTH = 1080;
static constexpr int SCREEN_HEIGHT = 720;

class Program {
public:
	void run();
private:
	SDLWindow window{ SCREEN_WIDTH, SCREEN_HEIGHT, TITLE };
	std::list<Element*> elementsList;
	bool exit = false;
	void draw();
	void init();
	void mainLoop();
	void event();
	void mouseHandle(int x, int y);
};