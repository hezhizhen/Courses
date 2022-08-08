#include <iostream>
using namespace std;

int main()
{
	char s[80];
	int a=0,e=0,i=0,o=0,u=0;
	cin.getline(s,80);
	for(int j=0;s[j]!='\0';j++)
	{
		switch(s[j])
		{
			case 'a': a++;break;
			case 'e': e++;break;
			case 'i': i++;break;
			case 'o': o++;break;
			case 'u': u++;break;
			default:break;
		}
	}
	cout << a << " " << e << " " << i << " " << o << " " << u << endl;
	return 0;
}