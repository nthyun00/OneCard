#pragma once
#include "DataType.h"
#include <forward_list>

namespace OneCard
{
	static class CardType
	{
	public:
		enum class Suit : Byte1 { Joker, Spade, Heart, Diamond, Club };
		enum class Value : Byte1 { Red = -1, Black, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
		using normalValue = ScopingType<Value, Value::Ace, Value::King>;
		using jokerValue = ScopingType<Value, Value::Red, Value::Black>;
		//enum class JokerType :char { Red, Black, Both };	//Joker
	
		static const std::forward_list<Suit>& iterSuit;
		static const std::forward_list<Value>& iterValue;
	};
	const std::forward_list<CardType::Suit>& CardType::iterSuit{ Suit::Spade, Suit::Heart, Suit::Diamond, Suit::Club };
	const std::forward_list<CardType::Value>& CardType::iterValue{
		Value::Ace, Value::Two, Value::Three, Value::Four, Value::Five,
		Value::Six, Value::Seven, Value::Eight, Value::Nine, Value::Ten,
		Value::Jack, Value::Queen, Value::King
	};

	class Card 
	{
	public:
		CardType::Suit suit;
		CardType::Value value;

		Card() = delete;
		Card(CardType::Suit suit, CardType::Value value) : suit(suit), value(value) {}

		void print()
		{
			using std::cout;
			using std::endl;
			cout << "(" << (Byte4)suit << "," << (Byte4)value << ")" << endl;
		}
	};
}