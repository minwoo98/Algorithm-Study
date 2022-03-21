#include <iostream>
#include <vector>
using namespace std;
 
int main(void)
{
	int n, k;
	cin >> n >> k;
	
	vector<int> money(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> money[i];
	}
	
	int ans = 0;
	for(int i=n; i>0; i--)
	{
		ans += k / money[i-1];
		k = k % money[i-1];
	}
	
	cout << ans << '\n';

	return 0;	
}
