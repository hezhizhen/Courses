#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	char s1[80], s2[80];
	cin.getline(s1,80);
	cin.getline(s2,80);
	int i = 0;
	char result;
	
	while(s1[i]!='\0')
	{
		if(s1[i]>=65 && s1[i]<=90)
		{
			s1[i] = (char)((int)s1[i]+32);
		}
		i++;
	}
	i=0;
	while(s2[i]!='\0')
	{
		if(s2[i]>=65 && s2[i]<=90)
		{
			s2[i] = (char)((int)s2[i]+32);
		}
		i++;
	}
	
	i = 0;
	while (s1[i] != '\0' && (s1[i] == s2[i])){
		i++;
	}
	if (s1[i] > s2[i]) {
		result = '>';
	} else if (s1[i] < s2[i]) {
		result = '<';
	} else{
		result = '=';
	}
	cout << result << endl;
	return 0;
}