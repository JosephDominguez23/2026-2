//
// Created by jdomi on 16/11/2026.
//

#ifndef POO_POLIMORFISMO_STACK_H
#define POO_POLIMORFISMO_STACK_H
#include "StackNode.h"


class Stack {
private:
    StackNode *top;
public:

    Stack();

    bool is_empty();
    void push(Product *);
    Product *pop();
};


#endif //POO_POLIMORFISMO_STACK_H