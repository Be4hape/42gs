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
    write(1, "sb\n", 3);
    swap(b);
}

void swap_ss(Node **a, Node **b){
    write(1, "ss\n", 3);
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
    write(1, "pa\n", 3);
    if(!*b)
        return ;
    push(b, a);
}

void push_pb(Node **a, Node **b){
    write(1, "pb\n", 3);
    if(!*a)
        return ;
    push(a, b);
}
void rotate(Node **head){
    if(!*head || !(*head) -> next)
        return;

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
    write(1, "ra\n", 3);
    rotate(a);
}
void rotate_rb(Node **b){
    write(1, "rb\n", 3);
    rotate(b);
}
void rotate_rr(Node **a, Node **b){
    write(1, "rr\n", 3);
    rotate(a);
    rotate(b);
}

void rotate_rra(Node **a){
    write(1, "rra\n", 4);
    reverse_rotate(a);
}
void rotate_rrb(Node **b){
    write(1, "rrb\n", 4);
    reverse_rotate(b);
}
void rotate_rrr(Node **a, Node **b){
    write(1, "rrr\n", 4);
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
    int sign = 1;
    int INT_MAX = 2147483647;
    int INT_MIN = -2147483648;
    long long acc = 0;
    long long val = 0;

    while(str[i]){
        //공백, 탭, 줄내림
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        if(!str)
            break;

        sign = 1;
        acc = 0;
        
        //부호
        if(str[i] == '+' || str[i] == '-'){
            if(str[i] == '-')
                sign = -1;
            i++;
            if(!(str[i] >= '0' && str[i] <= '9'))
                return 0;
        }
        //숫자
        while(str[i] >= '0' && str[i] <= '9'){
            int d = str[i++] - '0';
            //overflow, 다음 연산에서 acc는 acc * 10 + d이기 때문에, 
            //overflow 검사를 / 10을 통해 한다. (수학적인 접근)
            if(acc > (INT_MAX - d) / 10)
                return 0;
            acc = acc * 10 + d;            
        }
        val = acc * sign;
        //최종 숫자에 부호를 넣은 값이 min과 max에 부합하는지 검사
        if(val > INT_MAX || val < INT_MIN)
            return 0;
        val = (int) val;
        
        //중복 검사
        if(contains(*head, val))
            return 0;
        save_head(head, val);
    }
    return 1;
}


//노드 길이 count, 
int list_size(Node *head){
    int count = 0;
    while(head){
        count++;
        head = head -> next;
    }

    return count;
}

//노드 최댓값, i
int list_max(Node *head){
    int i = head -> data;
    while(head){
        if(head -> data > i)
            i = head -> data;
        head = head -> next;
    }

    return i;
}

void rdx_sorting(Node **a, Node **b){
    int i = 0;
    int j = 0;
    int top = 0;

    //노드 길이, 최댓값
    int size = list_size(*a);
    int max_data = list_max(*a);

    //최대 데이터의 비트 추출, 그만큼 반복하기 위함
    int max_bit = 0;
    while((max_data >> max_bit) != 0)
        max_bit++;

    while(i < max_bit){
        j = 0;
        while(j < size){
            top = (*a) -> data;
            if(((top >> i) & 1) == 0)
                push_pb(a,b);
            else
                rotate_ra(a);
            j++;
        }
        while(*b)
            push_pa(a, b);
        i++;
    }
}

static int is_sorting(Node *head){
	while (head && head -> next){
		if ((head -> data) > (head -> next -> data))
			return (0);
		head = head -> next;
	}
	return (1);
}

static void sort_3(Node **a){
    //argument가 3개일 때, 직접 비교
    int x = (*a) -> data;
    int y = (*a) -> next -> data;
    int z = (*a) -> next -> next -> data;

    //1 3 2
    if(x < y && y > z && x < z){
        swap_sa(a);
        rotate_ra(a);
    }       
    //2 1 3
    else if (x > y && y < z && x < z)
        swap_sa(a);
    //2 3 1
    else if(x < y && y > z && x > z)
        rotate_rra(a);

    //3 1 2
    else if(x > y && y < z && x > z)
        rotate_ra(a);

    //3 2 1
    else if(x > y && y > z){
        swap_sa(a);
        rotate_rra(a);
    }
}

static int get_min(Node *head){
    int min;

    min = head -> data;
    while(head){
        if(head -> data < min){
            min = head -> data;
        }
        head = head -> next;
    }
    return min;
}

static int get_second(Node *head, int min){
    int second;
    
    second = 2147483647;
    while(head){
        if (head -> data != min && head -> data < second)
            second = head -> data;
        head = head -> next;
    }
    return second;
}



void sort_5(Node **a, Node **b){
    int min, second;

    min = get_min(*a);
    second = get_second(*a, min);

    while (list_size(*a) > 3){
        if((*a) -> data == min || (*a) -> data == second)
            push_pb(a, b);
        else
            rotate_ra(a);
    }
    sort_3(a);
    push_pa(a, b);
    push_pa(a, b);

}





int main(int ac, char **av){
    //입력은 ./push_swap 2 1 3 6 5 8
    //의 형태로 들어옴, 
    Node *headA = NULL;
    Node *headB = NULL;
    int i = 1;
    
    if(ac < 2)
        return 0;
    while(i < ac){
        if(!parsing(&headA, av[i])){
            print_error();
            free_list(&headA);
            return 1;
        }            
        i++;
    }
    //print_list(headA);

    // -- algorithms -- //

    int n = list_size(headA);
    if(is_sorting(headA))
        return 0;
    if(n == 2){
        swap_sa(&headA);
        return 0;
    }
    else if(n == 3){
        sort_3(&headA);
        return 0;
    }
    else if(n <= 5)
        sort_5(&headA, &headB);
    else
        rdx_sorting(&headA, &headB);
    free_list(&headA);
    return 0;
}