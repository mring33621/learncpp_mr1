#include <algorithm>
#include <iostream>
#include <list>
#include "Soundex.h"

void printList(const std::list<std::string>& someList) {
    for (auto &it: someList) {
        std::cout << it << std::endl;
    }
}

void printArray(const std::string someArray[], int len) {
    for (int i = 0; i < len; i++) {
        std::cout << someArray[i] << std::endl;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    // print a blank line
    std::cout << "\nBasic array of names" << std::endl;

    // create an array of strings
    std::string names[7] = {"Scooby", "Shaggy", "Captain Cutler", "Velma", "Fred", "Daphne", "Mr. Hyde"};
    // print the length of the array
    std::cout << "The length of the array is: " << std::size(names) << std::endl;
    // print each name in the array
    printArray(names, 7);

    std::cout << "\nSorted array of names, alphabetical" << std::endl;

    // sort the list alphabetically
    std::sort(names, names + 7);
    // print each name in the array
    printArray(names, 7);

    std::cout << "\nSorted array of names, by length" << std::endl;

    // sort the array by name length (shortest to longest)
    std::sort(names, names + 7, [](const std::string& a, const std::string& b) { return a.length() < b.length(); });
    // print each name in the array
    printArray(names, 7);

    // print a blank line
    std::cout << "\nBasic list of names" << std::endl;

    // put the names into a list
    std::list<std::string> nameList;
    for (const auto & name : names) {
        nameList.push_back(name);
    }
    std::cout << "The length of the list is: " << std::size(nameList) << std::endl;
    //print the list
    printList(nameList);

    // print a blank line
    std::cout << "\nList of names with villians removed" << std::endl;

    // some names are heros and others villains
    // the villians are names that contain "Mr." or "Captain"
    // remove the villians from the list
    nameList.remove_if([](const std::string& a) {
        return a.find("Mr.") != std::string::npos || a.find("Captain") != std::string::npos;
    });

    // print the list
    printList(nameList);

    // print a blank line
    std::cout << "\nSoundex attempt:" << std::endl;

    std::string input = "Loscher";
    // Call the calcSoundex() function from the mattringxyz namespace
    std::string soundexResult = mattringxyz::calcSoundex(input);
    // print the input and result
    std::cout << "Input: " << input << std::endl;
    std::cout << "Result: " << soundexResult << std::endl;

    return 0;
}
