// Stack implement with linked list as a header file
#include<iostream>
#include "linkedlist.h"
using namespace std;

class Stack{
    public:
    Linkedlist* list; 
    Stack(){
        list = new Linkedlist();
    }

    ~Stack(){
        delete list;
    }

    void push(int val){
        list -> insert(val);
    }

    int pop(){
        int val = list -> deleteHead();
        return val;
    }

    void peek() {
        if (list->isEmpty()) {
            cout << "Stack is empty!!" << endl;
            return;
        }
        cout << "Top: " << list->front() << endl;
    }
    
    bool isEmpty(){
        return list -> isEmpty();
    }
};

int main(){

    Stack s;
    s.push(12);
    s.push(13);
    s.push(20);
    s.push(25);
    s.push(30);
    s.list -> display();
    cout << "size: " << s.list->size() << endl;

    Stack s2;
    s2.push(5);
    s2.push(10);
    s2.push(15);
    s2.push(20);
    s2.push(25);
    s2.push(30);
    s2.list -> display();
    cout << "size: " << s2.list -> size() << endl;
    return 0; 
}