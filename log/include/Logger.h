#pragma once

// stl
#include <vector>

// log
#include <log/include/ConfiguracionLogger.h>
#include <log/include/SalidaLogger.h>

namespace herramientas
{
namespace log
{

class Logger
{
public:

    Logger(std::vector<SalidaLogger*> salidas, ConfiguracionLogger * configuracion);
    virtual ~Logger();

    // GETTERS

    // SETTERS

    // CONSULTAS

private:

    // ATRIBUTOS

    ConfiguracionLogger * configuracion;

    std::vector<SalidaLogger*> salidas;

    std::shared_ptr<spdlog::logger> logger_ptr;
};

};
};

