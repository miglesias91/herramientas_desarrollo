#pragma once

// stl
#include <string>
#include <vector>

namespace herramientas
{
namespace utiles
{

class FuncionesString
{
public:
    FuncionesString();
    virtual ~FuncionesString();

    // parametro 'separador' tiene que ser un string de 1 SOLO CARACTER.
    static std::vector<std::string> separar(std::string string_a_separar, std::string separador = " ");

    static unsigned int reemplazarOcurrencias(std::string & string_a_modificar, std::string ocurrencia_a_reemplazar, std::string reemplazo);
};

};
};


