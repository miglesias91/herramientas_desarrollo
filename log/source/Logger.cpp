#include <log/include/Logger.h>

// stl
#include <algorithm>

using namespace herramientas::log;

std::vector<std::string> Logger::nombres_niveles = SPDLOG_LEVEL_NAMES;

Logger::Logger(std::vector<SalidaLogger*> salidas, ConfiguracionLogger * configuracion) : salidas(salidas), configuracion(configuracion)
{
    std::vector<spdlog::sink_ptr> sinks;

    for (std::vector<SalidaLogger*>::iterator it = this->salidas.begin(); it != this->salidas.end(); it++)
    {
        sinks.push_back((*it)->getSPDSink());
    }

     this->logger_ptr = std::make_shared<spdlog::logger>(configuracion->getNombreLogger(), sinks.begin(), sinks.end());

     this->logger_ptr->set_level(this->getNivelLog());

     this->logger_ptr->flush_on(this->getNivelFlush());

     if(false == this->configuracion->getPatron().empty())
     {
         this->logger_ptr->set_pattern(this->configuracion->getPatron());
     }
}

Logger::~Logger()
{
    spdlog::drop(this->configuracion->getNombreLogger());

    if (NULL != this->configuracion)
    {
        delete this->configuracion;
        this->configuracion = NULL;
    }
}

// GETTERS

spdlog::level::level_enum Logger::getNivelLog()
{
    unsigned int nivel = std::distance(nombres_niveles.begin(), std::find(nombres_niveles.begin(), nombres_niveles.end(), this->configuracion->getNivelLog()));

    return spdlog::level::level_enum(nivel);
}

spdlog::level::level_enum Logger::getNivelFlush()
{
    unsigned int nivel = std::distance(nombres_niveles.begin(), std::find(nombres_niveles.begin(), nombres_niveles.end(), this->configuracion->getNivelFlush()));

    return spdlog::level::level_enum(nivel);
}

// SETTERS

// METODOS


void Logger::marca(std::string mensaje)
{
    this->logger_ptr->trace(mensaje);
}

void Logger::debug(std::string mensaje)
{
    this->logger_ptr->debug(mensaje);
}

void Logger::info(std::string mensaje)
{
    this->logger_ptr->info(mensaje);
}

void Logger::advertencia(std::string mensaje)
{
    this->logger_ptr->warn(mensaje);
}

void Logger::error(std::string mensaje)
{
    this->logger_ptr->error(mensaje);
}

void Logger::critico(std::string mensaje)
{
    this->logger_ptr->critical(mensaje);
}

// CONSULTAS


