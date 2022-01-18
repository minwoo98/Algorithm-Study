#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int n = 9;
int key[9];

int main(void)
{
	int sum=0; //초기화 안해줬더니 틀렸었음... 
	for(int i=0; i<9; i++)
	{
		cin >> key[i];
		sum += key[i];
	}
	sort(key,key+9);
	
	for(int i=0; i<9; i++)
	{
		for(int j=i+1; j<9; j++)
		{
			if(sum - key[i] - key[j] == 100)
			{
				for(int k=0; k<9; k++)
				{
					if(k==i || k==j)
					{
						continue;
					}
					cout << key[k] << '\n';
				}
				return 0;
			}
		}
	}
	return 0;	
}
