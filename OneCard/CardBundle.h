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

		operator std::forward_list<Card>()
		{
			return bundle;
		}

		Card show()
		{
			return bundle.front();
		}
		CardBundle& put(Card& card)
		{
			bundle.push_front(card);
			return *this;
		}
	};
}