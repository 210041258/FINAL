#include "repairman.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <unistd.h>
#define wait_and_clear sleep(3); system("cls");


void repairman::show_my_duty()
{
    int id_t,id;
    int arr[4];
    string str[4];
    ifstream f7("employee_duty.txt");
    ifstream f77("tickets.txt");
    while (f7 >> id_t >> id)
    {
        if(give_access_id() == id )
        {
            while (f77 >> arr[0] >> str[0] >> str[1] >> str[2] >> str[3] >> arr[1] >> arr[2] >> arr[3])
            {
                if(id_t == arr[0] )
                {
                    cout << "\nRepairing  Duty Information : " << endl;
                    cout << "The Place Of Duty : " << str[0] << endl;
                    cout << "You Must Be There At  :  " << str[2] << " on : 8:00 Am" << endl;
                    cout << "--------------------------------" << endl;
                }
            }
            f77.clear();
            f77.seekg(0,ios::beg);
        }
    }
    f77.close();
    f7.close();
    repairman::gui_1();
}

repairman::repairman(int _Id,std::string _name,std::string _DoJ)
    : employee(_Id, _name, "Repairman",100000, _DoJ)
{
}



void repairman::home_screen()
{
    wait_and_clear
    cout << "Hi Id : " << repairman::give_access_id() << endl;
    cout << "\n1-Show My Duty\t2-Exite\n ";
    int i;
    cin >> i ;
    if(i == 1){
        show_my_duty();
    }
    else{
        exit(1);
    }
}

void repairman::gui_1()
{
    cout << "\a\n1-Return to Dashboard\n2-Exit\nEnter the Number : " << endl;
    int x;
    cin >> x;
    if (x == 1)
    {
        wait_and_clear
        repairman::home_screen();
    }
    else
    {
        exit(0);
    }
}
