//#pragma once
//
//#include "Card.h"
//#include <vector>
//
//namespace OneCard
//{
//	class CardHand
//	{
//		std::vector<Card> hand;
//
//	public:
//		CardHand() = default;
//
//		CardHand& operator+=(Card& card)
//		{
//			this->hand.push_back(card);
//
//			return *this;
//		}
//
//		operator std::vector<Card>()
//		{
//			return hand;
//		}
//	};
//}