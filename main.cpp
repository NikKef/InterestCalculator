#include <iostream>
#include <iomanip>

#define RETURN_RATE 0.08

using namespace std;

//main menu
void menu();

//function for option 1
int calc_age(float current_inv, float avg_return, float monthly_investment, int age, float goal_yearly_r);

//function for option 2
string eval_strat(int current_age, int retirement_age, float current_inv, float goal_yearly_r, float &monthly_inv, float &yearly_sal);

int main()
{
    int choice = -1;

    do
    {
        menu();
        cin >> choice;

        string msg;

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
                int current_age, retirement_age;
                float current_inv, monthly_inv, goal_yearly_r, yearly_sal;

                cout << "Enter your age: ";
                cin >> current_age;
                cout << "Enter your target retirement age: ";
                cin >> retirement_age;
                while(retirement_age < current_age)
                {
                    cout << "Retirement age cannot be smaller than current age!\n";
                    cout << "Enter your target retirement age again: ";
                    cin >> retirement_age;
                }
                cout << "Enter the value of your investments/assets currently: ";
                cin >> current_inv;
                cout << "What is your yearly target salary from your investments for when you retire: ";
                cin >> goal_yearly_r;

                msg = eval_strat(current_age, retirement_age, current_inv, goal_yearly_r, monthly_inv, yearly_sal);

                if(msg == "up")
                {
                    cout << "You can retire wihtout making any further investments.\n";
                    cout << "Assuming an average yearly return rate of " << RETURN_RATE * 100 << '%';
                    cout << " and a yearly withdrawal of 4" << '%' << " of your portfolio aftre retirement.\n";
                    cout << "Yearly salary at " << retirement_age << " and onwards: ";
                    cout << fixed << setprecision(2) << yearly_sal << "\n";
                }
                else if(msg == "down")
                {
                    cout << "Assuming an average yearly return rate of " << RETURN_RATE * 100 << '%';
                    cout << " and a yearly withdrawal of 4" << '%' << " of your portfolio after retirement.\n";
                    cout << "You can retire at age " << retirement_age << " making monthly contributions of ";
                    cout << fixed << setprecision(2) << monthly_inv << " with a yearly salary of ";
                    cout << fixed << setprecision(2) << yearly_sal << "\n";
                }
                else
                    cout << "Something went wrong. Try again.\n";

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
    int r_age = age;
    float sum_inv = current_inv;
    float goal_amount = goal_yearly_r / 0.04;

    if(goal_amount > current_inv)
    {
        r_age = age;

        do
        {
            sum_inv = sum_inv * (1 + avg_return/100.0) + monthly_investment * 12 * (1 + avg_return/100.0) / 2;
            r_age++;
        } while (sum_inv < goal_amount);
    }

    return r_age;
}

string eval_strat(int current_age, int retirement_age, float current_inv, float goal_yearly_r, float &monthly_inv, float &yearly_sal)
{
    string return_msg;

    return_msg.clear();

    monthly_inv = 0;

    float current_no_contr = current_inv * pow(RETURN_RATE, retirement_age - current_age);
    float goal_amount = goal_yearly_r / 0.04;

    if(current_no_contr >= goal_amount)
    {
        return_msg = "up";
        yearly_sal = current_no_contr * 0.04;
    }
    else
    {
        return_msg = "down";
        
        bool done = false;
        int duration = retirement_age - current_age;
        float sum;

        do
        {
            monthly_inv += 100;
            sum = current_inv;

            for(int i = 0; i < duration; i++)
            {
                sum = sum * (1 + RETURN_RATE) + monthly_inv * 12 * (1 + RETURN_RATE) / 2;
            }

            if(sum >= goal_amount)
            {
                done = true;
                yearly_sal = sum * 0.04;
            }
        } while(!done);
    }

    return return_msg;
}