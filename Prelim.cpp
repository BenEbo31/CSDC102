#include <iostream>
#include <queue>
using namespace std;


    // PART I: Initialize Function
    void initQueue(int queue[5][3], int &orderCount){
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            queue[i][j] = 0;
        }
    }   
        orderCount = 0;
    }
    
    // PART II: Insert Function
    int insertOrder(int queue[5][3], int &orderCount, int orderNum) {
    for(int col = 0; col < 3; col++){
        if(col % 2 == 0){
            for(int row = 0; row < 5; row++){
                if(queue[row][col] == 0){
                queue[row][col] = orderNum;
                orderCount++;
                return 1;
            } 
        }
    } else {
        for(int row = 4; row >= 0; row--){
            if (queue[row][col] == 0){
                queue[row][col] = orderNum;
                orderCount++;
                return 1;
                }
            }
        }
    }
        return 0;

}
    
    // PART III: Display Function
    void displayQueue(int queue[5][3], int orderCount) {
        
    cout << "STARBUCKS ORDER QUEUE: " << endl;
    cout << "       ";
    
    for(int j = 0; j < 3; j++){
        cout << "Col " << j << "  ";
    } 
        cout << endl;
        
    for(int i = 0; i < 5; i++){
        cout << "Row " << i << ": ";
        for(int j = 0; j < 3; j++){
            cout << "[";
            
        if(queue[i][j] < 10){
            cout << "  " << queue[i][j];
            
        } else if(queue[i][j] < 100){
            cout << " " << queue[i][j];
        } else {
            cout << queue[i][j];
        } cout << "]  ";
    }   cout << endl;
    
    }
        cout << "Total Orders: " << orderCount << endl;

    }
    
    // PART IV: Search Function
    int searchOrder(int queue[5][3], int orderNum) {
    
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j >= 2; j++){
            if(queue[i][j] == orderNum){
                return 1;
            }
        }
    
    }
        return 0;

}

    // PART V: Main Function
    int main() {
        int queue[5][3];
        int orderCount = 0;

        initQueue(queue, orderCount);
        int orders[8] = {101, 102, 103, 104, 105, 106, 107, 108};
        for(int i = 0; i < 8; i++){
            insertOrder(queue, orderCount, orders[i]);
        }

        displayQueue(queue, orderCount);
        cout << endl;

        int result1 = searchOrder(queue, 105);
        if(result1 == 1){
            cout << "Order 105 found in queue!";
        } else {
            cout << "Order 105 not found.";
        }
        cout << endl;

        int result2 = searchOrder(queue, 999);
        if(result2 == 1){
            cout << "Order 999 found in queue!";
        } else {
            cout << "Order 999 not found.";
        }

    
    return 0;
}
