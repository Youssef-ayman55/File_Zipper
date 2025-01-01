#ifndef HUFFMAN_H
#define HUFFMAN_H
#include<string>
using namespace std;
class Node
{
public:
    char c;
    int freq;
    Node *left, *right;
    Node(char t, int f)
    {
        c = t;
        freq = f;
        left = right = nullptr;
    }
};
class Huffman_tree
{
private:
    Node *root;
    struct custom_comparator
    {
        bool operator()(Node *a, Node *b);
    };
    void generate_codes(Node *current, string s = "");

public:
    string huffman_codes[128] = {""};
    Huffman_tree(const int freq_arr[128]);
};

#endif