#include <iostream>
using namespace std;

int main()
{
	int n,x,y;
	cin >> n >> x >> y;
	double temp = y/(double)x;
	int tmp = y/x;
	if (temp>tmp)
	{
		tmp++;
	}
	int result = n - tmp;
	if(result<0)
	{
		result = 0;
	}
	cout << result << endl;
	return 0;
}