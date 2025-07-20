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

void push_back(Node **head, int value){
    Node *new_node = malloc(sizeof(Node));
    if(!new_node)
        //malloc fail

    new_node -> data = value;
    new_node -> next = NULL;
    //null을 가리켜야 함, 스택처럼 쌓이는 것을 막기 위해.

    //함수의 파라미터로 받아온 *head가 빈 리스트일 경우,
    //head는 
    //이후 함수 탈출
    if(*head == NULL){
        *head = new_node;
        return;
    }

    //함수의 파라미터로써 받아온 head가 null이 아닌 경우에 
    //현재의 값을 다음 노드를 가리키게 하고, 이를 null이 나올 때까지 반복
    Node *cur = *head;
    while(cur -> next != NULL){
        cur = cur -> next;
    }
    cur -> next = new_node;
}



// sa : swap a - 스택 a의 가장 위에 있는 두 원소
// (혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.
void swap_sa(Node **head) {

}


// sb : swap b - 스택 b의 가장 위에 있는 두 원소
// (혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.

// ss : sa와 sb를 동시에 실행한다.

// pa : push a - 스택 b에서 가장 위(탑)에 있는 원소를 가져와서, 
// 스택 a의 맨 위(탑)에 넣는다. 스택 b가 비어 있으면 아무것도 하지 않는다.

// pb : push b - 스택 a에서 가장 위(탑)에 있는 원소를 가져와서, 
// 스택 b의 맨 위(탑)에 넣는다. 스택 a가 비어있으면 아무것도 하지 않는다.

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
    Node *head = NULL;
    // main > malloc > orders













    return 0;
}