#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void save_head(Node **head, int value){
    Node *new_node = malloc(sizeof(Node));
    if(!new_node){
        //malloc 실패 시, 프로그램 종료.
        exit(EXIT_FAILURE);
    }
    new_node -> data = value;
    new_node -> next = NULL;

    //빈 리스트면 꼬리탐색 없이 바로 연결한다. 
    // 바로 NULL을 포함하고 있는 new_node의 값을 *head에 대입한다.
    if(*head == NULL){
        *head = new_node;
        return ;
    }

    Node *cur = *head;
    while(cur -> next != NULL){
        cur = cur -> next;
        //current에 파라미터로 받아온 head의 값을 대입하고,
        //current-next가  null이 될 때까지 current는 다음 노드를 가리킨다.
    }

    //반복문이 끝난 뒤에, 제일 마지막 노드에 new_node. NULL을 연결한다.
    cur -> next = new_node;
}


// sa : swap a - 스택 a의 가장 위에 있는 두 원소
// (혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.
// sb : swap b - 스택 b의 가장 위에 있는 두 원소
// (혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.
// ss : sa와 sb를 동시에 실행한다.
void swap(Node **head){
    Node *first = *head;
    Node *second = first -> next;
    
    first -> next = second -> next;
    second -> next = first;
    
    *head = second;
}

void swap_sa(Node **a){
    swap(a);
}

void swap_sb(Node **b){
    swap(b);
}

void swap_ss(Node **a, Node **b){
    swap(a);
    swap(b);
}


// pa : push a - 스택 b에서 가장 위(탑)에 있는 원소를 가져와서, 
// 스택 a의 맨 위(탑)에 넣는다. 스택 b가 비어 있으면 아무것도 하지 않는다.
// pb : push b - 스택 a에서 가장 위(탑)에 있는 원소를 가져와서, 
// 스택 b의 맨 위(탑)에 넣는다. 스택 a가 비어있으면 아무것도 하지 않는다.

void push(Node **a, Node **b){
    Node *nA = *a;
    *a = nA -> next;

    Node *nB = *b;
    *b = nA;
    nA -> next = nB;
}

void push_pa(Node **a, Node **b){
    //b의 가장 위의 데이터를 a의 가장 위로 옮긴다.
    push(b, a);
}

void push_pb(Node **a, Node **b){
    //a의 가장 위의 데이터를 b의 가장 위로 옮긴다.
    push(a, b);
}



// ra : rotate a - 스택 a의 모든 원소들을 위로 1 인덱스만큼 올린다. 
// rb : rotate b - 스택 b의 모든 원소들을 위로 1 인덱스만큼 올린다. 
// rr : ra와 rb를 동시에 실행한다.
// rra : reverse rotate a - 스택 a의 모든 원소들을 아래로 1 인덱스만큼 내린다. 
// rrb : reverse rotate b - 스택 b의 모든 원소들을 아래로 1 인덱스만큼 내린다. 
// rrr : rra와 rrb를 동시에 실행한다.
void rotate(Node **head){
    Node *first = *head;
    *head = first -> next;

    Node *tail = *head;
    while(tail -> next)
        tail = tail -> next;
    tail = first -> next;
    first -> next = NULL;
}

void reverse_rotate(Node **head){
    Node *prev = NULL;
    Node *cur = *head;
    
    while(cur -> next){
        prev = cur;
        cur = cur -> next;
    }
    prev -> next = NULL;
    cur -> next = *head;
    *head = cur;
}


void rotate_ra(Node **a){
    rotate(a);
}
void rotate_rb(Node **b){
    rotate(b);
}
void rotate_rr(Node **a, Node **b){
    rotate(a);
    rotate(b);
}
void rotate_rra(Node **a){
    reverse_rotate(a);
}
void rotate_rrb(Node **b){
    reverse_rotate(b);
}
void rotate_rrr(Node **a, Node **b){
    reverse_rotate(a);
    reverse_rotate(b);
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
    // Node *head = NULL;
    // // main > malloc > orders
    // save_head(&head, 10);
    // save_head(&head, 20);
    // save_head(&head, 30);

    // //swap_sa(&head);
    // print_list(head);
    Node *headA = NULL;
    Node *headB = NULL;

    save_head(&headA, 1);
    save_head(&headA, 2);
    save_head(&headA, 3);
    save_head(&headA, 6);
    save_head(&headA, 5);
    save_head(&headA, 8);

    push_pb(&headA, &headB);
    push_pb(&headA, &headB);
    push_pb(&headA, &headB);

    rotate_ra(&headA);
    rotate_rb(&headB);

    print_list(headA);
    print_list(headB);

    return 0;
}