#include <iostream>
#include "Huffman.h"
#include <fstream>
#include "Header.h"

// Function to build a Huffman Tree from the content of a file
// and store the original text for compression.
Huffman_tree* readFromFile(ifstream& file, string& originalText) {
    if (!file) {
        cerr << "Failed to open the file.\n";
        return NULL;
    }

    char byte;
    int freq_arr[128] = {0}; // Array to store frequency of each character

    // Read the file content and count character frequencies
    while (file.get(byte)) {
        originalText += byte;
        freq_arr[int(byte)]++;
    }

    // Create Huffman Tree using character frequencies
    Huffman_tree* huffman = new Huffman_tree(freq_arr);

    file.close();
    return huffman;
}

// Function to convert a binary string to its decimal equivalent
int binary_to_decimal(string& in) {
    int result = 0;
    for (int i = 0; i < in.size(); i++)
        result = result * 2 + in[i] - '0'; // Calculate decimal value iteratively
    return result;
}

// Function to convert a decimal number to an 8-bit binary string
string decimal_to_binary(int in) {
    string temp = "";
    string result = "";

    while (in > 0) {
        temp = to_string(in % 2) + temp; // Get binary digits
        in /= 2;
    }

    // Pad with leading zeros to make it 8 bits
    int leadingZeros = 8 - temp.size();
    result.append(leadingZeros, '0');

    for (int i = 0; i < temp.size(); i++) {
        result += temp[i];
    }

    return result;
}

// Function to encode text using Huffman codes
void encodeText(string& in, const string& originalText, string huffman_codes[128]) {
    string s = ""; // Temporary string to hold binary data

    for (auto& byte : originalText) {
        int idx = int(byte);
        if(idx >= 0 && idx < 128) { // if the indxe is in valid ASCII range [0,127]
            s += huffman_codes[int(byte)]; // Append Huffman code for each character
        }

        // Write bytes to the output when we have at least 8 bits
        while (s.size() >= 8) {
            string byteStr = s.substr(0, 8);
            in += (char)binary_to_decimal(byteStr); // Convert to character
            s = s.substr(8); // Remove processed bits
        }
    }

    // Handle remaining bits
    int count = s.size() > 0 ? 8 - s.size() : 0;
    if (s.size() > 0) {
        s.append(count, '0'); // Pad remaining bits with zeros
        in += (char)binary_to_decimal(s); // Add to output
    }
    in += (char)count; // Store padding size
}

// Function to compress a text file using Huffman encoding
string compressFile(string fileIn) {
    int index = fileIn.rfind(".");
    if (index != string::npos && fileIn.substr(index + 1) != "txt") {
        cout << "The file is not a text file.\n";
        return "";
    }

    string fileOut = fileIn.substr(0, index) + "_compressed.hassan";
    ifstream file(fileIn, ios::binary);
    ofstream output(fileOut, ios::binary);

    if (!file || !output) {
        cerr << "Failed to open the file.\n";
        return "";
    }

    if (file.peek() == ifstream::traits_type::eof()) {
        cout << "The file is empty.\n";
        return "";
    }

    string originalText = "";
    Huffman_tree* huffman = readFromFile(file, originalText);
    if (huffman == NULL) {
        cout << "Failed to create the Huffman tree.\n";
        return "";
    }

    cout << "**** During Compression ******\n";

    cout << "Size of the original file: " << originalText.size() << endl;

    Header h(huffman->huffman_codes);
    string in = "";
    h.writeHeader(in);

    cout << "Size of the header: " << in.size() << endl;

    encodeText(in, originalText, huffman->huffman_codes);

    cout << "Size of the compressed file: " << in.size() << endl;
    output.write(in.c_str(), in.size());

    file.close();
    output.close();
    string re = to_string((originalText.size() / 1024.0)) + "KB --> " + to_string((in.size() / 1024.0)) + "KB";
    return re;
}

// Helper function to find the character corresponding to a Huffman code
int linearSearchKey(string val, string huffman_codes[128]) {
    for (int i = 0; i < 128; i++) {
        if (huffman_codes[i] == val) return i;
    }
    return -1;
}

// Function to decode a compressed text using Huffman codes
string decodeText(string huffman_codes[128], const string& codedText) {
    size_t i = 0;
    string decodedText = "";
    while (i < codedText.size()) {
        string current = "";
        size_t j;
        for (j = i; j < codedText.size(); j++) {
            current += codedText[j];
            int idx = linearSearchKey(current, huffman_codes);
            if (idx != -1) {
                decodedText += char(idx); // Append decoded character
                break;
            }
        }
        i = j + 1;
    }

    return decodedText;
}

// Function to retrieve the coded content of a compressed file
string getCodedContent(ifstream& fileIn) {
    string fileContent;
    char byte;

    // Read all bytes from the file
    while (fileIn.get(byte)) {
        fileContent += byte;
    }

    int paddSize = fileContent.back(); // Padding size
    string codedText;

    for (int i = 0; i < fileContent.size() - 1; i++) {
        unsigned char byte1 = fileContent[i];
        string byteStr = decimal_to_binary(byte1); // Convert byte to binary
        codedText += byteStr;
    }

    // Remove padding bits
    codedText = codedText.substr(0, codedText.size() - paddSize);

    return codedText;
}

// Function to decompress a file encoded with Huffman compression
string decompressFile(string fileIn) {
    int index = fileIn.rfind(".");
    if (index != string::npos && fileIn.substr(index + 1) != "hassan") {
        cout << "The file is not a hassan file.\n";
        return "";
    }

    string fileOut = fileIn.substr(0, index) + "_original.txt";
    ofstream output(fileOut, ios::binary);
    ifstream file(fileIn, ios::binary);

    if (!file || !output) {
        cerr << "Failed to open the file.\n";
        return "";
    }

    if (file.peek() == ifstream::traits_type::eof()) {
        cout << "The file is empty.\n";
        return "";
    }

    Header* h;
    string huffman_codes[128];

    h->readHeader(file, huffman_codes);
    cout << "** During Decompression **\n";

    string codedText = getCodedContent(file);


    string decodedText = decodeText(huffman_codes, codedText);


    output.write(decodedText.c_str(), decodedText.size());

    file.close();

    // find compressed file size
    file.open(fileIn, ios::binary);
    file.seekg(0, std::ios::end);
    streampos fileInSize = file.tellg();
    cout << fileInSize << endl;
    // find decompressed file size
    streampos fileOutSize = output.tellp();
    cout << fileOutSize << endl;

    file.close();
    output.close();
    string re = to_string((fileInSize / 1024.0)) + "KB --> " + to_string((fileOutSize / 1024.0)) + "KB";
    return re;
}
