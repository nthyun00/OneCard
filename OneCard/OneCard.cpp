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
	cout << CardDeck().test() << endl;
	cout << CardDeck(0).test() << endl;
	cout << CardDeck(1).test() << endl;
	cout << CardDeck(2).test() << endl;
	cout << CardDeck(3).test() << endl;
}

