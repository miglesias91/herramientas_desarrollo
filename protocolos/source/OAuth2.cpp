#include <herramientas_desarrollo/protocolos/include/OAuth2.h>

// casablanca wrapper
#include <herramientas_desarrollo/casablanca_wrapper/include/HTTPCliente.h>

// protocolos
#include <herramientas_desarrollo/protocolos/include/HTTPSolicitudTokenAcceso.h>

using namespace HerramientasDesarrollo::Protocolos;

OAuth2::OAuth2()
{
}

OAuth2::~OAuth2()
{
}

std::string OAuth2::getTokenAcceso(OAuth2Consumidor consumidor)
{
	std::string clave_publica = consumidor.getClavePublica();
	std::string clave_privada = consumidor.getClavePrivada();
	std::string servidor_api = consumidor.getServidorAPI();

	HTTPSolicitudTokenAcceso solicitud_token_acceso(clave_publica, clave_privada);

	HerramientasDesarrollo::CasablancaWrapper::HTTPCliente cliente_http_api(servidor_api);

	cliente_http_api.solicitar(solicitud_token_acceso);

	std::string token_acceso = solicitud_token_acceso.getTokenAcceso();

	return token_acceso;
}