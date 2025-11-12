#include "stdio.h"
#include "./src/CarProduction.h"

int main(void)
{
    CarProduction carProduction;
    initializeCarProduction(&carProduction);

    addOrderToProductionQueue(&carProduction, "Sedan", "Model S", "Red", 5);
    addOrderToProductionQueue(&carProduction, "SUV", "Model X", "Blue", 7);
    addOrderToProductionQueue(&carProduction, "Coupe", "Model 3", "Black", 4);

    printf("\nTotal Cars in Production: %d\n", carProduction.productionQueue.size);

    Car nextCar = peekNextCarInQueue(&carProduction);
    printf("\nNext car in queue:\n");
    seeCarInfo(&nextCar);

    Car producedCar = produceFirstCarInQueue(&carProduction);
    printf("\nProduced car:\n");
    seeCarInfo(&producedCar);

    nextCar = peekNextCarInQueue(&carProduction);
    printf("\nNext car in queue:\n");
    seeCarInfo(&nextCar);

    producedCar = produceFirstCarInQueue(&carProduction);
    printf("\nProduced car:\n");
    seeCarInfo(&producedCar);

    nextCar = peekNextCarInQueue(&carProduction);
    printf("\nNext car in queue:\n");
    seeCarInfo(&nextCar);

    producedCar = produceFirstCarInQueue(&carProduction);
    printf("\nProduced car:\n");
    seeCarInfo(&producedCar);

    printf("\nTotal Cars Produced: %d\n", carProduction.totalCarsProduced);

    freeCarProductionQueue(&carProduction);

    return 0;
}