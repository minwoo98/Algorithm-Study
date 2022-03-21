#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int m,n,k;
	cin >> m >> n >> k;

	vector<int> ans(m);
	for(int i=0; i<m; i++)	cin >> ans[i];

	vector<int> user(n);
	for(int i=0; i<n; i++)	cin >> user[i];
/*
	if(ans.size() > user.size())
	{
		cout << "normal" << '\n';
		return 0;
	}
	else if(ans.size() == user.size())
	{
		for(int i=0; i<m; i++)
		{
			if(ans[i] != user[i])
			{
				cout << "normal" << '\n';
				return 0;
			}
		}
		cout << "secret" << '\n';
	}*/
	//비밀 식권 코드를 포함하는 경우
	
		for(int i=0; i<user.size(); i++)
		{
			if(user[i] == ans[0])
			{
				int cnt = 0;
				for(int j=0; j<m; j++)
				{
					if(user[i+j] == ans[j])
					{
						cnt+=1;
					}
				}
				if(cnt == m)
				{
					cout << "secret" << '\n';
					return 0;
				}
			}
			else;
		}
		cout << "normal" << '\n';
	
	return 0;
}
