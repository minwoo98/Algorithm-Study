#include<iostream>
#include<vector>
using namespace std;

const int MAX = 1000000;
bool check[MAX];


int main(void)
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		vector<int> a(N);
		int index = 0;
		int ans = 0;
		//소수 판별 
		check[0]=check[1] = true;
		for(int i=2; i*i<=MAX; i++)
		{
			if(check[i] == false)
			{
				a.push_back(i);
				index++;
				for(int j=i+i; j<=MAX; j+=i)
				{
					check[j] = true;
				}
			}
		}
		//cout << index << ' '; if N=8, index = 4
		for(int i=0; i<index; i++)
		{	
			for(int j=i; j<index; j++)
			{
				if(a[i] + a[j] == N)
				{
					ans += 1;
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;	
}
