#include <protocolos/include/HTTPSolicitudTokenAcceso.h>

using namespace herramientas::protocolos;

HTTPSolicitudTokenAcceso::HTTPSolicitudTokenAcceso(std::string clave_publica, std::string clave_privada) :
	clave_publica(clave_publica), clave_privada(clave_privada), token_acceso("")
{
}


HTTPSolicitudTokenAcceso::~HTTPSolicitudTokenAcceso()
{
}

// GETTERS

std::string HTTPSolicitudTokenAcceso::getTokenAcceso()
{
	return this->token_acceso;
}

// SETTERS

// METODOS