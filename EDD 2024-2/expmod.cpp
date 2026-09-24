#include <iostream>
using namespace std;


long mod(long a, long b) {return (((a%b)+b)%b);}

long mpow(long x, int p, int z){
	int rslt= 1;
	x= mod(x, z);
	if(x==0){return 0;}

	while(p>0){
		if(p%2==1){
			rslt= mod((rslt*x),z);
		}
		int auxp= p/2;
		p= auxp;
		x= mod((x*x),z);
	}
	return rslt;
}

int main()
{
	int b = 9;
	int p = 7;
	int m = 527;
    //b^p mod m
	cout << "Power is " << mpow(b, p, m);
	return 0;
}