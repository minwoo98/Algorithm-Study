#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "linked_list.h"

int push(ll* head, ll* tail, const int data)
{
	add_node(head, tail, data);
}
int pop(ll* head)
{
	delete_node(head);
}
int top(ll* head)
{
	printf("top data : %d \n", head->link->data);
}
int empty(ll* head, ll* tail)
{
	if(head->link == tail)
	{
		printf("empty \n");
		return 0;
	}
	else
	{
		printf("not empty \n");
		return 0;
	}
}
int main(void)
{
	ll* head = init_node();
	ll* tail = init_node();
	head_to_tail(head, tail);
	
	push(head, tail, 1);
	push(head, tail, 2);
	push(head, tail, 3);
	push(head, tail, 4);
	print_node(head, tail);
	
	printf("---------------------- \n");
	
	top(head);	
	pop(head);
	pop(head);
	pop(head);
	
	empty(head, tail);	
	printf("---------------------- \n");
	
	pop(head);
	empty(head, tail);
	exit_node(&head, &tail);
	
	return 0;	
}
