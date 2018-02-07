#pragma once

// modelo
#include <utiles/include/Json.h>

namespace herramientas
{
namespace utiles
{

class IHashable
{
public:

    IHashable();
    virtual ~IHashable();

    virtual unsigned long long int hashcode() = 0;

    static unsigned long long int hashear(std::string string_a_hashear);

    static unsigned long long int hashear(unsigned int uint_a_hashear);

private:

    static std::hash<std::string> hasher_string;
    static std::hash<unsigned int> hasher_uint;

};

};
};

