#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;



void push_front(Node **head, int value){
    Node *n = malloc(sizeof(Node));

    n -> data = value;
    n -> next = *head;

    *head = n;    
}

void print_list(){
    
}

int main(){
    Node *head = NULL;

    push_front(&head, 10);
    push_front(&head, 20);
    push_front(&head, 30);
    print_list(head);  // 출력: 30 20 10


    return 0;
}