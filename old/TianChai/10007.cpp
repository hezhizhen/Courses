#include <iostream>
using namespace std;

int main()
{
	char a[15];
	cin >> a;
	int order=1;
	int sum=0;
	for(int i=0;i<12;i++)
	{
		int number = (int)a[i];
		if(number>=48 && number<=57)
		{
			number = number - 48;
			sum += number*order;
			order++;
		}
	}
	sum = sum%11;
	if(sum==10)
	{
		if(a[12]=='X')
		{
			cout << "Right" << endl;
		}
		else
		{
			a[12] = 'X';
			cout << a << endl;
		}
	}
	else
	{
		if(a[12]==(char)(sum+48))
		{
			cout << "Right" << endl;
		}
		else
		{
			a[12] = (char)(sum+48);
			cout << a << endl;
		}
	}
	return 0;

}
