// Stack implement through arrays
#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int nodes[10];     

        Stack(){
            size = 0;
        }

        bool isEmpty(){
            return size == 0;
        }

        bool isFull(){
            return size == 10;
        }

        void push(int val){
            if(isFull()){
                cout << "Stack overflow!!" << endl;
                return;
            }
            nodes[size] = val; 
            size++;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack is empty!!" << endl;
                return -1;
            }
            int temp = nodes[size - 1];  
            size--;                      
            return temp;
        }

        int top(){
            if(isEmpty()){
                return -1;
            }
            return nodes[size - 1];
        }

        int sizeOf(){
            return size;
        }

    void display(){
    if(isEmpty()){
        cout << "Stack is empty!!" << endl;
        return;
    }
    cout << "top -> ";
    for(int i = size - 1; i >= 0; i--){
        cout << nodes[i] << " ";
    }
    cout << endl;
}
};

int main(){
    Stack s;
    s.push(5);
    s.push(8);
    s.push(2);
    s.push(9);
    s.push(1);
    s.push(7);
    s.push(6);
    s.push(4);
    s.push(3);
    s.push(10);
    s.display();
    cout << "Top: " << s.top() << endl;        
    cout << "Popped: " << s.pop() << endl;     
    cout << "Top: " << s.top() << endl;        
    cout << "Size: " << s.sizeOf() << endl;  
    return 0;
}