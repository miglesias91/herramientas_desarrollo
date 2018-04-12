#pragma once

// stl
#include <string>
#include <vector>

namespace herramientas
{
namespace utiles
{

class FuncionesSistemaArchivos
{
public:
    FuncionesSistemaArchivos();
    virtual ~FuncionesSistemaArchivos();

	// escribe un archivo en disco. devuelve true/false en caso de escribir correcta/incorrectamente.
	// - path: path del archivo (path = <dir/del/archivo/><nombre_archivo>.<extension>).
	// - contenido: tira de bytes a almacenar.
	static bool escribir(const std::string & path, const std::string & contenido);

	// lee un archivo en disco. devuelve true/false en caso de leer correcta/incorrectamente.
	// - path: path del archivo (path = <dir/del/archivo/><nombre_archivo>.<extension>).
	// - contenido: tira de bytes leida.
	static bool leer(const std::string & path, std::string & contenido);

    // elimina el archivo ubicado en el path indicado.
    static bool eliminar(std::string path);

};

};
};


