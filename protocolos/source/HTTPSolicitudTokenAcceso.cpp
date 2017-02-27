#include <herramientas_desarrollo/protocolos/include/HTTPSolicitudTokenAcceso.h>

using namespace HerramientasDesarrollo::Protocolos;

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