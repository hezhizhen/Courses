#include <iostream>
using namespace std;

int main()
{
	int l,m;
	cin >> l >> m;
	int tree[10001]={0};
	for(int i=0;i<=l;i++)
	{
		tree[i]=1;
	}
	for(int i=0;i<m;i++)
	{
		int start, end;
		cin >> start >> end;
		for(int j=start;j<=end;j++)
		{
			tree[j]=0;
		}
	}
	int remain=0;
	for(int i=0;i<=l;i++)
	{
		if(tree[i]==1)
		{
			remain++;
		}
	}
	cout << remain << endl;
	return 0;
}