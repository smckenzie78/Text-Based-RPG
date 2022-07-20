#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

void inGame();
int main();
void battle();
void shop();

class Player{
    private:
        string playerName;
        int health;
        int defense;
        int magic;
        int newGame = 0;
    public:
        void setHealth(int val)
        {
            health = val;
        }
        void setDefense(int val)
        {
            defense = val;
        }
        void setMagic(int val)
        {
            magic = val;
        }
        void setnewGame(int val)
        {
            newGame = val;
        }
        int getHealth()
        {
            return health;
        }
        int getDefense()
        {
            return defense;
        }
        int getMagic()
        {
            return magic;
        }
        void getName()
        {
            cout << playerName;
        }
        void loadPlayer()
        {
            ifstream gameFile("gameFile.txt");
            string statsString;
            getline(gameFile, statsString);
            playerName = statsString;
            getline(gameFile, statsString);
            setHealth(stoi(statsString));
            getline(gameFile, statsString);
            setDefense(stoi(statsString));
            getline(gameFile, statsString);
            setMagic(stoi(statsString));
            gameFile.close();
            if(newGame == 1)
            {
                cout << "Welcome to my game " << playerName << "!" << endl;
                inGame();
            }
            else if(newGame == 2)
            {
                cout << "Welcome back " << playerName << "!" << endl;
                inGame();
            }
        }
        void newPlayer()
        {
            cout << "New game selected" << endl;
            cout << "Enter a name for your character: ";
            cin >> playerName;
            ofstream gameFile("gameFile.txt");
            gameFile << playerName << endl << "1\n5\n2\n";
            gameFile.close();
            newGame = 1;
        }
};

void inGame()
{   
    string menuInput;
    cout << "Choose an action" << endl;
    cout << "Press 'a' for Adventure Mode, 's' to go to the Shop, 'd' to check your Stats, and 'f' to Exit to Title Screen" << endl;
    cin >> menuInput;

    if((menuInput == "a") || (menuInput == "A"))
    {
        battle();
    }
    else if((menuInput == "s") || (menuInput == "S"))
    {
        shop();   
    }
    else if((menuInput == "d") || (menuInput == "D"))
    {
        Player player;
        player.setnewGame(3);
        player.loadPlayer();
        player.getName();
        int health = player.getHealth();
        int defense = player.getDefense();
        int magic = player.getMagic();
        cout << endl;
        cout << "Health: " << health << endl;
        cout << "Defense: " << defense << endl;
        cout << "Magic: " << magic << endl;
        inGame();
    }
    else if((menuInput == "f") || (menuInput == "F"))
    {
        cout << "Ending game session..." << endl;
        main();
    }
    else
    {
        cout << "Invalid input, try again!" << endl;
        inGame();
    }

}

void shop()
{

}

void battle()
{

}

int main()
{
    string input;
    cout << "TEXT-BASED RPG" << endl;
    cout << "Press 'n' for New Game, 'l' for Load Game, 'f' to Exit Game" << endl;
    cin >> input;
    Player player;

    if((input == "n") || (input == "N"))
    {
        player.newPlayer();
        player.loadPlayer();
    }
    else if((input == "l") || (input == "L"))
    {
        player.setnewGame(2);
        player.loadPlayer();    
    }
    else if((input == "f") || (input == "F"))
    {
        cout << "Thanks for playing!" << endl;
        return 0;
    }
    else
    {
        cout << "Invalid input, try again!" << endl;
        main();
    }
    
    return 0;
}