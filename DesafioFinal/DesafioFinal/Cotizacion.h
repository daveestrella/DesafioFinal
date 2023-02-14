#ifndef COTIZACION_H
#define COTIZACION_H

#include "Vendedor.h"
#include "Prenda.h"

class Cotizacion
{
private:
	int id;
	std::string fecha;
	Vendedor vendedor;
	std::unique_ptr<Prenda> prenda;
	int unidades;
	float total;
public:
	float Cotizar();
};

#endif // !COTIZACION_H