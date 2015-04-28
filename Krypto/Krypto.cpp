// Krypto.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#define test
#define testplus
#define testmal
//#define testexp
//#define testsquare

Gruppenpunkt calcB(Gruppenpunkt a, Gruppenpunkt x1)
{
	return ((x1 ^ 3) + (a*x1)).Negativ();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Gruppenpunkt::setPrim(/*8191*/127);
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
#ifdef testexp
	//Test des *
	printf("^ Test\n");
	for (int i = 1; i < Gruppenpunkt::getPrim(); i++)
	{
		Gruppenpunkt r = Gruppenpunkt(i) ^ (Gruppenpunkt::getPrim() - 1);
		if (r.zahl != 1)
		{
			if (r.Negativ().zahl != 1)
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
	b.print();

	system("pause");
}

