#include <iostream>
using namespace std;

void bubbleSort(int* arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                    *(arr + j) = *(arr + j + 1);
                    *(arr + j + 1) = temp;
            }
        }
    }
}

int main(){
    int arr[5];

    cout << "===== Pointer-Based Sorting =====" << endl;
    cout << "\n---------------------------------" << endl;
    cout << "Enter 5 Numbers: ";
        for(int i = 0; i < 5; i++){
            cin >> arr[i];
        }
    
    cout << "--------------------------------" << endl;
    cout  << "Before: ";
        for(int i = 0; i < 5; i++) cout << arr[i] << " ";

        bubbleSort(arr, 5);

    cout << "\nAfter: ";
        for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << "\n--------------------------------" << endl;    

    return 0;
}
