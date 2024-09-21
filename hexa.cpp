#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

string decimalToHex(int decimal)
{
    std::stringstream hexStream;
    hexStream << std::hex << decimal;
    return hexStream.str();
}

int hexToDecimal(string hex)
{
    int decimal;
    std::stringstream hexStream;
    hexStream << hex;
    hexStream >> std::hex >> decimal;
    return decimal;
}

string stringToUpper(string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}

string convert(string str, bool reverse = false)
{
    vector<int> asciiChars;
    vector<string> hexBytes;

    if (!reverse)
    {
        string hexString;
        for (char character : str)
        {
            int charAscii = character;
            asciiChars.emplace_back(charAscii);

            string hexValue = decimalToHex(charAscii);
            if (hexValue.length() == 1)
                hexValue = "0" + hexValue;
            hexString.append(hexValue);
        }

        return stringToUpper(hexString);
    }
    else
    {
        string tempChunk;
        for (int i = 0; i + 1 < str.length(); i += 2)
        {
            tempChunk = str.substr(i, 2);
            hexBytes.emplace_back(tempChunk);
        }

        string sequence;
        for (string chunk : hexBytes)
        {
            char c = hexToDecimal(chunk);
            sequence += c;
        }

        return sequence;
    }

    return " ";
}

int main()
{
    string stringa;
    string opt;
    bool reversa;

    std::cout << "Input some text: ";
    std::cin >> stringa;
    std::cout << std::endl;

    std::cout << "Are you tryna reverse hexadecimal to text? [y/n]: ";
    std::cin >> opt;

    if (opt == "y" || opt == "Y" || opt == "Yes")
    {
        reversa = true;
    }
    else
    {
        reversa = false;
    }

    std::cout << std::endl;

    std::cout << convert(stringa, reversa) << std::endl;
}
