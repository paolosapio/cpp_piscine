#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>      // setprecision, fixed

/* ************CONSTRUCTORES************** */

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& o) : _db(o._db)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o)
{
	if (this != &o) _db = o._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}


/* ************METODOS************** */


void BitcoinExchange::loadDatabase(const std::string& pathMameCSV)
{
	std::ifstream fileCSV(pathMameCSV.c_str());
	if (!fileCSV.is_open())
		throw std::runtime_error("Error: could not open database.");

	while(!fileCSV.eof())
	{
		std::string key;
		std::getline(fileCSV, key, ',');
		
		std::string value;
		getline(fileCSV, value, '\n');
		// std::cout << key <<  "is key\n";
		// std::cout << value <<  "is value\n";
		_db[key] = std::strtof(value.c_str(), NULL);
	}
		// std::cout << _db.size() << "size db\n";
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	// control calendario ok
	int m = std::atoi(date.substr(5,2).c_str());
	int d = std::atoi(date.substr(8,2).c_str());

	if (m < 1 || m > 12 || d < 1 || d > 31)
	{
		std::cout << "Fecha invalida\n";
		return (false);
	}


	// control tamaño n caracteres fecha
	if (date.size() != 10)
	{
		std::cout << "data invalida\n";
		return (false);
	}


	// control separadores fecha
	if (date[4] != '-' || date[7] != '-')
	{
		std::cout << "separadores fecha invalidos\n";
		return (false);
	}


	//cntrol fecha despues de invento bitcoin
	int y = std::atoi(date.substr(0,4).c_str());
	if (y <= 2008)
	{
		std::cout << "en este año no habia BITCOINS\n";
		return (false);
	}


	return (true);
}



float BitcoinExchange::getbitCoinValue(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
	if (it == _db.end() || it->first != date)
	{
		if (it == _db.begin())
			throw std::runtime_error("Error: no data for date => " + date);
		--it; // fecha anterior más cercana
	}
	return it->second;
}



bool Fill_KeyAndVal(std::ifstream &fileCSV, const std::string &strSeparador, std::string &key, std::string &value)
{
	std::string line;
	std::getline(fileCSV, line);
	size_t separadorPosition = line.find(strSeparador);
	if (separadorPosition == std::string::npos) // npos que no existe
	{
		std::cout << "ERROR: Invadlid separator\n";
		return (false);
	}

	key = line.substr(0, separadorPosition);
	value =  line.substr(separadorPosition + strSeparador.length());

	return (true);
}



bool BitcoinExchange::check_input(const std::string &date, const std::string &valStr) const
{
	// Validar fecha
	if (isValidDate(date) == false)
		return (false);

	// Validar valor
	char* end;
	double val = std::strtod(valStr.c_str(), &end);
	
	if (*end != '\0' || valStr.empty())
	{
		std::cout << "Error: bad input => " << valStr << "\n";
		return (false);
	}
	if (val < 0)
	{
		std::cout << "Error: not a positive number." << "\n";
		return (false);
	}
	if (val > 1000)
	{
		std::cout << "Error: too large a number." << "\n";
		return (false);
	}
	return (true);
}



void BitcoinExchange::processInput(const std::string& pathMameCSV) const
{
	std::ifstream fileCSV(pathMameCSV.c_str());
	if (!fileCSV.is_open())
		throw std::runtime_error("Error: could not open fileCSV.");

	std::string line;
	std::getline(fileCSV, line); // skip header

	std::string date;
	std::string value;

	while (!fileCSV.eof())
	{
		if (Fill_KeyAndVal(fileCSV, " | ", date, value) == false)
			continue ;

		if (check_input(date, value) == false)
			continue ;
		try
		{
			float bitCoinValue = getbitCoinValue(date);
			std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(1) << std::strtof(value.c_str(), NULL) * bitCoinValue << "\n";
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
