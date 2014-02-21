// Demonstrates conversion operators 

#include <iostream>
typedef unsigned short USHORT;

class Counter
{
public:
	Counter();
	Counter(USHORT val);
	~Counter(){};
	USHORT getItsVal() const {return itsVal; }
	void setItsVal(USHORT x) {itsVal = x; }
	operator unsigned short();
private:
	USHORT itsVal;
};

Counter::Counter(){
	itsVal = 0;
}

Counter::operator unsigned short ()
{
	return (USHORT (itsVal));
}

int main()
{
	Counter ctr(5);
	USHORT theShort = ctr;
	std::cout << "The value of theShort is " << theShort << std::endl;
	return 0;
}