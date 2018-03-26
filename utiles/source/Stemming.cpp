#include <utiles/include/Stemming.h>

// stl
#include <locale>
#include <codecvt>

using namespace herramientas::utiles;

stemming::spanish_stem<> Stemming::stem_spanish;

Stemming::Stemming()
{
}

Stemming::~Stemming()
{
}

void Stemming::stem(std::string & string_a_hashear)
{
    wchar_t * unicode_text_buffer = new wchar_t[string_a_hashear.length() + 1];
    std::wmemset(unicode_text_buffer, 0, string_a_hashear.length() + 1);
    std::mbstowcs(unicode_text_buffer, string_a_hashear.c_str(), string_a_hashear.length());
    std::wstring word = unicode_text_buffer;
    stem_spanish(word);

    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;

    string_a_hashear = conv.to_bytes(word);

    delete[] unicode_text_buffer;
}

void Stemming::stem(std::vector<std::string> & vector_de_string_a_stemmear)
{
    for (std::vector<std::string>::iterator it = vector_de_string_a_stemmear.begin(); it != vector_de_string_a_stemmear.end(); it++)
    {
        stem(*it);
    }
}
