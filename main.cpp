#include <iostream>

using namespace std;

//main menu
void menu();

int main()
{
    int choice = -1;

    do
    {
        menu();
        cin >> choice;

        switch(choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                cout << "Exiting....\n";
                break;
            default:
                cout << "Wrong input. Choice must be between 1 and 3 inclusive!\n";
        }
    } while (choice != 3);
    

    return 0;
}

void menu()
{
    cout << "                   ---------------------------------\n";
    cout << "                -------------------------------------\n";
    cout << "              ---------- Interest Calculator ----------\n";
    cout << "                -------------------------------------\n";
    cout << "                  ---------------------------------\n";
    cout << "1. Find out which age you can retire using your current investing practises\n";
    cout << "2. Find out how to change your stategy to retire at your desired age\n";
    cout << "3. Exit\n";
    cout << "Enter(1-3): ";
}