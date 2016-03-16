#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int before = 27;
	int after = 23;
	double walk = 1.2;
	double ride = 3.0;
	for(int i=1;i<=n;i++)
	{
		int dis;
		cin >> dis;
		double walk_t = dis/walk;
		double ride_t = dis/ride+after+before;
		if(ride_t<walk_t)
		{
			cout << "Bike" << endl;
		}
		else if(ride_t>walk_t)
		{
			cout << "Walk" << endl;
		}
		else {
			cout << "All" << endl;
		}
	}
	return 0;
}