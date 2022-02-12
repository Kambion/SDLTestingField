
#include "SDLgraphics.hpp"

static constexpr std::string_view TITLE = "SDL TESTING FIELD";
static constexpr int SCREEN_WIDTH = 1080;
static constexpr int SCREEN_HEIGHT = 720;

#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char** argv) {
	SDLWindow window{ SCREEN_WIDTH, SCREEN_HEIGHT, TITLE };
	while (true) {
		window.drawCircle(100, 100, 50, 3, 0xFFFFFF);
		window.update();
	}
	return 0;
};