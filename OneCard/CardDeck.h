#pragma once

#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

namespace Trump
{
	class CardDeck
	{
	private:
		std::vector<Card> deck; 

		static const std::vector<Card>&& defaulteDeck;
		static auto returnDefaulteDeck()
		{
			std::vector<Card> ret;
			for (auto suit : CardType::iterSuit)
				for (auto value : CardType::iterValue)
					ret.push_back(Card(suit, value));
			return ret;
		}
	public:
		CardDeck() : deck(defaulteDeck) { };
		CardDeck(ScopingType<SizeType, 1, 2> jokerNumber) :CardDeck()
		{
			for (SizeType i = 0; i < jokerNumber; i++)
				deck.push_back(Card(CardType::Suit::Joker, CardType::jokerValue((CardType::Value)(i - 1))));
		}

		auto& shuffle()
		{
			std::shuffle(deck.begin(), deck.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()) );
			return *this;
		}
		auto draw()
		{
			Card ret = deck.back();
			deck.pop_back();
			return ret;
		}

		auto& at(ScopingType <SizeType, 0, 53> index)	//T.T
		{
			return deck[index];
		}
	};
	const std::vector<Card>&& CardDeck::defaulteDeck = returnDefaulteDeck();
}