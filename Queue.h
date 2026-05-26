#pragma once
#include <iostream>
#include <stdexcept> // Необхідно для std::runtime_error

using std::cout;
using std::endl;

namespace myQueue {
    template <typename T>
    class Node {
    public:
        T info;
        Node* next;
        Node* prev;

        Node(T value) {
            info = value;
            next = prev = nullptr;
        }
    };

    // Queue - FIFO = first in, first out
    template <typename U>
    class Queue {
    protected:
        Node<U>* head;
        Node<U>* current;
    public:
        Queue() {
            head = current = nullptr;
        }

        virtual ~Queue() {
            while (!isEmpty()) {
                pop_front();
            }
        }

        bool isEmpty() const {
            return head == nullptr || current == nullptr;
        }

        U first() const {
            if (isEmpty()) throw std::runtime_error("Queue is empty!");
            return head->info;
        }

        void push_back(U value) {
            Node<U>* item = new Node<U>(value);

            if (isEmpty()) {
                head = current = item;
            }
            else {
                current->next = item;
                item->prev = current;
                current = item;
            }
        }

        void pop_front() {
            if (!isEmpty()) {
                if (head == current) {
                    delete head;
                    head = current = nullptr;
                }
                else {
                    head = head->next;
                    delete head->prev;
                    head->prev = nullptr;
                }
            }
        }

        void show() const {
            Node<U>* p = head;
            if (isEmpty()) cout << "Queue is empty!\n";
            else {
                while (p != nullptr) {
                    cout << p->info << " ";
                    p = p->next;
                }
                cout << endl;
            }
        }
    };
}