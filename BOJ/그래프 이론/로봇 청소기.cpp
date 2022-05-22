#include<iostream>
#include<queue>

using namespace std;

int map[50][50];
bool check[50][50];
int cnt = 0;
int turn_left_cnt = 0;
int ans = 0;

int back_dx[4] = {0,-1,0,1};
int back_dy[4] = {1,0,-1,0};

int main(void)
{
 	int n,m;
 	cin >> n >> m;
 	
 	int sy,sx,sd;
 	cin >> sy >> sx >> sd;
 	
 	for(int i=0; i<n; i++)
 	{
 		for(int j=0; j<m; j++)
 		{
 			cin >> map[i][j];
 			check[i][j] = false;
 		}
 	}
 	
 	queue<pair<pair<int,int>,int>> q;
 	q.push(make_pair(make_pair(sy,sx),sd));
 	check[sy][sx] = true;
	cnt += 1; //청소하기 
	
 	while(!q.empty())
 	{
 		int y = q.front().first.first;
 		int x = q.front().first.second;
 		int d = q.front().second;
 		cout << y << ' ' << x << ' ' <<d << '\n';
 		
 		q.pop();
 		
 		if(turn_left_cnt == 4)
 		{
 			turn_left_cnt = 0; //매우 중요!! , 한번 후진했으면 거기서 또 turn 4연속 체크해야하므로 0으로 초기화해줘야 
 			int back_y = y+back_dy[d];
 			int back_x = x+back_dx[d];

 			if(map[back_y][back_x] == 1)
 			{
 				cout << cnt << '\n';
 				return 0;
 			}
 			else
 			{
 				q.push({{back_y,back_x},d});
 				continue;
 			}
 		}
 		
 		
 			
 		if(d==0)
 		{
 			if( map[y][x-1] == 0 && check[y][x-1] == false)
 			{
 				q.push(make_pair(make_pair(y,x-1),3)); //큐에 push 하면 청소하는 것으로 간주  
 				cout << "a" << '\n';
				check[y][x-1] = true; 
				cnt += 1;
				turn_left_cnt = 0; //청소했으니까 turn_left_cnt 0으로 초기화 
 			}
 			else if( (map[y][x-1] == 0 && check[y][x-1] == true) || map[y][x-1] == 1)
 			{
 				q.push(make_pair(make_pair(y,x),3));
 				cout << "b" << '\n';
 				turn_left_cnt += 1;
 			}
 		}
 		
 		else if(d==1)
 		{
 			if( map[y-1][x] == 0 && check[y-1][x] == false)
 			{
 				q.push(make_pair(make_pair(y-1,x),0));  
 				cout << "c" << '\n';
				check[y-1][x] = true; 
				cnt += 1;
				turn_left_cnt = 0;  
 			}
 			else if( (map[y-1][x] == 0 && check[y-1][x] == true) || map[y-1][x] == 1)
 			{
 				cout << "d" << ' ' << y << 'a'<< x << '\n';
 				q.push(make_pair(make_pair(y,x),0));
 				cout << "d" << ' ' << y << 'a'<< x << '\n';
 				turn_left_cnt += 1;
 			}
 				
 		}
 		else if(d==2)
 		{
 			if( map[y][x+1] == 0 && check[y][x+1] == false)
 			{
 				q.push(make_pair(make_pair(y,x+1),1)); 
 				cout << "e" << '\n';
				check[y][x+1] = true; 
				cnt += 1;
				turn_left_cnt = 0; 
 			}
 			else if( (map[y][x+1] == 0 && check[y][x+1] == true) || map[y][x+1] == 1)
 			{
 				q.push(make_pair(make_pair(y,x),1));
 				cout << "f" << '\n';
 				turn_left_cnt += 1;
 			}
 		}
 		else if(d==3)
 		{	

 			if( map[y+1][x] == 0 && check[y+1][x] == false)
 			{
 				q.push(make_pair(make_pair(y+1,x),2));  
 				cout << "g" << '\n';
				check[y+1][x] = true; 
				cnt += 1;
				turn_left_cnt = 0;
 			}
 			else if( (map[y+1][x] == 0 && check[y+1][x] == true) || map[y+1][x] == 1)
 			{
 				q.push(make_pair(make_pair(y,x),2));
 				cout << "h" << '\n';
 				turn_left_cnt += 1;
 			}	 		
 		}
	
 	}

	return 0;	
}
