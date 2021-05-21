#include "Game.h"
#include "Grill.h"
#include <vector>

Game::Game(int n) {
	score = new int(0);
	score_limite = new int(10);
	nbclick = new int(2); 
	level = new int(1);
	niveau = n;
	//grill = new Grill(10);
	if (niveau == 0) {
		dim = 6;
		grill = new Grill(dim);
	}
	else if (niveau == 1) {
		dim = 8;
		grill = new Grill(dim);
	}
	else {
		dim = 10;
		grill = new Grill(dim);
	}
}
Game::~Game() {
	delete grill;
	delete score;
	delete nbclick;
	delete level;
	delete score_limite;
}
Grill *Game::get_grill() {
	return grill;
}

int* Game::get_score() {
	return score;
}
int Game::get_dim() {
	return dim;
}
int* Game::get_level() {
	return level;
}
int* Game::get_nbclick() {
	return nbclick;
}
int* Game::get_score_limite() {
	return score_limite;
}
int* Game::get_nbclick_limit() {
	return nbclick_limit;
}
void Game::set_nbclick(int a) {
	*nbclick = a;
}
void Game::set_score(int a) {
	*score = a;
}
void Game::set_niv(int a) {
	this->niveau = a;
}
void Game::set_level(int a) {
	*level = a;
}
void Game::set_score_limite(int a) {
	*score_limite = a;
}
void Game::Draw(Candy** g, sf::IntRect** rects, sf::RenderWindow& win,int tx , int ty ) {
	float stx, sty;
	if (dim == 10) {
		stx = 335.5;
		sty = 40;
	}
	else if (dim == 8) {
		stx = 410;
		sty = 110;
	}
	else if (dim == 6) {
		stx = 483;
		sty = 185;
	}
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			
			g[i][j].setSFMLimages();
			g[i][j].setSFMLpos(stx + tx, sty + ty); 
			

			sf::Vector2i position(stx + tx, sty + ty);  
			sf::Vector2i size(70, 70);
			sf::IntRect candyrect(position, size);
			rects[i][j] = candyrect;

			tx = tx + 73;
			win.draw(g[i][j].get_sp());
		}
		tx = 0;
		ty = ty + 73;
	}
}
void Game::clear(Grill* grill,int* sc, int dim, int tx, int ty, sf::IntRect** rects, sf::RenderWindow& win, int a, int b, int c, int d) {
	bool NDHIF = false;
	while (NDHIF == false) {
		NDHIF = true;
		bool NDHIF_5 = true;
		bool NDHIF_4 = true;
		bool NDHIF_L = true;
		bool NDHIF_T = true;
		// 4 & 5 
		Candy** mat5 = grill->verif5(dim, grill->get_g());
		grill->Destroy_5(grill->get_g(), mat5,a,b,c,d);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				if (grill->get_g()[i][j].get_clr() == 'X') {
					NDHIF_5 = false;
					NDHIF = false;
					*sc += 1;
					
				}
			}
		}
		if (NDHIF_5 == true) {
			Candy** mat4 = grill->verif4(dim, grill->get_g());
			grill->Destroy_4(grill->get_g(), mat4, a, b, c, d);

			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					if (grill->get_g()[i][j].get_clr() == 'X') {
						NDHIF_4 = false;
						NDHIF = false;
						*sc += 1;
					}
				}
			}
		}
		else {
			grill->translate(dim, grill->get_g());
			grill->generer(grill->get_g());
			continue;
		}
		//T & L
		if (NDHIF_4 == true) {
			Candy** mat30 = grill->verif3(dim, grill->get_g());
			Candy** matL = grill->verifL(dim, grill->get_g(), mat30);
			grill->Destroy_L(grill->get_g(), matL);
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					if (grill->get_g()[i][j].get_clr() == 'X') {
						NDHIF_L = false;
						NDHIF = false;
						*sc += 1;
					}
				}
			}
		}else {
			grill->translate(dim, grill->get_g());
			grill->generer(grill->get_g());
			continue;
		}
		if (NDHIF_L == true) {
			Candy** mat31 = grill->verif3(dim, grill->get_g());
			Candy** matT = grill->verifT(dim, grill->get_g(), mat31);
			grill->Destroy_T(grill->get_g(), matT);
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					if (grill->get_g()[i][j].get_clr() == 'X') {
						NDHIF_T = false;
						NDHIF = false;
						*sc += 1;
					}
				}
			}
		}
		else {
			grill->translate(dim, grill->get_g());
			grill->generer(grill->get_g());
			continue;
		}
		if (NDHIF_T == true) {
			Candy** mat32 = grill->verif3(dim, grill->get_g());
			grill->Destroy_3(grill->get_g(), mat32);
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					if (grill->get_g()[i][j].get_clr() == 'X') {
						NDHIF = false;
						*sc += 1;
					}
				}
			}
		}
		else {
			grill->translate(dim, grill->get_g());
			grill->generer(grill->get_g());
			continue;
		}

		if (NDHIF == false) {

			grill->translate(dim, grill->get_g());
			grill->generer(grill->get_g());
		}
		Draw(grill->get_g(), rects, win, tx, ty);
	}
}
//_________________Console Version (Changement Needed)______________
void Game::clear1(Grill* grill, int* sc, int dim, int a = 0, int b = 0, int c = 0, int d = 0) {
	bool NDHIF = false;
	while (NDHIF == false) {
		NDHIF = true;
		bool NDHIF_5 = true;
		bool NDHIF_4 = true;
		bool NDHIF_L = true;
		bool NDHIF_T = true;
		// 4 & 5 
		Candy** mat5 = grill->verif5(dim, grill->get_g());
		grill->Destroy_5(grill->get_g(), mat5, a, b, c, d);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				if (grill->get_g()[i][j].get_clr() == 'X') {
					NDHIF_5 = false;
					NDHIF = false;
					*sc += 1;

				}
			}
		}
		if (NDHIF_5 == true) {
			Candy** mat4 = grill->verif4(dim, grill->get_g());
			grill->Destroy_4(grill->get_g(), mat4, a, b, c, d);

			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					if (grill->get_g()[i][j].get_clr() == 'X') {
						NDHIF_4 = false;
						NDHIF = false;
						*sc += 1;
					}
				}
			}
		}
		else {
			grill->translate(dim, grill->get_g());
			grill->generer(grill->get_g());
			continue;
		}
		//T & L
		if (NDHIF_4 == true) {
			Candy** mat30 = grill->verif3(dim, grill->get_g());
			Candy** matL = grill->verifL(dim, grill->get_g(), mat30);
			grill->Destroy_L(grill->get_g(), matL);
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					if (grill->get_g()[i][j].get_clr() == 'X') {
						NDHIF_L = false;
						NDHIF = false;
						*sc += 1;
					}
				}
			}
		}
		else {
			grill->translate(dim, grill->get_g());
			grill->generer(grill->get_g());
			continue;
		}
		if (NDHIF_L == true) {
			Candy** mat31 = grill->verif3(dim, grill->get_g());
			Candy** matT = grill->verifT(dim, grill->get_g(), mat31);
			grill->Destroy_T(grill->get_g(), matT);
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					if (grill->get_g()[i][j].get_clr() == 'X') {
						NDHIF_T = false;
						NDHIF = false;
						*sc += 1;
					}
				}
			}
		}
		else {
			grill->translate(dim, grill->get_g());
			grill->generer(grill->get_g());
			continue;
		}
		if (NDHIF_T == true) {
			Candy** mat32 = grill->verif3(dim, grill->get_g());
			grill->Destroy_3(grill->get_g(), mat32);
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					if (grill->get_g()[i][j].get_clr() == 'X') {
						NDHIF = false;
						*sc += 1;
					}
				}
			}
		}
		else {
			grill->translate(dim, grill->get_g());
			grill->generer(grill->get_g());
			continue;
		}

		if (NDHIF == false) {

			grill->translate(dim, grill->get_g());
			grill->generer(grill->get_g());
		}
	}
}
void Game::Play(Grill*grill, int dim,int *score,int* nbclick,int* level,int* score_limite) {
	int x1, x2, y1, y2;
	bool pmt;
	grill->remplir(grill->get_g());
	clear1(grill,score ,dim); //, score
	grill->affiche(grill->get_g());
	cout << endl << endl;
	*score = 0;
	cout << "score = " << *score << endl;
	cout << "nbclick = " << *nbclick << endl;
	while(true) { //Game Loop
		if (*nbclick != 0 || *score < *score_limite) {
			cout << endl;
			cout << "*****************************" << endl;
			cout << "*******GAME STARTED!!!!!*******" << endl;
			cout << "*****************************" << endl;
			cout << endl;
			cout << "Donner x1 : ";
			cin >> x1;
			cout << endl << "Donner y1 : ";
			cin >> y1;
			cout << endl << "Donner x2 : ";
			cin >> x2;
			cout << endl << "Donner y2 : ";
			cin >> y2;
			pmt = grill->permut(x1, y1, x2, y2, grill->get_g());
			if (pmt == true) {
				*nbclick -= 1;
			}
			clear1(grill, score, dim); //, score
			grill->affiche(grill->get_g());
			cout << endl << endl;
			cout << "score = " << *score << endl << endl;
			cout << "nbclick = " << *nbclick << endl;
		}
		if (*score >= *score_limite) {
			*level += 1;
			cout << "***GOOD JOB! LEVEL UP!!***" << endl;
			cout << "Level " << *level << " : " << endl << endl;
			*score_limite += 40;
			*nbclick = 10;
			*score = 0;
			grill->remplir(grill->get_g());
			clear1(grill, score, dim);//, score
			grill->affiche(grill->get_g());
		}
		if (*nbclick == 0) {
			cout << "*****YOU LOST !!!*****" << endl << endl;
			break;
		}
	}
}