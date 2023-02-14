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
};

Tienda* Presenter::getTienda()
{
	return tienda;
}

Vendedor* Presenter::getVendedorEnTurno()
{
	return vendedorEnTurno;
}

void Presenter::pasarAEnum(char prenda, char manga, char cuello, char tipoPantalon, char calidad,
TipoPrenda& tPrenda, TipoManga& tManga, TipoCuello& tCuello, TipoPantalon& tPantalon, TipoCalidad& tCalidad)
{
	switch (prenda)
	{
	case '1':
		tPrenda = TipoPrenda::Camisa;
		break;
	case '2':
		tPrenda = TipoPrenda::Pantalon;
		break;
	default:
		break;
	}
	switch (manga)
	{
	case '1':
		tManga = TipoManga::Corta;
		break;
	case '2':
		tManga = TipoManga::Larga;
		break;
	default:
		break;
	}
	switch (cuello)
	{
	case '1':
		tCuello = TipoCuello::Comun;
		break;
	case '2':
		tCuello = TipoCuello::Mao;
		break;
	default:
		break;
	}
	switch (tipoPantalon)
	{
	case '1':
		tPantalon = TipoPantalon::Comun;
		break;
	case '2':
		tPantalon = TipoPantalon::Chupin;
		break;
	default:
		break;
	}
	switch (calidad)
	{
	case '1':
		tCalidad = TipoCalidad::Standard;
		break;
	case '2':
		tCalidad = TipoCalidad::Premium;
		break;
	default:
		break;
	}
}

int Presenter::getStock(char prenda, char manga, char cuello, char tipoPantalon, char calidad)
{
	TipoPrenda tPrenda;
	TipoManga tManga;
	TipoCuello tCuello;
	TipoPantalon tPantalon;
	TipoCalidad tCalidad;

	pasarAEnum(prenda, manga, cuello, tipoPantalon, calidad,
		tPrenda, tManga, tCuello, tPantalon, tCalidad);

	for (auto const& pre : *tienda->getPrendas())
	{
		if (tPrenda == TipoPrenda::Camisa)  //CAMISA
		{
			if (pre->getTipoPrenda() == tPrenda &&
				pre->getTipoManga() == tManga &&
				pre->getTipoCuello() == tCuello &&
				pre->getCalidad() == tCalidad)
				return pre->getStock();
		}
		else //PANTALON
		{
			if (pre->getTipoPrenda() == tPrenda &&
				pre->getTipoPantalon() == tPantalon &&
				pre->getCalidad() == tCalidad)
				return pre->getStock();
		}
	}
}

std::string Presenter::imprimirCotizacion(std::string codigo)
{
	std::string cadena = "";

	for (auto const& cot : *tienda->getCotizaciones())
	{
		if(cot->getId() == codigo)
		{
			cadena.append(std::string("Número de Identificación: ").append(cot->getId()).append("\n"));
			cadena.append(std::string("Fecha y Hora de la cotización: ").append(cot->getFecha()).append("\n"));
			cadena.append(std::string("Código del vendedor: ").append(cot->getVendedor()->getCodigo()).append("\n"));
			cadena.append(std::string("Prenda cotizada: ").append(cot->getPrenda()->getNombrePrenda()).append("\n"));
			cadena.append(std::string("Precio unitario: $").append(std::to_string(cot->getPrenda()->getPrecio())).append("\n"));
			cadena.append(std::string("Cantidad de unidades cotizadas: ").append(std::to_string(cot->getUnidades())).append("\n"));
			cadena.append(std::string("Precio Final: $").append(std::to_string(cot->getTotal())).append("\n"));
			break;
		}
	}

	return cadena;
}

std::string Presenter::realizarCotizacion(char prenda, char manga, char cuello, char tipoPantalon, char calidad, int unidades, float precio)
{
	TipoPrenda tPrenda;
	TipoManga tManga;
	TipoCuello tCuello;
	TipoPantalon tPantalon;
	TipoCalidad tCalidad;

	pasarAEnum(prenda, manga, cuello, tipoPantalon, calidad,
		tPrenda, tManga, tCuello, tPantalon, tCalidad);

	int codigo = stoi(tienda->getCotizaciones()->back()->getCodigo());
	codigo++;

	tienda->agregarCotizacion(std::make_unique<Cotizacion>());

}

void Presenter::InicializarTienda()
{
	tienda = new Tienda("Zonkos","Diagon Alley - Londres");

	//Se contratan vendedores
	tienda->contratarVendedor(std::make_unique<Vendedor>("Juan", "Perez", "JP001"));
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