#pragma once
#include "Grill.h"
#include "Candy.h"
class Game
{
private :
	int* score_limite;
	int* nbclick_limit;
	int niveau;
	int* score;
	int* level;
	int* nbclick;
	int dim;
	Grill *grill;

public:
	Game(int);
	~Game();
	Grill* get_grill();
	int* get_score();
	int *get_level();
	int *get_nbclick();
	int* get_score_limite();
	int* get_nbclick_limit();
	int get_dim();
	void set_nbclick(int);
	void set_score(int);
	void set_niv(int);
	void set_level(int);
	void set_score_limite(int);
	void clear(Grill* ,int*,int,int ,int, sf::IntRect**, sf::RenderWindow&, int a = -1, int b = -1, int c = -1, int d = -1); // int* sc
	void Draw(Candy**, sf::IntRect**, sf::RenderWindow&,int,int);
	void Play(Grill*, int, int*,int*,int*,int*);
	void clear1(Grill* grill, int* sc, int , int , int , int , int );
};

