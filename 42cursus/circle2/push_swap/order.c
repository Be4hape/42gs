#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


//일반적인 방식으로 연결리스트 data에 value를 넣으려고 하면, 스택처럼 반대로 들어감
//뒤에서부터 넣어야 함.
// void push_front(Node **head, int value){
//     Node *new = malloc(sizeof(Node));
//     if(!new){
//         //malloc fail
//     }

//     new -> data = value;
//     new -> next = *head;
//     *head = new;
// }

void save_head(Node **head, int value){
    Node *new_node = malloc(sizeof(Node));
    if(!new_node){
        //memory allocation fail case
    }
        
    new_node -> data = value;
    new_node -> next = NULL;

    //head가 null이라면, 1번만 돌아야 하기 때문에, 바로 NULL을 포함하고 있는
    //new_node의 값을 *head에 대입한다.
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
   // -> 이 연산자는 . 연산자와 동일함
   // *n.next 와 n -> next 는 완전히 동일, 
   // 포인터 n이 가리키는 Node 구조체 내부의 next 멤버를 뜻함.
    Node *n = *a;
    *a = n -> next;
    n -> next = *b;

    //b로 스왑하여 연결한 노드를, 떼어온 노드 n으로 바꿔줌.
    *b = n;
}

void push_pa(Node **a, Node **b){
    //b의 가장 위의 데이터를 a의 가장 위로 옮긴다.
}

void push_pb(Node **a, Node **b){
    //a의 가장 위의 데이터를 b의 가장 위로 옮긴다.
}






// ra : rotate a - 스택 a의 모든 원소들을 위로 1 인덱스만큼 올린다. 
// 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.

// rb : rotate b - 스택 b의 모든 원소들을 위로 1 인덱스만큼 올린다. 
// 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.

// rr : ra와 rb를 동시에 실행한다.

// rra : reverse rotate a - 스택 a의 모든 원소들을 아래로 1 인덱스만큼 내린다. 
// 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.

// rrb : reverse rotate b - 스택 b의 모든 원소들을 아래로 1 인덱스만큼 내린다. 
// 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.

// rrr : rra와 rrb를 동시에 실행한다.

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

    save_head(&headA, 10);
    save_head(&headA, 20);
    save_head(&headA, 30);

    swap_sa(&headA);

    print_list(headA);
    print_list(headB);

    return 0;
}