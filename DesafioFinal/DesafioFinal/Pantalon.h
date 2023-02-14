#ifndef PANTALON_H
#define PANTALON_H

#include <iostream>
#include "Prenda.h"
#include "Enums.h"

class Pantalon : public Prenda
{
private:
	TipoPantalon tipoPantalon;
public:
	Pantalon(TipoCalidad calidad, float precio, int stock, TipoPantalon tipoPantalon);
	TipoPrenda getTipoPrenda();
	std::string getNombrePrenda();
	TipoPantalon getTipoPantalon();
};

#endif // !PANTALON_H

