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

    static std::string toString(double numero, unsigned int cantidad_de_decimales = 2);

    static std::string unir(std::vector<std::string> strings_a_unir, std::string separador = "");

    // parametro 'separador' tiene que ser un string de 1 SOLO CARACTER.
    static std::vector<std::string> separar(std::string string_a_separar, std::string separador = " ");

    static unsigned int reemplazarOcurrencias(std::string & string_a_modificar, std::string ocurrencia_a_reemplazar, std::string reemplazo);

    static unsigned int eliminarOcurrencias(std::string & string_a_modificar, std::string ocurrencia_a_eliminar);

    static bool todoMinuscula(std::string & string_a_modificar);

    static unsigned int eliminarSignosYPuntuacion(std::string & string_a_modificar);

    // reemplaza los caracteres de control "\n", "\t", "\r", "\a" por un espacio en blanco:
    static unsigned int eliminarCaracteresDeControl(std::string & string_a_modificar);

    // reemplaza 2 o mas espacios por 1 solo espacio.
    static unsigned int eliminarEspaciosRedundantes(std::string & string_a_modificar);

    static bool empiezaCon(const std::string & string_a_chequear, const std::string & string_a_buscar);
};

};
};


