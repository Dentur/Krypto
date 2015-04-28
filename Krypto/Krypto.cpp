// Krypto.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#define test;

int _tmain(int argc, _TCHAR* argv[])
{
	Gruppenpunkt::setPrim(8191);
#ifdef test
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
				if (ergebnis.zahl != modErgebnis.Negativ().zahl)
				{

					printf("fehler at i=%d j=%d\n", i, j);
				}
			}
		}
	}
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
			if ((ergebnis.zahl != modErgebnis.zahl) && (ergebnis.zahl != modErgebnis.Negativ().zahl))
			{
				printf("fehler at i=%d j=%d\n", i, j);
			}
		}
	}
#endif
	system("pause");
}

