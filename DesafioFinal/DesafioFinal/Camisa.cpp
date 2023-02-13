#include <iostream>
#include "Camisa.h"

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