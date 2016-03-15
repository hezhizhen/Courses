#include <iostream>
using namespace std;

int main()
{
	int h,r;
	cin >> h >> r;
	const double PI = 3.14159;
	double volume = PI * r * r * h;
	const int demand = 20*1000;
	double temp = demand/volume;
	int result = (int)temp;
	if(temp-result > 0)
	{
		result++;
	}
	cout << result << endl;
	return 0;
}