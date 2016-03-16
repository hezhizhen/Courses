#include <iostream>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int a[1000];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int res = k - a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(res==a[j])
			{
				cout << "yes" << endl;
				return 0;
			}
		}
	}
	cout << "no" << endl;
	return 0;
}