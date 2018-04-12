#include <utiles/include/FuncionesSistemaArchivos.h>

// stl
#include <algorithm>
#include <fstream>
#include <sstream>

// utiles
#include <utiles/include/ImposibleAbrirArchivo.h>

using namespace herramientas::utiles;

FuncionesSistemaArchivos::FuncionesSistemaArchivos()
{
}

FuncionesSistemaArchivos::~FuncionesSistemaArchivos()
{
}

bool FuncionesSistemaArchivos::escribir(const std::string & path, const std::string & contenido)
{
    std::ofstream archivo(path);

    if (false == archivo.good())
    {
        throw herramientas::utiles::excepciones::ImposibleAbrirArchivo(path);
    }

    archivo << contenido;

    return true;
}

bool FuncionesSistemaArchivos::leer(const std::string &  path, std::string & contenido)
{
    std::ifstream archivo(path);

    if (false == archivo.good())
    {
        throw herramientas::utiles::excepciones::ImposibleAbrirArchivo(path);
    }

    std::ostringstream sstream;
    sstream << archivo.rdbuf();
    contenido = sstream.str();

    return true;
}

bool FuncionesSistemaArchivos::eliminar(std::string path)
{
    if (0 == std::remove(path.c_str()))
    {
        return true;
    }
    return false;
}


