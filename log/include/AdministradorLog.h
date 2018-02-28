/// IAdministradorAlmacenamiento.h
/// 02-05-2017

#pragma once

// stl
#include <vector>
#include <unordered_map>

// log
#include <log/include/ConfiguracionLogger.h>
#include <log/include/Logger.h>

namespace herramientas
{

namespace log
{

class AdministradorLog
{
public:

    AdministradorLog(ConfiguracionLogger * configuracion);
    virtual ~AdministradorLog();

    static Logger * iniciarNuevo(std::string path_configuracion);

    static void liberarTodo();

    static void liberarSalidaLogger(std::string path_salida);

    static void liberarLogger(std::string nombre_logger);

    // GETTERS

    static SalidaLogger * getSalidaLogger(std::string path_salida);

    static Logger* getLogger(std::string nombre_logger);

    // SETTERS

    // METODOS

    // CONSULTA

    static bool loggerIniciado(std::string nombre);

    static bool salidaLoggerIniciada(std::string path_salida);

protected:

    ConfiguracionLogger * configuracion;

private:
    // METODOS INTERNOS

    // ATRIBUTOS

    static std::unordered_map<std::string, Logger*> mapa_loggers;
    static std::unordered_map<std::string, SalidaLogger*> mapa_salidas;
};

};
};