#ifndef TIENDA_H
#define TIENDA_H
#include <iostream>
#include <list>
#include "Vendedor.h"
#include "Prenda.h"

class Tienda
{
private:
	std::string nombre;
	std::string direccion;
	std::list<Vendedor> vendedores;
	std::list<Prenda> prendas;
};

#endif // !TIENDA_H

