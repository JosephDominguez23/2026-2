//
// Created by jdomi on 16/11/2026.
//

#ifndef POO_POLIMORFISMO_QUEUE_H
#define POO_POLIMORFISMO_QUEUE_H
#include "QueueNode.h"


class Queue {
private:
    QueueNode *top;
    QueueNode *rear;
public:
    Queue();

    bool is_empty();
    void enqueue(Package *pack);
    Package *dequeue();
};


#endif //POO_POLIMORFISMO_QUEUE_H