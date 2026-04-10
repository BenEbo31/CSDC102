
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

    void clearScreen(){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    void typeText(string text){
        for(char c : text){
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    struct Legends{
        string name;
        string class1;
        string abilities1;
        int health1;
        int gearHP1;
        bool isAlive;
        string currentWeapon;
    };

    struct Enemy{
        string name;
        string class2;
        string abilities2;
        int health2;
        int gearHP2;
        string currentWeapon;
        bool isDefeated;
        string lootDrop;
    };
    
    struct Location{
        string area;
        string zoneArea;
        bool isZoneSafe;
        int numberOfEnemies;
        bool missilesNearby;
    };
    
    
int main(){
    int key, choice;
    char choice2;
    
    Legends octane;
        octane.name             = "Octane";
        octane.class1           = "Adrenaline Junkie";
        octane.abilities1       = "Stim";
        octane.health1          = 100;
        octane.gearHP1           = 100;
        octane.currentWeapon    = "R-301 Carbine";
    
    Legends Wraith;
        Wraith.name             = "Wraith";
        Wraith.class1           = "Interdimensional Skirmisher";
        Wraith.abilities1       = "Dimensional Rift";
        Wraith.health1          = 100;
        Wraith.gearHP1           = 100;
        Wraith.currentWeapon    = "R-99";
        
    Legends Pathfinder;
        Pathfinder.name             = "Pathfinder";
        Pathfinder.class1           = "Forward Scout";
        Pathfinder.abilities1       = "Grappling Hook";
        Pathfinder.health1          = 100;
        Pathfinder.gearHP1           = 100;
        Pathfinder.currentWeapon    = "Havoc";
    
    
    Enemy Revenant;
        Revenant.name             = "Revenant";
        Revenant.class2           = "Synthetic Nightmare";
        Revenant.abilities2       = "Forged Shadows";
        Revenant.health2          = 100;
        Revenant.gearHP2           = 100;
        Revenant.currentWeapon    = "Havoc";
        Revenant.lootDrop         = "Havoc   Backpack   Phoenix Kit   Med Kit";
    
    Enemy Crypto;
        Crypto.name             = "Crypto";
        Crypto.class2           = "Surveillance Expert";
        Crypto.abilities2       = "Surveillance Drone";
        Crypto.health2          = 100;
        Crypto.gearHP2           = 100;
        Crypto.currentWeapon    = "Sentinel";
        Crypto.lootDrop         = "Sentinel   Arc Star   Sheild Battery   Sniper Ammo";
        
    Enemy Bloodhound;
        Bloodhound.name            = "Bloodhound";
        Bloodhound.class2          = "Technological Tracker";
        Bloodhound.abilities2      = "Eye of the Allfather";
        Bloodhound.health2         = 100;
        Bloodhound.gearHP2          = 100;
        Bloodhound.currentWeapon   = "Devotion";
        Bloodhound.lootDrop        = "Devotion   1x holo   Frag Grenade   Sheild Cell";
        
        
    Location Map;
        Map.area                = "The Cage";
        Map.zoneArea            = "Closing in";
        Map.numberOfEnemies     = 56;
        
        
                string area;
        string zoneArea;
        bool isZoneSafe;
        int numberOfEnemies;
        bool missilesNearby;
        
    
            cout << "======= MAIN TEAM =======\n" << endl;
            
            cout << "\n-------------------------" << endl;
            cout << "        Player 1" << endl;
            cout << "-------------------------\n" << endl;
            cout << "Character: " << octane.name << endl;
            cout << "Class: " << octane.class1 << endl;
            cout << "Abilities: " << octane.abilities1 << endl;
            cout << "Health: " << octane.health1 << endl;
            cout << "Gear HP: " << octane.gearHP1 << endl;
            cout << "Current Weapon: " << octane.currentWeapon << endl;
            
            cout << "\n-------------------------" << endl;
            cout << "        Player 2" << endl;
            cout << "-------------------------\n" << endl;
            cout << "Character: " << Wraith.name << endl;
            cout << "Class: " << Wraith.class1 << endl;
            cout << "Abilities: " << Wraith.abilities1 << endl;
            cout << "Health: " << Wraith.health1 << endl;
            cout << "Gear HP: " << Wraith.gearHP1 << endl;
            cout << "Current Weapon: " << Wraith.currentWeapon << endl;
            
            cout << "\n-------------------------" << endl;
            cout << "        Player 3" << endl;
            cout << "-------------------------\n" << endl;
            cout << "Character: " << Pathfinder.name << endl;
            cout << "Class: " << Pathfinder.class1 << endl;
            cout << "Abilities: " << Pathfinder.abilities1 << endl;
            cout << "Health: " << Pathfinder.health1 << endl;
            cout << "Gear HP: " << Pathfinder.gearHP1 << endl;
            cout << "Current Weapon: " << Pathfinder.currentWeapon << endl;
            
            cout << "\nEnter any key to continue: ";
            cin >> key;
            
                clearScreen();
            cout << "\n========== PICKING ==========\n";
            cout << "Select a Legend!\n" << endl;
            cout << "\n-------------------------------" << endl;
            cout << "1.Octane 2.Wraith 3.Pathfinder\n";
            cout << "---------------------------------\n" << endl;
            
            cout << "Enter your selected legend: ";
            cin >> choice;
                
                clearScreen();
                if(choice == 1){
                    cout << "\nYou have selected the legend " << octane.name << ".\n";
                }
                else if(choice == 2){
                    cout << "\nYou have selected the legend " << Wraith.name << ".\n";
                }
                else if(choice == 3){
                    cout << "\nYou have selected the legend " << Pathfinder.name << ".\n";
                }
                else{
                    cout << "Invalid Choice." << endl;
                }
            
            cout << "\nEnter any key to continue: ";
            cin >> key;
            
                clearScreen();
            typeText("Entering Map...\n");
            typeText("\nYou landed on ");
            cout << Map.area << "\n";
            typeText("    ");
            
                clearScreen();
                if(choice == 1){
                    typeText("\nYou have landed with "); 
                    cout << Wraith.name;
                    typeText(" and ");
                    cout << Pathfinder.name << ".\n";
                }
                else if(choice == 2){
                    typeText("\nYou have landed with "); 
                    cout << octane.name;
                    typeText(" and ");
                    cout << Pathfinder.name << ".\n";
                }
                else if(choice == 3){
                    typeText("\nYou have landed with "); 
                    cout << Wraith.name;
                    typeText(" and ");
                    cout << octane.name << ".\n";
                }
                else{
                }
            
            cout << "\nEnter any key to Enter the Battle!: ";
            cin >> key;
            
                clearScreen();
            cout << "You crossed path with an enemy who is " << Bloodhound.name << ".\n" << endl;
            typeText("Are you initiating for a battle? (y/n)\n");
            
            cout << "\nEnter your choice: ";
            cin >> choice2;

                if(choice2 == 'y' || choice2 == 'Y'){
                    clearScreen();
                    typeText("You are now battling with ");
                    cout << Bloodhound.name;
                    typeText("    ");
                    
                clearScreen();
            cout << "\n==================================\n";
            cout << "=          IN A BATTLE!          =\n";
            cout << "==================================\n";
            
            cout << "----------------------------------\n";
            cout << "\n- Choose your move!              -" << endl;
            cout << "----------------------------------\n";
            cout << "-                                -\n";
            cout << "- 1. Aim and Shoot               -\n";
            cout << "- 2. Use Sheild Battery          -\n";
            cout << "- 3. Use Medkit or Bandage       -\n";
            cout << "- 4. Use lethal weapon           -\n";
            cout << "- 5. Use ability                 -\n";
            cout << "- 6. Run away                    -\n";
            cout << "-                                -\n";
            cout << "----------------------------------\n";
            
            cout << "Enter a choice: ";
            cout << choice;
            
            
                }
                else if(choice2 == 'n' || choice2 == 'N'){
                    clearScreen();
                    typeText("You avoided ");
                    cout << Bloodhound.name;
                    typeText(" to a battle.");
                }
            
                cout << "\nEnter any key to continue: ";
                cin >> key;
                
    return 0;
}



