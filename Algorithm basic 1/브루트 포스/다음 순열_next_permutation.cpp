#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	bool check = false;
	
	vector<int> a(n);
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	check = next_permutation(a.begin(), a.end());
	
	if(check)
	{
		for(int i=0; i<n; i++)
		{	
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	else cout << "-1";
	
	return 0;
}
