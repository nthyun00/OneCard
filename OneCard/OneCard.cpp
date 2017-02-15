// OneCard.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Card.h"
#include "CardDeck.h"
//#include "CardHand.h"

using namespace std;
using namespace OneCard;

int main()
{
	CardDeck test0;
	CardDeck test1(1);
	CardDeck test2(2);

	for (SizeType i = 0; i < 60; i++)
		test2.at(i).print();
}

