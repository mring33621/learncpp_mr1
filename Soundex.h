// Soundex.h

#ifndef MATTRINGXYZ_SOUNDEX_H  // Include guards to prevent multiple inclusions
#define MATTRINGXYZ_SOUNDEX_H

#include <string>

// Declare the namespace
namespace mattringxyz {

    // Declare the static method
    std::string calcSoundex(const std::string& word);

}  // namespace mattringxyz

#endif // MATTRINGXYZ_SOUNDEX_H
