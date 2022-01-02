#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
	int data;
	struct linked_list* link; //다음 노드의 주소를 저장하는 포인터 변수 
};
	
struct linked_list* head = NULL;
struct linked_list* tail = NULL;
struct linked_list* current = NULL;

void add_Node(int n)
{
	struct linked_list* node = malloc(sizeof(struct linked_list));
	node->data = n;
		
	if(head == NULL) //리스트가 비어있는 경우 
	{
		head = node;
		tail = node;
	}
	else //리스트에 데이터가 있는 경 
	{	
		tail->link = node;
		tail = node;
		
		tail->link = NULL;
	}
}

void show_Node()
{
	while(current != NULL)
	{
		printf("%d ", current->data);
		current = current->link;
	}	
}
int main(void)
{	
	add_Node(1);
	add_Node(2);
	add_Node(3);
	
	current = head;
	
	show_Node();

	//free 해줄 것!	
	return 0;
}
