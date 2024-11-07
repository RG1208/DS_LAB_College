#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee
{
    char name[20];
    int age;
    int salary;
};

struct DoublyNode
{
    struct Employee data;
    struct DoublyNode *next;
    struct DoublyNode *prev;
};

struct DoublyNode *head = NULL;

void traversal()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct DoublyNode *cur = head;
        printf("NULL <--> ");
        while (cur != NULL)
        {
            printf("%s <--> ", cur->data.name);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

void insertAtHead(struct Employee data)
{
    struct DoublyNode *newNode = (struct DoublyNode *)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

void deleteAtTail()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct DoublyNode *cur = head;

    if (cur->next == NULL)
    {
        free(cur);
        head = NULL;
        return;
    }

    struct DoublyNode *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->prev->next = NULL;
    free(last);
}

int main()
{
    struct Employee e1, e2, e3;
    strcpy(e1.name, "Abc");
    strcpy(e2.name, "xyz");
    strcpy(e3.name, "Rachit");
    e1.age = 39;
    e2.age = 41;
    e3.age = 26;
    e1.salary = 100000;
    e2.salary = 200000;
    e3.salary = 300000;
    insertAtHead(e1);
    traversal();

    insertAtHead(e2);
    insertAtHead(e3);
    traversal();

    deleteAtTail();
    traversal();

    deleteAtTail();
    traversal();

    return 0;
}