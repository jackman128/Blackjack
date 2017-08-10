#include "Card.hpp"
Card::Card(char suit, char rank) : suit(suit), rank(rank) {}

char Card::GetSuit() const
{
  return this->suit;
}

char Card::GetRank() const
{
  return this->rank;
}


std::string Card::ToString() const
{
  std::string out;
  switch (this->rank) {
  case '2':
    out += "Two";
    break;
  case '3':
    out += "Three";
    break;
  case '4':
    out += "Four";
    break;
  case '5':
    out += "Five";
    break;
  case '6':
    out += "Six";
    break;
  case '7':
    out += "Seven";
    break;
  case '8':
    out += "Eight";
    break;
  case '9':
    out += "Nine";
    break;
  case '0':
    out += "Ten";
    break;
  case 'J':
    out += "Jack";
    break;
  case 'Q':
    out += "Queen";
    break;
  case 'K':
    out += "King";
    break;
  case 'A':
    out += "Ace";
    break;
  }

  out += " of ";

  switch (this->suit) {
  case 'H':
    out += "Hearts";
    break;
  case 'C':
    out += "Clubs";
    break;
  case 'D':
    out += "Diamonds";
    break;
  case 'S':
    out += "Spades";
    break;
  }
  return out;
}

std::ostream& operator<<(std::ostream& stream, const Card& card)
{
  stream << card.ToString();
  return stream;
}
