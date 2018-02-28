#include <utiles/include/IReferenciable.h>

using namespace herramientas::utiles;

IReferenciable::IReferenciable() : cantidad_referencias(0)
{
}

IReferenciable::~IReferenciable()
{
}

bool IReferenciable::estaReferenciado()
{
    return false;
}

unsigned int IReferenciable::cantidadReferencias()
{
    return this->cantidad_referencias;
}

unsigned int IReferenciable::sumarReferencia()
{
    this->cantidad_referencias++;
    return this->cantidad_referencias;
}

unsigned int IReferenciable::restarReferencia()
{
    this->cantidad_referencias--;
    return this->cantidad_referencias;
}
