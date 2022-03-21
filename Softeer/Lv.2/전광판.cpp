#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char** argv) {
	
	int t;
	cin >> t;
	
	int arr[10][7] = {  {1,1,1,1,1,1,0},
						{0,1,1,0,0,0,0},
						{1,1,0,1,1,0,1},
						{1,1,1,1,0,0,1},
						{0,1,1,0,0,1,1},
						{1,0,1,1,0,1,1},
						{1,0,1,1,1,1,1},
						{1,1,1,0,0,1,0},
						{1,1,1,1,1,1,1},
						{1,1,1,1,0,1,1},
						};
						
					
	vector<int> v1(5); //a
	vector<int> v2(5); //b
	vector<int> v3; //ans
	cd
	while(t--)
	{
		int a,b, cnt=0;
		bool a_check[5] = {false,};
		bool b_check[5] = {false,};
		cin >> a >> b;
		int flag = 0;
		
		for(int i=10000; cnt<5; cnt++, i/=10)
		{
			int temp;
			temp = a/i;
			if(temp == 0 && flag==0)
			{
				a_check[cnt] = true;
			}
			else
			{
				flag = 1;
				v1[cnt] = temp;
				a %= i;
			}	
		}

		flag = 0;
		cnt = 0;
		for(int i=10000; cnt<5; cnt++, i/=10)
		{
			int temp;
			temp = b/i;
			if(temp == 0 && flag==0)
			{
				b_check[cnt] = true;
			}
			else
			{
				flag = 1;
				v2[cnt] = temp;
				b %= i;
			}	
		}
		
		int a_arr[5][7], b_arr[5][7];
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<7; j++)
			{
				a_arr[i][j] = arr[v1[i]][j];
				b_arr[i][j] = arr[v2[i]][j];
			}
		}

		int ans = 0;		 
		for(int i=0; i<5; i++)
		{
			if(a_check[i] == true || b_check[i] == true)
			{
				if(a_check[i] == true)
				{
					for(int j=0; j<7; j++)
					{
						a_arr[i][j] = 0;
					}
				}
				if(b_check[i] == true)
				{
					for(int j=0; j<7; j++)
					{
						b_arr[i][j] = 0;
					}
				}
			}
		}
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<7; j++)
			{
				if(a_arr[i][j] != b_arr[i][j]) 
				{
					ans++;
				}
			}
		}	
		v3.push_back(ans);
	}	
	for(int i=0; i<v3.size(); i++)
	{
		cout << v3[i] << '\n';
	}
	
	return 0;
}
