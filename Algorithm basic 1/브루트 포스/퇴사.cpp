#include <iostream>

using namespace std;

int ans = 0;
int n;

int t[100]; //21
int p[100];

void go(int day, int sum)
{
	if(day == n+1)
	{
		if(ans < sum)	ans = sum;
		return;
	}
	if(day > n+1)
	{
		return;
	}
	
	go(day + t[day], sum + p[day]);
	go(day+1, sum);
}

int main(void)
{
	cin >> n;

	for(int i=1; i<=n; i++)
	{
		cin >> t[i] >> p[i];
	}
	go(1, 0);
	cout << ans << '\n';
	
	return 0;	
}
