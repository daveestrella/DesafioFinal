#include <iostream>
#include <Windows.h>
#include <stdlib.h>
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
	std::string opcion;
	bool salir = false;

	do
	{
		clear();
		mostrarTexto("COTIZADOR EXPRESS - MENÚ PRINCIPAL");
		mostrarTexto("----------------------------------");
		mostrarTexto(presenter->getTienda()->getNombre().append(" | ").append(presenter->getTienda()->getDireccion()));
		std::cin.get();
		std::cin.get();
	} while (!salir);
}