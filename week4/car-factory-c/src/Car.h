#ifndef CAR_H
#define CAR_H

typedef struct Car
{
    char *model;
    char *color;
    char *type;
    int seats;
} Car;

Car initializeCar(const char *type, const char *model, const char *color, int seats);
void seeCarInfo(const Car *car);

#endif