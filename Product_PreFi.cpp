#include <iostream>
using namespace std;

    void clearScreen(){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    struct Product {
        string name;
        int quantity;
        float price;
    };

int main() {
    Product p[5];
    int n;
    float total, maxPrice = p[0].price;
    string expensive = p[0].name;

        cout << "======= Product Inventory =======\n" << endl;
        cout << "How many products (max 5): ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "\nItem No. " << i + 1 << endl;
            cout << "--------------------" << endl;
            cout << "Name: ";
            cin >> p[i].name;

            cout << "Quantity: ";
            cin >> p[i].quantity;

            cout << "Price: ";
            cin >> p[i].price;

        }
            clearScreen();
        cout << "-----------------------------------------------" << endl;
        cout << "Products:" << endl;
        cout << "-----------------------------------------------" << endl;

        cout << "\nNo.\tName:\tQuan.:\tPrice:\n";
        cout << "---\t-----\t------\t-----" << endl;
            for (int i = 0; i < n; i++) {
                total = p[i].quantity * p[i].price;

                cout << i + 1 << "." << "\t" << p[i].name << "\t" << p[i].quantity << "\t" << p[i].price << "\t" << " || Total: " << total << endl;

                if (p[i].price > maxPrice) {
                    maxPrice = p[i].price;
                    expensive = p[i].name;
                }
            }

        cout << "\n-----------------------------------------------" << endl;
        cout << "Most expensive:" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "\nName:\tPrice:" << endl;
        cout << "-----\t-----" << endl;
        cout << expensive << "\t" << maxPrice << "\n" << endl;
        cout << "-----------------------------------------------\n" << endl;

    return 0;
}
