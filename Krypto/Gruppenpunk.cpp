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
		if (zahl <= a.zahl) return((zahl - (a.zahl^prim)));
		else return ((a.zahl - (zahl^prim)));
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
	/*if ((zahl >= ((prim + 1)/2)) && (a.zahl >= ((prim + 1)/2))) 
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
	if (a.zahl < sqrtPrim)
	{

	}*/
	Gruppenpunkt x = Gruppenpunkt(zahl);
	Gruppenpunkt r = Gruppenpunkt(0);
	for (unsigned int bTemp = a.zahl; bTemp; bTemp = bTemp >> 1)
	{
		if (bTemp & 1)
			r = r + x;
		x = x + x;
	}
	return r;
}

Gruppenpunkt Gruppenpunkt::operator^(unsigned int a)
{
	int n = a;
	Gruppenpunkt r = Gruppenpunkt(1);
	Gruppenpunkt x = Gruppenpunkt(zahl);
	for (; a; a = a >> 1, x = x*x)
	{
		if (a & 1)
		{
			r = r*x;
		}
	}
	return r;
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
	sqrtPrim = 11;//127
	//sqrtPrim = 2;
}

unsigned int Gruppenpunkt::getPrim()
{
	return prim;
}

bool Gruppenpunkt::isSquare()
{
	Gruppenpunkt t = (*this);
	Gruppenpunkt s = t ^ ((prim - 1) >> 1);
	if (zahl == 0)
		return true;
	if (s.zahl==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Gruppenpunkt Gruppenpunkt::root()
{
	return *this ^ ((prim + 1) >> 2);
}

Gruppenpunkt Gruppenpunkt::operator/(Gruppenpunkt &a)
{
	if (a.zahl == 0)
	{
		return NULL;
	}
	Gruppenpunkt d = a^(prim-2);
	return *this*d;
}
Gruppenpunkt Gruppenpunkt::moddiv(Gruppenpunkt &a)
{
	if (a.zahl == 0)
		return NULL;
	return Gruppenpunkt((this->zahl / a.zahl) % prim);
}

bool Gruppenpunkt::operator==(Gruppenpunkt &a)
{
	return this->zahl == a.zahl;
}

Gruppenpunkt Gruppenpunkt::operator-(Gruppenpunkt &a)
{
	return (*this) + a.Negativ();
}
