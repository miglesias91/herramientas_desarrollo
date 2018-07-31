#pragma once

// stl
#include <fstream>
#include <vector>

// utiles
#include <utiles/include/FuncionesString.h>

namespace herramientas {
namespace utiles {

class csv {

    struct fila {
        explicit fila(const std::vector<std::string> & valores) : valores(valores) {}
        virtual ~fila() {};

        std::string escribir(const std::string& separador = ",") const {
            return FuncionesString::unir(this->valores, separador);
        };

        std::vector<std::string> valores;
    };

public:
    csv(const std::vector<std::string> & nombres_columnas = {}, const std::string & separador = ",");
    virtual ~csv();

    std::vector<std::string> columnas() const;
    void columnas(const std::vector<std::string>& nombres_columnas);

    std::vector<fila> filas() const;
    void filas(const std::vector<fila>& filas_valores);

    std::string separador() const;
    void separador(const std::string& separador_campos);

    void exportar(std::ofstream& salida) const;

    void agregar(const fila& fila);
    void agregar(const std::vector<std::string>& fila);

    void operator+=(const csv& otro);

private:
    std::vector<std::string> nombres_columnas;
    std::vector<fila> filas_valores;
    std::string separador_campos;
};

};
};

