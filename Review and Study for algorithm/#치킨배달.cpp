#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n,m;
int map[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> ch;
vector<pair<int,int>> sel_ch;
bool check[13] = {false};
int ans = 987654321;


void fine_min_dist()
{
	int result = 0;
	
	for(int i=0; i<home.size(); i++)
	{
		int temp = 987654321;
		for(int j=0; j<sel_ch.size(); j++)
		{
			int dist = abs(sel_ch[j].first - home[i].first) + abs(sel_ch[j].second - home[i].second);
			
			temp = min(dist,temp);
		}
		//�ϳ��� ������ �ִܰŸ��� ġŲ�Ÿ� -> temp
		//������ ��� ġŲ�Ÿ� -> result += temp;
		result += temp; 
	}
	//������ ġŲ�Ÿ� �߿��� �ּڰ� -> m�� ġŲ�� select �Ϸ��� ������ ��� �ּڰ� ��  
	ans = min(ans,result); 
}

void select_ch(int idx, int cnt)
{
	if(cnt == m)
	{
		fine_min_dist();
		/*
		for(int k=0; k<sel_ch.size(); k++)
		{
			cout << sel_ch[k].first << ',' << sel_ch[k].second << '\n';
		}
		cout << "------------" << '\n';
		*/
	}
	
	//select m ���� ġŲ��
	for(int i=idx; i<ch.size(); i++)
	{
		if(check[i] == false)
		{
			check[i] = true;
			sel_ch.push_back({ch[i].first, ch[i].second});
			select_ch(i,cnt+1);
			
			sel_ch.pop_back();
			check[i] = false;
		}
	}
}


int main(void){

	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 1)
			{
				home.push_back({i,j});
			}
			else if(map[i][j] == 2)
			{
				ch.push_back({i,j});
			}
		}
	}
	
	select_ch(0,0);
	
	cout << ans;

	return 0;
}




