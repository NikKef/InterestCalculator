#include <iostream>
#include <iomanip>

using namespace std;

//main menu
void menu();

//function for option 1
int calc_age(float current_inv, float avg_return, float monthly_investment, int age, float goal_yearly_r);

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
                float ci, ar, mi, gy;
                int a;

                cout << "Enter your age:  ";
                cin >> a;
                cout << "Enter your current value of your investments/assets: ";
                cin >> ci;
                cout << "Enter your average projected return percentage (Averge inflation-adjusted retun of the stock market is about 8%): ";
                cin >> ar;
                cout << "Enter the amount you project to invest monthly from now on: ";
                cin >> mi;
                cout << "What is your yearly target salary from your investments for when you retire: ";
                cin >> gy;

                cout << "You can retire at age " << calc_age(ci, ar, mi, a, gy) << " earning " << fixed << setprecision(2) << gy << " per year from your investments.\n";
                cout << "Note! The calculation is done assuming that you can sell 4 percent of your assets every year.\n";
                cout << "In this way, you can withdraw the amount of " << fixed << setprecision(2) << gy << " evry year without loosing any of principal amount while outpacing inflation\n";

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

int calc_age(float current_inv, float avg_return, float monthly_investment, int age, float goal_yearly_r)
{
    int r_age = -1;
    float sum_inv = current_inv;
    float goal_amount = goal_yearly_r / 0.04;

    if(goal_amount >= current_inv)
    {
        r_age = age;
        cout << "You can already retire. Well done!\n";
    }
    else
    {
        r_age = age;

        do
        {
            sum_inv = sum_inv * (1 + avg_return) + monthly_investment * 12 * (1 + avg_return) / 2;
            r_age++;
        } while (sum_inv < goal_amount);
    }

    return r_age;
}