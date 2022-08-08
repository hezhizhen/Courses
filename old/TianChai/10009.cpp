#include <iostream>
using namespace std;

int main()
{
	char a[14];
	cin >> a;
	int len=0;
	while(a[len]!='\0')
	{
		len++;
	}
	long long int sum=0;
	long long int order=1;
	for(int i=0;i<len;i++)
	{
		int num=(int)a[i];
		if(num>=48 && num <=57)
		{
			num = num-48;
			sum += num*order;
			order = order*10;
		}
	}
	if(a[0]=='-')
	{
		sum = -sum;
	}
	cout << sum << endl;
	return 0;
}