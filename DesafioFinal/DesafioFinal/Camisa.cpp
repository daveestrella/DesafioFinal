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