#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n!=0)
	{
		//input
		int a[15000];
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		//sort
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		if(n%2==1)
		{
			cout << a[n/2] << endl;
		}
		if(n%2==0)
		{
			int mid = a[(n+1)/2]+a[(n-1)/2];
			mid = mid/2;
			cout << mid << endl;
		}
		
		cin >> n;
	}
	return 0;
}