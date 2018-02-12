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

Fecha::Fecha(std::string etiqueta) : dia(0), mes(0), anio(0), etiqueta(etiqueta)
{
}

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio, std::string etiqueta) : dia(dia), mes(mes), anio(anio), etiqueta(etiqueta)
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
    std::string string_esta_fecha = this->getStringAAAAMMDD();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDD();

    return string_esta_fecha < string_fecha_a_comparar;
}

bool Fecha::operator>(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDD();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDD();

    return string_esta_fecha > string_fecha_a_comparar;
}

bool Fecha::operator<=(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDD();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDD();

    return string_esta_fecha <= string_fecha_a_comparar;
}

bool Fecha::operator>=(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDD();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDD();

    return string_esta_fecha >= string_fecha_a_comparar;
}

bool Fecha::operator==(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDD();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDD();

    return string_esta_fecha == string_fecha_a_comparar;
}
