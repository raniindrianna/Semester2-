#include "menu.hpp"

Sprites *BuildSprites(int ukuran)
{
    Sprites *bs = (Sprites*)malloc(sizeof(Sprites));

    if(bs == NULL){
        printf("Alokasi gagal\n");
        exit(1);
    }
    int area;
    area = imagesize(300,300,300+ukuran,300+ukuran);

    /** Wall Maze Level Easy **/
    readimagefile("image/ImageWall/wall1.jpg",300,300,300+ukuran,300+ukuran);
    bs->maze1 = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->maze1);

    /** Wall Maze Level Medium **/
    readimagefile("image/ImageWall/wall2.jpg",300,300,300+ukuran,300+ukuran);
    bs->maze2 = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->maze2);

    /** Wall Maze Level Hard **/
    readimagefile("image/ImageWall/wall3.jpg",300,300,300+ukuran,300+ukuran);
    bs->maze3 = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->maze3);

    /** Pacman arah Kanan **/
    readimagefile("image/ImagePacman/PacmanRight.jpg",300,300,300+ukuran,300+ukuran);
    bs->pkanan = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->pkanan);

    readimagefile("image/ImagePacman/Pacman.jpg",300,300,300+ukuran,300+ukuran);
    bs->pbulat1 = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->pbulat1);

    /** Pacman arah Kiri **/
    readimagefile("image/ImagePacman/PacmanLeft.jpg",300,300,300+ukuran,300+ukuran);
    bs->pkiri = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->pkiri);

    readimagefile("image/ImagePacman/Pacman.jpg",300,300,300+ukuran,300+ukuran);
    bs->pbulat2 = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->pbulat2);

    /** Pacman arah Atas **/
    readimagefile("image/ImagePacman/PacmanUp.jpg",300,300,300+ukuran,300+ukuran);
    bs->patas = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->patas);

    readimagefile("image/ImagePacman/Pacman.jpg",300,300,300+ukuran,300+ukuran);
    bs->pbulat3 = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->pbulat3);

    /** Pacman arah Bawah **/
    readimagefile("image/ImagePacman/PacmanDown.jpg",300,300,300+ukuran,300+ukuran);
    bs->pbawah = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->pbawah);

    readimagefile("image/ImagePacman/Pacman.jpg",300,300,300+ukuran,300+ukuran);
    bs->pbulat4 = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->pbulat4);

    /** Pellet **/
    readimagefile("image/ImagePellet/NormalPellet.jpg",300,300,300+ukuran,300+ukuran);
    bs->norpel = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->norpel);

    readimagefile("image/ImagePellet/PowerPellet.jpg",300,300,300+ukuran,300+ukuran);
    bs->powpel = malloc(area);
    getimage(300,300,300+ukuran,300+ukuran,bs->powpel);

    return bs;
}

void Rendering_Menu(const char ex[15])
{
    if((strcmp(ex,"Tampilan") == 0)){
        readimagefile("image/ImageSlide/Tampilan Awal.jpg",0,0,1000,700);
        delay(2000);
    }
    else if((strcmp(ex,"Halaman Utama") == 0)){
        readimagefile("image/ImageSlide/Halaman Utama.jpg",0,0,1000,700);
    }
    else if((strcmp(ex,"Menu Utama") == 0)){
        readimagefile("image/ImageSlide/Menu Utama.jpg",0,0,1000,700);
    }
    else if((strcmp(ex,"About Game") == 0)){
        readimagefile("image/ImageSlide/About1.jpg",0,0,1000,700);
        delay(3000);
        readimagefile("image/ImageSlide/About.jpg",0,0,1000,700);
    }
}

void Makelist(List *L1 , int level){
    List L2;
    int i,j,b,k;
    infotype nilai;
    address P1,P2,down;

    b = 23;
    k = 22;

    //samping = 22
    //kebwah - 23
        for(i=1;i<=b;i++){
            CreateList(&L2);
            for(j=1;j<=k;j++){
                if(level == 1){
                    //level easy

                    //Wall
                        if((i==1&&j<=22)||(i==23&&j<=23)||(j==1&&i>=1&&i<24)||(j==22&&i>=1&&i<24)){  //kotak luar
                            nilai = 2;
                        }else if((i==3&&j>=3&&j<=10)||(i==3&&j>=13&&j<=20)||(i==21&&j>=3&&j<=10)||(i==21&&j>=13&&j<=20)||(j==3&&i>=3&&i<=11)||(j==3&&i>=14&&i<=20)||(j==20&&i>=3&&i<=11)||(j==20&&i>=14&&i<=20)){ //tembok area 3 dan 21
                            nilai = 2;
                        }else if((i==5&&j>=5&&j<=10)||(i==5&&j>=13&&j<=18)||(i==19&&j>=5&&j<=10)||(i==19&&j>=13&&j<=18)||(j==5&&i>=5&&i<19)||(j==18&&i>5&&i<19)){ //tembok area 5 dan 19
                            nilai = 2;
                        }else if((i==7&&j>=7&&j<=16)||(i==17&&j>=7&&j<=16)||(j==7&&i>=7&&i<=11)||(j==7&&i>=14&&i<=17)||(j==16&&i>=7&&i<=11)||(j==16&&i>=14&&i<=17)){ //tembok area 7 dan 17
                            nilai = 2;
                        }else if((i==9&&j>=9&&j<=10)||(i==9&&j>=13&&j<=14)||(i==15&&j>=9&&j<=14)||(j==9&&i>=9&&i<15)||(j==14&&i>9&&i<15)){ //tembok area 9 dan 15
                            nilai = 2;
                        }else{
                            nilai = 0;
                        }

                }else if (level == 2){
                    //level medium

                    //Wall
                        if((i==1&&j>=1&&j<=22)||(i==23&&j>=1&&j<=22)||(j==1&&i>=1&&i<=12)||j==1&&i>=14&&i<=16||(j==1&&i>=18&&i<=23)){  //kotak luar
                            nilai = 2;
                        }else if((i==12&&j>=2&&j<=5)||(i==14&&j>=2&&j<=5)||(i==12&&j>=17&&j<=21)||(i==14&&j>=17&&j<=21)||(j==22&&i>=1&&i<=12)||(j==22&&i>=14&&i<=16)||(j==22&&i>=18&&i<=23)){ //kotak luar
                            nilai = 2;
                        }else if((i==13&&j==5)||(i==13&&j==17)||(i==17&&j==5)||(i==17&&j==17)){
                            nilai = 2;
                        }else if((i==16&&j>=2&&j<=5)||(i==18&&j>=2&&j<=5)||(i==16&&j>=17&&j<=21)||(i==18&&j>=17&&j<=21)){
                            nilai = 2;
                        }else if((i==3&&j>=3&&j<=5)||(i==5&&j>=3&&j<=5)||(j==3&&i>=3&&i<=5)||(j==5&&i>=3&&i<=5)||(i==3&&j>=7&&j<=9)||(i==5&&j>=7&&j<=9)||(j==7&&i==4)||(j==9&&i==4)){
                            nilai = 2;
                        }else if((i==3&&j>=13&&j<=15)||(i==5&&j>=13&&j<=15)||(j==13&&i==4)||(j==15&&i==4)||(i==3&&j>=17&&j<=20)||(i==5&&j>=17&&j<=20)||(j==17&&i==4)||(j==20&&i==4)){
                            nilai = 2;
                        }else if((i==7&&j>=3&&j<=5)||(i==10&&j>=3&&j<=5)||(j==3&&i>=8&&i<=9)||(j==5&&i>=8&&i<=9)||(i==11&&j==9)) {
                            nilai = 2;
                        }else if((j==7&&i>=7&&i<=11)||(i==9&&j>=8&&j<=9)||(j==15&&i>=7&&i<=11)||(i==9&&j>=13&&j<=14)||(i==7&&j>=17&&j<=20)) {
                            nilai = 2;
                        }else if((i==7&&j>=9&&j<=13)||(j==11&&i>=8&&i<=11)||(i==11&&j>=12&&j<=13)||(j==11&&i>=2&&i<=5)||(i==9&&j>=17&&j<=20)||(i==10&&j>=17&&j<=20)) {
                            nilai = 2;
                        }else if((j==7&&i>=13&&i<=19)||(j==9&&i>=18&&i<=19)||(j==13&&i>=18&&i<=19)||(j==15&&i>=13&&i<=19)||(i==20&&j>=3&&j<=5)){
                            nilai = 2;
                        }else if((i==21&&j>=3&&j<=15)||(j==11&&i>=18&&i<=20)||(i==20&&j>=17&&j<=20)||(i==21&&j>=17&&j<=20)) {
                            nilai = 2;
                        }else if((i==13&&j>=9&&j<=10)||(i==13&&j>=12&&j<=13)||(i==16&&j>=9&&j<=13)||(j==9&&i>=14&&i<=15)||(j==13&&i>=14&&i<=15)) {  //area musuh
                            nilai = 2;
                        }else{
                            nilai = 0;
                        }
                }else if ( level = 3){
                    //level Hard

                    //Wall
                         if((i==1&&j<=22)||(i==23&&j<=23)||(j==1&&i>=1&&i<24)||(j==22&&i>=1&&i<24)){  //kotak luar
                            nilai = 2;
                        }else if((i==3&&j>=5&&j<=7)||(i==3&&j>=9&&j<=12)||(i==3&&j>=14&&j<=20)||(i==4&&j==20)){
                            nilai = 2;
                        }else if((j==3&&i>=3&&i<=5)||(j==3&&i>=7&&i<=17)||(i==7&&j>=4&&j<=5)||(i==17&&j>=4&&j<=7)||(i==15&&j>=5&&j<=7)||(i==16&&j==7)){
                            nilai = 2;
                        }else if((i==19&&j>=3&&j<=6)||(j==6&&i>=19&&i<=21)||(i==21&&j>=3&&j<=4)||(j==5&&i>=9&&i<=13)){
                            nilai = 2;
                        }else if((i==5&&j>=5&&j<=10)||(j==10&&i>=6&&i<=7)||(i==7&&j>=11&&j<=13)){
                            nilai = 2;
                        }else if((j==7&&i>=7&&i<=11)||(i==7&&j==8)||(j==16&&i>=7&&i<=10)||(i==7&&j==15)||(i==19&&j>=10&&j<=12)||(j==10&&i>=20&&i<=21)){
                            nilai = 2;
                        }else if((i==13&&j>=7&&j<=12)||(i==15&&j>=9&&j<=16)||(i==21&&j>=12&&j<=18)){
                            nilai = 2 ;
                        }else if((j==8&&i>=19&&i<=21)||(j==20&&i>=6&&i<=8)||(i==19&&j>=18&&j<=20)||(j==20&&i>=20&&i<=21)) {
                            nilai = 2;
                        }else if((i==17&&j>=9&&j<=20)||(j==20&&i>=15&&i<=16)||(i==19&&j>=14&&j<=16)||(i==18&&j==14)) {
                            nilai = 2;
                        }else if((i==13&&j>=14&&j<=16)||(i==12&&j>=16&&j<=18)||(j==18&&i>=13&&i<=15)) {
                            nilai = 2;
                        }else if((j==12&&i>=4&&i<=5)||(i==5&&j>=13&&j<=18)||(j==18&&i>=5&&i<=10)||(i==10&&j>=18&&j<=20)||(j==20&&i>=11&&i<=13)) {
                            nilai = 2 ;
                        }else if((i==9&&j>=9&&j<=10)||(i==9&&j>=13&&j<=14)||(i==11&&j>=9&&j<=14)||(j==14&&i==10)||(j==9&&i==10)) {
                            nilai = 2;
                        }else{
                            nilai = 0;
                        }

                }else{
                    printf("Next");
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

void Info_map(Sprites *ps, List L){
    int x,y; //posisi awal map
    int gridSize = 25;
    address P1,P2;

    cleardevice();
    if (First(L)==Nil){
        printf ("List kosong\n");
    }else{
        P1=First(L);
        while (P1!=Nil){
            P2=P1;
            while (P2!=Nil){
                if(Info(P2) == 2){
                    //readimagefile("gambar//wall.jpg",x,y,x+gridSize,y+gridSize);
                    putimage(x,y,ps->maze2,COPY_PUT);
                }else if(Info(P2) == 0){
                    //readimagefile("gambar//pellet.jpg",x,y,x+gridSize,y+gridSize);
                    putimage(x,y,ps->norpel,COPY_PUT);
                }else if (Info(P2) == 4){
                    //readimagefile("gambar//bonus.gif",x,y,x+gridSize,y+gridSize);
                    putimage(x,y,ps->powpel,COPY_PUT);
                }/*else if(Info(P2) == 6){
                    putimage(x,y,pick->power_pelet,COPY_PUT);
                }else if(Info(P2) == 8){
                    putimage(x,y,pick->bonus,COPY_PUT);
                }*/
                x += 26;
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
