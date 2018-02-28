#pragma once

// stl
#include <string>
#include <vector>

// log
#include <log/include/SalidaLogger.h>

namespace herramientas
{
namespace log
{

class ConfiguracionLogger
{
public:

    ConfiguracionLogger(std::string path_archivo_configuracion = "");
    virtual ~ConfiguracionLogger();

    // METODOS

    void leerConfiguracion(std::string path_archivo_configuracion);

    // CONFIGURACIONES

    std::string getNombreLogger();
    unsigned long long int  getTamanioColaAsync();
    std::string getNivel();
    std::string getFlush();
    std::string getPatron();
    bool getAgruparPorFecha();
    std::vector<std::string> getSalidas();

    // TAGS

    std::string tagNombreLogger();
    std::string tagTamanioColaAsync();
    std::string tagAgruparPorFecha();
    std::string tagNivel();
    std::string tagFlush();
    std::string tagPatron();
    std::string tagSalidas();
    std::string tagSalidaTipo();
    std::string tagSalidaPath();

private:

    std::string nombre_logger;
    unsigned long long int tamanio_cola_async;
    bool agrupar_por_fecha;
    std::string nivel;
    std::string flush;
    std::string patron;
    std::vector<std::string> salidas_logger;
};

};
};
