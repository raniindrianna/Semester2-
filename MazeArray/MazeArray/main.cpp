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
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,1},
    {1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,0,0,1},
    {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
    {0,0,0,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,0,0,0},
    {1,1,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1},
    {1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1},
    {0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0},
    {1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

     //*** "MAZE LEVEL SULIT" *** //
int map3[23][22] =
{
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1},
   	{1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,1,1,0,1,1,0,1,1,1,1,0,1,1,0,1,0,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,1,0,0,1,1,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1},
    {1,0,1,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main(){
    initwindow(1000,700,"Maze");
    int a,b,x,y,tempSizing;

    tempSizing = imagesize(300,300,324,324);


     //*** "TAMPIL MAZE MUDAH" *** //

    readimagefile("wall.jpg",300,300,324,324);
    maze1 = malloc(tempSizing);
    getimage(300,300,324,324, maze1);
    putimage(x,y,maze1,XOR_PUT);
/*
    //menampilkan maze MUDAH
   x=126, y=1;
    for(a=0; a<23; a++) {
        for(b=0; b<22; b++) {
            if(map1[a][b]!=0){
                    setcolor(YELLOW);
                    rectangle(x-1,y-1,x+25,y+25); //border setiap kotak untuk sensor gerak
                putimage(x,y,maze1,COPY_PUT);
            }
            x=x+26;
        }
        y=y+26;
        x=126;

        //line
        setcolor(WHITE);
        line(386,221,437,221);
    }*/

     //*** "TAMPIL MAZE MEDIUM" *** //

    readimagefile("wall3.jpg",300,300,324,324);
    maze2 = malloc(tempSizing);
    getimage(300,300,324,324, maze2);
    putimage(300,300,maze2,XOR_PUT);

    //menampilkan maze MEDIUM
    x=126, y=1;
    for(a=0; a<23; a++) {
        for(b=0; b<22; b++) {
            if(map2[a][b]!=0){
                setcolor(YELLOW);
                rectangle(x-1,y-1,x+25,y+25); //border setiap kotak untuk sensor gerak
                putimage(x,y,maze2,COPY_PUT);
            }
            x=x+26;
        }
        y=y+26;
        x=126;

        //line
       // setcolor(WHITE);
        //line(386,221,437,221);
    }


      //*** "TAMPIL MAZE SULIT" *** //
    /*
   readimagefile("wall3.jpg", 300,300,324,324);
    maze3 = malloc(tempSizing);
    getimage(300,300,324,324,maze3);
    putimage(300,300,maze3,XOR_PUT);

    //menampilkan maze sulit
    x=126, y=1;
    for(a=0; a<23; a++) {
        for(b=0; b<22; b++){
            if(map3[a][b]!= 0){
                setcolor(YELLOW);
                rectangle(x-1,y-1,x+25,y+25); //border setiap kotak wall3 untuk sensor gerak
                putimage(x,y,maze3,COPY_PUT);
            }
           x=x+26;
        }
        y=y+26;
        x=126;
    }
    setcolor(WHITE); //warna line
    line(386,221,437,221);
*/


    getch();
    closegraph();

    return 0;
}
