#ifndef PRESENTER_H
#define PRESENTER_H

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
};
#endif //!PRESENTER_H
