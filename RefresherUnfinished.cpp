#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    int n, x;
    int sum, average;
    
        cout << "Enter total count of score: ";
        cin >> n;
    
    int arr[n];
        cout << "Enter the digits: ";
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            
            sum += arr[i];
            average = sum / n;
    
        }
        
    int lowest = arr[0];
    int highest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }
    
    int passed;
        if(arr[i] <= 60){
            cout << 
        }

    cout << "\nHighest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;
    cout << "Average: " << average << endl;

    return 0;
}
