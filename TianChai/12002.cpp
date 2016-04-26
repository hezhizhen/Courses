#include <iostream>
using namespace std;

int main()
{
	int L, M;
	cin >> L >> M;
	int a[10010];
	for(int i=0;i<=L;i++)
	{
		a[i] = 1;
	}
	for(int m=1;m<=M;m++)
	{
		int start,end;
		cin >> start >> end;
		for(int i=start;i<=end;i++)
		{
			a[i] = 0;
		}
	}
	int sum = 0;
	for(int i=0;i<=L;i++)
	{
		if(a[i]==1)
		{
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}