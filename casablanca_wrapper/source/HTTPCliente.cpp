#include <herramientas_desarrollo/casablanca_wrapper/include/HTTPCliente.h>

// casablanca wrapper
#include <herramientas_desarrollo/casablanca_wrapper/include/HTTPRespuesta.h>

using namespace herramientas::cpprest;

HTTPCliente::HTTPCliente(std::string cliente) : cliente( web::uri( utility::conversions::to_string_t(cliente) ) )
{
}

HTTPCliente::~HTTPCliente()
{
}

// GETTERS

// SETTERS

// METODOS

HTTPRespuesta * HTTPCliente::solicitar(HTTPSolicitud& solicitud)
{
	web::http::http_request http_solicitud = solicitud.getSolicitud();

	pplx::task<web::http::http_response> http_solicitud_tarea = this->cliente.request(http_solicitud);
	// aca lo mega-optimo seria hacer algo con la task 'http_solicitud_tarea' para hacer varias solicitudes en paralelo, aprovechando
	// que se hace una llamada asincronica.

	// por ahora obtengo directamente la respuesta, forzando a que se comporte como una llamada sincronica.
	web::http::http_response http_respuesta = http_solicitud_tarea.get();

	return new HTTPRespuesta(http_respuesta);
}
