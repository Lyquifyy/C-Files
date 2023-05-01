#include <iostream>
#include <string>
#include <vector>
int main() {

    using namespace std;
    
    cout << "This week's homework. \n";
    
    vector <string> inv;
    vector <string>::iterator changeiter;
    vector <string>::const_iterator iter;
    string userinput;
    int nopt;
    
            inv.push_back("Minecraft");
            inv.push_back("Simcity");
            inv.push_back("Candy Crush");

    cout << "Top video games in america - \n";
    
    for (iter = inv.begin(); iter != inv.end(); ++iter){
        
        cout << *iter << endl;
        
        }

        cout << "You can choose from three options... \n";
        cout << "1. Add name.\n";
        cout << "2. Change name.\n";
        cout << "3. Remove name.\n";
        cout << "4. List name.\n";
    
        cout << "What would you like to do?\n";

         cin >> nopt;

        if (nopt == 1){

            cout << "What would you like the name of the new item to be? \n";
            
            cin.ignore();

            getline(cin, userinput);
            
            inv.insert(inv.begin(), userinput);

            cout << "Top video games in america - \n";

            for(iter = inv.begin(); iter != inv.end(); ++iter){
        
        cout << *iter << endl;
        
        }
            
    }
        
        else if (nopt == 2){

            cout << "What do you want to change? \n";

            cout << "Top video games in america - \n";
            
            int i = 1;
            
            for(iter = inv.begin(); iter != inv.end(); ++iter){
      
        cout << i << " - " << *iter << endl;
        i++;
        
            }

            cout << "Please type in a number \n";

            cin >> nopt;

            nopt --;
            
            cout << "What would you like to change it too? \n";

            cin.ignore();

            getline(cin, userinput);

            inv[nopt] = userinput;

            cout << "Top video games in america - \n";

            for(iter = inv.begin(); iter != inv.end(); ++iter){
        
        cout << *iter << endl;   
            
        }

      }
        else if (nopt == 3){

            cout << "What do you want to remove?";

             cout << "Top video games in america - \n";
            
            int i = 1;
            
            for(iter = inv.begin(); iter != inv.end(); ++iter){
      
        cout << i << " - " << *iter << endl;
        
        i++;

        }

        cout << "Please type in a number \n";
           
        cin >> nopt;

        nopt --;

        inv.erase((inv.begin() + nopt));
        
        cout << "Top video games in america - \n";

            for(iter = inv.begin(); iter != inv.end(); ++iter){
        
        cout << *iter << endl;
        
        }
    }
        else if(nopt == 4) {

        cout << "Top video games in america - \n";

            for(iter = inv.begin(); iter != inv.end(); ++iter){
        
        cout << *iter << endl; 
                
        }

    }
    
}