/// @file
///
/// @author
///
/// @copyright

#include "morse_code_translator.hpp"

namespace morse_code_engine {

MorseCodeTranslator::MorseCodeTranslator() : m_morse_alphabet{} {}

std::string MorseCodeTranslator::Char2Morse(const char c) const
{
    return m_morse_alphabet[c];
}

char MorseCodeTranslator::Morse2Char(const std::string& morse) const
{
    return m_morse_alphabet[morse];
}

std::string MorseCodeTranslator::Text2Morse(const std::string& text) const
{
    std::string morse_text;
    for (auto c : text) {
        if (c != ' ') {
            morse_text += Char2Morse(c);
        }
        morse_text += ' ';
    }
    if (!morse_text.empty()) {
        morse_text.erase(morse_text.size() - 1);
    }
    return morse_text;
}

std::string MorseCodeTranslator::Morse2Text(const std::string& morse) const
{
    std::string result;
    auto tokens = split(morse);
    for (auto& token : tokens) {
        if (token.empty()) {
            result += " ";
        }
        else {
            result += Morse2Char(token);
        }
    }
    return result;
}

std::vector<std::string> MorseCodeTranslator::split(const std::string& text) const
{
    std::vector<std::string> result;
    size_t pos = 0, new_pos = 0;
    for (; (new_pos = text.find(' ', pos)) != std::string::npos;) {
        result.emplace_back(text.substr(pos, new_pos - pos));
        pos = new_pos + 1;
    }
    if (pos < text.size()) {
        result.emplace_back(text.substr(pos));
    }
    return result;
}

} // namespace morse_code_engine
