#pragma once

#include "Card.h"
#include "CardDeck.h"
#include <vector>

namespace OneCard
{
	using namespace Trump;

	class CardHand
	{
		std::vector<Card> hand;

	public:
		explicit CardHand() = default;

		CardHand& operator+=(Card& card)
		{
			this->hand.push_back(card);

			return *this;
		}

		operator std::vector<Card>()
		{
			return hand;
		}
	};
}