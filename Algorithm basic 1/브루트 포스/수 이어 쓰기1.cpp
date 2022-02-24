#include <iostream>
using namespace std;
	
int main(void)
{
	int n, temp;
	int cnt = 1;
	long long ans = 0; 
	
	cin >> n;
	temp = n;
	
	for(int start=1, len=1; start<=n; start*=10, len++)
	{
		int end = start*10-1;
		if(end > n)
		{
			end = n;
		}
		
		ans += (end-start+1)*len;
	}
	cout << ans << '\n';
	
	return 0;	
}
