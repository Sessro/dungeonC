#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <conio.h> // For _getch()
using namespace std;

// Clears the console screen for both Windows and Unix-based systems.
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Introduces the game with a descriptive narrative and waits for the user to press Enter.
void startOfGam()
{
    clearScreen();

    cout << "You wake up to the taste of blood in your mouth and a hole in your stomach.\n";
    cout << "The smell of rotten flesh sticks to the dark abyss that surrounds you.\n";
    cout << "Restless moans of the damned cry around you. You can hardly remember your name.\n";
    cout << "\nPress Enter to continue...";

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Wait for Enter key
}

// Prompts the user to enter their name.
void nameQ()
{
    clearScreen();

    cout << "What is your name? ";
}

// Captures the player's name as a string, allowing spaces.
string name()
{
    string response;

    getline(cin, response); // Allows spaces in the name

    return response;
}

// Placeholder function for level-related prompts.
void lvlQ()
{
    clearScreen();
}

// Prompts the user to enter their age and validates the input.
int level()
{
    int response;

    while (true)
    {
        cout << "How old are you? ";

        cin >> response;

        if (cin.fail()) // Check if input is invalid
        {
            cout << "Invalid input.\n";

            cin.clear(); // Clear the error flag

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else if (response < 16) // Optional range validation
        {
            cout << "Are you serious? Try again.\n";
        }
        else if (response > 40)
        {
            cout << "Too old. Try again.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer after valid input

            break; // Exit the loop when input is valid
        }
    }

    if (response == 0)
    {
        cout << "How?\n";
    }

    return response;
}

// Displays a menu for choosing a character's background class.
int chooseStarterClass()
{
    int choice = 0;

    char confirmationKey;

    do
    {
        clearScreen();
        cout << "Choose your background (1-5):\n"
            << "1. Brawler\n"
            << "2. Knight\n"
            << "3. Mage\n"
            << "4. Thief\n"
            << "5. Monkey\n"
            << "Your choice: ";
        cin >> choice;

        // Input validation for class choice.
        if (cin.fail() || (choice < 1 || choice > 5) && choice != 8)
        {
            cin.clear(); // Clear the error flag

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            cout << "Invalid. Please select 1-5.\n";

            system("pause"); // Pause to let the user see the error message

            continue;
        }

        // Display selected class details
        switch (choice)
        {
        case 1: cout << "\nBrawler: A young fighter with hands of steel! Born from the strongest fighter to set foot in the Nobleman's Arena\n";
            cout << "strives to looks for his own glory.\n";break;
        case 2: cout << "\nKnight: A noble warrior looking for his lost love. Far from his home in Alewood\n";
            cout << "he must find the people who stole his heart and soul.\n";break;
        case 3: cout << "\nMage: Gifted with knowledge and strength but left with a curse.\n";
            cout << "The mage seeks out to reverse what had been done to her.\n";break;
        case 4: cout << "\nThief: An agile man who bears his godfather's knife accompanied by his pet dog Salum.\n";
            cout << "Brought up by the slums but in search of gold.\n";break;
        case 5: cout << "\nMonkey: HOO HAA HOO HAA HOO HAA HOO HAA HOO HAA HOO HAA HOO HAA HOO HAA HOO HAA HOO HAA HOO HAA\n"; break;
        case 8: cout << "\n???: 0111010001101000011001010010000001100110011000010111010001100101001000000110111101100110001000000110010001100101011100110111010001110010011101010110001101110100011010010110111101101110001000000110100101110011001000000110000101101100011100110110111100100000011101000110100001100101001000000110101001101111011110010010000001101111011001100010000001110010011001010110001001101001011100100111010001101000\n";break;
        }

        cout << "\nWould you like to continue?\n";
        cout << "(Press Enter to confirm, Backspace to go back) : ";

        confirmationKey = _getch();

        if (confirmationKey == '\b') // Backspace key
        {
            cout << "\nReturning to class selection.\n";
            continue; // Loop back to re-display the menu
        }
        else if (confirmationKey == '\r') // Enter key
        {
            break; // Confirm and exit loop
        }
        else
        {
            cout << "\nInvalid key. Press Enter to confirm or Backspace to go back.\n";
        }
    } while (true);

    return choice;
}

// Displays the player's details, including name, age, and chosen class.
void playerDetails(string playerName, int playerLevel, int playerClass)
{
    clearScreen();

    cout << "Player Details:\n";
    cout << "Name: " << playerName << endl;
    cout << "Age: " << playerLevel << endl;

    string className;

    switch (playerClass)
    {
    case 1: className = "Brawler"; break;
    case 2: className = "Knight"; break;
    case 3: className = "Mage"; break;
    case 4: className = "Thief"; break;
    case 5: className = "Monkey"; break;
    case 8: className = "???";break;
    default: className = "Unknown"; break;
    }
    cout << "Class: " << className << endl;
}

// Simulates an encounter with a mysterious character or entity.
void theMan(int playerClass)
{
    cout << "\nOut of the depths of the shadows a withered monster presents itself! Could it be man?\n";

    char action;

    do
    {
        cout << "\nWhat will you do abandoned one?\n";
        cout << "1. Kill it.\n";
        cout << "2. Watch it linger in the dark\n";
        cout << "3. Slip into the darkness\n";
        cout << "What is your destiny?(1-3): ";
        cin >> action;

        if (cin.fail()) // Validate input
        {
            cin.clear(); // Clear the error flag

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            cout << "\nInvalid choice! Please enter 1, 2, or 3.\n";

            continue;
        }
        switch (action)
        {
        case '1': //kill it.
            switch (playerClass)
            {
            case 1: cout << "\nYou kill the monster with your bear hands, it's cold blood flows down your arms \n";
                cout << "and it dies without any retaliation. \n"; break;
            case 2: cout << "\nYou run towards it and strike your sword deep into it's chest, \n";
                cout << "it's cold blood flows down your sword and it dies without any retaliation \n";break;
            case 3: cout << "\nYou cast a simple spell with your palms and break its neck instantly \n";
                cout << "and without it speaking a whisper \n";break;
            case 4: cout << "\nYou command Salum to tear its throat out, Salum obeys and \n";
                cout << "rips the throat out of the monster killing it instantly \n";break;
            case 5: cout << "\nYOU SCREAM \"HOO HAA HOO HAA HOO HAA\" RUNNING AT THE MONSTER, \n";
                cout << "MAULING IT'S FACE AND KILLING IT INSTANTLY \n";break;
            case 8: cout << "\nYou walk away set on your own path \n";break;
            }
            break;

        case '2': //watch it linger in the dark
            switch (playerClass)
            {
            case 1: cout << "\nYou stand before the creature, gripping onto the hole in your stomach and \n";
                cout << "you yell,\"WHAT DO YOU WANT FOUL THING?\" \n";break;
            case 2:cout << "\nYou stand straight with pride fighting the pain that lies in your stomach and \n";
                cout << "ask, \"What do you want, creature?\" \n";break;
            case 3:cout << "\nAs you stand you try to heal the wound lying in your stomach but nothing works \n";
                cout << "and you ask, \"What do you want?\" to the creature. \n";break;
            case 4: cout << "\nSalum stares down the monster while you hold on to your stomach, \n";
                cout << "and you ask, \"What do you want thing?\" to the monster. \n";break;
            case 5: cout << "\nYOU SCREAM, \"HOO HAA HOO HAA\" STARING THE CREATURE DOWN. \n";break;
            case 8: cout << "\nThe man lets out a cry and says, \"YOU?! HOW COULD THIS BE?!\" \n";
                cout << "You walk away set on your own path. \n";break;
            }
            break;

        case '3': //slip into the darkness
            switch (playerClass)
            {
            case 1: cout << "\nYou take 2 steps back and slip into the darkness. You watch the monster pass \n";
                cout << "as you shield your wound. \n";break;
            case 2: cout << "\nYou take 2 steps back and slip into the darkness. You watch the monster pass  \n";
                cout << "as you shield your wound. \n";break;
            case 3: cout << "\nYou take 2 steps back and slip into the darkness. You press your palms into \n";
                cout << "your stomach to heal as you watch the monster walk by. The healing does not work.";break;
            case 4: cout << "\nYou and salum step back into the darkness. You watch the monster pass \n";
                cout << "as you shield your wound. \n";break;
            case 5: cout << "\nYOU STEP BACK INTO THE DARKNESS. YOU WATCH THE MONTSER PASS \n";
                cout << "AS YOU SHIELD YOUR WOUND. YOU TRY NOT TO HOO HAA HOO HAA. \n";break;
            case 8: cout << "\nYou walk away own your own path. \n";break;
            }
            break;
        }
    } while (action != '1' && action != '2' && action != '3');
}

// The main game loop that allows restarting the game.
void allMain()
{
    char playAgain;

    do
    {
        clearScreen();

        startOfGam();

        nameQ();

        string playerName = name();

        lvlQ();

        int playerLevel = level();

        int playerClass = chooseStarterClass();

        playerDetails(playerName, playerLevel, playerClass);

        theMan(playerClass);

        cout << "\nWould you like to play again? (R to restart): ";

        playAgain = _getch(); // Use _getch() to capture a single key press
    } while (playAgain == 'r' || playAgain == 'R');
}

int main()
{
    allMain();

    system("pause");
}