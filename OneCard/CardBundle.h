#pragma once

#include "Card.h"
#include <forward_list>

namespace OneCard
{
	using namespace Trump;

	class CardBundle
	{
	private:
		std::forward_list<Card> bundle;
		SizeType attackCount = 0;
	public:
		CardBundle() = delete;
		explicit CardBundle(Card& card)
		{
			bundle.push_front(card);
		}

		auto put(Card& card)
		{
			if (attackCount == 0) 
			{
				if (bundle.front().suit == card.suit ||
					bundle.front().value == card.value ||
					bundle.front().suit == CardType::Suit::Joker)
				{
					bundle.push_front(card);
					return true;
				}
			}
			else  //attack and 7,JQK T.T
			{
				if (bundle.front().value==CardType::Value::Two)
				{

				}
				else if (bundle.front().value == CardType::Value::Ace)
				{

				}
			}
		}
	};
}