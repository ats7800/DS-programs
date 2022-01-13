#include <stdio.h>
#include <stdlib.h>

struct node
{
    int type;
    char valC;
    int valI;
    struct node *next;
};
typedef struct node Node;
void displayList(Node *heap)
{
    Node *trav;
    trav = heap;
    while (trav != NULL)
    {
        if (trav->type == 1)
            printf("%d, ", trav->valI);
        else
            printf("%c, ", trav->valC);
        // printf("%d, ", trav->val);
        trav = trav->next;
    }
}

int insert(Node *heap, Node *givenNode, int position)
{
    // position from head
    Node *trav;
    trav = heap;
    int affirmative = 0;
    int travPos = 1;
    if (position == 0)
    {
        givenNode->next = heap;
    }
    else
    {
        while (trav != NULL)
        {
            if (travPos == position)
            {
                givenNode->next = trav->next;
                trav->next = givenNode;
                affirmative = 1;
                break;
            }
            affirmative = 0;
            travPos++;
            trav = trav->next;
        }
    }

    return affirmative;
}

int main(int argc, char const *argv[])
{
    Node tail;
    Node head;
    Node innerOne;

    tail.valI = 1;
    tail.type = 1;
    innerOne.valC = 'A';
    innerOne.type = 0;
    head.valI = 3;
    head.type = 1;
    tail.next = NULL;
    innerOne.next = &tail;
    head.next = &innerOne;
    Node N1;
    N1.valC = 'b';
    N1.type = 0;
    insert(&head, &N1, 1);
    displayList(&head);
    return 0;
}
