#ifndef CAMISA_H
#define CAMISA_H

#include "Prenda.h"
#include "Enums.h"

class Camisa : public Prenda
{
private:
	TipoCuello cuello;
	TipoManga manga;
public:
	Camisa(TipoCalidad calidad, float precio, int stock, TipoCuello cuello, TipoManga manga);
	TipoPrenda getTipoPrenda();
	std::string getNombrePrenda();
	TipoCuello getTipoCuello();
	TipoManga getTipoManga();
};

#endif // !CAMISA_H

