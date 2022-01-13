#include <stdio.h>
#include <stdlib.h>

struct eachNode
{
    int value;
    struct eachNode *next;
};

typedef struct eachNode node;
node *front;

int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void enqueue(int n)
{
    node *newNode = (node *)malloc(sizeof(node));
    if(isEmpty()==1)
    {
        front->value = n;
        front->next = NULL;
    }
    else
    {
        node *temp;
        temp = front;
        while (temp->next)
        {
            temp = temp->next;
        }
        newNode->value = n;
        newNode->next = NULL;
        temp->next = newNode;
    }
    printf("%d inserted", n);
}

int dequeue()
{
    if(isEmpty()==1)
        printf("Already Empty");
    return 0;
    int temp = front->value;
    front = front->next;
    return temp;
}



int main(int argc, char const *argv[])
{
    front = NULL;
    enqueue(3);
    enqueue(2);
    enqueue(4);
    enqueue(8);
    enqueue(90);
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());




    return 0;
}
