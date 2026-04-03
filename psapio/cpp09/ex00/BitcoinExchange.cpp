#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& o) : _db(o._db) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o) {
    if (this != &o) _db = o._db;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::getline(file, line); // skip header "date,exchange_rate"
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rateStr;
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
            _db[date] = std::strtof(rateStr.c_str(), NULL);
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    int y = std::atoi(date.substr(0,4).c_str());
    int m = std::atoi(date.substr(5,2).c_str());
    int d = std::atoi(date.substr(8,2).c_str());
    if (m < 1 || m > 12 || d < 1 || d > 31) return false;
    (void)y;
    return true;
}

float BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
    if (it == _db.end() || it->first != date) {
        if (it == _db.begin())
            throw std::runtime_error("Error: no data for date => " + date);
        --it; // fecha anterior más cercana
    }
    return it->second;
}

void BitcoinExchange::processInput(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        // Parsear "date | value"
        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, sep);
        std::string valStr = line.substr(sep + 3);

        // Validar fecha
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        // Validar valor
        char* end;
        double val = std::strtod(valStr.c_str(), &end);
        if (*end != '\0' || valStr.empty()) {
            std::cout << "Error: bad input => " << valStr << std::endl;
            continue;
        }
        if (val < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (val > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        // Buscar precio y calcular
        try {
            float rate = getRate(date);
            std::cout << date << " => " << val << " = " << val * rate << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}