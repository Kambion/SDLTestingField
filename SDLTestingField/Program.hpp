#pragma once
#include "SDLgraphics.hpp"
#include "Interface.hpp"

static constexpr std::string_view TITLE = "SDL TESTING FIELD";
static constexpr int SCREEN_WIDTH = 1080;
static constexpr int SCREEN_HEIGHT = 720;

class Program {
public:
	void run();
private:
	SDLWindow window{ SCREEN_WIDTH, SCREEN_HEIGHT, TITLE };
	bool exit = false;
	void draw();
	void mainLoop();
	void event();
};