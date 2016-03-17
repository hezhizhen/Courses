#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a[5][5];
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin >> a[i][j];
		}
	}
	int n,m;
	cin >> n >> m;
	if(n>=0 && n<5 && m>=0 && m<5)
	{
		//exchange row n and row m
		int temp[5];
		for(int i=0;i<5;i++)
		{
			temp[i] = a[n][i];
		}
		for(int i=0;i<5;i++)
		{
			a[n][i] = a[m][i];
		}
		for(int i=0;i<5;i++)
		{
			a[m][i] = temp[i];
		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				cout << setw(4) << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "error" << endl;
	}
	return 0;
}