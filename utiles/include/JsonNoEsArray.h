#pragma once

// utiles
#include <utiles/include/Excepcion.h>

namespace herramientas
{
namespace utiles
{
namespace excepciones
{

class JsonNoEsArray : public Excepcion
{
public:
    JsonNoEsArray(std::string clave = "");
    virtual ~JsonNoEsArray();
};

};
};
};

