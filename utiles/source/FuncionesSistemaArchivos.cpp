#include <utiles/include/FuncionesSistemaArchivos.h>

// stl
#include <algorithm>
#include <sstream>

using namespace herramientas::utiles;

FuncionesSistemaArchivos::FuncionesSistemaArchivos()
{
}

FuncionesSistemaArchivos::~FuncionesSistemaArchivos()
{
}

bool FuncionesSistemaArchivos::escribir(std::string path, std::vector<unsigned char> contenido)
{
	// TO DO
	return false;
}

bool FuncionesSistemaArchivos::leer(std::string path, std::vector<unsigned char>& contenido)
{
	// TO DO
	return false;
}

bool FuncionesSistemaArchivos::eliminar(std::string path)
{
    if (0 == std::remove(path.c_str()))
    {
        return true;
    }
    return false;
}


