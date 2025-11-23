#include "EnergyCard.h"
#include <iostream>

EnergyCard::EnergyCard(const string& energyType)
    : Card("Energy"), energyType(energyType) {
}

void EnergyCard::DisplayInfo() const {
    cout << "Energy Card: " << getCardName() << endl;
    cout << "Type d'energie: " << energyType << endl;
    
}