#include<iostream>
#include<vector>
using namespace std; 

int main(void)
{
	int N;
	cin >> N;
	vector<int> p(N+1);
	
	for(int i=1; i<=N; i++)
	{
		cin >> p[i];
	}	
	
	vector<int> d(N+1);
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=i; j++)
		{
			d[i] = max(d[i],d[i-j]+p[j]);
		}
	}
	cout << d[N] << '\n';
	return 0;	
}
