#include <iostream>
#include <pqxx/pqxx>

#include "../headers/db.h"


Database::Database(
    const std::string dbname,
    const std::string user,
    const std::string password,
    const std::string hostaddr,
    const std::string port
) : cx("dbname=" + dbname + " user=" + user + " password=" + password + " hostaddr=" + hostaddr + " port=" + port) {}

pqxx::result Database::exec(const std::string& query) {
    pqxx::work tx(cx);
    pqxx::result r = tx.exec(query);
    tx.commit();
    return r;
}