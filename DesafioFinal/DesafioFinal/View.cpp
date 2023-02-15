#include <iostream>
#include < conio.h >
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

		opcion = _getch();
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
		mostrarTexto(cotizacion->imprimir());
	}

	pie();

	do
	{
		regreso = _getch();
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
	mostrarTexto("Presiona 3 para volver al menú principal");
	mostrarTexto("-----------------------------------------------------------------------");
}

void View::realizarCotizacion()
{
	bool opcionValida = false;
	char opcion = '0', prenda = '0', manga = '0', cuello = '0', tipoPantalon = '0', calidad = '0';
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

		prenda = _getch();

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

				manga = _getch();

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

				cuello = _getch();

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

				tipoPantalon = _getch();;

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
			break;
		}
	} while (!opcionValida);

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

		calidad = _getch();

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
		}
		else
			opcionValida = true;


	} while (!opcionValida);

	/*---------------------Precio------------------------------*/
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
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			opcionValida = false;
			clear();
			encabezado("COTIZAR");
			pie();
			mostrarTexto("Valor no válido. Asegurése que sea un valor numérico");
			std::cin.get();
		}

	} while (!opcionValida);

	/*---------------------Unidades------------------------------*/
	opcionValida = false;
	int stock;

	do
	{
		stock = presenter->getStock(prenda, manga, cuello, tipoPantalon, calidad);
		clear();
		encabezado("COTIZAR");
		pie();
		mostrarTexto("\nINFORMACIÓN:");
		mostrarTexto(std::string("EXISTE ").append(std::to_string(stock).append(" CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA\n")));
		mostrarTexto("PASO 5: Ingrese la cantidad de unidades a cotizar:");
		mostrarTexto("-----------------------------------------------------------------------");

		std::cin >> unidades;

		if (std::cin.good())
		{
			if (unidades == 3)
				menuPrincipal();

			if (unidades > stock)
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				opcionValida = false;
				clear();
				encabezado("COTIZAR");
				pie();
				mostrarTexto("Valor no válido. No hay suficiente stock");
				std::cin.get();
			}

			else
				opcionValida = true;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			opcionValida = false;
			clear();
			encabezado("COTIZAR");
			pie();
			mostrarTexto("Valor no válido. Asegurése que sea un valor numérico");
			std::cin.get();
		}


	} while (!opcionValida);


	/*--------------------Resultado-----------------------------*/

	presenter->realizarCotizacion(prenda, manga, cuello, tipoPantalon, calidad, unidades, precio);

	clear();
	encabezado("COTIZAR");
	pie();
	mostrarTexto(presenter->getTienda()->getCotizaciones()->back()->imprimir());
	pie();

	do
	{
		opcion = _getch();
	} while (opcion != '3');

	menuPrincipal();
}