#pragma once

// stl
#include <iostream>
#include <sstream>
#include <string>
#include <exception>

namespace herramientas
{
namespace utiles
{
namespace excepciones
{

/// \brief Excepcion generica. IMPLEMENTACIÓN TOMADA DEL P3D.
class Excepcion : public std::exception
{
public:
    /// \brief Constructor
    Excepcion();

    /// \brief Constructor
    /// \param[in] desc string con una descripcion
    explicit Excepcion(const std::string& desc);

    /// \brief Constructor de copia
    /// \param[in] e Excepcion a copiar
    Excepcion(const Excepcion& e);

    /// \brief Redefinicion de std::exception::what
    virtual const char* what() const throw()
    {
        return this->mensaje.str().c_str();
    }

    /// \brief Operador de asignacion
    /// \param[in] e Excepcion para asignar
    /// \return Devuelve la excepcion asignada
    Excepcion& operator = (const Excepcion& e);

    /// \brief Destructor
    virtual ~Excepcion();

    /// \brief Getter para obtener el mensaje de la excepcion
    /// \return Devuelve un stringstream con el mensaje
    virtual const std::stringstream& getMensaje() const;

    /// \brief Operador << para Excepcion
    /// \param[in] os ostream para volcar el contenido
    /// \param[in] e Excepcion para mostrar
    /// \return Devuelve un ostream con el contenido de la excepcion
    friend std::ostream& operator << (std::ostream& os, const Excepcion& e)
    {
        // SC SKIP #N007
        os << e.descripcion.str() << std::endl;
        // SC SKIP #A018
        os << e.mensaje.str() << std::endl;
        // SC SKIP #A018
        return os;
    };

    /// \brief Operador << para string de tipo char*
    /// \param[in] s String de char*
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (char* s);

    /// \brief Operador << para std::string
    /// \param[in] s string
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (std::string& s);

    /// \brief Operador << para bool
    /// \param[in] n valor bool
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (bool n);

    /// \brief Operador << para short
    /// \param[in] n valor short
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (short n);

    /// \brief Operador << para unsigned short
    /// \param[in] n valor unsigned short
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (unsigned short n);

    /// \brief Operador << para int
    /// \param[in] n valor int
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (int n);

    /// \brief Operador << para unsigned int
    /// \param[in] n valor unsigned int
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (unsigned int n);

    /// \brief Operador << para long
    /// \param[in] n valor long
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (long n);

    /// \brief Operador << para unsigned long
    /// \param[in] n valor unsigned long
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (unsigned long n);

    /// \brief Operador << para float
    /// \param[in] n valor float
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (float n);

    /// \brief Operador << para double
    /// \param[in] n valor double
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator << (double n);

    /// \brief Operador << para long double
    /// \param[in] n valor long double
    /// \return Devuelve un stringstream con el parametro de entrada agregado
    std::stringstream& operator  <<  (long double n);

protected:
    /// \brief Descripcion de la excepcion
    std::stringstream descripcion;

    /// \brief Mensaje complementario de la descripcion
    std::stringstream mensaje;
};

};
};
};