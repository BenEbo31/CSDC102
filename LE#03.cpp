#include <iostream>
#include <vector>
using namespace std;

    void clearScreen(){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void displayMenu(const vector<string>& menuItems,
                    const vector<double>& menuPrices) {
                    
        cout << "=============================\n";
        cout << "            MENU\n";
        cout << "=============================\n";
        for(int i = 0; i < menuItems.size(); i++) {
            cout << i << " - " << menuItems[i] << " - \u20b1" << menuPrices[i] << endl;
    }
}

    int login(string& ADMIN_PASSCODE) {

        clearScreen();

        int role;
        string passcode;

        clearScreen();

        cout << "\n==== CHOOSE A USER TO LOGIN ====\n" << endl;
        cout << "[1] User   [2] Admin   [3] Shutdown\n" << endl;
        cout << "Enter choice: ";
        cin >> role;

    if(role == 2) {
        cout << "Enter Admin Passcode: ";
        cin >> passcode;
        if(passcode != ADMIN_PASSCODE) return 0; // invalid
    }
    return role;  // 1, 2, or 3
}
    void userMenu(const vector<string>& menuItems,
                    const vector<double>& menuPrices) {

            vector<string> receiptItems;
            vector<double> receiptPrices;
            vector<int> receiptQuantities;

            int choice;
    
    do{
        clearScreen();
        
        cout << "==== SELF-ORDERING MACHINE ====\n" << endl;
        cout << "1. View Menu\n";
        cout << "2. Add Item to Receipt\n";
        cout << "3. index Item from Receipt\n";
        cout << "4. View Receipt & Checkout\n";
        cout << "5. Exit\n";
        cout << "Enter a choice: ";
        cin >> choice;
        
        if(choice == 1){

            clearScreen();

            displayMenu(menuItems, menuPrices);

            cout << "\nPress any number to continue: ";
            string pause;
            cin >> pause;
        }
        else if(choice == 2){
            clearScreen();
            displayMenu(menuItems, menuPrices);

            int index, indexQuan;
            
            cout << "Enter item number to add: ";
            cin >> index;
            cout << "Enter how many item to add: ";
            cin >> indexQuan;

            if(indexQuan <= 0){
                cout << "Invalid Quantity.\n";
            }
            else if(index >= 0 && index < menuItems.size()){
                bool found = false;

                for(int i = 0; i < receiptItems.size(); i++){
                    if(receiptItems[i] == menuItems[index]){
                        receiptQuantities[i] += indexQuan;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    receiptItems.push_back(menuItems[index]);
                    receiptPrices.push_back(menuPrices[index]);
                    receiptQuantities.push_back(indexQuan);
                }
                cout << "\nItem(s) added successfully.\n";
            }
            else {
                cout << "Invalid Input\n";
            }
            cout << "\nPress any key to continue: ";
            string pause;
            cin >> pause;

        }
        else if(choice == 3){

            clearScreen();

            if(receiptItems.empty()){
                clearScreen();

                cout << "Receipt is Empty.\n";
            }
            
            else{
                char remAll;

                cout << "Do you want to index all items? (y/n): ";
                cin >> remAll;

                if(remAll == 'y' || remAll == 'Y'){
                    receiptItems.clear();
                    receiptPrices.clear();
                    cout << "Items indexd successfully.\n";
                }
                else {
                    clearScreen();
                    
                    cout << "==== Number of Items ====\n";
                    for(int i = 0; i < receiptItems.size(); i++){
                        cout << i << " - " << receiptItems[i] << " x" << receiptQuantities[i] << " - Php " << receiptPrices[i] << " each\n";
                    }
                    
                    double index;
                    
                    cout << "\nEnter item number to index by 1: ";
                    cin >> index;
                
                    if(index >= 0 && index < receiptItems.size()){
                        if(receiptQuantities[index] > 1){
                            receiptQuantities[index]--;
                            clearScreen();
                            
                            cout << "You now indexd 1 item.\n"; 
                            cout << "Remaining: " << receiptQuantities[index] << endl;
                        }
                        else {
                            receiptItems.erase(receiptItems.begin() + index);
                            receiptPrices.erase(receiptPrices.begin() + index);
                            receiptQuantities.erase(receiptQuantities.begin() + index);
            
                            cout << "Item indexd successfully.\n";
                        }
                    }
                    else {
                        cout << "Invalid Input\n";
                    }
                }
            }
            cout << "\nPress any number to continue: ";
            string pause;
            cin >> pause;
        }
        else if(choice == 4){

            clearScreen();

            double total = 0;

            if(receiptItems.empty()){
                cout << "No items ordered yet.\n";
            }
            else {
                
                for(int i = 0; i < receiptItems.size(); i++){

                    double subtotal = receiptPrices[i] * receiptQuantities[i];

                    cout << i << " - " << receiptItems[i] << " - x" << receiptQuantities[i] << " = Php " << subtotal << endl;
                    total += subtotal;
                }
                cout << "\nTotal items: " << receiptItems.size() << endl;
                cout << "Total: Php " << total << endl;

            }
            char checkOut;

                cout << "\nPress any key to continue: ";
                string pause;
                cin >> pause;

                cout << "\nDo you want to checkout? (y/n): ";
                cin >> checkOut;

            if((checkOut == 'Y' || checkOut == 'y') && total > 0){
                double Cash;
                
                clearScreen();

                cout << "How much are you paying?: ";
                cin >> Cash;

                double RemCash = Cash - total;

                clearScreen();

                if(Cash < total){
                    cout << "You don't have enough balance.\n";
                    cout << "You still need: PHP" << total - Cash << endl;
                }
                else{
                    clearScreen();

                    cout << "Thank you for your order!\n";
                    cout << "Remaing Balance: " << RemCash << "PHP\n";

                    receiptItems.clear();
                    receiptPrices.clear();
                    receiptQuantities.clear();

                }
                cout << "\nPress any key to continue: ";
                string pause;
                cin >> pause;

            }
            else{
                cout << "\nPress any key to continue: ";
                string pause;
                cin >> pause;
            }
        }
        else if(choice == 5){ 
            clearScreen();

            cout << "Thank you for ordering with us! Now exiting the program...\n";
        }
        else {
            cout << "Invalid Choice\n";
        }
           
    } while(choice != 5);
        }

    void adminMenu(vector<string>& menuItems,
                    vector<double>& menuPrices, string& ADMIN_PASSCODE){

        clearScreen();

        int choice;

        do {
            cout << "\n1. View Menu\n";
            cout << "2. Edit/Add New Menu Item\n";
            cout << "3. Change Password\n";
            cout << "4. Exit\n";
            cout << "\nEnter Choice: ";
            cin >> choice;
        
        if(choice == 1){
            clearScreen();
            displayMenu(menuItems, menuPrices);
        }
        if(choice == 2) {
            string newItem; double newPrice, choice1, choice2, editChoice;
            int index;

            clearScreen();

            cout << "1. Add an Item.\n";
            cout << "2. Edit an Item\n";
            cout << "Enter choice: ";
            cin >> choice1;

            if(choice1 == 1){
                cout << "You are now entering a new Item!\n" << endl;
                cout << "Enter item name: ";
                cin >> newItem;

                cout << "\nEnter price: ";
                cin >> newPrice;

                cout << "You added a new Item Successfully!\n";
            

                menuItems.push_back(newItem);
                menuPrices.push_back(newPrice);
            }
            else if(choice1 == 2){
                displayMenu(menuItems, menuPrices);

                cout << "\nChoose an Item to Edit: ";
                cin >> choice2;

                if(choice2 < 0 || choice2 >= menuItems.size()){
                    cout << "Invalid item number.\n";
                    return;
                }
                clearScreen();

                cout << "=== Choose an Item to Edit ===";
                cout << "\n1. Name  2. Price  3. Both\n" << endl;
                cout << "Which one would you like to edit?: ";
                cin >> editChoice;

                if(editChoice == 1){

                    clearScreen();

                    string newName;
                    cout << "Enter new name: ";
                    cin >> newName;

                    menuItems[choice2] = newName;
                    cout << "Item name has now been changed.\n";
                }
                else if(editChoice == 2){
                    clearScreen();

                    cout << "Enter new price: ";
                    cin >> newPrice;

                    menuPrices[choice2] = newPrice;
                    cout << "Price has now been changed.\n";
                }
                else if(editChoice == 3){
                    string newName;
                    cout << "Enter new name: ";
                    cin >> newName;

                    cout << "Enter new price: ";
                    cin >> newPrice;

                    menuItems[choice2] = newName;
                    menuPrices[choice2] = newPrice;

                    cout << "Item's Name & Price has fully changed.\n";
                }
                else{
                    cout << "Invalid Choice.\n";
                }
 
            }
        }
        if(choice == 3){
            string realPasscode, changedPass;

            cout << "Enter Admin Passcode: ";
            cin >> realPasscode;
            if(realPasscode == ADMIN_PASSCODE){

            cout << "Now enter a new Passcode: ";
            cin >> changedPass;

            ADMIN_PASSCODE = changedPass;

            cout << "Nice! You changed your password!";
            }
            else {
                clearScreen();

                cout << "BRUH! Invalid Passcode, Try again.";
            }
            
            clearScreen();
        }
        cout << "\nPress any key to continue: ";
        string pause;
        cin >> pause;

    } while(choice != 4);

    }

int main(){

    vector<string> menuItems = {"Burger", "Fries", "Coke", "Chicken"};
    vector<double> menuPrices = {99, 49, 39, 129};

    string adminPasscode = "6767";

    while(true){
        int role = login(adminPasscode);

        if(role == 1)
            userMenu(menuItems, menuPrices);

        else if(role == 2)
            adminMenu(menuItems, menuPrices, adminPasscode);
    
        else if(role == 3)
            break;
    
        else {
            cout << "Acces Denied.\n";
            break;
        }
    }

    clearScreen();
    cout << "Arigathanks, Sayonara! System is now shutting down.\n";

    return 0;
}
