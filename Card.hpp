#ifndef __CARD_HPP__
#define __CARD_HPP__

#include <string>
#include <ostream>

//these strings allow the Deck class to iterate through the suits and ranks.
const std::string cardSuits = "HDCS";
const std::string cardRanks = "A234567890JQK";

class Card {
private:
  //HDCS for hearts, diamonds, clubs, spades
  char suit;

  //234567890JQKA //numbers (0 is 10), jack, queen, king, ace
  char rank;

public:
  Card(char suit, char rank);
  char GetSuit() const;
  char GetRank() const;
  //returns a string describing the card
  std::string ToString() const;
};

//allow easy printing of cards
std::ostream &operator<<(std::ostream &stream, Card const &card);

#endif
