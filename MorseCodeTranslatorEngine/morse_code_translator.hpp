/// @file
///
/// @author
///
/// @copyright

#ifndef MORSECODETRANSLATORENGINE_H
#define MORSECODETRANSLATORENGINE_H

#include <string>
#include <vector>
#include <morse_alphabet.hpp>

namespace morse_code_engine {

///
/// \brief The MorseCodeTranslator class
///
class MorseCodeTranslator {

public:
    ///
    /// \brief MorseCodeTranslator
    ///
    MorseCodeTranslator();

    ///
    /// \brief MorseCodeTranslator
    ///
    MorseCodeTranslator(MorseCodeTranslator const&) = delete;

    ///
    /// \brief MorseCodeTranslator
    ///
    MorseCodeTranslator(MorseCodeTranslator&&) = delete;

    ///
    ~MorseCodeTranslator() = default;

    ///
    /// \brief operator =
    /// \return
    ///
    MorseCodeTranslator& operator=(MorseCodeTranslator const&) = delete;

    ///
    /// \brief operator =
    /// \return
    ///
    MorseCodeTranslator& operator=(MorseCodeTranslator&&) = delete;

    ///
    /// \brief Char2Morse
    /// \param c
    /// \return
    ///
    std::string Char2Morse(char const c) const;

    ///
    /// \brief Morse2Char
    /// \param morse
    /// \return
    ///
    char Morse2Char(std::string const& morse) const;

    ///
    /// \brief Text2Morse
    /// \param text
    /// \return
    ///
    std::string Text2Morse(std::string const& text) const;

    ///
    /// \brief Morse2Text
    /// \param morse
    /// \return
    ///
    std::string Morse2Text(std::string const& morse) const;

private:
    ///
    /// \brief split
    /// \param text
    /// \return
    ///
    std::vector<std::string> split(const std::string& text) const;

private:
    ///
    /// \brief m_morse_alphabet
    ///
    MorseAlphabet m_morse_alphabet;
};

} // namespace morse_code_engine

#endif // MORSECODETRANSLATORENGINE_H
