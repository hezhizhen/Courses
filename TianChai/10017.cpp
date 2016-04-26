#include <iostream>
using namespace std;

struct st
{
	char name[20];
	int average;
	int score;
	char off;
	char west;
	int paper;
	int total;
};

int main()
{
	int N;
	cin >> N;
	struct st stu[110];
	for(int i=1;i<=N;i++)
	{
		cin >> stu[i].name >> stu[i].average >> stu[i].score >> stu[i].off >> stu[i].west >> stu[i].paper;
		stu[i].total = 0;
		if(stu[i].average>80 && stu[i].paper>=1)
		{
			stu[i].total += 8000;
		}
		if(stu[i].average>85 && stu[i].score>80)
		{
			stu[i].total += 4000;
		}
		if(stu[i].average>90)
		{
			stu[i].total += 2000;
		}
		if(stu[i].average>85 && stu[i].west=='Y')
		{
			stu[i].total += 1000;
		}
		if(stu[i].score>80 && stu[i].off=='Y')
		{
			stu[i].total += 850;
		}
	}
	struct st max = stu[1];
	int sum = max.total;
	for(int i=2;i<=N;i++)
	{
		sum += stu[i].total;
		if(stu[i].total>max.total)
		{
			max = stu[i];
		}
	}
	cout << max.name << endl;
	cout << max.total << endl;
	cout << sum << endl;
	return 0;
}