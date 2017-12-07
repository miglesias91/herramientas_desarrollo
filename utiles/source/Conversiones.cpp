#include <utiles/include/Conversiones.h>

// cpprest
#include <cpprest/http_client.h>
#include <cpprest/oauth2.h>

using namespace herramientas::utiles;

Conversiones::Conversiones()
{
}

Conversiones::~Conversiones()
{
}

std::string Conversiones::string2base64(std::string tira_de_bytes_como_string)
{
    unsigned int tamanio = tira_de_bytes_como_string.size() + 1;
    unsigned char* tira_bytes = new unsigned char[tamanio];

    strcpy_s(reinterpret_cast<char*>(tira_bytes), tamanio, tira_de_bytes_como_string.c_str());

    std::vector<unsigned char> vector_tira_de_bytes(tira_bytes, tira_bytes + tamanio - 1);

    utility::string_t bytes_decodificados = utility::conversions::to_base64(vector_tira_de_bytes);

    return utility::conversions::to_utf8string(bytes_decodificados);
}
