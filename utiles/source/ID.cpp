#include <utiles/include/ID.h>

using namespace herramientas::utiles;

// CONSTRUCTORES

ID::ID()
{
}

ID::ID(unsigned long long int id) : id(id)
{
}

ID::~ID()
{
}

// METODOS

unsigned long long int ID::numero()
{
	return this->id;
}

ID * ID::copia()
{
    return new ID(this->id);
}

std::string ID::string()
{
	return std::to_string(this->id);
}

bool ID::comparador(ID * a, ID * b)
{
    return a->numero() < b->numero();
}
