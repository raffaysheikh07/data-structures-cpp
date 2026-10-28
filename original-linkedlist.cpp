// The original linked list code
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

void deleteHead(){

    if(head == nullptr){
        cout << "List is empty!!" << endl;
        return;
    }

    Node* temp = head;
    head = temp -> next;
    delete temp;
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

int main(){
    int val, choice;
    char ch;

    do{
        cout << "Linked List Menu" << endl;
        cout << "1. Enter integers to store in the list" << endl;
        cout << "2. Delete a stored integer from the list" << endl;
        cout << "3. Search a stored integer" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                do{
                    cout << "Enter integer to store: ";
                    cin >> val;
                    insertAt(val);

                    cout << "Do you want to store more integers (y/n): ";
                    cin >> ch;
                }while(ch == 'Y' || ch == 'y');
                display();
                break;

            case 2:
                do{
                    cout << "Enter integer to delete: ";
                    cin >> val;
                    deleteNode(val);

                    cout << "Do you want to delete more values (y/n): ";
                    cin >> ch;
                }while(ch == 'Y' || ch == 'y');
                display();
                break;

            case 3:
                do{
                    cout << "Enter number to search: ";
                    cin >> val;
                    if(!search(val)){
                        cout << "Value not found in the list" << endl;
                    }

                    cout << "Do you want to search more numbers (y/n): ";
                    cin >> ch;
                }while(ch == 'Y' || ch == 'y');
                break;

            case 4:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid Choice!!" << endl;
        }
    }while(choice != 4);
    
    return 0;
}