#pragma once
class Gruppenpunkt
{
private:
	static unsigned int prim;
	static unsigned int sqrtPrim;
public:
	
	unsigned int zahl;


	Gruppenpunkt();
	Gruppenpunkt(unsigned int value);
	~Gruppenpunkt();

	Gruppenpunkt operator+(Gruppenpunkt& a);
	Gruppenpunkt ModPlus(Gruppenpunkt& a);
	Gruppenpunkt Negativ();
	Gruppenpunkt operator*(Gruppenpunkt&a);
	Gruppenpunkt ModMal(Gruppenpunkt &a);
	Gruppenpunkt div2();
	Gruppenpunkt operator^(unsigned int a);
	bool isSquare();

	void print();
	static void setPrim(unsigned int value);
	static unsigned int getPrim();
};

