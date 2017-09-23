#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
	char data[100001];
	struct node* prev;
	struct node* next;
} node;

node* push_front(node* tail, char c[])
{
	node* iter = tail;
	node* target = malloc(sizeof(node));
	strcpy(target->data, c);
	while(iter->prev != NULL)
		iter = iter->prev;
	target->prev = NULL;
	target->next = iter;
	iter->prev = target;
	return target;
}

int main()
{
	int i;
	char text[100001];
	while(scanf("%s", text) != EOF)
	{
		node* head = malloc(sizeof(node));
		node* tail = malloc(sizeof(node));
		node* space = malloc(sizeof(node));
		tail->prev = tail->next = space->prev = space->next = NULL;
		bool shift = false;
		for (i = 0 ; i < strlen(text) ; ++i)
		{
			if (text[i] == '[')
			{
				shift = true;
				continue;
			}
			else if (text[i] == ']')
			{
				shift = false;
				head = push_front(tail, space->data);
				memset(space->data, '\0', 100001);
				continue;
			}
			if (shift)
				strncat(space->data, &text[i], 1);
			else
				strncat(tail->data, &text[i], 1);
		}
		node* iter = head;
		while(iter != NULL)
		{
			printf("%s", iter->data);
			iter = iter->next;
		}
		printf("\n");
	}
	return 0;
}
