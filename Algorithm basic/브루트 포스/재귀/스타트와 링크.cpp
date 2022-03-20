#include<iostream>
#include<vector>

using namespace std;

int score[20][20] = {};

bool team[20] = {false,};
int n, ans = 99999999;
	
void teamset(int index, int cnt)
{
	vector<int> t1; //local
	vector<int> t2;
	int sum1 = 0;
	int sum2 = 0;// local
	
	if(cnt == n/2)
	{
		for(int i=0; i<n; i++)
		{
			if(team[i] == true)
			{
				t1.push_back(i);
			}
			else t2.push_back(i);
		}
		for(int i=0; i<(n/2); i++)
		{	
			for(int j=0; j<(n/2); j++)
			{
				sum1 += score[t1[i]][t1[j]];
				sum2 += score[t2[i]][t2[j]];
			}
		}	
		int diff = sum1 - sum2;
		if(diff<0) diff = -diff;
		if(diff<ans) ans = diff;
		return;
	}
	for(int i=index; i<n; i++)
	{
		if(team[i] == true) continue;
		else
		{
			team[i] = true; //true => team1
			teamset(i+1, cnt+1);
			team[i] = false; 
		}
	}
}

int main(void)
{
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> score[i][j];
		}
	}
	teamset(0,0);
	cout << ans << '\n';

	return 0;	
}
