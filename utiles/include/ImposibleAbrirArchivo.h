#pragma once

// utiles
#include <utiles/include/Excepcion.h>

namespace herramientas
{
namespace utiles
{
namespace excepciones
{

class ImposibleAbrirArchivo : public Excepcion
{
public:
    ImposibleAbrirArchivo(std::string archivo = "");
    virtual ~ImposibleAbrirArchivo();
};

};
};
};

