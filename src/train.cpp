// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>
Train::Train() : countOp(0), first(nullptr) {}
Train::~Train() {
    if (!first) return;
    Car* current = first;
    Car* nextCar = nullptr;
    do {
        nextCar = current->next;
        delete current;
        current = nextCar;
    } while (current != first);
}
void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}
int Train::getLength() {
    if (!first) return 0;
    // Алгоритм подсчета вагонов
    Car* current = first;
    Car* start = first;
    // Шаг 1: Включаем свет в текущем вагоне
    current->light = true;
    countOp = 0;  // Сбрасываем счетчик операций
    // Шаг 2: Идем вперед и выключаем свет, пока не встретим выключенный
    while (true) {
        current = current->next;
        countOp++;
        if (!current->light) {
            current->light = true;
            break;
        }
    }
    // Шаг 3: Продолжаем идти и считать, пока не встретим включенный свет
    int length = 1;
    while (true) {
        current = current->next;
        countOp++;
        length++;
        if (current->light) {
            break;
        }
    }
    return length;
}
int Train::getOpCount() const {
    return countOp;
}
void Train::resetOpCount() {
    countOp = 0;
}
