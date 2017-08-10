#include "Deck.hpp"
#include <vector>
#include <utility>
#include <cstdlib>

Deck::Deck() : cards(std::queue<Card>())
{
  //create a vector of integers from 0 to 51
  std::vector<int> cardVec(52);
  for (int i = 0; i < 52; i++) {
    cardVec.at(i) = i;
  }

  //shuffle the vector of integers by swapping every element with
  //an element at a random location
  for (int i = 0; i < 52; i++) {
    //get a random number from 0 to 51
    int randLoc = rand() % 52;
    std::swap(cardVec.at(i), cardVec.at(randLoc));
  }

  //convert the vector of ints into a queue of cards.
  //dividing num yields a number between 0 and 3, representing a suit in cardSuits
  //modding num yields a number between 0 and 12, representing a rank in cardRanks
  for (int i = 0; i < 52; i++) {
    int num = cardVec.at(i);
    Card card(cardSuits[num / 13], cardRanks[num % 13]);
    this->cards.push(card);
  }
}

Card Deck::Draw()
{
  Card card = this->cards.front();
  this->cards.pop();
  return card;
}
