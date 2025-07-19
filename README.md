# 42gs
당일에 필요한 테스트 코드
<pre>
--- TEST CODE ---
Push_swap


1. 프로젝트 개요

a와 b스택이 있고,

a스택 : 랜덤으로 음수/양수를 포함한 정수가 들어있다.
b스택 : 비어있음



1. a를 오름차순으로 정렬한다.
2. 명령어들에 대해 구현한다.

sa : swap a - 스택 a의 가장 위에 있는 두 원소(혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.

sb : swap b - 스택 b의 가장 위에 있는 두 원소(혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.

ss : sa와 sb를 동시에 실행한다.

pa : push a - 스택 b에서 가장 위(탑)에 있는 원소를 가져와서, 스택 a의 맨 위(탑)에 넣는다. 스택 b가 비어 있으면 아무것도 하지 않는다.

pb : push b - 스택 a에서 가장 위(탑)에 있는 원소를 가져와서, 스택 b의 맨 위(탑)에 넣는다. 스택 a가 비어있으면 아무것도 하지 않는다.

ra : rotate a - 스택 a의 모든 원소들을 위로 1 인덱스만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.

rb : rotate b - 스택 b의 모든 원소들을 위로 1 인덱스만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.

rr : ra와 rb를 동시에 실행한다.

rra : reverse rotate a - 스택 a의 모든 원소들을 아래로 1 인덱스만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.

rrb : reverse rotate b - 스택 b의 모든 원소들을 아래로 1 인덱스만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.

rrr : rra와 rrb를 동시에 실행한다.




[ 연결 리스트 ]
메모리 상에 연속적이지 않은 노드들을 포인터를 연결해 만든 자료구조
각 노드는 데이터와 다음 노드를 가리키는 포인터를 가진다.

칸 사이의 간격이 메모리 상에 띄엄띄엄 있어도 선로만 연결되어 있으면 전체가 하나로 이어진다.

배열처럼 연속된 공간 X, 필요할 때마다 malloc 으로 새로운 노드를 만들어야 한다,
그리고 이를 next 포인터로 연결한다.

기본 구성은 아래와 같다.

typedef struct Node {
    int data;        // 칸 안에 저장할 값	
    struct Node *next; // 다음 칸을 가리키는 포인터
} Node;

typedef struct 형태로 구조체를 만들고, 
안에 원하는 만큼의 필드를 만든 뒤, 다음 칸을 가리키는 포인터를 추가한다.


struct Node *head;
> typedef struct Node 구조체는 Node라는 별칭을 가지고 있고,
이 별칭으로 연결하지 않고, 기본적인 구조체 형식을 가져와 연결하고 있는 것.
head 포인터에 struct Node 를 연결함으로써, typedef struct Node 안에 있는 모든 필드들에 접근할 수 있다.

N *head;
> 위와 완전히 동일함.


void push_front(Node **head, int value) {
    Node *n = malloc(sizeof(Node));
    n->data = value;
    n->next = *head;
    *head = n;
}

0. 파라미터에서 Node 형식으로 head를 이중포인터로, value를 정수형으로 받는다.
    이중 포인터  	> 함수 안에서 호출한 쪽의 head 변수 자체를 갱신(새 노드를 머리로)하기 위해서.
    value		> 노드 안에 있는 value를 저장하기 위해.

1. Node *n = malloc(sizeof(Node))
>> Node 구조체만큼 동적할당을 한다. 이를 노드 포인터 n에 저장하는 것.

n -> data = value;
n - > next = *head;
Node 구조체 형식으로 선언했던 n과 data를 연결한다. 그리고 이 값은 value다.
이전의 첫 번째 노드를 복사해서 n -> next에 저장한다. ( next는 문자와 전혀 관계가 없고,  )



*** 연결리스트를 잇는다 == 구조체의 틀을 만들고, 이를 여러 번 복사하여 그 안의 필드들을 사용하겠다는 뜻. ***

따라서 malloc을 각각 진행해야 하고,
포인터를 연결해야 하고, 
data 필드에 있는 값을 저장해서 계속 다음 칸으로 보내야 한다.









typedef struct Node{
    int data; // 저장할 실제 값
    struct Node *next; // 다음 노드의 주소(포인터)
} Node;

void stack_push(Node **top, int value) {
    Node *n = malloc(sizeof(Node));
    n->data = value;
    n->next = *top;
    *top = n;
}



함수의 signature 부터 짚어보면,

1. void stack_push(Node **top, int value);
> Node **top : 노드 포인터를 가리키는 포인터.










































































    
<pre/>
