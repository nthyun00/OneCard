#pragma once

#include "Card.h"
#include <vector>
#include <algorithm>

namespace OneCard
{
	class CardDeck
	{
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

		auto test()
		{
			return deck.size();
		}
	};
	const std::vector<Card>&& CardDeck::defaulteDeck = returnDefaulteDeck();
}