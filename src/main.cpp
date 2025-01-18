#include "BubChain.h"
using namespace std;

int main() {
    // Create the BubCoin blockchain
    BubChain bc;

    // Simulate some transactions
    bc.addBlock("Block 1: bub sent 100 BubCoins to alice");
    bc.addBlock("Block 2: alice sent 50 BubCoins to bob");
    bc.mineBlock();  // Simulate mining

    // Display the blockchain
    std::cout << "Displaying Blockchain:" << std::endl;
    bc.displayBubChain();

    return 0;
}
