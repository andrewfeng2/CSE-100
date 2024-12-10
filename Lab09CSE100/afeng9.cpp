//chmod 700 Grade
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class HuffmanTree {
private:
    struct Node {
        // Node structure for Huffman tree
        // left/right: Pointers to child nodes
        // symbol: The character/symbol being encoded ("!" for internal nodes)
        // frequency: Number of occurrences of the symbol
        // id: Unique identifier for tie-breaking in priority queue
        Node* left;
        Node* right;
        string symbol;
        int frequency;
        int id;
        
        Node(string symbol, int freq, int id = 0) 
            : left(nullptr), right(nullptr), symbol(symbol), 
              frequency(freq), id(id) {}
    };
    
    struct NodeCompare {
        // Custom comparator for priority queue
        // Orders nodes by frequency (smaller first)
        // If frequencies are equal, uses id for consistent ordering
        bool operator()(const Node* a, const Node* b) const {
            if (a->frequency == b->frequency) {
                return a->id > b->id;
            }
            return a->frequency > b->frequency;
        }
    };
    
    // Stores the final Huffman codes for each symbol
    vector<string> encodings;
    
    void generateCodes(Node* root, string code, const string symbols[], int size) {
        // Recursive function to generate Huffman codes
        // Traverses tree, adding '0' for left branches and '1' for right branches
        // When a leaf node is found, stores the accumulated binary code
        if (!root) return;
        
        if (root->symbol != "!") {  // Leaf node found
            for (int i = 0; i < size; i++) {
                if (root->symbol == symbols[i]) {
                    encodings[i] = code;
                    break;
                }
            }
        } else {  // Internal node - continue traversal
            generateCodes(root->left, code + "0", symbols, size);
            generateCodes(root->right, code + "1", symbols, size);
        }
    }
    
public:
    void encode(int size, const string symbols[], const vector<int>& frequencies) {
        // Main encoding function that builds Huffman tree and generates codes
        encodings.resize(size);
        
        // Min-heap priority queue to build tree bottom-up
        priority_queue<Node*, vector<Node*>, NodeCompare> minHeap;
        
        // Create initial leaf nodes for each symbol
        for (int i = 0; i < size; i++) {
            minHeap.push(new Node(symbols[i], frequencies[i], i + 1));
        }
        
        // Build tree by repeatedly combining two lowest-frequency nodes
        while (minHeap.size() > 1) {
            // Extract two minimum frequency nodes
            Node* left = minHeap.top(); minHeap.pop();
            Node* right = minHeap.top(); minHeap.pop();
            
            // Create parent node with combined frequency
            Node* parent = new Node("!", left->frequency + right->frequency);
            
            // Handle special case for equal frequencies
            // Ensures consistent tree structure by ordering nodes by id
            if (left->frequency == right->frequency && left->id > right->id) {
                parent->left = right;
                parent->right = left;
                parent->id = right->id;
            } else {
                parent->left = left;
                parent->right = right;
                parent->id = left->id;
            }
            
            minHeap.push(parent);
        }
        
        // Generate the Huffman codes by traversing the completed tree
        generateCodes(minHeap.top(), "", symbols, size);
        
        // Output the codes for symbols A through F
        for (char c = 'A'; c <= 'F'; c++) {
            cout << c << ":" << encodings[c - 'A'] << endl;
        }
        
        // Clean up allocated memory
        while (!minHeap.empty()) {
            delete minHeap.top();
            minHeap.pop();
        }
    }
};

int main() {
    // Initialize variables for 6 symbols (A-F)
    const int SIZE = 6;
    vector<int> frequencies;
    string symbols[SIZE];
    
    // Read frequencies from input and create symbol names (K0 through K5)
    for (int i = 0; i < SIZE; i++) {
        int freq;
        cin >> freq;
        frequencies.push_back(freq);
        symbols[i] = "K" + to_string(i);
    }
    
    HuffmanTree huffman;
    huffman.encode(SIZE, symbols, frequencies);
    
    return 0;
}