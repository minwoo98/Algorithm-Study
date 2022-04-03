#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int m,n;
	cin >> m >> n;
	
	vector<int> a(100);
	vector<int> b;
	for(int i=1; i<=100; i++)
	{
		a[i-1] = i*i;
	}
	
	int ans = 0;
	int least;
	for(int i=0; i<a.size(); i++)
	{
		if(a[i] >= m && a[i] <=n)
		{	
			b.push_back(a[i]);
			ans += a[i];
		}
	}
	
	if(b.size() == 0)
	{
		cout << -1;
		return 0;
	}

	cout << ans << '\n';
	cout << b[0];
	
	return 0;	
}

