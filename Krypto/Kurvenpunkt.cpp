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
	Kurvenpunkt ret;
	if ((a.x.zahl == 0) && (a.y.zahl==0))
		return *this;
	if ((x.zahl==0)&&(y.zahl==0))
		return a;
	if ((y + a.y) == Gruppenpunkt(0))
	{
		return Kurvenpunkt(Gruppenpunkt(Gruppenpunkt::getPrim()), Gruppenpunkt(Gruppenpunkt::getPrim()));
	}
	if (this->x == a.x)
	{
		if ((this->y == a.y) && (y.zahl!=0))
		{
			Gruppenpunkt m = ((Gruppenpunkt(3)*x*x)+ka) / (Gruppenpunkt(2)*y);
			Gruppenpunkt m2 = m*m;
			Gruppenpunkt x3 = m2 - (x+x);
			Gruppenpunkt y3 = (m*(x - x3)) - y;
			ret = Kurvenpunkt(x3, y3);
			if (!(ret.y^2).isSquare())
			{
				printf("Punkt liegt nicht auf der Kurve! ");
				//ret.print();
			}
			return ret;
		}
		else
		{
			Kurvenpunkt t = Kurvenpunkt(Gruppenpunkt(Gruppenpunkt::getPrim()), Gruppenpunkt(Gruppenpunkt::getPrim()));;
			t.none = true;
			/*if (!t.y.isSquare())
			{
				printf("Punkt liegt nicht auf der Kurve! ");
				t.print();
			}*/
			return t;
		}
	}
	else
	{
		Gruppenpunkt m = (a.y - y) / (a.x - x);
		Gruppenpunkt x3 = m * m - a.x-x;
		Gruppenpunkt y3 = m*(x - x3) - y;
		ret = Kurvenpunkt(x3, y3);
		if (!(ret.y ^ 2).isSquare())
		{
			printf("Punkt liegt nicht auf der Kurve! ");
			//ret.print();
		}
		return ret;
	}
}

Kurvenpunkt Kurvenpunkt::operator^(unsigned int y)
{
	Kurvenpunkt tmp = *this;
	while(y)
	{
		tmp = tmp + *this;
	}
	return tmp;
}

void Kurvenpunkt::print()
{
	printf("Kurvenpunkt: x:%d y:%d\n", x.zahl, y.zahl);
}

bool Kurvenpunkt::operator==(Kurvenpunkt &a)
{
	return(x == a.x) && (y == a.y);
}