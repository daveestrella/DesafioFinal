#include "Cotizacion.h"
#include "Enums.h"
#include "Camisa.h"
#include "Pantalon.h"


float Cotizacion::Cotizar()
{
	float precioUnitario = prenda.getPrecio();
	total = precioUnitario * unidades;
	if (prenda.getTipo() == TipoPrenda::Camisa)
	{
		Camisa camisa = prenda;
		if()
	}
	else
	{ }
}

