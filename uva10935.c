#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} node;

int node_size(node* head)
{
	int size = 1;
	node *iter = head;
	while(iter->next != NULL)
	{
		iter = iter->next;
		++size;
	}
	return size;
}

void push_back_node(node* head, int num)
{
	node *iter = head, *target = malloc(sizeof(node));
	target->data = num;
	target->next = NULL;
	target->prev = NULL;
	while(iter->next != NULL)
		iter = iter->next;
	iter->next = target;
	target->prev = iter;
}

void delete_tail_node(node* head)
{
	node *iter = head;
	while(iter->next != NULL)
		iter = iter->next;
	printf(" %d", iter->data);
	iter->prev->next = NULL;
	iter->prev = NULL;
	free(iter);
}

node* exchange_node(node* head)
{
	node *tail = head;
	while(tail->next != NULL)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	return tail;
}

int main()
{
	int i, card_size;
	while(1)
	{
		scanf("%d", &card_size);
		if (card_size == 0)
			break;
		node *card = malloc(sizeof(node));
		card->data = card_size;
		card->prev = card->next = NULL;
		for (i = 0 ; i < card_size - 1 ; ++i)
			push_back_node(card, card_size - i - 1);
		printf("Discarded cards:");
		while(node_size(card) > 1)
		{
			delete_tail_node(card);
			if (node_size(card) == 1)
				break;
			printf(",");
			card = exchange_node(card);
		}
		printf("\nRemaining card: %d\n", card->data);
	}
	return 0;
}
