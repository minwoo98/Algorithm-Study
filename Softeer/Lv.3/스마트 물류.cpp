#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int n,k;
	cin >> n >> k;

	bool check[20000] = {false, };
	int cnt = 0;

	vector<char> a(n);
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}

	for(int i=0; i<a.size(); i++)
	{
		if(a[i] == 'H')
		{
			check[i] = true;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(a[i] == 'P')
		{
			for(int m=i-k; m<=i+k; m++)	//로봇의 왼쪽에 k개 ~ 로봇 오른쪽 k개 물건 집을지 결정
			{
				if(m>=0)
				{
					if(check[m] == true)
					{
						cnt += 1;
						check[m] = false;
						break;
					}
				}
			}
		}
		else;
	}
	cout << cnt << '\n';
	
	return 0;
}
