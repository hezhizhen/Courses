#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
	char a[101],s[101];
	cin >> a;
	int len=strlen(a);
	int top=0;
	bool over = false;//定义这个变量，只是为了在break跳出时不因为top恰好为0而输出YES
	for(int i=0;i<len;i++)
	{
		char c;
		c = a[i];
		if(c=='('||c=='['||c=='{')
		{
			top++;
			s[top] = c;
		}
		else
		{
			//cout << c << " " << s[top] << endl;
			char a = s[top];
			if(c==')' && a=='(')
			{
				top--;
			}
			else if(c==']' && a=='[')
			{
				top--;
			}
			else if(c=='}' && a=='{')
			{
				top--;
			}
			else
			{
				over = true;
				break;
			}
			//cout << top << endl;
		}
		//cout << top << " " << s[top] << endl;
	}
	if(top==0 && over==false)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}