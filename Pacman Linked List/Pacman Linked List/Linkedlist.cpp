/* File        : bodylist.c */
/* Deskripsi   : Body ADT Linked list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */

#include <stdio.h>
#include <malloc.h>
#include "Linkedlist.hpp"

boolean ListEmpty (List L)
{
	 return (First(L) == Nil);
}

void CreateList (List * L)
{
	 First(*L) = Nil;
}

address Alokasi (infotype X)
{
    address P;

    P = (address) malloc (sizeof (ElmtList));
    if (P != Nil)		/* Alokasi berhasil */
    {
        Info(P) = X;
        Next(P) = Nil;
        baris(P) = Nil;
    }
    return (P);
}

void DeAlokasi (address P)
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

void InsVFirst (List * L, infotype X)
{
	address P;

	P = Alokasi (X);
	if (P != Nil)
	{	InsertFirst (&(*L), P);		}
}

void InsVLast (List * L, infotype X)
{
	address P;

	P = Alokasi (X);
	if (P != Nil)
	{	InsertLast (&(*L), P);		}
}

void DelVFirst (List * L, infotype * X)
{
	address P;

	P = First(*L);
		  *X = Info(P);
	First(*L) = Next(First(*L));
	DeAlokasi (P);
}

void DelVLast (List * L, infotype * X)
{
	address PDel;

	PDel = First(*L);
	DelLast (&(*L), &PDel);
	(*X) = Info(PDel);
	DeAlokasi (PDel);
}

void InsertFirst (List * L, address P)
{
	 Next(P) = First(*L);
	 First(*L) = P;
}

void InsertAfter (List * L, address P, address Prec)
{
	 Next(P) = Next(Prec);
	 Next(Prec) = P;
}

void InsertLast (List * L, address P)
{
	address Last;

	if (First(*L) != Nil)
	{
		 Last = First(*L);
		 while (Next(Last) != Nil)
		 {	Last = Next(Last); 	}
		 Next(Last) = P;
	}
		else
	{	First(*L) = P;		}
}

void DelFirst (List * L, address * P)
{
	 *P = First(*L);
	 First(*L) = Next(First(*L));
}


void DelP (List * L, infotype X)
{
	address P, Prec;
	boolean found=false;

    Prec = Nil;
	P = First(*L);
	while ((P != Nil) && (!found))
	{
		 if (Info(P) == X)
		 {	found = true;	}
		 else
		 {
		Prec = P;
		P = Next(P);
		 }
	}

	if (found)
	{
		 if (Prec == Nil && Next(P) == Nil)		/* Hanya 1 elemen */
		 {	First(*L) = Nil;	}
		 else if (Prec == Nil)			/* Ketemu di elemen 1*/
		 {	First(*L) = Next(P);	}
		 else		/* Ketemu di elemen list yang ditengah/akhir */
		 {	Next(Prec) = Next(P);	}
		 Next(P) = Nil;
		 DeAlokasi (P);
	}
}

void DelLast (List * L, address * P)
{
	address Prec;

	*P = First(*L);
	Prec = Nil;
	while (Next(*P) != Nil)
	{
		 Prec = *P;
		 *P = Next (*P);
	}

	if (Prec == Nil)	/* Hanya 1 elemen */
	{	First(*L) = Nil;	}
	else	/* List Lebih dari 1 elemen */
	{	Next(Prec) = Nil;	}
}

void DelAfter (List * L, address * Pdel, address Prec)
{
	 *Pdel = Next(Prec);
	 if (Pdel != Nil)
	 {
	Next(Prec) = Next(*Pdel);
	Next(*Pdel) = Nil;
	 }
}

void PrintInfo (List L)
{
	address P;

	if (First(L) == Nil)
	{
		 printf ("List Kosong .... \a\n");
	}
	else	/* List memiliki elemen */
	{
		 P = First(L);
		 for (;;)
		 {
		if (P == Nil)
		{
			 printf("\n");
			 break;
		}
		else	/* Belum berada di akhir List */
		{
			 printf ("%d ", Info(P));
			 P = Next(P);
		}
		 }
	}
}


void DelAll (List * L)
{
	address PDel;

	PDel = First(*L);
	while (PDel != Nil)
	{
		 DelFirst (&(*L), &PDel);
		 DeAlokasi (PDel);
		 PDel = First(*L);
	}
}
