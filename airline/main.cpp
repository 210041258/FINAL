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
#include "resource.h"
#include "employee/employee.h"
#include "employee/repairman/repairman.h"
#include "employee/driver/driver.h"
#include "employee/host/host.h"
#define wait_and_clear sleep(3); system("cls");


int search_username(string username_);
void start_program();
void login();
void sign_up();
void format_screen();
void  _security_rules_checker();
void login_employee();
#define wait_and_clear sleep(3); system("cls");

int main()
{
    _security_rules_checker();
    format_screen();
    start_program();
    return 0;
}

void start_program()
{
    int x;
    cout << "Welcome to our system for airlines tickets" << endl;
    cout << "\a \t1-Login User  \t2-Sign up User \t3- Login Employee \t4-Exit\n" << endl;
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
            login_employee();
            return;
        }
        else if(x==4)
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
            if (arr[1] == 0)
            {
                user_data.close();
                wait_and_clear
                customer u1(user_temp, pass_temp, arr[0], arr[1], arr[2],arr[3], arr[4]);
                cout << "Sign in Done ..!" << endl;
                wait_and_clear
                u1.customer_dashboard();
            }
            else if (arr[1] == 1)
            {
                user_data.close();
                wait_and_clear
                cout << "\nSign in as Customer press 1 \nSign in as admin press 2 \n";
                int aa;
                cin >> aa;
                if (aa == 1)
                {
                    user_data.close();
                    customer u1(user_temp, pass_temp, arr[0], arr[1], arr[2],arr[3], arr[4]);
                    cout << "Sign in Done ..!" << endl;
                    wait_and_clear
                    u1.customer_dashboard();
                }
                else if (aa == 2)
                {
                    user_data.close();
                    admin u2(user_temp, pass_temp, arr[0], arr[1], arr[2],arr[3], arr[4]);
                    cout << "Sign in Done {ADMIN} ..!" << endl;
                    wait_and_clear
                    u2.admin_dashboard();
                }
                else
                {
                    user_data.close();
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



void format_screen()
{
    SetConsoleTitleA("Airline Project V1.2");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN );
    HWND hwnd = GetConsoleWindow();
    if( hwnd != NULL )
    {
        SetWindowPos(hwnd,0,400,300,1250,200,SWP_SHOWWINDOW);
    }
    system("color 5f");
}



void  _security_rules_checker()
{
    ifstream user_data("user.txt");
    ifstream user_operation_data("operation_user.txt");
    ofstream temp("temp.txt",ios::app);
    int uo[2];
    string uo_username;
    int ud[5];
    string ud_napas[2];
    while(user_operation_data >> uo_username >> uo[0] >> uo[1])
    {
        while(user_data >> ud_napas[0] >> ud_napas[1] >> ud[0] >> ud[1] >> ud[2] >> ud[3] >> ud[4])
        {
            if(uo_username == ud_napas[0])
            {
                if(ud[0] == 1)
                {
                    temp << uo_username <<  " "  << uo[0]  <<  " " << uo[1] << endl;
                }
            }
        }
        user_data.clear();
        user_data.seekg(0,ios::beg);
    }
    temp.close();
    user_operation_data.close();
    user_data.close();
    ifstream temp_reader("temp.txt");
    ofstream user_operation_data_writer("operation_user.txt");
    while(temp_reader >> uo_username >> uo[0] >> uo[1])
    {
        user_operation_data_writer << uo_username << " " << uo[0]  << " "<<  uo[1] << endl;
    }
    temp_reader.close();
    user_operation_data_writer.close();
    remove("temp.txt");
    remove("user_new.txt");
}

void login_employee()
{
    string username, job;
    int id;
    bool founded =  false;
    int a;
    float b;
    string arr[3];
    cout << "Enter ID :" << endl;
    cin >> id;
    cout << "Enter Username :" << endl;
    cin >> username;
    cout << "Enter Job :" << endl;
    cin >> job;
    ifstream f1("employee.txt");
    while (f1 >> a >> arr[0] >> arr[1] >> b>> arr[2])
    {
        if (a == id && arr[0] == username && arr[1] == job) {
                    founded = true ;
                    if(job == "driver")
                    {
                        driver* div;
                        div = new driver(a, username, arr[2]);
                        div->home_screen();
                        delete div;
                        break;
                    }
                    else if(job == "host")
                    {
                        host* host1;
                        host1 = new host(a, username, arr[2]);
                        host1->home_screen();
                        delete host1;
                        break;
                    }
                    else if(job == "repairman")
                    {
                        repairman* rep;
                        rep = new repairman(a, username, arr[2]);
                        rep->home_screen();
                        delete rep;
                        break;
                    }
                    else
                    {
                        cout << "Check the Job You Entered !! " << endl;
                        wait_and_clear
                        start_program();
                    }
                }


    }
    f1.close();
    if(founded != true)
    {
        cout << "Check the Info about Your Job You Entered !! " << endl;
        wait_and_clear
        start_program();
    }
}
