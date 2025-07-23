#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    srand(time(0)); 
    string playerName;
    int choice, health = 100, treasure = 0;

    cout << "Welcome to the Mystic Cave Adventure!\n";
    cout << "Enter your name, brave explorer: ";
    getline(cin, playerName);

    cout << "\nHello, " << playerName << "! You enter a dark cave with 100 health.\n";
    cout << "Find treasure, but beware of traps! Choose your path wisely.\n";

    for (int i = 1; i <= 3; i++) { 
        cout << "\n--- Room " << i << " ---\n";
        cout << "You see three paths: \n1. Left (a glowing tunnel)\n2. Right (a dusty path)\n3. Straight (a creaky bridge)\n";
        cout << "Choose a path (1-3): ";
        cin >> choice;

        int event = rand() % 3; 
        switch (choice) {
            case 1:
                cout << "You venture into the glowing tunnel...\n";
                break;
            case 2:
                cout << "You tread carefully down the dusty path...\n";
                break;
            case 3:
                cout << "You cross the creaky bridge, heart pounding...\n";
                break;
            default:
                cout << "Invalid choice! You stumble and lose 10 health.\n";
                health -= 10;
                continue;
        }

        if (event == 0) {
            int found = (rand() % 50) + 10; 
            treasure += found;
            cout << "You found " << found << " gold coins! Total treasure: " << treasure << "\n";
        } else if (event == 1) {
            int damage = (rand() % 30) + 10; 
            health -= damage;
            cout << "A trap springs! You take " << damage << " damage. Health: " << health << "\n";
        } else {
            cout << "Nothing happens. The cave is eerily quiet.\n";
        }

        if (health <= 0) {
            cout << "\nOh no, " << playerName << "! You succumbed to the cave's dangers.\n";
            cout << "Final treasure: " << treasure << " gold coins.\n";
            return 0;
        }
    }

    cout << "\nCongratulations, " << playerName << "! You escaped the cave!\n";
    cout << "Final Health: " << health << "\n";
    cout << "Treasure Collected: " << treasure << " gold coins.\n";
    if (treasure >= 100) {
        cout << "You're a legendary treasure hunter!\n";
    } else {
        cout << "Not bad, but the cave holds more secrets!\n";
    }

    return 0;
}
