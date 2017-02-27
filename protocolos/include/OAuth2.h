#pragma once

// stl
#include <string>

// protocolos
#include <herramientas_desarrollo/protocolos/include/OAuth2Consumidor.h>

namespace HerramientasDesarrollo
{
namespace Protocolos
{
	class OAuth2
	{
	public:
		OAuth2();
		virtual ~OAuth2();

		static std::string getTokenAcceso(OAuth2Consumidor consumidor);
	};
}
}

