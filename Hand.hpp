#ifndef __HAND_HPP__
#define __HAND_HPP__

#include <string>
#include <vector>
#include "Card.hpp"

/*
  The Hand class is never instantiated. The Player and Dealer classes
  inherit from it. It stores the player or dealer's cards in a vector,
  and provides functions for getting the point value of the hand,
  putting a new card in the hand, and more.
*/

class Hand {
private:
  //holds the player's cards
  std::vector<Card> hand;
public:

  Hand();

  //returns the number of points in a player's hand,
  //or -100 for a bust or 100 for a blackjack
  int HandValue() const;

  //puts a card into the player's hand
  void Take(Card card);

  //returns a string containing the player's hand
  std::string HandToString() const;

  //removes all cards from the player's hand
  void ResetHand();

};

#endif
