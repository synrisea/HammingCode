#include "coder.h"

uint16_t calculateHammingCode4(uint8_t b)
{
    bool d1 = (b >> 0) & 0x1;
    bool d2 = (b >> 1) & 0x1;
    bool d3 = (b >> 2) & 0x1;
    bool d4 = (b >> 3) & 0x1;


    bool p1 = d1 ^ d3 ^ d4;
    bool p2 = d1 ^ d2 ^ d4;
    bool p3 = d2 ^ d3 ^ d4;
    bool p4 = d1 ^ d2 ^ d3 ^ d4 ^ p1 ^ p2 ^ p3;

    uint16_t hamming = (p1 << 0) | (d1 << 1) | (p2 << 2) |
        (d2 << 3) | (d3 << 4) | (p3 << 5) |
        (d4 << 6) | (p4 << 7);

    return hamming;
}

std::bitset<16> generateHammingCode16(uint8_t byte)
{
    uint8_t lowNibble = byte & 0xF;
    uint8_t highNibble = (byte >> 4);

    uint16_t hammingLow = calculateHammingCode4(lowNibble);
    uint16_t hammingHigh = calculateHammingCode4(highNibble) << 8;

    uint16_t hammingCombined = hammingLow | hammingHigh;

    return std::bitset<16>(hammingCombined);
}