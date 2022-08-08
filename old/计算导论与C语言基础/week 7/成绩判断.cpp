#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	if(n>=95)
	{
		cout << 1 << endl;
	}
	else if(n>=90)
	{
		cout << 2 << endl;
	}
	else if(n>=85)
	{
		cout << 3 << endl;
	}
	else if(n>80)
	{
		cout << 4 << endl;
	}
	else if(n>=70)
	{
		cout << 5 << endl;
	}
	else if(n>=60)
	{
		cout << 6 << endl;
	}
	else
	{
		cout << 7 << endl;
	}
	return 0;
}