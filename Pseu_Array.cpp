#include <iostream>

int main(){

    int arr[10] = {9, 7, 17, 13, 27, 31, 33, 19, 22, 77};
    int n = 10;

    int largest = arr[0];                 // almost same code from the first
    int smallest = arr[0];
    int sum = 0;

        for (int i = 0; i < n; i++){
            if (arr[i] > largest){
                largest = arr[i];
            }

            if (arr[i] < smallest){
                smallest = arr[i];
            }

        sum = sum + arr[i];

        }

    double average = static_cast<double>(sum) / n;

    std::cout << "Largest: " << largest << std::endl;
    std::cout << "Smallest: " << smallest << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << “\n” << std::endl;

    for (int i = 0; i < n; i++){
        if (arr[i] > average){
            std::cout << arr[i] << " (Above Average)" << std::endl;

        } else {
            std::cout << arr[i] << " (Below or Equal Average)" << std::endl;
        }
    }

    return 0;
}
