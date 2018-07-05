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

uint32_t IReferenciable::cantidadReferencias()
{
    return this->cantidad_referencias;
}

uint32_t IReferenciable::sumarReferencia()
{
    this->cantidad_referencias++;
    return this->cantidad_referencias;
}

uint32_t IReferenciable::restarReferencia()
{
    this->cantidad_referencias--;
    return this->cantidad_referencias;
}
