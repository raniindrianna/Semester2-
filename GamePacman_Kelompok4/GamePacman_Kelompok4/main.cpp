#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <iostream>
#include <windows.h>

/** MODUL GLOBAL **/
void tampilanAwal();       // tampilan awal permainan sebelum masuk ke menu awal
void halamanUtama();       // tampilan menu awal permainan
void menuUtama();          // tampilan untuk ke halaman permainan

/*** MODUL MAZE ***/
void *maze1;
void *maze2;
void *maze3;
const int baris = 23;
const int kolom = 22;
int maze(int level);

/*** MODUL HIGHSCORE ***/
void tampil_score();                            // menampilkan score pada permainan
int score_pacman(int p1, int p2, int score);    // menyimpan hasil score
void search_score(int score);                   // mencari score tertinggi
void highscore_pacman();                        // menampilkan high score
char arr[100];
int p1;int p2;

/*** MODUL FITUR CONTROL ***/
void move_pacman();                             // mengatur arah pergerakan pacman
void sprite_pacman();                           // menjadikan gambar pacman sebagai buffer
void *pkanan;                                   // menampung alokasi memori u/ pacman mulut terbuka ke kanan
void *pkiri;                                    // menampung alokasi memori u/ pacman mulut terbuka ke kiri
void *patas;                                    // menampung alokasi memori u/ pacman mulut terbuka ke atas
void *pbawah;                                   // menampung alokasi memori u/ pacman mulut terbuka ke bawah
void *pbulat1,*pbulat2,*pbulat3,*pbulat4;       // menampung alokasi memori u/ pacman mulut tertutup

void pacman_kanan(int x, int y);                // menampilkan pacman dengan arah ke kanan
void pacman_kiri(int x, int y);                 // menampilkan pacman dengan arah ke kiri
void pacman_atas(int x, int y);                 // menampilkan pacman dengan arah ke atas
void pacman_bawah(int x,int y);                 // menampilkan pacman dengan arah ke bawah
void arah_pacman(int dir, int x, int y);        // memanggil modul diatas


/*** MODUL COLLISION ***/
void collision();//procedure utama untuk fitur collision
void collision_con1(int p2);//procedure untuk kondisi pacman tidak makan pellet besar(p2)
void collision_con2(int p2); //procedure untuk kondisi  pacman makan pellet besar(p2)

/*** MODUL GHOST ***/
void *G_right,*G_up,*G_left,*G_down,*Gtrans_right,*Gtrans_up,*Gtrans_left,*Gtrans_down;
void *R_right,*R_up,*R_left,*R_down,*Rtrans_right,*Rtrans_up,*Rtrans_left,*Rtrans_down;
void *P_right,*P_up,*P_left,*P_down,*Ptrans_right,*Ptrans_up,*Ptrans_left,*Ptrans_down;
void *B_right,*B_up,*B_left,*B_down,*Btrans_right,*Btrans_up,*Btrans_left,*Btrans_down;
void *Dying,*Dyingtrans;
void *E_right,*E_up,*E_left,*E_down,*Etrans_right,*Etrans_up,*Etrans_left,*Etrans_down;
void g_alloc();
class ghost
{
private:
	//KOORDINAT GHOST
	int i_g;
	int j_g;
	//SENSOR GERAK
	int gleft_top;
	int gleft_mid;
	int gleft_bottom;
	int gmid_bottom;
	int gright_bottom;
	int gright_mid;
	int gright_top;
	int gmid_top;
	//
	int g_no;
	int ioro;
	//ARAH GERAK
	char d;
	//PENANDA WARNA
	int color;
	//
	int trans;

	void inhome();
	void moveghost(int ,int );
	void gmove_rand();
	void gchase_smthin(int ,int );

public:
	void addcolor(int n)
	{
		color=n;
	}
	void gwork(int ,int );
	void disp_still(int ,int );

	ghost()
	{
		g_no=0;
		trans=1;
		d='l';
		ioro=1;
		gleft_top=0;
		gleft_mid=0;
		gleft_bottom=0;
		gmid_bottom=0;
		gright_bottom=0;
		gright_mid=0;
		gright_top=0;
		gmid_top=0;
	}
};
unsigned long count=1;
int number,SensorColor,level;

/*** MODUL FITUR SPAWN PELLET ***/
void *pelet1;
int pellet(int level);

       //*** "MAZE LEVEL MUDAH" *** //
int map1[baris][kolom] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

      //*** "MAZE LEVEL MEDIUM" *** //
int map2[baris][kolom] =
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
    {0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0},
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
int map3[baris][kolom] =
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
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main()
{
	initwindow(1000,700,"Pacman");
	g_alloc();
	tampilanAwal();
	halamanUtama();
	//cleardevice();
	//maze(3);
	//pellet();
	//tampil_score();
    //move_pacman();
	//ghost(1000);
	getch();
    closegraph();

    return 0;
}

void tampilanAwal(){
    readimagefile("image/ImageSlide/Tampilan Awal.jpg",0,0,1000,700);
    getch();
}

void halamanUtama(){
    POINT CursorPosition;
    int x,y;
    bool option = false;

    //while(!option){
    readimagefile("image/ImageSlide/Halaman Utama.jpg",0,0,1000,700);
    while(1)
    {
    	GetCursorPos(&CursorPosition);
    	x=CursorPosition.x;
    	y=CursorPosition.y;

    	if(GetAsyncKeyState(VK_LBUTTON))
    	{
    		if((x < 600) && (x > 350) && (y < 425) && (y > 325))
			{
        		clearviewport();
        		setviewport(0,0,getmaxx(),getmaxy(),1);
        		readimagefile("image/ImageSlide/Menu Utama.jpg",0,0,1000,700);
        		menuUtama();    // tampilan untuk memilih level dan memulai permainan
				return;
    		}

    	/*	if((x < 600 && x > 400) && (y < 420 && y > 377))
			{
        		highscore(); // halaman highsccore
    		}

    		if((x < 600 && x > 400) && (y < 472 && y > 422))
			{
    		    instruction(); // halaman instruction
    		}*/

    		if((x < 600 && x > 400) && (y < 690 && y > 590))
			{
        		exit(1);
        	}
    	}
	}
}

void menuUtama(){
	POINT CursorPosition;
    int x,y;

	while(1)
    {
    	GetCursorPos(&CursorPosition);
    	x=CursorPosition.x;
    	y=CursorPosition.y;

    	if(GetAsyncKeyState(VK_LBUTTON))
    	{
    		if((x < 352) && (x > 50) && (y < 590) && (y > 490))
			{
        		cleardevice();

				level=1;
        		SensorColor=1;
        		maze(1);
        		tampil_score();
				/*ghost g[3];
				g[0].addcolor(1);
				g[1].addcolor(2);
				g[2].addcolor(3);*/
				count=0;

				setcolor(WHITE);
				settextstyle(0,0,6);
				outtextxy(230,625,"PA");
				outtextxy(460,625,"MAN");
				setcolor(YELLOW);
				setfillstyle(1,YELLOW);
				pieslice(386,650,0,360,40);
				setcolor(0);
				setfillstyle(1,0);
				pieslice(386,650,0,20,60);
				pieslice(386,650,340,360,60);


				/*while(count<=30)
				{
					if(count==2)
					{
						setcolor(WHITE);
						settextstyle(0,0,0);
						outtextxy(360,290,"GET READY !");
					}
					else if(count==30)
					{
						setcolor(BLACK);
						outtextxy(360,290,"GET READY !");
					}
					g[0].disp_still(373,247);
					g[1].disp_still(399,247);
					g[2].disp_still(425,247);
					g[3].disp_still(451,247);
					count++;
					delay(77);
				}*/
				pellet(1);
				count=0;
				/*while(++count)
				{
					for(number=0;number<3;++number)
						g[number].gwork(295,559);
					//delay(10);
				}*/
				return;
    		}
			if((x < 660) && (x > 452) && (y < 590) && (y > 490))
			{
    		    cleardevice();

				level=2;
        		SensorColor=1;
        		maze(2);
        		tampil_score();
				/*ghost g[3];
				g[0].addcolor(1);
				g[1].addcolor(2);
				g[2].addcolor(3);*/
				count=0;

				setcolor(WHITE);
				settextstyle(0,0,6);
				outtextxy(230,625,"PA");
				outtextxy(460,625,"MAN");
				setcolor(YELLOW);
				setfillstyle(1,YELLOW);
				pieslice(386,650,0,360,40);
				setcolor(0);
				setfillstyle(1,0);
				pieslice(386,650,0,20,60);
				pieslice(386,650,340,360,60);


				while(count<=30)
				{
					if(count==2)
					{
						setcolor(WHITE);
						settextstyle(0,0,0);
						outtextxy(360,290,"GET READY !");
					}
					else if(count==30)
					{
						setcolor(BLACK);
						outtextxy(360,290,"GET READY !");
					}
				/*	g[0].disp_still(373,247);
					g[1].disp_still(399,247);
					g[2].disp_still(425,247);
					g[3].disp_still(451,247);*/
					count++;
					delay(77);
				}
				pellet(2);
				count=0;
				/*while(++count)
				{
					for(number=0;number<3;++number)
						g[number].gwork(295,559);
					//delay(10);
				}*/
        		return;
    		}
			if((x < 950) && (x > 762) && (y < 590) && (y > 490))
			{
        		cleardevice();

				level=3;
        		SensorColor=1;
        		maze(3);
        		tampil_score();
				ghost g[4];
				g[0].addcolor(1);
				g[1].addcolor(2);
				g[2].addcolor(3);
				g[3].addcolor(4);
				count=0;

				setcolor(WHITE);
				settextstyle(0,0,6);
				outtextxy(230,625,"PA");
				outtextxy(460,625,"MAN");
				setcolor(YELLOW);
				setfillstyle(1,YELLOW);
				pieslice(386,650,0,360,40);
				setcolor(0);
				setfillstyle(1,0);
				pieslice(386,650,0,20,60);
				pieslice(386,650,340,360,60);


				while(count<=30)
				{
					if(count==2)
					{
						setcolor(WHITE);
						settextstyle(0,0,0);
						outtextxy(360,290,"GET READY !");
					}
					else if(count==30)
					{
						setcolor(BLACK);
						outtextxy(360,290,"GET READY !");
					}
					g[0].disp_still(373,247);
					g[1].disp_still(399,247);
					g[2].disp_still(425,247);
					g[3].disp_still(451,247);
					count++;
					delay(77);
				}
				pellet(3);
				count=0;
				while(++count)
				{
					for(number=0;number<4;++number)
						g[number].gwork(295,559);
					//delay(10);
				}
        		return;
    		}
		}
	}
}
/*int score_pacman (int p1,int p2, int score) {
	int i,j,k;
	FILE*ds;
	ds=fopen("data_score.txt", "at+");

	//p1=10;//variabel untuk pellet kecil
	//p2=100; //variabel untuk pellet besar
	//int ghost=200;//variabel untuk musuh

	fclose(ds);
}*/

/*int score_pacman (int level,int score) {
	int i,j,k;
	FILE*ds;
	ds=fopen("data_score.txt", "at+");
	for(i=1,a<=23,a++){
        for(j=1,j<=22,j++){
        	if(level==1){
	        	if(map1[i][j]==0){
	            k=10
	        	}
	    	}
	    	else if(level==2){
	        	if(map2[i][j]==0){
	            k=10
	        	}
	   		}
	    	else if(level==3){
	        	if(map2[i][j]==0){
	            k=10
	        	}
	    	}
        }
	}
	return score;
	fclose(ds);
}*/

void tampil_score(){
    int x=0;
    rectangle(700,40,920,250);
    rectangle(720,170,900,220);
	sprintf(arr,"score : %d",x);
    outtextxy(770,188,arr);
}

int pellet(int level){
    int a,b,x,y,tempSizing;

    tempSizing = imagesize(600,600,614,614);

    readimagefile("image/ImagePellet/NormalPellet.jpg",600,600,614,614);
    pelet1 = malloc(tempSizing);
    getimage(600,600,614,614, pelet1);
    putimage(600,600,pelet1,XOR_PUT);
    //menampilkan pellet level MUDAH
    if(level==1)
    {
    	x=126, y=1;
    	for(a=0; a<23; a++)
		{
        	for(b=0; b<22; b++)
			{
            	if(map1[a][b]!=1)
				{
            	    putimage(x+7,y+7,pelet1,COPY_PUT);
            	}
           	 	x=x+26;
        	}
        	y=y+26;
        	x=126;
		}
    }
    //menampilkan pellet level SEDANG
    else if(level==2)
    {
    	x=126, y=1;
	    for(a=0; a<23; a++)
		{
	        for(b=0; b<22; b++)
			{
 	           if(map2[a][b]==0)
				{
            	    putimage(x+7,y+7,pelet1,COPY_PUT);
          		}
        	    x=x+26;
        	}
        	y=y+26;
        	x=126;
        }
    }
    //menampilkan pellet level SULIT
    else if(level==3)
    {
    	x=126, y=1;
	    for(a=0; a<23; a++)
		{
	        for(b=0; b<22; b++)
			{
 	           if(map3[a][b]==0)
				{
            	    putimage(x+7,y+7,pelet1,COPY_PUT);
          		}
        	    x=x+26;
        	}
        	y=y+26;
        	x=126;
        }
    }
    return 0;
}

int maze(int level)
{
   int a,b,x,y,tempSizing;

    tempSizing = imagesize(300,300,324,324);

    //tampil maze

    if(level == 3)
	{
    	readimagefile("image/ImageWall/wall3.jpg",300,300,324,324);
   	 	maze3 = malloc(tempSizing);
    	getimage(300,300,324,324,maze3);
    	putimage(300,300,maze3,XOR_PUT);

	    x=126, y=1;
	    for(a=0; a<23; a++)
		{
	        for(b=0; b<22; b++)
			{
 	           if(map3[a][b]!=0)
				{
    	        	setcolor(BLUE);
        	    	rectangle(x-1,y-1,x+25,y+25);//border setiap kotak wall3 buat sensor gerak
            	    putimage(x,y,maze3,COPY_PUT);
          		}
        	    x=x+26;
        	}
        	y=y+26;
        	x=126;
        }
        	setcolor(WHITE);
			line(386,221,437,221);
			setcolor(BLUE);
    }
    else if(level == 2){
    readimagefile("image/ImageWall/wall2.jpg",300,300,324,324);
    maze2 = malloc(tempSizing);
    getimage(300,300,324,324,maze2);
    putimage(300,300,maze2,XOR_PUT);

    x=126, y=1;
   	for(a=0; a<23; a++)
    {
       	for(b=0; b<22; b++)
		{
     	    if(map2[a][b]!=0)
			{
       	        setcolor(5);
       	        rectangle(x-1,y-1,x+25,y+25); //border setiap kotak untuk sensor gerak
       	        putimage(x,y,maze2,COPY_PUT);
       	    }
       	    x=x+26;
       	}
   	 	y=y+26;
       	x=126;

        //line
       	setcolor(WHITE);
        line(386,325,411,325);
        setcolor(MAGENTA);
    	}
    }
    else if(level == 1){
    readimagefile("image/ImageWall/wall1.jpg",300,300,324,324);
    maze1 = malloc(tempSizing);
    getimage(300,300,324,324,maze1);
    putimage(300,300,maze1,XOR_PUT);

    x=126, y=1;
    for(a=0; a<23; a++) {
        for(b=0; b<22; b++){
            if(map1[a][b]!=0){
                setcolor(4);
       	        rectangle(x-1,y-1,x+25,y+25); //border setiap kotak untuk sensor gerak
                putimage(x,y,maze1,COPY_PUT);
            }
            x=x+26;
        }
        y=y+26;
        x=126;
        //printf("baris = %d\n, kolom = %d\n, x = %d\n, y = %d\n",a,b,x,y);
        }
        //line
       	setcolor(WHITE);
        line(386,221,437,221);
        setcolor(RED);
    }
    return 0;
}

void ghost::inhome()
{ //KETIKA GHOST BERADA DI BASIS DAN KELUAR SATU PERSATU
	int num=rand()%6;
	if(level==1)
	{

	}
	else if (level==2)
	{

	}
	else if(level==3)
	{
		if(i_g==412)
		{
			if(num==0)
			{
				d='u';
				ioro=0;
			}
		}
		else if(i_g==373)
		{
			d='r';
		}
		else if(i_g==451)
		{
			d='l';
		}
	}
	if(ioro!=0)
	{
		moveghost(0,0);
	}
}

void ghost::moveghost(int px=0,int py=0)
{ //MENGGERAKKAN GHOST DENGAN PENAMBAHAN/PENGURANGAN KOORDINAT UNTUK MENAMPILAKAN GHOST
	setfillstyle(1,BLACK);
	setcolor(BLACK);
	bar(i_g-11,j_g-11,i_g+12,j_g+12);

	if(level==1)
	{

	}
	else if(level==2)
	{

	}
	else if(level==3)
	{
		if((j_g==208||j_g==234)&&i_g==412)
		{ //reprints the line in the entrance of their home
			setcolor(WHITE);
			line(386,221,437,221);
		}
	}

	switch(d)
	{
		case 'r': i_g++;
			break;
		case 'l': i_g--;
			break;
		case 'u': j_g--;
			break;
		case 'd': j_g++;
	}

	if(trans==1)
	{
		setfillstyle(1,BLACK);
		setcolor(BLACK);
		bar(i_g-11,j_g-11,i_g+12,j_g+12);
		if((count%10>=0)&&(count%10<=4))
		{
			if(g_no==1||(color!=5&&color!=6))
			{
				if(d=='u')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,G_up,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,B_up,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,R_up,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,P_up,COPY_PUT);
					}
				}
				else if(d=='d')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,G_down,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,B_down,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,R_down,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,P_down,COPY_PUT);
					}
				}
				else if(d=='l')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,G_left,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,B_left,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,R_left,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,P_left,COPY_PUT);
					}
				}
				else
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,G_right,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,B_right,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,R_right,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,P_right,COPY_PUT);
					}
				}
			}
			if((color==5||color==6)&&g_no==0)
			{
				if(color==5)
				{
					putimage(i_g-11,j_g-11,Dying,COPY_PUT);
				}
				else if(color==6)
				{
					if(d=='u')
					{
						putimage(i_g-11,j_g-11,E_up,COPY_PUT);
					}
					else if(d=='d')
					{
						putimage(i_g-11,j_g-11,E_down,COPY_PUT);
					}
					else if(d=='l')
					{
						putimage(i_g-11,j_g-11,E_left,COPY_PUT);
					}
					else
					{
						putimage(i_g-11,j_g-11,E_right,COPY_PUT);
					}
				}
			}
		}
		else
		{
			if(g_no==1||(color!=5&&color!=6))
			{
				if(d=='u')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,Gtrans_up,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,Btrans_up,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,Rtrans_up,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,Ptrans_up,COPY_PUT);
					}
				}
				else if(d=='d')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,Gtrans_down,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,Btrans_down,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,Rtrans_down,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,Ptrans_down,COPY_PUT);
					}
				}
				else if(d=='l')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,Gtrans_left,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,Btrans_left,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,Rtrans_left,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,Ptrans_left,COPY_PUT);
					}
				}
				else
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,Gtrans_right,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,Btrans_right,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,Rtrans_right,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,Ptrans_right,COPY_PUT);
					}
				}
			}
			if((color==5||color==6)&&g_no==0)
			{
				if(color==5)
				{
					putimage(i_g-11,j_g-11,Dyingtrans,COPY_PUT);
				}
				else if(color==6)
				{
					if(d=='u')
					{
						putimage(i_g-11,j_g-11,Etrans_up,COPY_PUT);
					}
					else if(d=='d')
					{
						putimage(i_g-11,j_g-11,Etrans_down,COPY_PUT);
					}
					else if(d=='l')
					{
						putimage(i_g-11,j_g-11,Etrans_left,COPY_PUT);
					}
					else
					{
						putimage(i_g-11,j_g-11,Etrans_right,COPY_PUT);
					}
				}
			}
		}
	}
	gleft_top=getpixel(i_g-13,j_g-13);
	gleft_mid=getpixel(i_g-13,j_g);
	gleft_bottom=getpixel(i_g-13,j_g+13);
	gright_top=getpixel(i_g+13,j_g-13);
	gright_mid=getpixel(i_g+13,j_g);
	gright_bottom=getpixel(i_g+13,j_g+13);
	gmid_top=getpixel(i_g,j_g-13);
	gmid_bottom=getpixel(i_g,j_g+13);
	/*printf("%d %d %d %d %d %d %d %d\n",gleft_top,gleft_mid,gleft_bottom,gright_top,gright_mid,gright_bottom,gmid_top,gmid_bottom);*/
}

void ghost::gmove_rand()
{ //MENGACAK PERGERAKAN GHOST DAN MELARANG GHOST BERGERAK BERLAINAN (PUTAR BALIK)
	int num2,num3;
	num2=rand()%2;
	num3=rand()%3;

	if(level==1)
	{

	}
	else if(level==2)
	{

	}
	else if(level==3)
	{
		if(i_g==412&&j_g==195)
		{
			if(d=='u')
			{
				if(num2==0)
				{
					d='r';
				}
				else
				{
					d='l';
				}
			}
		}
	}

	if((gright_top==SensorColor)&&(gright_bottom==SensorColor)&&(gleft_top==SensorColor)&&(gleft_bottom==SensorColor))
	{
		if((gleft_mid==SensorColor)&&(gright_mid==SensorColor)&&(gmid_top==SensorColor))
		{
			if(d=='u')
			{
				d='d';
			}
		}
		else if((gmid_top==SensorColor)&&(gright_mid==SensorColor)&&(gmid_bottom==SensorColor))
		{
			if(d=='r')
			{
				d='l';
			}
		}
		else if((gright_mid==SensorColor)&&(gmid_bottom==SensorColor)&&(gleft_mid==SensorColor))
		{
			if(d=='d')
			{
				d='u';
			}
		}
		else if((gmid_bottom==SensorColor)&&(gleft_mid==SensorColor)&&(gmid_top==SensorColor))
		{
			if(d=='l')
			{
				d='r';
			}
		}
		else if((gright_mid==SensorColor)&&(gmid_top==SensorColor))
		{
			if(d=='r')
			{
				d='d';
			}
			else if(d=='u')
			{
				d='l';
			}
		}
		else if((gright_mid==SensorColor)&&(gmid_bottom==SensorColor))
		{
			if(d=='d')
			{
				d='l';
			}
			else if(d=='r')
			{
				d='u';
			}
		}
		else if((gleft_mid==SensorColor)&&(gmid_top==SensorColor))
		{
			if(d=='l')
			{
				d='d';
			}
			else if(d=='u')
			{
				d='r';
			}
		}
		else if((gleft_mid==SensorColor)&&(gmid_bottom==SensorColor))
		{
			if(d=='d')
			{
				d='r';
			}
			else if(d=='l')
			{
				d='u';
			}
		}
		else if((gmid_bottom==SensorColor)&&(gmid_top==SensorColor));
		else if((gleft_mid==SensorColor)&&(gright_mid==SensorColor));
		else if(gright_mid==SensorColor)
		{
			if(d=='u'||d=='d')
			{
				if(num2==0)
				{
					d='l';
				}
			}
			else if(d=='r')
			{
				if(num2==0)
				{
					d='u';
				}
				else
				{
					d='d';
				}
			}
		}
		else if(gleft_mid==SensorColor)
		{
			if(d=='u'||d=='d')
			{
				if(num2==0)
				{
					d='r';
				}
			}
			else if(d=='l')
			{
				if(num2==0)
				{
					d='u';
				}
				else
				{
					d='d';
				}
			}
		}
		else if(gmid_top==SensorColor)
		{
			if(i_g==400&&j_g==188);
			else if(d=='u')
			{
				if(num2==0)
				{
					d='l';
				}
				else
				{
					d='r';
				}
			}
			else if(d=='l'||d=='r')
			{
				if(num2==0)
				{
					d='d';
				}
			}
		}
		else if(gmid_bottom==SensorColor)
		{
			if(d=='d')
			{
				if(num2==0)
				{
					d='l';
				}
				else
				{
					d='r';
				}
			}
			else if(d=='l'||d=='r')
			{
				if(num2==0)
				{
					d='u';
				}
			}
		}
		else
		{
			if(d=='u'||d=='d')
			{
				if(num3==0)
				{
					d='r';
				}
				else if(num3==1)
				{
					d='l';
				}
			}
			else if(d=='r'||d=='l')
			{
				if(num3==0)
				{
					d='u';
				}
				else if(num3==1)
				{
					d='d';
				}
			}
		}
	}
}

void ghost::gchase_smthin(int i,int j)
{//GHOST AKAN MENUJU KOORDINAT TERTENTU (PACMAN ATAU BASIS) DENGAN POLA ALUR TETAP RANDOM
	int x=i,y=j;

	if(level==1)
	{

	}
	else if(level==2)
	{

	}
	else if(level==3)
	{
		if(i_g==412&&j_g==195)
		{
			if(d=='u')
			{
				if(number==2)
					d='r';
				else
					d='l';
			}
		}
		else if(i_g==400&&j_g==238)
		{
			g_no=0;
			trans=1;
			if(number==0)
			{
				color=1;
			}
			else if(number==1)
			{
				color=2;
			}
			else if(number==2)
			{
				color=3;
			}
			else if(number==3)
			{
				color=4;
			}
			ioro=1;
		}
	}

	if((gright_top==SensorColor)&&(gright_bottom==SensorColor)&&(gleft_top==SensorColor)&&(gleft_bottom==SensorColor))
	{
		if((gleft_mid==SensorColor)&&(gright_mid==SensorColor)&&(gmid_top==SensorColor))
		{
			if(d=='u')
			{
				d='d';
			}
		}
		else if((gmid_top==SensorColor)&&(gright_mid==SensorColor)&&(gmid_bottom==SensorColor))
		{
			if(d=='r')
			{
				d='l';
			}
		}
		else if((gright_mid==SensorColor)&&(gmid_bottom==SensorColor)&&(gleft_mid==SensorColor))
		{
			if(d=='d')
			{
				d='u';
			}
		}
		else if((gmid_bottom==SensorColor)&&(gleft_mid==SensorColor)&&(gmid_top==SensorColor))
		{
			if(d=='l')
			{
				d='r';
			}
		}
		else if((gright_mid==SensorColor)&&(gmid_top==SensorColor))
		{
			if(d=='r')
			{
				d='d';
			}
			else if(d=='u')
			{
				d='l';
			}
		}
		else if((gright_mid==SensorColor)&&(gmid_bottom==SensorColor))
		{
			if(d=='d')
			{
				d='l';
			}
			else if(d=='r')
			{
				d='u';
			}
		}
		else if((gleft_mid==SensorColor)&&(gmid_top==SensorColor))
		{
			if(d=='l')
			{
				d='d';
			}
			else if(d=='u')
			{
				d='r';
			}
		}
		else if((gleft_mid==SensorColor)&&(gmid_bottom==SensorColor))
		{
			if(d=='d')
			{
				d='r';
			}
			else if(d=='l')
			{
				d='u';
			}
		}
		else if((gmid_bottom==SensorColor)&&(gmid_top==SensorColor));
		else if((gleft_mid==SensorColor)&&(gright_mid==SensorColor));
		else if(gright_mid==SensorColor)
		{
			if(d=='u'||d=='d')
			{
				if(i_g>x)
				{
					d='l';
				}
			}
			else if(d=='r')
			{
				if(j_g>=y)
				{
					d='u';
				}
				else if(j_g<y)
				{
					d='d';
				}
			}
		}
		else if(gleft_mid==SensorColor)
		{
			if(d=='u'||d=='d')
				{
				if(i_g<x)
				{
					d='r';
				}
			}
			else if(d=='l')
			{
				if(j_g>=y)
				{
					d='u';
				}
				else if(j_g<y)
				{
					d='d';
				}
			}
		}
		else if(gmid_top==SensorColor)
		{
			if(trans==1&&i_g==400&&j_g==188);
			else if(d=='u')
			{
				if(i_g<=x)
				{
					d='r';
				}
				else if(i_g>x)
				{
					d='l';
				}
			}
			else if(d=='l'||d=='r')
			{
				if(j_g<y)
				{
					d='d';
				}
			}
		}
		else if(gmid_bottom==SensorColor)
		{
			if(d=='l'||d=='r')
			{
				if(j_g>y)
				{
					d='u';
				}
			}
			else if(d=='d')
			{
				if(i_g>=x)
				{
					d='l';
				}
				else if(i_g<x)
				{
					d='r';
				}
			}
		}
		else
		{
			if(d=='u'||d=='d')
			{
				if(i_g<=x)
				{
					d='r';
				}
				else if(i_g>x)
				{
					d='l';
				}
			}
			else if(d=='r'||d=='l')
			{
				if(j_g>=y)
				{
					d='u';
				}
				else if(j_g<y)
				{
					d='d';
				}
			}
		}
	}
}

void ghost::gwork(int i,int j)
{//MENGATUR ALOKASI PENGGUNAAN MODUL GHOST LAINNYA
	if((color==1||color==2||color==3||color==4)&&ioro==0&&g_no==0) //KONDISI GHOST HIDUP
	{
		/*if(number== 2||(number==1&&abs(i-i_g)>50&&abs(j-j_g)>50)||(number==0&&abs(i-i_g)>100&&abs(j-j_g)>100))
			gchase_smthin(i,j);
		else*/
			gmove_rand();
	}
	else if(g_no==1&&trans==0)  //KONDISI GHOST SEKARAT
	{
		gchase_smthin(213,221);    //KOORDINAT BASIS UNTUK KEMBALI KETIKA GHOST KALAH
		moveghost();
	}
	else if(ioro==1)
		inhome();
	else if((color==5||color==6)&&ioro==0)  //KONDISI GHOST SEKARAT
	{
		if(count%2==0)
		{
			gmove_rand();
			moveghost(i,j);
		}
	}
	if(color!=5&&color!=6&&ioro==0)
		moveghost();
}

void ghost::disp_still(int xg,int yg)
{//MENAMPILKAN GHOST ATAU SPAWN GHOST
	if(level==1)
	{

	}
	else if(level==2)
	{

	}
	else if(level==3)
	{
		if(xg!=0&&yg!=0)
		{
			if(yg==188)
				ioro=0;
			i_g=xg;
			j_g=yg;
		}
	}

	setfillstyle(1,BLACK);
	setcolor(BLACK);
	bar(i_g-11,j_g-11,i_g+10,j_g+10);
	if(trans==1)
	{
		if(count%2!=0)
		{
			if(g_no==1||(color!=5&&color!=6))
			{
				if(d=='u')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,G_up,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,B_up,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,R_up,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,P_up,COPY_PUT);
					}
				}
				else if(d=='d')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,G_down,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,B_down,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,R_down,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,P_down,COPY_PUT);
					}
				}
				else if(d=='l')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,G_left,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,B_left,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,R_left,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,P_left,COPY_PUT);
					}
				}
				else
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,G_right,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,B_right,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,R_right,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,P_right,COPY_PUT);
					}
				}
			}
			if((color==5||color==6)&&g_no==0)
			{
				if(color==5)
				{
					putimage(i_g-11,j_g-11,Dying,COPY_PUT);
				}
				else if(color==6)
				{
					if(d=='u')
					{
						putimage(i_g-11,j_g-11,E_up,COPY_PUT);
					}
					else if(d=='d')
					{
						putimage(i_g-11,j_g-11,E_down,COPY_PUT);
					}
					else if(d=='l')
					{
						putimage(i_g-11,j_g-11,E_left,COPY_PUT);
					}
					else
					{
						putimage(i_g-11,j_g-11,E_right,COPY_PUT);
					}
				}
			}
		}
		else if(count%2==0)
		{
			if(g_no==1||(color!=5&&color!=6))
			{
				if(d=='u')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,Gtrans_up,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,Btrans_up,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,Rtrans_up,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,Ptrans_up,COPY_PUT);
					}
				}
				else if(d=='d')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,Gtrans_down,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,Btrans_down,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,Rtrans_down,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,Ptrans_down,COPY_PUT);
					}
				}
				else if(d=='l')
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,Gtrans_left,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,Btrans_left,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,Rtrans_left,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,Ptrans_left,COPY_PUT);
					}
				}
				else
				{
					if(color==1)
					{
						putimage(i_g-11,j_g-11,Gtrans_right,COPY_PUT);
					}
					else if(color==2)
					{
						putimage(i_g-11,j_g-11,Btrans_right,COPY_PUT);
					}
					else if(color==3)
					{
						putimage(i_g-11,j_g-11,Rtrans_right,COPY_PUT);
					}
					else if(color==4)
					{
						putimage(i_g-11,j_g-11,Ptrans_right,COPY_PUT);
					}
				}
			}
			if((color==5||color==6)&&g_no==0)
			{
				if(color==5)
				{
					putimage(i_g-11,j_g-11,Dyingtrans,COPY_PUT);
				}
				else if(color==6)
				{
					if(d=='u')
					{
						putimage(i_g-11,j_g-11,Etrans_up,COPY_PUT);
					}
					else if(d=='d')
					{
						putimage(i_g-11,j_g-11,Etrans_down,COPY_PUT);
					}
					else if(d=='l')
					{
						putimage(i_g-11,j_g-11,Etrans_left,COPY_PUT);
					}
					else
					{
						putimage(i_g-11,j_g-11,Etrans_right,COPY_PUT);
					}
				}
			}
		}
	}
}

void g_alloc()
{//MODUL UNTUK MENJADIKAN GAMBAR GHOST SEBAGAI BUFFER
	int X1=976,Y1=676,area,X2=X1+22,Y2=Y1+22;

	//			HANTU HIJAU (GREEN)
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/hijau kanan.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	G_right=malloc(area);
	getimage(X1,Y1,X2,Y2,G_right);
	putimage(X1,Y1,G_right,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/hijau kanan trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Gtrans_right=malloc(area);
	getimage(X1,Y1,X2,Y2,Gtrans_right);
	putimage(X1,Y1,Gtrans_right,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/hijau kiri.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	G_left=malloc(area);
	getimage(X1,Y1,X2,Y2,G_left);
	putimage(X1,Y1,G_left,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/hijau kiri trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Gtrans_left=malloc(area);
	getimage(X1,Y1,X2,Y2,Gtrans_left);
	putimage(X1,Y1,Gtrans_left,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/hijau atas.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	G_up=malloc(area);
	getimage(X1,Y1,X2,Y2,G_up);
	putimage(X1,Y1,G_up,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/hijau atas trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Gtrans_up=malloc(area);
	getimage(X1,Y1,X2,Y2,Gtrans_up);
	putimage(X1,Y1,Gtrans_up,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/hijau bawah.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	G_down=malloc(area);
	getimage(X1,Y1,X2,Y2,G_down);
	putimage(X1,Y1,G_down,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/hijau bawah trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Gtrans_down=malloc(area);
	getimage(X1,Y1,X2,Y2,Gtrans_down);
	putimage(X1,Y1,Gtrans_down,XOR_PUT);
	//////////////////////////////////////////////

	//			HANTU MERAH (RED)
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/merah kanan.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	R_right=malloc(area);
	getimage(X1,Y1,X2,Y2,R_right);
	putimage(X1,Y1,R_right,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/merah kanan trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Rtrans_right=malloc(area);
	getimage(X1,Y1,X2,Y2,Rtrans_right);
	putimage(X1,Y1,Rtrans_right,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/merah kiri.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	R_left=malloc(area);
	getimage(X1,Y1,X2,Y2,R_left);
	putimage(X1,Y1,R_left,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/merah kiri trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Rtrans_left=malloc(area);
	getimage(X1,Y1,X2,Y2,Rtrans_left);
	putimage(X1,Y1,Rtrans_left,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/merah atas.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	R_up=malloc(area);
	getimage(X1,Y1,X2,Y2,R_up);
	putimage(X1,Y1,R_up,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/merah atas trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Rtrans_up=malloc(area);
	getimage(X1,Y1,X2,Y2,Rtrans_up);
	putimage(X1,Y1,Rtrans_up,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/merah bawah.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X1+25,Y1+25);

	R_down=malloc(area);
	getimage(X1,Y1,X2,Y2,R_down);
	putimage(X1,Y1,R_down,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/merah bawah trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X1+25,Y1+25);

	Rtrans_down=malloc(area);
	getimage(X1,Y1,X2,Y2,Rtrans_down);
	putimage(X1,Y1,Rtrans_down,XOR_PUT);
	//////////////////////////////////////////////

	//			HANTU UNGU (PURPLE)
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/ungu kanan.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	P_right=malloc(area);
	getimage(X1,Y1,X2,Y2,P_right);
	putimage(X1,Y1,P_right,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/ungu kanan trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Ptrans_right=malloc(area);
	getimage(X1,Y1,X2,Y2,Ptrans_right);
	putimage(X1,Y1,Ptrans_right,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/ungu kiri.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	P_left=malloc(area);
	getimage(X1,Y1,X2,Y2,P_left);
	putimage(X1,Y1,P_left,XOR_PUT);
		//////////////////////////////////////////////
	readimagefile("image/ImageGhost/ungu kiri trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Ptrans_left=malloc(area);
	getimage(X1,Y1,X2,Y2,Ptrans_left);
	putimage(X1,Y1,Ptrans_left,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/ungu atas.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	P_up=malloc(area);
	getimage(X1,Y1,X2,Y2,P_up);
	putimage(X1,Y1,P_up,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/ungu atas trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Ptrans_up=malloc(area);
	getimage(X1,Y1,X2,Y2,Ptrans_up);
	putimage(X1,Y1,Ptrans_up,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/ungu bawah.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	P_down=malloc(area);
	getimage(X1,Y1,X2,Y2,P_down);
	putimage(X1,Y1,P_down,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/ungu bawah trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Ptrans_down=malloc(area);
	getimage(X1,Y1,X2,Y2,Ptrans_down);
	putimage(X1,Y1,Ptrans_down,XOR_PUT);
	//////////////////////////////////////////////

	//			HANTU BIRU (BLUE)
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/biru kanan.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	B_right=malloc(area);
	getimage(X1,Y1,X2,Y2,B_right);
	putimage(X1,Y1,B_right,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/biru kanan trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Btrans_right=malloc(area);
	getimage(X1,Y1,X2,Y2,Btrans_right);
	putimage(X1,Y1,Btrans_right,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/biru kiri.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	B_left=malloc(area);
	getimage(X1,Y1,X2,Y2,B_left);
	putimage(X1,Y1,B_left,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/biru kiri trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Btrans_left=malloc(area);
	getimage(X1,Y1,X2,Y2,Btrans_left);
	putimage(X1,Y1,Btrans_left,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/biru atas.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	B_up=malloc(area);
	getimage(X1,Y1,X2,Y2,B_up);
	putimage(X1,Y1,B_up,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/biru atas trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Btrans_up=malloc(area);
	getimage(X1,Y1,X2,Y2,Btrans_up);
	putimage(X1,Y1,Btrans_up,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/biru bawah.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	B_down=malloc(area);
	getimage(X1,Y1,X2,Y2,B_down);
	putimage(X1,Y1,B_down,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/biru bawah trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Btrans_down=malloc(area);
	getimage(X1,Y1,X2,Y2,Btrans_down);
	putimage(X1,Y1,Btrans_down,XOR_PUT);
	//////////////////////////////////////////////

	//			HANTU SEKARAT (DYING)
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/sekarat.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Dying=malloc(area);
	getimage(X1,Y1,X2,Y2,Dying);
	putimage(X1,Y1,Dying,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/sekarat trans.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	Dyingtrans=malloc(area);
	getimage(X1,Y1,X2,Y2,Dyingtrans);
	putimage(X1,Y1,Dyingtrans,XOR_PUT);
	//////////////////////////////////////////////

	//			MATA HANTU (EYE)
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/mata kanan.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	E_right=malloc(area);
	getimage(X1,Y1,X2,Y2,E_right);
	putimage(X1,Y1,E_right,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/mata kiri.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	E_left=malloc(area);
	getimage(X1,Y1,X2,Y2,E_left);
	putimage(X1,Y1,E_left,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/mata atas.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	E_up=malloc(area);
	getimage(X1,Y1,X2,Y2,E_up);
	putimage(X1,Y1,E_up,XOR_PUT);
	//////////////////////////////////////////////
	readimagefile("image/ImageGhost/mata bawah.jpg",X1,Y1,X2,Y2);
	area=imagesize(X1,Y1,X2,Y2);

	E_down=malloc(area);
	getimage(X1,Y1,X2,Y2,E_down);
	putimage(X1,Y1,E_down,XOR_PUT);
	//////////////////////////////////////////////
}

void sprite_pacman(){
    int area, tempsizing;
    tempsizing = imagesize(300,300,322,322);

    // Pacman arah Kanan //
    readimagefile("PacmanRight.jpg",300,300,322,322);   //pacman dengan mulut terbuka
    pkanan = malloc(tempsizing);
    getimage(300,300,322,322,pkanan);
    putimage(300,300,pkanan,XOR_PUT);

    readimagefile("Pacman.jpg",300,300,322,322);        //pacman dengan mulut tertutup
    pbulat1 = malloc(tempsizing);
    getimage(300,300,322,322,pbulat1);
    putimage(300,300,pbulat1,XOR_PUT);

    // Pacman arah Kiri //
    readimagefile("PacmanLeft.jpg",300,300,322,322);   //pacman dengan mulut terbuka
    pkiri = malloc(tempsizing);
    getimage(300,300,322,322,pkiri);
    putimage(300,300,pkiri,XOR_PUT);

    readimagefile("Pacman.jpg",300,300,322,322);        //pacman dengan mulut tertutup
    pbulat2 = malloc(tempsizing);
    getimage(300,300,322,322,pbulat2);
    putimage(300,300,pbulat2,XOR_PUT);

    // Pacman arah Atas //
    readimagefile("PacmanUp.jpg",300,300,322,322);      //pacman dengan mulut terbuka
    patas = malloc(tempsizing);
    getimage(300,300,322,322,patas);
    putimage(300,300,patas,XOR_PUT);

    readimagefile("Pacman.jpg",300,300,322,322);        //pacman dengan mulut tertutup
    pbulat3 = malloc(tempsizing);
    getimage(300,300,322,322,pbulat3);
    putimage(300,300,pbulat3,XOR_PUT);

    // Pacman arah Bawah //
    readimagefile("PacmanDown.jpg",300,300,322,322);    //pacman dengan mulut terbuka
    pbawah = malloc(tempsizing);
    getimage(300,300,322,322,pbawah);
    putimage(300,300,pbawah,XOR_PUT);

    readimagefile("Pacman.jpg",300,300,322,322);         //pacman dengan mulut tertutup
    pbulat4 = malloc(tempsizing);
    getimage(300,300,322,322,pbulat4);
    putimage(300,300,pbulat4,XOR_PUT);

}

void pacman_kanan(int x, int y){
    putimage(x,y,pkanan,XOR_PUT);
    delay(500);
    putimage(x,y,pbulat1,XOR_PUT);
    delay(500);

}

void pacman_kiri(int x, int y){
    putimage(x,y,pkiri,XOR_PUT);
    delay(500);
    putimage(x,y,pbulat2,XOR_PUT);
    delay(500);

}

void pacman_atas(int x, int y){
    putimage(x,y,patas,XOR_PUT);
    delay(500);
    putimage(x,y,pbulat3,XOR_PUT);
    delay(500);

}

void pacman_bawah(int x,int y){
    putimage(x,y,pbawah,XOR_PUT);
    delay(500);
    putimage(x,y,pbulat4,XOR_PUT);
    delay(500);
}

void arah_pacman(int dir, int x, int y){
    if(dir == 1){
        pacman_kanan(x,y);
    }
    else if(dir == 2){
        pacman_kiri(x,y);
    }
    else if(dir == 3){
        pacman_atas(x,y);
    }
    else if(dir == 4){
        pacman_bawah(x,y);
    }
}

void move_pacman(){
    int id, dir;
    int x = 26, y = 25;
    int a, b;

    putimage(x,y,pkanan,XOR_PUT);
    delay(500);
    swapbuffers();

        if(map1[a][b]==0){
            if(GetAsyncKeyState(VK_RIGHT)){
                id = 1;
            }else if(GetAsyncKeyState(VK_LEFT)){
                id = 2;
            }else if(GetAsyncKeyState(VK_UP)){
                id = 3;
            }else if(GetAsyncKeyState(VK_DOWN)){
                id = 4;
            }else{
                id = 0;
            }
            switch(id){
            case 0 :
                if(dir == 1){
                    swapbuffers();
                    dir = 1;
                    x = x+22;
                    arah_pacman(1,x,y);
                    b++;
                    break;
                }else if(dir == 2){
                    swapbuffers();
                    dir = 2;
                    x = x-22;
                    arah_pacman(2,x,y);
                    b--;
                    break;
                }else if(dir == 3){
                    swapbuffers();
                    dir = 3;
                    y = y-22;
                    arah_pacman(3,x,y);
                    a--;
                    break;
                }else if(dir == 4){
                    swapbuffers();
                    dir = 4;
                    y = y+22;
                    arah_pacman(4,x,y);
                    a++;
                    break;}
            case 1 :
                    swapbuffers();
                    dir = 1;
                    x = x+22;
                    arah_pacman(1,x,y);
                    b++;
                    break;
            case 2 :
                    swapbuffers();
                    dir = 3;
                    x = x-22;
                    arah_pacman(3,x,y);
                    b--;
                    break;
            case 3 :
                    swapbuffers();
                    dir = 3;
                    y = y-22;
                    arah_pacman(3,x,y);
                    a--;
                    break;
            case 4 :
                    swapbuffers();
                    dir = 4;
                    y = y+22;
                    arah_pacman(4,x,y);
                    a++;
                    break;
                }
            }
        else if(map2[a][b] == 0){
            if(GetAsyncKeyState(VK_RIGHT)){
                id = 1;
            }else if(GetAsyncKeyState(VK_LEFT)){
                id = 2;
            }else if(GetAsyncKeyState(VK_UP)){
                id = 3;
            }else if(GetAsyncKeyState(VK_DOWN)){
                id = 4;
            }else{
                id = 0;
            }
            switch(id){
            case 0 :
                if(dir == 1){
                    swapbuffers();
                    dir = 1;
                    x = x+22;
                    arah_pacman(1,x,y);
                    b++;
                    break;
                }else if(dir == 2){
                    swapbuffers();
                    dir = 2;
                    x = x-22;
                    arah_pacman(2,x,y);
                    b--;
                    break;
                }else if(dir == 3){
                    swapbuffers();
                    dir = 3;
                    y = y-22;
                    arah_pacman(3,x,y);
                    a--;
                    break;
                }else if(dir == 4){
                    swapbuffers();
                    dir = 4;
                    y = y+22;
                    arah_pacman(4,x,y);
                    a++;
                    break;}
            case 1 :
                    swapbuffers();
                    dir = 1;
                    x = x+22;
                    arah_pacman(1,x,y);
                    b++;
                    break;
            case 2 :
                    swapbuffers();
                    dir = 2;
                    y = y-22;
                    arah_pacman(2,x,y);
                    b--;
                    break;
            case 3 :
                    swapbuffers();
                    dir = 3;
                    y = y-22;
                    arah_pacman(3,x,y);
                    a--;
                    break;
            case 4 :
                    swapbuffers();
                    dir = 4;
                    y = y+22;
                    arah_pacman(4,x,y);
                    a++;
                    break;
                }
            }
        else if(map3[a][b] == 0){
            if(GetAsyncKeyState(VK_RIGHT)){
                id = 1;
            }else if(GetAsyncKeyState(VK_LEFT)){
                id = 2;
            }else if(GetAsyncKeyState(VK_UP)){
                id = 3;
            }else if(GetAsyncKeyState(VK_DOWN)){
                id = 4;
            }else{
                id = 0;
            }
            switch(id){
            case 0 :
                if(dir == 1){
                    swapbuffers();
                    dir = 1;
                    x = x+22;
                    arah_pacman(1,x,y);
                    b++;
                    break;
                }else if(dir == 2){
                    swapbuffers();
                    dir = 2;
                    x = x-22;
                    arah_pacman(2,x,y);
                    b--;
                    break;
                }else if(dir == 3){
                    swapbuffers();
                    dir = 3;
                    y = y-22;
                    arah_pacman(3,x,y);
                    a--;
                    break;
                }else if(dir == 4){
                    swapbuffers();
                    dir = 4;
                    y = y+22;
                    arah_pacman(4,x,y);
                    a++;
                    break;}
            case 1 :
                    swapbuffers();
                    dir = 1;
                    x = x+22;
                    arah_pacman(1,x,y);
                    b++;
                    break;
            case 2 :
                    swapbuffers();
                    dir = 2;
                    x = x-22;
                    arah_pacman(2,x,y);
                    b--;
                    break;
            case 3 :
                    swapbuffers();
                    dir = 3;
                    y = y-22;
                    arah_pacman(3,x,y);
                    a--;
                    break;
            case 4 :
                    swapbuffers();
                    dir = 4;
                    y = y+22;
                    arah_pacman(4,x,y);
                    a++;
                    break;
                }
        }
    }
