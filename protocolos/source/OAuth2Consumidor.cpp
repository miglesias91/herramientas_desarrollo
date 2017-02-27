#include <herramientas_desarrollo/protocolos/include/OAuth2Consumidor.h>

using namespace HerramientasDesarrollo::Protocolos;

OAuth2Consumidor::OAuth2Consumidor(std::string clave_publica, std::string clave_privada, std::string servidor_api) :
	clave_publica(clave_publica), clave_privada(clave_privada), servidor_api(servidor_api)
{
}

OAuth2Consumidor::~OAuth2Consumidor()
{
}

// GETTERS

std::string OAuth2Consumidor::getClavePublica()
{
	return this->clave_publica;
}

std::string OAuth2Consumidor::getClavePrivada()
{
	return this->clave_privada;
}

std::string OAuth2Consumidor::getServidorAPI()
{
	return this->servidor_api;
}

// SETTERS

void OAuth2Consumidor::getClavePublica(std::string clave_publica)
{
	this->clave_publica = clave_publica;
}

void OAuth2Consumidor::getClavePrivada(std::string clave_privada)
{
	this->clave_privada = clave_privada;
}

void OAuth2Consumidor::getServidorAPI(std::string servidor_api)
{
	this->servidor_api = servidor_api;
}