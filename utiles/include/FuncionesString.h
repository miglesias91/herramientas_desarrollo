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

    static std::string toString(const double_t & numero, const uint32_t & cantidad_de_decimales = 2);

    static std::string unir(const std::vector<std::string> & strings_a_unir, const std::string & separador = "", const std::string & separador_final = "");

    // parametro 'separador' tiene que ser un string de 1 SOLO CARACTER.
    static std::vector<std::string> separar(const std::string & string_a_separar, const std::string & separador = " ");

    static uint32_t reemplazarOcurrencias(std::string & string_a_modificar, const std::string & ocurrencia_a_reemplazar, const std::string & reemplazo);

    static uint32_t eliminarOcurrencias(std::string & string_a_modificar, std::string ocurrencia_a_eliminar);

    static bool todoMinuscula(std::string & string_a_modificar);

    static uint32_t eliminarSignosYPuntuacion(std::string & string_a_modificar, const std::vector<std::string> & caracteres_a_mantener = {});

    // reemplaza los caracteres de control "\n", "\t", "\r", "\a" por un espacio en blanco:
    static uint32_t eliminarCaracteresDeControl(std::string & string_a_modificar);

    // reemplaza 2 o mas espacios por 1 solo espacio.
    static uint32_t eliminarEspaciosRedundantes(std::string & string_a_modificar);

    static bool empiezaCon(const std::string & string_a_chequear, const std::string & string_a_buscar);

    // elimina las tildes del string.
    static uint32_t eliminar_tildes(std::string * string_a_modificar);

    // elimina las tildes del string en formato utf8.
    static uint32_t eliminar_tildes_utf8(std::string * string_a_modificar);
};

};
};


