#include <utiles/include/csv.h>

// stl
#include <algorithm>

using namespace herramientas::utiles;

csv::csv(const std::vector<std::string> & nombres_columnas, const std::string & separador) : nombres_columnas(nombres_columnas), separador_campos(separador) {}

csv::~csv() {}

std::vector<std::string> csv::columnas() const {
    return this->nombres_columnas;
}

void csv::columnas(const std::vector<std::string>& nombres_columnas) {
    this->nombres_columnas = nombres_columnas;
}

std::vector<herramientas::utiles::csv::fila> csv::filas() const {
    return this->filas_valores;
}

void csv::filas(const std::vector<fila>& filas_valores) {
    this->filas_valores = filas_valores;
}

std::string csv::separador() const {
    return this->separador_campos;
}

void csv::separador(const std::string & separador_campos) {
    this->separador_campos = separador_campos;
}

void csv::exportar(std::ofstream& salida) const {
    salida << herramientas::utiles::FuncionesString::unir(this->nombres_columnas, this->separador_campos) << "\n";

    std::for_each(this->filas_valores.cbegin(), this->filas_valores.cend(), [=, &salida](const fila& fila_a_escribir) {
        salida << fila_a_escribir.escribir(this->separador_campos) << "\n";
    });
}

void csv::agregar(const csv::fila& fila) {
    this->filas_valores.push_back(fila);
}

void csv::agregar(const std::vector<std::string>& fila_nueva) {
    this->filas_valores.push_back(fila(fila_nueva));
}

void csv::operator+=(const csv & otro) {
    std::vector<fila> filas_a_agregar = otro.filas();

    this->filas_valores.insert(this->filas_valores.end(), filas_a_agregar.begin(), filas_a_agregar.end());
}
