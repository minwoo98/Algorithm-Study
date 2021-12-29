#include <iostream>
#include <string>
using namespace std;

string check(string ss){
	
	int cnt = 0;	
	
	for(int i=0; i < ss.size(); i++)
	{
		if(ss[i] == '('){
			cnt += 1;
		}
		else if(ss[i] == ')'){
			cnt -= 1;				
		}
	}	
	
	if(cnt == 0)	return "YES";
	else if(cnt != 0) return "NO";
}

int main(void){
	
	int t;
	cin >>	t;
	
	while(t--)
	{
		string s;
		cin >> s;
		
		cout << check(s) << '\n';
	}
	
	return 0;	
}
