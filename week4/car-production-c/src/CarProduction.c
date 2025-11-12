#include "CarProduction.h"
#include "stdio.h"
#include "stdlib.h"

void initializeCarProduction(CarProduction *carProduction)
{
    carProduction->totalCarsProduced = 0;
    initializeQueue(&carProduction->productionQueue);
}

void addOrderToProductionQueue(CarProduction *carProduction, const char *type, const char *model, const char *color, int seats)
{
    Car newCar = initializeCar(type, model, color, seats);
    enqueue(&carProduction->productionQueue, newCar);
}

Car produceFirstCarInQueue(CarProduction *carProduction)
{
    if (isQueueEmpty(&carProduction->productionQueue))
    {
        printf("No cars in the production queue to produce.\n");
        Car emptyCar = {0};
        return emptyCar;
    }

    carProduction->totalCarsProduced++;
    return dequeue(&carProduction->productionQueue);
}

Car peekNextCarInQueue(const CarProduction *carProduction)
{
    if (isQueueEmpty(&carProduction->productionQueue))
    {
        printf("No cars in the production queue\n");
        Car emptyCar = {0};
        return emptyCar;
    }

    return peek(&carProduction->productionQueue);
}

void freeCarProductionQueue(CarProduction *carProduction)
{
    for (int i = 0; i < carProduction->productionQueue.size; i++)
    {
        dequeue(&carProduction->productionQueue);
    }

    freeQueue(&carProduction->productionQueue);
}