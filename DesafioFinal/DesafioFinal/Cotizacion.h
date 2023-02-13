#ifndef COTIZACION_H
#define COTIZACION_H
#include <iostream>
#include "Vendedor.h"
#include "Prenda.h"

class Cotizacion
{
private:
	int id;
	std::string fecha;
	Vendedor vendedor;
	Prenda prenda;
	int unidades;
	float total;
public:
	float Cotizar();
};

#endif // !COTIZACION_H