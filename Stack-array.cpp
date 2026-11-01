#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class Stack{
    public:
        int size;
        Node nodes[10];

        Stack(){
            size = 0;
        }

        void push(int val){
            nodes[size].data = val;
            size++;
        }

        int pop(){
            int temp = nodes[size -1].data;
            nodes[size - 1].data = 0;
            size--;
            return temp;
        }

        int top(){
            if(size == 0){
                return -1;
            }
            return nodes[size - 1].data;
        }

        int sizeOf(){
            return size;
        }

        bool isEmpty(){
            if(size == 0){
                return true;
            }else{
                return false;
            }
        }

        void display(){
    if(isEmpty()){
        cout << "Stack is empty!!" << endl;
        return;
    }
    cout << "top -> ";
    for(int i = size - 1; i >= 0; i--){
        cout << nodes[i].data << " ";
    }
    cout << endl;
}
};

int main(){

    Stack s1;
    s1.push(12);
    s1.display();

}