#include <utiles/include/JsonNoExisteClave.h>

using namespace herramientas::utiles::excepciones;

JsonNoExisteClave::JsonNoExisteClave(std::string clave) : Excepcion("No existe la clave '" + clave + "'.")
{
}

JsonNoExisteClave::~JsonNoExisteClave()
{
}
