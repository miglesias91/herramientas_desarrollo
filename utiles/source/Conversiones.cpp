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

std::string herramientas::utiles::Conversiones::utf82iso8859_1(std::string a_convertir)
{
    std::string out;

    const char * in = a_convertir.c_str();
    if (in == NULL)
        return out;

    unsigned int codepoint;
    while (*in != 0)
    {
        unsigned char ch = static_cast<unsigned char>(*in);
        if (ch <= 0x7f)
            codepoint = ch;
        else if (ch <= 0xbf)
            codepoint = (codepoint << 6) | (ch & 0x3f);
        else if (ch <= 0xdf)
            codepoint = ch & 0x1f;
        else if (ch <= 0xef)
            codepoint = ch & 0x0f;
        else
            codepoint = ch & 0x07;
        ++in;
        if (((*in & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
        {
            if (codepoint <= 255)
            {
                out.append(1, static_cast<char>(codepoint));
            }
            else
            {
                // do whatever you want for out-of-bounds characters
            }
        }
    }
    return out;
}
