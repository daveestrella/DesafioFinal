#ifndef PRENDA_H
#define PRENDA_H

#include <iostream>
#include "Enums.h"

class Prenda
{
protected:
	TipoCalidad calidad;
	float precio;
	int stock;
public:
	Prenda(TipoCalidad calidad, float precio, int stock) ;
	TipoCalidad getCalidad();
	float getPrecio();
	int getStock();
	virtual TipoPrenda getTipoPrenda() = 0;
	virtual std::string getNombrePrenda() = 0;
};

#endif // !PRENDA_H
