#include <protocolos/include/HTTPSolicitudTokenAcceso.h>

// utiles
#include <utiles/include/Conversiones.h>

using namespace herramientas::protocolos;

HTTPSolicitudTokenAcceso::HTTPSolicitudTokenAcceso(std::string clave_publica, std::string clave_privada) :
    clave_publica(clave_publica), clave_privada(clave_privada), token_acceso(""), HTTPSolicitud()
{
    std::string claves_concatenadas = clave_publica + ":" + clave_privada;
    std::string claves_concatenadas_codificadas_en_base64 = herramientas::utiles::Conversiones::string2base64(claves_concatenadas);
    std::string header_claves_codificadas = "Basic " + claves_concatenadas_codificadas_en_base64;

    // armo la solicitud para el token de acceso
    web::http::http_request * http_solicitud_token_acceso = new web::http::http_request();

    http_solicitud_token_acceso->headers().add(L"Authorization", utility::conversions::to_string_t(header_claves_codificadas));
    http_solicitud_token_acceso->headers().add(L"Content-Type", L"application/x-www-form-urlencoded;charset=UTF-8");
    http_solicitud_token_acceso->set_body(L"grant_type=client_credentials");
    http_solicitud_token_acceso->set_request_uri(L"/oauth2/token");
    http_solicitud_token_acceso->set_method(web::http::methods::POST);

    this->setSolicitud(http_solicitud_token_acceso);
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