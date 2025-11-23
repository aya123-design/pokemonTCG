#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card {
private:
    string cardName;
    
public:
    Card(const string& name);
    string getCardName() const {
        return cardName;
    }
    virtual void DisplayInfo() const = 0;
};

#endif