// Krypto.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

//#define test
#define testplus
#define testmal
#define testdiv
#define testexp
#define testsquare

int kgv(int a, int b)
{
	int tmp = a;
	for (int index = 1; (tmp % b); index++)
	{
		tmp = a * index;
	}
	return tmp;
}

Gruppenpunkt calcB(Gruppenpunkt a, Gruppenpunkt x1)
{
	return ((x1 ^ 3) + (a*x1)).Negativ();
}

Gruppenpunkt kurve(Gruppenpunkt x, Gruppenpunkt a, Gruppenpunkt b)
{
	return (x ^ 3) + x*a + b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Gruppenpunkt::setPrim(/*8191*/127);
	//Gruppenpunkt::setPrim(7);
#ifdef test
#ifdef testplus
	//Test des +
	printf("+ Test\n");
	for (int i = 0; i < Gruppenpunkt::getPrim(); i++)
	{
		Gruppenpunkt g = Gruppenpunkt(i);
		for (int j = 0; j < Gruppenpunkt::getPrim(); j++)
		{
			Gruppenpunkt p = Gruppenpunkt(j);
			Gruppenpunkt ergebnis = p + g;
			Gruppenpunkt modErgebnis = p.ModPlus(g);
			if (ergebnis.zahl != modErgebnis.zahl)
			{
				printf("fehler at i=%d j=%d\n", i, j);
			}
		}
	}
#endif
#ifdef testmal
	//Test des *
	printf("* Test\n");
	for (int i = 0; i < Gruppenpunkt::getPrim(); i++)
	{
		Gruppenpunkt g = Gruppenpunkt(i);
		for (int j = 0; j < Gruppenpunkt::getPrim(); j++)
		{
			Gruppenpunkt p = Gruppenpunkt(j);
			Gruppenpunkt ergebnis = p * g;
			Gruppenpunkt modErgebnis = p.ModMal(g);
			if ((ergebnis.zahl != modErgebnis.zahl))
			{
				printf("fehler at i=%d j=%d\n", i, j);
			}
		}
	}
#endif
#ifdef testdiv
	//Test des /
	printf("/ Test\n");
	for (int i = 1; i < Gruppenpunkt::getPrim(); i++)
	{
		Gruppenpunkt g = Gruppenpunkt(i);
		for (int j = 1; j < Gruppenpunkt::getPrim(); j++)
		{
			Gruppenpunkt p = Gruppenpunkt(j);
			Gruppenpunkt ergebnis = p / g;
			Gruppenpunkt modErgebnis = ergebnis*g;
			if ((p.zahl != modErgebnis.zahl))
			{
				printf("fehler at i=%d j=%d\n", i, j);
			}
		}
	}
#endif
#ifdef testexp
	//Test des *
	printf("^ Test\n");
	for (int i = 1; i < Gruppenpunkt::getPrim(); i++)
	{
		Gruppenpunkt r = Gruppenpunkt(i) ^ (Gruppenpunkt::getPrim() - 1);
		if (r.zahl != 1)
		{
			printf("fehler at i=%u\n", i);
		}
	}
#endif
#ifdef testsquare
	//Test des isSquare
	printf("isSquare Test\n");
	int s = 0;
	for (int i = 0; i < Gruppenpunkt::getPrim(); i++)
	{
		if (Gruppenpunkt(i).isSquare())
		{
			s++;
			printf("%d is Square\n", i);
		}
	}
	printf("Es gibt %d Squares.\n", s);
#endif
#endif
	Gruppenpunkt a, b, x1;
	a = Gruppenpunkt(3);
	x1 = Gruppenpunkt(2);
	b = calcB(a, x1);
	a = Gruppenpunkt(4);
	b = Gruppenpunkt(20%Gruppenpunkt::getPrim());
	if (((4 * a.zahl*a.zahl*a.zahl + 27 * b.zahl*b.zahl) % Gruppenpunkt::getPrim())==0)
	{
		printf("a und b sind doof!");
		system("pause");
		return 0;
	}
	
	int anzahl = 0;

	for (int i = 0; i < Gruppenpunkt::getPrim(); i++)
	{
		Gruppenpunkt y = kurve(i, a, b);
		if (y.isSquare())
		{
			Gruppenpunkt r = y.root();
			//printf("%d %d\n", y.zahl, r.zahl);
			if (r.zahl == 0)
			{
				printf("X:%d Y:%d\n", i, r.zahl);
				anzahl++;
			}
			else
			{
				printf("X:%d Y:%d -Y:%d\n", i, r.zahl,r.Negativ().zahl);
				anzahl += 2;
			}
		}
	}
	Kurvenpunkt *tabelle = new Kurvenpunkt[anzahl];
	int index = 0;
	for (int i = 0; i < Gruppenpunkt::getPrim(); i++)
	{
		Gruppenpunkt y = kurve(i, a, b);
		if (y.isSquare())
		{
			Gruppenpunkt r = y.root();
			//printf("%d %d\n", y.zahl, r.zahl);
			if (r.zahl != 0)
			{
				tabelle[index] = Kurvenpunkt(Gruppenpunkt(i),r);
				index = index + 1;
				tabelle[index] = Kurvenpunkt(Gruppenpunkt(i), r.Negativ());
				index = index +1;
			}
			else
			{
				tabelle[index] = Kurvenpunkt(Gruppenpunkt(i), r);
				index = index +1;
			}
		}
	}
	printf("anzahl:%d\n", anzahl);
	printf("\n\n");
	//for (int i = 0; i < 10/*Gruppenpunkt::getPrim()*/; i++)
	//{
	//	printf("(%d,%d):\n", tabelleX[i].zahl, tabelleY[i].zahl);
	//	for (int j = 0; j < 10/*Gruppenpunkt::getPrim()*/; j++)
	//	{
	//		Gruppenpunkt x, y;
	//		kpKp(tabelleX[i], tabelleY[i], tabelleX[j], tabelleY[j], &x, &y, a);
	//		printf(" +(%d,%d)=(%d, %d)\n",tabelleX[j].zahl,tabelleY[j].zahl, x.zahl, y.zahl);
	//	}
	//	printf("\n\n");
	//}
	Kurvenpunkt::ka = a;
	int alterKGV = 1;
	for (int i = 0; i < anzahl; i++)
	{
		Kurvenpunkt a, tmp;
		a = tabelle[i];
		tmp = a;
		int tAnz = 0;
		//printf("Berechne Punkt: ");
		//a.print();
		do
		{
			if (tmp.y == Gruppenpunkt(Gruppenpunkt::getPrim()))
			{
				break;
			}
			tAnz++;
			tmp = a + tmp;
			//tmp.print();
		} while (!(tmp == a));
		printf("(%d,%d) %d\n", tabelle[i].x.zahl, tabelle[i].y.zahl, tAnz);
		alterKGV = kgv(alterKGV, tAnz);
	}
	printf("#: %d\n", alterKGV);
	system("pause");
}

