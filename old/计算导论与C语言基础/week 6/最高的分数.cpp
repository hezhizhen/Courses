#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int max = 0;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin >> a;
		if(max<a)
		{
			max = a;
		}
	}
	cout << max << endl;
	return 0;
}