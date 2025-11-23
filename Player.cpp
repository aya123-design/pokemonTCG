#include "Player.h"
#include <iostream>

Player::Player(const string& name) : playerName(name) {}

Player::~Player() {
    for (Card* card : benchCards) delete card;
    for (PokemonCard* pokemon : actionCards) delete pokemon;
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int benchIndex) {
    if (benchIndex < 0 || benchIndex >= benchCards.size()) return;
    
    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[benchIndex]);
    if (pokemon) {
        actionCards.push_back(pokemon);
        benchCards.erase(benchCards.begin() + benchIndex);
        cout << playerName << " is activating a Pokemon Card: " << pokemon->getCardName() << endl;
    }
}

void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    if (benchIndex < 0 || benchIndex >= benchCards.size() || 
        actionIndex < 0 || actionIndex >= actionCards.size()) return;
    
    EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
    if (energy) {
        actionCards[actionIndex]->attachEnergy(energy->getCardName());
        benchCards.erase(benchCards.begin() + benchIndex);
        cout << playerName << " is attaching Energy Card of type " << energy->getCardName() 
             << " to the Pokemon " << actionCards[actionIndex]->getCardName() << endl;
        delete energy;
    }
}

void Player::displayBench() const {
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for (Card* card : benchCards) {
        card->DisplayInfo();
    }
}

void Player::displayAction() const {
    cout << "Action cards for Player " << playerName << ":" << endl;
    for (PokemonCard* pokemon : actionCards) {
        pokemon->DisplayInfo();
    }
}

void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex) {
    if (attackerIndex < 0 || attackerIndex >= actionCards.size() ||
        targetIndex < 0 || targetIndex >= opponent.actionCards.size()) return;
    
    PokemonCard* attacker = actionCards[attackerIndex];
    PokemonCard* target = opponent.actionCards[targetIndex];
    
    if (!attacker->canUseAttack(attackIndex)) {
        cout << "Not enough energy to use this attack!" << endl;
        return;
    }
    
    cout << playerName << " attacking " << opponent.getPlayerName() 
         << "'s Pokemon " << target->getCardName() 
         << " with the Pokemon " << attacker->getCardName() 
         << " with its attack: " << get<2>(attacker->getAttacks()[attackIndex]) << endl;
    
    attacker->useAttack(attackIndex, *target);
}

void Player::useTrainer(int benchIndex) {
    if (benchIndex < 0 || benchIndex >= benchCards.size()) return;
    
    TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[benchIndex]);
    if (trainer && trainer->getEffect() == "heal all your action pokemon") {
        cout << playerName << " is using the Trainer Card to \"heal all your action pokemon\"" << endl;
        healAllActionPokemon();
        benchCards.erase(benchCards.begin() + benchIndex);
        delete trainer;
    }
}

void Player::healAllActionPokemon() {
    for (PokemonCard* pokemon : actionCards) {
        pokemon->setHP(pokemon->getMaxHP());
    }
}