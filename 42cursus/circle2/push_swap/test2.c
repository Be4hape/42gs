#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void push_back{
    
}

void print_list(Node *head){
    
}


int main(){
    Node *head = NULL;

    push_back(&head, 1);  // [1]
    push_back(&head, 2);  // [1 → 2]
    push_back(&head, 3);  // [1 → 2 → 3]
    print_list(head);     // 출력: 1 2 3

    return 0;
}