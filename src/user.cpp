#include "../headers/user.h"
#include "../headers/utils.h"

User::User(

    const string username,
    const string email,
    const string password
): username(username), email(email), password(password) {}


User::User(
    const int id,
    const string username,
    const string email,
    const string password
): id(id), username(username), email(email), password(password) {}


bool User::isValidPassword(const string& password) const {
    return this->password == hashPassword(password);
}

void User::setPassword(const string& password) {
    this->password = hashPassword(password);
}


User UserManager::createUser(const std::string& username, const std::string& email, const std::string& password) {
    User user(username, email);
    user.setPassword(password);

    db.exec("INSERT INTO c_user (username, email, password) VALUES ('" + user.getUsername() + "', '" + user.getEmail() + "', '" + user.getPassword() + "')");
    return user;
}

User UserManager::getUser(const int id) {
    pqxx::result r = db.exec("SELECT * FROM c_user WHERE id = " + std::to_string(id));
    if(r.size() == 0) {
        throw std::invalid_argument("User not found");
    }

    pqxx::result::const_iterator row = r.begin();
    return User(row[0].as<int>(), row[1].as<string>(), row[2].as<string>(), row[3].as<string>());
}

User UserManager::getUserByUsername(const std::string& username) {
    pqxx::result r = db.exec("SELECT * FROM c_user WHERE username = '" + username + "'");
    if(r.size() == 0) {
        throw std::invalid_argument("User not found");
    }

    pqxx::result::const_iterator row = r.begin();
    return User(row[0].as<int>(), row[1].as<string>(), row[2].as<string>(), row[3].as<string>());
}

User UserManager::getUserByEmail(const std::string& email) {
    pqxx::result r = db.exec("SELECT * FROM c_user WHERE email = '" + email + "'");
    if(r.size() == 0) {
        throw std::invalid_argument("User not found");
    }

    pqxx::result::const_iterator row = r.begin();
    return User(row[0].as<int>(), row[1].as<string>(), row[2].as<string>(), row[3].as<string>());
}


void UserManager::createTable() {
    db.exec("CREATE TABLE IF NOT EXISTS c_user (id SERIAL PRIMARY KEY, username VARCHAR(255) NOT NULL, email VARCHAR(255) NOT NULL, password VARCHAR(255) NOT NULL, CONSTRAINT unique_username UNIQUE (username), CONSTRAINT unique_email UNIQUE (email))");
}