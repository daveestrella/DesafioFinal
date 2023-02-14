#include "Pantalon.h"


Pantalon::Pantalon(TipoCalidad calidad, float precio, int stock, TipoPantalon tipoPantalon) : Prenda(calidad, precio, stock)
{
	this->tipoPantalon = tipoPantalon;
}

TipoPrenda Pantalon::getTipoPrenda()
{
	return TipoPrenda::Pantalon;
}

TipoPantalon Pantalon::getTipoPantalon()
{
	return tipoPantalon;
}