
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
                    cout << "You are now battling with ";
                    cout << Bloodhound.name;
                    typeText("    ");

            Legends * player;
            
            if(choice == 1) player = &octane;
            else if(choice == 2) player = &Wraith;
            else if(choice == 3) player = &Pathfinder;
            
            
            while(player -> health1 > 0 && Bloodhound.health2 > 0){
            
                cout << "\n==================================\n";
                cout << "=          IN A BATTLE!          =\n";
                cout << "==================================\n";
            
                cout << "\nYour Health: " << player -> health1;
                cout << "\nYour Shield: " << player -> gearHP1;
            
                cout << "\nEnemy Health: " << Bloodhound.health2;
                cout << "\nEnemy Shield: " << Bloodhound.gearHP2 << "\n";
            
                cout << "----------------------------------\n";
                cout << "-        Choose your move!       -\n";
                cout << "----------------------------------\n";
                cout << "- 1. Aim and Shoot               -\n";
                cout << "- 2. Use Shield Battery          -\n";
                cout << "- 3. Use Medkit or Bandage       -\n";
                cout << "- 4. Use lethal weapon           -\n";
                cout << "- 5. Use ability                 -\n";
                cout << "- 6. Run away                    -\n";
                cout << "----------------------------------\n";
            
                cout << "Enter a choice: ";
                cin >> choice;
            
                if(choice == 1){
                    int damage = 70;
            
                    if(Bloodhound.gearHP2 > 0){
                        Bloodhound.gearHP2 -= damage;
                        if(Bloodhound.gearHP2 < 0){
                            Bloodhound.health2 += Bloodhound.gearHP2;
                            Bloodhound.gearHP2 = 0;
                        }
                    }
                    else{
                        Bloodhound.health2 -= damage;
                    }
            
                    cout << "\nYou dealt " << damage << " damage!\n";
                }
                else if(choice == 2){
                    player -> gearHP1 += 60;
                    if(player -> gearHP1 > 100) player -> gearHP1 = 100;
                    cout << "\nShield restored by 60!\n";
                }
                else if(choice == 3){
                    player -> health1 += 100;
                    if(player -> health1 > 100) player -> health1 = 100;
                    cout << "\nYou healed 100 HP!\n";
                }
                else if(choice == 4){
                    int damage = 25;
            
                    if(Bloodhound.gearHP2 > 0){
                        Bloodhound.gearHP2 -= damage;
                        if(Bloodhound.gearHP2 < 0){
                            Bloodhound.health2 += Bloodhound.gearHP2;
                            Bloodhound.gearHP2 = 0;
                        }
                    }
                    else{
                        Bloodhound.health2 -= damage;
                    }
            
                    cout << "\nCritical hit! " << damage << " damage!\n";
                }
                else if(choice == 5){
                    int damage = 30;
            
                    if(Bloodhound.gearHP2 > 0){
                        Bloodhound.gearHP2 -= damage;
                        if(Bloodhound.gearHP2 < 0){
                            Bloodhound.health2 += Bloodhound.gearHP2;
                            Bloodhound.gearHP2 = 0;
                        }
                    }
                    else{
                        Bloodhound.health2 -= damage;
                    }
            
                    cout << "\nUsed ability (" << player -> abilities1 << ")! " << damage << " damage!\n";
                }
                else if(choice == 6){
                    cout << "\nYou ran away from the battle.\n";
                    break;
                }
                else{
                    cout << "\nInvalid move!\n";
                    continue;
                }
            
                // Enemy turn
                if(Bloodhound.health2 > 0){
                    int enemyDamage = 65;
            
                    if(player -> gearHP1 > 0){
                        player -> gearHP1 -= enemyDamage;
                        if(player -> gearHP1 < 0){
                            player -> health1 += player->gearHP1;
                            player -> gearHP1 = 0;
                        }
                    }
                    else{
                        player -> health1 -= enemyDamage;
                    }
            
                    cout << "Enemy dealt " << enemyDamage << " damage to you!\n";
                }
            
                // Prevent negatives
                if(player -> health1 < 0) player -> health1 = 0;
                if(Bloodhound.health2 < 0) Bloodhound.health2 = 0;
            
                cout << "\nPress any key to continue...";
                cin >> key;
            }
            
            // Result
            clearScreen();
            
            if(choice == 6){
                cout << "\n==================================\n";
                cout << "=             FLED               =\n";
                cout << "==================================\n";
                cout << "\nYou escaped from " << Bloodhound.name << ".\n";
            }
            else if(player -> health1 <= 0){
                cout << "\n==================================\n";
                cout << "=            DEFEAT              =\n";
                cout << "==================================\n";
                cout << "\nYou were defeated by " << Bloodhound.name << "...\n";
            }
            else if(Bloodhound.health2 <= 0){
                cout << "\n==================================\n";
                cout << "=            VICTORY             =\n";
                cout << "==================================\n";
                cout << "\nYou defeated " << Bloodhound.name << "!\n";
                cout << "Loot Acquired: " << Bloodhound.lootDrop << endl;
            }
            
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




