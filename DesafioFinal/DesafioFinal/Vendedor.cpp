#include "Vendedor.h"

Vendedor::Vendedor(std::string nombre, std::string apellido, std::string codigo)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->codigo = codigo;
}

std::string Vendedor::getNombre()
{
	return nombre;
}

std::string Vendedor::getApellido()
{
	return apellido;
}

std::string Vendedor::getCodigo()
{
	return codigo;
}