//
// Created by jdomi on 16/11/2026.
//

#ifndef POO_POLIMORFISMO_STACKNODE_H
#define POO_POLIMORFISMO_STACKNODE_H
#include "Product.h"


class StackNode {
private:
    Product *data;
    StackNode *next;
public:
    StackNode();

    friend class Stack;
};


#endif //POO_POLIMORFISMO_STACKNODE_H