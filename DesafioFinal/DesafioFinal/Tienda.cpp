#include "Tienda.h"

Tienda::Tienda(std::string nombre, std::string direccion)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->vendedores = new std::vector<std::unique_ptr<Vendedor>>();
	this->prendas = new std::vector<std::unique_ptr<Prenda>>();
	this->cotizaciones = new std::vector<std::unique_ptr<Cotizacion>>();
}

Tienda::~Tienda()
{
	delete vendedores;
	delete prendas;
	delete cotizaciones;
}

std::string Tienda::getNombre()
{
	return nombre;
}

std::string Tienda::getDireccion()
{
	return direccion;
}

void Tienda::contratarVendedor(std::unique_ptr<Vendedor> vendedor)
{
	vendedores->push_back(std::move(vendedor));
}

std::vector<std::unique_ptr<Vendedor>>* Tienda::getVendedores()
{
	return vendedores;
}

void Tienda::agregarInventario(std::unique_ptr<Prenda> prenda)
{
	prendas->push_back(std::move(prenda));
}

std::vector<std::unique_ptr<Prenda>>* Tienda::getPrendas()
{
	return prendas;
}

void Tienda::agregarCotizacion(std::unique_ptr<Cotizacion> cotizacion)
{
	cotizaciones->push_back(std::move(cotizacion));
}

std::vector<std::unique_ptr<Cotizacion>>* Tienda::getCotizaciones()
{
	return cotizaciones;
}