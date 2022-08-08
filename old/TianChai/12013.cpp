#include <iostream>
using namespace std;

int main()
{
	char a[100];
	cin >> a;
	char b[100];
	int len=0;
	while(a[len]!='\0')
	{
		len++;
	}
	for(int i=0;i<len;i++)
	{
		b[len-i-1]=a[i];
	}
	bool reverse = true;
	for(int i=0;i<len;i++)
	{
		if(a[i]!=b[i])
		{
			reverse = false;
			break;
		}
	}
	if(reverse==true)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}