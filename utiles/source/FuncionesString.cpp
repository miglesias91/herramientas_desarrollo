#include <utiles/include/FuncionesString.h>

// stl
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iomanip>

using namespace herramientas::utiles;

FuncionesString::FuncionesString()
{
}

FuncionesString::~FuncionesString()
{
}

std::string FuncionesString::toString(const double_t & numero, const uint32_t & cantidad_de_decimales)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(cantidad_de_decimales) << numero;
    return stream.str();
}

std::string FuncionesString::unir(const std::vector<std::string> & strings_a_unir, const std::string & separador, const std::string & separador_final)
{
    if (0 == strings_a_unir.size()) {
        return "";
    }

    std::string strings_unidos = *strings_a_unir.begin();
    for (std::vector<std::string>::const_iterator it = (strings_a_unir.cbegin() + 1); it != strings_a_unir.cend(); it++) {
        strings_unidos += separador + *it;
    }

    return strings_unidos;
}

std::vector<std::string> FuncionesString::separar(const std::string & string_a_separar, const std::string & separador)
{
    std::stringstream string_stream(string_a_separar);
    std::string token;

    std::vector<std::string> tokens;
    while (std::getline(string_stream, token, separador.c_str()[0])) {
        tokens.push_back(token);
    }

    return tokens;
}

uint32_t FuncionesString::reemplazarOcurrencias(std::string & string_a_modificar, const std::string & ocurrencia_a_modificar, const std::string & reemplazo)
{
    uint32_t cantidad_ocurrencias_reemplazadas = 0;

    for (size_t posicion_ocurrencia = 0; ; posicion_ocurrencia)
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

uint32_t FuncionesString::eliminarOcurrencias(std::string & string_a_modificar, std::string ocurrencia_a_eliminar)
{
    return reemplazarOcurrencias(string_a_modificar, ocurrencia_a_eliminar, "");
}

bool FuncionesString::todoMinuscula(std::string & string_a_modificar)
{
    reemplazarOcurrencias(string_a_modificar, "Á", "á");
    reemplazarOcurrencias(string_a_modificar, "É", "é");
    reemplazarOcurrencias(string_a_modificar, "Í", "í");
    reemplazarOcurrencias(string_a_modificar, "Ó", "ó");
    reemplazarOcurrencias(string_a_modificar, "Ú", "ú");

    std::transform(string_a_modificar.begin(), string_a_modificar.end(), string_a_modificar.begin(), ::tolower);
    return true;
}

uint32_t FuncionesString::eliminarSignosYPuntuacion(std::string & string_a_modificar, const std::vector<std::string> & caracteres_a_mantener)
{
    std::vector<std::string> signos_y_puntuacion = { "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", ":", ";", "<", "=", ">", "?", "[", "\\", "]", "^", "_", "`", "{", "|", "}", "~" };
    std::vector<std::string> caracteres_a_mantener_ordenados = caracteres_a_mantener;

    if (caracteres_a_mantener.size()) {  // si hay caracters a sacar, entonces los saco.
        std::vector<std::string> signos_y_puntuacion_a_sacar = {};

        std::sort(signos_y_puntuacion.begin(), signos_y_puntuacion.end());
        std::sort(caracteres_a_mantener_ordenados.begin(), caracteres_a_mantener_ordenados.end());

        std::set_difference(signos_y_puntuacion.begin(), signos_y_puntuacion.end(), caracteres_a_mantener_ordenados.begin(), caracteres_a_mantener_ordenados.end(),
            std::inserter(signos_y_puntuacion_a_sacar, signos_y_puntuacion_a_sacar.begin()));
        signos_y_puntuacion = signos_y_puntuacion_a_sacar;
    }

    uint32_t cantidad_de_signos_y_puntuaciones_eliminados = 0;
    for (std::vector<std::string>::iterator it_signo = signos_y_puntuacion.begin(); it_signo != signos_y_puntuacion.end(); it_signo++)
    {
        cantidad_de_signos_y_puntuaciones_eliminados += FuncionesString::reemplazarOcurrencias(string_a_modificar, (*it_signo), " ");
    }

    FuncionesString::eliminarEspaciosRedundantes(string_a_modificar);

    return cantidad_de_signos_y_puntuaciones_eliminados;
}

uint32_t FuncionesString::eliminarCaracteresDeControl(std::string & string_a_modificar)
{
    std::vector<std::string> caracteres_de_control = { u8"\n", u8"\t", u8"\r", u8"\a" };

    uint32_t cantidad_de_caracteres_de_control_reemplazados = 0;
    for (std::vector<std::string>::iterator it_caracter_de_control = caracteres_de_control.begin(); it_caracter_de_control != caracteres_de_control.end(); it_caracter_de_control++)
    {
        cantidad_de_caracteres_de_control_reemplazados += herramientas::utiles::FuncionesString::reemplazarOcurrencias(string_a_modificar, (*it_caracter_de_control), " ");
    }

    return cantidad_de_caracteres_de_control_reemplazados;
}

uint32_t FuncionesString::eliminarEspaciosRedundantes(std::string & string_a_modificar)
{
    uint32_t cantidad_de_espacios_redundantes_eliminados = 0;
    for (std::string::iterator it = string_a_modificar.begin(); it != string_a_modificar.end(); it++)
    {
        if (' ' == *it)
        {
            std::string::iterator it_aux = it + 1;
            uint32_t cantidad_de_espacios_a_borrar = 0;
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

uint32_t FuncionesString::recortar(std::string * string_a_recortar, const std::string & caracteres_de_corte) {
    return recortar_derecha(string_a_recortar, caracteres_de_corte) + recortar_izquierda(string_a_recortar, caracteres_de_corte);
}

uint32_t FuncionesString::recortar_derecha(std::string * string_a_recortar, const std::string & caracteres_de_corte) {
    uint32_t largo_inicial = string_a_recortar->size();
    string_a_recortar->erase(0, string_a_recortar->find_first_not_of(caracteres_de_corte));
    return largo_inicial - string_a_recortar->size();
}

uint32_t FuncionesString::recortar_izquierda(std::string * string_a_recortar, const std::string & caracteres_de_corte) {
    uint32_t largo_inicial = string_a_recortar->size();
    string_a_recortar->erase(string_a_recortar->find_last_not_of(caracteres_de_corte) + 1);
    return largo_inicial - string_a_recortar->size();
}

bool FuncionesString::empiezaCon(const std::string & string_a_chequear, const std::string & string_a_buscar)
{
    return string_a_buscar.length() <= string_a_chequear.length() && std::equal(string_a_buscar.begin(), string_a_buscar.end(), string_a_chequear.begin());
}

uint32_t FuncionesString::eliminar_tildes(std::string * string_a_modificar) {
    uint32_t cantidad_de_tildes_reemplazadas = 0;
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "á", "a");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "é", "e");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "í", "i");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "ó", "o");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "ú", "u");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "ý", "y");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "Á", "a");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "É", "e");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "Í", "i");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "Ó", "o");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "Ú", "u");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, "Ý", "y");
    
    return cantidad_de_tildes_reemplazadas;
}

uint32_t FuncionesString::eliminar_tildes_utf8(std::string * string_a_modificar) {
    uint32_t cantidad_de_tildes_reemplazadas = 0;
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"á", "a");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"é", "e");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"í", "i");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"ó", "o");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"ú", "u");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"ý", "y");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"Á", "a");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"É", "e");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"Í", "i");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"Ó", "o");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"Ú", "u");
    cantidad_de_tildes_reemplazadas += reemplazarOcurrencias(*string_a_modificar, u8"Ý", "y");

    return cantidad_de_tildes_reemplazadas;
}
