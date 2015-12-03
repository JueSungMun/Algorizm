#include <iostream>
using namespace std;

//initialize state to random bits
static unsigned long state[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

//return 32 bit random number
static unsigned int index = 0;

unsigned long WELLRNG512(void);

int main()
{
	unsigned long result;
	for(int i = 0; i<10; i++)
	{
		result = WELLRNG512();
		cout<<result<<endl;
	}
	

	return 0;
}

unsigned long WELLRNG512(void)
{
	unsigned long a, b, c, d;
	a = state[index];
	c = state[(index+13)&15];
	b = a^c^(a<<16)^(c<<15);
	c = state[(index+9)&15];
	c ^= (c>>11);
	a = state[index] = b^c;
	d = a^((a<<5)&0xDA442D0UL);
	index = (index + 15)&15;
	a = state[index];
	state[index] = a^b^d^(a<<2)^(b<<18)^(c<<28);
	return state[index];
}