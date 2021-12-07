#include "render.hpp"




void renderMenu(const char ket[15])
{
    if ((strcmp (ket, "opening")) == 0)
    {
        readimagefile("gambar//kelompok.jpg",0,0,900,500);
        delay(2000);
        readimagefile("gambar//present.jpg",0,0,900,500);
        delay(2000);
    }
    else if ((strcmp (ket, "load"))== 0)
    {
        readimagefile("gambar//load1.jpg",0,0,900,500);
        delay(1500);
        readimagefile("gambar//load2.jpg",0,0,900,500);
        delay(1500);
        readimagefile("gambar//load3.jpg",0,0,900,500);
        delay(1500);
 //       readimagefile("gambar//menu.jpg",0,0,900,500);
 //       delay(1500);
    }
    else if((strcmp (ket,"pilih menu"))== 0)
    {
        readimagefile("gambar//menu.jpg",0,0,900,500);
    }
    else if((strcmp (ket,"pilih level"))== 0)
    {
        readimagefile("gambar//play.jpg",0,0,900,500);
    }
    else if((strcmp (ket,"how to play"))== 0)
    {
        readimagefile("gambar//howtoplay.jpg",0,0,900,500);
    }

}

sprite *sprite_create(int gridSize)
{
    sprite *s =(sprite *)malloc(sizeof(sprite));
    int x=200,y=200;

    if (s == NULL)
    {
        printf("error!");
        exit(1);
    }
    unsigned int tempSizing;
    tempSizing = imagesize(x,y,x + gridSize,y + gridSize);

    //sprite for BackgroundMap

    //sprite for WallMap
        //putimage(600,600)
        readimagefile("gambar//wall.jpg",x,y,x + gridSize,y + gridSize);
        s->WallMap = malloc(tempSizing);
        getimage(x,y,x + gridSize,y + gridSize, s->WallMap);
        cleardevice();

        //sprite for food

        readimagefile("gambar//pellet.jpg", x , y, x + gridSize, y + gridSize);
        s->Food = malloc(tempSizing);
        getimage(x, y, x + gridSize, y + gridSize, s->Food);
        cleardevice();

        readimagefile("gambar//bonus.gif",x,y,x+gridSize,y+gridSize);
        s->bonus = malloc(tempSizing);
        getimage(x, y, x + gridSize, y + gridSize, s->bonus);
        cleardevice();

        //Sprite pacman
        readimagefile("pacman hantu.gif",x,y,x+gridSize,y+gridSize);
        s->pacman=malloc(tempSizing);
        cleardevice();



    return s;
}

void Makelist(List *L1 , int lv){
    List L2;
    int i,j,b,k;
    infotype nilai;
    address P1,P2,down;

    b = 21;
    k = 20;

        for(i=1;i<=b;i++){
            CreateList(&L2);
            for(j=1;j<=k;j++){
                if(lv == 1){
                    //level easy

                    //Wall
                        if((i == 4 && j <= 22)|| (i == 22 && j<= 22)||(j == 1 && i > 3 && i<27) ||(j == 22 && i > 3 && i < 27)) { //border kotak luar
                        nilai = 2;
                    }else if((i== 6 || i == 24) &&(j == 3 || j == 20)) { //area tembok baris 6 dan 24
                        nilai = 2;
                    }else if((i == 8 || i == 22) && (j == 5 || j == 18)){ //area tembok baris 8 dan 22
                        nilai = 2;
                    }else if((i == 10 || i == 20) && (j == 7 || j == 16)){ //area tembok baris 10 dan 20
                        nilai = 2;
                    }else if((i == 12 || i == 18) && (j == 9 || j == 14)) { //area tembok baris 12 dan 18
                        nilai = 2;
                    //Cherry
                    //}else if(i==10 && (j==3 || j==5)){  //buah bonus
                      //      nilai = 4;
                    //no render
                        }else if((i <= 3 || i >= 27) && (j >= 1 || j == 22)) {
                        nilai = 1;
                    }else if((i >= 4 || i <= 26) && (j >= 23 || j == 21 )) {
                        nilai = 1;
                    //Food Pellet
                        }else{
                            nilai = 0;

                        }

                }else if (lv == 2){
                    //level medium

                    //Wall
                        if((i == 4 && j <= 9) || (i == 16 && j<= 9) || (j == 1 && i > 3 && i < 17) || (j == 9 && i > 3 && i < 17)){ //border kotak luar
                            nilai = 2;
                        }else if((i==6 || i ==14) && (j==4 || j==6 )){ //area wall baris 6 dan 14
                            nilai = 2;
                        }else if((i==7 || i==13) && ((j>=4 && j <= 6 ))){ //area wall baris 7 dan 13
                            nilai = 2;
                        }else if((i==9 || i==11 ) && ((j>=3 && j < 5) || (j > 5 && j <=7 ))){ //area wall baris 9 dan 11
                            nilai = 2;
                        }else if((i==10 &&( j==4 || j == 6 ))){ //area wall baris 10
                            nilai = 2;
                    //Cherry
                        }else if(i==10 && (j==3 || j==7)){  //buah bonus
                            nilai = 4;
                    //no render
                        }else if((i <= 3 || i >= 17) && (j >= 1 || j == 20)){
                            nilai = 1;
                        }else if((i >=4 || i <= 16) && (j >= 10 || j == 21)){
                            nilai = 1;
                    //Food Pellet
                        }else{
                            nilai = 0;
                        }
                }else if ( lv = 3){
                    //level Hard

                    //Wall
                        if((i == 4 && j <= 12) || (i == 16 && j<= 12) || (j == 1 && i > 3 && i < 17) || (j == 12 && i > 3 && i < 17)){ //border kotak luar
                            nilai = 2;
                        }else if((i==6 && (j>=5 && j<=9 ))){ //area wall garis datar baris 6
                            nilai = 2;
                        }else if((i==13 && (j>=5 && j<=8 ))){ //area wall garis datar baris 13
                            nilai = 2;
                        }else if((j == 3 && (i > 4 && i <13)) ||( j == 10 && (i > 7 && i < 16 ) )){ //area wall tegak  kolom 3 dan 10
                            nilai = 2;
                        }else if((i == 9 || i == 10 ) && ((j == 5 || j == 8))){ //area wall baris 9 dan 10
                            nilai = 2;
                        }else if((i==11 &&( j>5 && j < 8 ))){ //area wall baris 11
                            nilai = 2;
                        }else if (i == 15 && j == 6){ // area wall di baris 15
                            nilai = 2 ;
                    //Cherry
                        }else if(i==15 && j == 11){  //buah bonus
                            nilai = 4;
                    //no render
                        }else if((i <= 3 || i >= 17) && (j >= 1 || j == 20)){
                            nilai = 1;
                        }else if((i >=4 || i <= 16) && (j >= 13 || j == 21)){
                            nilai = 1;
                    //Food Pellet
                       // }else{
                        //    nilai = 0;
                        }

                }else{
                    printf("Next Update");
                }
                P1 = Alokasi(nilai);
                if(i==1){
                    InsertLast(&(*L1),P1);
                    P2 = First(*L1);
                }
                else{
                    InsertLast(&L2,P1);
                    baris(down) = P1;
                    down = Next(down);
                }
            }
            if(i>1){
                P2 = baris(P2);
            }
            down = P2;
        }
}

void map_view(sprite *s, List L){
    int x,y; //posisi awal map
    int gridSize = 25;
    address P1,P2;

    cleardevice();
    if (First(L)==Nil){
        printf ("List kosong.\n\n");
    }else{
        P1=First(L);
        while (P1!=Nil){
            P2=P1;
            while (P2!=Nil){
                if(Info(P2) == 2){
                    //readimagefile("gambar//wall.jpg",x,y,x+gridSize,y+gridSize);
                    putimage(x,y,s->WallMap,COPY_PUT);
                }else if(Info(P2) == 0){
                    //readimagefile("gambar//pellet.jpg",x,y,x+gridSize,y+gridSize);
                    putimage(x,y,s->Food,COPY_PUT);
                }else if (Info(P2) == 4){
                    //readimagefile("gambar//bonus.gif",x,y,x+gridSize,y+gridSize);
                    putimage(x,y,s->bonus,COPY_PUT);
                }/*else if(Info(P2) == 6){
                    putimage(x,y,pick->power_pelet,COPY_PUT);
                }else if(Info(P2) == 8){
                    putimage(x,y,pick->bonus,COPY_PUT);
                }*/
                x += 25;
                printf ("%d ",Info(P2));
                P2=Next(P2);
            }
            x = 26;
            y = y + 26;
            printf ("\n");
            P1=baris(P1);
        }
    }
}
