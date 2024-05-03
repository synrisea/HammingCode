#include "coder.h"
#include "decoder.h"



int main()
{
    // B is 99 in Ascii table - 01100011

    char character = 'c'; 
    int number = 4; 

    std::bitset<16> hammingCode1 = generateHammingCode16(character);
    std::cout << "Hamming code for '" << character << "': " << hammingCode1 << std::endl;

    std::bitset<16> hammingCode2 = generateHammingCode16(number);
    std::cout << "Hamming code for '" << number << "': " << hammingCode2 << std::endl;

    try 
    {
        uint8_t decodedData1 = decodeHamming16(static_cast<uint16_t>(hammingCode1.to_ulong()));
        std::cout << "Decoded data from Hamming code: " << std::bitset<8>(decodedData1) << std::endl;

        uint8_t decodedData2 = decodeHamming16(static_cast<uint16_t>(hammingCode2.to_ulong()));
        std::cout << "Decoded data from Hamming code: " << std::bitset<8>(decodedData2) << std::endl;
    }
    catch (const NotFixableException& ex) 
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

