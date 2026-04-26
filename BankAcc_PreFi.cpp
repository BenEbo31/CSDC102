#include <iostream>
using namespace std;

    void clearScreen(){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    class BankAccount{
        private:
            string accountHolder;
            double balance;
        
        public:
            BankAccount(string name, double initial){
                accountHolder = name;
                balance = initial;
            }
    void deposit(double amount){
        balance += amount;
    }

    void withdraw(double amount){
        if(amount > balance){
            cout << "Insufficient Funds.\n";
        }
        else {
            balance -= amount;
        }
    }

    void displayBalance(){
        cout << "\n------------------------" << endl;
        cout << "Balance: " << balance << endl;
        cout << "------------------------\n" << endl;
    }
};

int main(){
    string name;
    double initial;

        cout << "----------------------------" << endl;
        cout << "Enter your Name: ";
        cin >> name;
        cout << "Initial Deposit: ";
        cin >> initial;
        cout << "\n----------------------------" << endl;

    BankAccount acc(name, initial);

    int choice, choice2;
        do{
            clearScreen();
            cout << "\n[1] Deposit\t[2] Withdraw\t[3] Check Balance\t [4] Exit\nChoice: ";
            cin >> choice;

            double amount;
                if(choice == 1){
                    cout << "\n------------------------" << endl;
                    cout << "Enter amount: ";
                    cin >> amount;
                    acc.deposit(amount);
                }
                else if(choice == 2){
                    cout << "\n------------------------" << endl;
                    cout << "Enter amount: ";
                    cin >> amount;
                    acc.withdraw(amount);
                }
                else if(choice == 3){
                    acc.displayBalance();
                }
            cout << "\nEnter any key to continue: ";
            cin >> choice2;
        }
        while(choice !=4);

    return 0;
}
