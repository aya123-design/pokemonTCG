#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

using namespace std;

class PokemonCard : public Card {
private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<tuple<int, int, string, int>> attacks; 
    vector<string> attachedEnergyTypes;

public:
    PokemonCard(const string& cardName,
                const string& pokemonType,
                const string& familyName,
                int evolutionLevel,
                int maxHP,
                int initialEnergy,
                const string& attack1Desc, int attack1Damage, int attack1Cost,
                const string& attack2Desc, int attack2Damage, int attack2Cost);
    
    void DisplayInfo() const override;
    int getMaxHP() const { return maxHP; }
    int getHP() const { return hp; }
    void setHP(int newHP) { hp = newHP; }
    void attachEnergy(const string& energyType);
    bool canUseAttack(int attackIndex) const;
    void useAttack(int attackIndex, PokemonCard& target);
    string getPokemonType() const { return pokemonType; }
    vector<tuple<int, int, string, int>> getAttacks() const { return attacks; }
};

#endif