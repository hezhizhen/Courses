#include <iostream>
using namespace std;

int main()
{
	int k;
	cin >> k;
	int n1=0, n5=0, n10=0;
	for(int i=1;i<=k;i++)
	{
		int a;
		cin >> a;
		if(a==1)
		{
			n1++;
		}
		if(a==5)
		{
			n5++;
		}
		if(a==10)
		{
			n10++;
		}
	}
	cout << n1 << endl;
	cout << n5 << endl;
	cout << n10 << endl;
	return 0;
}