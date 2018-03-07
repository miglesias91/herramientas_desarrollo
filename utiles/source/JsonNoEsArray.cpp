#include <utiles/include/JsonNoEsArray.h>

using namespace herramientas::utiles::excepciones;

JsonNoEsArray::JsonNoEsArray(std::string clave) : Excepcion("'" + clave + "' no es un array.")
{
}

JsonNoEsArray::~JsonNoEsArray()
{
}
