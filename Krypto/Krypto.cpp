// Krypto.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Gruppenpunkt::setPrim(29);
	Gruppenpunkt g = Gruppenpunkt(6);
	Gruppenpunkt p = Gruppenpunkt(3);
	(g.ModMal(p)).print();
	(g*p).print();
	//g.Negativ().print();

	/*(g + p).print();
	printf("Ueberpruefung via modulo: ");
	g.ModPlus(p).print();
	printf("Ueberpruefung via modulo: ");
	g.ModPlus(p).Negativ().print();*/

	system("pause");
}

