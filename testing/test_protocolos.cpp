// gtest
#include <gtest/gtest.h>

// cpprest
#include <cpprest/http_client.h>

// protocolos
#include <protocolos/include/OAuth2.h>

using namespace herramientas::protocolos;

std::string aBase64(std::string tira_de_bytes_como_string)
{
    uint32_t tamanio = tira_de_bytes_como_string.size() + 1;
    unsigned char* tira_bytes = new unsigned char[tamanio];

    strcpy_s(reinterpret_cast<char*>(tira_bytes), tamanio, tira_de_bytes_como_string.c_str());

    std::vector<unsigned char> vector_tira_de_bytes(tira_bytes, tira_bytes + tamanio - 1);

    utility::string_t bytes_decodificados = utility::conversions::to_base64(vector_tira_de_bytes);

    delete[] tira_bytes;

    return utility::conversions::to_utf8string(bytes_decodificados);
}

TEST(Protocolos, DISABLED_obtenerTokenDeAccesoCorrectamente)
{
    OAuth2Consumidor oauth2_consumidor_valido("aXPpXInb16k0jKIswOYuUS3ly", "MhuDBpN9EtnafrIUHvJEbleJ3WKiFCSBIulwRVNvZTWoXGs2eV");

    bool se_obtuvo_token_de_consumidor_valido = OAuth2::solicitarTokenAcceso(&oauth2_consumidor_valido, "https://api.twitter.com");

    ASSERT_EQ(true, se_obtuvo_token_de_consumidor_valido);
}