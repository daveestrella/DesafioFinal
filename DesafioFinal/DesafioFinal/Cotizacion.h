#ifndef COTIZACION_H
#define COTIZACION_H

#include "Vendedor.h"
#include "Prenda.h"

class Cotizacion
{
private:
	std::string id;
	std::string fecha;
	Vendedor* vendedor;
	Prenda* prenda;
	int unidades;
	float total;
public:
	Cotizacion(std::string id, std::string fecha, Vendedor* vendedor, Prenda* prenda, int unidades);
	std::string getCodigo();
	std::string getFecha();
	Vendedor* getVendedor();
	Prenda* getPrenda();
	int getUnidades();
	float getTotal();
	void Cotizar();
	std::string imprimir();
};

#endif // !COTIZACION_H