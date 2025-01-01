#include "Huffman.h"
#include "HPQ.h"
#include "HVector.h"
#include <queue>
using namespace std;

bool Huffman_tree::custom_comparator::operator()(Node *a, Node *b)
{
    return a->freq > b->freq; // Min-heap based on frequency
}
void Huffman_tree::generate_codes(Node *current, string s)
{
    if (current == NULL)
        return;
    if (current->c != 127)
        huffman_codes[int(current->c)] = s;
    generate_codes(current->left, s + '0');
    generate_codes(current->right, s + '1');
}

Huffman_tree::Huffman_tree(const int freq_arr[128])
{
    Node *top, *left, *right;

    HPQ<Node *, custom_comparator> q;
    for (int i = 0; i < 128; i++)
    {
        if (freq_arr[i] == 0)
            continue;
        q.push(new Node(char(i), freq_arr[i]));
    }

    while (q.size() > 1)
    {
        left = q.top();
        q.pop();
        right = q.top();
        q.pop();

        top = new Node(127, left->freq + right->freq);

        top->left = left;
        top->right = right;
        q.push(top);
    }
    root = q.top();
    generate_codes(root, "");
}
