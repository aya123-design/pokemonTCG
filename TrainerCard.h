#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"
#include <string>

using namespace std;

class TrainerCard : public Card {
private:
    string trainerEffect;

public:
    TrainerCard(const string& trainerName, const string& effect);
    void DisplayInfo() const override;
    string getEffect() const { return trainerEffect; }
};

#endif