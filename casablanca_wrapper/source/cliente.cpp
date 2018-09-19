#include <casablanca_wrapper/include/cliente.h>

// casablanca wrapper
#include <casablanca_wrapper/include/respuesta.h>

namespace herramientas { namespace cpprest {

cliente::cliente(const std::string &uri_cliente) : http_cliente(web::uri(utility::conversions::to_string_t(uri_cliente))), uri_cliente(uri_cliente) {}

cliente::~cliente() {}

std::string cliente::uri() const {
    return this->uri_cliente;
}

void cliente::uri(const std::string &uri_cliente) {
    this->uri_cliente = uri_cliente;
}

respuesta * cliente::solicitar(const solicitud *solicitud) {
    web::http::http_request * http_solicitud = solicitud->solicitud_http();

    pplx::task<web::http::http_response> http_solicitud_tarea = this->http_cliente.request(*http_solicitud);
    // aca lo mega-optimo seria hacer algo con la task 'http_solicitud_tarea' para hacer varias solicitudes en paralelo, aprovechando
    // que se hace una llamada asincronica.

    // por ahora obtengo directamente la respuesta, forzando a que se comporte como una llamada sincronica.
    web::http::http_response http_respuesta = http_solicitud_tarea.get();

    return new respuesta(http_respuesta);
}
}
}