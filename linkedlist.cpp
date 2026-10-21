#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = nullptr;
    }
};
Node* head = nullptr;

void insert(int val){

    Node* obj = new Node();
    obj -> data = val;
    obj -> next = nullptr;

    if(head == nullptr){
        head = obj;
    }else{
        Node* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        temp -> next = obj;
    }
}

void insertAt(int val){
    Node* obj = new Node();
    obj -> data = val;
    obj -> next = nullptr;

    if(head == nullptr){
        head = obj;
        return;
    }

    if(val <= head -> data){
        obj -> next = head;
        head = obj;
        return;
    }

    Node* temp = head; 
    while(temp -> next != nullptr && temp -> next-> data < val){
        temp = temp -> next;
    }

    obj -> next = temp -> next;
    temp -> next = obj;
}

void deleteAtEnd(){
    if(head == nullptr){
        cout << "List is empty!!" << endl;
        return;
    }

    if(head -> next == nullptr){
        delete head;
        head = nullptr;
    }else{
        Node* temp = head;
        while(temp -> next -> next != nullptr){
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = nullptr;
    }
}

int deleteHead(){
    if(head == nullptr){
        return -1;
    }

    int val = head -> data;
    Node* temp = head;
    head = temp -> next;
    delete temp;
    return val;
}

void deleteNode(int val){
    if(head == nullptr){
        cout << "List is empty!!" << endl;
        return;
    }

    Node* temp = head;

    if(temp -> data == val){
        deleteHead();
        return;
    }

    while(temp -> next != nullptr){
        if(temp -> next -> data == val){
            Node* obj = temp -> next;
            temp -> next = temp -> next -> next;
            delete obj;
        }
        else{
            temp = temp -> next;
        }
    }
}

bool search(int val){
    Node* temp = head;
    if(head == nullptr){
        return false;
    }

    while(temp != nullptr){
        if(temp -> data == val){
            cout << "Value exist in the list" << endl;
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

void display(){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << " nullptr" << endl;
}
