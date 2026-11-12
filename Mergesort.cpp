#include<iostream>
using namespace std;

int sum(int num){
    if(num <= 0)
    {return 0;}

    return num + sum(num-1);
}

void printNum(int num){
    if(num <= 0)
    {return;}

    printNum(num-1);
    cout << num << endl;
}

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;          
    int n2 = right - mid;             

    int* L = new int[n1];             
    int* R = new int[n2];

    for(int a = 0; a < n1; a++){
        L[a] = arr[left + a];
    }
    for(int b = 0; b < n2; b++){
        R[b] = arr[mid + 1 + b];
    }

    int i = 0;                        
    int j = 0;                        
    int k = left;                     

    while(i < n1 && j < n2){          
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){                    
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){                    
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;                       
    delete[] R;
}

void mergeSort(int arr[], int left, int right){
    if(left >= right){               
        return;
    }
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);        
    mergeSort(arr, mid + 1, right);   
    merge(arr, left, mid, right);     
}

int main(){

    int arr[6] = {90,1,65,23,89,3};
    mergeSort(arr, 0, 7);

    for(int x = 0; x < 8; x++){
        cout << arr[x] << " ";        
    }
    cout << endl;
    return 0;
}