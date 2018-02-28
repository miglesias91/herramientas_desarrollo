#pragma once

// stl
#include <string>

// spdlog
#include <spdlog/spdlog.h>

namespace herramientas
{
namespace log
{

class SalidaLogger
{
public:

    SalidaLogger();
    SalidaLogger(std::string tipo, std::string path_salida_log);
    virtual ~SalidaLogger();

    // GETTERS

    std::string getTipo();
    std::string getPathSalidaLog();

    spdlog::sink_ptr getSPDSink();

    // SETTERS

    // CONSULTAS

private:

    // ATRIBUTOS

    std::string tipo;
    std::string path_salida_log;

    spdlog::sink_ptr sink;
};

};
};

