#pragma once

#include "Card.h"
#include "CardBundle.h"
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
		explicit CardDeck() : deck(defaulteDeck)
		{ 
			shuffle(); 
		};
		explicit CardDeck(ScopingType<SizeType, 1, 2> jokerNumber) :CardDeck()
		{
			for (SizeType i = 0; i < jokerNumber; i++)
				deck.push_back(Card(CardType::Suit::Joker, CardType::jokerValue((CardType::Value)(i - 1))));
		}

		CardDeck& shuffle()
		{
			std::shuffle(deck.begin(), deck.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()) );
			return *this;
		}
		Card draw()
		{
			Card ret = deck.back();
			deck.pop_back();
			return ret;
		}
		CardDeck& reFill(OneCard::CardBundle& bundle)
		{
			std::forward_list<Card>& bundle_list = (std::forward_list<Card>)bundle;
			auto tmp = bundle_list.front();
			bundle_list.pop_front();
			for (auto var : bundle_list )
				deck.push_back(var);
			bundle_list.clear();
			bundle_list.push_front(tmp);
			return *this;
		}

		Card& at(ScopingType <SizeType, 0, 53> index)	//T.T
		{
			return deck[index];
		}
	};
	const std::vector<Card>&& CardDeck::defaulteDeck = returnDefaulteDeck();
}