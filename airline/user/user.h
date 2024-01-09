// user.h
#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <string>
class user {
public:
    user(std::string _username, std::string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_);
    virtual ~user();
    class error_file_not_founded {};

    std::string give_access_username();
    std::string give_access_password();
    int give_access_access();
    int give_access_admin_access();
    int give_access_co_cert();
    int give_access_visa_cert();
    int give_access_balance();

    void edit_access_username(std::string _user);
    void edit_access_password(std::string password);
    void edit_access_access(int _access);
    void edit_access_admin_access(int _admin_access);
    void edit_access_co_cert(int _co_cert__);
    void edit_access_visa_cert(int _visa_cert_);
    int  edit_access_balance(int _balance_);

    void save_user_direct();
    void update_user_direct(std::string new_str);
    user extract_info_username(std::string username_);
    int delete_username(std::string username_);
    int print_info_username(std::string username_);
    int search_username(std::string username_);
    int print_user_operation(std::string username_);
    void save_user_operation(std::string username_, int id_, int value);
    int return_user_operation(std::string username_, int id_, int value);

private:
    std::string username;
    std::string password;
    int access;
    int admin_access;
    int co_cert;
    int visa_cert;
    int balance;
};

#endif // USER_H
