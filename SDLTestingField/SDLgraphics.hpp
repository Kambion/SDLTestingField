#pragma once

#include "SDL_common.hpp"
#include "Interface.hpp"
#include <string_view>
#include <utility>

enum class Highlight { RED, GREEN, CIRCLE };
enum class Fonts {ARIAL, SANS, COMIC_SANS, CONSOLAS};

class SDLWindow {
private:	//niezmienne dla user(debil)
	int w, h;
	std::string_view title;

	SDL_Surface* screen = nullptr;
	SDL_Texture* scrtex = nullptr;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	TTF_Font* font = nullptr;

	struct {
		SDL_Surface
			* charset = nullptr,
			* pieces = nullptr,
			* background = nullptr,
			* deskaRustykalna03NaŚcianęJasnyBrąz = nullptr;
	} images;
	struct {
		Uint32 white{}, light_gary{}, dark_gary{}, light_red{}, light_green{};
	} colors;
public: //user(debil) może popsuć
	SDLWindow(int width, int height, std::string_view title);

	inline int width() const { return w; } 
	inline int height() const { return h; }
	inline std::string_view windowTitle() const { return title; }

	Uint32 mapColor(int rgb) const;

	void drawPixel(int x, int y, Uint32 color);
	void drawString(int x, int y, std::string text, int fontSize, Fonts fontName, SDL_Color color);
	void drawString(SDL_Rect rect, std::string text, int fontSize, Fonts fontName, SDL_Color color);
	void drawLine(int x, int y, int l, int dx, int dy, Uint32 color);
	void drawRectangle(SDL_Rect rect, Uint32 fillColor);
	void drawRectangle(SDL_Rect rect, int thickness, Uint32 outlineColor, Uint32 fillColor);
	void drawCircle(int x, int y, int radius, int thickness, Uint32 fillColor);
	void drawElement(SDL_Rect rect, ElementDrawType type, std::string text, int droplistNumber = 0);
	void update();

	~SDLWindow(); 
private:
	bool loadImages();
	void initColors();
};
