#include "Hand.hpp"
#include "Deck.hpp"

/*
  The dealer class inherits from Hand. The only thing it adds is the
  TakeTurn function, which makes the dealer hit until they bust or reach
  17 points.
*/

class Dealer : public Hand {
private:

public:
  void TakeTurn(Deck &deck);

};
