#include <log/include/AdministradorLog.h>

using namespace herramientas::log;

// stl
#include <algorithm>
#include <iostream>

// log
#include <log/include/LoggerIniciadoPreviamente.h>

std::unordered_map<std::string, Logger*> AdministradorLog::mapa_loggers;
std::unordered_map<std::string, SalidaLogger*> AdministradorLog::mapa_salidas;

AdministradorLog::AdministradorLog(ConfiguracionLogger * configuracion) : configuracion(configuracion)
{
}

AdministradorLog::~AdministradorLog()
{
    if (NULL != this->configuracion)
    {
        delete this->configuracion;
        this->configuracion = NULL;
    }
}

Logger * AdministradorLog::iniciarNuevo(std::string path_configuracion)
{
    // levanto config

    ConfiguracionLogger * config = new ConfiguracionLogger(path_configuracion);
    std::string nombre_logger = config->getNombreLogger();

    if (loggerIniciado(nombre_logger))
    {
        delete config;

        throw excepciones::LoggerIniciadoPreviamente(nombre_logger);
    }

    // creo y guardo las salidas. si ya existen, las recupero.

    std::vector<std::string> paths_salidas = config->getSalidas();

    std::vector<SalidaLogger*> salidas_logger;
    for (std::vector<std::string>::iterator it = paths_salidas.begin(); it != paths_salidas.end(); it++)
    {
        SalidaLogger * salida_logger = getSalidaLogger(*it);

        salidas_logger.push_back(salida_logger);
    }

    // creo el logger.

    mapa_loggers[nombre_logger] = new Logger(salidas_logger, config);
    return mapa_loggers[nombre_logger];
}

void AdministradorLog::liberarTodo()
{
    for (std::unordered_map<std::string, Logger*>::iterator it = mapa_loggers.begin(); it != mapa_loggers.end(); it++)
    {
        delete it->second;
    }
    mapa_loggers.clear();

    for (std::unordered_map<std::string, SalidaLogger*>::iterator it = mapa_salidas.begin(); it != mapa_salidas.end(); it++)
    {
        delete it->second;
    }
    mapa_salidas.clear();
}

void AdministradorLog::liberarSalidaLogger(std::string path_salida)
{
    if (true == salidaLoggerIniciada(path_salida))
    {
        delete mapa_salidas[path_salida];
        mapa_salidas.erase(path_salida);
    }
}

void AdministradorLog::liberarLogger(std::string nombre_logger)
{
    if (true == loggerIniciado(nombre_logger))
    {
        delete mapa_loggers[nombre_logger];
        mapa_loggers.erase(nombre_logger);
    }
}

bool AdministradorLog::loggerIniciado(std::string nombre)
{
    std::unordered_map<std::string, Logger*>::iterator it = mapa_loggers.find(nombre);

    return it != mapa_loggers.end();
}

bool AdministradorLog::salidaLoggerIniciada(std::string path_salida)
{
    std::unordered_map<std::string, SalidaLogger*>::iterator it = mapa_salidas.find(path_salida);

    return it != mapa_salidas.end();
}

// GETTERS

SalidaLogger * AdministradorLog::getSalidaLogger(std::string path_salida)
{
    if (false == salidaLoggerIniciada(path_salida))
    {
        mapa_salidas[path_salida] = new SalidaLogger("simple", path_salida);
    }

    return mapa_salidas[path_salida];
}

Logger * AdministradorLog::getLogger(std::string nombre)
{
    if (loggerIniciado(nombre))
    {
        return mapa_loggers[nombre];
    }
    else
    {
        throw std::exception("Logger no inicializado.");
    }
}
