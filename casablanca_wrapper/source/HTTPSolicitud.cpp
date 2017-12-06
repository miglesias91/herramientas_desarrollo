#include <casablanca_wrapper/include/HTTPSolicitud.h>

using namespace herramientas::cpprest;

HTTPSolicitud::HTTPSolicitud()
{
}

HTTPSolicitud::~HTTPSolicitud()
{
}

// GETTERS

web::http::http_request HTTPSolicitud::getSolicitud()
{
	return this->solicitud;
}

// SETTERS

void HTTPSolicitud::setCuerpo(std::string cuerpo)
{
	this->solicitud.set_body(cuerpo);
}

void HTTPSolicitud::setURI(std::string uri)
{
	utility::string_t uri_t = utility::conversions::to_string_t(uri);

	web::uri web_uri(uri_t);

	this->solicitud.set_request_uri(web_uri);
}

void HTTPSolicitud::setPOST()
{
	this->metodo_http = web::http::methods::POST;
}

void HTTPSolicitud::setGET()
{
	this->metodo_http = web::http::methods::GET;
}

void HTTPSolicitud::setPUT()
{
	this->metodo_http = web::http::methods::PUT;
}

// METODOS

void HTTPSolicitud::agregarEncabezado(std::string nombre_encabezado, std::string contenido_encabezado)
{
	utility::string_t nombre_encabezado_t = utility::conversions::to_string_t(nombre_encabezado);

	utility::string_t contenido_encabezado_t = utility::conversions::to_string_t(contenido_encabezado);

	this->solicitud.headers().add(nombre_encabezado_t, contenido_encabezado_t);
}