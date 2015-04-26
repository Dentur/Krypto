#include "stdafx.h"
#include "Gruppenpunk.h"

unsigned long long Gruppenpunkt::prim;
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

Gruppenpunkt Gruppenpunkt::operator+(const Gruppenpunkt &a)
{
	if (zahl < (a.zahl^prim))
		return Gruppenpunkt(zahl + a.zahl);
	else
	{
		if (zahl <= a.zahl) return((zahl - (a.zahl^prim)) ^ prim);
		else return ((a.zahl - (zahl^prim)) ^ prim);
	}
}

void Gruppenpunkt::print()
{
	printf("Gruppenzahl: %lld", zahl);
	printf("\n");
}

void Gruppenpunkt::setPrim(unsigned long long value)
{
	prim = value;
}
