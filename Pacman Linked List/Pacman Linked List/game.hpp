#ifndef game_H
#define game_H
#include <graphics.h>
#include "menu.hpp"

typedef struct menuGame
{
    int ukuran;     // ukuran gambar.
    int ukuranl;    // lebar gambar.
    int ukuranp;    // panjang gambar.
    int windowl;    // ukuran lebar window.
    int windowp;    // ukuran panjang window.
} menuGame;

void menuUtama();

menuGame *BuildGame(int ukuran,int l,int p);

menuGame run(menuGame *g);



#endif // game_H
