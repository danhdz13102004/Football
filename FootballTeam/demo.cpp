#include "node.h"
#include <iostream>
using namespace std;

template <typename T>
class LLDB {
private:
    node<T> *head;
    node<T> *tail;

public:
    LLDB() : head(nullptr), tail(nullptr) {}
    ~LLDB() {}

    node<T> *makenode(T data) {
        node<T> *newNode = new node<T>(data);
        return newNode;
    }

    int size(node<T> *head) {
        int count = 0;
        node<T> *current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void push_fr(node<T> **head, T data) {
        node<T> *newNode = makenode(data);
        if (*head == nullptr) {
            *head = newNode;
            tail = newNode;
        } else {
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
        }
    }

    void push_b(node<T> **head, T data) {
        node<T> *newNode = makenode(data);
        if (*head == nullptr) {
            *head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insert(node<T> **head, int pos, T data) {
        if (pos <= 0) {
            push_fr(head, data);
        } else if (pos >= size(*head)) {
            push_b(head, data);
        } else {
            node<T> *newNode = makenode(data);
            node<T> *current = *head;
            for (int i = 1; i < pos; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    void delete_fr(node<T> **head) {
        if (*head != nullptr) {
            node<T> *temp = *head;
            *head = (*head)->next;
            if (*head != nullptr) {
                (*head)->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        }
    }

    void delete_b(node<T> **head) {
        if (*head == nullptr) {
            return;
        } else if ((*head)->next == nullptr) {
            delete *head;
            *head = nullptr;
        } else {
            node<T> *current = *head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            tail = current;
        }
    }

    void erase(node<T> **head, int pos) {
        if (pos <= 0) {
            delete_fr(head);
        } else if (pos >= size(*head) - 1) {
            delete_b(head);
        } else {
            node<T> *current = *head;
            for (int i = 1; i < pos; i++) {
                current = current->next;
            }
            node<T> *temp = current->next;
            current->next = temp->next;
            temp->next->prev = current;
            delete temp;
        }
    }

    void duyetxuoi(node<T> *head) {
        node<T> *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void duyetnguoc(node<T> *tail) {
        node<T> *current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void sort(node<T> *head) {
        // implementation for sorting the linked list
    }
};
