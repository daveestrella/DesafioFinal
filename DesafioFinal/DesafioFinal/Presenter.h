#ifndef PRESENTER_H
#define PRESENTER_H

#include <iostream>
#include "Enums.h"

class View;
class Tienda;
class Vendedor;

class Presenter
{
private:
	View* view = nullptr;
	Tienda* tienda = nullptr;
	Vendedor* vendedorEnTurno = nullptr;
public:
	Presenter(View* view);
	~Presenter();
	Tienda* getTienda();
	Vendedor* getVendedorEnTurno();
	void InicializarTienda();
	int getStock(char prenda, char manga, char cuello, char tipoPantalon, char calidad);
	void realizarCotizacion(char prenda, char manga, char cuello, char tipoPantalon, char calidad, int unidades, float precio);
};
#endif //!PRESENTER_H
