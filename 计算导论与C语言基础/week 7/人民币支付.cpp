#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int n100=0,n50=0,n20=0,n10=0,n5=0,n1=0;
	n100 = n/100;
	n = n - n100*100;
	n50 = n/50;
	n = n - n50*50;
	n20 = n/20;
	n = n - n20*20;
	n10 = n/10;
	n = n - n10*10;
	n5 = n/5;
	n = n - n5*5;
	n1 = n;
	cout << n100 << endl << n50 << endl << n20 << endl << n10 << endl << n5 << endl << n1 << endl;
	return 0;
}