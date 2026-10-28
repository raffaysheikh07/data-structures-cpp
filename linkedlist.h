// Linked list code converted into file 
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Node{
public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = nullptr;
    }
};

class Linkedlist{
private:
    Node* head;
public:

    Linkedlist(){
        head = nullptr;
    }

    ~Linkedlist(){
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    inline  bool isEmpty() { 
        return head == nullptr;
    }

    inline int front() { return head == nullptr ? -1 : head->data; }

    inline void insert(int val) {
    Node* obj = new Node();
    obj->data = val;
    obj->next = nullptr;

    if (head == nullptr) {
        head = obj;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = obj;
    }
}

inline void insertAt(int val) {
    Node* obj = new Node();
    obj->data = val;
    obj->next = nullptr;

    if (head == nullptr) {
        head = obj;
        return;
    }

    if (val <= head->data) {
        obj->next = head;
        head = obj;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data < val) {
        temp = temp->next;
    }

    obj->next = temp->next;
    temp->next = obj;
}

inline void deleteAtEnd() {
    if (head == nullptr) {
        std::cout << "List is empty!!" << std::endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
}

inline int deleteHead() {
    if (head == nullptr) {
        return -1;
    }

    int val = head->data;
    Node* temp = head;
    head = temp->next;
    delete temp;
    return val;
}

inline void deleteNode(int val) {
    if (head == nullptr) {
        std::cout << "List is empty!!" << std::endl;
        return;
    }

    while (head != nullptr && head->data == val) {
        deleteHead();
    }

    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == val) {
            Node* obj = temp->next;
            temp->next = temp->next->next;
            delete obj;
        } else {
            temp = temp->next;
        }
    }
}

inline bool search(int val) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == val) {
            std::cout << "Value exist in the list" << std::endl;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

inline int size(){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp -> next;
    }
    return count;
}

inline void display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << " nullptr" << std::endl;
}
};
#endif