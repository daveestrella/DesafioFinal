#ifndef VENDEDOR_H
#define VENDEDOR_H
#include <iostream>

class Vendedor
{
private:
	std::string nombre;
	std::string apellido;
	std::string codigo;
public:
	Vendedor(std::string nombre, std::string apellido, std::string codigo);
	std::string getNombre();
	std::string getApellido();
	std::string getCodigo();
};

#endif // !VENDEDOR_H

