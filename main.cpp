#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char line[100];
    struct Node* next;
    struct Node* prev;
};

struct Node* addToEnd(struct Node* head, char* line)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->line, line);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}


void printListInReverse(struct Node* tail)
{
    struct Node* current = tail;
    while (current != NULL)
    {
        printf("%s", current->line);
        current = current->prev;
    }
}

void freeList(struct Node* head)
{
    struct Node* current = head;
    while (current != NULL)
    {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    FILE *file;
    char s[100];
    struct Node* head = NULL;

    file = fopen("likhitha.txt", "a");
    if (file == NULL)
    {
        puts("Cannot open file");

    }
    printf("Enter content:\n");
    while (strlen(gets(s)) > 0)
    {
        fputs(s, file);
        fputs("\n", file);
    }
    fclose(file);

    file = fopen("likhitha.txt", "r");
    if (file == NULL)
    {
        puts("Cannot open file");
    }
    while (fgets(s, sizeof(s), file) != NULL)
    {
        head = addToEnd(head, s);
    }
    fclose(file);

    struct Node* tail = head;
    while (tail != NULL && tail->next != NULL)
    {
        tail = tail->next;
    }

    printf("Reversed content of the file:\n");
    printListInReverse(tail);

    freeList(head);

    return 0;
}
