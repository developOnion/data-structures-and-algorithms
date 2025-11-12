#ifndef CAR_PRODUCTION_H
#define CAR_PRODUCTION_H

#include "Car.h"
#include "CarProductionQueue.h"

typedef struct CarProduction
{
    int totalCarsProduced;
    CarProductionQueue productionQueue;
} CarProduction;

void initializeCarProduction(CarProduction *carProduction);
void addOrderToProductionQueue(CarProduction *carProduction, const char *type, const char *model, const char *color, int seats);
Car produceFirstCarInQueue(CarProduction *carProduction);
Car peekNextCarInQueue(const CarProduction *carProduction);
void freeCarProductionQueue(CarProduction *carProduction);

#endif