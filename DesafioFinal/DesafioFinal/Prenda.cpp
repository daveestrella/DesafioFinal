#include <iostream>
#include "Prenda.h"

Prenda::Prenda(std::string calidad, float precio, int stock)
{
	this->calidad = calidad;
	this->precio = precio;
	this->stock = stock;
}

std::string Prenda::getCalidad()
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