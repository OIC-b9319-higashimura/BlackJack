#include <iostream>

#include	"Deck.h"

#include <string>
#include <vector>
#include <algorithm>

struct Hand
{
	std::vector<std::string> Cards;

	int GetTotalValue() {
		int sum = 0;
		int Count1 = 0;
		for (auto card : Cards) {
			if (card.erase(0, 1) == "1") { ++Count1; }
			sum += std::min(atoi(card.c_str()), 10);
		} // for
		for (int i = 0; i < Count1; i++) {
			sum <= 11 ? sum += 10 : false;
		} // for
		return sum;
	}

	void AddCard(const std::string & card) {
		Cards.push_back(card);
	}
};

void PrintHand(const char* name, Hand hand) {
	std::cout << name << " { ";
	for (auto c : hand.Cards) {
		std::cout << c << " ";
	} // for
	std::cout << "} = [" << hand.GetTotalValue() << "]" << std::endl;
}

int main()
{
	CDeck Deck;
	Hand Player;
	bool PlayerStand = false;
	Hand Dealer;

	Deck.Reset();
	Deck.Shuffle();

	Dealer.AddCard(Deck.Draw());
	Dealer.AddCard(Deck.Draw());

	Player.AddCard(Deck.Draw());
	Player.AddCard(Deck.Draw());

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	

	std::cout << "ブラックジャックを開始します。" << std::endl;
	std::cout << "Dealer " << "{ " << Dealer.Cards[0] << ", ? }" << std::endl;
	PrintHand("You", Player);
	while (true) {
		std::cout << std::endl;

		if (Player.GetTotalValue() > 21) {
			std::cout << "You burst" << std::endl;
			std::cout << "**** Winner Dealer ****" << std::endl;
			break;
		} // if

		std::string input_key;
		std::cout << "Hit(H) or Stand(S) => "; std::cin >> input_key;
		std::cout << std::endl;

		if (input_key == "h" || input_key == "H" || input_key == "hit" || input_key == "Hit") {
			Player.AddCard(Deck.Draw());
			PrintHand("You", Player);
		} // if
		if (input_key == "s" || input_key == "S" || input_key == "stand" || input_key == "Stand") {
			PlayerStand = true;
			break;
		} // if
	} // while

	while (PlayerStand) {
		PrintHand("Dealer", Dealer);
		if (Dealer.GetTotalValue() < 17) {
			Dealer.AddCard(Deck.Draw());
		} // if
		else {
			if (Dealer.GetTotalValue() > 21) {
				std::cout << "Dealer burst" << std::endl;
				std::cout << "**** Winner You ****" << std::endl;
			} // if
			else {
				std::cout << std::endl;

				PrintHand("Dealer", Dealer);
				PrintHand("You", Player);

				if (Dealer.GetTotalValue() < Player.GetTotalValue()) {
					std::cout << "**** Winner You ****" << std::endl;
				} // if
				else {
					std::cout << "**** Winner Dealer ****" << std::endl;
				} // else
			} // else
			break;
		} // if
	} // while



	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}