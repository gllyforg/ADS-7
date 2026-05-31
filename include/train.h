// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Car {
    bool light;
    Car *next;
    Car *prev;
  };
  int countOp; // счетчик шагов (число переходов из вагона в вагон)
  Car *first; // точка входа в поезд (первый вагон)
 public:
  Train();
  void addCar(bool light);
  int getLength();          // вычислить длину поезда
  int getOpCount();          
};
#endif  // INCLUDE_TRAIN_H_
