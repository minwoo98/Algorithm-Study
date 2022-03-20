#include <iostream>
using namespace std;

const int MAX = 1000000;
bool check[MAX+1]; //all data initialized for 0

int main(int argc, char** argv)
{		
	check[0] = check[1] = true; // true: ¼Ò¼ö¾Æ´Ô
	
	for(int i=2; i*i<=MAX; i++)
	{
		if(check[i] == false)
		{
			for(int j = i+i; j<=MAX; j+=i)
			{
				check[j] = true; //delete 
			}
		}
	}

	int M, N;
	cin >> M >> N;
	
	for(int i=M; i<=N; i++)
	{
		if(check[i] == false)
		{
			cout << i << '\n';
		}
	}
	return 0;	
}
