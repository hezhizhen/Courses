#include <iostream>
using namespace std;

int main()
{
	char r[7];
	int n;
	while(cin >> r >> n)
	{
		// output for test
		cout << "r is: " << r << endl;
		cout << "n is: " << n << endl;
		
		int cnt = 0;// count of decimal
		int left, right;

		for(left=1;left<6&&r[left]!='.';left++)
		{
			for(right=5;right>=0&&r[right]=='0';right--)
			{
				cnt = right-left;
			}
		}

		double R;

	}
	return 0;
}
