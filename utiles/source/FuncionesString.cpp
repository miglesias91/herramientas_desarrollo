#include <utiles/include/FuncionesString.h>

// stl
#include <algorithm>
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

unsigned int FuncionesString::eliminarOcurrencias(std::string & string_a_modificar, std::string ocurrencia_a_eliminar)
{
    return reemplazarOcurrencias(string_a_modificar, ocurrencia_a_eliminar, "");
}

bool FuncionesString::todoMinuscula(std::string & string_a_modificar)
{
    std::transform(string_a_modificar.begin(), string_a_modificar.end(), string_a_modificar.begin(), ::tolower);
    return true;
}

unsigned int FuncionesString::eliminarSignosYPuntuacion(std::string & string_a_modificar)
{
    std::vector<std::string> signos_y_puntuacion = { "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", ":", ";", "<", "=", ">", "?", "[", "\\", "]", "^", "_", "`", "{", "|", "}", "~" };

    unsigned int cantidad_de_signos_y_puntuaciones_eliminados = 0;
    for (std::vector<std::string>::iterator it_signo = signos_y_puntuacion.begin(); it_signo != signos_y_puntuacion.end(); it_signo++)
    {
        cantidad_de_signos_y_puntuaciones_eliminados += FuncionesString::reemplazarOcurrencias(string_a_modificar, (*it_signo), " ");
    }

    FuncionesString::eliminarEspaciosRedundantes(string_a_modificar);

    return cantidad_de_signos_y_puntuaciones_eliminados;
}

unsigned int FuncionesString::eliminarCaracteresDeControl(std::string & string_a_modificar)
{
    std::vector<std::string> caracteres_de_control = { u8"\n", u8"\t", u8"\r", u8"\a" };

    unsigned int cantidad_de_caracteres_de_control_reemplazados = 0;
    for (std::vector<std::string>::iterator it_caracter_de_control = caracteres_de_control.begin(); it_caracter_de_control != caracteres_de_control.end(); it_caracter_de_control++)
    {
        cantidad_de_caracteres_de_control_reemplazados += herramientas::utiles::FuncionesString::reemplazarOcurrencias(string_a_modificar, (*it_caracter_de_control), " ");
    }

    return cantidad_de_caracteres_de_control_reemplazados;
}

unsigned int FuncionesString::eliminarEspaciosRedundantes(std::string & string_a_modificar)
{
    unsigned int cantidad_de_espacios_redundantes_eliminados = 0;
    for (std::string::iterator it = string_a_modificar.begin(); it != string_a_modificar.end(); it++)
    {
        if (' ' == *it)
        {
            std::string::iterator it_aux = it + 1;
            unsigned int cantidad_de_espacios_a_borrar = 0;
            while (string_a_modificar.end() != it_aux && ' ' == *it_aux)
            {
                cantidad_de_espacios_a_borrar++;
                it_aux++;
            }

            string_a_modificar.erase(it, it + cantidad_de_espacios_a_borrar);
            cantidad_de_espacios_redundantes_eliminados += cantidad_de_espacios_a_borrar;
        }
    }


    return cantidad_de_espacios_redundantes_eliminados;
}
