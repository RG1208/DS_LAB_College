#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct College
{
    char name[50];
    char location[50];
    int establishedYear;
    struct College *next;
};

struct College *createNode(char *name, char *location, int year)
{
    struct College *newNode = (struct College *)malloc(sizeof(struct College));
    strcpy(newNode->name, name);
    strcpy(newNode->location, location);
    newNode->establishedYear = year;
    newNode->next = NULL;
    return newNode;
}
void insertAtFront(struct College **head, char *name, char *location, int year)
{
    struct College *newNode = createNode(name, location, year);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = head;
    }
    else
    {
        struct College *temp = *head;
        while (temp->next != *head)
        {

            temp - temp->next;
            newNode->next = *head;
            temp->next = newNode;
            *head = newNode;
        }
        printf("College inserted at the front: %s\n", name);
    }
}
void deleteAtEnd(struct College **head)
{
    if (*head == NULL)
    {
        printf("List is empty, No deletion performed.\n");
        return;
    }
    if ((*head)->next == *head)
    {
        printf("College deleted from the end: %s\n", (*head)->name);
        free(*head);
        *head = NULL;
    }
    else
    {
        struct College *temp = *head;
        struct College *prev = NULL;
        while (temp->next != *head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = *head;
        printf("College deleted from the end: %s\n", temp->name);
        free(temp);
    }
}
void displayList(struct College *head)
{

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct College *temp = head;
    do
    {
        printf("College Name: %s, Location: %s, Established Year: %d\n", temp->name, temp->location, temp->establishedYear);
        temp = temp->next;
    } while (temp = head);
}
int main()
{
    struct College *head = NULL;
    insertAtFront(&head, "VIPS", "Pitampura", 2000);
    insertAtFront(&head, "MAIT", "Rithala", 1999);
    insertAtFront(&head, "BPIT", "Rohini", 2007);
    printf("\nCircular Linked List after insertions: \n");
    displayList(head);
    deleteAtEnd(&head);
    printf("\nCircular Linked List after deletion: \n");
    displayList(head);
    return 0;
}