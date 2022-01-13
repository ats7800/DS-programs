#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node listNode;

void makeNull(listNode *head)
{
    head = NULL;
}

listNode first(listNode *head)
{
    return *head;
}

void printList(listNode *head)
{
    listNode *trav;
    trav = head;
    while (trav != NULL)
    {
        printf("%d, \n", trav->value);
        trav = trav->next;
    }
}

int insertAfter(listNode *head, int x, int y)
{
    int affermative = 0;
    listNode *trav;
    trav = head;
    while (trav != NULL)
    {
        if (trav->value == x)
        {
            listNode *temp = (listNode *)malloc(sizeof(listNode));
            temp->value = y;
            temp->next = trav->next;
            trav->next = temp;
            affermative = 1;
        }
        trav = trav->next;
    }

    affermative || printf("Can not find the value entered in the list!!!\n");
    return affermative;
}

int insertBefore(listNode *head, int x, int y)
{
    int affermative = 0;
    if (head->value == x)
    {
        listNode *temp = (listNode *)malloc(sizeof(listNode));
        temp->value = head->value;
        temp->next = head->next;
        head->value = y;
        head->next = temp;
        return 1;
    }
    listNode *travPrev;
    listNode *trav;
    travPrev = head;
    trav = travPrev->next;
    while (trav != NULL)
    {
        if (trav->value == x)
        {
            listNode *temp = (listNode *)malloc(sizeof(listNode));
            temp->value = y;
            temp->next = travPrev->next;
            travPrev->next = temp;
            affermative = 1;
        }
        trav = trav->next;
        travPrev = travPrev->next;
    }

    affermative || printf("Can not find the value entered in the list!!!\n");
    return affermative;
}

listNode *previous(listNode *head, int i)
{
    listNode *travPrev;
    listNode *trav;
    trav = head->next;
    travPrev = head;
    int success = 0;
    while (trav != NULL)
    {
        if (trav->value == i)
        {
            success = 1;
            break;
        }
        trav = trav->next;
        travPrev = travPrev->next;
    }
    success || printf("error!!! \nvalue not found!\n");
    return success ? travPrev : NULL;
}

listNode *next(listNode *head, int i)
{
    listNode *trav;
    trav = head;
    int success = 0;
    while (trav != NULL)
    {
        if (trav->value == i && trav->next != NULL)
        {
            success = 1;
            break;
        }
        trav = trav->next;
    }
    success || printf("error!!! \nvalue not found!\n");
    return success ? trav->next : NULL;
}

listNode *end(listNode *head)
{

    listNode *trav;
    trav = head;

    while (trav->next != NULL)
    {
        trav = trav->next;
    }

    return trav;
}

int length(listNode *head)
{
    int len = 0;
    listNode *trav;
    trav = head;
    while (trav != NULL)
    {
        len++;
        trav = trav->next;
    }
    return len;
}
int isEmpty(listNode *head)
{
    return head ? 1 : 0;
}

void removeDuplicates(listNode *head)
{
    int array[length(head)];
    int indexInArr = 0;
    listNode *trav;
    listNode *travPrev;
    travPrev = head;
    trav = travPrev->next;
    array[indexInArr++] = head->value;
    while (trav != NULL)
    {
        int remove = 0;
        for (int i = 0; i < indexInArr; i++)
        {
            if (array[i] == trav->value)
            {
                remove = 1;
                break;
            }
        }
        if (remove)
        {
            trav = trav->next;
            travPrev->next = trav;
        }
        else
        {
            array[indexInArr++] = trav->value;
            trav = trav->next;
            travPrev = travPrev->next;
        }
    }
}

void reverseInPlace(listNode *head)
{
    listNode *trav1;
    listNode *trav2;
    listNode *trav3;
    listNode *temp = (listNode *)malloc(sizeof(listNode));
    temp->value = head->value;
    temp->next = NULL;

    trav1 = head->next;
    trav2 = temp;
    trav3 = temp;

    while (trav1 != NULL)
    {
        trav2 = trav1;
        trav1 = trav1->next;
        trav2->next = trav3;
        trav3 = trav2;
    }
    head->value = trav3->value;
    head->next = trav3->next;
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void concatenate(listNode *head1, listNode *head2)
{
    listNode *trav;
    trav = head1;
    while (trav->next != NULL)
    {
        trav = trav->next;
    }
    trav->next = head2;
}

void merge(listNode *head1, listNode *head2)
{
    listNode *trav;
    concatenate(head1, head2);
    int arr[length(head1)];
    trav = head1;
    int i = 0;
    while (trav != NULL)
    {
        arr[i++] = trav->value;
        trav = trav->next;
    }
    qsort(arr, length(head1), sizeof(int), cmpfunc);
    trav = head1;
    int j = 0;
    while (trav != NULL)
    {
        trav->value=arr[j++];
        trav=trav->next;
    }
}

int main()
{

    listNode *head;
    listNode A;
    listNode B;
    listNode C;
    head = &A;
    A.value = 1;
    A.next = &B;
    B.value = 2;
    B.next = &C;
    C.value = 3;
    C.next = NULL;
    printf("List 1:\n");
    printList(head);
    insertAfter(head, 3, 8);
    insertAfter(head, 3, 9);
    insertAfter(head, 3, 9);
    insertAfter(head, 2, 9);
    insertBefore(head, 1, 9);
    insertBefore(head, 1, 9);
    insertAfter(head, 8, 9);
    printf("List 1 after insertion after and before:\n");
    printList(head);
    printf("list 1 after removing duplicates:\n");
    removeDuplicates(head);
    printList(head);
    printf("List 1 Reaversed:\n");
    reverseInPlace(head);
    printList(head);

    listNode *headNew;
    listNode a;
    listNode b;
    listNode c;
    headNew = &a;
    a.value = 1;
    a.next = &b;
    b.value = 2;
    b.next = &c;
    c.value = 3;
    c.next = NULL;

    printf("List 1 and 2 Merged and (sorted):\n");
    merge(headNew, head);
    printList(headNew);
    printf("Concatenated after removing duplicates:\n");
    removeDuplicates(headNew);
    printList(headNew);

}
