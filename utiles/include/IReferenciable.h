#pragma once

// types
#include <cstdint>

namespace herramientas
{
namespace utiles
{
class IReferenciable
{
public:
    IReferenciable();
    virtual ~IReferenciable();

    bool estaReferenciado();

    uint32_t cantidadReferencias();

    uint32_t sumarReferencia();

    uint32_t restarReferencia();

private:

    uint32_t cantidad_referencias;
};
};
};

