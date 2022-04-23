#include<iostream>
using namespace std;

int n;
int math[4] = {0,};
int check[11] = {4,}; //+,-,x,/ =>0,1,2,3
int num[11];

int maxs = 99999999;
int mins = -99999999;


void dfs(int index, int result) //연산자 갯수, 연산 결과  
{
	if(index == n)
	{
		if(result > mins)
		{
			mins = result;
		}
		if(result < maxs)
		{
			maxs = result;
		}
		return;
	}
	
	for(int k=0; k<4; k++)
	{
		if(math[k] > 0)
		{
			math[k] -= 1;
			if(k==0)
			{
				dfs(index+1, result+num[index]); 
			}
			else if(k==1)
			{
				dfs(index+1, result-num[index]);
			}
			else if(k==2)
			{
				dfs(index+1, result*num[index]);
			}
			else
			{
				dfs(index+1, result/num[index]);
			}
			math[k] += 1;
		}
	}
	
	
}
int main(void)
{
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> num[i];
	}
	
	for(int i=0; i<4; i++)
	{
		cin >> math[i];
	}
	
	dfs(1,num[0]);
	
	cout << mins << '\n' << maxs;
	return 0;	
}
