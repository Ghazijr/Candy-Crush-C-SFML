#include <iostream>
#include <ostream>
#include "Candy.h"
#include "Grill.h"
#include "Game.h"
#include <windows.h>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/window.hpp"
#include "SFML/audio.hpp"

using namespace sf;
using namespace std;

int main() {
	//____Console____(Uncomment Console and Comment SFML)
    /*Game jeux(0);
	jeux.Play(jeux.get_grill(), jeux.get_dim(), jeux.get_score(), jeux.get_nbclick(),
			  jeux.get_level(), jeux.get_score_limite());*/
	//_____SFML______
    //Remove Console
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    RenderWindow window(sf::VideoMode(700, 800), "Candy Crush!");
    
    //Setting Up Background and Greys.
    Texture bg,bgm, gr0,gr1,gr2;
    bg.loadFromFile("assets/back2.jpg");
    bgm.loadFromFile("assets/back.jpg");
    gr0.loadFromFile("assets/grey01.png");
    gr1.loadFromFile("assets/grey21.png");
    gr2.loadFromFile("assets/grey12.png");

    Sprite background(bg), grey, back(bgm);
    //MENU
    sf::Texture mn, pl, ex;
    mn.loadFromFile("assets/menu.png");
    pl.loadFromFile("assets/play.png");
    ex.loadFromFile("assets/quit.png");
    sf::Sprite menu(mn), play(pl), quit(ex);
    menu.setPosition(sf::Vector2f(100, 130));
    play.setPosition(sf::Vector2f(236, 650));
    quit.setPosition(sf::Vector2f(366, 650));
    menu.setColor(sf::Color(255, 255, 255, 230));

    sf::Texture hh, ee, nn, df;
    hh.loadFromFile("assets/hard.png");
    ee.loadFromFile("assets/easy.png");
    nn.loadFromFile("assets/normal.png");
    df.loadFromFile("assets/difficulty.png");
    sf::Sprite hard(hh), easy(ee), normal(nn), diff(df);
    diff.setPosition(sf::Vector2f(236, 280));
    easy.setPosition(sf::Vector2f(240, 365));
    normal.setPosition(sf::Vector2f(240, 445));
    hard.setPosition(sf::Vector2f(240, 525));

    //CLICKABLE MENU
    sf::Vector2i positionp(236, 650);
    sf::Vector2i sizep(100, 100);
    sf::IntRect playrect(positionp, sizep);
    sf::Vector2i positionex(336, 650);
    sf::Vector2i sizeex(100, 100);
    sf::IntRect quitrect(positionex, sizeex);

    sf::Vector2i positionez(240, 360);
    sf::Vector2i sizeez(220, 58);
    sf::IntRect easyrect(positionez, sizeez);
    sf::Vector2i positionnn(240, 440);
    sf::Vector2i sizenn(220, 58);
    sf::IntRect normalrect(positionnn, sizenn);
    sf::Vector2i positionhh(240, 520);
    sf::Vector2i sizehh(220, 58);
    sf::IntRect hardrect(positionhh, sizehh);

    //ICON
    sf::Image icon;
    icon.loadFromFile("assets/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Musique
    sf::Music music;
    if (!music.openFromFile("assets/song.ogg"))
        return -1; // erreur

    sf::Texture mt;
    mt.loadFromFile("assets/moff.png"); //ON
    sf::Texture mbtn;
    mbtn.loadFromFile("assets/mon.png"); //OFF
    sf::Sprite msb(mbtn);
    msb.setPosition(1300.f, 30.f);
    sf::Vector2i positionms(1300.f, 30.f);
    sf::Vector2i sizems(60, 60);
    sf::IntRect mbtnrect(positionms, sizems);

    //Home
    sf::Texture hm;
    hm.loadFromFile("assets/home.png");
    sf::Sprite home(hm);
    home.setPosition(1300.f, 170.f);
    sf::Vector2i positionhm(1300.f, 170.f);
    sf::Vector2i sizehm(60, 60);
    sf::IntRect homerect(positionhm, sizehm);

    //RESTART
    sf::Texture rs;
    rs.loadFromFile("assets/restart.png");
    sf::Sprite restart(rs);
    restart.setPosition(1300.f, 240.f);
    sf::Vector2i positionrs(1300.f, 240.f);
    sf::Vector2i sizers(60, 60);
    sf::IntRect restartrect(positionrs, sizers);


    
    //CANDY CRUSH
    sf::Texture cc;
    cc.loadFromFile("assets/Candy Crush.png");
    sf::Sprite candylabel(cc);

    //INFO
    sf::RectangleShape grb;
    grb.setFillColor(sf::Color(0, 0, 0,160));
    grb.setSize(sf::Vector2f(700, 800));

    sf::Texture exc, rlc;
    exc.loadFromFile("assets/exc.png");
    rlc.loadFromFile("assets/rules.png");
    sf::Sprite info(exc), cadre(rlc);
    info.setPosition(sf::Vector2f(40.f , 30.f));
    cadre.setPosition(sf::Vector2f(35, 15));

    sf::Vector2i positionif(40, 30);
    sf::Vector2i sizeif(60, 60);
    sf::IntRect inforect(positionif, sizeif);

    sf::Font fnt;
    fnt.loadFromFile("assets/Candice.ttf");
    sf::Text inftxt("          Comment Jouer ?\n  Realisez une combinaison de\ntrois pour eliminer les bonbons.\n     Pour avoir des Bonbons \n          speciaux combiner :", fnt);
    inftxt.setPosition(sf::Vector2f(125, 80));
    inftxt.setCharacterSize(36);
    inftxt.setLineSpacing(1.28);

    sf::Texture cb, nx;
    cb.loadFromFile("assets/comb.png");
    nx.loadFromFile("assets/next.png");
    sf::Sprite comb(cb), next(nx);
    comb.setPosition(sf::Vector2f(210, 280));
    next.setPosition(sf::Vector2f(245, 640));

    //BLOC
    sf::Texture bl;
    bl.loadFromFile("assets/bloc.png");
    sf::Sprite bloc(bl), bloc2(bl);
    bloc.setPosition(sf::Vector2f(56, 140));
    bloc.setScale(0.7, 0.7);
    bloc.setColor(sf::Color(255, 255, 255, 220));
    bloc2.setPosition(sf::Vector2f(56, 360));
    bloc2.setScale(0.7, 0.7);
    bloc2.setColor(sf::Color(255, 255, 255, 220));

    sf::Texture lv, lvup, gl, mvt, scr, gj, ls;
    lv.loadFromFile("assets/level.png");
    lvup.loadFromFile("assets/levelup.png");
    gl.loadFromFile("assets/goql.png");
    mvt.loadFromFile("assets/mouvement.png");
    scr.loadFromFile("assets/score.png");
    gj.loadFromFile("assets/goodjob.png");
    ls.loadFromFile("assets/lost.png");
    sf::Sprite level(lv), levelup(lvup), goal(gl), mouvement(mvt), scrr(scr), good(gj), lost(ls);
    goal.setPosition(sf::Vector2f(110, 190));
    scrr.setPosition(sf::Vector2f(110, 255));
    mouvement.setPosition(sf::Vector2f(75, 410));
    level.setPosition(sf::Vector2f(110, 470));
    good.setPosition(sf::Vector2f(66, 570));
    levelup.setPosition(sf::Vector2f(20, 640));
    lost.setPosition(sf::Vector2f(510, 330));
    
    //BLOC TEXTS
    sf::Text scoretext, leveltext, mvttext, goaltext;
    scoretext.setFont(fnt);
    leveltext.setFont(fnt);
    mvttext.setFont(fnt);
    goaltext.setFont(fnt);
    scoretext.setPosition(sf::Vector2f(153, 280));
    scoretext.setString("0");
    scoretext.setFillColor(sf::Color(226, 47, 68));
    goaltext.setPosition(sf::Vector2f(139, 220));
    goaltext.setString("10");
    goaltext.setFillColor(sf::Color(226, 47, 68));
    mvttext.setPosition(sf::Vector2f(145, 434));
    mvttext.setString("10");
    mvttext.setFillColor(sf::Color(226, 47, 68));
    leveltext.setPosition(sf::Vector2f(153, 496));
    leveltext.setString("1");
    leveltext.setFillColor(sf::Color(226, 47, 68));

    //LOST ANIMATION
    sf::RectangleShape lsrect;
    lsrect.setFillColor(sf::Color(0, 0, 0, 160));
    lsrect.setSize(sf::Vector2f(1400, 800));

    //SOUND ANIMATION
    sf::SoundBuffer nvbuff, winbuff, losebuff, mvbuff;
    nvbuff.loadFromFile("assets/nv.ogg");
    winbuff.loadFromFile("assets/win.ogg");
    losebuff.loadFromFile("assets/lose.ogg");
    mvbuff.loadFromFile("assets/destroy.ogg");
    sf::Sound news(nvbuff), wins(winbuff), loses(losebuff), moves(mvbuff);
     
    sf::Texture st;
    st.loadFromFile("assets/soundoff.png"); //ON
    sf::Texture sbtn;
    sbtn.loadFromFile("assets/soudon.png"); //OFF
    sf::Sprite sb(sbtn);
    sb.setPosition(1300.f, 100.f);

    sf::Vector2i positionso(1300.f, 100.f);
    sf::Vector2i sizeso(60, 60);
    sf::IntRect sbtnrect(positionms, sizems);

    //VARs..
    int get = 1;
    int click;
    int x1=-25, x2=-25, y1=-25, y2=-25;
    int  m = 0;
    int  f = 0;
    int travel_x = 0;
    int travel_y = 0;
    int niv = -1;
    int k = 0;
    Vector2i pos;

    //BUTTON INTERSECTION BOOLs
    bool musicbtn = 0;
    bool playbtn = 0;
    bool homebtn = 0;
    bool closebtn = 0;
    bool easybtn = 0;
    bool normalbtn = 0;
    bool hardbtn = 0;
    bool infobtn = 0;
    bool nextbtn = 0;
    bool restartbtn = 0;
    bool soundbtn = 0;

    //GAME VARs
    int sc= 0;
    int nbclick = 0;
    int goall = 10;
    int lvl = 1;
    int scp = 0;

    //BOOLS
    bool once = 1;
    bool win = 1;
    bool nv = 1;
    bool ken = 1;
    bool ok = 0;
    bool plays = 0;
    bool again = 0;
    bool startinc = 0;
    bool playlose = 1;
    bool isoff = 0;

    //WINDOW SIZE
    int wx = window.getSize().x;

    //MUSIC SETTINGS
    music.play();
    music.setVolume(15.f);
    music.setLoop(true);
    moves.setVolume(20.f);
    loses.setVolume(50.f);
    wins.setVolume(50.f);
    news.setVolume(50.f);

    //__Setting UP NEW Game..
    Game jeux0(0);
    Game jeux1(1);
    Game jeux2(2);
    Game* jeux = new Game(jeux2);
    
    Grill* G = jeux->get_grill();
    Candy** g = G->get_g();
    G->remplir(g);
    IntRect** rects = G->get_rects();
    int dim = jeux->get_dim();


    while (window.isOpen())
    {
        //Event Polling..
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.key.code == sf::Mouse::Left)
                {
                    //MOUSE POSITION
                    pos = sf::Mouse::getPosition(window);  // pos.x pos.y
                    //BUTTONS ANIMATION
                    normal.setColor(sf::Color(255, 255, 255, 255));
                    easy.setColor(sf::Color(255, 255, 255, 255));
                    hard.setColor(sf::Color(255, 255, 255, 255));
                    //MENU BUTTONS INTERSECTION (INFO FIXED)
                    if (ok == 0) {
                        infobtn = inforect.contains(pos);
                    }
                    if (infobtn == 0 && ken == 1) {
                        playbtn = playrect.contains(pos);
                        homebtn = homerect.contains(pos);
                        closebtn = quitrect.contains(pos);
                        easybtn = easyrect.contains(pos);
                        normalbtn = normalrect.contains(pos);
                        hardbtn = hardrect.contains(pos);
                        restartbtn = restartrect.contains(pos);
                    }
                    else if (infobtn == 1){
                        ken = 0;
                        ok = 1;
                        easybtn = 0;
                        normalbtn = 0;
                        hardbtn = 0;
                        normal.setColor(sf::Color(255, 255, 255, 255));
                        easy.setColor(sf::Color(255, 255, 255, 255));
                        hard.setColor(sf::Color(255, 255, 255, 255));
                        sf::Vector2i positionnx(245, 640);
                        sf::Vector2i sizenx(232, 74);
                        sf::IntRect nextrect(positionnx, sizenx);
                        nextbtn = nextrect.contains(pos);
                        if (nextbtn) {
                            ken = 1;
                            infobtn = 0;
                            ok = 0;
                        }
                    }
                    //Music Button Intersection
                    if (wx == 700)  {
                        sf::IntRect mbtnrect(sf::Vector2i(600.f, 30.f), sizems);
                        sf::IntRect sbtnrect(sf::Vector2i(600.f, 100.f), sizems);
                        musicbtn = mbtnrect.contains(pos);
                        soundbtn = sbtnrect.contains(pos);
                    }
                    if (wx == 1400) {
                        sf::IntRect mbtnrect(positionms, sizems);
                        sf::IntRect sbtnrect(sf::Vector2i(1300.f, 100.f), sizems);
                        musicbtn = mbtnrect.contains(pos);
                        soundbtn = sbtnrect.contains(pos);
                    }
                    if (restartbtn) {
                        //SHUFFLE GAME
                        G->remplir(g);
                        jeux->clear(G, jeux->get_score(), dim, travel_x, travel_y, rects, window);
                        jeux->set_score(sc);
                        get = 1;
                        plays = 1;
                    }
                    //MENU BUTTONS
                    if (wx == 700 && easybtn) {
                        jeux = &jeux2;
                        grey.setPosition(sf::Vector2f(337.5, 37.5));    
                        grey.setTexture(gr0, true);

                        easy.setScale(sf::Vector2f(1.1, 1.1));
                        easy.setPosition(sf::Vector2f(229, 363));
                        normal.setColor(sf::Color(255, 255, 255, 130));
                        hard.setColor(sf::Color(255, 255, 255, 130));
                        easy.setColor(sf::Color(255, 255, 255, 255));
                        niv = 2;
                        normalbtn = 0;
                        hardbtn = 0;                        
                    }
                    else if (wx == 700 && normalbtn) {
                        jeux = &jeux1;
                        grey.setPosition(sf::Vector2f(405, 104));
                        grey.setTexture(gr1, true);

                        normal.setScale(sf::Vector2f(1.1, 1.1));
                        normal.setPosition(sf::Vector2f(229, 443));
                        easy.setColor(sf::Color(255, 255, 255, 130));
                        hard.setColor(sf::Color(255, 255, 255, 130));
                        normal.setColor(sf::Color(255, 255, 255, 255));
                        niv = 1;
                        easybtn = 0;
                        hardbtn = 0;                        
                    }
                    else if (wx == 700 && hardbtn) {
                        jeux = &jeux0;
                        grey.setPosition(sf::Vector2f(478, 179));
                        grey.setTexture(gr2, true);
                        hard.setScale(sf::Vector2f(1.1, 1.1));
                        hard.setPosition(sf::Vector2f(229, 523));
                        normal.setColor(sf::Color(255, 255, 255, 130));
                        easy.setColor(sf::Color(255, 255, 255, 130));
                        hard.setColor(sf::Color(255, 255, 255, 255));
                        niv = 0;
                        easybtn = 0;
                        normalbtn = 0;
                    }
                    if (easybtn == 0) {
                        easy.setScale(sf::Vector2f(1, 1));
                        easy.setPosition(sf::Vector2f(240, 365));        
                    }
                    if (normalbtn == 0) {
                        normal.setScale(sf::Vector2f(1, 1));
                        normal.setPosition(sf::Vector2f(240, 445));
                    }
                    if (hardbtn == 0) {
                        hard.setScale(sf::Vector2f(1, 1));
                        hard.setPosition(sf::Vector2f(240, 525));
                    }
                    //Window Switch From Main Menu To Game
                    if ((win == true && playbtn == 1)|| again) {
                        if (isoff == 0) {
                            news.play();
                        }
                        window.create(sf::VideoMode(1400, 800), "Candy Crush"); 
                        wx = window.getSize().x;
                        G->remplir(g);
                        jeux->clear(G, jeux->get_score(), dim, travel_x, travel_y, rects, window);
                        plays = 1;
                        get = 1; 
                        once = true;
                        win = false;
                        nv = 1;
                    }
                    //Window Switch From Game To Main Menu
                    else if (homebtn == 1 && wx == 1400){
                        window.create(sf::VideoMode(700, 800), "Candy Crush");
                        wx = window.getSize().x;
                        win = true;
                    }
                    //MUSIC MOUSE
                    else if (musicbtn == 1) {
                        if (m % 2 == 0) {
                            music.pause();
                            mt.setSmooth(true);
                            msb.setTexture(mt);

                        }
                        if (m % 2 != 0) {
                            music.play();
                            msb.setTexture(mbtn);
                        }
                    }
                    //MUSIC MOUSE
                    else if (soundbtn == 1) {
                        if (f % 2 == 0) {
                            isoff = true;
                            sb.setTexture(st);

                        }
                        if (m % 2 != 0) {
                            isoff = false;
                            sb.setTexture(sbtn);
                        }
                    }
                    //CANDY MVT
                    else if (plays == 1) {
                        if (get == 1) {
                            for (int i = 0; i < dim; i++) {
                                for (int j = 0; j < dim; j++) {
                                    click = rects[i][j].contains(pos);
                                    if (click == 1) {
                                        x1 = i;
                                        y1 = j;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            get++;
                        }
                        else if (get == 2) {
                            for (int i = 0; i < dim; i++) {
                                for (int j = 0; j < dim; j++) {
                                    click = rects[i][j].contains(pos);
                                    if (click == 1) {
                                        x2 = i;
                                        y2 = j;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            get++;
                        }      
                    }
                    m++;
                    f++;
                }
            }
            //MUSIC BUTTON
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::M) {
                    if  (m % 2 == 0) {
                        music.pause();
                        msb.setTexture(mt);
                        
                    }if (m % 2 != 0) {
                        music.play();
                        msb.setTexture(mbtn);
                    }
                    m++;
                } 
            }
        }
        //Game Rendering..
        if (wx == 1400) {
            if (nv == 1 && (easybtn || normalbtn || hardbtn)) {
                Grill* G = jeux->get_grill();
                Candy** g = G->get_g();
                G->remplir(g);
                IntRect** rects = G->get_rects();
                int dim = jeux->get_dim();
                nv = 0;
            }
            //Drawing..
            candylabel.setPosition(10, 40);
            msb.setPosition(1300.f, 30.f);
            sb.setPosition(1300.f, 100.f);
            window.clear();
            window.draw(background);
            window.draw(grey);
            window.draw(bloc);
            window.draw(bloc2);
            window.draw(goal);
            window.draw(level);
            window.draw(scrr);
            window.draw(mouvement);
            window.draw(scoretext);
            window.draw(goaltext);
            window.draw(mvttext);
            window.draw(leveltext);
            //UPDATE
            jeux->clear(G, jeux->get_score(), dim, travel_x, travel_y, rects, window);
            if (once == 1) {
                //INITIALISATION
                jeux->set_score(0);
                jeux->set_nbclick(10);
                jeux->set_level(1);
                jeux->set_score_limite(10);
                mvttext.setString(std::to_string(*jeux->get_nbclick()));
                leveltext.setString(std::to_string(*jeux->get_level()));
                scoretext.setString(std::to_string(*jeux->get_score()));
                goaltext.setString(std::to_string(*jeux->get_score_limite()));
                once = 0;
            }
            //PERMUTE UPDATE
            nbclick = *jeux->get_nbclick();
            goall = *jeux->get_score_limite();
            lvl = *jeux->get_level();
            if (get == 3) {
                scp = *jeux->get_score();
                G->permut(x1, y1, x2, y2, g);
                jeux->set_nbclick(*jeux->get_nbclick() - 1);
                jeux->clear(G, jeux->get_score(), dim, travel_x, travel_y, rects, window, x1, y1, x2, y2);
                //UPDATE SCORE
                sc = *jeux->get_score();
                scoretext.setString(std::to_string(sc));
                //UPDATE SCORE POS
                if (sc > 10) {
                    scoretext.setPosition(sf::Vector2f(145, 280));
                    if (sc > 100) {
                        scoretext.setPosition(sf::Vector2f(139, 280));
                        if (sc > 1000) {
                            scoretext.setPosition(sf::Vector2f(130, 280));
                            if (sc > 10000) {
                                scoretext.setPosition(sf::Vector2f(121, 280));
                            }
                        }
                    }
                }
                //CHECK IF PERMUTE POSSIBLE
                if (scp == *jeux->get_score()) {
                    G->permut(x1, y1, x2, y2, g);
                    jeux->set_nbclick(*jeux->get_nbclick() + 1);
                }
                if (scp != *jeux->get_score() && isoff == 0) {
                    moves.play();
                }
                //UPDATE  NBCLICK
                nbclick = *jeux->get_nbclick();
                mvttext.setString(std::to_string(nbclick));
                if (nbclick < 10) {
                    mvttext.setPosition(sf::Vector2f(153, 434));
                }
                get = 1;
            }
            // LEVEL UP OR LOSE
            if (nbclick == 0 && sc < goall ) {
                get = 0;
                window.draw(lsrect);
                window.draw(lost);
                if (playlose && isoff == 0) {
                    loses.play();
                    playlose = 0;
                }
            }
            else if (sc >= goall) {
                goall = goall*2;
                lvl = lvl + 1;
                jeux->set_level(lvl);
                jeux->set_score_limite(goall);
                jeux->set_nbclick(10);
                goaltext.setString(std::to_string(goall));
                leveltext.setString(std::to_string(lvl));
                mvttext.setString(std::to_string(10));
                startinc = true;
                if (isoff == 0) {
                    wins.play();
                }
            }
            if (k < 60 && startinc == true) {
                window.draw(good);
                window.draw(levelup);
                k++;
                if (k == 59) {
                    startinc = false;
                    k = 0;
                }
            }
            window.draw(candylabel);
            window.draw(msb);
            window.draw(sb);
            window.draw(home);
            window.draw(restart);
            window.display();
        }
        else if (wx == 700) {
            //DRAWING
            candylabel.setPosition(180, 30);
            msb.setPosition(600.f, 30.f);
            sb.setPosition(600.f, 100.f);
            window.clear();
            window.draw(back);
            window.draw(menu);
            window.draw(play);
            window.draw(quit);
            window.draw(candylabel);
            window.draw(msb);
            window.draw(sb);
            window.draw(diff);
            window.draw(easy);
            window.draw(normal);
            window.draw(hard);
            window.draw(info);
            //CLOSE
            if (closebtn == 1) {
                window.close();
            }
            //INFO
            if (infobtn) {
                window.draw(grb);
                window.draw(cadre);
                window.draw(comb);
                window.draw(inftxt);
                window.draw(next);
            }
            window.display();
        }
    }
}