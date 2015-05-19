#pragma once
class Kurvenpunkt
{
public:
	Gruppenpunkt x;
	Gruppenpunkt y;
	bool none;


	static Gruppenpunkt ka;

	Kurvenpunkt();
	Kurvenpunkt(Gruppenpunkt u, Gruppenpunkt v);
	~Kurvenpunkt();

	Kurvenpunkt operator+(Kurvenpunkt &Kurvenpunkt);
	Kurvenpunkt operator^(unsigned int y);
	bool operator==(Kurvenpunkt &a);
	void print();
};



