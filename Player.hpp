#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

/*
  The player class represents the user's money and cards.
  It inherits from the Hand class, and adds functions
  to modify the amount of money and for the player to take a turn
*/

#include "Hand.hpp"
#include "Deck.hpp"

class Player : public Hand {
private:
  int money;
public:
  Player(int startingMoney = 0);
  void SetMoney(int money);
  int GetMoney() const;
  void IncMoney(int difference);

  //asks the user to hit or stand until they bust or stand.
  void TakeTurn(Deck &deck);
};

#endif
