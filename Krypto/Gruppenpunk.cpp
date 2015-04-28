#include "stdafx.h"
#include "Gruppenpunk.h"

unsigned int Gruppenpunkt::prim;
unsigned int Gruppenpunkt::sqrtPrim;
Gruppenpunkt::Gruppenpunkt()
{
}

Gruppenpunkt::Gruppenpunkt(unsigned int value)
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
	if ((zahl >= ((prim + 1)/2)) && (a.zahl >= ((prim + 1)/2))) 
		return ((*this).Negativ()*a.Negativ());
	if (zahl >= ((prim + 1)/2)) 
		return (*this).Negativ()*a;
	if (a.zahl >= ((prim + 1)/2)) 
		return (*this)*a.Negativ();
	if (zahl > sqrtPrim)
	{
		unsigned int test = sqrtPrim * a.zahl;
		Gruppenpunkt c = Gruppenpunkt(test);
		Gruppenpunkt d = Gruppenpunkt((zahl - sqrtPrim)*a.zahl);
		return c+d;
	}
}

Gruppenpunkt Gruppenpunkt::ModMal(Gruppenpunkt &a)
{
	return Gruppenpunkt((zahl*a.zahl) % prim);
}

Gruppenpunkt Gruppenpunkt::div2()
{
	if ((zahl & 1) == 0) return zahl >> 1;
	else return ((zahl^prim) >> 1) ^ prim;
}

void Gruppenpunkt::print()
{
	printf("Gruppenzahl: %u", zahl);
	printf("\n");
}

void Gruppenpunkt::setPrim(unsigned int value)
{
	prim = value;
	sqrtPrim = 5;
}

unsigned int Gruppenpunkt::getPrim()
{
	return prim;
}
