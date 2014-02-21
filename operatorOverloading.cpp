// Demonstrates including operators in a class 

#include <iostream>
typedef unsigned short USHORT;

class Counter
{
public:
	Counter();
	~Counter(){};
	USHORT getItsVal() const {return itsVal; }
	void setItsVal(USHORT x) {itsVal = x; }
	void increment() {++itsVal; } //Increment operator
	// void operator++ () {++itsVal; } //Prefix operator
	// void const operator++ (int); //Postfix operator
	const Counter& operator++ (); //Prefix
	const Counter operator++ (int); //Postfix
private:
	USHORT itsVal;
};

Counter::Counter(){
	itsVal = 0;
}

const Counter & Counter::operator++()
{
	++itsVal;
	return *this; //so it returns an unnamed temporary
}

const Counter Counter::operator++ (int)
{
	Counter temp(*this);
	++itsVal;
	return temp;
}

int main()
{
	Counter i;
	std::cout << "The value of i is " << i.getItsVal() << std::endl;
	i.increment(); //Increment operator
	std::cout << "The value of i is " << i.getItsVal() << std::endl;
	++i; //Prefix operator
	std::cout << "The value of i is " << i.getItsVal() << std::endl;
	return 0;
}