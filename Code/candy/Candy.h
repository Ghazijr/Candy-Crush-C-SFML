#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/window.hpp" //SFML

class Candy
{
private:
	char color;
	char raiure;
	bool explosive;
	bool multi;
	sf::Texture tx;
	sf::Sprite sp;
public:
	int grid_x, grid_y;
	int alpha = 240;

	Candy(int x = -1, int ord = 0, char clr = 'X',char r = 'n', bool exp = false ,bool m = false);
	~Candy();
	//void setpos(int x, int y); SFML
	void setclr(char clr);
	void setgridpos(int r, int c);
	void setraiure(char);
	void setexplosive(bool);
	void setmulti(bool);
	void setSFMLpos(int, int);
	void setSFMLimages();

	bool operator ==(Candy c);
	void operator =(Candy c);

	int get_x();
	int get_y();
	char get_clr();
	char get_raiure();
	bool get_explosive();
	bool get_multi();
	int get_grid_x();
	int get_grid_y();
	sf::Sprite get_sp();
};

