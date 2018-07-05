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

    virtual uint64_t hashcode() = 0;

    static uint64_t hashear(std::string string_a_hashear);

    static uint64_t hashear(uint32_t uint_a_hashear);

private:

    static std::hash<std::string> hasher_string;
    static std::hash<uint32_t> hasher_uint;

};

};
};

