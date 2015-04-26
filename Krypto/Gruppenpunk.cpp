#include "stdafx.h"
#include "Gruppenpunk.h"

unsigned long long Gruppenpunkt::prim;
unsigned long long Gruppenpunkt::sqrtPrim;
Gruppenpunkt::Gruppenpunkt()
{
}

Gruppenpunkt::Gruppenpunkt(unsigned long long value)
{
	zahl = value;
}


Gruppenpunkt::~Gruppenpunkt()
{
}

Gruppenpunkt Gruppenpunkt::operator+(Gruppenpunkt &a)
{
	if (zahl < (a.zahl^prim))
		return Gruppenpunkt(zahl + a.zahl);
	else
	{
		if (zahl <= a.zahl) return((zahl - (a.zahl^prim)) ^ prim);
		else return ((a.zahl - (zahl^prim)) ^ prim);
	}
}

Gruppenpunkt Gruppenpunkt::ModPlus(Gruppenpunkt &a)
{
	return (zahl + a.zahl) % prim;
}

Gruppenpunkt Gruppenpunkt::Negativ()
{
	return zahl^prim;
}

Gruppenpunkt Gruppenpunkt::operator*(Gruppenpunkt &a)
{
	if ((zahl >= ((prim + 1) >> 1)) && (a.zahl >= ((prim + 1) >> 1))) return ((*this).Negativ()*a.Negativ());
	if (zahl >= ((prim + 1) >> 1)) return (*this).Negativ()*a;
	if (a.zahl >= ((prim + 1) >> 1)) return (*this)*a.Negativ();
	//if (zahl >= sqrtPrim) return 
}

Gruppenpunkt Gruppenpunkt::div2()
{
	if ((zahl & 1) == 0) return zahl >> 1;
	else return ((zahl^prim) >> 1) ^ prim;
}

void Gruppenpunkt::print()
{
	printf("Gruppenzahl: %lld", zahl);
	printf("\n");
}

void Gruppenpunkt::setPrim(unsigned long long value)
{
	prim = value;
	sqrtPrim = 1;
}

unsigned long long Gruppenpunkt::getPrim()
{
	return prim;
}
