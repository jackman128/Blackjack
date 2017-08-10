#include "Dealer.hpp"
#include <iostream>

using namespace std;

void Dealer::TakeTurn(Deck &deck)
{
  //reveal the first card to the user
  Card card = deck.Draw();
  cout << "The dealer turns up a " << card << "." << endl;
  this->Take(card);
  card = deck.Draw();
  this->Take(card);
  //the dealer hits until busted and standing
  while (this->HandValue() != -100 && this->HandValue() < 17) {
    this->Take(deck.Draw());
  }
}
