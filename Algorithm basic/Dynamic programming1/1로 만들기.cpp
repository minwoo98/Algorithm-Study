#include <iostream>
using namespace std;

int count = 0;
int d[1000000];

int x_to_1(int x)
{
	if(x==1) return count;
	if(d[x] > 0) return d[x];
	d[x] = x_to_1(x-1) + 1;
	if(x%2 == 0)
	{
		int temp = x_to_1(x/2) + 1;
		if(d[x] > temp)	d[x] = temp;	
	}
	if(x%3 == 0)
	{
		int temp = x_to_1(x/3) + 1;
		if(d[x] > temp)	d[x] = temp;	
	}
	return d[x];
}
	
int main(void)
{
	int x;
	cin >> x;
	int ans;
	
	ans = x_to_1(x);
	cout << ans;
	
	return 0;	
}
