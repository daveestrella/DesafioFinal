#ifndef VIEW_H
#define VIEW_H
#include <string>

class Presenter;
class Weapon;

class View
{
private:
	Presenter* presenter;
public:
	View();
	~View();
	void menuPrincipal();
	void opcion(const char opcion, bool salir);
	void historialCotizaciones();
	void realizarCotizacion();
	void mostrarTexto(std::string texto);
	void clear();
};
#endif //!VIEW_H

