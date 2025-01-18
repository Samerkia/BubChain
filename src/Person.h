//Person.h
#include "header.h"
using namespace std;

class Person {
public:

    // Constructor
    Person(string personName, bool isPersonMiner, bool isPersonHacker):
        name(personName),
        isMiner(isPersonMiner),
        isHacker(isPersonHacker),
        cryptoOwned(0) {
            if (!isMiner) {
                miningPower = 0;
            } else {
                miningPower = rand() % 10 + 1;
            }
        }

    // Get the amount of Crypto the Person owes
    double getCryptoAmount() {
        return cryptoOwned;
    }

    // Adds Crypto to the person
    void addCrypto(double amount) {
        cryptoOwned += amount;
    }

    // Removes crypto from the person
    void deductCrypto(double amount){
        if (cryptoOwned > amount){
            cryptoOwned -= amount;
        } else {
            cout << name << " DOES NOT HAVE A VALID BALANCE OF BUBCOIN";
        }
    }

    // If they're a miner, then they can mine Crypto
    void mineCrypto(BubCoin& bc, BubChain& chain) {
        if (isMiner) {
            double reward = getRewardAmount(bc);  // Pass BubCoin reference to get the reward

            string blockData = name + " Mined " + to_string(reward) + " BubCoin!";
            if (chain.addBlock(blockData)) {
                addCrypto(reward);
                bc.updateCirculatingSupply(reward);
                cout << name << " Has helped out the BubChain! They have received " << reward << " BubCoin!\n";
            }
        } else {
            cout << endl << name << " Not a Miner... can't do this";
        }
    }

    // Displays the Wallet of the person
    void displayCryptoWallet(BubCoin& bc) {
        cout << endl << name << "'s Wallet\n";
        cout << "Crypto\t|\tUSD\n";
        cout << "BubCoin: " << getCryptoAmount() << "\t|\t$" << getCryptoAmount() * bc.getCoinPrice();
    }

private:
    string name;            // Name Of person
    double cryptoOwned;     // Amount of Crypto (BubCoin) they own
    bool isMiner;           // Can they Mine crypto?
    double miningPower;     // If they're a Crypto Miner, how much can they mine?
    bool isHacker;          // Are they a hacker?
    double hackerSkillz;     // Skill level of the hacker

    // Function to get dynamic mining reward based on price, supply, and mining power with randomness
    double getRewardAmount(BubCoin& bc) {
        double coinPrice = bc.getCoinPrice();
        double totalSupply = bc.getTotalSupply();  // Get the total supply from BubCoin
        double reward;

        // Generate a random multiplier between 0.1 and 1.9 to vary the reward each time
        double randomFactor = 0.1 + (rand() % 181) / 100.0;  // Random value between 0.1 and 1.9

        // cout << "Random factor: " << randomFactor << endl;  // Debugging line to show the factor

        if (totalSupply == -1) {  // Infinite supply
            reward = (5 * miningPower) * randomFactor;  // Apply randomness to the reward for infinite supply
        } else {
            // For finite supply, reward will be inversely proportional to price and supply
            double difficultyFactor = (coinPrice / 10000.0) * (totalSupply / 10000000.0);  // Adjusted for better scaling
            reward = (miningPower / difficultyFactor) * randomFactor;  // Apply randomness here as well

            // Ensure reward is not negative
            if (reward < 0) reward = 0;
        }

        // cout << "Calculated Reward: " << reward << endl;  // Debugging line to show the reward value

        // Return the calculated reward
        return reward;
    }

};