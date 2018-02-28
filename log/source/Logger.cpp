#include <log/include/Logger.h>

using namespace herramientas::log;

Logger::Logger(std::vector<SalidaLogger*> salidas, ConfiguracionLogger * configuracion) : salidas(salidas), configuracion(configuracion)
{
    std::vector<spdlog::sink_ptr> sinks;

    for (std::vector<SalidaLogger*>::iterator it = this->salidas.begin(); it != this->salidas.end(); it++)
    {
        sinks.push_back((*it)->getSPDSink());
    }

     this->logger_ptr = std::make_shared<spdlog::logger>(configuracion->getNombreLogger(), sinks.begin(), sinks.end());

     this->logger_ptr->set_level();
}

Logger::~Logger()
{
    if (NULL != this->configuracion)
    {
        delete this->configuracion;
        this->configuracion = NULL;
    }
}

