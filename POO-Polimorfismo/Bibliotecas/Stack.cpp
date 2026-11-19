//
// Created by jdomi on 16/11/2026.
//

#include "Stack.h"

Stack::Stack() {
    top=nullptr;
}

bool Stack::is_empty() {
    return top==nullptr;
}

void Stack::push(Product *prod) {
    StackNode *node;
    node=new StackNode;
    node->data=prod;
    node->next=top;
    top=node;
}


Product *Stack::pop() {
    if (not is_empty()) {
        StackNode *node=top;
        Product *product=node->data;
        top=node->next;
        delete node;
        return product;
    }
    return nullptr;
}



