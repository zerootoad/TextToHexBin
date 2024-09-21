#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

string decimalToBinary(int decimal)
{
    return std::bitset<8>(decimal).to_string();
}

int binaryToDecimal(string binary)
{
    return std::bitset<8>(binary).to_ulong();
}

string convert(string str, bool reverse = false)
{
    vector<int> asciiChars;
    vector<string> binaryBytes;

    if (!reverse)
    {
        string binaryString;
        for (char character : str)
        {
            int charAscii = character;
            asciiChars.emplace_back(charAscii);

            string binaryByte = decimalToBinary(charAscii);
            binaryString.append(binaryByte + " ");

            // std::cout << asciiChars.size() - 1 << ". " << character << " | " << charAscii << " | " << binaryByte << std::endl;
        }

        return binaryString;
    }
    else
    {
        string tempString;
        for (char character : str)
        {
            if (character != ' ')
                tempString += character;
        }

        string tempChunk;
        for (int i = 0; i + 1 < tempString.length(); i += 8)
        {
            tempChunk = tempString.substr(i, 8);
            binaryBytes.emplace_back(tempChunk);
        }

        string sequence;
        for (string byte : binaryBytes)
        {
            char c = binaryToDecimal(byte);
            // std::cout << byte << " | " << c << std::endl;
            sequence += c;
        }

        return sequence;
    }
}

int main()
{
    string stringa;
    string opt;
    bool reversa;

    std::cout << "Input some text: ";
    std::cin >> stringa;
    std::cout << std::endl;

    std::cout << "Are you tryna reverse binary to text? [y/n]: ";
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
