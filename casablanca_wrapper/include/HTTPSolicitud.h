#pragma once

//stl
#include <string>

// casablanca wrapper
#include <casablanca_wrapper/include/HTTPRespuesta.h>

// casablanca
#include <cpprest/http_client.h>

namespace herramientas
{
namespace cpprest
{

/// \brief wrapper de las http_request's
class HTTPSolicitud
{
public:
	HTTPSolicitud();
	virtual ~HTTPSolicitud();

	// GETTERS
		
	web::http::http_request * getSolicitud();

    std::string getCuerpo();

    std::string getMetodo();

    std::string getURI();

    std::vector<std::string> getEncabezados();

	// SETTERS
    
    void setSolicitud(web::http::http_request * solicitud);

	void setCuerpo(std::string cuerpo);

	void setURI(std::string uri);

	void setPOST();

	void setGET();

	void setPUT();

	// METODOS

	void agregarEncabezado(std::string nombre_encabezado, std::string contenido_encabezado);

private:

	web::http::http_request * solicitud;

    std::string metodo;
    std::string cuerpo;
    std::string uri;

    std::vector<std::string> encabezados;
};

}
}

