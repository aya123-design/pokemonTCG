#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include <vector>
#include <string>

using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(const string& name);
    ~Player();

    string getPlayerName() const { return playerName; }
    vector<Card*> getBenchCards() const { return benchCards; }
    vector<PokemonCard*> getActionCards() const { return actionCards; }

    void addCardToBench(Card* card);
    void activatePokemonCard(int benchIndex);
    void attachEnergyCard(int benchIndex, int actionIndex);
    void displayBench() const;
    void displayAction() const;
    void attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex);
    void useTrainer(int benchIndex);
    void healAllActionPokemon();
};

#endif