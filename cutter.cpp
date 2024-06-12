#include <iostream>
#include <vector>
#include <string>

// Funkcja dzieląca string na odcinki o podanej długości
std::vector<std::string> splitString(const std::string& str, std::size_t length) {
    std::vector<std::string> segments;
    
    for (std::size_t i = 0; i < str.size(); i += length) {
        segments.push_back(str.substr(i, length));
    }

    return segments;
}

int main() {
    std::string inputString;
    std::size_t segmentLength;

    // Wprowadzenie danych
    std::cout << "Wprowadź string: ";
    std::getline(std::cin, inputString);
    std::cout << "Wprowadź długość odcinka: ";
    std::cin >> segmentLength;

    // Dzielenie stringa
    std::vector<std::string> result = splitString(inputString, segmentLength);

    // Wyświetlanie wyników
    std::cout << "Pocięte odcinki:\n";
    for (const auto& segment : result) {
        std::cout << segment << std::endl;
    }

    return 0;
}
