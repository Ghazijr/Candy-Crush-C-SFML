#include "Candy.h"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace std;

//Constructor
Candy::Candy(int x  , int y , char clr, char r , bool exp, bool m) {
	grid_x = x;
	grid_y = y;
	color = clr;
	raiure = r;
	explosive = exp;
	multi = m;
}
//destructure 
Candy::~Candy() {};
//Setters
void Candy::setclr(char clr) {
	color = clr;
}

void Candy::setgridpos(int r, int c) {
	grid_x = r;
	grid_y = c;
}
void Candy::setSFMLpos(int x, int y) {
	this->sp.setPosition(sf::Vector2f(x, y));
}
void Candy::setSFMLimages() {
	if (this->color != 'X') {
		if (this->get_raiure() == 'h') {
			this->tx.loadFromFile("assets/" + string(1, color) + "H.png");
			this->sp.setTexture(tx);
			
		}
		else if (this->get_raiure() == 'v') {
			this->tx.loadFromFile("assets/" + string(1, color) + "V.png");
			this->sp.setTexture(tx);
		}
		else if (this->get_explosive() == true) {
			this->tx.loadFromFile("assets/" + string(1, color) + "E.png");
			this->sp.setTexture(tx);

		}
		else if (this->get_clr() == 'M') {
			this->tx.loadFromFile("assets/ColourBomb.png");
			this->sp.setTexture(tx);
		}
		else {
			this->tx.loadFromFile("assets/" + string(1, color) + ".png");
			this->sp.setTexture(tx);
		}
		this->sp.setColor(sf::Color(255, 255, 255, this->alpha));
	}
}
void Candy::setexplosive(bool exp) {
	explosive = exp;
}
void Candy::setraiure(char r) {
	raiure = r;
}
void Candy::setmulti(bool m) {
	multi = m;
}
bool Candy::get_multi() {
	return multi;
}
//Getters
int Candy::get_x() {
	return grid_x;
}
int Candy::get_y() {
	return grid_y;
}
char Candy::get_clr() {
	return color;
}
int Candy::get_grid_x() {
	return grid_x;
}
int Candy::get_grid_y() {
	return grid_y;
}
char Candy::get_raiure() {
	return raiure;
}
bool Candy::get_explosive() {
	return explosive;
}
sf::Sprite Candy::get_sp() {
	return sp;
}
bool Candy::operator == (Candy c) {
	return (this->color == c.color);
}
void  Candy::operator = (Candy c) {
	color = c.color;
	grid_x = c.grid_x;
	grid_y = c.grid_y;
	raiure = c.raiure;
	explosive = c.explosive;
	multi = c.multi;
}