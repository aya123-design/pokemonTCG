#include "PokemonCard.h"
#include <iostream>

PokemonCard::PokemonCard(const string& cardName,
                         const string& pokemonType,
                         const string& familyName,
                         int evolutionLevel,
                         int maxHP,
                         int initialEnergy,
                         const string& attack1Desc, int attack1Damage, int attack1Cost,
                         const string& attack2Desc, int attack2Damage, int attack2Cost)
    : Card(cardName), pokemonType(pokemonType), familyName(familyName),
      evolutionLevel(evolutionLevel), maxHP(maxHP), hp(maxHP) {
    
    attacks.push_back(make_tuple(attack1Cost, initialEnergy, attack1Desc, attack1Damage));
    attacks.push_back(make_tuple(attack2Cost, initialEnergy, attack2Desc, attack2Damage));
}

void PokemonCard::DisplayInfo() const {
    cout << "Pokemon Card - Name: " << getCardName() 
         << ", Type: " << pokemonType 
         << ", Evolution Level: " << evolutionLevel 
         << " of the family \"" << familyName 
         << ", HP: " << hp << "\"" << endl;
    
    cout << "Attacks:" << endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << get<0>(attacks[i]) << endl;
        cout << "Attack current energy storage: " << get<1>(attacks[i]) << endl;
        cout << "Attack description: " << get<2>(attacks[i]) << endl;
        cout << "Attack damage: " << get<3>(attacks[i]) << endl;
    }
    if (attacks.size() == 2) {
        cout << "Only 2 attacks exist." << endl;
    }
}

void PokemonCard::attachEnergy(const string& energyType) {
    attachedEnergyTypes.push_back(energyType);
    for (auto& attack : attacks) {
        get<1>(attack) += 1;
    }
}

bool PokemonCard::canUseAttack(int attackIndex) const {
    if (attackIndex < 0 || attackIndex >= attacks.size()) return false;
    return get<1>(attacks[attackIndex]) >= get<0>(attacks[attackIndex]);
}

void PokemonCard::useAttack(int attackIndex, PokemonCard& target) {
    if (attackIndex < 0 || attackIndex >= attacks.size()) return;
    
    const auto& attack = attacks[attackIndex];
    cout << "Reducing " << get<3>(attack) << " from " << target.getCardName() << "'s Pokemon's HP" << endl;
    
    target.setHP(target.getHP() - get<3>(attack));
    
    if (target.getHP() > 0) {
        cout << "Pokemon " << target.getCardName() << " is still alive" << endl;
    } else {
        cout << "Pokemon " << target.getCardName() << " is defeated!" << endl;
    }
}