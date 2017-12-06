#pragma once

// stl
#include <string>

namespace herramientas
{
namespace protocolos
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

    std::string getTokenAcceso();

	// SETTERS

	void setClavePublica(std::string clave_publica);

	void setClavePrivada(std::string clave_privada);

	void setServidorAPI(std::string servidor_api);

    void setTokenAcceso(std::string token_acceso);

private:

	std::string clave_publica;
	std::string clave_privada;
	std::string servidor_api;

    std::string token_acceso;
};

}
}

