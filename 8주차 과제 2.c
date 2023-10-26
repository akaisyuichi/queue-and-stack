#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// ����ü ����
struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

// ť ���� �Լ�
struct CircularQueue* createQ() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// ť�� ����ִ��� Ȯ���ϴ� �Լ�
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

// ť�� ���� ���ִ��� Ȯ���ϴ� �Լ�
int isFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// ť�� ��� �߰� �Լ�
void enQueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("ť�� ���� á���ϴ�.\n");
    }
    else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("����: %d\n", value);
    }
}

// ť���� ��� ���� �Լ�
int deQueue(struct CircularQueue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("ť�� ��� �ֽ��ϴ�.\n");
        return -1;
    }
    else {
        item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        }
        else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return item;
    }
}

int main() {
    struct CircularQueue* queue = createQ();

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);

    printf("Dequeued: %d\n", deQueue(queue));
    printf("Dequeued: %d\n", deQueue(queue));

    enQueue(queue, 4);
    enQueue(queue, 5);
    enQueue(queue, 6); // ť�� ���� ���� ���Ե��� ���� ����

    printf("Is Empty: %s\n", isEmpty(queue) ? "Yes" : "No");
    printf("Is Full: %s\n", isFull(queue) ? "Yes" : "No");

    return 0;
}
