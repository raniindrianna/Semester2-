#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void *maze1;
void *maze2;
void *maze3;

const int baris = 23;
const int kolom = 22;

       //*** "MAZE LEVEL MUDAH" *** //

int map1[23][22] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

      //*** "MAZE LEVEL MEDIUM" *** //

int map2[23][22] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,0,0,1,0,0,1,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,0,0,0,1,0,0,1,0,0,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,1,0,0,0,1,1,1,1,0,1,0,0,1},
    {1,0,1,0,1,0,1,1,0,0,0,0,0,0,0,1,1,0,1,0,0,1},
    {1,0,1,0,1,0,1,1,0,0,0,0,0,0,0,1,1,0,1,0,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};



int main(){
    initwindow(1000,700,"Maze");
    int a,b,x,y,tempSizing;

    tempSizing = imagesize(300,300,325,325);


     //*** "TAMPIL MAZE MUDAH" *** //

  /*  readimagefile("wall.jpg",300,300,325,325);
    maze1 = malloc(tempSizing);
    getimage(300,300,325,325, maze1);

    //menampilkan maze MUDAH
    x=80, y=0;
    for(a=0; a<23; a++) {
        for(b=0; b<22; b++) {
            if(map1[a][b]!=0){
                putimage(x,y,maze1,COPY_PUT);
            }
            x=x+25;
        }
        y=y+25;
        x=80;
    }*/

     //*** "TAMPIL MAZE MEDIUM" *** //

    readimagefile("wall.jpg",300,300,325,325);
    maze2 = malloc(tempSizing);
    getimage(300,300,325,325, maze2);

    //menampilkan maze MEDIUM
    x=80, y=0;
    for(a=0; a<23; a++) {
        for(b=0; b<22; b++) {
            if(map2[a][b]!=0){
                putimage(x,y,maze2,COPY_PUT);
            }
            x=x+25;
        }
        y=y+25;
        x=80;
    }


    getch();
    closegraph();

    return 0;
}