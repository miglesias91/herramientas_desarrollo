#pragma once

// stl
#include <string>

// aplicacion
#include <utiles/include/GestorIDs.h>

namespace herramientas
{
namespace utiles
{

class GestorIDs;

class ID
{
public:

	ID();
	ID(unsigned long long int id);
	virtual ~ID();

	unsigned long long int numero();

    ID * copia();

	std::string string();

    static bool comparador(ID* a, ID* b);

private:

	unsigned long long int id;

	friend class GestorIDs;
};

};
};

