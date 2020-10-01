/// @file
///
/// @author
///
/// @copyright

#ifndef MORSE_ALPHABET_HPP
#define MORSE_ALPHABET_HPP

#include <string>
#include <unordered_map>
#include <vector>

namespace morse_code_engine {

///
/// \brief The MorseAlphabet class
///
class MorseAlphabet {
public:
    ///
    /// \brief MorseAlphabet
    ///
    MorseAlphabet();

    ///
    ~MorseAlphabet() = default;

    ///
    /// \brief operator []
    /// \param c
    /// \return
    ///
    const std::string& operator[](char c) const;

    ///
    /// \brief operator []
    /// \param morse_code
    /// \return
    ///
    char operator[](const std::string& morse_code) const;

private:
    ///
    /// \brief BuildSearchTree
    ///
    void BuildSearchTree();

    ///
    /// \brief IndexOf
    /// \param morse_code
    /// \return
    ///
    size_t IndexOf(const std::string& morse_code) const;

private:
    ///
    /// \brief m_morse_codes
    ///
    const std::unordered_map<char, std::string> m_morse_codes;
    ///
    /// \brief m_search_tree
    ///
    std::vector<char> m_search_tree;
};

} // namespace morse_code_engine

#endif // MORSE_ALPHABET_HPP
