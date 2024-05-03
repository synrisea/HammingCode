#pragma once

#include <iostream>

struct NotFixableException : public std::runtime_error
{
	NotFixableException(const std::string& message);
};

uint8_t decodeHamming(uint8_t code);

uint8_t decodeHamming16(uint16_t code);

