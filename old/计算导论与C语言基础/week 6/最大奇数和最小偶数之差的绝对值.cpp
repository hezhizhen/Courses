#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 100;
	for(int i=1;i<=6;i++)
	{
		int k;
		cin >> k;
		if(k%2==1)
		{
			if(k>a)
			{
				a = k;
			}
		}
		else
		{
			if(k<b)
			{
				b = k;
			}
		}
	}
	int result = a-b;
	if(result<0)
	{
		result = -result;
	}
	cout << result << endl;
	return 0;
}