#include "Player.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

Player::Player(int startingMoney) : money(startingMoney) {}

void Player::SetMoney(int money)
{
  this->money = money;
}

int Player::GetMoney() const
{
  return this->money;
}

void Player::IncMoney(int difference)
{
  this->money += difference;
}

void Player::TakeTurn(Deck &deck)
{
  //The player is dealt 2 cards initially
  bool done = false;
  Card card = deck.Draw();
  this->Take(card);
  cout << "You were dealt a " << card;
  card = deck.Draw();
  this->Take(card);
  cout << " and a " << card << "." << endl;

  cout << "type 'h' to hit or 's' to stand." << endl;
  //stop asking the player for input if they quit, stand, or bust.
  while (!done) {
    char input;
    cin >> input;
    input = tolower(input);
    switch (input) {
      //hit
    case 'h':
      card = deck.Draw();
      this->Take(card);
      cout << "You were dealt a " << card << "." << endl;
      if (this->HandValue() == -100) {
        done = true;
      }
      break;
      //stand
    case 's':
      done = true;
      break;
      //unknown
    default:
      cout << "Command not recognized." << endl;
    }
  }
}
