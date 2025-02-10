//  Build a C++ Login System – Beginner Friendly! (Step-by-Step with File Handling)
//  Created by NEURAL & WIRES
//  C++ Project
/*
 
 Classes & Objects              Organized related functions together.
 File Handling (fstream)        Read & write user data to a file.
 Switch Cases                   Handle different menu options.
 getline() & cin.ignore()       Take full user input properly.
 Error Handling (if (!file))    Prevent crashes when files don’t open.
 
 */

#include<iostream>
#include<fstream> //This allows your program to read and write files.
using namespace std;

class temp {      //Think of a class like a blueprint for a machine.
    string userName, Email, password;               //These are storage containers (variables)
    string searchName, searchPass, searchEmail;     //These are used for searching when logging in or recovering a password.
    fstream file;                                   //This is a file handler → It opens, reads, writes, and closes the file.
    public:
    void login();
    void signUp();
    void forgot();
}obj;

int main() {
    char choice;
    cout << "\n1 - Login";
    cout << "\n2 - Sign-Up";
    cout << "\n3 - Forgot Password";
    cout << "\n4 - Exit";
    cout << "\n - Enter your Choice :: ";
    cin >> choice;
    
    switch(choice){
        case '1':
            cin.ignore();
            obj.login();
        break;
        case '2':
            cin.ignore();
            obj.signUp();
        break;
        case '3':
            cin.ignore(); // cin >> choice
            obj.forgot();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Invalid Selection...!" << endl;
        return 0;
    }
}

void temp :: signUp() {
    cout << "\nEnter Your User Name :: ";
    getline(cin, userName);
    cout << "Enter Your Email Address ::";
    getline(cin, Email);
    cout << "Enter Your Password ::";
    getline(cin, password);
    
    file.open("/Users/kevinomerkilic/Desktop/loginData.txt", ios::out | ios::app);
    if (!file) {
        cout <<"Error: Unable to open file!" << endl;
        return;
    }
    file << userName << "*" << Email << "*" << password << endl; //kevin*kevin@gmail.com*password123
    file.close();
}

void temp :: login() {
    cout << "-------------LOGIN-------------" << endl;
    cout << "Enter Your User Name :: ";
    getline(cin, searchName);
    cout << "Enter Your Password :: ";
    getline(cin, searchPass);
    
    file.open("/Users/kevinomerkilic/Desktop/loginData.txt", ios::out | ios::app);
    if (!file) {
        cout <<"Error: Unable to open file!" << endl;
        return;
    }
    
    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') &&
        getline(file, password, '\n')) {
        if (userName == searchName) {
            if (password == searchPass) {
                cout << "\nAccount Login Successful!" << endl;
                cout << "Username: " << userName << endl;
                cout << "Email: " << Email << endl;
                found =  true;
                break;
            } else {
                cout << "Incorrect Password!" << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "Account not found! " << endl;
    }
    
    file.close();
}

void temp :: forgot() {
    cout << "\nEnter Your UserName :: ";
        getline(cin, searchName);
        cout << "\nEnter Your Email Address :: ";
        getline(cin, searchEmail);
    
    file.open("/Users/kevinomerkilic/Desktop/loginData.txt", ios::in);
    if (!file) {
        cout << "Error: Unable to open file!" << endl;
        return;
    }
    
    bool found = false;
        while(getline(file, userName, '*') && getline(file, Email, '*') &&
            getline(file, password, '\n')) {
            if (userName == searchName && Email == searchEmail) {
                cout << "\nAccount Found!" << endl;
                cout << "Your Password: " << password << endl;
                found = true;
                break;
                
            }
        }
    
    if (!found) {
        cout << "\nAccount not found...!" << endl;
    }
    file.close();
}
