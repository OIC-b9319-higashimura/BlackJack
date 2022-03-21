#include "Deck.h"

#include	<random>

std::vector<std::string> CDeck::GetDeck()
{
	return m_Deck;
}

void CDeck::Shuffle()
{
	std::random_device seed;
	std::mt19937 mt(seed());
	std::shuffle(m_Deck.begin(), m_Deck.end(), mt);

}

std::string CDeck::Draw()
{
	auto card = m_Deck.back();
	m_Deck.pop_back();
	return card;
}

void CDeck::Reset()
{
	m_Deck.clear();
	for (int mark = 0; mark < make::count; mark++) {
		for (int num = 0; num < 13; num++) {
			switch (mark) {
			case make::spade:
				m_Deck.push_back("s");
				break;
			case make::heart:
				m_Deck.push_back("h");
				break;
			case make::diamond:
				m_Deck.push_back("d");
				break;
			case make::club:
				m_Deck.push_back("c");
				break;
			default:
				break;
			} // switch
			m_Deck.back() += std::to_string((num + 1));
		} // for
	} // fof
}
