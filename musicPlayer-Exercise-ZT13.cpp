#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

//linux-only libraries
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

//_Win32 libraries
// #include <windows.h>
// #include <conio.h>

using namespace std;

//constants
    const string csv_file = "playlist.csv";
    const string header = "Title,Artist,Genre,Year,Duration";

//system-only functions
    void clearScreen(){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    
// A function that detects keypresses without waiting to reinterpret_cast
    static struct termios g_oldt;
    
    void setRawMode(bool enable){
        if(enable){
            struct termios newt;
            tcgetattr(STDIN_FILENO, &g_oldt);
            newt = g_oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        }
        else{
            tcsetattr(STDIN_FILENO, TCSANOW, &g_oldt);
        }
    }
    
    bool keyPressed(){
        struct timeval tv = {0,0};
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
    }
    
// Helper function for lowercasing strings
    string tolower(string str){
        for(int i = 0; i < (int)str.length(); i++){
            str[i] = tolower(str[i]);
        }
        return str; 
    }
  
  
    class Song{
        public:
            string title;
            string artist;
            string genre;
            int year;
            string duration; // "MM:SS"
            
            Song(){
                year = 0;
            }
            
            Song(string t, string a, string g, int y, string d){
                title = t;
                artist = a;
                genre = g;
                year = y;
                duration = d;
            }
            
            //  Convert duration to total seconds
            int convertIntoSeconds() const{
                int colonPos = duration.find(":");
                if(colonPos == (int)string::npos){
                    return 0;
                }
                return stoi(duration.substr(0, colonPos)) * 60 + stoi(duration.substr(colonPos)) * 60 
                    + stoi(duration.substr(colonPos + 1));
            }
    };

    class Node{
        public:
            Song song;
            Node* next;
            Node* prev;
            
            Node(Song s){
                song = s;
                next = nullptr;
                prev = nullptr;
                
            }
    };
    
    
    
int main(){
    
    return 0;
}
