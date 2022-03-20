#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		int m, n,x, y;
		cin >> m >> n >> x >> y;
		
		x -= 1;
		y -= 1;
		bool ok = false; 	
		for(int k=x; k<(m*n); k+=m)
		{
			if(k%n == y)
			{
				cout << k+1 << '\n';
				ok = true;
				break;
			}				
		}
		if(!ok)
		{
			cout << -1 << '\n';
		}	
	}
	
	return 0;
}
