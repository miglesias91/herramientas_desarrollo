#include <utiles/include/JsonMalFormado.h>

using namespace herramientas::utiles::excepciones;

JsonMalFormado::JsonMalFormado(std::string mensaje) : Excepcion(mensaje)
{
}

JsonMalFormado::~JsonMalFormado()
{
}
