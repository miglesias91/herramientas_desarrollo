#include <utiles/include/FuncionesString.h>

// stl
#include <sstream>

using namespace herramientas::utiles;

FuncionesString::FuncionesString()
{
}

FuncionesString::~FuncionesString()
{
}

std::vector<std::string> FuncionesString::separar(std::string string_a_separar, std::string separador)
{
    std::stringstream string_stream(string_a_separar);
    std::string token;

    std::vector<std::string> tokens;
    while (std::getline(string_stream, token, separador.c_str()[0]))
    {
        tokens.push_back(token);
    }

    return tokens;
}

unsigned int FuncionesString::reemplazarOcurrencias(std::string & string_a_modificar, std::string ocurrencia_a_modificar, std::string reemplazo)
{
    unsigned int cantidad_ocurrencias_reemplazadas = 0;

    for (size_t posicion_ocurrencia = 0; ; posicion_ocurrencia += ocurrencia_a_modificar.length())
    {
        posicion_ocurrencia = string_a_modificar.find(ocurrencia_a_modificar, posicion_ocurrencia);

        if (std::string::npos == posicion_ocurrencia)
        {
            break;
        }

        string_a_modificar.replace(posicion_ocurrencia, ocurrencia_a_modificar.size(), reemplazo);

        cantidad_ocurrencias_reemplazadas++;
    }

    return cantidad_ocurrencias_reemplazadas;
}
