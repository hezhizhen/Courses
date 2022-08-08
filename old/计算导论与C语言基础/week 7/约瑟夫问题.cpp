#include <iostream>
using namespace std;

int succedent[300];//这个数组用来保存一个猴子后一位是谁
int precedent[300];//这个数组用来保存一个猴子前一位是谁

int main()
{
	int n,m;
	while(true)
	{
		cin >> n >> m;
		if(n==0 && m==0)
		{
			break;
		}
		for(int i=0;i<n-1;i++)
		{
			succedent[i] = i+1;
			precedent[i+1] = i;
		}
		succedent[n-1]=0;
		precedent[0]=n-1;
		
		int current = 0;
		while(true)
		{
			//如果一共要报m次，则取m-1次succedent之后就是需要退出的那只猴子
			for(int count=0;count<m-1;count++)
			{
				current = succedent[current];
			}
			int pre = precedent[current];
			int suc = succedent[current];
			//让current号猴子退出，就是把前一位的“下一位”指向current的下一位
			succedent[pre] = suc;
			precedent[suc] = pre;
			if(pre == suc)
			{
				//如果只剩下两只，那么每个人的前位和后位是同一只
				//current是退出的，另一只就是剩下的
				//我们的序号从0编号，输出时要加1
				cout << pre+1 << endl;
				break;
			}
			current = suc;
		}
	}
	return 0;
}