#pragma once
class Gruppenpunkt
{
private:
	static unsigned long long prim;
	static unsigned long long sqrtPrim;
public:
	
	unsigned long long zahl;


	Gruppenpunkt();
	Gruppenpunkt(unsigned long long value);
	~Gruppenpunkt();

	Gruppenpunkt operator+(Gruppenpunkt& a);
	Gruppenpunkt ModPlus(Gruppenpunkt& a);
	Gruppenpunkt Negativ();
	Gruppenpunkt operator*(Gruppenpunkt&a);
	Gruppenpunkt div2();

	void print();
	static void setPrim(unsigned long long value);
	static unsigned long long getPrim();
};

