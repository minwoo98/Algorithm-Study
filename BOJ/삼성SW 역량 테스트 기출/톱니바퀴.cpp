#include <iostream>
#include <cstdio>
#include <algorithm> //copy()
using namespace std;

int one[8];
int two[8];
int three[8];
int four[8];

bool turn[5] = {false, false, false, false, false}; //false면 턴안함, true면 턴함.
int ans = 0;
/*
if(dir == -1) //반시계 -> index -- 
{
	for(int j=0; j<8; j++)
	{
		if(j==7)	three[j] = three[0];
		else	three[j] = three[j+1];
	}
}
else if(dir == 1) //시계 -> index++  
{ 
	for(int j=0; j<8; j++)
	{
		if(j==0)	three[j] = three[7];
		else	three[j] = three[j-1];
	}
}
*/

int main(int argc, char** argv)
{	
	int one[8];
	int two[8];
	int three[8];
	int four[8];
	
	for(int i=0; i<8; i++)
	{
		scanf("%1d", &one[i]);
	}
	for(int i=0; i<8; i++)
	{
		scanf("%1d", &two[i]);
	}
	for(int i=0; i<8; i++)
	{
		scanf("%1d", &three[i]);
	}
	for(int i=0; i<8; i++)
	{
		scanf("%1d", &four[i]);
	}
	
	//temp
	int one_t[8];
	int two_t[8];
	int three_t[8];
	int four_t[8];
	
	copy(one, one+8, one_t);
	copy(two, two+8, two_t);
	copy(three, three+8, three_t);
	copy(four, four+8, four_t);
	
	int k;
	cin >> k;
	while(k--)
	{
		int start;
		int dir;
		cin >> start >> dir; //dir:1->시계, -1->반시계 
		
		bool turn[5] = {false, false, false, false, false}; //false면 턴안함, true면 턴함.
		//회전유무 초기화  
		turn[1] = false;
		turn[2] = false;
		turn[3] = false;
		turn[4] = false;
		
		copy(one, one+8, one_t);
		copy(two, two+8, two_t);
		copy(three, three+8, three_t);
		copy(four, four+8, four_t);
		
		if(start == 1)
		{
			turn[1] = true;
			if(one[2] == two[6])	turn[2] = false;
			else	turn[2] = true;
			if(turn[2] == true)
			{
				if(two[2] == three[6])	turn[3] = false;
				else	turn[3] = true;
			}
			else
			{
				turn[3] = false;
				turn[4] = false;
			}
			if(turn[3] == true)
			{
				if(three[2] == four[6])	turn[4] = false;
				else	turn[4] = true;
			}	
			
			//1,3 dir방향,2,4 반대방향 
			for(int i=1; i<=4; i++)
			{
				if(turn[i] == true)
				{
					if(i==1)
					{	
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==7)	one[j] = one_t[0];
								else	one[j] = one_t[j+1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==0)	one[j] = one_t[7];
								else	one[j] = one_t[j-1];
							}
						}	
					}
					else if(i==2)
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	two[j] = two_t[7];
								else	two[j] = two_t[j-1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==7)	two[j] = two_t[0];
								else	two[j] = two_t[j+1];
							}
						}
					}
					else if(i==3)
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==7)	three[j] = three_t[0];
								else	three[j] = three_t[j+1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	three[j] = three_t[7];
								else	three[j] = three_t[j-1];
							}
						}
					}
					else
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	four[j] = four_t[7];
								else	four[j] = four_t[j-1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==7)	four[j] = four_t[0];
								else	four[j] = four_t[j+1];
							}
						}
					}		
				}
				else;
			}
		}
		else if(start == 2)  
		{
			turn[2] = true;
			if(two[2] == three[6])	turn[3] = false;
			else	turn[3] = true;
			if(turn[3] == true)
			{
				if(three[2] == four[6])	turn[4] = false;
				else	turn[4] = true;
			}
			else	turn[4] = false;
			if(two[6] == one[2])	turn[1] = false;
			else	turn[1] = true;
			
			//2,4번 dir방향 
			//1,3번 반대방향 
			for(int i=1; i<=4; i++)
			{
				if(turn[i] == true)
				{
					if(i==1)
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	one[j] = one_t[7];
								else	one[j] = one_t[j-1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==7)	one[j] = one_t[0];
								else	one[j] = one_t[j+1];
							}
						}
					}
					else if(i==2)
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==7)	two[j] = two_t[0];
								else	two[j] = two_t[j+1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==0)	two[j] = two_t[7];
								else	two[j] = two_t[j-1];
							}
						}
					}
					else if(i==3)
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	three[j] = three_t[7];
								else	three[j] = three_t[j-1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==7)	three[j] = three_t[0];
								else	three[j] = three_t[j+1];
							}
						}
					}
					else
					{
						if(dir == -1)
						{
							for(int j=0; j<8; j++)
							{
								if(j==7)	four[j] = four_t[0];
								else	four[j] = four_t[j+1];
							}
						}
						else if(dir == 1)
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	four[j] = four_t[7];
								else	four[j] = four_t[j-1];
							}
						}
					}
				}
				else;
			} 	
		}
		else if(start == 3)
		{
			turn[3] = true;
			//1.오른쪽 톱니 회전결정 
			if(three[2] == four[6])	turn[4] = false; 
			else	turn[4] = true;
			
			//2.왼쪽 톱니랑 회전결정
			if(three[6] == two[2])	turn[2] = false;
			else	turn[2] = true;
			
			//3. 인접하지 않은 톱니(1번톱니) 회전결정 
			if(turn[2] == false)	turn[1] = false;
			else
			{
				if(two[6] == one[2])	turn[1] = false;
				else	turn[1] = true;
			}
			
			//4.회전을 여부를  결정했으면 톱니바퀴 회전시킨다. 
			//2,4는 start dir과 반대방향, 1,3은 같은 방향  
			for(int i=1; i<=4; i++)
			{
				if(turn[i] == true)
				{
					if(i==1)
					{	
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==7)	one[j] = one_t[0];
								else	one[j] = one_t[j+1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==0)	one[j] = one_t[7];
								else	one[j] = one_t[j-1];
							}
						}	
					}
					else if(i==2)
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	two[j] = two_t[7];
								else	two[j] = two_t[j-1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==7)	two[j] = two_t[0];
								else	two[j] = two_t[j+1];
							}
						}
					}
					else if(i==3)
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==7)	three[j] = three_t[0];
								else	three[j] = three_t[j+1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==0)	three[j] = three_t[7];
								else	three[j] = three_t[j-1];
							}
						}
					}
					else
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	four[j] = four_t[7];
								else	four[j] = four_t[j-1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{
							for(int j=0; j<8; j++)
							{
								if(j==7)	four[j] = four_t[0];
								else	four[j] = four_t[j+1];
							}
						}
					}		
				}
				else;
			}
		}
		else
		{
			turn[4] = true;
			//턴 결정  
			if(four[6] == three[2])	turn[3] = false;
			else	turn[3] = true;
			if(turn[3] == true)
			{
				if(three[6] == two[2])	turn[2] = false;
				else	turn[2] = true;
			}
			else
			{
				turn[2] = false;
				turn[1] = false;
			}
			if(turn[2] == true)
			{
				if(two[6] == one[2])	turn[1] = false;
				else	turn[1] = true;
			}
			else	turn[1] = false;
			
			//회전 시키기
			//1,3번은 dir과 반대
			//2,4번은 dir방향  
			for(int i=1; i<=4; i++)
			{
				if(turn[i] == true)
				{
					if(i==1)
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	one[j] = one_t[7];
								else	one[j] = one_t[j-1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==7)	one[j] = one_t[0];
								else	one[j] = one_t[j+1];
							}
						}
					}
					else if(i==2)
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==7)	two[j] = two_t[0];
								else	two[j] = two_t[j+1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==0)	two[j] = two_t[7];
								else	two[j] = two_t[j-1];
							}
						}
					}
					else if(i==3)
					{
						if(dir == -1) //반시계 -> index -- 
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	three[j] = three_t[7];
								else	three[j] = three_t[j-1];
							}
						}
						else if(dir == 1) //시계 -> index++  
						{ 
							for(int j=0; j<8; j++)
							{
								if(j==7)	three[j] = three_t[0];
								else	three[j] = three_t[j+1];
							}
						}
					}
					else
					{
						if(dir == -1)
						{
							for(int j=0; j<8; j++)
							{
								if(j==7)	four[j] = four_t[0];
								else	four[j] = four_t[j+1];
							}
						}
						else if(dir == 1)
						{
							for(int j=0; j<8; j++)
							{
								if(j==0)	four[j] = four_t[7];
								else	four[j] = four_t[j-1];
							}
						}
					}
				}
				else;
			} 
		}
		/*
		//turn debug
		cout << "-------------" << '\n';
		for(int i=1; i<=4; i++)
		{
			cout << turn[i] << ' ';
		}
		cout << '\n';	
		cout << "-------------" << '\n';
			
		for(int i=0;i<8; i++)
		{
			cout << one[i];
		}
		cout << '\n';
		for(int i=0;i<8; i++)
		{
			cout << two[i];
		}
		cout << '\n';
		for(int i=0;i<8; i++)
		{
			cout << three[i];
		}
		cout << '\n';
		for(int i=0;i<8; i++)
		{
			cout << four[i];
		}
		cout << '\n';
		*/
	}
	
	//점수계산 
	if(one[0] == 1)	ans+= 1;
	else;
	if(two[0] == 1)	ans+= 2;
	else;
	if(three[0] == 1)	ans+= 4;
	else;
	if(four[0] == 1)	ans+= 8;
	else;
	
	cout << ans;

	return 0;	
}
