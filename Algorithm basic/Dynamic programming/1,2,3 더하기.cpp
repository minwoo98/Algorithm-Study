#include<iostream>
#include<math.h>
using namespace std;
 
 int d[1000];
 int main(void)
 {
 	int T;
 	cin >> T;
 	
 	while(T--)
 	{
 		int n;
		cin >> n;
		d[0] = 1;
		d[1] = 1;
		d[2] = 2;
		
		for(int i=3; i<=n; i++)
		{
			d[i] = d[i-1] + d[i-2] + d[i-3];	
		}
		cout << d[n] << '\n';
 	}
 	return 0;
 }
