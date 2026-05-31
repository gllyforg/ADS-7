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
    newCar->next = nullptr;
    newCar->prev = nullptr;
    
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
    
    countOp = 0;
    Car* current = first;
    
    // Step 1: Turn off current light (if on)
    if (current->light) {
        current->light = false;
    }
    
    int step = 1;
    
    // Step 2: Find the end marker
    while (true) {
        // Move forward 'step' cars
        for (int i = 0; i < step; i++) {
            current = current->next;
            countOp++;
        }
        
        if (current->light) {
            // Found a lit car - turn it off and go back
            current->light = false;
            countOp++;
            
            for (int i = 0; i < step; i++) {
                current = current->prev;
                countOp++;
            }
            step = 1;
        } else {
            // Found unlit car - turn it on and exit
            current->light = true;
            countOp++;
            break;
        }
    }
    
    // Step 3: Count all cars
    int length = 0;
    current = first;
    do {
        length++;
        current = current->next;
        countOp++;
    } while (current != first);
    
    return length;
}

int Train::getOpCount() const {
    return countOp;
}

void Train::resetOpCount() {
    countOp = 0;
}
