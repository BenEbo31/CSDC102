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
    
    class CSVManager {
        public:
            bool parseline(string line, string fields[], int fieldCount) {
                int idx = 0;
                string token = "";
                for (int i = 0; i <= (int)line.length(); i++){
                    if (idx >= fieldCount){
                        return false;
                    
                    fields[idx++] == token;
                    token = "";
                }
                else {
                    token += line[i];
                }
            
            return idx == fieldCount;
        };
    
    void writeDefaultSongs(){
        ofstream file(csv_file);
        if(!file.is_open()){
            cout << "Error";
            return;
        }
            file << header << "\n";
            file << "Africa,Toto,Rock,1982,4:55" << endl;
            file << "Daisies,Justin Bieber,Pop,2025,2:57" << endl;
            file << "Africa,Toto,Rock,1982,4:55" << endl;
            file << "Africa,Toto,Rock,1982,4:55" << endl;
            file << "Africa,Toto,Rock,1982,4:55" << endl;
            file << "Africa,Toto,Rock,1982,4:55" << endl;
            file << "Africa,Toto,Rock,1982,4:55" << endl;
            file << "Africa,Toto,Rock,1982,4:55" << endl;
            file.close();
        }
    };
    
    void createDefaultCSV(){
        ifstream checkFile(csv_file);
        if(checkFile.is_open()){
            string header;
            getline(checkFile, header);
            checkFile.close();
            if(header == header){
                return;
            }
            cout << "[!] Old CSV format detected. Recreating playlist.csv...\n";
        }
        writeDefaultSongs();
        cout << "Default playlist CSV created.";
    }
    
    bool isDuplicate(string title, string artist){
        ifstream file(csv_file);
            if(!file.is_open()){
                return false;
            }
            string line;
            getline(file, line);
        
        while(getline(file, line)){
            if(line.empty()){
                cotinue;
            }
            string fields[5];
            
            if(!pareLine(line, fields, 5)){
                continue;
            }
            
            if(toLower(fields[0]) == toLower(title) &&
                toLower(fields[1]) == toLower(artist)) {
                    file.close();
                    return true;
            }
        }
        file.close();
        return false;
    }
    
    void saveSong(Song s){
        ofstream file(csv_file, ios::app);
        if(!file.is_open()){
            cout << "Error\n";
        }
        
        file << s.title << "," << s.artist << "," << s.genre << "," 
             << s.year << "," << s.duration << "\n";
        file.close();
    }
    
    int loadSongs(Song songs[], int maxSongs){
        ifstream file(csv_file);
        if(!file.is_open()){
            cout << "Error\n";
        }
        string line;
        getline(file, line);
        int count = 0;
        
        while(getline(file, line) && count < maxSongs){
            if(line.empty()){
                continue;
            }
            string fields[5];
            if(!parseLine(line, fields, 5)){
                continue;
            }
            songs[count++] = Song(fields[0], fields[1], fields[2],
                                  stoi(fields[3]), fields[4]);
        }
        file.close();
            return count;
    }
};
    
int main(){
    
    return 0;
}
