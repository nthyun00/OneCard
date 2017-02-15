// OneCard.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Card.h"
#include "CardDeck.h"
#include "CardBundle.h"
//#include "CardHand.h"

using namespace std;
using namespace OneCard;
using namespace Trump;

int main()
{
	
	CardDeck test(2);
	cout << typeid(test).name() << endl;
	/*test.shuffle();

	for (SizeType i = 0; i < 60; i++)
		test.at(i).print();*/

}

