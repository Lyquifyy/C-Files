#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {

    const int MAX = 10;
    string inventory[MAX];
    int invnumber = 0;
    int YorN = 0;
    
    int itemnum = 1;
    inventory[itemnum++] = "Item One";
    inventory[itemnum++] = "Item Two";
    inventory[itemnum++] = "Item Three";

    cout << "Hello adventurer! Youve been set on a path to find your lost mother that has been missing for almost a year. It is up too you to find her...\n";

    sleep(5);

    cout << "Please name your sword: \n";

    cin >> inventory[1];

    cout << "Please name your sheild: \n";

    cin >> inventory[2];

    cout << "Please name your food item that you brought with you: \n";

    cin >> inventory[3];

    cout << "Your current items: \n";

    for(int i = 0; i < itemnum; i++){

        cout << inventory[i] << endl;
        
    }

    sleep(3);

    cout << "On your journey, you get hungry so you decide to eat your " << inventory[2] << ". You now have one less item in you inventory.\n";

    sleep(3);

    inventory[2] = "";

     cout << "Your current items: \n";

    for(int i = 0; i < itemnum; i++){

        cout << inventory[i] << endl;
        
    }

    sleep(3);

    cout << "On your journey you find a mysterious box that could have something useful inside, will you open it? (1 = yes, 2 = no)\n";

    cin >> YorN;

    if(YorN == 1){

        cout << "You decide to open the box and gain a healing potion!\n";

         inventory[itemnum++] = "Healing Potion";

         cout << "Your current items: \n";

        for(int i = 0; i < itemnum; i++){

        cout << inventory[i] << endl;

        }
        
    }
    else{

      cout << "You decide to leave the box and keep walking along.";
        
    }

    sleep(3);

    cout << "You stumbled apon a troll on the bridge! You must give up your most valued item to pass.";

    sleep(3);

    cout << "please pick what item number you want to give up: \n";

    cin >> invnumber;

    for(int i = 4; i > invnumber; ){

        cout << "You picked " << inventory[invnumber] << ". The troll excepts your item and you continue on the search to find your lost mother. \n ";

        inventory[invnumber] = "";

         cout << "Your current items: \n";

         for(int i = 0; i < itemnum; i++){

        cout << inventory[i] << endl;
        
        }

        return 0;
        
    }
    
}