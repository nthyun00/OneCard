#pragma once

#include "Card.h"
#include "CardDeck.h"
#include "CardBundle.h"
#include "CardHand.h"
#include <vector>

namespace OneCard
{
	using namespace Trump;

	class GameManagement
	{
		CardDeck deck;
		CardBundle bundle;
		Card bundleFrontCard;
		std::vector<CardHand> hand;

		GameManagement() :deck(2), bundle(deck.draw()), bundleFrontCard(bundle.show()) { }
	public:
		GameManagement(ScopingType<SizeType, 1, 4> participants, ScopingType<SizeType, 5, 7> numberOfCard) : GameManagement()
		{
			hand.assign(participants, CardHand());
			for (auto& var : hand)
			{
				for (SizeType i = 0; i < numberOfCard; i++)
					var += deck.draw();
			}
		}


	};
}