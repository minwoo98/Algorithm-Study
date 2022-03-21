#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(void)
{
	int n;
	cin >> n;
	
	vector<int> time(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> time[i];
	}
	
	vector<int> sum(n,0);
	int ans = 0;
	
	sort(time.begin(), time.end());
	
	sum[0] = time[0];
	ans = sum[0];
	
	for(int i=1; i<n; i++)
	{
		sum[i] = sum[i-1] + time[i];
		ans += sum[i];
	}
	
	cout << ans << '\n';
	
	return 0;	
}
