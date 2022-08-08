#include <iostream>
using namespace std;

int main()
{
	int a[101];
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	int cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			cnt++;
		}
	}
	cout << cnt << endl;


	cout << a[1] << " ";
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}
