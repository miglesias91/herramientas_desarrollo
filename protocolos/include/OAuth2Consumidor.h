#pragma once

// stl
#include <string>

namespace HerramientasDesarrollo
{
namespace Protocolos
{
	class OAuth2Consumidor
	{
	public:
		OAuth2Consumidor(std::string clave_publica, std::string clave_privada, std::string servidor_api);
		virtual ~OAuth2Consumidor();

		// GETTERS

		std::string getClavePublica();

		std::string getClavePrivada();

		std::string getServidorAPI();

		// SETTERS

		void getClavePublica(std::string clave_publica);

		void getClavePrivada(std::string clave_privada);

		void getServidorAPI(std::string servidor_api);

	private:

		std::string clave_publica;
		std::string clave_privada;
		std::string servidor_api;
	};
}
}

