#include "CarProductionQueue.h"
#include "stdlib.h"

void initializeQueue(CarProductionQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

void enqueue(CarProductionQueue *queue, Car car) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->car = car;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

Car dequeue(CarProductionQueue *queue) {
    if (isQueueEmpty(queue)) {
        Car emptyCar = {0};
        return emptyCar;
    }

    Node *temp = queue->front;
    Car car = temp->car;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
    return car;
}

Car peek(const CarProductionQueue *queue) {
    if (isQueueEmpty(queue)) {
        Car emptyCar = {0};
        return emptyCar;
    }
    return queue->front->car;
}

int isQueueEmpty(const CarProductionQueue *queue) {
    return queue->size == 0;
}

void freeQueue(CarProductionQueue *queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
}