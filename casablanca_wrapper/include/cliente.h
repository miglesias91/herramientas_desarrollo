#pragma once

// stl
#include <string>

// casablanca
#include <cpprest/http_client.h>

// casablanca wrapper
#include <casablanca_wrapper/include/solicitud.h>
#include <casablanca_wrapper/include/respuesta.h>

namespace herramientas { namespace cpprest {
	/// \brief wrapper de los http_client's
class cliente
{
public:
	cliente(const std::string &uri_cliente);
	virtual ~cliente();

    std::string uri() const;

    void uri(const std::string &uri_cliente);

	respuesta* solicitar(const solicitud *solicitud);

private:

	web::http::client::http_client http_cliente;
	std::string uri_cliente;
};

}
}

