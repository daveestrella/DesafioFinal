#include "Cotizacion.h"
#include "Enums.h"
#include "Camisa.h"
#include "Pantalon.h"

Cotizacion::Cotizacion(std::string id, std::string fecha, Vendedor* vendedor, Prenda* prenda,int unidades)
{
	this->id = id;
	this->fecha = fecha;
	this->vendedor = vendedor;
	this->prenda = prenda;
	this->unidades = unidades;
	this->total = 0;
}

std::string Cotizacion::getCodigo()
{
	return id;
}

std::string Cotizacion::getFecha()
{
	return fecha;
}

Vendedor* Cotizacion::getVendedor()
{
	return vendedor;
}

Prenda* Cotizacion::getPrenda()
{
	return prenda;
}

int Cotizacion::getUnidades()
{
	return unidades;
}

float Cotizacion::getTotal()
{
	return total;
}


void Cotizacion::Cotizar()
{
	float precioUnitario = prenda->getPrecio();
	total = precioUnitario * unidades;
	if (prenda->getTipoPrenda() == TipoPrenda::Camisa)
	{
		Camisa* camisa = dynamic_cast<Camisa*>(prenda);

		if (camisa->getTipoManga() == TipoManga::Corta)
			total = total * 0.9;
		if (camisa->getTipoCuello() == TipoCuello::Mao)
			total = total * 1.03;

	}
	else
	{
		Pantalon* pantalon = dynamic_cast<Pantalon*>(prenda);

		if (pantalon->getTipoPantalon() == TipoPantalon::Chupin)
			total = total * 0.88;
	}

	if (prenda->getCalidad() == TipoCalidad::Premium)
		total = total * 1.3;
}

