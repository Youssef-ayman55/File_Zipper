#include "Header.h"
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int Header::binary_to_decimal(string &in)
{
    int result = 0; // Resulting decimal value
    for (int i = 0; i < in.size(); i++)
        result = result * 2 + in[i] - '0'; // Convert binary to decimal
    return result;                         // Return the decimal result
}

string Header::decimal_to_binary(int in)
{
    string temp = "";   // Temporary binary string
    string result = ""; // Final binary string with leading zeros

    // Convert decimal to binary
    while (in > 0) {
        temp = to_string(in % 2) + temp; // Prepend binary digit
        in /= 2;                         // Divide by 2 for next iteration
    }

    // Add leading zeros to make the binary string 8 bits long
    int leadingZeros = 8 - temp.size();
    result.append(leadingZeros, '0'); // Append leading zeros
    result += temp;                   // Append the binary digits
    return result;                    // Return the binary string
}

Header::Header()
{
    header = "";
}

Header::Header(string huffman_codes[128])
{
    generateHeader(huffman_codes);
}

void Header::generateHeader(string huffman_codes[128])
{
    string tempHeader = ""; // Temporary header string
    unsigned char size = 0; // Size of the header

    // Iterate through all possible characters
    for (int i = 0; i < 128; i++) {
        if (huffman_codes[i].empty())
            continue;                                    // Skip empty codes
        tempHeader.push_back(i);                         // Add character to header
        tempHeader.push_back(huffman_codes[i].length()); // Add code length
        tempHeader += huffman_codes[i];                  // Add the actual Huffman code
        size++;                                          // Increment the size of the header
    }

    char size_char = size;           // Convert size to char
    header = size_char + tempHeader; // Construct the final header
}

string Header::getHeader()
{
    return header;
}

void Header::writeHeader(string &in)
{
    in += header[0]; // Add the size of the header
    int i = 1;       // Start index for reading the header

    // Loop through the header and write it to the output
    while (i < header.size()) {
        char ch = header[i];                 // Current character
        in += header[i];                     // Add character to output
        int codeSize = header[++i];          // Get size of the Huffman code
        in += codeSize;                      // Add code size to output
        int numBytes = ceil(codeSize / 8.0); // Calculate number of bytes needed
        int padd = numBytes * 8 - codeSize;  // Calculate padding needed
        string s = "";                       // Temporary string for binary code

        // Collect the binary code
        int j;
        for (j = i + 1; j <= i + codeSize; j++) {
            s += header[j]; // Append each bit
        }
        s += string(padd, '0'); // Append padding zeros

        // Convert the binary string to bytes and add to output
        for (int k = 0; k < numBytes; k++) {
            string byteStr = s.substr(k * 8, 8);     // Get each byte (8 bits)
            in += (char) binary_to_decimal(byteStr); // Convert to char and add to output
        }
        i = j; // Move index to the next character
    }
}

void Header::readHeader(ifstream &file, string huffman_codes[128])
{
    char headerSize;           // Variable to hold the size of the header
    file.read(&headerSize, 1); // Read the header size from file

    // Loop through each character in the header
    for (int i = 0; i < headerSize; i++) {
        char letter;           // Current character
        file.read(&letter, 1); // Read the character from file
        char letterCodeSize;   // Variable to hold the size of the Huffman code for the character
        file.read(&letterCodeSize, 1); // Read the size of the Huffman code

        // Calculate the number of bytes needed to store the code
        int numBytes = ceil(static_cast<unsigned char>(letterCodeSize) / 8.0);
        string binaryCode = ""; // String to hold the binary code

        // Read the bytes and convert them to a binary string
        for (int j = 0; j < numBytes; j++) {
            char byte;                              // Variable to hold each byte
            file.read(&byte, 1);                    // Read a byte from the file
            unsigned char byte1 = byte;             // Cast to unsigned char
            binaryCode += decimal_to_binary(byte1); // Convert byte to binary and append
        }

        // Trim the binary code to the correct length
        binaryCode = binaryCode.substr(0, letterCodeSize);
        huffman_codes[letter] = binaryCode; // Store the Huffman code for the character
    }
}
