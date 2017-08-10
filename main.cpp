/*
  Jack Wilson
  Lab 3
  The final version of blackjack, with betting.
*/

#include <iostream>
#include <cstdlib>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"

using namespace std;

const int playerStartingMoney = 250;

bool askPlayerQuit();

int main() {
  srand(time(NULL));
  Deck deck;
  Player player(playerStartingMoney);
  Dealer dealer;

  cout << "Welcome to Blackjack." << endl;

  do {
    int bet = 0;
    dealer.TakeTurn(deck);

    //Ask the player how much they want to bet
    cout << "You have $" << player.GetMoney() << "." << endl;
    while (true) {
      cout << "How much would you like to bet?" << endl;
      cin >> bet;
      if (bet < 0) {
        cout << "Your bet cannot be negative." << endl;
      }
      else if (bet > player.GetMoney()) {
        cout << "Your bet cannot be greater than the money that you have." << endl;
      }
      else {
        break;
      }
    }

    player.TakeTurn(deck);

    cout << "The dealer reveals his cards: " << dealer.HandToString() << endl;
    int playerValue = player.HandValue();
    int dealerValue = dealer.HandValue();

    //tell the player who got a blackjack or busted
    if (playerValue == 100)
      cout << "You got a blackjack!" << endl;
    else if (playerValue == -100)
      cout << "You busted." << endl;
    if (dealerValue == 100)
      cout << "The dealer got a blackjack!" << endl;
    else if (dealerValue == -100)
      cout << "The dealer busted." << endl;

    //evaluate winner and loser
    if (dealerValue > playerValue) {
      cout << "The dealer won." << endl;
      player.IncMoney(-bet);
    }
    else if (dealerValue < playerValue) {
      cout << "You won." << endl;
      if (playerValue == 100) {
        //Pay out double for blackjack
        player.IncMoney(2 * bet);
      }
      else {
        player.IncMoney(bet);
      }
    }
    else {
      cout << "Draw." << endl;
    }
    cout << endl;

    //empty the player and dealer's hands and get a new deck
    player.ResetHand();
    dealer.ResetHand();
    deck = Deck();
  } while (!askPlayerQuit()); //Play again for as long as the user doesn't quit

  cout << "You leave the game with $" << player.GetMoney() << "." << endl;
  cout << "Goodbye." << endl;
}

//return true for quit, or false to play again
bool askPlayerQuit()
{
  cout << "Do you want to play again? (y/n)" << endl;
  char input;
  //ask the user again if they input an invalid value
  while (true) {
    cin >> input;
    input = toupper(input);
    switch (input) {
    case 'Y':
      return false;
      break;
    case 'N':
      return true;
      break;
    default:
      cout << "Command not recognized." << endl;
      break;
    }
  }
}
