#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> peo;
int b,c;
long long ans = 0;

int main(void)
{
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		int temp;
		cin >> temp;
		peo.push_back(temp);
	}
	
	cin >> b >> c;
	
	for(int i=0; i<peo.size(); i++)
	{
		int a = peo[i];
		if(b > a)	
		{
			ans+=1;
			continue;
		}
		
		a = a-b;
		ans += 1;
		
		ans += a/c;
		if(a%c > 0)	ans+=1;
		
	}

	cout << ans << ' ';
	
	return 0;	
}
