#include "customer.h"


int search_id_user(string username,int id,int price)
{
    string str;
    int in[2];
    ifstream f5("operation_user.txt");
    while (f5 >> str >> in[0] >> in[1])
    {
        if (username == str&&(id==in[0])&&(price=in[1]))
        {
            return in[1];
            f5.close();
        }
    }
    return 0;
    f5.close();
}
void customer::view_tickets()
{
    ifstream fileoutput("tickets.txt");
    if (!fileoutput.is_open())
    {
        cout << " There is No Tickets Inside the System" << endl;
        return;
    }
    int arr[4];
    string str[4];
    cout << "Ticket Id \t" << "Ticket from \t" << "Ticket where \t" << "Ticket date to go\t" << "Ticket date to return \t" << "Ticket Price\t"<< "Requirment Visa\t" << "Requirment Covid-19" << endl;
    // >> int >> int
    while (fileoutput >> arr[0] >> str[0] >> str[1] >> str[2] >> str[3] >> arr[1] >> arr[2] >> arr[3])
    {
        cout << arr[0] << "\t\t" << str[0] << "\t\t"<< str[1] << "\t\t" << str[2] << "\t\t" << str[3] << "\t\t" << arr[1] << "\t\t" << (arr[2]==1 ? "Yes" : "No") <<"\t\t"<< (arr[3]==1 ? "Yes" : "No") << endl;
    }
    fileoutput.close();
}

customer::customer(string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_)
    : user(_username, _password, _access, _admin_access, _co_cert_, _visa_cert_, _balance_)
{
}

customer::~customer()
{
}

void customer::gui_1()
{
    wait_and_clear
    cout << "\a\n1-Return to Dashboard\n2-Exit\nEnter the Number : " << endl;
    int x;
    cin >> x;

    if (x == 1)
    {
        wait_and_clear
        customer::customer_dashboard();
    }
    else
    {
        exit(0);
    }
}

void customer::buy_ticket()
{
    int id_;
    cout << "Enter Id: " << endl;
    cin >> id_;
    tickets t1(0,"","","","",000,000,00);
    t1 = t1.extract_info_id(id_);
    if (!(t1.give_access_price()))
    {
        cout << "ID Ticket Not Found !! " << endl;
        customer::customer_dashboard();
    }
    if(customer::give_access_access()==0){
        cout << " \n  \t \t \a you can't do any operation , you are blocked !! \n " << endl ;
        wait_and_clear
        customer::customer_dashboard();
    }
    int temp = user::give_access_balance() - t1.give_access_price();
    if ((temp)<0)
    {
        cout << "Check the Balance !!" << endl;
        wait_and_clear
        customer::customer_dashboard();
    }
    user::edit_access_balance(temp);
    user::save_user_operation(user::give_access_username(), t1.give_access_id(), t1.give_access_price());
    user::update_user_direct(user::give_access_username());
    t1.print_info_id(id_);
    sleep(3);
    cout << "Your Available Balance : " << user::give_access_balance() << endl;
    cout << "Your Operation is done !!" << endl;
    sleep(2);
    gui_1();
}

void customer::return_ticket()
{
    int id_;
    cout << "Enter Id: " << endl;
    cin >> id_;
    tickets t1(00,"","","","",00,00,0);
    t1=t1.extract_info_id(id_);
    if(!t1.give_access_id())
    {
        cout << "ID Ticket Not Found !! " << endl;
        customer::gui_1();
    }
    if(customer::give_access_access()==0){
        cout << " \n  \t \t \a you can't do any operation , you are blocked !! \n " << endl ;
        wait_and_clear
        customer::customer_dashboard();
    }
    int pi = search_id_user(user::give_access_username(),id_,t1.give_access_price());
    if(pi)
    {
        user::edit_access_balance(user::give_access_balance() + pi);
        user::return_user_operation(user::give_access_username(), t1.give_access_id(), pi);
        user::update_user_direct(user::give_access_username());
        sleep(3);
        cout << "Your Operation is done !!" << endl;
    }
    else
    {
        cerr << "Make Sure you Bought  the ticket !! " <<endl;
    }
    sleep(3);
    customer::gui_1();
}

void customer::customer_dashboard()
{

    customer::view_tickets();
    cout << "Welcome To User Panel " << endl;
    cout << "1 - Buy Ticket " << endl;
    cout << "2 - Return Ticket " << endl;
    cout << "3 - View Information " << endl;
    cout << "4 - Exit Program " << endl;

    int x;
    cin >> x;

    switch (x)
    {
    case 1:
        buy_ticket();
        break;
    case 2:
        return_ticket();
        break;
    case 3:
        view_my_information();
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << "Invalid option. Please choose again." << endl;
        customer::customer_dashboard();
        break;
    }
}
void  customer::view_my_information()
{
    wait_and_clear
    cout << "\nYour Name : " << customer::give_access_username();
    cout << "\nYour balance : " << customer::give_access_balance();
    cout << "\nYour Accessable to do any operation  : " << (customer::give_access_access() == 1 ? "Yes":"No");
    cout << "\n 0-View My Tickets \n 1-Delete Your Account \n 2- Back \n";
    int x;
    cin >> x ;
    if(x== 0){
    cout << " \n\n \t \t You will be Redirected to Your Tickets Screen !! \n\n " << endl;
    wait_and_clear
    customer::view_my_tickets();
    }
    else if(x == 1 )
    {
        cout << "\n \n \t Your Account Will be Deleted !! \n \t after 5 seconds !! \n \a \n \t You Will Exit the program !! " ;
        wait_and_clear
        customer::delete_username(customer::give_access_username());
        exit(1);
    }
    else if(x == 2)
    {
        wait_and_clear
        customer::customer_dashboard();
    }
    else{
        exit(1);
    }
}

void     customer::view_my_tickets(){
ifstream user_data("user.txt");
int arr[4];
string str[4];
int uo[2];
ifstream user_operation_data("operation_user.txt");
ifstream fileoutput("tickets.txt");
string uo_username;
while(user_operation_data >> uo_username >> uo[0] >> uo[1] ){
while (fileoutput >> arr[0] >> str[0] >> str[1] >> str[2] >> str[3] >> arr[1] >> arr[2] >> arr[3]){
            if(uo[0] == arr[0]){
            cout << "\nTicket Information: " << endl;
            cout << "The Ticket Id: " << arr[0] << endl;
            cout << "The Ticket From: " << str[0] << endl;
            cout << "To: " << str[1] << endl;
            cout << "Date to start the flight: " << str[2] << endl;
            cout << "Date to return the flight: " << str[3] << endl;
            cout << "The price of flight: " << arr[1] << endl;
            cout << "The Visa-Country requirement of flight: " << (arr[2]==1?"Needed":"No Need") << endl;
            cout << "The Covid-19 requirement of flight: " << (arr[3]==1?"Needed":"No Need")  << endl;
            cout << "--------------------------------------------" << endl;
            break;
            }
}
    user_data.clear();
    user_data.seekg(0,ios::beg);
}
user_data.close();
fileoutput.close();
cout << "\a\n1-Return to Dashboard\n2-Exit\nEnter the Number : " << endl;
int x;
cin >> x;
if (x == 1)
    {
        wait_and_clear
        customer::customer_dashboard();
    }
    else
    {
        exit(1);
    }

}
