#ifndef menu_H
#define menu_H
#include <graphics.h>
#include "Linkedlist.hpp"
#include <conio.h>
#include <string>

typedef struct Sprites
{
    void *maze1;    // untuk gambar wall maze level easy
    void *maze2;    // untuk gambar wall maze level medium
    void *maze3;    // untuk gambar wall maze level hard
    void *norpel;   // untuk normal pellet
    void *powpel;   // untuk power pellet
    void *pkanan;   // untuk gambar pacman kanan
    void *pkiri;    // untuk gambar pacman kiri
    void *patas;    // untuk gambar pacman atas
    void *pbawah;   // untuk gambar pacman bawah
    void *pbulat1,*pbulat2,*pbulat3,*pbulat4;  // untuk gambar pacman full
}Sprites;

Sprites *BuildSprites(int ukuran);      // melakukan alokasi gambar
void Rendering_Menu(const char ex[15]);

void Makelist(List *L1 , int level);

void Info_map(Sprites *ps, List L);


#endif // menu_H
