#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 2147483647;
	
	vector<vector<int>> a(n, vector<int>(n,0));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	vector<int> b(n,0);
	for(int i=0 ; i<n; i++)
	{
		b[i] = i;
	}

	do
	{	
		int sum = 0;
		bool ok = true; 
		for(int i=0; i<n-1; i++)
		{
			if(a[b[i]][b[i+1]] == 0) ok = false;
			else	sum += a[b[i]][b[i+1]];
		}
		if(ok && a[b[n-1]][b[0]] != 0)
		{
			sum += a[b[n-1]][b[0]];
			if(sum < ans)	ans = sum;
		}
				
	}while(next_permutation(b.begin(), b.end()));
	
	cout << ans;
	
	return 0;
}
