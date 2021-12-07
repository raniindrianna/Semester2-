#include "gamePlay.hpp"





game *buildGame(int ukuran,int l,int t)
{
    game *p = (game*)malloc(sizeof(game*));
    p->lebar = l;
    p->tinggi = t;
    p->ukuran = ukuran;
    p->lebarWindow = ukuran * l;
    p->tinggiWindow = ukuran * t;

    return p;
}

game startGame(game *p)
{
    initwindow(p->lebarWindow,p->tinggiWindow);
//     render menu awal
  renderMenu("opening");
    renderMenu("load");
    // masuk ke permainan
  controlMenu();

}

void controlMenu()
{
    int x,y,lv;
    List maze;
    CreateList(&maze);
    sprite *gambar = sprite_create(50) ;
    while(1)
    {
        menu:
        renderMenu("pilih menu");
        getmouseclick(WM_LBUTTONDOWN,x,y);
        // kalo klik play
        if((x <580 && x > 350) && ( y > 225 && y < 290))
            {
                while (1)
                {
                    renderMenu("pilih level");
                    getmouseclick(WM_LBUTTONDOWN,x,y);
                    // klik back
                    if((x < 100 && x > 0) && ( y > 400 && y < 500))
                        {
                            goto menu;
                        }
                    // klik easy
                    if((x <580 && x > 350) && ( y > 225 && y < 290))
                        {
                            //mulai permainan level easy
                            lv = 1 ;
                            cleardevice();
                            Makelist(&maze,lv);
                            map_view(gambar,maze);
                            getch();
                            //ghost(1);
                        }
                     // klik medium
                    if((x <580 && x > 350) && ( y > 305 && y < 360))
                        {
                            //mulai permainan level easy
                            lv = 2 ;
                            cleardevice();
                            Makelist(&maze,lv);
                            map_view(gambar,maze);
                            getch();
                            //ghost(1);
                        }
                    // kalo klik hard
                    if((x <580 && x > 350) && ( y > 405 && y < 455))
                        {
                            //mulai permainan level easy
                            lv = 3 ;
                            cleardevice();
                            Makelist(&maze,lv);
                            map_view(gambar,maze);
                            getch();
                            //ghost(1);
                        }
                }
            }
                // klik how to play
            if((x <580 && x > 350) && ( y > 405 && y < 455))
                    {
                    while (1)
                        {
                            renderMenu("how to play");
                            getmouseclick(WM_LBUTTONDOWN,x,y);
                            // klik back
                            if((x < 100 && x > 0) && ( y > 400 && y < 500))
                                {
                                    goto menu;
                                }
                        }
                    }
               // kalo klik exit
            if((x < 900 && x > 800) && ( y > 400 && y < 500))
                    {
                        exit(1);
                    }
}
}

