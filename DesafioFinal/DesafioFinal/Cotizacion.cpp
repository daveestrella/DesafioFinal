#include "Cotizacion.h"
#include "Enums.h"
#include "Camisa.h"
#include "Pantalon.h"


float Cotizacion::Cotizar()
{
	float precioUnitario = prenda->getPrecio();
	total = precioUnitario * unidades;
	if (prenda->getTipoPrenda() == TipoPrenda::Camisa)
	{
		Camisa* camisa = dynamic_cast<Camisa*>(prenda.get());

		if (camisa->getTipoManga() == TipoManga::Corta)
			total = total * 0.9;
		if (camisa->getTipoCuello() == TipoCuello::Mao)
			total = total * 1.03;

	}
	else
	{
		Pantalon* pantalon = dynamic_cast<Pantalon*>(prenda.get());

		if (pantalon->getTipoPantalon() == TipoPantalon::Chupin)
			total = total * 0.88;
	}

	if (prenda->getCalidad() == TipoCalidad::Premium)
		total = total * 1.3;

	return total;
}

