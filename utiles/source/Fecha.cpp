#include <utiles/include/Fecha.h>

// stl
#include <iomanip>
#include <sstream>
#include <time.h>

// funciones string
#include <utiles/include/FuncionesString.h>

namespace herramientas::utiles {

std::vector<std::string> Fecha::nombres_meses = { "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre" };

// CONSTRUCTORES

Fecha::Fecha(const std::string & etiqueta) : dia(0), mes(0), anio(0), horas(0), minutos(0), segundos(0), etiqueta(etiqueta) {}
Fecha::Fecha(const uint32_t & dia, const uint32_t & mes, const uint32_t & anio, const std::string & etiqueta)
    : dia(dia), mes(mes), anio(anio), horas(0), minutos(0), segundos(0), etiqueta(etiqueta) {}
Fecha::Fecha(const uint32_t & dia, const uint32_t & mes, const uint32_t & anio, const uint32_t & horas, const uint32_t & minutos, const uint32_t & segundos, const std::string & etiqueta)
    : dia(dia), mes(mes), anio(anio), horas(horas), minutos(minutos), segundos(segundos), etiqueta(etiqueta) {}

Fecha::~Fecha() {}

// GETTERS

Fecha Fecha::getFechaActual() {
    time_t tiempo = std::time(nullptr);
    tm tm;
    localtime_s(&tm, &tiempo);

    Fecha fecha_actual;
    fecha_actual.setAnio(tm.tm_year + 1900);
    fecha_actual.setMes(tm.tm_mon + 1);
    fecha_actual.setDia(tm.tm_mday);
    fecha_actual.setHoras(tm.tm_hour);
    fecha_actual.setMinutos(tm.tm_min);
    fecha_actual.setSegundos(tm.tm_sec);

    return fecha_actual;
}

uint32_t Fecha::getDia() const {
	return this->dia;
}

uint32_t Fecha::getMes() const {
	return this->mes;
}

uint32_t Fecha::getAnio() const {
	return this->anio;
}

uint32_t Fecha::getHoras() const {
    return this->horas;
}

uint32_t Fecha::getMinutos() const {
    return this->minutos;
}

uint32_t Fecha::getSegundos() const {
    return this->segundos;
}

std::string Fecha::getStringDia() const {
    char buffer[10];

    sprintf_s(buffer, "%02d", this->dia);

	return std::string(buffer);
}

std::string Fecha::getStringMes() const {
    char buffer[10];

    sprintf_s(buffer, "%02d", this->mes);

    return std::string(buffer);
}

std::string Fecha::getStringAnio() const {
    char buffer[10];

    sprintf_s(buffer, "%04d", this->anio);

    return std::string(buffer);
}

std::string Fecha::getStringHoras() const {
    char buffer[10];

    sprintf_s(buffer, "%02d", this->horas);

    return std::string(buffer);
}

std::string Fecha::getStringMinutos() const {
    char buffer[10];

    sprintf_s(buffer, "%02d", this->minutos);

    return std::string(buffer);
}

std::string Fecha::getStringSegundos() const {
    char buffer[10];

    sprintf_s(buffer, "%02d", this->segundos);

    return std::string(buffer);
}

std::string Fecha::getNombreMes() const {
    return nombres_meses[this->mes - 1];
}

std::string Fecha::getStringDDMMAAAA(const std::string & separador) const {
    return this->getStringDia() + separador + this->getStringMes() + separador + this->getStringAnio();
}

std::string Fecha::getStringAAAAMMDD(const std::string & separador) const {
    return this->getStringAnio() + separador + this->getStringMes() + separador + this->getStringDia();
}

std::string Fecha::getStringAAAAMMDDHHmmSS(const std::string & separador_dia, const std::string & separador_dia_hora, const std::string & separador_hora) const {
    return this->getStringAnio() + separador_dia + this->getStringMes() + separador_dia + this->getStringDia() + separador_dia_hora + this->getStringHoras() + separador_hora + this->getStringMinutos() + separador_hora + this->getStringSegundos();
}

std::string Fecha::getStringDDmesAAAA(const std::string & separador) const {
    return this->getStringDia() + separador + this->getNombreMes() + separador + this->getStringAnio();
}

// SETTERS

void Fecha::setDia(const std::string & dia)
{
	this->dia = std::stoi(dia);
}

void Fecha::setMes(const std::string & mes)
{
	this->mes = std::stoi(mes);
}

void Fecha::setAnio(const std::string & anio)
{
	this->anio = std::stoi(anio);
}

void Fecha::setHoras(const std::string & horas)
{
    this->horas = std::stoi(horas);
}

void Fecha::setMinutos(const std::string & minutos)
{
    this->minutos = std::stoi(minutos);
}

void Fecha::setSegundos(const std::string & segundos)
{
    this->segundos = std::stoi(segundos);
}

void Fecha::setDia(const uint32_t & dia)
{
	this->dia = dia;
}

void Fecha::setMes(const uint32_t & mes)
{
	this->mes = mes;
}

void Fecha::setAnio(const uint32_t & anio)
{
	this->anio = anio;
}

void Fecha::setHoras(const uint32_t & horas)
{
    this->horas = horas;
}

void Fecha::setMinutos(const uint32_t & minutos)
{
    this->minutos = minutos;
}

void Fecha::setSegundos(const uint32_t & segundos)
{
    this->segundos = segundos;
}

// METODOS

bool Fecha::parsear(const std::string & string_fecha, const std::string & formato, Fecha * fecha) {

    std::stringstream stream_fecha(string_fecha);

    std::tm t = {};
    stream_fecha >> std::get_time(&t, formato.c_str());

    if (stream_fecha.fail()) {
        return false;
    }

    fecha->setAnio(t.tm_year + 1900);
    fecha->setMes(t.tm_mon + 1);
    fecha->setDia(t.tm_mday);

    fecha->setHoras(t.tm_hour);
    fecha->setMinutos(t.tm_min);
    fecha->setSegundos(t.tm_sec);

    return true;
}

Fecha Fecha::parsearFormatoAAAAMMDD(const std::string & string_fecha, const std::string & separador)
{
    std::string copia = string_fecha;
    if (separador.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(copia, separador);
    }
    
    if (8 != copia.size())
    {
        return Fecha(0, 0, 0);
    }

    std::string string_anio = copia.substr(0, 4);
    std::string string_mes = copia.substr(4, 2);
    std::string string_dia = copia.substr(6, 2);

    uint32_t anio = std::stoul(string_anio);
    uint32_t mes = std::stoul(string_mes);
    uint32_t dia = std::stoul(string_dia);
    
    if (mes > 12 || dia > 31)
    {
        return Fecha(0, 0, 0);
    }

    return Fecha(dia, mes, anio);
}

Fecha Fecha::parsearFormatoAAAAMMDDHHmmSS(const std::string & string_fecha, const std::string & separador_dia, const std::string & separador_dia_hora, const std::string & separador_hora)
{
    std::string copia = string_fecha;
    if (separador_dia.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(copia, separador_dia);
    }

    if (separador_dia_hora.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(copia, separador_dia_hora);
    }

    if (separador_hora.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(copia, separador_hora);
    }

    if (14 != copia.size())
    {
        return Fecha(0, 0, 0);
    }

    std::string string_anio = copia.substr(0, 4);
    std::string string_mes = copia.substr(4, 2);
    std::string string_dia = copia.substr(6, 2);
    std::string string_horas = copia.substr(8, 2);
    std::string string_minutos = copia.substr(10, 2);
    std::string string_segundos = copia.substr(12, 2);

    uint32_t anio = std::stoul(string_anio);
    uint32_t mes = std::stoul(string_mes);
    uint32_t dia = std::stoul(string_dia);
    uint32_t horas = std::stoul(string_horas);
    uint32_t minutos = std::stoul(string_minutos);
    uint32_t segundos = std::stoul(string_segundos);

    if (mes > 12 || dia > 31 || horas > 23 || minutos > 59 || segundos > 59)
    {
        return Fecha(0, 0, 0);
    }

    return Fecha(dia, mes, anio, horas, minutos, segundos);
}

Fecha Fecha::parsearFormatoDDmesAAAA(const std::string & string_fecha, const std::string & separador)
{
    std::string copia = string_fecha;
    if (separador.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(copia, separador);
    }

    std::string string_dia = copia.substr(0, 2);
    std::string string_mes = copia.substr(2, copia.size() - 6);
    std::string string_anio = copia.substr(copia.size() - 4, 4);

    uint32_t anio = std::stoul(string_anio);
    uint32_t mes = std::distance(nombres_meses.begin(), std::find(nombres_meses.begin(), nombres_meses.end(), string_mes)) + 1;
    uint32_t dia = std::stoul(string_dia);

    if (mes > 12 || dia > 31)
    {
        return Fecha(0, 0, 0);
    }

    return Fecha(dia, mes, anio);
}

Fecha Fecha::parsearFormatoDDMMAAAA(const std::string & string_fecha, const std::string & separador)
{
    std::string copia = string_fecha;
    if (separador.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(copia, separador);
    }

    if (8 != copia.size())
    {
        return Fecha(0, 0, 0);
    }

    std::string string_anio = copia.substr(4, 4);
    std::string string_mes = copia.substr(2, 2);
    std::string string_dia = copia.substr(0, 2);

    uint32_t anio = std::stoul(string_anio);
    uint32_t mes = std::stoul(string_mes);
    uint32_t dia = std::stoul(string_dia);
    
    if (mes > 12 || dia > 31)
    {
        return Fecha(0, 0, 0);
    }

    return Fecha(dia, mes, anio);
}

// CONSULTAS

// OPERADORES

bool Fecha::operator<(const Fecha & fecha_a_comparar) const
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha < string_fecha_a_comparar;
}

bool Fecha::operator>(const Fecha & fecha_a_comparar) const
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha > string_fecha_a_comparar;
}

bool Fecha::operator<=(const Fecha & fecha_a_comparar) const
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha <= string_fecha_a_comparar;
}

bool Fecha::operator>=(const Fecha & fecha_a_comparar) const
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha >= string_fecha_a_comparar;
}

bool Fecha::operator==(const Fecha & fecha_a_comparar) const
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha == string_fecha_a_comparar;
}

bool Fecha::operator!=(const Fecha & fecha_a_comparar) const
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha != string_fecha_a_comparar;
}

bool Fecha::operator-=(const std::chrono::hours & horas) {
    struct tm t = {0};
    t.tm_year = this->anio - 1900;
    t.tm_mon = this->mes - 1;
    t.tm_mday = this->dia;
    t.tm_hour = this->horas;
    t.tm_min = this->minutos;
    t.tm_sec = this->segundos;

    std::chrono::system_clock::time_point segundos_desde_epoca = std::chrono::system_clock::from_time_t(std::mktime(&t));
    segundos_desde_epoca = segundos_desde_epoca - horas;

    time_t tiempo = std::chrono::system_clock::to_time_t(segundos_desde_epoca);
    t = *localtime(&tiempo);

    this->setAnio(t.tm_year + 1900);
    this->setMes(t.tm_mon + 1);
    this->setDia(t.tm_mday);

    this->setHoras(t.tm_hour);
    this->setMinutos(t.tm_min);
    this->setSegundos(t.tm_sec);

    return true;
}

bool Fecha::operator+=(const std::chrono::hours & horas) {
    struct tm t = {0};
    t.tm_year = this->anio - 1900;
    t.tm_mon = this->mes - 1;
    t.tm_mday = this->dia;
    t.tm_hour = this->horas;
    t.tm_min = this->minutos;
    t.tm_sec = this->segundos;

    std::chrono::system_clock::time_point segundos_desde_epoca = std::chrono::system_clock::from_time_t(std::mktime(&t));
    segundos_desde_epoca = segundos_desde_epoca + horas;

    time_t tiempo = std::chrono::system_clock::to_time_t(segundos_desde_epoca);
    t = *localtime(&tiempo);

    this->setAnio(t.tm_year + 1900);
    this->setMes(t.tm_mon + 1);
    this->setDia(t.tm_mday);

    this->setHoras(t.tm_hour);
    this->setMinutos(t.tm_min);
    this->setSegundos(t.tm_sec);
    return false;
}

bool Fecha::operator-=(const std::chrono::minutes & minutos) {
    struct tm t = {0};
    t.tm_year = this->anio - 1900;
    t.tm_mon = this->mes - 1;
    t.tm_mday = this->dia;
    t.tm_hour = this->horas;
    t.tm_min = this->minutos;
    t.tm_sec = this->segundos;

    std::chrono::system_clock::time_point segundos_desde_epoca = std::chrono::system_clock::from_time_t(std::mktime(&t));
    segundos_desde_epoca = segundos_desde_epoca - minutos;

    time_t tiempo = std::chrono::system_clock::to_time_t(segundos_desde_epoca);
    t = *localtime(&tiempo);

    this->setAnio(t.tm_year + 1900);
    this->setMes(t.tm_mon + 1);
    this->setDia(t.tm_mday);

    this->setHoras(t.tm_hour);
    this->setMinutos(t.tm_min);
    this->setSegundos(t.tm_sec);
    return false;
}

bool Fecha::operator+=(const std::chrono::minutes & minutos) {
    struct tm t = {0};
    t.tm_year = this->anio - 1900;
    t.tm_mon = this->mes - 1;
    t.tm_mday = this->dia;
    t.tm_hour = this->horas;
    t.tm_min = this->minutos;
    t.tm_sec = this->segundos;

    std::chrono::system_clock::time_point segundos_desde_epoca = std::chrono::system_clock::from_time_t(std::mktime(&t));
    segundos_desde_epoca = segundos_desde_epoca + minutos;

    time_t tiempo = std::chrono::system_clock::to_time_t(segundos_desde_epoca);
    t = *localtime(&tiempo);

    this->setAnio(t.tm_year + 1900);
    this->setMes(t.tm_mon + 1);
    this->setDia(t.tm_mday);

    this->setHoras(t.tm_hour);
    this->setMinutos(t.tm_min);
    this->setSegundos(t.tm_sec);
    return false;
}

bool Fecha::operator-=(const std::chrono::seconds & segundos) {
    struct tm t = {0};
    t.tm_year = this->anio - 1900;
    t.tm_mon = this->mes - 1;
    t.tm_mday = this->dia;
    t.tm_hour = this->horas;
    t.tm_min = this->minutos;
    t.tm_sec = this->segundos;

    std::chrono::system_clock::time_point segundos_desde_epoca = std::chrono::system_clock::from_time_t(std::mktime(&t));
    segundos_desde_epoca = segundos_desde_epoca - segundos;

    time_t tiempo = std::chrono::system_clock::to_time_t(segundos_desde_epoca);
    t = *localtime(&tiempo);

    this->setAnio(t.tm_year + 1900);
    this->setMes(t.tm_mon + 1);
    this->setDia(t.tm_mday);

    this->setHoras(t.tm_hour);
    this->setMinutos(t.tm_min);
    this->setSegundos(t.tm_sec);
    return false;
}

bool Fecha::operator+=(const std::chrono::seconds & segundos) {
    struct tm t = {0};
    t.tm_year = this->anio - 1900;
    t.tm_mon = this->mes - 1;
    t.tm_mday = this->dia;
    t.tm_hour = this->horas;
    t.tm_min = this->minutos;
    t.tm_sec = this->segundos;

    std::chrono::system_clock::time_point segundos_desde_epoca = std::chrono::system_clock::from_time_t(std::mktime(&t));
    segundos_desde_epoca = segundos_desde_epoca + segundos;

    time_t tiempo = std::chrono::system_clock::to_time_t(segundos_desde_epoca);
    t = *localtime(&tiempo);

    this->setAnio(t.tm_year + 1900);
    this->setMes(t.tm_mon + 1);
    this->setDia(t.tm_mday);

    this->setHoras(t.tm_hour);
    this->setMinutos(t.tm_min);
    this->setSegundos(t.tm_sec);
    return false;
}

}