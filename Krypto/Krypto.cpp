// Krypto.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Gruppenpunkt::setPrim(127);
	Gruppenpunkt g = Gruppenpunkt(50);
	Gruppenpunkt p = Gruppenpunkt(80);

	(g + p).print();
	printf("Ueberpruefung via modulo: ");
	g.ModPlus(p).print();
	printf("Ueberpruefung via modulo: ");
	g.ModPlus(p).Negativ().print();

	system("pause");
}

