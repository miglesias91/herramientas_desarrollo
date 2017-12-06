#pragma once

// stl
#include <string>

// protocolos
#include <protocolos/include/OAuth2Consumidor.h>

namespace herramientas
{
namespace protocolos
{
	class OAuth2
	{
	public:
		OAuth2();
		virtual ~OAuth2();

		static bool solicitarTokenAcceso(OAuth2Consumidor * consumidor);
	};
}
}

