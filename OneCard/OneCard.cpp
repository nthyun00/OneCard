// OneCard.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

