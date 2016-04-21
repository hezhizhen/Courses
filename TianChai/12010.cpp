#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int q[200005];//把数组开得比n的上限大一倍，避免数组越界；实际上只要1.5倍上限就够了
	for(int i=1;i<=n;i++)
	{
		cin >> q[i];
	}
	int head = 1;
	int tail = n+1;
	while(head!=tail)
	{
		cout << q[head] << " ";
		head++;
		
		q[tail] = q[head];
		tail++;
		
		head++;
	}
	return 0;
}