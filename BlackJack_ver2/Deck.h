#pragma once

#include	<string>
#include	<vector>

enum make
{
	spade,
	heart,
	diamond,
	club,

	count,
};

class CDeck
{
private:
	std::vector<std::string> m_Deck;

public:

	std::vector<std::string> GetDeck();

	void Shuffle();

	std::string Draw();

	void Reset();
};

