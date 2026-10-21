#include<iostream>
#include "linkedlist.h"
using namespace std;

class Stack{
    public:
    Linkedlist* list; 
    Stack(){
        list = new Linkedlist();
    }

    void push(int val){
        list -> insertAt(val);
    }

    int pop(){
        int val = list -> deleteHead();
        return val;
    }

    void peek(){
    if(head == nullptr){
        cout << "Stack is empty!!" << endl;
        return;
    }
    cout << "Top: " << head -> data << endl;
}

    bool isEmpty(){
        return head == nullptr;
}
};

int main(){

    Stack s;
    s.push(12);
    s.push(13);
    s.push(20);
    s.push(25);
    s.push(30);
    s.pop();
    s.peek();
    s.list -> display();
    return 0; 
}