#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list
{
	int data;
	struct linked_list* link; //다음 노드의 주소를 저장하는 포인터 변수 
}ll;

ll* init_node()
{
	ll* node = NULL;
	node = malloc(sizeof(ll));
	if(node == NULL)
	{
		printf("Failed to allocate memory...");
		return 0;
	}
	return node;
}

int add_node(ll* pre_node, int node_data)
{
	ll* node = init_node(); // generate new node
	node->data = node_data;
	
	if(pre_node == NULL)
	{
		pre_node = node;
		node->link = NULL;
	}
	else
	{
		pre_node->link = node;
		node->link = NULL;
	}
	return 0;
}

int print_node(ll* head_node)
{
	if(head_node == NULL) return 0;
	
	ll* current_node = head_node->link;
	while(current_node != NULL)
	{
		printf("data : %d \n", current_node->data);
		current_node = current_node->link;	
	}
	return 0;
}


int main(void)
{
	ll* head = malloc(sizeof(ll));
	ll* curr = NULL;

	if( head == NULL )
	{
		printf("Failed to allocate memory...");
		return 0;
	}
	
	add_node(head, 1);
	add_node(head->link, 2);
	add_node(head->link->link, 3);
	add_node(head->link->link->link, 4);
	print_node(head);
		
	return 0;
}
