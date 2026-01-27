#include <iostream>

int main(){

    int arr[10] = {7, 17, 9, 27, 17, 37, 13, 31, 10, 20};
    int n = 10;

        std::cout << "Array: ";
    
        for (int i = 0; i < n; i++){      // used for loop to print each element in original order
            std::cout << arr[i] << " ";       // this simply prints out all the integers inside an array

        }
        std::cout << “\n” << std::endl;

    int sum = 0;
        for (int i = 0; i < n; i++){       // this adds all the array to sum
            sum += arr[i];
        }  
        std::cout << "Sum: " << sum << std::endl;

    double average = static_cast<double>(sum) / n;        //in order for the final average to include the decimal part, I used "static_cast<double>(sum)". Instead of directly putting it as "average = sum / n" 
    std::cout << "Average: " << average << std::endl;

    int smallest = arr[0];     // to find which is the smallest and largest inside the array list
    int largest = arr[0];

        for (int i = 1; i < n; i++){
            if (arr[i] < smallest)       // this updates when there is a smaller value found
                smallest = arr[i];
            
            if (arr[i] > largest)        // same goes with this, it updates when there is a larger value found
                largest = arr[i];
            
        }

    int secondSmallest = largest;        // this starts as the largest value
    int secondLargest = smallest;        // opposite, starts as smallest value

        for (int i = 0; i < n; i++){
            if (arr[i] > smallest && arr[i] < secondSmallest)     // will find the smallest value which is greater than “smallest”
                secondSmallest = arr[i];
            
            if (arr[i] < largest && arr[i] > secondLargest)   // same thing but lesser than “largest”
                secondLargest = arr[i];
        }

        std::cout << "Second largest: " << secondLargest << std::endl;
        std::cout << "Second Smallest: " << secondSmallest << std::endl;

    int k = 2;
    k = k % n;

    int reversed[10];           // i’m not sure if this is correct hehe

        for (int i = 0; i < n; i++){
            reversed[i] = arr[n - 1 - i];

        }

        std::cout << "Reversed array: ";

            for (int i = 0; i < n; i++){
                std::cout << reversed[i] << " ";

            }
            
            std::cout << std::endl;
    
    return 0;

}
