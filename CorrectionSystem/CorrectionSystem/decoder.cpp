#include "decoder.h"


NotFixableException::NotFixableException(const std::string& message) : std::runtime_error(message) {}


uint8_t decodeHamming(uint8_t code)
{
    bool p1 = (code >> 0) & 0x1;
    bool d1 = (code >> 1) & 0x1;
    bool p2 = (code >> 2) & 0x1;
    bool d2 = (code >> 3) & 0x1;
    bool d3 = (code >> 4) & 0x1;
    bool p3 = (code >> 5) & 0x1;
    bool d4 = (code >> 6) & 0x1;

    bool s1 = p1 ^ d1 ^ d3 ^ d4;
    bool s2 = p2 ^ d1 ^ d2 ^ d4;
    bool s3 = p3 ^ d2 ^ d3 ^ d4;

    uint8_t errorPosition = s1 + (s2 << 1) + (s3 << 2);

    if (errorPosition == 0)
    {
        return (d1 + (d2 << 1) + (d3 << 2) + (d4 << 3));
    }
    else if (errorPosition >= 1 && errorPosition <= 7)
    {
        code ^= (1 << (errorPosition - 1));

        d1 = (code >> 1) & 0x1;
        d2 = (code >> 3) & 0x1;
        d3 = (code >> 4) & 0x1;
        d4 = (code >> 6) & 0x1;

        return (d1 + (d2 << 1) + (d3 << 2) + (d4 << 3));
    }
    else {
        throw NotFixableException("Error can not be fixed.");
    }
}


uint8_t decodeHamming16(uint16_t code)
{
    uint8_t highCode = (code >> 8);
    uint8_t lowCode = (code & 0xFF);

    uint8_t highData = decodeHamming(highCode);
    uint8_t lowData = decodeHamming(lowCode);

    return (highData << 4) | lowData;
}