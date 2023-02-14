#include "Presenter.h"
#include "View.h"
#include "Tienda.h"
#include "Camisa.h"
#include "Pantalon.h"

Presenter::Presenter(View* view)
{
	this->view = view;
}

Presenter::~Presenter()
{
	delete tienda;
	delete vendedorEnTurno;
};

void Presenter::InicializarTienda()
{
	tienda = new Tienda("Zonkos","Diagon Alley - Londres");

	//Se contratan vendedores
	tienda->contratarVendedor(std::move(std::make_unique<Vendedor>("Juan", "Perez", "JP001")));
	tienda->contratarVendedor(std::make_unique<Vendedor>("Diana","Pinto", "DP002"));
	tienda->contratarVendedor(std::make_unique<Vendedor>("Maria","Del Barrio", "MD003"));

	vendedorEnTurno = tienda->getVendedores()->at(rand() % 2).get();

	/*---------------------------- - SE AGREGA INVENTARIO - ----------------------------------- -*/

	//Cuello Mao y Manga Corta
	tienda->agregarInventario(std::make_unique<Camisa>(TipoCalidad::Standard,100,100,TipoCuello::Mao,TipoManga::Corta)); //Estandar
	tienda->agregarInventario(std::make_unique<Camisa>(TipoCalidad::Premium,100,100,TipoCuello::Mao,TipoManga::Corta));//Premium

	//Cuello Comun y Manga Corta
	tienda->agregarInventario(std::make_unique<Camisa>(TipoCalidad::Standard,100,150,TipoCuello::Comun,TipoManga::Corta));//Estandar
	tienda->agregarInventario(std::make_unique<Camisa>(TipoCalidad::Premium,100,150,TipoCuello::Comun,TipoManga::Corta));//Premium

	//Cuello Mao y Manga larga
	tienda->agregarInventario(std::make_unique<Camisa>(TipoCalidad::Standard, 100, 75, TipoCuello::Mao, TipoManga::Larga));//Estandar
	tienda->agregarInventario(std::make_unique<Camisa>(TipoCalidad::Premium, 100, 75, TipoCuello::Mao, TipoManga::Larga));//Premium

	//Cuello Comun y Manga larga
	tienda->agregarInventario(std::make_unique<Camisa>(TipoCalidad::Standard, 100, 175, TipoCuello::Comun, TipoManga::Larga));//Estandar
	tienda->agregarInventario(std::make_unique<Camisa>(TipoCalidad::Premium, 100, 175, TipoCuello::Comun, TipoManga::Larga));//Premium

	//Pantalon Chupin
	tienda->agregarInventario(std::make_unique<Pantalon>(TipoCalidad::Standard, 100, 750,TipoPantalon::Chupin));//Estandar
	tienda->agregarInventario(std::make_unique<Pantalon>(TipoCalidad::Premium, 100, 750,TipoPantalon::Chupin));//Premium

	//Pantalon Comun
	tienda->agregarInventario(std::make_unique<Pantalon>(TipoCalidad::Standard, 100, 250, TipoPantalon::Comun));//Estandar
	tienda->agregarInventario(std::make_unique<Pantalon>(TipoCalidad::Premium, 100, 250, TipoPantalon::Comun));//Premium
}

Tienda* Presenter::getTienda()
{
	return tienda;
}

Vendedor* Presenter::getVendedorEnTurno()
{
	return vendedorEnTurno;
}