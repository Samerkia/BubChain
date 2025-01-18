#ifndef BUBCHAIN_H
#define BUBCHAIN_H

#include <vector>
#include "BubBlock.h"
using namespace std;

class BubChain {

public:
    // Constructor
    BubChain() {
        // Creates the Genesis Block for the chian
        chain.emplace_back(createGenesisBlock());
    }

    // Adds a block to the block chain
    void addBlock(const string& data) {
        int idx = chain.size();
        string prevHash = chain.back().getHash();
        chain.emplace_back(BubBlock(idx, data, prevHash, "Bob"));
    }

    void mineBlock() {
        string newData = "Mined a Block! BubCoin Transaction Processed!";
        addBlock(newData);
    }

    // Displays the Chain
    void displayBubChain() {
        for (const auto& block : chain) {
            block.displayBlock();
        }
        cout << "\t.\n\t.\n\t.\n";
    }

private:
    // Generate the Genesis (first) block in the chain
    BubBlock createGenesisBlock() {
        return BubBlock(0, "Genesis Block - Bubbles is a good kitty", "0", "bubbles");
    }

    vector<BubBlock> chain;
    // BubCoin coin;
};

#endif