#include "Hucre.hpp"
#include "Pencere.hpp"

void Hucre::ciz(Pencere& pencere)
{
	m_sekil.setPosition(m_konum);
	pencere.ciz(m_sekil);
}

void Hucre::renkAta(const sf::Color& renk)
{
	m_sekil.setFillColor(renk);
}

Hucre::Hucre()
{
	m_sekil.setFillColor(sf::Color::Yellow);
	m_sekil.setOutlineColor(sf::Color::Black);
	m_sekil.setOutlineThickness(1);
	boyutAta(20);
	hizAta(5);
	yonAta(HucreYon::Sag);
}

Hucre Hucre::hucreUret()
{
	sf::Vector2f yeniKonum = m_konum;

	switch (m_yon)
	{
	case HucreYon::Sag:
		yeniKonum.x -= m_boyut;
		break;
	case HucreYon::Sol:
		yeniKonum.x += m_boyut;
		break;
	case HucreYon::Yukari:
		yeniKonum.y += m_boyut;
		break;
	case HucreYon::Asagi:
	    yeniKonum.y -= m_boyut;
		break;
	}
	Hucre yeniHucre;
	yeniHucre.konumAta(yeniKonum);
	yeniHucre.yonAta(m_yon);
	return yeniHucre;

}

void Hucre::yonAta(HucreYon yon)
{
	m_yon = yon;
}

HucreYon Hucre::yonGetir()
{
	return m_yon;
}

float Hucre::boyutGetir()
{
	return m_boyut;
}

void Hucre::boyutAta(float boyut)
{
	m_boyut = boyut;
	m_sekil.setSize(sf::Vector2f(m_boyut, m_boyut));
}

void Hucre::hizAta(float hiz)
{
	m_hiz = hiz;
}

float Hucre::hizGetir()
{
	return m_hiz;
}

void Hucre::konumAta(sf::Vector2f konum)
{
	m_konum = konum;
}

sf::Vector2f Hucre::konumGetir() const
{
	return m_konum;
}


void Hucre::hareket()
{
	switch (m_yon)
	{
	case HucreYon::Sag:
		m_konum.x += m_hiz;
		break;
	case HucreYon::Sol:
		m_konum.x -= m_hiz;
		break;
	case HucreYon::Yukari:
		m_konum.y -= m_hiz;
		break;
	case HucreYon::Asagi:
		m_konum.y += m_hiz;
		break;
	}
}
