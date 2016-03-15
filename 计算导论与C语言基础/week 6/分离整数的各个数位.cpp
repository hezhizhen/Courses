#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int a;
	cin >> a;
	int h,t,b;
	b = a%10;
	a /= 10;
	t = a%10;
	a /= 10;
	h = a%10;
	cout << h << endl;
	cout << t << endl;
	cout << b << endl;
	return 0;
}