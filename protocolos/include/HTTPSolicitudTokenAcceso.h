#pragma once

// stl
#include <string>

// casablanca wrapper
#include <herramientas_desarrollo/casablanca_wrapper/include/HTTPSolicitud.h>

namespace HerramientasDesarrollo
{
namespace Protocolos
{

	class HTTPSolicitudTokenAcceso : public HerramientasDesarrollo::CasablancaWrapper::HTTPSolicitud
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

