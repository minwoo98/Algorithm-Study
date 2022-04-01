#include <iostream>
#include <math.h>
using namespace std;

int weight[50];
int ki[50];
int ans[50];

int main(void)
{
 	int n;
 	cin >> n;
 	
 	for(int i=0; i<n; i++)
 	{
 		cin >> weight[i] >> ki[i];
 	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j) continue;
			
			if(weight[i] < weight[j] && ki[i] < ki[j])
			{
				ans[i]+=1;
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		cout << ans[i]+1 << ' ';
	}
	
	return 0;	
}
