#include <iostream>
#define mod 1000000000
using namespace std;
 
int main(void)
{
	int N;
	cin >> N;
	
	long long d[101][10];
	//d[N][L] = d[N-1][L-1] + d[N-1][L+1]
	//������ ���� L, ����N 
	for(int i=1; i<=9; i++)
	{
		d[1][i] = 1;
	}
	d[1][0] = 0;
	
	for(int i=2; i<=N; i++)
	{
		for(int j=0; j<=9; j++)
		{
			if(j==0)	d[i][j] = d[i-1][j+1] % mod;
			else if(j==9)	d[i][j] = d[i-1][j-1] % mod;
			else	d[i][j] = d[i-1][j-1] + d[i-1][j+1] % mod;
		}
	}
	//������ ��� ���� ���س�, ���� �������� ���ϴ� �� ���
	long long ans = 0;;
	for(int i=0; i<=9; i++)
	{
		ans += d[N][i];
	}
	cout << ans%mod << '\n';
	 
	return 0;	
}
