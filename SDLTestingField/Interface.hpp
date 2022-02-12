#pragma once

typedef void (*funcPtr)();
enum class Types{
	BUTTON
};

class Element {
protected:
	int x, y;
	int w, h;
	Types type;
public:
	Element(int x, int y, int w, int h, Types type) : x(x), y(y), w(w), h(h), type(type) {}
	void onClick();
};

class Button : public Element {
public:
	Button(int x, int y, int w, int h, Types type) : Element(x, y, w, h, type) {}
};