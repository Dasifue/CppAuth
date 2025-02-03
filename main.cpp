#include <iostream>
#include <fstream>
#include <cstdlib>
#include <pqxx/pqxx>

#include "./headers/user.h"
#include "./headers/db.h"

using namespace std;


int main() {

    try {
        Database db(getenv("POSTGRES_DB"), getenv("POSTGRES_USER"), getenv("POSTGRES_PASSWORD"), getenv("DB_HOST"), getenv("DB_PORT"));
        UserManager userManager(db);
        userManager.createTable();


        try {
            userManager.createUser("user1", "user1@gmail.com", "123456");
        }
        catch (const exception &e) {
            cerr << e.what() << endl;
        }

        try {
            User user = userManager.authenticate("user1", "123456");
            cout << "User authenticated" << endl;
            user.print();
        }
        catch (const exception &e) {
            cerr << e.what() << endl;
        }
        
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}


// g++ -o main main.cpp src/user.cpp src/utils.cpp database/db.cpp -lpqxx -lpq -lssl -lcrypto