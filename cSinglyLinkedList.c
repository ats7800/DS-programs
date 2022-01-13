#include<stdio.h>
#include<stdlib.h>

struct nodeSL{
    int data;
    struct nodeSL* next;
};
typedef struct nodeSL node;


int main(int argc, char const *argv[])
{
    node* A;
    A=NULL;
    node* temp = (node*)malloc(sizeof(node));

    // (*temp).data=2;
    // // or we could use temp->data
    // temp->next=NULL;
    // A->next=temp;
    // printf("%d",A->data);
    // temp = (node*)malloc(sizeof(node));
    // temp->data=3;
    // temp->next=NULL;
}
