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
	OAuth2Consumidor(std::string clave_publica, std::string clave_privada);
	virtual ~OAuth2Consumidor();

	// GETTERS

	std::string getClavePublica();

	std::string getClavePrivada();

    std::string getTokenAcceso();

	// SETTERS

	void setClavePublica(std::string clave_publica);

	void setClavePrivada(std::string clave_privada);

    void setTokenAcceso(std::string token_acceso);

private:

	std::string clave_publica;
	std::string clave_privada;

    std::string token_acceso;
};

}
}

