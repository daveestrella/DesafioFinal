#include <string>
#include <iomanip>
#include <sstream>
#include "Cotizacion.h"
#include "Enums.h"
#include "Camisa.h"
#include "Pantalon.h"

Cotizacion::Cotizacion(std::string id, std::string fecha, Vendedor* vendedor, Prenda* prenda, int unidades)
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
			total = total * 0.90f;
		if (camisa->getTipoCuello() == TipoCuello::Mao)
			total = total * 1.03f;

	}
	else
	{
		Pantalon* pantalon = dynamic_cast<Pantalon*>(prenda);

		if (pantalon->getTipoPantalon() == TipoPantalon::Chupin)
			total = total * 0.88f;
	}

	if (prenda->getCalidad() == TipoCalidad::Premium)
		total = total * 1.30f;
}

std::string Cotizacion::imprimir()
{
	std::string cadena = "";

	std::stringstream precio,tot;
	precio << std::fixed << std::setprecision(2) << prenda->getPrecio();
	tot << std::fixed << std::setprecision(2) << total;

	cadena.append(std::string("Número de Identificación: ").append(id).append("\n"));
	cadena.append(std::string("Fecha y Hora de la cotización: ").append(fecha).append("\n"));
	cadena.append(std::string("Código del vendedor: ").append(vendedor->getCodigo()).append("\n"));
	cadena.append(std::string("Prenda cotizada: ").append(prenda->getNombrePrenda()).append("\n"));
	cadena.append(std::string("Precio unitario: $").append(precio.str()).append("\n"));
	cadena.append(std::string("Cantidad de unidades cotizadas: ").append(std::to_string(unidades)).append("\n"));
	cadena.append(std::string("Precio Final: $").append(tot.str()).append("\n"));

	return cadena;
}

