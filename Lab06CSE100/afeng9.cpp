#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <string> 
// HashTable class implements a hash table using separate chaining for collision resolution
class HashTable {
    // Vector of linked lists to store chains of elements
    // Each index (bucket) contains a list of integers that hash to that index
    std::vector<std::list<int> > table;
    int size;  // Size of the hash table (number of buckets)

    // Private hash function that maps keys to bucket indices
    // Uses the modulo operator to ensure the hash value is within table bounds
    int hash(int key) { return key % size; }

public:
    // Constructor initializes the hash table with 'm' buckets
    // table(m) creates a vector of 'm' empty lists
    HashTable(int m) : size(m), table(m) {}
// 
    // Inserts a new key into the hash table
    // Uses push_front for O(1) insertion at the beginning of the chain
    void insert(int key) {
        table[hash(key)].push_front(key);
    }

    // Removes a key from the hash table if it exists
    void remove(int key) {
        std::list<int>& bucket = table[hash(key)];  // Replace auto
        std::list<int>::iterator it = std::find(bucket.begin(), bucket.end(), key);
        
        if (it != bucket.end()) {
            bucket.erase(it);
            std::cout << key << ":DELETED;\n";
        } else {
            std::cout << key << ":DELETE_FAILED;\n";
        }
    }

    // Searches for a key in the hash table
    void search(int key) {
        std::list<int>& bucket = table[hash(key)];  // Replace auto
        std::list<int>::iterator it = std::find(bucket.begin(), bucket.end(), key);
        
        if (it != bucket.end()) {
            std::cout << key << ":FOUND_AT" << hash(key) << ","
                     << std::distance(bucket.begin(), it) << ";\n";
        } else {
            std::cout << key << ":NOT_FOUND;\n";
        }
    }

    // Outputs the entire hash table structure
    void output() {
        for (int i = 0; i < size; ++i) {
            std::cout << i << ":";
            for (std::list<int>::iterator it = table[i].begin(); it != table[i].end(); ++it) {
                std::cout << *it << "->";
            }
            std::cout << ";\n";
        }
    }
};

int main() {
    int m;
    std::cin >> m;  // Read the size of hash table
    HashTable ht(m);  // Create hash table with 'm' buckets

    // Process commands until 'e' (exit) is encountered
    for (char op; std::cin >> op && op != 'e';) {
        int key;
        switch (op) {
            case 'i': std::cin >> key; ht.insert(key); break;  // Insert operation
            case 'd': std::cin >> key; ht.remove(key); break;  // Delete operation
            case 's': std::cin >> key; ht.search(key); break;  // Search operation
            case 'o': ht.output(); break;                      // Output operation
        }
    }
}
