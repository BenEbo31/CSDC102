#include <iostream>
#include <iomanip>

using namespace std;

    void clearScreen(){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    struct Student{
        string name;
        float midterm, final_exam, average;
        
    };
    
int main(){
    
    Student stud[5];
    
        cout << "==== Student Grade Report ====" << endl;

        for(int i = 0; i < 5; i++){
            cout << "\nStudent No. " << i + 1 << endl;
            cout << "--------------------" << endl;
            cout << "Name: ";
            cin >> stud[i].name;
            
            cout << "Midterm Score: ";
            cin >> stud[i].midterm;
            
            cout << "Finals Score: ";
            cin >> stud[i].final_exam;
            cout << "\n--------------------" << endl;
            
            stud[i].average = (stud[i].midterm + stud[i].final_exam) / 2;

        }
        
            clearScreen();
        cout << "----------------------------------------------------" << endl;
        cout << "\nName\t\tMidterm\tFinal\tAverage\tRemark\n";
        cout << "-------\t\t------- -------\t------- -------" << endl;
        
        for(int i = 0; i < 5; i++){

            cout << stud[i].name << "\t" << stud[i].midterm << "\t" << stud[i].final_exam << "\t" << stud[i].average << "\t" << (stud[i].average >= 75 ? "Passed" : "Failed") << endl;
        }
        cout << "\n----------------------------------------------------" << endl;
        
    return 0;
}
