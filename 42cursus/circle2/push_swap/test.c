#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;


//push_front, print_list
void push_front(Node **head, int value){
    Node *n = malloc(sizeof(Node));
    if(!n){
        //malloc 실패
        perror("malloc fail");
        exit(EXIT_FAILURE);
    }
    n -> data = value;
    n -> next = *head;
    *head = n;
}

void print_list(Node *head){
    Node *cur = head;
    while(cur){
        printf("%d ", cur -> data);
        cur = cur -> next;
    }
    printf("\n");
}


int main(){
    Node *head = NULL;
    
    push_front(&head, 10);
    push_front(&head, 20);
    push_front(&head, 30);
    print_list(head);  // 출력: 30 20 10


    while(head){
        Node *tmp = head;
        head = head -> next;
        free(tmp);
    }
    return 0;
}