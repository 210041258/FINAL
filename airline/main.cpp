#include <fstream>
using namespace std;
#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include "user/customer/customer.h"
#include "tickets/tickets.h"
#include "user/admin/admin.h"
#include "user/user.h"
#define _WIN32_WINNT 0x0502
#include "resource.h"
int search_username(string username_);
void start_program();
void login();
void sign_up();
void format_screen();

#define wait_and_clear sleep(3); system("cls");

int main()
{
    format_screen();
    start_program();
    cin.get();
    return 0;
}

void start_program()
{
    int x;
    cout << "Welcome to our system for airlines tickets" << endl;
    cout << "\a \t1-Login  \t2-Sign up  \t3-Exit\n" << endl;
    cout << "Enter the number :" << endl;
    cin >> x;
    if(1<=x&&x<=3)
    {
        if(x==1)
        {
            login();
            return;
        }
        else if(x==2)
        {
            sign_up();
            return;
        }
        else if(x==3)
        {
            exit(1);
        }
    }
    else
    {
        cout << "Invalid option. Please choose again." << endl;
        wait_and_clear
        start_program();
    }
}

int search_username(string username_)
{
    ifstream f3("user.txt");
    string str[2];
    int arr[5];
    while (f3 >> str[0] >> str[1] >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4])
    {
        if (str[0] == username_)
        {
            f3.close();
            return 1;
        }
    }
    f3.close();
    return 0;
}


void login()
{
    string username, user_temp;
    string password, pass_temp;
    int arr[5];

    cout << "Enter Username :" << endl;
    cin.ignore();
    getline(cin, username);
    cout << "Enter Password :" << endl;
    getline(cin, password);

    ifstream user_data("user.txt");

    // Check if the file is open
    if (!user_data.is_open())
    {
        cerr << "Error opening user.txt" << endl;
        return;
    }

    bool userFound = false;

    while (user_data >> user_temp >> pass_temp >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4])
    {
        if ((username == user_temp) && (password == pass_temp))
        {
            userFound = true;
            if ((arr[0] == 1) && (arr[1] == 0))
            {
                wait_and_clear
                customer u1(user_temp, pass_temp, 1, 0, 1, 1, 100000);
                cout << "Sign in Done ..!" << endl;
                wait_and_clear
                u1.customer_dashboard();
            }
            else if ((arr[1] == 1) && (arr[0] == 1))
            {
                wait_and_clear
                cout << "\nSign in as Customer press 1 \nSign in as admin press 2 \n";
                int aa;
                cin >> aa;
                if (aa == 1)
                {
                    customer u1(user_temp, pass_temp, 1, 0, 1, 1, 100000);
                    cout << "Sign in Done ..!" << endl;
                    wait_and_clear
                    u1.customer_dashboard();
                }
                else if (aa == 2)
                {
                    admin u2(user_temp, pass_temp, 1, 1, 1, 1, 100000);
                    cout << "Sign in Done {ADMIN} ..!" << endl;
                    wait_and_clear
                    u2.admin_dashboard();
                }
                else
                {
                    cout << "Invalid option. Please choose again." << endl;
                    wait_and_clear
                    start_program();
                }
            }
        }
    }

    user_data.close();

    if (!userFound)
    {
        cout << "Error: Invalid username or password." << endl;
        wait_and_clear;
        start_program();
    }
}

void sign_up()
{
    string pass_temp, user_temp;
    cout << "Enter Username :" << endl;
    cin >> user_temp ;
    if(!(search_username(user_temp)))
    {
        cout << "Enter Password :" << endl;
        cin >> pass_temp;
        customer c1(user_temp, pass_temp, 1, 0, 1, 1, 100000);
        cout << "Sign UP Done ..!" << endl;
        wait_and_clear
        c1.customer_dashboard();
    }
    else
    {
        cout << " Try Another Name !! "<<endl;
        wait_and_clear
        start_program();
    }
}



void format_screen(){
    SetConsoleTitleA("Airline Project V1.2");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN );
    HWND hwnd = GetConsoleWindow();
    if( hwnd != NULL )
    {
        SetWindowPos(hwnd,0,0,0,1250,200,SWP_SHOWWINDOW|SWP_NOMOVE);
    }
    system("color 5f");
}
