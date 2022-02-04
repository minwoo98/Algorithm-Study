#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

ll* init_node(void)
{
	ll* node = NULL;
	node = calloc(1, sizeof(ll));

	if(node == NULL)
	{
		printf("Failed to allocate memory...");
		return NULL;
	}
	return node;
}

int head_to_tail(ll* head, ll* tail)
{
	head->link = tail;
}

int add_node(ll* front_node, ll* tail, int data)
{
	ll* node = init_node();
	node->data = data;
		
	if(front_node->link == tail)
	{ 
		front_node->link = node;
		node->link = tail;
	}
	else
	{	
		node->link = front_node->link;
		front_node->link = node;	
	}
	return 0;
}

int delete_node(ll* head)
{
	ll* delete_next_node = head->link->link;
	free(head->link);
	head->link = delete_next_node;
	
}
int exit_node(ll** head, ll** tail)
{
	if(*head == NULL || *tail == NULL)
	{
		return -1;
	}
	
	ll* cur = NULL;
	while(*head != *tail)
	{
		cur = *head;
		*head = (*head)->link;
		free(cur);
		cur = NULL;
	}
	
	free(*tail);
	return 0;
}
int print_node(ll* head, ll* tail)
{
	ll* current = head->link;
	while(current != tail)
	{
		printf("%d \n", current->data);
		current = current->link;
	}
	return 0;
}
