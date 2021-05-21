//#include <time.h>
#include <cmath> 
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Candy.h"


using namespace std;
using namespace sf;

//This function will be in Game class...
void SwapCandy(Candy c1, Candy c2,Candy*G[]) {
	swap(c1.col, c2.col);
	swap(c1.row, c2.row);

	G[c1.row][c1.col] = c1;
	G[c2.row][c2.col] = c2;
}

int main()
{
	RenderWindow window(VideoMode(1300, 740), "Candy Crush");
	window.setFramerateLimit(60);

	//Setting Background and Grey Texture

	Texture t1, t2, t3;
	t1.loadFromFile("assets/background.jpg");
	t2.loadFromFile("assets/grey.png");
	t3.loadFromFile("assets/score.png");

	Sprite background(t1), grey(t2), score_bar(t3);
	grey.setPosition(350.f, 70.f);
	score_bar.setPosition(10.f, 10.f);

	/*//Creating Candy Matrix
	Candy G[8][8];
	int travel_x = 0;
	int travel_y = 0;
	vector<char> list{ 'B', 'G', 'R', 'O' };

	srand(time(NULL));

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			G[i][j].setpos(360.f + travel_x, 80.f + travel_y);
			travel_x = travel_x + 73;

			int index = rand() % list.size();
			char value = list[index];

			G[i][j].setclr(value);
			G[i][j].setpath();
			G[i][j].setgridpos(i, j);
		}
		travel_x = 0;
		travel_y = travel_y + 73;
	}
	//End.
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << G[i][j].get_clr();
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << '(' << G[i][j].get_row() << ',' << G[i][j].get_col() << ')' << "**";
		}
		cout << endl;
	}
	//Swap Logic Goes Here ATM...

	int ts = 70; //tile size
	int x0 , y0 , x , y; int click = 0; Vector2i pos;
	bool isSwap = false;
	*/
	while (window.isOpen())
	{
		//Event Pooling
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					/*if (!isSwap)
					{
						click++;
						pos = Mouse::getPosition(window);
					}*/
				}
			}
		}
		//Mouvement
		/*if (click == 1)
		{
			x0 = (pos.x - 360) / ts ;
			y0 = (pos.y - 80) / ts ;
		}
		if (click == 2)
		{	
			x = (pos.x - 360) / ts ;
			y = (pos.y - 80) / ts ;
			click = 0;
			if (abs(x - x0) + abs(y - y0) == 1)
			{
				
				cout << "****before****" << endl;
				cout << G[y0][x0].get_x() << "****" << G[y0][x0].get_y() << endl;
				cout << G[y][x].get_x() << "****" << G[y][x].get_y() << endl;
				cout << G[y0][x0].get_clr() << "**" << G[y][x].get_clr() << endl;
				swap(G[y0][x0], G[y][x]);
				cout << "****after****" << endl;
				cout << G[y0][x0].get_x() << "****" << G[y0][x0].get_y() << endl;
				cout << G[y][x].get_x() << "****" << G[y][x].get_y() << endl;
				cout << G[y0][x0].get_clr() << "**" << G[y][x].get_clr() << endl;
				
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						cout << G[i][j].get_clr();
					}
					cout << endl;
				}
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						cout << '(' << G[i][j].get_row() << ',' << G[i][j].get_col() << ')' << "**";
					}
					cout << endl;
				}
				isSwap = false;//True This
				click = 0;
			}
			else click = 0;
		}*/
		//END.
		//Game Render
		window.clear();
		window.draw(background);
		window.draw(grey);
		//FIX FIRST
		//window.draw(score_bar);
		//Drawing All Matrix Candys
		/*for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Candy c = G[i][j];
				c.DrawReady();
				window.draw(c.sprite);
			}
		}*/
		//End.
		window.display();
	}

	return 0;
}