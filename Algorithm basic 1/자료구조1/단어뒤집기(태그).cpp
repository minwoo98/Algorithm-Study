#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
void print_stack_reverse(stack<char> &s)
{
	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}
*/

int main(){
	
	string str;
	getline(cin, str); //공백도 입력으로 포함
	str += '\n';
	bool tag = false;
	stack<char> s;
	
	for(int i=0; str.size(); i++){
		if(str[i] == '<'){
			while(!s.empty()){
				cout << s.top();
				s.pop();
			}
			cout << str[i];
			tag = true;	
		}	
		else if(tag){
			cout << str[i];	
		}
		else if(str[i] == '>'){
			cout << str[i];
			tag = false;
		}
		else{
			if(str[i] == ' ' || str[i] == '\n'){
				while(!s.empty()){
				cout << s.top();
				s.pop();
				}
				cout << str[i];
			}
			else{
				s.push(str[i]);
			}
		}	
	}
	return 0;
}
