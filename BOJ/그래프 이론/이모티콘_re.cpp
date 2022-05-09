#include<iostream>
#include<queue>
using namespace std; 

int time[1001][1001] = {{0,0},};
bool check[1001][1001] = {{false,false},};
int s;

int main(void)
{
	cin >> s;
	queue<pair<int,int>> q;
	q.push(make_pair(1,0)); //display, clipboard
	
	check[1][0] = true;
	time[1][0] = 0;
	
	while(!q.empty())
	{
		int display = q.front().first;
		int clipboard = q.front().second;	
		q.pop();
		
		if(display == s)
		{
			cout << time[display][clipboard] << '\n';
			break;
		}
		
		for(int k=0; k<3; k++)
		{	
			if(k==0)
			{
				//클립보드에 복사
				if(display>0 && display < 1001)
				{
					if(check[display][display] == false)
					{
						q.push(make_pair(display,display));
						check[display][display] = true;
						time[display][display] = time[display][clipboard] + 1;
					}
				}	
			}
			else if(k==1)
			{
				//화면에 붙여넣기  
				if(display+clipboard>0 && display+clipboard < 1001)
				{
					if(check[display+clipboard][clipboard] == false)
					{
						q.push(make_pair(display+clipboard,clipboard));
						check[display+clipboard][clipboard] = true;
						time[display+clipboard][clipboard] = time[display][clipboard] + 1;
					}
				}
			}
			else
			{
				//화면에 이모티콘 한개 삭제하기  
				if(display>0 && display < 1001)
				{
					if(check[display-1][clipboard] == false)
					{
						q.push(make_pair(display-1,clipboard));
						check[display-1][clipboard] = true;
						time[display-1][clipboard] = time[display][clipboard] + 1;
					}
				}
			}
		}
	}
	
	
	
	return 0;	
}
