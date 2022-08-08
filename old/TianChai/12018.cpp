#include <iostream>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int s[100001];
    int top = 0;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin >> c;
        int num;
        if(c=='I')
        {
            top++;
            cin >> num;
            s[top] = num;
        }
        if(c=='O')
        {
            top--;
        }
    }
    for(int i=1;i<=top;i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}