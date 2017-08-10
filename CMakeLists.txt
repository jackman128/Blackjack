cmake_minimum_required (VERSION 2.8.12)
project(blackjack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Weffc++ -Wall -pedantic -std=c++11")

add_executable(blackjack "main.cpp" "Deck.cpp" "Card.cpp" "Player.cpp" "Hand.cpp" "Dealer.cpp")
