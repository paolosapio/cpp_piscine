


// std::map es el contenedor ideal para ex00. GitHub Permite buscar la fecha más cercana usando lower_bound.



/* 
1. Cargar data.csv en un std::map<string, float>
2. Leer el archivo de input línea por línea
3. Para cada línea:
   a. Parsear fecha y valor
   b. Validar fecha (formato YYYY-MM-DD, valores reales)
   c. Validar valor (>0, <=1000)
   d. Buscar en el map la fecha igual o anterior más cercana
   e. Multiplicar valor × precio BTC
*/


/* 
⚠️ Errores comunes a manejar
CasoMensajeArchivo no abreError: could not open file.Formato incorrectoError: bad input => <línea>Número negativoError: not a positive number.Número > 1000Error: too large a number.

🔑 Clave: lower_bound
El truco central del ejercicio es usar map::lower_bound(date) para encontrar la fecha igual o posterior a la buscada, y luego retroceder un iterador (--it) para obtener la fecha igual o anterior más cercana.
*/


#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, float> _db;

	bool  isValidDate(const std::string& date) const;
	float getbitCoinValue(const std::string& date) const;
	bool check_input(const std::string &date, const std::string &value) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadDatabase(const std::string& filename); //
	void processInput(const std::string& filename) const;
};
