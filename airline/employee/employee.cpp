#include "employee.h"

using namespace std;
employee::employee() {}
void employee::edit_access_id(int i)
{
    if(id!=i)
    {
        id=i;
        employee::update_employee(employee::give_access_id());
    }
}
void employee::edit_access_job(string str)
{
    if(job!=str)
    {
        job=str;
        employee::update_employee(employee::give_access_id());
    }
}
void employee::edit_access_name(string _name)
{
    if(name!=_name)
    {
        name=_name;
        employee::update_employee(employee::give_access_id());
    }
}
void employee::edit_access_DoJ(string str_new)
{
    if(DoJ!=str_new)
    {
        DoJ=str_new;
        employee::update_employee(employee::give_access_id());
    }
}
void employee::edit_access_Salary(float say)
{
    if(Salary!=say)
    {
        Salary=say;
        employee::update_employee(employee::give_access_id());
    }
}

employee::employee(int _Id,string _name,string _Job,float _Salary,string _DoJ)
{
    employee::id = _Id;
    employee::name = _name;
    employee::job = _Job;
    employee::Salary = _Salary;
    employee::DoJ = _DoJ;
    if(!(employee::search_employee(_Id)))
    {
        if(id!=0)
        {
            employee::save_employee();
        }
    }
}
int employee::add_employee()
{
    int a;
    float b;
    string arr[3];
    cout << "Enter Employee Id " << endl;
    cin >> a;
    if(!(employee::search_employee(a)))
    {
        cout << "Enter Employee Name " << endl;
        cin >> arr[0];
        cout << "Enter Employee DoJ " << endl;
        cin >> arr[2];
        cout << "Our Salary List :" << endl;
        cout << "Driver Job -> 30000" << endl;
        cout << "Repairman Job -> 10000" << endl;
        cout << "Host Job -> 50000" << endl;
        cout << "Admin Who Only Can Add Employee And Increase thier Salary" << endl;
        cout << "Enter Employee Job " << endl;
        cin >> arr[1];
        cout << "Enter Employee Salary " << endl;
        cin >> b;
        ofstream temo("employee.txt",ios::app);
        temo << a << " " <<  arr[0] << " ";
        temo << arr[1] << " " <<  b << " " ;
        temo << arr[2] << endl;
        temo.close();
        return 1;
    }
    else
    {
        cout << "Check your Entered ID !! \n" ;
        return 0;
    }
}
int employee::edit_employee()
{
    float b;
    string arr;
    cout << "Enter Id Of the Employee :  " << endl;
    int a;
    cin >> a ;
    if(employee::search_employee(a))
    {
        cout << "Enter Which Option You Want to Edit Of Your Employee ? " << endl;
        cout << " \n0-Id\n1-Name\n2-DoJ3-Job\n4-Salary" << endl;
        cin >> a;
        if(a == 0)
        {
            cout << " Enter New Id :  " << endl;
            cin >>  a;
            employee::edit_access_id(a);
            return 1 ;
        }
        else if( a == 1 )
        {
            cout << " Enter New Name :  " << endl;
            cin >>  arr;
            employee::edit_access_name(arr);
            return 1 ;

        }
        else if( a == 2 )
        {
            cout << " Enter New DoJ :  " << endl;
            cin >>  arr;
            employee::edit_access_DoJ(arr);
            return 1 ;
        }
        else if (a == 3 )
        {
            cout << " Enter New Job :  " << endl;
            cin >>  arr;
            employee::edit_access_job(arr);
            return 1 ;
        }
        else if (a == 4 )
        {
            cout << " Enter New Salary :  " << endl;
            cin >>  b;
            employee::edit_access_Salary(b);
            return 1 ;
        }
        else
        {
            cout << "\n Check Your Input !! " <<endl;
            delay
            return 0;
        }
    }

}

int employee::give_access_id()
{
    return employee::id;
}
string employee::give_access_name()
{
    return employee::name;
}
string employee::give_access_Job()
{
    return employee::job;
}
float employee::give_access_Salary()
{
    return employee::Salary;
}
string employee::give_access_DoJ()
{
    return employee::DoJ;
}

void employee::save_employee()
{
    ofstream finput("employee.txt",ios::app);
    finput << give_access_id() << " " <<  give_access_name() <<" ";
    finput << give_access_Job() << " " <<  give_access_Salary() << " ";
    finput <<  give_access_DoJ() <<endl;
    finput.close();
}

int employee::delete_employee(int id)
{
    bool found=false;
    int a;
    float b;
    string arr[3];
    ifstream f7("employee.txt");
    ofstream f8("employee_new.txt");
    while (f7 >> a >> arr[0] >> arr[1] >> b>> arr[2] )
    {
        if (id != a)
        {
            f8 << a << " " << arr[0] << " ";
            f8 << arr[1] << " " << b << " ";
            f8 << arr[2] << endl;
        }
        if(id == a )
        {
            found =true;
        }
    }
    f8.close();
    f7.close();
    if(found != true )
    {
        return 0;
    }
    ifstream f1("employee_new.txt");
    ofstream f2("employee.txt");
    while (f1 >> a >> arr[0] >> arr[1] >> b>> arr[2])
    {
        f2 << a << " " << arr[0] << " ";
        f2 << arr[1] << " " << b << " ";
        f2 << arr[2] << endl;
    }
    f1.close();
    f2.close();
    return 1;
}
int employee::search_employee(int id)
{
    ifstream f3("employee.txt");
    int a;
    float b;
    string arr[3];
    while (f3 >> a >> arr[0] >> arr[1] >> b>> arr[2] )
    {
        if (id == a)
        {
            f3.close();
            return 1;
        }
    }
    f3.close();
    return 0;
}
employee extract_employee(int id)
{
    ifstream fg("employee.txt");
    int a;
    float b;
    string arr[3];
    while (fg >> a >> arr[0] >> arr[1] >> b>> arr[2])
    {
        if (a== id)
        {
            employee emp1(0,"","",0,"");
            emp1.edit_access_id(a);
            emp1.edit_access_name(arr[0]);
            emp1.edit_access_job(arr[1]);
            emp1.edit_access_Salary(b);
            emp1.edit_access_DoJ(arr[2]);
            fg.close();
            return emp1;
        }
    }
    fg.close();
}

void employee::update_employee(int id__)
{
    ifstream fin("employee.txt");
    ofstream fout("employee_new.txt");
    int a;
    float b;
    string arr[3];
    while (fin >> a >> arr[0] >> arr[1] >> b>> arr[2] )
    {
        if (   a == id__)
        {
            fout << give_access_id() << " " <<  give_access_name() <<" ";
            fout << give_access_Job() << " " <<  give_access_Salary() <<" ";
            fout <<  give_access_DoJ() <<endl;
        }
        else
        {
            fout << a << " " << arr[0] << " ";
            fout << arr[1] << " " << b << " ";
            fout << arr[2] << endl;
        }
    }
    fin.close();
    fout.close();
    ifstream f1("employee_new.txt");
    ofstream f2("employee.txt");
    while (f1 >> a >> arr[0] >> arr[1] >> b>> arr[2] )
    {
        fout << a << " " << arr[0] << " ";
        fout << arr[1] << " " << b << " ";
        fout << arr[2] << endl;
    }
    f1.close();
    f2.close();
    remove("employee_new.txt");
}

int employee::add_duty()
{
    wait_and_clear
    cout << "Ticket Id : " << endl;
    int re;
    cin >> re;
    tickets t1;
    if(t1.search_id(re))
    {
        cout << "Employee Id : " << endl;
        int z;
        cin >> z;
        if(employee::search_employee(z))
        {
            ofstream f70("employee_duty.txt",ios::app);
            f70 << re << " " << z << endl;
            f70.close();
            return 1;
        }
        return 0;
    }
    return 0;
}
