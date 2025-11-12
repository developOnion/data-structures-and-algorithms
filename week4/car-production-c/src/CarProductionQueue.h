#ifndef CAR_PRODUCTION_QUEUE_H
#define CAR_PRODUCTION_QUEUE_H

#include "Car.h"

typedef struct Node
{
    Car car;
    struct Node *next;
} Node;

typedef struct CarProductionQueue
{
    Node *front;
    Node *rear;
    int size;
} CarProductionQueue;

void initializeQueue(CarProductionQueue *queue);
void enqueue(CarProductionQueue *queue, Car car);
Car dequeue(CarProductionQueue *queue);
Car peek(const CarProductionQueue *queue);
int isQueueEmpty(const CarProductionQueue *queue);
void freeQueue(CarProductionQueue *queue);

#endif