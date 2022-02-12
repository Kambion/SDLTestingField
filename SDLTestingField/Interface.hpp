#pragma once
#include "SDL.h";
#include <list>
#include <iostream>

enum class ElementDrawType {
	BUTTON,
	DROPLISTMAIN,
	DROPLIST
};
class Element {
protected:
	int x, y;
	int w, h;
	bool active = true;
	bool draw = true;
	int dropListElements = 0;
	ElementDrawType drawType;
	std::string text = "";
public:
	Element(int x, int y, int w, int h, ElementDrawType type) : x(x), y(y), w(w), h(h), drawType(type) {}
	inline SDL_Rect shape() {SDL_Rect rect = { x, y, w, h }; return rect;}
	inline ElementDrawType type() { return drawType; }
	inline bool checkClick(int xc, int yc) { return (xc > x && xc<x + w && yc>y && yc < y + h); }
	inline bool checkDraw() { return draw; }
	inline bool checkActive() { return active; }
	inline std::string getText() { return text; }
	inline void setText(std::string textInput) { text = textInput; }
	inline int getDroplistNumber() { return dropListElements; }
	inline void setDroplistNumber(int number) { dropListElements = number; }
	inline void changeActive() { active = !active; }
	inline void changeDraw() { draw = !draw; }

	virtual void onClick(int xc, int yc) = 0;

	int mapButton(int yc);
};
class Button1 : public Element {
public:
	Button1(int x, int y, int w, int h, ElementDrawType type) : Element(x, y, w, h, type) {}
	void onClick(int xc, int yc) override;
};
class Button2 : public Element {
public:
	Button2(int x, int y, int w, int h, ElementDrawType type) : Element(x, y, w, h, type) {}
	void onClick(int xc, int yc) override;
};
class Droplist1Elements : public Element {
public:
	Droplist1Elements(int x, int y, int w, int h, ElementDrawType type) : Element(x, y, w, h, type) {}
	void onClick(int xc, int yc) override;
};
class Droplist1 : public Element {
public:
	Droplist1(int x, int y, int w, int h, ElementDrawType type) : Element(x, y, w, h, type) {}
	void onClick(int xc, int yc) override;
	void initElements(std::list<Element*>* elementsList);
private:
	Droplist1Elements* elements = new Droplist1Elements{x+5, y+h, w-10, h*3, ElementDrawType::DROPLIST};
};
