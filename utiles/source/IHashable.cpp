#include <utiles/include/IHashable.h>

using namespace herramientas::utiles;

std::hash<std::string> IHashable::hasher_string;
std::hash<uint32_t> IHashable::hasher_uint;

IHashable::IHashable()
{
}

IHashable::~IHashable()
{
}

uint64_t IHashable::hashear(std::string string_a_hashear)
{
    return hasher_string(string_a_hashear);
}

uint64_t IHashable::hashear(uint32_t uint_a_hashear)
{
    return hasher_uint(uint_a_hashear);
}

