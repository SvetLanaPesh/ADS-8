// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : first(nullptr), countOp(0) {}
void Train::addCage(bool light) {
    Cage* item = new Cage;
    item->light = light;
    item->next = nullptr;
    item->prev = nullptr;
    if (!first) {
        first = item;
        first->next = item;
        first->prev = item;
    } else {
        item->prev = first->prev;
        item->next = first;
        first->prev->next = item;
        first->prev = item;
    }
}
int Train::getLength() {
    Cage* temp = first;
    temp->light = true;
    int count = 1;
    while (true) {
        temp = temp->next;
        if (temp->light == false) {
            count++;
            countOp++;
        } else {
            temp->light = false;
            for (int i = count; i > 0; i--) {
                temp = temp->prev;
                countOp++;
            }
            countOp++;
            if (temp->light == false) {
                return count;
            } else {
                count = 1;
            }
        }
    }
}
int Train::getOpCount() {
    return countOp;
}
