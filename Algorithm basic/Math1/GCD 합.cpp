#include <iostream>
using namespace std;

int GCD_sum(int a, int b)
{
	if(b==0)	return a;
	else return GCD_sum(b, a%b);
}

int main(void)
{
	int t;
	
	cin >> t;
	while(t--)
	{	
		int number[100];
		int n;
		cin >> n;
		for(int i=0; i<n; i++)
		{
			cin >> number[i];
		}
		long long result = 0;
		for(int i=0; i<n-1; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				result += GCD_sum(number[i], number[j]);
			}
		}
		cout << result << '\n';	
	}
	return 0;	
}

