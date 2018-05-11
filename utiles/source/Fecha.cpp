#include <utiles/include/Fecha.h>

// stl
#include <iomanip>
#include <sstream>
#include <time.h>

// funciones string
#include <utiles/include/FuncionesString.h>

using namespace herramientas::utiles;

std::vector<std::string> Fecha::nombres_meses = { "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre" };

// CONSTRUCTORES

Fecha::Fecha(std::string etiqueta) : dia(0), mes(0), anio(0), horas(0), minutos(0), segundos(0), etiqueta(etiqueta)
{
}

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio, std::string etiqueta) : dia(dia), mes(mes), anio(anio), horas(0), minutos(0), segundos(0), etiqueta(etiqueta)
{
}

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio, unsigned int horas, unsigned int minutos, unsigned int segundos, std::string etiqueta) : dia(dia), mes(mes), anio(anio), horas(horas), minutos(minutos), segundos(segundos), etiqueta(etiqueta)
{
}

Fecha::~Fecha()
{
}

// GETTERS

Fecha Fecha::getFechaActual()
{
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

unsigned int Fecha::getDia()
{
	return this->dia;
}

unsigned int Fecha::getMes()
{
	return this->mes;
}

unsigned int Fecha::getAnio()
{
	return this->anio;
}

unsigned int Fecha::getHoras()
{
    return this->horas;
}

unsigned int Fecha::getMinutos()
{
    return this->minutos;
}

unsigned int Fecha::getSegundos()
{
    return this->segundos;
}

std::string Fecha::getStringDia()
{
    char buffer[10];

    sprintf_s(buffer, "%02d", this->dia);

	return std::string(buffer);
}

std::string Fecha::getStringMes()
{
    char buffer[10];

    sprintf_s(buffer, "%02d", this->mes);

    return std::string(buffer);
}

std::string Fecha::getStringAnio()
{
    char buffer[10];

    sprintf_s(buffer, "%04d", this->anio);

    return std::string(buffer);
}

std::string Fecha::getStringHoras()
{
    char buffer[10];

    sprintf_s(buffer, "%02d", this->horas);

    return std::string(buffer);
}

std::string Fecha::getStringMinutos()
{
    char buffer[10];

    sprintf_s(buffer, "%02d", this->minutos);

    return std::string(buffer);
}

std::string Fecha::getStringSegundos()
{
    char buffer[10];

    sprintf_s(buffer, "%02d", this->segundos);

    return std::string(buffer);
}

std::string Fecha::getNombreMes()
{
    return nombres_meses[this->mes - 1];
}

std::string Fecha::getStringDDMMAAAA(std::string separador)
{
    return this->getStringDia() + separador + this->getStringMes() + separador + this->getStringAnio();
}

std::string Fecha::getStringAAAAMMDD(std::string separador)
{
    return this->getStringAnio() + separador + this->getStringMes() + separador + this->getStringDia();
}

std::string Fecha::getStringAAAAMMDDHHmmSS(std::string separador_dia, std::string separador_dia_hora, std::string separador_hora)
{
    return this->getStringAnio() + separador_dia + this->getStringMes() + separador_dia + this->getStringDia() + separador_dia_hora + this->getStringHoras() + separador_hora + this->getStringMinutos() + separador_hora + this->getStringSegundos();
}

std::string Fecha::getStringDDmesAAAA(std::string separador)
{
    return this->getStringDia() + separador + this->getNombreMes() + separador + this->getStringAnio();
}

// SETTERS

void Fecha::setDia(std::string dia)
{
	this->dia = std::stoi(dia);
}

void Fecha::setMes(std::string mes)
{
	this->mes = std::stoi(mes);
}

void Fecha::setAnio(std::string anio)
{
	this->anio = std::stoi(anio);
}

void Fecha::setHoras(std::string horas)
{
    this->horas = std::stoi(horas);
}

void Fecha::setMinutos(std::string minutos)
{
    this->minutos = std::stoi(minutos);
}

void Fecha::setSegundos(std::string segundos)
{
    this->segundos = std::stoi(segundos);
}

void Fecha::setDia(unsigned int dia)
{
	this->dia = dia;
}

void Fecha::setMes(unsigned int mes)
{
	this->mes = mes;
}

void Fecha::setAnio(unsigned int anio)
{
	this->anio = anio;
}

void Fecha::setHoras(unsigned int horas)
{
    this->horas = horas;
}

void Fecha::setMinutos(unsigned int minutos)
{
    this->minutos = minutos;
}

void Fecha::setSegundos(unsigned int segundos)
{
    this->segundos = segundos;
}

// METODOS

Fecha Fecha::parsearFormatoAAAAMMDD(std::string string_fecha, std::string separador)
{
    if (separador.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(string_fecha, separador);
    }
    
    if (8 != string_fecha.size())
    {
        return Fecha(0, 0, 0);
    }

    std::string string_anio = string_fecha.substr(0, 4);
    std::string string_mes = string_fecha.substr(4, 2);
    std::string string_dia = string_fecha.substr(6, 2);

    unsigned int anio = std::stoul(string_anio);
    unsigned int mes = std::stoul(string_mes);
    unsigned int dia = std::stoul(string_dia);
    
    if (mes > 12 || dia > 31)
    {
        return Fecha(0, 0, 0);
    }

    return Fecha(dia, mes, anio);
}

Fecha Fecha::parsearFormatoAAAAMMDDHHmmSS(std::string string_fecha, std::string separador_dia, std::string separador_dia_hora, std::string separador_hora)
{
    if (separador_dia.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(string_fecha, separador_dia);
    }

    if (separador_dia_hora.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(string_fecha, separador_dia_hora);
    }

    if (separador_hora.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(string_fecha, separador_hora);
    }

    if (14 != string_fecha.size())
    {
        return Fecha(0, 0, 0);
    }

    std::string string_anio = string_fecha.substr(0, 4);
    std::string string_mes = string_fecha.substr(4, 2);
    std::string string_dia = string_fecha.substr(6, 2);
    std::string string_horas = string_fecha.substr(8, 2);
    std::string string_minutos = string_fecha.substr(10, 2);
    std::string string_segundos = string_fecha.substr(12, 2);

    unsigned int anio = std::stoul(string_anio);
    unsigned int mes = std::stoul(string_mes);
    unsigned int dia = std::stoul(string_dia);
    unsigned int horas = std::stoul(string_horas);
    unsigned int minutos = std::stoul(string_minutos);
    unsigned int segundos = std::stoul(string_segundos);

    if (mes > 12 || dia > 31 || horas > 23 || minutos > 59 || segundos > 59)
    {
        return Fecha(0, 0, 0);
    }

    return Fecha(dia, mes, anio, horas, minutos, segundos);
}

Fecha Fecha::parsearFormatoDDmesAAAA(std::string string_fecha, std::string separador)
{
    if (separador.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(string_fecha, separador);
    }

    std::string string_dia = string_fecha.substr(0, 2);
    std::string string_mes = string_fecha.substr(2, string_fecha.size() - 6);
    std::string string_anio = string_fecha.substr(string_fecha.size() - 4, 4);

    unsigned int anio = std::stoul(string_anio);
    unsigned int mes = std::distance(nombres_meses.begin(), std::find(nombres_meses.begin(), nombres_meses.end(), string_mes)) + 1;
    unsigned int dia = std::stoul(string_dia);

    if (mes > 12 || dia > 31)
    {
        return Fecha(0, 0, 0);
    }

    return Fecha(dia, mes, anio);
}

Fecha Fecha::parsearFormatoDDMMAAAA(std::string string_fecha, std::string separador)
{
    if (separador.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(string_fecha, separador);
    }

    if (8 != string_fecha.size())
    {
        return Fecha(0, 0, 0);
    }

    std::string string_anio = string_fecha.substr(4, 4);
    std::string string_mes = string_fecha.substr(2, 2);
    std::string string_dia = string_fecha.substr(0, 2);

    unsigned int anio = std::stoul(string_anio);
    unsigned int mes = std::stoul(string_mes);
    unsigned int dia = std::stoul(string_dia);
    
    if (mes > 12 || dia > 31)
    {
        return Fecha(0, 0, 0);
    }

    return Fecha(dia, mes, anio);
}

// CONSULTAS

// OPERADORES

bool Fecha::operator<(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha < string_fecha_a_comparar;
}

bool Fecha::operator>(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha > string_fecha_a_comparar;
}

bool Fecha::operator<=(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha <= string_fecha_a_comparar;
}

bool Fecha::operator>=(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha >= string_fecha_a_comparar;
}

bool Fecha::operator==(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha == string_fecha_a_comparar;
}

bool Fecha::operator!=(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDDHHmmSS();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDDHHmmSS();

    return string_esta_fecha != string_fecha_a_comparar;
}