FROM ubuntu:latest

WORKDIR /app

RUN apt-get update && apt-get install -y \
    g++ \
    libpqxx-dev \
    libpq-dev \
    libssl-dev

COPY . /app

RUN chmod +x ./auth.sh
