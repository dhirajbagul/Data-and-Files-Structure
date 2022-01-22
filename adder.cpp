#include <iostream>
using namespace std;
class Adder
{ 
	private: int total;
	public:
	Adder(int i= 0)
	{ total = i; }

	void addNum(int number)
	{ total += number; }
	int getTotal()
	{ return total; };

};
int main( )
{ 	Adder a;
	a.addNum(10); a.addNum(20);
	a.addNum(30);
	cout<< a.getTotal();
	return 0 ;
}
