#include "Interface.hpp"

int Element::mapButton(int yc) {
	if (dropListElements) {
		int step = (h / dropListElements);
		for (int i = 0; i < dropListElements; i++) {
			if (yc > y + i * step && yc < y + (i + 1) * step) {
				return i;
			}
		}
	}
	return 0;
}
void Button1::onClick(int xc, int yc) {
	std::cout << "test\n";
}
void Button2::onClick(int xc, int yc) {
	std::cout << "dupa\n";
}
void Droplist1::onClick(int xc, int yc) {
	elements->changeActive();
	elements->changeDraw();
}
void Droplist1::initElements(std::list<Element*> *elementsList) {
	elements->setDroplistNumber(3);
	elements->setText("text1+dupa+mleko");
	elements->changeActive();
	elements->changeDraw();
	elementsList->push_front(elements);
}
void Droplist1Elements::onClick(int xc, int yc) {
	int button = mapButton(yc);
	switch (button) {
	case 0:
		std::cout << "button 1\n";
		break;
	case 1:
		std::cout << "button 2\n";
		break;
	case 2:
		std::cout << "button 3\n";
		break;
	}
}