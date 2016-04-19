#include <iostream>
using namespace std;

int main()
{
	int c[8][3];
	for(int i=1;i<=7;i++)
	{
		cin >> c[i][0] >> c[i][1];
		c[i][2] = c[i][0]+c[i][1];
	}
	int week = 0;
	int burden = 8;
	for(int i=1;i<=7;i++)
	{
		if(c[i][2]>burden)
		{
			week = i;
			burden=c[i][2];
		}
	}
	cout << week << endl;
	return 0;
}
