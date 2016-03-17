#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char a;
	char s[500];
	int i=0;
	int len=0;
	int max=0;
	int stay=0;
	while((a=getchar())!=EOF)
	{
		s[len] = a;
		
				
		if(a==' '|| a=='.')
		{
			if(i>max)
			{
				max = i;
				stay=len-max;
			}
			i=0;
		}
		else
		{
			i++;
		}
		//cout << s[len] << " " << i << " " << max << endl;
		len++;
		if(a=='.')
		{
			break;
		}
		
	}
	//cout << "len:" << len << endl;
	//cout << "max:" << max << endl;
	//cout << "stay:" << stay << endl;
	for(int i=stay;i<stay+max;i++)
	{
		cout << s[i];
	}
	cout << endl;
	return 0;
}