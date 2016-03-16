#include <iostream>
using namespace std;

int main()
{
	double s=0, p=200;
	int n,k,m=0;
	int r[1000] = {0};
	int j=0;
	while(cin >> n >> k)
	{
		m=0;
		s=0;
		p=200;
		if(n<10 || n>50 || k<1 || k>20)
		{
			break;
		}
		else
		{
			for(int i=0;i<21;i++)
			{
				s = s+n;
				if(s<p)
				{
					p=p*(1+k/100.0);
					m++;
				}
				else
				{
					m++;
					break;
				}
			}
			r[j] = m;
			j++;
		}
	}
	for(int i=0;i<1000;i++)
	{
		if(r[i]<=20 && r[i]!=0)
		{
			cout << r[i] << endl;
		}
		else if(r[i]==21)
		{
			cout << "Impossible" << endl;
		}
		else if(r[i]==0)
		{
			break;
		}
	}
	return 0;
}