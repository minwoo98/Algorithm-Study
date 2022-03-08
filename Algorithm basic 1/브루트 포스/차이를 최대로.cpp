#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	
	vector<int> a(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	do
	{
		int temp = 0;
		for(int i=1; i<n; i++)
		{
			temp += abs(a[i-1] - a[i]);
		}
		if(temp > ans)
		{
			ans = temp;
		}
	}while(next_permutation(a.begin(), a.end()));
	
	cout << ans;
	
	return 0;
}
