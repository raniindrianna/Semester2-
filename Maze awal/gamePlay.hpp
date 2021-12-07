#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <graphics.h>

#include "map.hpp"

typedef struct permainan{
    int ukuran; // ??
   // ukuran gambar
    int lebar;
    int tinggi;
    // ukuran window
    int lebarWindow;
    int tinggiWindow;
}game;

game *buildGame(int ukuran,int lebar,int tinggi);

game startGame(game *p);

void controlMenu();




#endif //
