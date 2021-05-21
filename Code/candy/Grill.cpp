#include "Grill.h"
#include "Candy.h"
#include <vector>
#include <list>
#include <time.h>
#include <iostream>
#include <windows.h>

using namespace std;

Grill::Grill(int a) {
	dim = a;
	g = new Candy * [dim];
	int i;	
	for (i = 0; i < dim; i++) {
		g[i] = new Candy[dim];

	}
	rects = new sf::IntRect * [dim];
	for (int s = 0; s < dim; s++)
	{
		rects[s] = new sf::IntRect[dim];
	}
}
Grill::~Grill() {
	delete[] g;
}

Candy** Grill::get_g() {
	return g;
}
sf::IntRect** Grill::get_rects() {
	return rects;
}
void Grill::set_g(Candy** m) {
	g = m;
}

void Grill::remplir(Candy **g) {
	vector<char> list{ 'B', 'G', 'R', 'O', 'Y','P' };

	srand((unsigned int)time(0));

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			
			int index = rand() % list.size();
			char value = list[index];
		
			g[i][j].setclr(value);
			g[i][j].setgridpos(i, j);
		}
	}
}
void Grill::affiche(Candy** g) {
	cout << "  ";
	for (int k = 0; k < dim; k++) {
		if (k > 10) {
			cout << "__" << k;
		}
		else {
			cout << "___" << k;
		}
	}
	cout << endl;
	for (int i = 0; i < dim; i++) {
		if (i > 9) {
			cout << i << " | ";
		}
		else {
			cout << i << "  | ";
		}
		for (int j = 0; j < dim; j++) {
			if (g[i][j].get_explosive()) {
				cout << g[i][j].get_clr()<<"E" << "  ";
			}
			else if (g[i][j].get_raiure() == 'v') {
				cout << g[i][j].get_clr()<<"V" << "  ";
			}
			else if (g[i][j].get_raiure() == 'h') {
				cout << g[i][j].get_clr()<<"H" << "  ";
			}
			else {
				cout << g[i][j].get_clr() << "   ";
			}
		}
		cout << endl;
	}
}
bool Grill::permut(int x1, int y1, int x2, int y2, Candy** g) {
	if ((abs(x1 - x2) == 1 && abs(y1 - y2) == 0) || (abs(x1 - x2) == 0 && abs(y1 - y2) == 1)){//&& (g[x1][y1].get_clr() != g[x2][y2].get_clr())) {
		if (g[x1][y1].get_clr() == 'M') {
			Multi(g, g[x2][y2]);
			g[x1][y1].setclr('X');
			translate(dim, g);
			generer(g);
		}
		else if (g[x2][y2].get_clr() == 'M') {
			Multi(g, g[x1][y1]);
			g[x2][y2].setclr('X');
			translate(dim, g);
			generer(g);
		}
		Candy aux;
		aux = g[x1][y1];
		g[x1][y1] = g[x2][y2];
		g[x2][y2] = aux;
		g[x1][y1].setgridpos(x1, y1);
		g[x2][y2].setgridpos(x2, y2);
		return true;
	}
	else {
		cout<< "vous ne pouvez pas permuter deux elements ne sont adjacents " << endl;
		return false;
	}
}
void Grill::translate(int dim, Candy** g) {
	
	for (int k = 0; k < dim; k++) {
		for (int i = dim - 1; i > 0; i--) {
			for (int j = dim - 1; j >= 0; j--) {
				if (g[i][j].get_clr()=='X') {
					Candy aux;
					aux = g[i][j];
					g[i][j] = g[i-1][j];
					g[i - 1][j] = aux;
					g[i][j].setgridpos(i, j);
					g[i - 1][j].setgridpos(i-1, j);
				}

			}
		}
	}
}
void Grill::change(int i, int j, Candy c, Candy** g) {
	g[i][j] = c;

}
void Grill::generer(Candy** g) {
	vector<char> list{ 'B', 'G', 'R', 'O', 'Y','P',};
	srand((unsigned int)time(0));
	Candy c;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (g[i][j] == c) {
				int index = rand() % list.size();
				char value = list[index];
				g[i][j].setclr(value);
				g[i][j].setgridpos(i, j);
			}
		}
	}
}

Candy** Grill::verif3(int dim, Candy** g) {
	Candy** m;
	m = new Candy * [dim*4];
	int s = 0;
	for (int i = 0; i < dim*4; i++) {
		m[i] = new Candy[3];
	}
	Candy c;
	for (int i = 0; i < dim; i++) {
		Candy c1, c2, c3;
		int j = 0;
		for(int j=0;j<dim;j++){
			c3 = g[i][j];
			if (c1 == c2 && c2 == c3) {
				m[s][0] = c1;
				m[s][1] = c2;
				m[s][2] = c3;
				c1 = c;
				c2 = c;
				c3 = c;
				s+=1;
			}
			else {
				c1 = c2;
				c2 = c3;
			}
		}
	}

	for (int j = 0; j < dim; j++) {
		Candy c1, c2, c3;
		for (int i= 0; i < dim; i++) {
			c3 = g[i][j];
			if (c1 == c2 && c2 == c3) {
				m[s][0] = c1;
				m[s][1] = c2;
				m[s][2] = c3;
				c1 = c;
				c2 = c;
				c3 = c;
				s += 1;
			}
			else {
				c1 = c2;
				c2 = c3;
			}

		}
	}
	return m;

}
Candy** Grill::verif4(int dim, Candy** g) {
	Candy** m;
	m = new Candy * [dim * 2];
	int s = 0;
	for (int i = 0; i < dim * 2; i++) {
		m[i] = new Candy[4];
	}
	Candy c;
	for (int i = 0; i < dim; i++) {
		Candy c1, c2, c3, c4 ;
		
		for (int j = 0; j < dim; j++) {

			 c4 = g[i][j];
			if ((c1 == c2 && c2 == c3) && (c3 == c4) ){
				m[s][0] = c1;
				m[s][1] = c2;
				m[s][2] = c3;
				m[s][3] = c4;
				c1 = c;
				c2 = c;
				c3 = c;
				c4 = c;
				s += 1;
			}
			else {
				c1 = c2;
				c2 = c3;
				c3 = c4;
			}
		}
	}

	for (int j = 0; j < dim; j++) {
		Candy c1, c2, c3, c4;
		for (int i = 0; i < dim; i++) {
			 c4 = g[i][j];
			if (c1 == c2 && c2 == c3 && c3 == c4 ) {
				m[s][0] = c1;
				m[s][1] = c2;
				m[s][2] = c3;
				m[s][3] = c4;
				c1 = c;
				c2 = c;
				c3 = c;
				c4 = c;
				s += 1;
			}
			else {
				c1 = c2;
				c2 = c3;
				c3 = c4;
			}
		}
	}
	return m;

}
Candy** Grill::verif5(int dim, Candy** g) {
	Candy** m;
	m = new Candy * [dim ];
	int s = 0;
	for (int i = 0; i < dim; i++) {
		m[i] = new Candy[5];
	}
	Candy c;
	for (int i = 0; i < dim; i++) {
		Candy c1, c2, c3, c4 , c5;

		for (int j = 0; j < dim; j++) {

			 c5 = g[i][j];
			if ((c1 == c2 && c2 == c3) && (c3 == c4 && c4 
				== c5 )) {
				m[s][0] = c1;
				m[s][1] = c2;
				m[s][2] = c3;
				m[s][3] = c4;
				m[s][4] = c5;
				
				c1 = c;
				c2 = c;
				c3 = c;
				c4 = c;
				c5 = c;

				s += 1;
			}
			else {
				c1 = c2;
				c2 = c3;
				c3 = c4;
				c4 = c5;
			}
		}
	}

	for (int j = 0; j < dim; j++) {
		Candy c1, c2, c3, c4 ,c5;
		for (int i = 0; i < dim; i++) {
			c5 = g[i][j];
			if (c1 == c2 && c2 == c3 && c3 == c4 && c4==c5 ) {

				m[s][0] = c1;
				m[s][1] = c2;
				m[s][2] = c3;
				m[s][3] = c4;
				m[s][4] = c5;
				c1 = c;
				c2 = c;
				c3 = c;
				c4 = c;
				c5 = c;
				s += 1;
			}
			else {
				c1 = c2;
				c2 = c3;
				c3 = c4;
				c4 = c5;
			}
		}
	}
	return m;

}
Candy** Grill::verifL(int dim, Candy** g, Candy** m) {

	int s = 0;
	Candy** h;
	h = new Candy * [dim ];

	for (int i = 0; i < dim; i++) {
		h[i] = new Candy[5];
	}
	Candy c;
	for (int i = 0; i < dim; i++) {
		for (int j = i+1; j < dim; j++) {
			if (m[i][0].get_clr() == m[j][0].get_clr() && m[i][0].get_clr() != 'X') {
				if (m[i][0] == m[j][0]&& m[i][0].get_grid_x() == m[j][0].get_grid_x() && m[i][0].get_grid_y() == m[j][0].get_grid_y()) {
					h[s][0] = m[j][2];
					h[s][1] = m[j][1];
					h[s][2] = m[j][0];
					h[s][3] = m[i][1];
					h[s][4] = m[i][2];
					m[j][2] = c;
					m[j][1] = c;
					m[j][0] = c;
					m[i][0] = c;
					m[i][1] = c;
					m[i][2] = c;
					s+=1;
				}
				 if (m[i][0] == m[j][2] && m[i][0].get_grid_x() == m[j][2].get_grid_x() && m[i][0].get_grid_y() == m[j][2].get_grid_y()) {
					h[s][0] =  m[j][0];
					h[s][1] =  m[j][1];
					h[s][2] =  m[i][0];
					h[s][3] =  m[i][1];
					h[s][4] =  m[i][2];
					s+=1;
					m[j][2] = c;
					m[j][1] = c;
					m[j][0] = c;
					m[i][0] = c;
					m[i][1] = c;
					m[i][2] = c;
				}
				if (m[i][2] == m[j][2]  && m[i][2].get_grid_x() == m[j][2].get_grid_x() && m[i][2].get_grid_y() == m[j][2].get_grid_y()) {
					h[s][0] =  m[j][0]; 
					h[s][1] =  m[j][1];
					h[s][2] =  m[i][2];
					h[s][3] =  m[i][1];
					h[s][4] =  m[i][0];
					s++;
					m[j][2] = c;
					m[j][1] = c;
					m[j][0] = c;
					m[i][0] = c;
					m[i][1] = c;
					m[i][2] = c;
				}
				if (m[i][2] == m[j][0] && m[i][2].get_grid_x() == m[j][0].get_grid_x() && m[i][2].get_grid_y() == m[j][0].get_grid_y()) {
					h[s][0] = m[j][2];
					h[s][1] = m[j][1];
					h[s][2] = m[i][2];
					h[s][3] = m[i][0];
					h[s][4] = m[i][1];
					s+=1;
					m[j][2] = c;
					m[j][1] = c;
					m[j][0] = c;
					m[i][0] = c;
					m[i][1] = c;
					m[i][2] = c;
				}
			}
		}
	}
	return h;

}
Candy** Grill::verifT(int dim, Candy** g, Candy** m) {

	int s = 0;
	Candy** h;
	h = new Candy * [dim];

	for (int i = 0; i < dim; i++) {
		h[i] = new Candy[5];
	}
	Candy c;
	for (int i = 0; i < dim; i++) {
		for (int j = i + 1; j < dim; j++) {
			if (m[i][0].get_clr() == m[j][0].get_clr() && m[i][0].get_clr() != 'X') {
				if (m[i][1] == m[j][0] && m[i][1].get_grid_x() == m[j][0].get_grid_x() && m[i][1].get_grid_y() == m[j][0].get_grid_y()) {
					h[s][0] = m[j][2];
					h[s][1] = m[j][1];
					h[s][2] = m[j][0];
					h[s][3] = m[i][0];
					h[s][4] = m[i][2];
					m[j][2] = c;
					m[j][1] = c;
					m[j][0] = c;
					m[i][0] = c;
					m[i][1] = c;
					m[i][2] = c;
					s++;
				}
				if (m[i][1] == m[j][2] && m[i][1].get_grid_x() == m[j][2].get_grid_x() && m[i][1].get_grid_y() == m[j][2].get_grid_y()) {
					h[s][0] = m[j][0];
					h[s][1] = m[j][1];
					h[s][2] = m[i][1];
					h[s][3] = m[i][0];
					h[s][4] = m[i][2];
					s++;
					m[j][2] = c;
					m[j][1] = c;
					m[j][0] = c;
					m[i][0] = c;
					m[i][1] = c;
					m[i][2] = c;
				}
				if (m[i][0] == m[j][1] && m[i][0].get_grid_x() == m[j][1].get_grid_x() && m[i][0].get_grid_y() == m[j][1].get_grid_y()) {
					h[s][0] = m[j][0];
					h[s][1] = m[j][2];
					h[s][2] = m[i][0];
					h[s][3] = m[i][1];
					h[s][4] = m[i][2];
					s++;
					m[j][2] = c;
					m[j][1] = c;
					m[j][0] = c;
					m[i][0] = c;
					m[i][1] = c;
					m[i][2] = c;
				}
				if (m[i][2] == m[j][1] && m[i][2].get_grid_x() == m[j][1].get_grid_x() && m[i][2].get_grid_y() == m[j][1].get_grid_y()) {
					h[s][0] = m[j][2];
					h[s][1] = m[j][0];
					h[s][2] = m[i][2];
					h[s][3] = m[i][1];
					h[s][4] = m[i][0];
					s++;
					m[j][2] = c;
					m[j][1] = c;
					m[j][0] = c;
					m[i][0] = c;
					m[i][1] = c;
					m[i][2] = c;
				}
			}
		}
	}
	return h;

}

void Grill::Explosif(Candy** g, Candy c) {
	int x, y;
	x = c.get_grid_x();
	y = c.get_grid_y();
	if (x - 1 >= 0 && y - 1 >= 0 && g[x - 1][y - 1].get_clr()!='M') {
		g[x - 1][y - 1].setclr('X');
	}
	if (y - 1 >= 0 && g[x ][y - 1].get_clr() != 'M') {
		g[x][y - 1].setclr('X');
	}
	if (x + 1 != dim && y - 1 >= 0 && g[x + 1][y - 1].get_clr() != 'M') {
		g[x + 1][y - 1].setclr('X');
	}
	if (x - 1 >= 0 && g[x - 1][y].get_clr() != 'M') {
		g[x - 1][y].setclr('X');
	}

	g[x][y].setclr('X');

	if (x + 1 != dim && g[x + 1][y].get_clr() != 'M') {
		g[x + 1][y].setclr('X');
	}
	if (x - 1 >= 0 && y + 1 != 0 && g[x - 1][y + 1].get_clr() != 'M') {
		g[x - 1][y + 1].setclr('X');
	}
	if (y + 1 != dim && g[x][y + 1].get_clr() != 'M') {
		g[x][y + 1].setclr('X');
	}
	if (x + 1 != dim && y + 1 != dim && g[x + 1][y + 1].get_clr() != 'M') {
		g[x + 1][y + 1].setclr('X');
	}



}
void Grill::Raiure(Candy** g, Candy c) {
	int x, y;
	x = c.get_grid_x();
	y = c.get_grid_y();
	if (c.get_raiure() == 'h') {
		for (int k = 0; k < dim; k++) {
			if (g[x][k].get_clr() != 'M') {
				g[x][k].setclr('X');
			}
		}
	}
	if (c.get_raiure() == 'v') {
		for (int k = 0; k < dim; k++) {
			if (g[k][y].get_clr() != 'M') {
				g[k][y].setclr('X');
			}
		}
	}
}

void Grill::Multi(Candy** g, Candy c) {
	int x, y;
	x = c.get_grid_x();
	y = c.get_grid_y();
	for (int k = 0; k < dim; k++) {
		for (int l = 0; l < dim; l++) {
			if (g[k][l] == c) {
				g[k][l].setclr('X');
			}
		}
	}
}

void Grill::Destroy_3(Candy** g, Candy** m) {
	int x, y;
	for (int i = 0; i < dim * 4; i++) {
		for (int j = 0; j < 3; j++) {
			x = m[i][j].get_grid_x();
			y = m[i][j].get_grid_y();
			if (x != -1 && y != -1) {
				if (m[i][j].get_raiure() != 'n') {
					Raiure(g, m[i][j]);
				}
				if (m[i][j].get_explosive() == true) {
					Explosif(g, m[i][j]);
				}
				if (m[i][j].get_clr() != 'M') {
					g[x][y].setclr('X');
				}
			}
		}
	}
}
void Grill::Destroy_4(Candy** g, Candy** m, int a, int b, int c, int d) {
	int x, y, j,k,l;
	for (int i = 0; i < dim * 2; i++) {
		for (j = 0; j < 4; j++) {
			x = m[i][j].get_grid_x();
			y = m[i][j].get_grid_y();
			if (x != -1 && y != -1) {
				if (m[i][j].get_raiure() != 'n') {
					Raiure(g, m[i][j]);
				}
				if (m[i][j].get_explosive() == true) {
					Explosif(g, m[i][j]);
				}
				if (m[i][j].get_clr() != 'M') {
					g[x][y].setclr('X');
				}	
			}
		}
		if (a == -1 && b == -1 && c == -1 && d == -1) {
			x = m[i][j-1].get_grid_x();
			y = m[i][j-1].get_grid_y();
			k = m[i][j - 2].get_grid_x();
			l = m[i][j - 2].get_grid_y();
			if (x != -1 && y != -1 && k != -1 && l != -1) {
				if (x == k) {
					Candy c(k, l, m[i][j-1].get_clr(), 'h', false, false);
					g[k][l] = c;
				}
				if (y == l) {
					Candy c(k, l, m[i][j-1].get_clr(), 'v', false, false);
					g[k][l] = c;
				}
			}
		}
	}
	if (a != -1 && b != -1 && c != -1 && d != -1) {
		for (int i = 0; i < dim * 2; i++) {
			for (int j = 0; j < 4; j++) {
				x = m[i][j].get_grid_x();
				y = m[i][j].get_grid_y();
				if (x != -1 && y != -1) {
					if (x == a && y == b) {
						if (a == c) {
							Candy l(a,b, m[i][j].get_clr(), 'h', false, false);
							g[x][y] = l;
						}
						if (b == d) {
							Candy l(a, b, m[i][j].get_clr(), 'v', false, false);
							g[x][y] = l;
						}
					}
					if (x == c && y == d) {
						if (a == c) {
							Candy c(c,d, m[i][j].get_clr(), 'h', false, false);
							g[x][y] = c;
						}
						if (b == d) {
							Candy c(c, d, m[i][j].get_clr(), 'v', false, false);
							g[x][y] = c;
						}
					}
						
				}
			}
		}
	}
}
void Grill::Destroy_5(Candy * *g, Candy * *m, int a, int b, int c, int d) {
	int x, y, j, k, l;
	for (int i = 0; i < dim; i++) {
		for (j = 0; j < 5; j++) {
			x = m[i][j].get_grid_x();
			y = m[i][j].get_grid_y();
			if (x != -1 && y != -1) {
				if (m[i][j].get_raiure() != 'n') {
					Raiure(g, m[i][j]);
				}
				if (m[i][j].get_explosive() == true) {
					Explosif(g, m[i][j]);
				}
				if (m[i][j].get_clr() != 'M') {
					g[x][y].setclr('X');
				}
			}
		}
		if (a == -1 && b == -1 && c == -1 && d == -1) {
			k = m[i][j - 3].get_grid_x();
			l = m[i][j - 3].get_grid_y();
			if (k != -1 && l != -1) {
				Candy c(k, l, 'M', 'n', false, true);
				g[k][l] = c;
			}
		}
	}
	if (a != -1 && b != -1 && c != -1 && d != -1) {
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < 5; j++) {
				x = m[i][j].get_grid_x();
				y = m[i][j].get_grid_y();
				if (x != -1 && y != -1) {
					if (x == a && y == b) {
						Candy c(a, b, 'M', 'n', false, true);
						g[x][y] = c;
					}
					if (x == c && y == d) {
						Candy c(c, d, 'M', 'n', false, true);
						g[x][y] = c;
					}
				}
			}
		}
	}
}
void Grill::Destroy_T(Candy** g, Candy** T) {
	int x, y, j, k, l;
	for (int i = 0; i < dim; i++) {
		for (j = 0; j < 5; j++) {
			x = T[i][j].get_grid_x();
			y = T[i][j].get_grid_y();
			if (x != -1 && y != -1) {
				if (T[i][j].get_raiure() != 'n') {
					Raiure(g, T[i][j]);
				}
				if (T[i][j].get_explosive() == true) {
					Explosif(g, T[i][j]);
					
				}

				if (T[i][j].get_clr() != 'M') {
					g[x][y].setclr('X');
				}
				
			}
		}		
		k = T[i][j-3].get_grid_x();
		l = T[i][j-3].get_grid_y();
	
		if (k != -1 && l != -1) {
			Candy c(k, l, T[i][j-1].get_clr(), 'n', true, false);
			g[k][l] = c;
		}
	}
}
void Grill::Destroy_L(Candy** g, Candy** L){
	int x, y, j, k, l;
	for (int i = 0; i < dim; i++) {
		for (j = 0; j < 5; j++) {
			x = L[i][j].get_grid_x();
			y = L[i][j].get_grid_y();
			if (x != -1 && y != -1) {
				if (L[i][j].get_raiure() != 'n') {
					Raiure(g, L[i][j]);
				}
				if (L[i][j].get_explosive() == true) {
					Explosif(g,L[i][j]);
				}
				if (L[i][j].get_clr() != 'M') {
					g[x][y].setclr('X');
				}
			}
		}
		k = L[i][j - 3].get_grid_x();
		l =	L[i][j - 3].get_grid_y();
		if (k != -1 && l != -1) {
			Candy c(k, l, L[i][j-1].get_clr(), 'n', true, false);
			g[k][l] = c;
		}
	}
}