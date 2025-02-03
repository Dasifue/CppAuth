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