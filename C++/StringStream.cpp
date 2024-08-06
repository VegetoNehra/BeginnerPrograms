#include <iostream>
#include <sstream>

int main() {
    // Writing to a stringstream
    std::stringstream ss;
    ss << "The number is " << 42 << " and the string is " << "hello";

    // Reading from a stringstream
    std::string part1, part2;
    int number;
    ss >> part1 >> number >> part2;
    
    std::cout << "Part1: " << part1 << std::endl;
    std::cout << "Number: " << number << std::endl;
    std::cout << "Part2: " << part2 << std::endl;

    // Getting the entire string
    std::string fullString = ss.str();
    std::cout << "Full String: " << fullString << std::endl;

    return 0;
}
