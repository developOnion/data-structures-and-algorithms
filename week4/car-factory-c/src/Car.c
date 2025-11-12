#include "Car.h"
#include "stdio.h"

Car initializeCar(const char *type, const char *model, const char *color, int seats) {
    Car car;

    car.type = (char*) type;
    car.model = (char*) model;
    car.color = (char*) color;

    car.seats = seats;

    return car;
}

void seeCarInfo(const Car *car) {
    printf("Car Type: %s\n", car->type);
    printf("Model: %s\n", car->model);
    printf("Color: %s\n", car->color);
    printf("Seats: %d\n", car->seats);
}