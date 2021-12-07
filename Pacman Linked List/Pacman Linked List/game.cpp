#include "game.hpp"
#include <windows.h>

menuGame *BuildGame(int ukuran,int l,int p)
{
    menuGame *game = (menuGame*)malloc(sizeof(menuGame*));
    game->ukuranl = l;
    game->ukuranp = p;
    game->ukuran = ukuran;
    game->windowl = ukuran * l;
    game->windowp = ukuran * p;

    return game;
}

menuGame run(menuGame *g)
{
    initwindow(g->windowl,g->windowp,"PACMAN");
    Rendering_Menu("Tampilan");     // gamuncul pas ditampilin
    menuUtama();
    closegraph();
}

void menuUtama()
{
    int x,y,level;
    List map;
    CreateList(&map);
    Sprites *gambar = BuildSprites(25);
    POINT CursorPosition;

    Rendering_Menu("Tampilan Awal");
    while(1)
    {
        menu:
        Rendering_Menu("Halaman Utama");
        //getmouseclick(WM_LBUTTONDOWN,x,y);
        GetCursorPos(&CursorPosition);
    	x=CursorPosition.x;
    	y=CursorPosition.y;
        if(GetAsyncKeyState(VK_LBUTTON))
        {
        // Start Game
            if((x < 600) && (x > 350) && (y < 425) && (y > 325))
            {
                Rendering_Menu("Menu Utama");
                //getmouseclick(WM_LBUTTONDOWN,x,y);
                while(1)
                {
                    GetCursorPos(&CursorPosition);
                    x=CursorPosition.x;
                    y=CursorPosition.y;
                    if(GetAsyncKeyState(VK_LBUTTON))
                    {
                    // Level Easy
                        if((x < 352) && (x > 50) && (y < 590) && (y > 490))
                        {
                            level = 1 ;
                            cleardevice();
                            Makelist(&map,level);
                            Info_map(gambar,map);

                            setcolor(WHITE);
                            settextstyle(0,0,6);
                            outtextxy(130,625,"PA");
                            outtextxy(320,625,"MAN");
                            setcolor(YELLOW);
                            setfillstyle(1,YELLOW);
                            pieslice(266,650,0,360,25);
                            setcolor(0);
                            setfillstyle(1,0);
                            pieslice(266,650,0,20,40);
                            pieslice(266,650,340,360,40);

                            getch();
                            //ghost(1);
                        }
                     // Level Medium
                    if((x < 660) && (x > 452) && (y < 590) && (y > 490))
                        {
                            //mulai permainan level easy
                            level = 2 ;
                            cleardevice();
                            Makelist(&map,level);
                            Info_map(gambar,map);

                            setcolor(WHITE);
                            settextstyle(0,0,6);
                            outtextxy(130,625,"PA");
                            outtextxy(320,625,"MAN");
                            setcolor(YELLOW);
                            setfillstyle(1,YELLOW);
                            pieslice(266,650,0,360,25);
                            setcolor(0);
                            setfillstyle(1,0);
                            pieslice(266,650,0,20,40);
                            pieslice(266,650,340,360,40);

                            getch();
                            //ghost(1);
                        }
                    // Level Hard
                    if((x < 950) && (x > 762) && (y < 590) && (y > 490))
                        {
                            //mulai permainan level easy
                            level = 3 ;
                            cleardevice();
                            Makelist(&map,level);
                            Info_map(gambar,map);

                            setcolor(WHITE);
                            settextstyle(0,0,6);
                            outtextxy(130,625,"PA");
                            outtextxy(320,625,"MAN");
                            setcolor(YELLOW);
                            setfillstyle(1,YELLOW);
                            pieslice(266,650,0,360,25);
                            setcolor(0);
                            setfillstyle(1,0);
                            pieslice(266,650,0,20,40);
                            pieslice(266,650,340,360,40);

                            getch();
                            //ghost(1);
                        }
                    // Back
                    if((x < 600) && (x > 320) && (y < 575) && (y > 360))
                        {
                            goto menu;
                        }
                    }
                }
            }
        // HighScore
            if((x < 600 && x > 400) && (y < 500 && y > 385))
                {
                    break;
                }
        // About
            if((x < 600 && x > 400) && (y < 590 && y > 510))/** gabisa nampilin sm ngeklik about**/
                    {
                    Rendering_Menu("About Game");
                    while(1)
                    {
                        GetCursorPos(&CursorPosition);
                        x=CursorPosition.x;
                        y=CursorPosition.y;
                        if(GetAsyncKeyState(VK_LBUTTON))
                        {
                            if((x < 287 && x > 50) && (y < 670 && y > 571))
                                {
                                    goto menu;
                                }
                            if((x < 950 && x > 713) && (y < 670 && y > 571))
                                {
                                    exit(1);
                                }
                        }
                    }
                    }
        // Exit
            if((x < 600 && x > 400) && (y < 690 && y > 610))
                {
                    exit(1);
                }
        }
    }
}
