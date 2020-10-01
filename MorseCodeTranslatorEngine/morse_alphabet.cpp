/// @file
///
/// @author
///
/// @copyright

#include "morse_alphabet.hpp"
#include <cctype>
#include <cmath>

namespace morse_code_engine {

MorseAlphabet::MorseAlphabet()
    : m_morse_codes{
          {'a', ".-"},     {'b', "-..."},    {'c', "-.-."},   {'d', "-.."},    {'e', "."},
          {'f', "..-."},   {'g', "--."},     {'h', "...."},   {'i', ".."},     {'j', ".---"},
          {'k', "-.-"},    {'l', ".-.."},    {'m', "--"},     {'n', "-."},     {'o', "---"},
          {'p', ".--."},   {'q', "--.-"},    {'r', ".-."},    {'s', "..."},    {'t', "-"},
          {'u', "..-"},    {'v', "...-"},    {'w', ".--"},    {'x', "-..-"},   {'y', "-.--"},
          {'z', "--.."},   {'1', ".----"},   {'2', "..---"},  {'3', "...--"},  {'4', "....-"},
          {'5', "....."},  {'6', "-...."},   {'7', "--..."},  {'8', "---.."},  {'9', "----."},
          {'0', "-----"},  {'.', ".-.-.-"},  {',', "--..--"}, {'?', "..--.."}, {'\'', ".----."},
          {'!', "-.-.--"}, {'/', "-..-."},   {'(', "-.--."},  {')', "-.--.-"}, {'&', ".-..."},
          {':', "---..."}, {';', "-.-.-."},  {'=', "-...-"},  {'+', ".-.-."},  {'-', "-....-"},
          {'_', "..--.-"}, {'\"', ".-..-."}, {'@', ".--.-."}}
{
    BuildSearchTree();
}

const std::string& MorseAlphabet::operator[](char c) const
{
    try {
        return m_morse_codes.at(std::tolower(static_cast<unsigned char>(c)));
    }
    catch (std::out_of_range) {
        throw std::invalid_argument{"Unsupported character"};
    }
}

char MorseAlphabet::operator[](const std::string& morse_code) const
{
    size_t index = IndexOf(morse_code);
    if (m_search_tree[index] == 0 || index >= m_search_tree.size()) {
        throw std::invalid_argument{"Unsupported Morse code"};
    }
    return m_search_tree[index];
}

void MorseAlphabet::BuildSearchTree()
{
    // Maximum binary tree depth
    const size_t tree_depth = 7;
    m_search_tree.resize(std::pow(2, tree_depth));
    for (auto& pair : m_morse_codes) {
        size_t index = IndexOf(pair.second);
        m_search_tree[index] = pair.first;
    }
}

size_t MorseAlphabet::IndexOf(const std::string& morse_code) const
{
    size_t index = 0;
    for (auto c : morse_code) {
        if (c == '.') {
            index = 2 * index + 1;
        }
        else if (c == '-') {
            index = 2 * index + 2;
        }
        else {
            throw std::invalid_argument{"Invalid Morse code input character"};
        }
    }
    return index;
}

} // namespace morse_code_engine
