#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include "View.h"
#include "Presenter.h"
#include "Vendedor.h"
#include "Tienda.h"

View::View()
{
	SetConsoleTitleW(L"Cotizador Express");
	setlocale(LC_ALL, "es_Es");
	presenter = new Presenter(this);

	presenter->InicializarTienda();
	menuPrincipal();
}

View::~View()
{
	delete presenter;
}

void View::mostrarTexto(const std::string texto)
{
	std::cout << texto << std::endl;
}

void View::clear()
{
	std::cout << "\x1B[2J\x1B[H";
};

void View::menuPrincipal()
{
	char opcion;
	bool salir = false;

	do
	{
		clear();
		encabezado("MENÚ PRINCIPAL");
		mostrarTexto("----------------------------------");
		mostrarTexto(presenter->getTienda()->getNombre().append(" | ").append(presenter->getTienda()->getDireccion()));
		mostrarTexto("----------------------------------");
		mostrarTexto(presenter->getVendedorEnTurno()->getNombre().append(" ").append(presenter->getVendedorEnTurno()->getApellido().append(" | ").append(presenter->getVendedorEnTurno()->getCodigo())));
		mostrarTexto("----------------------------------\n");
		mostrarTexto("SELECCIONE UNA OPCIÓN DEL MENÚ:\n");
		mostrarTexto("1) Historial de Cotizaciones");
		mostrarTexto("2) Realizar Cotización");
		mostrarTexto("3) Salir");
		mostrarTexto("");

		std::cin >> opcion;
		escogerOpcion(opcion, salir);

	} while (!salir);
}

void View::escogerOpcion(char opcion, bool& salir)
{
	clear();

	switch (opcion)
	{
	case '1':
		historialCotizaciones();
		break;
	case '2':
		realizarCotizacion();
		break;
	case '3':
		mostrarTexto("---------------------------------------------");
		mostrarTexto("Gracias por visitarnos. Vuelva pronto.");
		mostrarTexto("---------------------------------------------");
		std::cin.get();
		std::cin.get();
		salir = true;
		break;
	}
}

void View::historialCotizaciones()
{
	char regreso;
	clear();

	encabezado("HISTORIAL DE COTIZACIONES");
	pie();

	for (auto const& cotizacion : *presenter->getTienda()->getCotizaciones())
	{
		mostrarTexto(std::string("Número de Identificación: ").append(cotizacion->getId()));
		mostrarTexto(std::string("Fecha y Hora de la cotización: ").append(cotizacion->getFecha()));
		mostrarTexto(std::string("Código del vendedor: ").append(cotizacion->getVendedor()->getCodigo()));
		mostrarTexto(std::string("Prenda cotizada: ").append(cotizacion->getPrenda()->getNombrePrenda()));
		mostrarTexto(std::string("Precio unitario: $").append(std::to_string(cotizacion->getPrenda()->getPrecio())));
		mostrarTexto(std::string("Cantidad de unidades cotizadas: ").append(std::to_string(cotizacion->getUnidades())));
		mostrarTexto(std::string("Precio Final: $").append(std::to_string(cotizacion->getTotal())));
		mostrarTexto("\n\n");
	}

	pie();

	do
	{
		std::cin >> regreso;
	} while (regreso != '3');

	menuPrincipal();
}

void View::encabezado(std::string titulo)
{
	mostrarTexto(std::string("COTIZADOR EXPRESS - ").append(titulo));
}

void View::pie()
{
	mostrarTexto("-----------------------------------------------------------------------");
	mostrarTexto("Presiona 3 para volver al menú principal (Se abandona la cotizacion)");
	mostrarTexto("-----------------------------------------------------------------------");
}

void View::realizarCotizacion()
{
	bool opcionValida = false;
	char opcion,prenda, manga, cuello, tipoPantalon, calidad;
	int unidades;
	float precio;

	/*---------------------Tipo de Prenda-----------------------*/
	do
	{
		clear();
		encabezado("COTIZAR");
		pie();
		mostrarTexto("PASO 1: Selecciona la prenda a cotizar:");
		mostrarTexto("1) Camisa");
		mostrarTexto("2) Pantalón");
		mostrarTexto("-----------------------------------------------------------------------");

		std::cin >> prenda;

		switch (prenda)
		{
			
		case '1'://CAMISA
			do
			{
				clear();
				encabezado("COTIZAR");
				pie();
				mostrarTexto("PASO 2.a: Selecciona el tipo de manga:");
				mostrarTexto("1) Corta");
				mostrarTexto("2) Larga");
				mostrarTexto("-----------------------------------------------------------------------");

				std::cin >> manga;

				if (manga == '3')
					menuPrincipal();

				if (manga != '1' && manga != '2')
				{
					opcionValida = false;
					clear();
					encabezado("COTIZAR");
					pie();
					mostrarTexto("Opción no Válida. Vuelva a intentar");
					std::cin.get();
					std::cin.get();
				}
				else
					opcionValida = true;

			} while (!opcionValida);
			do
			{
				clear();
				encabezado("COTIZAR");
				pie();
				mostrarTexto("PASO 2.a: Selecciona el tipo de cuello:");
				mostrarTexto("1) Común");
				mostrarTexto("2) Mao");
				mostrarTexto("-----------------------------------------------------------------------");

				std::cin >> cuello;

				if (cuello == '3')
					menuPrincipal();

				if (cuello != '1' && cuello != '2')
				{
					opcionValida = false;
					clear();
					encabezado("COTIZAR");
					pie();
					mostrarTexto("Opción no Válida. Vuelva a intentar");
					std::cin.get();
					std::cin.get();
				}
				else
					opcionValida = true;
				
			} while (!opcionValida);
			break;
			
		case '2'://PANTALON
			do
			{
				clear();
				encabezado("COTIZAR");
				pie();
				mostrarTexto("PASO 2: Selecciona el tipo de pantalón:");
				mostrarTexto("1) Común");
				mostrarTexto("2) Chupín");
				mostrarTexto("-----------------------------------------------------------------------");

				std::cin >> tipoPantalon;

				if (tipoPantalon == '3')
					menuPrincipal();

				if (tipoPantalon != '1' && tipoPantalon != '2')
				{
					opcionValida = false;
					clear();
					encabezado("COTIZAR");
					pie();
					mostrarTexto("Opción no Válida. Vuelva a intentar");
					std::cin.get();
					std::cin.get();
				}
				else
					opcionValida = true;

			} while (!opcionValida);
			break;

		case '3': //SALIR
			menuPrincipal();
			break;

		default:
			opcionValida = false;
			clear();
			encabezado("COTIZAR");
			pie();
			mostrarTexto("Opción no Válida. Vuelva a intentar");
			std::cin.get();
			std::cin.get();
			break;
		}
	}while (!opcionValida);

	/*---------------------Calidad------------------------------*/
	opcionValida = false;

	do
	{
		clear();
		encabezado("COTIZAR");
		pie();
		mostrarTexto("PASO 3: Selecciona la calidad de la prenda:");
		mostrarTexto("1) Standard");
		mostrarTexto("2) Premium");
		mostrarTexto("-----------------------------------------------------------------------");

		std::cin >> calidad;

		if (calidad == '3')
			menuPrincipal();

		if (calidad != '1' && calidad != '2')
		{
			opcionValida = false;
			clear();
			encabezado("COTIZAR");
			pie();
			mostrarTexto("Opción no Válida. Vuelva a intentar");
			std::cin.get();
			std::cin.get();
		}
		else
			opcionValida = true;


	} while (!opcionValida);

	/*---------------------Calidad------------------------------*/
	opcionValida = false;

	do
	{
		clear();
		encabezado("COTIZAR");
		pie();
		mostrarTexto("PASO 4: Ingrese el precio unitario de la prenda a cotizar:");
		mostrarTexto("-----------------------------------------------------------------------");

		std::cin >> precio;

		if (std::cin.good())
		{
			if (precio == 3)
				menuPrincipal();

			opcionValida = true;
		}
		else
			opcionValida = false;


	} while (!opcionValida);

	/*---------------------Calidad------------------------------*/
	opcionValida = false;

	do
	{
		clear();
		encabezado("COTIZAR");
		pie();
		mostrarTexto("\nINFORMACIÓN:");
		mostrarTexto(std::string("EXISTE").append(std::to_string(presenter->getStock(prenda,manga,cuello,tipoPantalon,calidad)).append(" CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA\n")));
		mostrarTexto("PASO 5: Ingrese la cantidad de unidades a cotizar:");
		mostrarTexto("-----------------------------------------------------------------------");

		std::cin >> unidades;

		if (std::cin.good())
		{
			if (unidades == 3)
				menuPrincipal();

			opcionValida = true;
		}
		else
			opcionValida = false;


	} while (!opcionValida);

	std::string codigoCotizacion = presenter->realizarCotizacion(prenda,manga,cuello,tipoPantalon,calidad,unidades,precio);

	/*--------------------Resultado-----------------------------*/

	clear();
	encabezado("COTIZAR");
	pie();
	mostrarTexto(presenter->imprimirCotizacion(codigoCotizacion));
	pie();

	do
	{
		std::cin >> opcion;
	} while (opcion != '3');

	menuPrincipal();
}