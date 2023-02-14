#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "Vendedor.h"
#include "Prenda.h"
#include "Cotizacion.h"

class Tienda
{
private:
	std::string nombre;
	std::string direccion;
	std::vector<std::unique_ptr<Vendedor>>* vendedores;
	std::vector<std::unique_ptr<Prenda>>* prendas;
	std::vector<std::unique_ptr<Cotizacion>>* cotizaciones;
public:
	Tienda(std::string nombre, std::string direccion);
	~Tienda();
	std::string getNombre();
	std::string getDireccion();
	void contratarVendedor(std::unique_ptr<Vendedor> vendedor);
	std::vector<std::unique_ptr<Vendedor>>* getVendedores();
	void agregarInventario(std::unique_ptr<Prenda> prenda);
	std::vector<std::unique_ptr<Prenda>>* getPrendas();
	void agregarCotizacion(std::unique_ptr<Cotizacion> cotizacion);
	std::vector<std::unique_ptr<Cotizacion>>* getCotizaciones();
};

#endif // !TIENDA_H

