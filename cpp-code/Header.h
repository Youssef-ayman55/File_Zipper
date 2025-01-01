#ifndef HEADER_H
#define HEADER_H
#include <fstream>
#include <string>

using namespace std;

// Class to manage the header for Huffman coding
class Header
{
private:
    string header; // Holds the constructed header string

    // Converts a binary string to a decimal integer
    int binary_to_decimal(string &in);

    // Converts a decimal integer to a binary string
    string decimal_to_binary(int in);

public:
    // Default constructor initializes an empty header
    Header();

    // Constructor that generates the header from Huffman codes
    Header(string huffman_codes[128]);

    // Generates the header based on the provided Huffman codes
    void generateHeader(string huffman_codes[128]);

    // Returns the constructed header
    string getHeader();

    // Writes the header to the output string
    void writeHeader(string &in);

    // Reads the header from a file and populates the Huffman codes
    void readHeader(ifstream &file, string huffman_codes[128]);
};

#endif HEADER_H
