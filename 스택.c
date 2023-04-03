#include <stdio.h>
#include <stdlib.h>
#define SIZE 100 //배열의 사이즈 정의

typedef struct StackType { //스택이라는 구조체 생성
    int arr[100]; //int형 데이터 100개 int형 100개니까 총 400바이트
    int top; //배열의 맨 위?

}StackType;

void init(StackType* s)//void init: 스택이 가지고 있는 탑을 -1로 초기화시켜줌
{
    s->top = -1; //배열은 index 0부터 시작 -1로 시작해서 0이면 데이터가 있고 -1이면 데이터가 없음
}

//empty: return 1
//!empty : return 0
int is_empty(StackType* s) { //스택이 비어있는지 확인하는 함수
    if (s->top == -1)
        return 1; //empty면 1을 리턴하고
    return 0;// empty가 아니면 0을 리턴
}

//full: retirn 1
//!full: return 0
int is_full(StackType* s) {
    if (s->top == SIZE - 1)
        return 1;
    return 0;
}



void push(StackType* s, int value) {
    if (is_full(s))
    {
        printf("Stack is full");
        exit(1);

    }
    printf("pushed: %d\n", value);
    s->arr[++(s->top)] = value;

}

int pop(StackType* s) { //return 형 필요, pop함수같은 경우는 is empty 판별해야함.
    if (is_empty(s)) { //아무것도 없는데 팝할게 없으면 오류남
        printf("Stack is empty");
    }
    return s->arr[(s->top)--]; //스택이 가리키는 arr이라는 배열에 스택에 있는 탑에 있는 데이터를 리턴.
}

//맨 위의 데이터를 리턴해주는 함수
int peek(StackType* s) { //스택의 최상단을 들여다보는 것
    if (is_empty(s)) {
        printf("Stack is empty");
        exit(1);
    }return s->arr[(s->top)]; //가장 최상단에 있는 데이터를 리턴
}


int main() {
    StackType s;
    init(&s); //stack 초기화됨

    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    printf("\npeek: %d\n", peek(&s));
    printf("\npop: %d\n", pop(&s));
    printf("\npop: %d\n", pop(&s));
    printf("\npop: %d\n", pop(&s));

    printf("\npop: %d\n", pop(&s));

    return 0;

}