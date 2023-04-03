#include <stdio.h>
#include <stdlib.h>
#define SIZE 100 //�迭�� ������ ����

typedef struct StackType { //�����̶�� ����ü ����
    int arr[100]; //int�� ������ 100�� int�� 100���ϱ� �� 400����Ʈ
    int top; //�迭�� �� ��?

}StackType;

void init(StackType* s)//void init: ������ ������ �ִ� ž�� -1�� �ʱ�ȭ������
{
    s->top = -1; //�迭�� index 0���� ���� -1�� �����ؼ� 0�̸� �����Ͱ� �ְ� -1�̸� �����Ͱ� ����
}

//empty: return 1
//!empty : return 0
int is_empty(StackType* s) { //������ ����ִ��� Ȯ���ϴ� �Լ�
    if (s->top == -1)
        return 1; //empty�� 1�� �����ϰ�
    return 0;// empty�� �ƴϸ� 0�� ����
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

int pop(StackType* s) { //return �� �ʿ�, pop�Լ����� ���� is empty �Ǻ��ؾ���.
    if (is_empty(s)) { //�ƹ��͵� ���µ� ���Ұ� ������ ������
        printf("Stack is empty");
    }
    return s->arr[(s->top)--]; //������ ����Ű�� arr�̶�� �迭�� ���ÿ� �ִ� ž�� �ִ� �����͸� ����.
}

//�� ���� �����͸� �������ִ� �Լ�
int peek(StackType* s) { //������ �ֻ���� �鿩�ٺ��� ��
    if (is_empty(s)) {
        printf("Stack is empty");
        exit(1);
    }return s->arr[(s->top)]; //���� �ֻ�ܿ� �ִ� �����͸� ����
}


int main() {
    StackType s;
    init(&s); //stack �ʱ�ȭ��

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