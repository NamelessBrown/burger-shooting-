#include "Music.h"

Music::Music()
	:m_rd(), m_mt(m_rd()), m_WhatFile(0)
{
	m_songs.emplace_back("Music/ArianaGrande-BreakFreeft.Zedd.ogg");
	m_songs.emplace_back("Music/ArianaGrande-TheWayft.MacMiller.ogg");
	m_songs.emplace_back("Music/CarlyRaeJepsen-CallMeMaybe.ogg");
	m_songs.emplace_back("Music/DifferentHeaven&EH!DE-MyHeart[NCSRelease].ogg");
	m_songs.emplace_back("Music/DokiDokiLiteratureClub!OST-YourReality(Credits).ogg");
	m_songs.emplace_back("Music/Sabrepulse-CloseToMe(HD).ogg");
}

void Music::Play()
{
	std::uniform_int_distribution<int> distribution(0, m_songs.size() - 1);
	m_WhatFile = distribution(m_mt);

	m_music.openFromFile(m_songs.at(m_WhatFile));

	m_music.play();

}

const sf::Music& Music::getSong() const
{
	return m_music;
}
