#include "Prenda.h"
#include "Enums.h"

Prenda::Prenda(TipoCalidad calidad, float precio, int stock)
{
	this->calidad = calidad;
	this->precio = precio;
	this->stock = stock;
}

TipoCalidad Prenda::getCalidad()
{
	return this->calidad;
}

float Prenda::getPrecio()
{
	return this->precio;
}

int Prenda::getStock()
{
	return this->stock;
}