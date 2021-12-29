#include <iostream>
#include <string>
using namespace std;

struct Queue{
	int data[10000];
	int begin, end;
	Queue(){
		begin = 0;
		end = 0;
	}
	void push(int num){
		data[end] = num; 
		end += 1;
	}
	bool empty()
	{
		if(begin == end) return 1;
		else return 0;
	}
	int pop(){
		if(!empty())
		{
			begin += 1;
			return data[begin-1];		
		}
		else return -1;
	}
	int size(){
		return end - begin;
	}
	int front(){
		if(!empty())	return data[begin];
		else return -1;
	}
	int back(){
		if(!empty()) return data[end-1];
		else return -1;
	}	
};

int main(void)
{
	int n;	
	cin >> n;
	
	Queue q;
	
	while(n--)
	{
		string s;
		cin >> s;
		
		if(s == "push")	{
			int x;
			cin >> x;	
			q.push(x);
		}
		else if(s == "pop"){
			cout << q.pop() << '\n';
		}
		else if(s == "size"){
			cout << q.size() << '\n';
		}
		else if(s == "empty"){
			cout << q.empty() << '\n';
		}
		else if(s == "front"){
			cout << q.front() << '\n';
		}
		else if(s == "back"){
			cout << q.back() << '\n';
		}
	}
	return 0;	
}
