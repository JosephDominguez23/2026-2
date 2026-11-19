//
// Created by jdomi on 16/11/2026.
//

#ifndef POO_POLIMORFISMO_QUEUENODE_H
#define POO_POLIMORFISMO_QUEUENODE_H
#include "Package.h"


class QueueNode {
private:
    Package *data;
    QueueNode *next;
public:
    QueueNode();

    friend class Queue;

};


#endif //POO_POLIMORFISMO_QUEUENODE_H