#include <protocolos/include/OAuth2.h>

// casablanca wrapper
#include <casablanca_wrapper/include/HTTPCliente.h>
#include <casablanca_wrapper/include/HTTPRespuesta.h>

// protocolos
#include <protocolos/include/HTTPSolicitudTokenAcceso.h>

using namespace herramientas::protocolos;

OAuth2::OAuth2()
{
}

OAuth2::~OAuth2()
{
}

bool OAuth2::solicitarTokenAcceso(OAuth2Consumidor * consumidor, std::string servidor_api)
{
	std::string clave_publica = consumidor->getClavePublica();
	std::string clave_privada = consumidor->getClavePrivada();

	HTTPSolicitudTokenAcceso solicitud_token_acceso(clave_publica, clave_privada);

	herramientas::cpprest::HTTPCliente cliente_http_api(servidor_api);

	herramientas::cpprest::HTTPRespuesta * http_respuesta = cliente_http_api.solicitar(&solicitud_token_acceso);

    std::string token_acceso;
    
    try
    {
        token_acceso = http_respuesta->getJson()->getAtributoValorString("access_token");
    }
    catch (...)
    {// si entra aca, es porq no reconoce el campo "access_token", osea que no se obtuvo ningun token.
        delete http_respuesta;
        return false;
    }

    consumidor->setTokenAcceso(token_acceso);

    delete http_respuesta;

    return true;;
}