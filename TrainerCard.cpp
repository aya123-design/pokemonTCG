#include "TrainerCard.h"
#include <iostream>

TrainerCard::TrainerCard(const string& trainerName, const string& effect)
    : Card(trainerName), trainerEffect(effect) {
}

void TrainerCard::DisplayInfo() const {
    cout << "Trainer Card - Name: " << getCardName() << ", Effect: " << trainerEffect << endl;
}