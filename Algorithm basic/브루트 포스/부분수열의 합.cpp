#include<iostream>

using namespace std;
 
int n, s;
int a[20];
int ans = 0;
int sum = 0;

void go(int index, int sum)
{
	if(index == n)
	{
		if(sum == s)
		{
			ans+=1;
		}
		return;
	}
	
	go(index+1, sum+a[index]);
	go(index+1, sum);
}

int main()
{
	cin >> n >> s;
	
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	go(0,0);
	
	if(s==0)
	{
		ans -=1;
	}
 	cout << ans << '\n';
 	
 	return 0;
 }
