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
	std::string imprimirCotizacion(std::string codigo);
	std::string realizarCotizacion(char prenda, char manga, char cuello, char tipoPantalon, char calidad, int unidades, float precio);
	void pasarAEnum(char prenda, char manga, char cuello, char tipoPantalon, char calidad,
		TipoPrenda& tPrenda, TipoManga& tManga, TipoCuello& tCuello, TipoPantalon& tPantalon, TipoCalidad& tCalidad);
};
#endif //!PRESENTER_H
