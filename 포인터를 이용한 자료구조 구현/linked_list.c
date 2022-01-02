#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
	int data;
	struct linked_list* link; //���� ����� �ּҸ� �����ϴ� ������ ���� 
};
	
struct linked_list* head = NULL;
struct linked_list* tail = NULL;
struct linked_list* current = NULL;

void add_Node(int n)
{
	struct linked_list* node = malloc(sizeof(struct linked_list));
	node->data = n;
		
	if(head == NULL) //����Ʈ�� ����ִ� ��� 
	{
		head = node;
		tail = node;
	}
	else //����Ʈ�� �����Ͱ� �ִ� �� 
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

	//free ���� ��!	
	return 0;
}
