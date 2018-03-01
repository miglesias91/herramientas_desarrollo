#include <log/include/SalidaLogger.h>

using namespace herramientas::log;

SalidaLogger::SalidaLogger() : tipo(""), path_salida_log("")
{
}

SalidaLogger::SalidaLogger(std::string tipo, std::string path_salida_log) : tipo(tipo), path_salida_log(path_salida_log)
{
    this->sink = std::make_shared<spdlog::sinks::simple_file_sink_mt>(this->path_salida_log);
}

SalidaLogger::~SalidaLogger()
{
}

// GETTERS

std::string SalidaLogger::getTipo()
{
    return this->tipo;
}

std::string SalidaLogger::getPathSalidaLog()
{
    return this->path_salida_log;
}

spdlog::sink_ptr SalidaLogger::getSPDSink()
{
    return this->sink;
}

// SETTERS

// METODOS

// CONSULTAS

