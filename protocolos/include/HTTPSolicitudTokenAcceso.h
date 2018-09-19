#pragma once

// stl
#include <string>

// casablanca wrapper
#include <casablanca_wrapper/include/solicitud.h>

namespace herramientas
{
namespace protocolos
{

class HTTPSolicitudTokenAcceso : public herramientas::cpprest::solicitud
{
public:
	HTTPSolicitudTokenAcceso(std::string clave_publica, std::string clave_privada);

	virtual ~HTTPSolicitudTokenAcceso();

	// GETTERS

	std::string getTokenAcceso();

	// SETTERS

	// METODOS

private:

	std::string clave_publica;
	std::string clave_privada;
	std::string token_acceso;
};


}
}

