#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Stack {
    int stack[MAX_SIZE];
    int top;
} Stack;

void CreateStack(Stack* stack) { // ����� ���ڷ� ���� ����
    stack->top = -1;
}

int isFull(Stack* stack) {
    if (stack->top >= MAX_SIZE - 1) { // ���� �� ��츦 �ùٸ��� �˻�
        return 1;
    }
    else return 0;
}

int isEmpty(Stack* stack) {
    if (stack->top == -1) {
        return 1;
    }
    else return 0;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("������ ���� á���ϴ�.\n");
        exit(1);
    }
    else {
        stack->top += 1; // top�� ���� ������Ű�� ���� ����
        stack->stack[stack->top] = value;
    }
}

int pop(Stack* stack) {
    int element;
    if (isEmpty(stack)) {
        printf("������ ��� �ֽ��ϴ�.\n");
        exit(1);
    }
    else {
        element = stack->stack[stack->top];
        stack->top -= 1;
        return element;
    }
}

int main() {
    Stack mystack;
    CreateStack(&mystack);

    push(&mystack, 2);
    push(&mystack, 8);
    push(&mystack, 7);
    push(&mystack, 5);

    printf("Is Empty: %d\n", isEmpty(&mystack));
    printf("pop�� ���: %d\n", pop(&mystack));
    printf("pop�� ���: %d\n", pop(&mystack));

    printf("���� ����: ");
    for (int i = 0; i <= mystack.top; i++) {
        printf("%d ", mystack.stack[i]);
    }

    return 0;
}
