#pragma once

// aplicacion
#include <utiles/include/ID.h>

namespace herramientas
{
namespace utiles
{

class ID;

class GestorIDs
{
public:

	GestorIDs(unsigned long long int id_mas_alto = 0);
	virtual ~GestorIDs();

	// GETTERS

	ID* nuevoID();
	
	unsigned long long int getIdActual();

	// SETTERS

	void setIdActual(unsigned long long int id_mas_alto);

private:

	// 0 <= id_mas_alto < 18.446744.073709.551616
	unsigned long long int id_mas_alto;
};

};
};

