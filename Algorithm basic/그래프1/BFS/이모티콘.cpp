#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int time[1001][1001];
bool check[1001][1001];

int main(int argc, char** argv)
{		
	int s;
	cin >> s;
	
	queue<pair<int,int>> q;
	q.push(make_pair(1,0));
	
	check[1][0] = true;
	time[1][0] = 0;
	
	while(!q.empty())
	{
		int display = q.front().first;
		int clipboard = q.front().second;
		q.pop();
		
		if(display == s)
		{
			cout << time[display][clipboard] <<'\n';
			break; 
		}
		
		if(display>0 && display < 1001)
		{	//클립보드에 저장  
			if(check[display][display] == false)
			{
				q.push(make_pair(display,display));
				check[display][display] = true;
				time[display][display] = time[display][clipboard] + 1;		
			}	
			if(clipboard>0 && display + clipboard < 1001)
			{	//클립보드에 있는거 붙여넣기
				if(check[display+clipboard][clipboard] == false)
				{	
					q.push(make_pair(display+clipboard,clipboard));
					check[display+clipboard][clipboard] = true;
					time[display+clipboard][clipboard] = time[display][clipboard] + 1;		
				}	
			}
			if(check[display-1][clipboard] == false)
			{	//화면에 있는 이모티콘 1개 삭제  
				q.push(make_pair(display-1, clipboard));
				check[display-1][clipboard] = true;
				time[display-1][clipboard] = time[display][clipboard] + 1;		
			}
		}
	}
	
	return 0;	
}
