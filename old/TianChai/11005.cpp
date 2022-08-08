#include <iostream>
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	int times = 0;
	for(int i=1;i<=n;i++)
	{
		int copy = i;
		while(copy!=0)
		{
			int part = copy%10;
			if(part==x){
				times++;
			}
			copy = copy/10;
		}
	}
	cout << times << endl;
	return 0;
}