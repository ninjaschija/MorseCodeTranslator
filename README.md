# MorseCodeTranslator

Simple bi-directional Morse code translator using QT.

## Implementation

The translation from English characters to Morse codes is ensured by a standard unordered map. The inverse translation is performed by building a binary search tree based on the (extended) Morse alphabet, inspired by the binary tree used in Huffman compression.  
The tree nodes contain the English alphabet. All branches from the left side of any node correspond to a dot, where all right branches correspond to a dash. When a Morse code character is translated, each dot or dash help navigate through the binary tree towards the corresponding English character.

## Interface
The interface is simple and consists ot two text areas where the user can input English text / Morse code and the translation is performed in the real time.
