#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for(int i=0; i<n; i++)
	{
		cin >> v[i];
	}
	while(k--)
	{
		int a, b;
		cin >> a >> b;

		float ans = 0.00;
		for(int i=a-1; i<b; i++)
		{
			ans +=  (float)v[i];
		}
		ans = ans / (b-a+1);

		cout << ans << '\n';
	}

	return 0;
}
