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
	struct linked_list* temp;
	struct linked_list* temp2;
	
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
}

void delete_Node(int m) // delete m th node 
{
	struct linked_list* node = malloc(sizeof(struct linked_list));
	struct linked_list* pre_node;
		
	// delete first node
	if(m==1)
	{
		head = head->link;		
	}
	else
	{
		pre_node = head;
		int i;
		for(i=0; i<m-2; i++)
		{
			pre_node = pre_node->link;
		}
		struct linked_list* del_node = pre_node->link; 	
		pre_node->link = del_node->link;
	}
}
int main(void)
{	
	add_FrontNode(1);
	add_BackNode(2);
	add_BackNode(3);
	insert_Node(2,4); //2��° ��� �ڿ� 4 insert 
	delete_Node(3);
   // 1 2 3
	current = head;
	while(current != NULL)
	{
		printf("%d ", current->data);
		current = current->link;
	}	
	//free
	return 0;
}
