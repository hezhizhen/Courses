#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		int a;
		cin >> a;
		int num = 0;
		while(a>0)//反复除以2，看最低位是0还是1
		{
			num += a%2;
			a = a/2;
		}
		cout << num << endl;
	}
	return 0;
}