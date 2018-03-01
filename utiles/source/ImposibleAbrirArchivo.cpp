#include <utiles/include/ImposibleAbrirArchivo.h>

using namespace herramientas::utiles::excepciones;

ImposibleAbrirArchivo::ImposibleAbrirArchivo(std::string archivo) : Excepcion("no se pudo abrir '" + archivo + "'.")
{
}

ImposibleAbrirArchivo::~ImposibleAbrirArchivo()
{
}
