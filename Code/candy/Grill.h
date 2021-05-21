#pragma once
#include <iostream>
#include "Candy.h" 
using namespace std;
class Grill {
private:
	int dim;
	Candy** g;
	sf::IntRect** rects;
public:
	Grill(int);
	~Grill();
	void remplir(Candy** g);
	void affiche(Candy** g);
	Candy** get_g();
	sf::IntRect** get_rects();
	void set_g(Candy** m);

	bool permut(int, int, int, int, Candy** g);
	Candy** verif3(int dim, Candy** g);
	Candy** verif4(int dim, Candy** g);
	Candy** verif5(int dim, Candy** g);
	Candy** verifL(int dim, Candy** g, Candy** m);
	Candy** verifT(int dim, Candy** g, Candy** m);
	void translate(int dim, Candy** g);
	void change(int, int, Candy, Candy** g);
	void generer(Candy** g);
	void Explosif(Candy** g, Candy c);
	void Raiure(Candy** g, Candy c);
	void Multi(Candy** g, Candy c);

	void Destroy_3(Candy** g, Candy** m);
	void Destroy_4(Candy** g, Candy** m, int a = -1, int b = -1, int c = -1, int d = -1);
	void Destroy_5(Candy** g, Candy** m, int a = -1, int b = -1, int c = -1, int d = -1);
	void Destroy_T(Candy** g, Candy** T);
	void Destroy_L(Candy** g, Candy** L);
};

