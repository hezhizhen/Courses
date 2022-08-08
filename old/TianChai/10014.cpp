#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i=n;i>=0;i--)
	{
		int coe;
		cin >> coe;
		if(i==n)
		{
			if(coe>0)
			{
				if(coe==1)
				{
					cout << "x^" << i;
				}
				else
				{
					cout << coe << "x^" << i;
				}
			}
			else if(coe<0)
			{
				cout << "-";
				coe = -coe;
				if(coe==1)
				{
					cout << "x^" << i;
				}
				else
				{
					cout << coe << "x^" << i;
				}

			}
			else
			{
				continue;
			}
		}
		else if(i==1)
		{
			if(coe>0)
			{
				cout << "+";
				if(coe==1)
				{
					cout << "x";
				}
				else
				{
					cout << coe << "x";
				}
			}
			else if(coe<0)
			{
				cout << "-";
				coe = -coe;
				if(coe==1)
				{
					cout << "x";
				}
				else
				{
					cout << coe << "x";
				}
			}
			else
			{
				continue;
			}
		}
		else if(i==0)
		{
			if(coe>0)
			{
				cout << "+";
				cout << coe;
			}
			else if(coe<0)
			{
				cout << coe;
			}
			else
			{
				continue;
			}
		}
		else
		{
			if(coe>0)
			{
				cout << "+";
				if(coe==1)
				{
					cout << "x^" << i;
				}
				else
				{
					cout << coe << "x^" << i;
				}
			}
			else if(coe<0)
			{
				cout << "-";
				coe = -coe;
				if(coe==1)
				{
					cout << "x^" << i;
				}
				else
				{
					cout << coe << "x^" << i;
				}

			}
			else
			{
				continue;
			}
		}
	}
	return 0;
}