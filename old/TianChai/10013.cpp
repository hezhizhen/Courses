#include <iostream>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int t = 0;
	int water[110] = {0};
	int min = 10000;
	int min_index=0;
	if(m>=n)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> water[i];
			if(t<water[i])
			{
				t = water[i];
			}
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			cin >> water[i];
			if(t<water[i])
			{
				t=water[i];
			}
			if(min>water[i])
			{
				min=water[i];
				min_index=i;
			}
		}
		for(int j=m+1;j<=n;j++)
		{
			int addi;
			cin >> addi;
			water[min_index] += addi;
			min += addi;
			for(int i=1;i<=m;i++)
			{
				if(t<water[i])
				{
					t=water[i];
				}
				if(min>water[i])
				{
					min=water[i];
					min_index=i;
				}
			}
		}
	}
	cout << t << endl;
	return 0;
}