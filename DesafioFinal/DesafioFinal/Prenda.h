#ifndef PRENDA_H
#define PRENDA_H

#include <iostream>
#include "Enums.h"

class Prenda
{
protected:
	std::string calidad;
	float precio;
	int stock;
public:
	Prenda(std::string calidad, float precio, int stock);
	std::string getCalidad();
	float getPrecio();
	int getStock();
	virtual TipoPrenda getTipoPrenda() = 0;
};

#endif // !PRENDA_H
