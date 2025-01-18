#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "BubCoin.h"
#include "Person.h"

using namespace std;

// Initialize the random seed once at the start of the program
void initRandom() {
    srand(time(0));
}


int main() {
    // Initialize the random seed once at the start of the program
    initRandom();
    // Sets the precious to avoid to large of numbers
    cout << fixed << setprecision(4);

    BubCoin bc;
    BubChain chain;
    
    Person alice("Alice", true, false);  // Alice is a miner
    Person charles("Charles", true, false);  // Charles is also a miner
    Person bob("Bob", false, false);  // Bob is not a miner

    cout << "Initial  values\n\n";
    // Display blockchain and coin info
    chain.displayBubChain();
    bc.displayBubCoinInfo();

    // Simulate mining
    alice.mineCrypto(bc, chain);
    charles.mineCrypto(bc, chain);

    cout << "Final values\n\n";
    // Display blockchain and coin info
    chain.displayBubChain();
    bc.displayBubCoinInfo();

    return 0;
}


