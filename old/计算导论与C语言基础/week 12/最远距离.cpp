#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double points[100][2];
	for(int i=0;i<n;i++)
	{
		cin >> points[i][0] >> points[i][1];
	}
	double dis=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			double temp = sqrt((points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
			if(temp>dis)
			{
				dis=temp;
			}
		}
	}
	//output
	cout << fixed << setprecision(4) << dis << endl;
	return 0;
}