#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){     
                minIndex = j;
            }
        }
        if(minIndex != i){                   
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int num[10] = {9,3,7,4,1,8,2,6,11,5};
    SelectionSort(num, 10);
    display(num, 10);       
    return 0;
}