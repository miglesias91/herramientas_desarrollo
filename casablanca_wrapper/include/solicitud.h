#pragma once

//stl
#include <string>
#include <array>

// casablanca wrapper
#include <casablanca_wrapper/include/respuesta.h>

// casablanca
#include <cpprest/http_client.h>

namespace herramientas { namespace cpprest {

/// \brief wrapper de las http_request's
class solicitud
{
public:
    static const std::array<std::string, 4> nombres_metodos;
    static const std::array<web::http::method, 4> metodos_web;

    enum metodos { GET = 0, POST = 1, PUT = 2, DEL = 3 };

	solicitud();
	virtual ~solicitud();
		
	web::http::http_request* solicitud_http() const;
    std::string cuerpo() const;
    metodos metodo() const;
    std::string nombre_metodo() const;
    std::string uri() const;
    std::vector<std::string> encabezados() const;
    
	void cuerpo(const std::string &cuerpo);
	void uri(const std::string &uri);
    void metodo(const metodos &metodo_solicitud);

	void nuevo_encabezado(const std::string &nombre_encabezado, const std::string &contenido_encabezado);

private:
    std::unique_ptr<web::http::http_request> solicitud_http_ptr;

    metodos metodo_solicitud;
    std::string cuerpo_solicitud;
    std::string uri_solicitud;

    std::vector<std::string> encabezados_solicitud;
};

}
}

