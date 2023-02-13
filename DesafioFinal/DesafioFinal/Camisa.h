#ifndef CAMISA_H
#define CAMISA_H
#include <iostream>
#include "Prenda.h"
#include "Enums.h"

class Camisa : Prenda
{
private:
	TipoCuello cuello;
	TipoManga manga;
public:
	TipoPrenda getTipoPrenda();
	TipoCuello getTipoCuello();
	TipoManga getTipoManga();
};

#endif // !CAMISA_H

