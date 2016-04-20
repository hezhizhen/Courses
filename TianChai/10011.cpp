// 由于题目说n是两个不同质数的乘积，所以直接找能整除的数即可
// 本来想穷举从n-1到sqrt(n)之间所有的数，但是超时了
// 这里的思路是，找到2到sqrt(n)之间的质因数，然后去除n，得到较大的质因数
// 然而我并不明白这种方法快在哪里

#include <iostream>
#include <cmath>
using namespace std;

bool prime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int i=2;
	int upper = sqrt(n);
	while(i<=upper)
	{
		if(prime(i))
		{
			if(n%i==0)
			{
				n = n/i;
			}
		}
		i++;
	}
	cout << n << endl;
	return 0;
}