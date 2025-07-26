#include "utils.h"
//read, write, malloc, free, exit

void save_head(Node **head, int value){
    Node *new_node = malloc(sizeof(Node));
    if(!new_node){
        exit(EXIT_FAILURE);
    }
    new_node -> data = value;
    new_node -> next = NULL;
    if(*head == NULL){
        *head = new_node;
        return ;
    }
    Node *cur = *head;
    while(cur -> next != NULL){
        cur = cur -> next;
    }    
    cur -> next = new_node;
}

void swap(Node **head){
    Node *first = *head;
    Node *second = first -> next;
    
    first -> next = second -> next;
    second -> next = first;
    
    *head = second;
}

void swap_sa(Node **a){
    write(1, "sa\n", 3);
    swap(a);
}

void swap_sb(Node **b){
    swap(b);
}

void swap_ss(Node **a, Node **b){
    swap(a);
    swap(b);
}

void push(Node **a, Node **b){
    Node *nA = *a;
    *a = nA -> next;

    Node *nB = *b;
    *b = nA;
    nA -> next = nB;
}

void push_pa(Node **a, Node **b){
    if(!*b)
        return ;
    push(b, a);
}

void push_pb(Node **a, Node **b){
    if(!*a)
        return ;
    push(a, b);
}
void rotate(Node **head){
    Node *first = *head;
    *head = first -> next;
    Node *cur = *head;
    
    while(cur -> next) 
        cur = cur -> next;
    cur -> next = first;
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

//Error 출력
static void print_error(void){
    write(2, "Error\n", 6);
}

//중복 검사, 중복일 시 return 1
static int contains(Node *head, int v){
    while(head){
        if(head -> data == v)
            return 1;
        head = head -> next;
    }
    return 0;
}

//리스트 전체 해제
static void free_list(Node **head){
    Node *cur = *head;
    Node *nn;

    while(cur){
        //free로 해제한 뒤에 node 연결
        nn = cur -> next;
        free(cur);
        cur = nn;
    }
    *head = NULL;
}

static int parsing(Node **head, const char *str){
    int i = 0;
    int value;
    int sign = 1;
    int INT_MAX = 2147483647;
    int INT_MIN = -2147483648;
    long long acc = 0;

    while(str[i]){
        //공백, 탭, 줄내림
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        if(!str)
            break;
        //부호
        if(str[i] == '+' || str[i] == '-'){
            if(str[i] == '-')
                sign = -1;
            i++;
        }
        //숫자
        while(!(str[i] >= '0' && str[i] <= '9'))
            return 0;

        



        //정수 min max 
        if(str[i] >= INT_MAX || str[i] <= INT_MIN)
            return 0;

        




        i++;
    }
}








int main(int argc, char **argv){
    //입력은 ./push_swap 2 1 3 6 5 8
    //의 형태로 들어옴, 
    
    





    //## subject ex test
    // save_head(&headA, 1);
    // save_head(&headA, 2);
    // save_head(&headA, 3);
    // save_head(&headA, 6);
    // save_head(&headA, 5);
    // save_head(&headA, 8);

    // push_pb(&headA, &headB);
    // push_pb(&headA, &headB);
    // push_pb(&headA, &headB);

    // print_list(headA);
    // print_list(headB);

    // rotate_ra(&headA);
    // rotate_rb(&headB);

    // print_list(headA);
    // print_list(headB);

    // rotate_rra(&headA);
    // rotate_rrb(&headB);

    // print_list(headA);
    // print_list(headB);

    // swap_sa(&headA);

    // print_list(headA);
    // print_list(headB);

    // push_pa(&headA, &headB);
    // push_pa(&headA, &headB);
    // push_pa(&headA, &headB);

    // print_list(headA);
    // print_list(headB);

    // //## pa, pb > b가 비어있는 상태, a가 비어있는 상태
    // Node *headA = NULL;
    // Node *headB = NULL;
    // save_head(&headA, 1);
    // save_head(&headA, 2);
    // save_head(&headA, 3);
    // save_head(&headA, 6);
    // save_head(&headA, 5);
    // save_head(&headA, 8);
    // print_list(headA);

    // push_pa(&headA, &headB);
    // print_list(headA);

    return 0;
}