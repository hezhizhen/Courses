#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int grade1=0, grade2=0,grade3=0,grade4=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin >> a;
		if(a<=18)
		{
			grade1++;
		}
		else if(a<=35)
		{
			grade2++;
		}
		else if(a<=60)
		{
			grade3++;
		}
		else
		{
			grade4++;
		}
	}

	cout << "1-18: " << fixed << setprecision(2) << 100*(double)grade1/n << "%" << endl;
	cout << "19-35: " << fixed << setprecision(2) << 100*(double)grade2/n << "%" << endl;
	cout << "36-60: " << fixed << setprecision(2) << 100*(double)grade3/n << "%" << endl;
	cout << "60-: " << fixed << setprecision(2) << 100*(double)grade4/n << "%" << endl;
	return 0;
}