#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// 구조체 정의
struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

// 큐 생성 함수
struct CircularQueue* createQ() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// 큐가 비어있는지 확인하는 함수
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

// 큐가 가득 차있는지 확인하는 함수
int isFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// 큐에 요소 추가 함수
void enQueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("큐가 가득 찼습니다.\n");
    }
    else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("삽입: %d\n", value);
    }
}

// 큐에서 요소 제거 함수
int deQueue(struct CircularQueue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("큐가 비어 있습니다.\n");
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
    enQueue(queue, 6); // 큐가 가득 차서 삽입되지 않을 것임

    printf("Is Empty: %s\n", isEmpty(queue) ? "Yes" : "No");
    printf("Is Full: %s\n", isFull(queue) ? "Yes" : "No");

    return 0;
}
