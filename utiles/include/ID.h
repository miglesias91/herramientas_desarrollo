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
	ID(uint64_t id);
	virtual ~ID();

	uint64_t numero();

    ID * copia();

	std::string string();

    static bool comparador(ID* a, ID* b);

private:

	uint64_t id;

	friend class GestorIDs;
};

};
};

