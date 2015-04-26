#pragma once
class Gruppenpunkt
{
public:
	static unsigned long long prim;
	unsigned long long zahl;


	Gruppenpunkt();
	Gruppenpunkt(unsigned long long value);
	~Gruppenpunkt();

	Gruppenpunkt operator+(const Gruppenpunkt& a);

	void print();
	static void setPrim(unsigned long long value);
};

