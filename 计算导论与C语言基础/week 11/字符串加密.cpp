#include <iostream>
using namespace std;

int main()
{
	char str[200];
	while(cin.getline(str,200))
	{
		for(int i=0;str[i]!='\0';i++)
		{
			if(str[i]=='Z')
			{
				str[i]='A';
				continue;
			}
			if(str[i]=='z')
			{
				str[i]='a';
				continue;
			}
			if(str[i]==' ')
			{
				continue;
			}
			str[i]++;
		}
		cout << str << endl;
	}
	return 0;
}