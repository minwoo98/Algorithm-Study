#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list
{
	int data;
	struct linked_list* link; //다음 노드의 주소를 저장하는 포인터 변수 
}ll;

ll* init_node(void);
int head_to_tail(ll* head, ll* tail);
int add_node(ll* front_node, ll* tail, int data);
int delete_node(ll* head);
int exit_node(ll** head, ll** tail);
int print_node(ll* head, ll* tail);

#endif
