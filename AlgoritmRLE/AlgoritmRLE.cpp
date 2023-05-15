#include <iostream>
#include <string>
#include <fstream>

std::string compressRLE(std::string str) {
    std::string compressed = "";
    int count = 1;
    char current = str[0];
    std::cout << "Original length: " << str.size() << std::endl;

    for (int i = 1; i <= str.size(); i++) {
        if (str[i] != current) {
            compressed += std::to_string(count) + current;
            count = 1;
            current = str[i];
        }
        else {
            count++;
        }
    }

    return compressed;
}

int main() {
    std::string data;

    std::ifstream fin("input.txt");
    fin >> data;

    std::string compressed = compressRLE(data);
    std::cout << "Compressed: " << compressed << std::endl;
    std::cout << "Original length: " << compressed.size() << std::endl;
    fin.close();
    return 0;
}