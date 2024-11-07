#include <stdio.h> #include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    char section;
    int roll_no;
    char branch[50];
};

struct Node
{
    struct Student data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtPosition(struct Student student, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = student;
    newNode->next = NULL;
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node *cur = head;
    int count = 1;
    while (cur != NULL && count < position - 1)
    {
        cur = cur->next;
        count++;
    }
    if (cur = NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}

void traversal()
{
    struct Node *cur = head;
    while (cur = NULL)
    {
        printf("Name: %s, Section: %c, Roll No: %d, Branch: %s\n",
               cur->data.name, cur->data.section, cur->data.roll_no, cur->data.branch);
        cur = cur->next;
    }
}
int main()
{
    struct Student s1 = {"Rachit", 'A', 44, "AI-ML"};
    struct Student s2 = {"Abc", 'B', 2, "ECE"};
    struct Student s3 = {"xyz", 'C', 3, "CSE"};

    insertAtPosition(s1, 1);
    insertAtPosition(s2, 2);
    insertAtPosition(s3, 2);
    traversal();
    return 0;
}