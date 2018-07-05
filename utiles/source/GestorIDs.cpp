#include <utiles/include/GestorIDs.h>

using namespace herramientas::utiles;

// CONSTRUCTORES

GestorIDs::GestorIDs(uint64_t id_mas_alto) : id_mas_alto(id_mas_alto)
{
}

GestorIDs::~GestorIDs()
{
}

// SETTERS

void GestorIDs::setIdActual(uint64_t id_mas_alto)
{
	GestorIDs::id_mas_alto = id_mas_alto;
}

// METODOS

ID * GestorIDs::nuevoID()
{
	ID* id_nuevo = new ID(id_mas_alto);
	id_mas_alto++;
	return id_nuevo;
}

uint64_t GestorIDs::getIdActual()
{
	return id_mas_alto;
}

