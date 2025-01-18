#ifndef BUBBLOCK_H
#define BUBBLOCK_H

#include "header.h"
using namespace std;

class BubBlock {
public:

    // Constructor
    BubBlock(int idx, const string& blockData, const string& prevHash, const string& key) :
        index(idx),
        data(blockData),
        previousHash(prevHash),
        code(key) {
            timestamp = time(nullptr);
            hash = calculateBlockHash(data, code);  // Generate hash for the block
        }

    //Display Block
    void displayBlock() const {
        std::cout << "-----------------------------\n";
        cout << "Block: " << index << endl;
        cout << "Timestamp: " << timestamp << endl;
        cout << "Data: " << data << endl;
        cout << "Previous Hash: " << previousHash << endl;
        std::cout << "Miner: " << miner << "\n";
        cout << "Hash: " << hash << endl;
        std::cout << "-----------------------------\n";
    }

    string getHash() {
        return hash;
    }

private:

    // A Quick Hash thing I made just to avoid needing to install other libraries
    string calculateBlockHash(const string& input, const string& key) {
        
        // Start with a simple seed value
        unsigned long long hash = 5381;

        // Process each character in the input
        for (size_t i = 0; i < input.length(); ++i) {
            hash = ((hash << 5) + hash) + input[i]; // hash * 33 + input[i]
            hash ^= key[i % key.length()];         // XOR with the key character
        }

        // Convert hash to a hexadecimal string
        ostringstream hashStream;
        hashStream << hex << setw(16) << setfill('0') << hash;

        return hashStream.str();
    }

    int index;            // Block number
    string data;          // Data in the block (e.g., transaction information)
    string previousHash;  // Hash of the previous block
    string hash;          // Hash of the current block
    time_t timestamp;     // Timestamp of when the block was created
    string code;          // A key or salt for generating the hash (could be a simple string)
    string miner;         // The person who mined the chain/block/coin/whatever

};

#endif