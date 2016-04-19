#include <iostream>
using namespace std;

int main()
{
	int a[11];
	for(int i=1;i<=10;i++)
	{
		cin >> a[i];
	}
	int h;
	cin >> h;
	int addi = 30;
	int cnt=0;
	for(int i=1;i<=10;i++)
	{
		if(h+addi>=a[i])
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
