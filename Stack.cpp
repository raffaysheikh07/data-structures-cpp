#include<iostream>
#include "linkedlist.h"

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
};

int main(){

    Stack s;
    s.push(12);
    s.push(13);
    s.push(20);
    s.push(25);
    s.push(30);
    s.pop();
    s.list -> display();
    return 0; 
}