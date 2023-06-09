// Final for Introduction to C++
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;

enum en_DIRS { NORTH, EAST, SOUTH, WEST };
// New room names : Entrance, Hallway, Dungeon, Empty Cell, Kings' Dinal Hall, Staircase, Lobby, Kings Bedroom, Bathroom, Garden maze, Fountain, The Garden, Pathway, Fishing dock, The Dark Cavern, The Dying Tunnels, The Decaying Taverns, The Black Pit, The Ghost Chambers, The Golden Cell
enum en_ROOMS {ENTRANCE, HALLWAY, DUNGEON, EMPTY_CELL, KINGS_DINING_HALL, STAIRCASE, LOBBY, KINGS_BEDROOM, BATHROOM, BRIDGE, FOUNTAIN, THE_GARDEN, PATHWAY, FISHING_DOCK, THE_DARK_CAVERN, THE_DYING_TUNNELS, THE_DECAYING_TAVERNS, THE_BLACK_PIT, THE_GHOST_CHAMBERS, THE_GOLDEN_CELL};
// Old room names : SPORTSHOP, CASINO, CARPARK, LOBBY, RESTAURANT, CORRIDOR, STOREROOM, POOL, GARDEN, POND, PUMPROOM 
enum en_VERBS { GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK };
// New Noun names : KEY, SWORD, SHEILD, APPLE, SOAP, STUFFED_BUNNY, MYSTERIOUS_ROCK, KINGS_CROWN, BROKEN_GLASSES, THEGOLDENCELL, CELL_DOOR, METAL_PIPE, STEAK, FLOWER, LUCKY_COIN 
enum en_NOUNS {KEY, SWORD, SHEILD, APPLE, SOAP, STUFFED_BUNNY, MYSTERIOUS_ROCK, KINGS_CROWN, BROKEN_GLASSES, PAINTING, CELL_DOOR, METAL_PIPE, STEAK, FLOWER, LUCKY_COIN};
// Old Room Names :  STORE_DOOR, MAGNET, METER, ROULETTE, MONEY, FISHROD
const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 20;
const int VERBS = 8;
const int NOUNS = 15;

bool debug = false;

// Classes with public getters/setters and private strings and ints.
class words {
public:
    void setWord(string w) { word = w; }
    string getWord() { return word; }
    void setCode(int c) { code = c; }
    int getCode() { return code; }

private:
    string word;
    int code;
};

class room {
public:
    void setDesc(string d) { description = d; }
    string getDescription() { return description; }
    int exits_to_room[DIRS];

private:
    string description;
};

class noun {
public:
    void setWord(string w) { word = w; }
    string getWord() { return word; }
    void setDesc(string d) { description = d; }
    string getDescription() { return description; }
    void setCode(int c) { code = c; }
    int getCode() { return code; }
    void setLocation(int l) { location = l; }
    int getLocation() { return location; }
    bool can_carry;

private:
    string word;
    string description;
    int code;
    int location;
};

class inventory {
public:
    string inventory;
    int itemnum = 0;
};

void set_room(vector<room> &rooms) {
    if (debug) cout << "Starting set_room\n";

    rooms[ENTRANCE].setDesc("entrance to the King's Dungeon");
    rooms[ENTRANCE].exits_to_room[NORTH] = HALLWAY;
    rooms[ENTRANCE].exits_to_room[EAST] = NONE;
    rooms[ENTRANCE].exits_to_room[SOUTH] = NONE;
    rooms[ENTRANCE].exits_to_room[WEST] = NONE;
    
    rooms[HALLWAY].setDesc("hallway");
    rooms[HALLWAY].exits_to_room[NORTH] = DUNGEON;
    rooms[HALLWAY].exits_to_room[EAST] = NONE;
    rooms[HALLWAY].exits_to_room[SOUTH] = ENTRANCE;
    rooms[HALLWAY].exits_to_room[WEST] = NONE;

    rooms[DUNGEON].setDesc("creepy dungeon");
    rooms[DUNGEON].exits_to_room[NORTH] = NONE;
    rooms[DUNGEON].exits_to_room[EAST] = EMPTY_CELL;
    rooms[DUNGEON].exits_to_room[SOUTH] = HALLWAY;
    rooms[DUNGEON].exits_to_room[WEST] = STAIRCASE;

    rooms[EMPTY_CELL].setDesc("empty cell");
    rooms[EMPTY_CELL].exits_to_room[NORTH] = NONE;
    rooms[EMPTY_CELL].exits_to_room[EAST] = NONE;
    rooms[EMPTY_CELL].exits_to_room[SOUTH] = NONE;
    rooms[EMPTY_CELL].exits_to_room[WEST] = DUNGEON;

    rooms[KINGS_DINING_HALL].setDesc("kings dining hall");
    rooms[KINGS_DINING_HALL].exits_to_room[NORTH] = LOBBY;
    rooms[KINGS_DINING_HALL].exits_to_room[EAST] = NONE;
    rooms[KINGS_DINING_HALL].exits_to_room[SOUTH] = NONE;
    rooms[KINGS_DINING_HALL].exits_to_room[WEST] = NONE;

    rooms[STAIRCASE].setDesc("staircase");
    rooms[STAIRCASE].exits_to_room[NORTH] = NONE;
    rooms[STAIRCASE].exits_to_room[EAST] = DUNGEON;
    rooms[STAIRCASE].exits_to_room[SOUTH] = NONE;
    rooms[STAIRCASE].exits_to_room[WEST] = LOBBY;

    rooms[LOBBY].setDesc("lobby");
    rooms[LOBBY].exits_to_room[NORTH] = BRIDGE;
    rooms[LOBBY].exits_to_room[EAST] = STAIRCASE;
    rooms[LOBBY].exits_to_room[SOUTH] = KINGS_DINING_HALL;
    rooms[LOBBY].exits_to_room[WEST] = KINGS_BEDROOM;

    rooms[KINGS_BEDROOM].setDesc("Kings Luxurious Bedroom");
    rooms[KINGS_BEDROOM].exits_to_room[NORTH] = NONE;
    rooms[KINGS_BEDROOM].exits_to_room[EAST] = LOBBY;
    rooms[KINGS_BEDROOM].exits_to_room[SOUTH] = BATHROOM;
    rooms[KINGS_BEDROOM].exits_to_room[WEST] = NONE;

    rooms[BATHROOM].setDesc("bathroom");
    rooms[BATHROOM].exits_to_room[NORTH] = KINGS_BEDROOM;
    rooms[BATHROOM].exits_to_room[EAST] = NONE;
    rooms[BATHROOM].exits_to_room[SOUTH] = NONE;
    rooms[BATHROOM].exits_to_room[WEST] = NONE;

    rooms[BRIDGE].setDesc("bridge");
    rooms[BRIDGE].exits_to_room[NORTH] = FOUNTAIN;
    rooms[BRIDGE].exits_to_room[EAST] = NONE;
    rooms[BRIDGE].exits_to_room[SOUTH] = LOBBY;
    rooms[BRIDGE].exits_to_room[WEST] = NONE;

    rooms[FOUNTAIN].setDesc("fountain");
    rooms[FOUNTAIN].exits_to_room[NORTH] = THE_GARDEN;
    rooms[FOUNTAIN].exits_to_room[EAST] = NONE;
    rooms[FOUNTAIN].exits_to_room[SOUTH] = BRIDGE;
    rooms[FOUNTAIN].exits_to_room[WEST] = NONE;

    rooms[THE_GARDEN].setDesc("beautiful garden");
    rooms[THE_GARDEN].exits_to_room[NORTH] = PATHWAY;
    rooms[THE_GARDEN].exits_to_room[EAST] = NONE;
    rooms[THE_GARDEN].exits_to_room[SOUTH] = FOUNTAIN;
    rooms[THE_GARDEN].exits_to_room[WEST] = NONE;

    rooms[PATHWAY].setDesc("pathway");
    rooms[PATHWAY].exits_to_room[NORTH] = FISHING_DOCK;
    rooms[PATHWAY].exits_to_room[EAST] = NONE;
    rooms[PATHWAY].exits_to_room[SOUTH] = THE_GARDEN;
    rooms[PATHWAY].exits_to_room[WEST] = NONE;

    rooms[FISHING_DOCK].setDesc("fishing dock");
    rooms[FISHING_DOCK].exits_to_room[NORTH] = THE_DARK_CAVERN;
    rooms[FISHING_DOCK].exits_to_room[EAST] = NONE;
    rooms[FISHING_DOCK].exits_to_room[SOUTH] = PATHWAY;
    rooms[FISHING_DOCK].exits_to_room[WEST] = NORTH;

    rooms[THE_DARK_CAVERN].setDesc("gloomy cavern");
    rooms[THE_DARK_CAVERN].exits_to_room[NORTH] = THE_DYING_TUNNELS;
    rooms[THE_DARK_CAVERN].exits_to_room[EAST] = NONE;
    rooms[THE_DARK_CAVERN].exits_to_room[SOUTH] = FISHING_DOCK;
    rooms[THE_DARK_CAVERN].exits_to_room[WEST] = NONE;

    rooms[THE_DYING_TUNNELS].setDesc("dying tunnels");
    rooms[THE_DYING_TUNNELS].exits_to_room[NORTH] = THE_DECAYING_TAVERNS;
    rooms[THE_DYING_TUNNELS].exits_to_room[EAST] = NONE;
    rooms[THE_DYING_TUNNELS].exits_to_room[SOUTH] = THE_DARK_CAVERN;
    rooms[THE_DYING_TUNNELS].exits_to_room[WEST] = NONE;

    rooms[THE_DECAYING_TAVERNS].setDesc("rotten tavern");
    rooms[THE_DECAYING_TAVERNS].exits_to_room[NORTH] = THE_BLACK_PIT;
    rooms[THE_DECAYING_TAVERNS].exits_to_room[EAST] = NONE;
    rooms[THE_DECAYING_TAVERNS].exits_to_room[SOUTH] = THE_DYING_TUNNELS;
    rooms[THE_DECAYING_TAVERNS].exits_to_room[WEST] = NONE;

    rooms[THE_BLACK_PIT].setDesc("dark pit");
    rooms[THE_BLACK_PIT].exits_to_room[NORTH] = THE_GHOST_CHAMBERS;
    rooms[THE_BLACK_PIT].exits_to_room[EAST] = NONE;
    rooms[THE_BLACK_PIT].exits_to_room[SOUTH] = THE_DECAYING_TAVERNS;
    rooms[THE_BLACK_PIT].exits_to_room[WEST] = NONE;

    rooms[THE_GHOST_CHAMBERS].setDesc("chamber full of ghosts");
    rooms[THE_GHOST_CHAMBERS].exits_to_room[NORTH] = THE_GOLDEN_CELL;
    rooms[THE_GHOST_CHAMBERS].exits_to_room[EAST] = NONE;
    rooms[THE_GHOST_CHAMBERS].exits_to_room[SOUTH] = THE_BLACK_PIT;
    rooms[THE_GHOST_CHAMBERS].exits_to_room[WEST] = NONE;

    rooms[THE_GOLDEN_CELL].setDesc("cell that is holding my missing wife");
    rooms[THE_GOLDEN_CELL].exits_to_room[NORTH] = NONE;
    rooms[THE_GOLDEN_CELL].exits_to_room[EAST] = NONE;
    rooms[THE_GOLDEN_CELL].exits_to_room[SOUTH] = THE_GHOST_CHAMBERS;
    rooms[THE_GOLDEN_CELL].exits_to_room[WEST] = NONE;
}

void set_directions(vector<words> &directions) {
    if (debug)
    cout << "Starting directions\n";

    directions[NORTH].setCode(NORTH);
    directions[NORTH].setWord("NORTH");
    directions[EAST].setCode(EAST);
    directions[EAST].setWord("EAST");
    directions[SOUTH].setCode(SOUTH);
    directions[SOUTH].setWord("SOUTH");
    directions[WEST].setCode(WEST);
    directions[WEST].setWord("WEST");
}

void set_verbs(vector<words> &verbs) {
    if (debug)
    cout << "Starting set_verbs\n";

    // enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK};
    verbs[GET].setCode(GET);
    verbs[GET].setWord("GET");
    verbs[DROP].setCode(DROP);
    verbs[DROP].setWord("DROP");
    verbs[USE].setCode(USE);
    verbs[USE].setWord("USE");
    verbs[OPEN].setCode(OPEN);
    verbs[OPEN].setWord("OPEN");
    verbs[CLOSE].setCode(CLOSE);
    verbs[CLOSE].setWord("CLOSE");
    verbs[EXAMINE].setCode(EXAMINE);
    verbs[EXAMINE].setWord("EXAMINE");
    verbs[INVENTORY].setCode(INVENTORY);
    verbs[INVENTORY].setWord("INVENTORY");
    verbs[LOOK].setCode(LOOK);
    verbs[LOOK].setWord("LOOK");
}

void set_nouns(vector<noun> &nouns) {
    if (debug)
    cout << "Starting set_nouns\n";

    // enum en_NOUNS {KEY, SWORD, SHEILD, APPLE, SOAP, STUFFED_BUNNY, MYSTERIOUS_ROCK, KINGS_CROWN, BROKEN_GLASSES, PAINTING, CELL_DOOR, METAL_PIPE, STEAK, FLOWER, LUCKY_COIN};
    nouns[CELL_DOOR].setWord("DOOR");
    nouns[CELL_DOOR].setCode(CELL_DOOR);
    nouns[CELL_DOOR].setDesc("a mysterious closed cell door");
    nouns[CELL_DOOR].can_carry = false;
    nouns[CELL_DOOR].setLocation(THE_GOLDEN_CELL);
    
    nouns[KEY].setWord("KEY");
    nouns[KEY].setCode(KEY);
    nouns[KEY].setDesc("a strange key");
    nouns[KEY].can_carry = true;
    nouns[KEY].setLocation(EMPTY_CELL);
    
    nouns[SWORD].setWord("SWORD");
    nouns[SWORD].setCode(SWORD);
    nouns[SWORD].setDesc("a sharp sword");
    nouns[SWORD].can_carry = true;
    nouns[SWORD].setLocation(HALLWAY);
    
    nouns[SHEILD].setWord("SHEILD");
    nouns[SHEILD].setCode(SHEILD);
    nouns[SHEILD].setDesc("a shiny looking sheild");
    nouns[SHEILD].can_carry = true;
    nouns[SHEILD].setLocation(DUNGEON);
    
    nouns[APPLE].setWord("APPLE");
    nouns[APPLE].setCode(APPLE);
    nouns[APPLE].setDesc("a delicious looking apple");
    nouns[APPLE].can_carry = true;
    nouns[APPLE].setLocation(KINGS_DINING_HALL);
    
    nouns[SOAP].setWord("SOAP");
    nouns[SOAP].setCode(SOAP);
    nouns[SOAP].setDesc("a bar of soap");
    nouns[SOAP].can_carry = false;
    nouns[SOAP].setLocation(BATHROOM);

    nouns[STUFFED_BUNNY].setWord("BUNNY");
    nouns[STUFFED_BUNNY].setCode(STUFFED_BUNNY);
    nouns[STUFFED_BUNNY].setDesc("a cute bunny");
    nouns[STUFFED_BUNNY].can_carry = false;
    nouns[STUFFED_BUNNY].setLocation(PATHWAY);

    nouns[MYSTERIOUS_ROCK].setWord("ROCK");
    nouns[MYSTERIOUS_ROCK].setCode(MYSTERIOUS_ROCK);
    nouns[MYSTERIOUS_ROCK].setDesc("a plain rock");
    nouns[MYSTERIOUS_ROCK].can_carry = true;
    nouns[MYSTERIOUS_ROCK].setLocation(BRIDGE);

    nouns[KINGS_CROWN].setWord("CROWN");
    nouns[KINGS_CROWN].setCode(KINGS_CROWN);
    nouns[KINGS_CROWN].setDesc("a very shiny crown");
    nouns[KINGS_CROWN].can_carry = true;
    nouns[KINGS_CROWN].setLocation(KINGS_BEDROOM);

    nouns[BROKEN_GLASSES].setWord("GLASSES");
    nouns[BROKEN_GLASSES].setCode(BROKEN_GLASSES);
    nouns[BROKEN_GLASSES].setDesc("a pair of old glasses");
    nouns[BROKEN_GLASSES].can_carry = true;
    nouns[BROKEN_GLASSES].setLocation(STAIRCASE);

    nouns[PAINTING].setWord("PAINTING");
    nouns[PAINTING].setCode(PAINTING);
    nouns[PAINTING].setDesc("a very expensive painting");
    nouns[PAINTING].can_carry = false;
    nouns[PAINTING].setLocation(LOBBY);

    nouns[METAL_PIPE].setWord("PIPE");
    nouns[METAL_PIPE].setCode(METAL_PIPE);
    nouns[METAL_PIPE].setDesc("a old looking pipe");
    nouns[METAL_PIPE].can_carry = false;
    nouns[METAL_PIPE].setLocation(THE_BLACK_PIT);

    nouns[STEAK].setWord("STEAK");
    nouns[STEAK].setCode(STEAK);
    nouns[STEAK].setDesc("a nice but cold steak");
    nouns[STEAK].can_carry = true;
    nouns[STEAK].setLocation(FISHING_DOCK);

    nouns[FLOWER].setWord("FLOWER");
    nouns[FLOWER].setCode(FLOWER);
    nouns[FLOWER].setDesc("a pretty flower");
    nouns[FLOWER].can_carry = true;
    nouns[FLOWER].setLocation(THE_GARDEN);

    nouns[LUCKY_COIN].setWord("COIN");
    nouns[LUCKY_COIN].setCode(LUCKY_COIN);
    nouns[LUCKY_COIN].setDesc("a lucky coin");
    nouns[LUCKY_COIN].can_carry = true;
    nouns[LUCKY_COIN].setLocation(FOUNTAIN);
}

void section_command(string Cmd, string &wd1, string &wd2) {
    if (debug)
    cout << "Starting section_command().\n";
    string sub_str;
    vector<string> words;
    char search = ' ';
    short i, j;

    for (i = 0; i < Cmd.size(); i++) {
        if (Cmd.at(i) != search) {
            sub_str.insert(sub_str.end(), Cmd.at(i));
        }
        if (i == Cmd.size() - 1) {
            words.push_back(sub_str);
            sub_str.clear();
        }
        if (Cmd.at(i) == search) {
            words.push_back(sub_str);
            sub_str.clear();
        }
    }
    for (i = words.size() - 1; i > 0; i--) {
        if (words.at(i) == "") {
            words.erase(words.begin() + i);
        }
    }
    for (i = 0; i < words.size(); i++) {
        for (j = 0; j < words.at(i).size(); j++) {
            if (islower(words.at(i).at(j))) {
                words.at(i).at(j) = toupper(words.at(i).at(j));
            }
        }
    }
    if (words.size() == 0) {
        cout << "No command given" << endl;
    }
    if (words.size() == 1) {
        wd1 = words.at(0);
    }
    if (words.size() == 2) {
        wd1 = words.at(0);
        wd2 = words.at(1);
    }
    if (words.size() > 2) {
        cout << "command too long. Only type one or two words (directions or verb "
                        "and noun)"<< endl;
    }
}

void look_around(int loc, vector<room> &rooms, vector<words> &directions,
                                 vector<noun> &nouns) {
    int i;
    cout << "I am in a " << rooms[loc].getDescription() << "." << endl;

    for (i = 0; i < DIRS; i++) {
        if (rooms[loc].exits_to_room[i] != NONE) {
            cout << "There is an exit " << directions[i].getWord() << " to a " << rooms[rooms[loc].exits_to_room[i]].getDescription() << "." << endl;
        }
    }

    // The look command should check which objects (nouns) are in the current room
    // and report them to the player.
    for (i = 0; i < DIRS; i++) {
        if (nouns[i].getLocation() == loc) {
            cout << "I see " << nouns[i].getDescription() << "." << endl;
        }
    }
}
bool parser(int &loc, string wd1, string wd2, vector<words> &directions,
                        vector<words> &verbs, vector<room> &rooms, vector<noun> &nouns) {
    static bool doorIsOpen = false; // false is closed door

    int i;
    for (i = 0; i < DIRS; i++) {
        if (wd1 == directions[i].getWord()) {
            if (rooms[loc].exits_to_room[directions[i].getCode()] != NONE) {
                loc = rooms[loc].exits_to_room[directions[i].getCode()];
                cout << "I am now in a " << rooms[loc].getDescription() << "." << endl;
                // A special case for the corridor storeroom door.
                if (loc == THE_GOLDEN_CELL or loc == THE_GHOST_CHAMBERS) {
                    nouns[CELL_DOOR].setLocation(loc);
                }

                return true;
            } else {
                cout << "No exit that way." << endl;
                return true;
            }
        }
    }

    int VERB_ACTION = NONE;
    int NOUN_MATCH = NONE;

    for (i = 0; i < VERBS; i++) {
        if (wd1 == verbs[i].getWord()) {
            VERB_ACTION = verbs[i].getCode();
            break;
        }
    }

    if (wd2 != "") {
        for (i = 0; i < NOUNS; i++) {
            if (wd2 == nouns[i].getWord()) {
                NOUN_MATCH = nouns[i].getCode();
                break;
            }
        }
    }
    if (VERB_ACTION == NONE) {
        cout << "No valid command entered." << endl;
        return true;
    }
    if (VERB_ACTION == LOOK) {
        look_around(loc, rooms, directions, nouns);
        return true;
    }

    // Actions for usage of VERB OPEN
    if (VERB_ACTION == CELL_DOOR) {
        if (loc == THE_GOLDEN_CELL or loc == THE_GHOST_CHAMBERS) {
            if (doorIsOpen == false) {
                doorIsOpen = true;
                rooms[THE_GHOST_CHAMBERS].exits_to_room[NORTH] = THE_GOLDEN_CELL;
                rooms[THE_GOLDEN_CELL].exits_to_room[SOUTH] = THE_GHOST_CHAMBERS;
                nouns[CELL_DOOR].setDesc("NONE");
                nouns[CELL_DOOR].setDesc("an open cell door");
                cout << "I have opened the door." << endl;
                return true;
            } else if (doorIsOpen == true) {
                cout << "The door is already open." << endl;
                return true;
            }
        } else {
            cout << "There is no door to open here." << endl;
            return true;
        }
    } else {
        cout << "Opening that door is not possible." << endl;
        return true;
    }
    return false;
}
void game_start(){
    cout << "Welcome player!\n";
    sleep(2);
    cout << "...You are a Knight looking for your captured wife. The King has her hidden somewhere in the the castle. Do you have what it takes to find your beloved Wife?\n";
    sleep(4);
    cout << "\n";
    cout << "Below are a list of commands you are able to use to help aid you in the search:\n";\
    cout << "1. " << "LOOK\n"; 
    cout << "\n";
}
// My verb funtions

int main() {
    if (debug)
    cout << "Starting main().\n";
    string command;
    string word_1;
    string word_2;

    // vector prototype
    vector<room> rooms(ROOMS);
    // room rooms[ROOMS];
    void set_room(vector<room> & rooms);
    set_room(rooms);

    vector<words> directions(DIRS);
    // words directions[DIRS];
    void set_directions(vector<words> & directions);
    set_directions(directions);

    vector<words> verbs(VERBS);
    // words verbs[VERBS];
    void set_verbs(vector<words> & verbs);
    set_verbs(verbs);

    vector<noun> nouns(NOUNS);
    // noun nouns[NOUNS];
    void set_nouns(vector<noun> & nouns);
    set_nouns(nouns);

    int location = ENTRANCE;

    if (debug) cout << "Setup is complete. Starting the main game loop.\n";

    game_start();

    sleep(4);

    while (word_1 != "QUIT") {
    command.clear();
    cout << "What shall you do? ";
    getline(cin, command);

    word_1.clear();
    word_2.clear();

    section_command(command, word_1, word_2);

    if (word_1 != "QUIT") {
        parser(location, word_1, word_2, directions, verbs, rooms, nouns);
        }
    }

    return 0;
}