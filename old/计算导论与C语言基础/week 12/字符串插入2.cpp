#include <iostream>
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
		//output the first part
		for(int i=0;i<index;i++)
		{
			cout << str[i];
		}
		cout << substr;
		for(int i=index;str[i]!='\0';i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	return 0;
}