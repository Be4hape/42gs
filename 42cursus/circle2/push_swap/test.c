#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
} N;

void push_front(N **head, int value){
    
}

void print_list(){
    
}



int main(){
    N *head = NULL;

    push_front(&head, 10);
    push_front(&head, 20);
    push_front(&head, 30);
    print_list(head);  // 출력: 30 20 10

    return 0;
}