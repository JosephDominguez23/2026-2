//
// Created by jdomi on 16/11/2026.
//

#include "Queue.h"

Queue::Queue() {
    top=nullptr;
    rear=nullptr;
}

bool Queue::is_empty() {
    return top==nullptr;
}

void Queue::enqueue(Package *pack) {
    QueueNode *node;
    node=new QueueNode;
    node->data=pack;
    if (is_empty()) {
        top=node;
    } else {
        rear->next=node;
    }
    rear=node;
}

Package *Queue::dequeue() {
    if (not is_empty()) {
        QueueNode *node=top;
        Package *pack=node->data;
        top=node->next;
        if (top==nullptr) rear=nullptr;
        delete node;
        return pack;
    }
    return nullptr;
}



