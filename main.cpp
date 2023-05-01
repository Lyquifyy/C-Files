#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

int main() {
    using namespace std;
    string pName;
    int pBegin=0;
    string sSent;
    
   //Introduction to FIRST ADVENTURE
    
  cout << "Welcome to the FIST ADVENTURE\n";
   cout << "Enter your username here: ";
   cin >> pName;
    
    cout << "Hello " << pName << ", you have been stranded in a forest far away from camp. This is a deadly forest with possibly dangerous creatures " << pName << ", so with that you need to survive throughout the night. Goodluck and lets hope you can make it till sunrise...\n";

    sleep(8);
    
    cout << "Are you ready to begin " << pName << "? Type in 1 if think you can survive the night.\n";
    cin >> pBegin;
    while (pBegin < 1 or pBegin > 1) {

        //Have the play type in 1 so they can begin the game
        
         cout << "Please type in 1 to begin.\n";
         cin >> pBegin;
        
    }if(pBegin == 1 ) {
        
     //Start of the First adventure  
        
        cout << "Starting the First Adventure...\n" ;

        sleep(3);
           
        srand(static_cast<unsigned int>(time(0)));//random number generator

        int gHealth = 10;

        int i = 0;

        int gEncounter = (rand() % 25) +1;

        int eNumber = 1;

        while(i < gEncounter){

             int attack = (rand() % 4) + 1; 

             int block = (rand() % 4) + 1;

            cout<< "Health = " << gHealth << "\n";
            
            cout << "Encounter #" << eNumber << " is about to begin...\n";

            sleep(5);

            if(attack >= block){

            cout<< "You were not able to block the attack...\n";

                sleep(2);
            
            cout<< "Here comes the next encounter!\n";

                sleep(2);
            
            gHealth --;
        }
            else if(attack < block){

            cout<< "You were able to block the encounter!\n";

                sleep(2);

            cout<< "Here comes the next encounter!\n";

            if(gHealth < 1){
                
                cout<< "You Died.\n";
                break;
                
            }
            
        }

            gEncounter--;
            eNumber++;
            
        }
        if(gEncounter == 0){
                
            if(gHealth > 0){

                cout<< "You survived the night!\n";
                
            }
            
        }
         
    }

}