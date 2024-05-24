#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Function to generate a random string of given length
std::string generateRandomString(int length) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyz";
    std::string randomString;
    for (int i = 0; i < length; ++i) {
        randomString += characters[std::rand() % characters.size()];
    }
    return randomString;
}

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Define the file name
    std::string fileName = "random_strings.txt";

    // Open the file in write mode
    std::ofstream outFile(fileName);

    // Check if the file is open
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return 1;
    }

    // Define the number of random strings and the length of each string
    const int numRandomStrings = 100;
    const int lengthOfString = 10;

    // Generate and write random strings to the file
    for (int i = 0; i < numRandomStrings; ++i) {
        std::string randomString = generateRandomString(lengthOfString);
        outFile << randomString << std::endl;
    }

    // Close the file
    outFile.close();

    std::cout << "Random strings have been written to " << fileName << std::endl;

    return 0;
}
