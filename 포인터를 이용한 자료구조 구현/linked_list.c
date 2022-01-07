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

void add_FrontNode(int n)
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
		node->link = head;
		head = node;
	}
}
void add_BackNode(int n)
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
void insert_Node(int m, int n) // insert node at m'th behind
{ 
	struct linked_list* node = malloc(sizeof(struct linked_list));
	struct linked_list* temp = malloc(sizeof(struct linked_list));
	struct linked_list* temp2 = malloc(sizeof(struct linked_list));
	node->data = n;
	
	temp = head;
	temp2 = head;
	int i;
	
	for(i=0; i<m; i++)
	{
		temp = temp->link;
		if(m-i != 1)
		{
			temp2 = temp2->link;
		}
	}
	temp2->link = node;
	node->link = temp;
	//temp = head->link->link;
	//head->link->link = node;
	//node->link = temp;		
}

/*
void show_Node()
{
	current = head;
	while(current != NULL)
	{
		printf("%d ", current->data);
		current = current->link;
	}	
}*/
int main(void)
{	
	add_FrontNode(1);
	add_BackNode(2);
	add_BackNode(3);
	add_BackNode(4);
	add_FrontNode(5);
	insert_Node(5,7);

	current = head;
	while(current != NULL)
	{
		printf("%d ", current->data);
		current = current->link;
	}	
	//free ���� ��!	
	return 0;
}
