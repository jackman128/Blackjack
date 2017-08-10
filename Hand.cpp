#include "Hand.hpp"

Hand::Hand() : hand(std::vector<Card>()) {}

//calculate the points in a player's hand.
//returns a special value -100 for a bust, 100 for a blackjack,
//and the number of points otherwise.
int Hand::HandValue() const
{
  int value = 0;

  //for every card, add its corresponding value.
  for (unsigned int i = 0; i < this->hand.size(); i++) {
    char rank = this->hand.at(i).GetRank();
    if (rank >= '2' && rank <= '9') {
      //subtracting the ASCII value '0' from an ASCII number
      //yields the number.
      value += rank - '0';
    }
    else if (rank == '0' || rank == 'J' || rank == 'Q' || rank == 'K') {
      //tens and face cards get 10.
      value += 10;
    }
    else if (rank == 'A') {
      //aces are worth 11 or 1 points, whichever benefits the player
      value += 11;
    }
  }

  //if the hand is a bust, then make the player's aces worth one point
  //until the hand is not a bust
  if (value > 21) {
    for (unsigned int i = 0; i < this->hand.size(); i++) {
      char rank = this->hand.at(i).GetRank();
      if (value <= 21) {
        break;
      }
      else if (rank == 'A') {
        value -= 10;
      }
    }
  }
  //blackjack
  if (value == 21 && this->hand.size() == 2)
    return 100;
  //bust
  else if (value > 21)
    return -100;
  else
    return value;
}

void Hand::Take(Card card)
{
  this->hand.push_back(card);
}

//return a string containing a list of the player's cards.
std::string Hand::HandToString() const
{
  std::string out;
  for (unsigned int i = 0; i < this->hand.size() - 1; i++) {
    out += this->hand.at(i).ToString() + ", ";
  }
  out += this->hand.at(this->hand.size() - 1).ToString();
  return out;
}

//remove all of the cards from the player's hand.
void Hand::ResetHand()
{
  this->hand.clear();
}
