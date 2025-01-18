//BubCoin.h
#ifndef BUBCOIN_H
#define BUBCOIN_H

// #include "Person.h"
using namespace std;

class BubCoin {
public:

    //Constructor
    BubCoin() {
        // Randomly set whether the supply is infinite or limited
        isInfinite = rand() % 10 == 0;  // 10% chance for infinite supply

        // Set the total available BubCoin supply if it's limited between 20 million and 100 million
        if (!isInfinite) {
            // Helps make it more random within the range
            totalSupply = 20000000 + static_cast<long>((80000000 * (static_cast<double>(rand()) / RAND_MAX)));
            //Circulatiing/Available Supply initialized to be same as total
            circulatingSupply = totalSupply;
        } else {
            totalSupply, circulatingSupply = -1;  // -1 indicates infinite supply
        }

        // Set the initial price of BubCoin
        setInitialCoinPrice();
    }

    // Sets the initial coin price
    void setInitialCoinPrice() {
        if (totalSupply == -1) {
            int i = rand() % 4 + 1;
            switch (i)
            {
            case 1:
                price = 0.25;
                break;
            case 2:
                price = 0.5;
                break;
            case 3:
                price = 1.0;
                break;
            case 4:
                price = 2.0;
                break;
            default:
                price = 1.0;
            }
        } else {
            // This could be done better tbh
            int randomVal = rand() % 50000000 + 1000000; // Random Number between 1 million and 50 million
            price = totalSupply / randomVal;
        }
    }

    // Returns the current price of the BubCoin
    double getCoinPrice() {
        return price;    
    }

    // Returns the total supply of the coin
    double getTotalSupply() {
        return totalSupply;
    }

    // Returns the circulating/available supply of the coin
    double getCirculatingSupply() {
        return circulatingSupply;
    }

    // Updates the circulating supply
    void updateCirculatingSupply(double a) {
        circulatingSupply = circulatingSupply - a;
    }

    // Displays the info of the BubCoin
    void displayBubCoinInfo() {
        cout << "BubCoin Info:\n";
        if (isInfinite) {
            cout << "Supply: Infinite\n";
            cout << "Circulating Supply: Infinite\n";
        } else {
            cout << "Supply: " << totalSupply << endl;
            cout << "Circulating Supply: " << circulatingSupply << endl;
        }
        cout << "Price per coin: $" << price << endl;
    }

private:
    double price;                   // Price of the BubCoin
    double totalSupply;             // Max Supply of the BubCoin
    double circulatingSupply;       // Circulating Supply as in how much is there to buy?
    bool isInfinite;                // is there an infinite amount of this coin?
};

#endif