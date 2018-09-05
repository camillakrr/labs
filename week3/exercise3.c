#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void print_list(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void insert_node(struct Node** head, int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = (*head);
    (*head) = node;
}

void delete_node(struct Node** head, int key)
{
    struct Node* tmp = *head, *prev;
    while (tmp != NULL && tmp->data != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        return;
    }
    prev->next = tmp->next;
    free(tmp);
}


