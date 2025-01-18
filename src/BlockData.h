#ifndef BLOCKDATA_H
#define BLOCKDATA_H

#include "header.h"
using namespace std;

class BlockData {
public:
    BlockData(string name, string type, string data):
        personName(name), actionType(type), data(data) {}

    string getData() {
        return data;
    }

private:
    string personName;   // Name of person data belongs to
    string actionType;  // Mined or Traded
    string data;        // String/Message to add
};

#endif