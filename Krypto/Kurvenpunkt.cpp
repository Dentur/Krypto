#include "stdafx.h"
#include "Kurvenpunkt.h"

Gruppenpunkt Kurvenpunkt::ka;

Kurvenpunkt::Kurvenpunkt() : Kurvenpunkt(0,0)
{
	
}

Kurvenpunkt::Kurvenpunkt(Gruppenpunkt u, Gruppenpunkt v)
{
	x = u;
	y = v;
	none = false;
}


Kurvenpunkt::~Kurvenpunkt()
{
}

Kurvenpunkt Kurvenpunkt::operator+(Kurvenpunkt &a)
{
	if (none)
		return a;
	if (a.none)
		return *this;
	if (this->x == a.x)
	{
		if (this->y == a.y)
		{
			Gruppenpunkt m = ((Gruppenpunkt(3)*x*x)+ka) / (Gruppenpunkt(2)*y);
			Gruppenpunkt m2 = m*m;
			Gruppenpunkt x3 = m2 - Gruppenpunkt(2)*x;
			Gruppenpunkt y3 = (m*(x - x3)) - y;
			return Kurvenpunkt(x3, y3);
		}
		else
		{
			Kurvenpunkt t;
			t.none = true;
			return t;
		}
	}
	else
	{
		Gruppenpunkt m = (a.y - y) / (a.x - x);
		Gruppenpunkt x3 = m * m - a.x-x;
		Gruppenpunkt y3 = m*(x - x3) - y;
		return Kurvenpunkt(x3, y3);
	}
}

void Kurvenpunkt::print()
{
	printf("Kurvenpunkt: x:%d y:%d\n", x.zahl, y.zahl);
}