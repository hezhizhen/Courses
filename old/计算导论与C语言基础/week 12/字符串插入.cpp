#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[20], substr[5];
	while(cin >> str >> substr)
	{
		int index=0;
		int max = (int)str[0];
		for(int i=1;str[i]!='\0';i++)
		{
			if(max<(int)str[i])
			{
				max=(int)str[i];
				index = i;
			}
		}
		index++;
		int len=0;
		for(int i=0;str[i]!='\0';i++)
		{
			len++;
		}
		
		for(int i=len-1;i>=index;i--)
		{
			str[i+3] = str[i];
			//cout << str << endl;
		}
		
		for(int i=index;i<index+3;i++)
		{
			str[i] = substr[i-index];
		}
		cout << str << endl;
	}
	return 0;
}