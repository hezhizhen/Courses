#include <iostream>
using namespace std;

int main()
{
	int l,r;
	cin >> l >> r;
	int cnt=0;
	for(int i=l;i<=r;i++)
	{
		int test=i;
		while(test!=0)
		{
			if(test%10==2)
			{
				cnt++;
			}
			test=test/10;
		}
	}
	cout << cnt << endl;
	return 0;
}
