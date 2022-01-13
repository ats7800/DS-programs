// Enqueue operation and dequeue
// let queue length be 100

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int length = 3;
int array[3];
int front = 0;
int end = 0;

// int isEmpty(){
//     front==-1 &&
//     end == -1 &&
//     printf("Empty!\n");
//     return (front==-1&&end==-1);
// }

int isEmpty()
{
    (front - end) || printf("Empty!\n");
    (front - end) && printf("Not Empty yet!!!\n");
    return (front - end == 0);
}

int isFull()
{
    if (end - front == length-1 || end-front == -1)
    {
        printf("Full!\n");
        return 1;
    }
    else
    {
        printf("Not full!\n");
        return 0;
    }
}

int enqueue(int num)
{
    if (!isFull())
    {
        array[end] = num;
        if (end == length-1)
            end = 0;
        else
            end++;
        printf("Done!");
        return 1;
    }
    else
    {
        printf("Queue Full!!");
        return 0;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue empty already!!!\n");
        return 0;
    }
    else
    {
        int tempReturn = array[front];
        if (front == length-1)
            front = 0;
        else
            front++;
        printf("Done!\n");
        return tempReturn;
    }
}

int main(int argc, char const *argv[])
{
    enqueue(2);
    printf("%d\n",dequeue());
    enqueue(3);
    enqueue(7);
    printf("%d\n",dequeue());
    enqueue(6);
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    enqueue(85);
    enqueue(36);
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());

}
