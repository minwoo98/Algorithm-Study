#include <iostream>
#include <math.h>
using namespace std;

int GCD(int a, int b)
{
	if(b==0) return a;
	else return GCD(b, a%b);
}
int main(void)
{
 	int N, S;  //N: people, S: initial location
 	int location[100000];
 	int dist[100000];
 	int ans = 0;
	cin >> N >> S;
	
	for(int i=0; i<N; i++)
	{
		cin >> location[i];
		dist[i] = abs(S-location[i]);
	}
	
	for(int i=0; i<N; i++)
	{
		ans = GCD(dist[i],ans);
	}
	cout << ans << '\n';
	
	return 0;	
}
