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

std::string Pantalon::getNombrePrenda()
{
	std::string nombre("Pantal�n - ");

	if (tipoPantalon == TipoPantalon::Comun)
		nombre.append("Com�n - ");
	else
		nombre.append("Chup�n - ");

	if (calidad == TipoCalidad::Standard)
		nombre.append("Standard");
	else
		nombre.append("Premium");

	return nombre;
}