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
		a[i] = i+1;
	}
	
	do
	{
		for(int i=0; i<n; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		
	}while(next_permutation(a.begin(), a.end()));
	
	return 0;
}
