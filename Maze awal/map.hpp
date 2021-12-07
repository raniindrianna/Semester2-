#ifndef MAP_H
#define MAP_H

#include <graphics.h>
#include "LinkedList.hpp"
#include <string.h>


typedef struct sprite
{
    void *WallMap;
    void *BackgroundMap;
    void *Food;
    void *bonus;
    void *pacman;
}sprite;

sprite *sprite_create(int gridSize);
void BackgroundMap(sprite *s);
void WallMap(sprite *s);
void Rendering_Food(sprite *s);
void Rendering_bonus(sprite *s);

void renderMenu(const char ket[15]);

void Makelist(List *L1, int lv);
void map_view(sprite *s, List L);


#endif // RENDER_H
