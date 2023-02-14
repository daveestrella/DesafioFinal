#include <iostream>
#include "Camisa.h"


Camisa::Camisa(TipoCalidad calidad, float precio, int stock, TipoCuello cuello, TipoManga manga) : Prenda(calidad,precio,stock)
{
	this->cuello = cuello;
	this->manga = manga;
}

TipoPrenda Camisa::getTipoPrenda()
{
	return TipoPrenda::Camisa;
}

TipoCuello Camisa::getTipoCuello()
{
	return cuello;
}

TipoManga Camisa::getTipoManga()
{
	return manga;
}

std::string Camisa::getNombrePrenda()
{
	std::string nombre("Camisa - ");

	if (cuello == TipoCuello::Comun)
		nombre.append("Cuello Común - ");
	else
		nombre.append("Cuello Mao - ");

	if (manga == TipoManga::Corta)
		nombre.append("Manga Corta - ");
	else
		nombre.append("Manga Larga - ");

	if (calidad == TipoCalidad::Standard)
		nombre.append("Standard");
	else
		nombre.append("Premium");

	return nombre;
}