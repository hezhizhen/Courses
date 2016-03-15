#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int N,K;
	cin >> N >> K;
	int a[100]={0};
	
	for(int i=1;i<=N;i++)
	{
		int num;
		cin >> num;
		
		for(int j=1;j<=K;j++)
		{
			
			if(num>a[j])
			{
				for(int k=K;k>j;k--)
				{
					a[k] = a[k-1];
				}
				a[j] = num;
				break;
			}
		}
		
	}
	cout << a[K] << endl;
	return 0;
}