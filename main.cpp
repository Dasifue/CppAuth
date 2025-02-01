#include <iostream>
#include <pqxx/pqxx>

#include "./headers/user.h"
#include "./headers/db.h"

using namespace std;


int main() {
    try {
        Database db("postgres", "postgres", "123456", "127.0.0.1", "5432");
        UserManager userManager(db);
        userManager.createTable();


        userManager.createUser("user1", "user1@gmail.com", "123456");

        User user = userManager.getUserByUsername("user1");
        user.print();
        
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}


// g++ -o main main.cpp src/user.cpp src/utils.cpp database/db.cpp -lpqxx -lpq -lssl -lcrypto