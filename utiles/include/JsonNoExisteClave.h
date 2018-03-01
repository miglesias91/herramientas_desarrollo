#pragma once

// utiles
#include <utiles/include/Excepcion.h>

namespace herramientas
{
namespace utiles
{
namespace excepciones
{

class JsonNoExisteClave : public Excepcion
{
public:
    JsonNoExisteClave(std::string clave = "");
    virtual ~JsonNoExisteClave();
};

};
};
};

