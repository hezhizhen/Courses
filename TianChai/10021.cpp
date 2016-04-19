#include <iostream>
using namespace std;

bool prime(int n)
{
	if(n==1 || n==0)
	{
		return false;
	}
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	char a[100];
	cin >> a;
	int len=0;
	int cnt[26] = {0};
	while(a[len]!='\0')
	{
		int al = (int)a[len] - 97;
		cnt[al]++;
		len++;
	}
	int maxn = 0;
	int minn = 100;
	for(int i=0;i<26;i++)
	{
		if(cnt[i]>maxn)
		{
			maxn=cnt[i];
		}
		if(cnt[i]>0 && cnt[i]<minn)
		{
			minn = cnt[i];
		}
	}
	int d = maxn-minn;
	bool output = prime(d);
	if(output == true)
	{
		cout << "Lucky Word" << endl << d << endl;
	}
	else {
		cout << "No Answer" << endl << 0 << endl;
	}
	
	return 0;
}