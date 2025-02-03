#ifndef user_h
#define user_h

#include <iostream>
#include <string>

#include "db.h"

using namespace std;

class User {
    private:
        int id;
        string username;
        string email;
        string password;
    
    public:
        User(
            const string username,
            const string email,
            const string password
        );

        User(
            const string username,
            const string email
        ): username(username), email(email) {};

        User(
            const int id,
            const string username,
            const string email,
            const string password
        );

        string getUsername() const {
            return username;
        }

        string getEmail() const {
            return email;
        }

        string getPassword() const {
            return password;
        }

        int getId() const {
            return id;
        }

        bool isValidPassword(const string& password) const;
        void setPassword(const string& password);

        void print() const {
            cout << "ID: " << id << endl;
            cout << "Username: " << username << endl;
            cout << "Email: " << email << endl;
            cout << "Password: " << password << endl;
        }
};


class UserManager {
    private:
        Database& db;
    public:
        UserManager(Database& _db): db(_db) {}

        User createUser(const std::string& username, const std::string& email, const std::string& password);
        User getUser(const int id);
        User getUserByUsername(const std::string& username);
        User getUserByEmail(const std::string& email);
        User authenticate(const std::string& username, const std::string& password);
        User authenticateByEmail(const std::string& email, const std::string& password);

        void createTable();
};

#endif // user_h