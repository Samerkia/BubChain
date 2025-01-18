#ifndef BUBCOIN_H
#define BUBCOIN_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class BubCoin {
public:
    BubCoin() {
        balances["Bob"] = 100;
    }

    void createTransaction(string sender, string receiver, double amt) {
        if (balances[sender] >= amt) {
            balances[sender] -= amt;
            balances[receiver] += amt;
            ledger.push_back(sender + " sent " + to_string(amt) + " BubCoins to " + receiver);
        } else {
            cout << "FAILED TRANSACTION: " << sender << " DOES NOT HAVE ENOUGH BUBCOIN TO SEND";
        }
    }

    // Gets the Balance of owners wallet
    double getBalance(const std::string& owner) {
        return balances[owner];
    }

    // Shows the transaction record of the BubCoin network
    void displayLedger() const {
        for (const auto& entry : ledger) {
            std::cout << entry << std::endl;
        }
    }

private:
    map<string, double> balances; // Tracks balance of each user
    vector<string> ledger; // Transaction record holder
    double maxCoins = 1000000;
};

#endif