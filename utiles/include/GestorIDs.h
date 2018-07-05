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

	GestorIDs(uint64_t id_mas_alto = 1);
	virtual ~GestorIDs();

	// GETTERS

	ID* nuevoID();
	
	uint64_t getIdActual();

	// SETTERS

	void setIdActual(uint64_t id_mas_alto);

private:

	// 0 <= id_mas_alto < 18.446744.073709.551616
	uint64_t id_mas_alto;
};

};
};

