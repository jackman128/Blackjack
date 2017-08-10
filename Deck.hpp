#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <queue>
#include "Card.hpp"

/*
  The Deck class stores the deck of cards in a vector.
  It provides a function to draw cards from it.
*/

class Deck {
private:
  //holds all 52 cards
  std::queue<Card> cards;

public:
  //constructs a set of 52 cards and shuffles them
  Deck();

  //removes the top card from the deck and returns it
  Card Draw();
};

#endif
