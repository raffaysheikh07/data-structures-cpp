// Stack implement with linked list code
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

class Stack{
    private:
        Node* head;
        int size;
    public:
        Stack(){
            head = nullptr;
            size = 0;
        }

        ~Stack(){
    while(head != nullptr){
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
}

    void push(int val){
        Node* obj = new Node();
        obj -> data = val;
        if(head == nullptr){
            head = obj;
        }
        else{
            obj -> next = head;
            head = obj;
        }
        size++;
    }

    void pop(){
        if(head == nullptr){
            cout << "list is empty!!" << endl;
            return;
        }
        Node* temp = head;
        head = temp -> next;
        delete temp;
        size--;
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

    int Sizeof(){
        cout << "Size of stack: " << size << endl;
}

    void display(){
        Node* temp = head;
        cout << "top -> ";
        while(temp != nullptr){
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "nullptr" << endl;
    }
};

int main(){
    
    Stack s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    s.push(12);
    s.Sizeof();
    s.peek();
    s.display();
    return 0;
}