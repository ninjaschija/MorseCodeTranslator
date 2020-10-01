/// @file
///
/// @author
///
/// @copyright

#include <iostream>
#include <morse_code_translator.hpp>

using namespace std;

int main()
{
    morse_code_engine::MorseCodeTranslator translator;

    std::string input = "hello there, general Kenobi!";
    std::string morse = translator.Text2Morse(input);
    std::cout << input << " = [" << morse << "]\n";
    std::cout << morse << " = [" << translator.Morse2Text(morse) << "]\n";

    return 0;
}
