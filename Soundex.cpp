// Soundex.cpp

#include "Soundex.h"

#include <algorithm>
#include <iostream>
#include <unordered_map>

// Define the static method
namespace mattringxyz {
    std::string calcSoundex(const std::string &word) {
        // Convert word parameter to uppercase
        std::string upperWord = word;
        std::transform(upperWord.begin(), upperWord.end(), upperWord.begin(), ::toupper);

        // Define a mapping of characters to their Soundex digits
        const std::unordered_map<char, char> soundexMap = {
            {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
            {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
            {'D', '3'}, {'T', '3'},
            {'L', '4'},
            {'M', '5'}, {'N', '5'},
            {'R', '6'}
        };

        // Keep the first letter
        char firstLetter = upperWord[0];

        // Initialize the Soundex code with the first letter
        std::string soundexCode(1, firstLetter);

        // Iterate through the remaining characters and replace them with Soundex digits
        for (size_t i = 1; i < upperWord.length(); ++i) {
            char currentChar = upperWord[i];

            // If the character is in the mapping table, replace it with the corresponding digit
            if (soundexMap.find(currentChar) != soundexMap.end()) {
                char soundexDigit = soundexMap.at(currentChar);

                // Avoid duplicate digits
                if (soundexDigit != soundexCode.back()) {
                    soundexCode += soundexDigit;
                }
            }
        }

        // Pad or truncate the Soundex code to have a length of 4
        soundexCode.resize(4, '0');

        return soundexCode;
    }
} // namespace mattringxyz
