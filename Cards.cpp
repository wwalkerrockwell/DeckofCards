#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Card {
public: 
	string face, suit;
	string SuitList[4] = { "Heart", "Diamond", "Club", "Spade"};
	string FaceList[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "King", "Queen" };
	
	Card() {
		face = "f";
		suit = "s";
	}



	string toString() {
		return suit + " of " + face;
	}
	void SetValues(string f, string s) {
		face = f;
		suit = s;
	}
	void displayValues() {
		cout << face << suit << endl;
	}

};

class DeckOfCards {
public:
	int currentCard = -1, k = 0;
	bool moreCards = true;
	Card deck[52];

	
	DeckOfCards() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				deck[k].SetValues(deck[k].SuitList[i], deck[k].FaceList[j]);
				k += 1;
			}
		}
	}

	void Shuffle() {
		int random = rand() % 52;
		Card Placeholder;
		for (int i = 0; i < 52; i++) {
			Placeholder = deck[random];
			deck[random] = deck[i];
			deck[i] = Placeholder;
			random = rand() % 52;
			
		}
	}
	void PrintDeck() {
		for (int i = 0; i < 52; i++) {
			cout << deck[i].toString() << endl;
		}
	}
	Card dealCard() {
		currentCard += 1;
		return deck[currentCard];
	}

	void MoreCards() {
		if (currentCard == 51) {
			moreCards == false;
			return;
		}
	}

};

int main() {
	srand(time(NULL));
	DeckOfCards Deck;
	Card hand[52];

	Deck.Shuffle();
	cout << "\n\n" << endl;

	for (int i = 0; i < 52; i++) {
		if (Deck.moreCards == true) {
			hand[i] = Deck.dealCard();
		}

		cout << hand[i].toString() << endl;
	}

}