#pragma once

// utiles
#include <utiles/include/Excepcion.h>

namespace herramientas
{
namespace utiles
{
namespace excepciones
{

class JsonMalFormado : public Excepcion
{
public:
    JsonMalFormado(std::string mensaje = "");
    virtual ~JsonMalFormado();
};

};
};
};

