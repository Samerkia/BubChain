//bubChain.h
#ifndef BUBCHAIN_H
#define BUBCHAIN_H

#include "BubBlock.h"
#include "BlockData.h"
using namespace std;

class BubChain {

public:
    // Constructor
    BubChain() {
        // Creates the Genesis Block for the chian
        chain.emplace_back(createGenesisBlock());
    }

    // Adds a block to the block chain
    bool addBlock(BlockData& data) {
        int idx = chain.size();
        string prevHash = chain.back().getHash();
        string key = "key";
        string bd = data.getData(); 
        BubBlock block(idx, bd, prevHash, key);

        // Validates the block
        if (validateBlock(block)) {
            chain.emplace_back(block);
            return true;
        } else {
            cout << "Invalid block, not adding to the chain!" << endl;
        }

        return false;
    }   

    // Displays the Chain
    void displayBubChain() {
        for (const auto& block : chain) {
            block.displayBlock();
            cout << "\t.\n\t.\n\t.\n";
        }
    }

private:

    // Validation of the created block
    // Will add implementation of hashes at a later date
    bool validateBlock(BubBlock& b) {
        return true;
    }

    // Generate the Genesis (first) block in the chain
    BubBlock createGenesisBlock() {
        return BubBlock(0, "Genesis Block - Bubbles is a good kitty", "0", "bubbles");
    }

    vector<BubBlock> chain;
};

#endif