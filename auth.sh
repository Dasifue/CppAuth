#!/bin/sh

g++ -o main main.cpp src/user.cpp src/utils.cpp database/db.cpp -lpqxx -lpq -lssl -lcrypto

exec ./main