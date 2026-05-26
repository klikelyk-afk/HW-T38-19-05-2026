#pragma once
#include "Queue.h"

namespace myQueue {
    template<typename U>
    class PriorityQueue : public Queue<U> {
    public:
        void push_back(U value) {
            Node<U>* el = new Node<U>(value);

            if (Queue<U>::isEmpty()) {
                Queue<U>::head = Queue<U>::current = el;
            }
            else {
                Node<U>* p = Queue<U>::head;

                while (p != nullptr && p->info >= value) {
                    p = p->next;
                }

                if (p == Queue<U>::head) {
                    el->next = Queue<U>::head;
                    if (Queue<U>::head != nullptr) {
                        Queue<U>::head->prev = el;
                    }
                    Queue<U>::head = el;
                }
                else if (p == nullptr) {
                    Queue<U>::current->next = el;
                    el->prev = Queue<U>::current;
                    Queue<U>::current = el;
                }
                else {
                    el->next = p;
                    el->prev = p->prev;
                    p->prev->next = el;
                    p->prev = el;
                }
            }
        }
    };
}