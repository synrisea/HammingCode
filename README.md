# Hamming Code (8, 4) in C++

This project demonstrates encoding and decoding data using the Hamming Code (8, 4). It includes:

- An encoding function that converts an 8-bit value into a 16-bit Hamming code.
- A decoding function that takes a 16-bit Hamming code and attempts to recover the original 8-bit value, with error correction.


## Table of Contents
- [Hamming Code (8, 4)](#hamming-code-84)
- [Encoding Function](#encoding-function)
- [Decoding Function](#decoding-function)
- [Usage](#usage)
- [Example Output](#example-output)

## Hamming Code (8, 4)

Hamming Code (8, 4) is a method of encoding that allows for error detection and correction. It uses 8 bits of data and adds 8 bits of parity, resulting in a 16-bit Hamming code. This allows for correcting one error in each 8-bit block and detecting multiple errors.

## Encoding Function

The `generateHammingCode16(uint8_t byte)` function takes an 8-bit byte and returns a 16-bit Hamming code. The process includes:

- Splitting the 8-bit byte into two 4-bit values.
- Applying the Hamming Code (7, 4) to each 4-bit value.
- Combining the two 7-bit results to create a 16-bit Hamming code.

## Decoding Function

The `decodeHamming16(uint16_t code)` function takes a 16-bit Hamming code and attempts to recover the original 8-bit byte with error correction. The process includes:

- Splitting the 16-bit Hamming code into two 7-bit blocks.
- Decoding each block to recover the original 4-bit data.
- If there's an error, it attempts to correct it. If the error cannot be corrected, it throws a NotFixableException.

## Usage

To use this project:

- Compile the C++ code with a compiler like g++ or clang++.
- Run the compiled application to see an example of encoding and decoding using the Hamming Code.

## Example Output

The example output demonstrates the encoding and decoding process using the Hamming Code (8, 4). If an error cannot be corrected, the appropriate message is displayed.

~~~
B : 01000010
Hamming code for 'B': 11010011 10101000
Decoded data from Hamming code: 01000010
~~~
In this example:

- The ASCII character B is represented in its 8-bit binary form.
- The Hamming code for B is displayed as a 16-bit binary value.
- The original 8-bit value B is successfully decoded from the 16-bit Hamming code.
