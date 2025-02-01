#ifndef db_h
#define db_h

#include <iostream>
#include <pqxx/pqxx>

class Database {
    private:
        pqxx::connection cx;

    public:
        Database(
            const std::string dbname,
            const std::string user,
            const std::string password,
            const std::string hostaddr,
            const std::string port
        );

        pqxx::result exec(const std::string& query);
        
};

#endif // db_h