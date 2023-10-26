#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Stack {
    int stack[MAX_SIZE];
    int top;
} Stack;

void CreateStack(Stack* stack) { // 사이즈를 인자로 받지 않음
    stack->top = -1;
}

int isFull(Stack* stack) {
    if (stack->top >= MAX_SIZE - 1) { // 가득 찬 경우를 올바르게 검사
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
        printf("스택이 가득 찼습니다.\n");
        exit(1);
    }
    else {
        stack->top += 1; // top을 먼저 증가시키고 값을 저장
        stack->stack[stack->top] = value;
    }
}

int pop(Stack* stack) {
    int element;
    if (isEmpty(stack)) {
        printf("스택이 비어 있습니다.\n");
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
    printf("pop의 결과: %d\n", pop(&mystack));
    printf("pop의 결과: %d\n", pop(&mystack));

    printf("스택 내용: ");
    for (int i = 0; i <= mystack.top; i++) {
        printf("%d ", mystack.stack[i]);
    }

    return 0;
}
